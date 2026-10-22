// Export the ClStVersionInfo implementation without modifying the source DLL.
// @category Glyph.Research
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import java.io.PrintWriter;
import java.io.File;

public class ExportClst extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        File output = new File(args[0]);
        output.mkdirs();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        Address start = toAddr(0x68117700L);
        Address end = toAddr(0x68119100L);
        try (PrintWriter asm = new PrintWriter(new File(output, "clst-disassembly.txt"), "UTF-8")) {
            InstructionIterator instructions = currentProgram.getListing().getInstructions(new AddressSet(start, end), true);
            while (instructions.hasNext()) {
                Instruction instruction = instructions.next();
                asm.println(instruction.getAddress() + " " + instruction.toString());
            }
        }
        FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
        while (functions.hasNext()) {
            Function function = functions.next();
            long address = function.getEntryPoint().getOffset();
            boolean extra = address == 0x6810a989L || address == 0x6810a9b5L ||
                address == 0x6810207eL || address == 0x68134d99L || address == 0x68134dbaL;
            if (!extra && (address < 0x68117700L || address > 0x68118ea0L)) continue;
            DecompileResults result = decompiler.decompileFunction(function, 60, monitor);
            try (PrintWriter writer = new PrintWriter(new File(output, "FUN_" + function.getEntryPoint() + ".c"), "UTF-8")) {
                writer.println("// " + currentProgram.getName() + " entry=" + function.getEntryPoint());
                if (result.decompileCompleted()) writer.println(result.getDecompiledFunction().getC());
                else writer.println("// ERROR " + result.getErrorMessage());
            }
            println("EXPORTED " + function.getName());
        }
        decompiler.dispose();
    }
}
