// Source: CLCiffConversion_Data.dll @ 45016f42; FUN_45016f42

undefined4 __thiscall FUN_45016f42(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_450165f9(this,param_1);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    puVar3 = (undefined4 *)FUN_45016a80(this,iVar1);
    uVar2 = *puVar3;
  }
  return uVar2;
}


