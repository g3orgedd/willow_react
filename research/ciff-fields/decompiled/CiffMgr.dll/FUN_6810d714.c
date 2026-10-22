// Source: CiffMgr.dll @ 6810d714; FUN_6810d714

undefined4 __thiscall FUN_6810d714(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_6810d3fa(this,param_1);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    puVar3 = (undefined4 *)FUN_6810d59a(this,iVar1);
    uVar2 = *puVar3;
  }
  return uVar2;
}


