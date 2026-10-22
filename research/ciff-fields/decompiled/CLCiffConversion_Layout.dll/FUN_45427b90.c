// Source: CLCiffConversion_Layout.dll @ 45427b90; FUN_45427b90

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_45427b90(void *this,char *param_1)

{
  int iVar1;
  undefined1 local_1008 [4096];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == '=') && (iVar1 = FUN_45426781(this,param_1), -1 < iVar1)) {
    FUN_45427bf6(this);
    iVar1 = FUN_45426781(this,local_1008);
    if (-1 < iVar1) {
      FUN_45426781(this,param_1);
    }
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


