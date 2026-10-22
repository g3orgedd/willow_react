// Source: CLCiffConversion_Data.dll @ 45027ccc; FUN_45027ccc

void __cdecl FUN_45027ccc(int param_1,DWORD param_2,DWORD param_3)

{
  uint uVar1;
  BOOL BVar2;
  LONG LVar3;
  EXCEPTION_POINTERS local_32c;
  EXCEPTION_RECORD local_324;
  undefined4 local_2d4;
  
  uVar1 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if (param_1 != -1) {
    FUN_4502ebed();
  }
  local_324.ExceptionCode = 0;
  FUN_45021c10(&local_324.ExceptionFlags,0,0x4c);
  local_32c.ExceptionRecord = &local_324;
  local_32c.ContextRecord = (PCONTEXT)&local_2d4;
  local_2d4 = 0x10001;
  local_324.ExceptionCode = param_2;
  local_324.ExceptionFlags = param_3;
  BVar2 = IsDebuggerPresent();
  LVar3 = ___crtUnhandledException(&local_32c);
  if (((LVar3 == 0) && (BVar2 == 0)) && (param_1 != -1)) {
    FUN_4502ebed();
  }
  FUN_45022e32(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}


