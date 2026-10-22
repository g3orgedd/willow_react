// Source: CLCiffConversion_Data.dll @ 4500a544; FUN_4500a544

void __cdecl FUN_4500a544(int param_1,int param_2,undefined4 *param_3)

{
  wchar_t *pwVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 local_10 [2];
  int local_8;
  
  puVar3 = param_3;
  if (param_1 != param_2) {
    do {
      piVar4 = (int *)*puVar3;
      pwVar1 = (wchar_t *)(param_1 + 0x10);
      iVar2 = *piVar4;
      piVar4 = (int *)FUN_45007e32(piVar4,&local_8,pwVar1);
      if (*piVar4 == iVar2) {
        FUN_4500a6bc((void *)*puVar3,local_10,(undefined4 *)0x0,pwVar1,(uint)DAT_450538df);
      }
      FUN_45005947(&param_1);
    } while (param_1 != param_2);
  }
  return;
}


