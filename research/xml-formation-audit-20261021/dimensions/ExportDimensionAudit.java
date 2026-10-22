// @category Glyph.Research
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import java.io.*;
import java.util.*;

public class ExportDimensionAudit extends GhidraScript {
    private String q(String value) {
        return "\"" + value.replace("\\", "\\\\").replace("\"", "\\\"").replace("\n", "\\n").replace("\r", "\\r").replace("\t", "\\t") + "\"";
    }
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File output = new File(args[0], currentProgram.getName());
        output.mkdirs();
        boolean rootsMode = args.length > 1 && args[1].equals("roots");
        boolean allCode = args.length > 1 && args[1].equals("all-code");
        long first = !rootsMode && !allCode && args.length > 1 ? Long.parseUnsignedLong(args[1], 16) : 0;
        long last = !rootsMode && !allCode && args.length > 2 ? Long.parseUnsignedLong(args[2], 16) : 0;
        if(allCode) { first=currentProgram.getMemory().getBlock(".text").getStart().getOffset(); last=currentProgram.getMemory().getBlock(".text").getEnd().getOffset(); }
        Set<Long> requested = new HashSet<>();
        if (rootsMode) {
            List<String> addresses = java.nio.file.Files.readAllLines(new File(args[2],currentProgram.getName()+".roots.txt").toPath());
            for (String address : addresses) requested.add(Long.parseUnsignedLong(address.trim(),16));
            File methodsFile = new File(args[2],currentProgram.getName()+".methods.tsv");
            if (methodsFile.exists()) {
                DataType variant = null;
                List<DataType> found = new ArrayList<>();
                currentProgram.getDataTypeManager().findDataTypes("VARIANTARG",found);
                for (DataType candidate : found) if(candidate.getLength()==16) { variant=candidate; break; }
                if(variant==null) variant=new StructureDataType("Oracle_VARIANTARG",16);
                DataType ptr=new PointerDataType(VoidDataType.dataType,4);
                DataType widePtr=new PointerDataType(WideCharDataType.dataType,4);
                for(String line:java.nio.file.Files.readAllLines(methodsFile.toPath())) {
                    String[] parts=line.split("\\t");
                    Function f=currentProgram.getFunctionManager().getFunctionAt(toAddr(Long.parseUnsignedLong(parts[0],16)));
                    if(f==null) continue;
                    ArrayList<Parameter> params=new ArrayList<>();
                    params.add(new ParameterImpl("self",ptr,currentProgram));
                    if(parts[1].equals("CreateField")) {
                        params.add(new ParameterImpl("fieldType",IntegerDataType.dataType,currentProgram));
                        params.add(new ParameterImpl("fontName",widePtr,currentProgram));
                        params.add(new ParameterImpl("fontPitch",IntegerDataType.dataType,currentProgram));
                        params.add(new ParameterImpl("ciffFile",variant,currentProgram));
                        params.add(new ParameterImpl("subImage",widePtr,currentProgram));
                        params.add(new ParameterImpl("fieldName",widePtr,currentProgram));
                        params.add(new ParameterImpl("coderCapabilities",variant,currentProgram));
                        params.add(new ParameterImpl("outField",new PointerDataType(variant,4),currentProgram));
                    } else if(parts[1].equals("GetFieldTypeID")) {
                        params.add(new ParameterImpl("fieldTypeName",widePtr,currentProgram));
                        params.add(new ParameterImpl("outFieldType",ptr,currentProgram));
                    } else if(parts[1].equals("UpdateData")) {
                        params.add(new ParameterImpl("field",variant,currentProgram));
                        params.add(new ParameterImpl("ciffFile",variant,currentProgram));
                    } else if(parts[1].equals("CalculateSize")) {
                        params.add(new ParameterImpl("outSize",ptr,currentProgram));
                        params.add(new ParameterImpl("field",variant,currentProgram));
                        params.add(new ParameterImpl("coderCapabilities",variant,currentProgram));
                        params.add(new ParameterImpl("ciffFile",variant,currentProgram));
                    } else if(parts[1].equals("Resize")) {
                        params.add(new ParameterImpl("position",ptr,currentProgram));
                        params.add(new ParameterImpl("ciffFile",variant,currentProgram));
                        params.add(new ParameterImpl("coderCapabilities",variant,currentProgram));
                        params.add(new ParameterImpl("field",variant,currentProgram));
                    } else continue;
                    f.setCallingConvention("__stdcall");
                    f.setReturnType(IntegerDataType.dataType,SourceType.USER_DEFINED);
                    f.replaceParameters(Function.FunctionUpdateType.DYNAMIC_STORAGE_ALL_PARAMS,true,SourceType.USER_DEFINED,params.toArray(new Parameter[0]));
                }
            }
            Set<Function> frontier = new HashSet<>();
            for (Long address : requested) {
                Function f = currentProgram.getFunctionManager().getFunctionAt(toAddr(address));
                if (f != null) frontier.add(f);
            }
            for (int depth=0;depth<3;depth++) {
                Set<Function> next = new HashSet<>();
                for (Function f : frontier) for (Function called : f.getCalledFunctions(monitor)) {
                    if (called.isExternal() || called.isThunk()) continue;
                    if (!called.getName().startsWith("FUN_")) continue;
                    if (requested.add(called.getEntryPoint().getOffset())) next.add(called);
                }
                frontier=next;
            }
        } else if (args.length > 3) for (String address : java.nio.file.Files.readAllLines(new File(args[3]).toPath())) requested.add(Long.parseUnsignedLong(address.trim(),16));
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try (PrintWriter catalog = new PrintWriter(new File(output, "functions.jsonl"), "UTF-8")) {
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            while (functions.hasNext()) {
                Function function = functions.next();
                long address = function.getEntryPoint().getOffset();
                StringBuilder record = new StringBuilder("{\"address\":" + q(function.getEntryPoint().toString()) + ",\"name\":" + q(function.getName(true)) + ",\"size\":" + function.getBody().getNumAddresses() + ",\"calls\":[");
                boolean comma = false;
                for (Function called : function.getCalledFunctions(monitor)) {
                    if (comma) record.append(','); comma = true;
                    record.append(q(called.getEntryPoint().toString()));
                }
                catalog.println(record.toString() + "]}");
                if (!(address >= first && address <= last) && !requested.contains(address)) continue;
                DecompileResults result = decompiler.decompileFunction(function, 45, monitor);
                try (PrintWriter writer = new PrintWriter(new File(output, "FUN_" + function.getEntryPoint() + ".c"), "UTF-8")) {
                    writer.println("// Source: " + currentProgram.getName() + " @ " + function.getEntryPoint() + "; " + function.getName(true));
                    if (result.decompileCompleted()) writer.println(result.getDecompiledFunction().getC());
                    else writer.println("// ERROR " + result.getErrorMessage());
                }
                try (PrintWriter writer = new PrintWriter(new File(output, "FUN_" + function.getEntryPoint() + ".asm"), "UTF-8")) {
                    InstructionIterator instructions = currentProgram.getListing().getInstructions(function.getBody(), true);
                    while (instructions.hasNext()) {
                        Instruction instruction = instructions.next();
                        writer.println(instruction.getAddress() + " " + instruction.toString());
                    }
                }
            }
        }
        try (PrintWriter writer = new PrintWriter(new File(output, "string-references.jsonl"), "UTF-8")) {
            DataIterator data = currentProgram.getListing().getDefinedData(true);
            while (data.hasNext()) {
                Data item = data.next();
                if (!item.hasStringValue()) continue;
                StringBuilder record = new StringBuilder("{\"address\":" + q(item.getAddress().toString()) + ",\"value\":" + q(String.valueOf(item.getValue())) + ",\"refs\":[");
                boolean comma = false;
                ReferenceIterator references = currentProgram.getReferenceManager().getReferencesTo(item.getAddress());
                while (references.hasNext()) {
                    Reference reference = references.next();
                    Function function = currentProgram.getFunctionManager().getFunctionContaining(reference.getFromAddress());
                    if (comma) record.append(','); comma = true;
                    record.append("{\"from\":" + q(reference.getFromAddress().toString()) + ",\"function\":" + (function == null ? "null" : q(function.getEntryPoint().toString())) + "}");
                }
                writer.println(record.toString() + "]}");
            }
        }
        decompiler.dispose();
        println("EXPORT COMPLETE " + currentProgram.getName());
    }
}
