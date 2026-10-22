// Source: CiffMgr.dll @ 6810e945; FUN_6810e945

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_6810e945(void *this,short *param_1)

{
  int iVar1;
  undefined2 local_2008 [4096];
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  if ((*param_1 == 0x3d) && (iVar1 = FUN_6810d73a(this,param_1), -1 < iVar1)) {
    FUN_6810e9ac(this);
    iVar1 = FUN_6810d73a(this,local_2008);
    if (-1 < iVar1) {
      FUN_6810d73a(this,param_1);
    }
  }
  FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


