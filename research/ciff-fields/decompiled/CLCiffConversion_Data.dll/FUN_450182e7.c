// Source: CLCiffConversion_Data.dll @ 450182e7; FUN_450182e7

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_450182e7(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_4501703e(this,param_1), -1 < iVar1)) {
    FUN_4501834e(this);
    iVar1 = FUN_4501703e(this,local_2008);
    if (-1 < iVar1) {
      FUN_4501703e(this,param_1);
    }
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


