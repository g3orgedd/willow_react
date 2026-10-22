// Source: CiffHelper.dll @ 40816f44; FUN_40816f44

undefined4
FUN_40816f44(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  VARIANTARG local_3c;
  VARIANTARG local_2c;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  CComQIPtr<>(&local_14,param_4);
  local_10 = 0;
  uVar1 = (**(code **)(*local_14 + 0x1c))(local_14,&local_10);
  iVar2 = 0;
  if (0 < local_10) {
    do {
      FUN_40802e76((uint *)&local_3c);
      iVar2 = iVar2 + 1;
      local_1c = iVar2;
      (**(code **)(*local_14 + 0x24))(local_14,iVar2,&local_3c);
      CComQIPtr<>(&local_c,(undefined4 *)local_3c.n1._8_4_);
      local_8 = 0;
      uVar1 = (**(code **)(*local_c + 0x1c))(local_c,&local_8);
      iVar3 = 0;
      if (0 < local_8) {
        do {
          FUN_40802e76((uint *)&local_2c);
          local_18 = iVar3 + 1;
          (**(code **)(*local_c + 0x24))(local_c,local_18,&local_2c);
          iVar2 = param_1[0x1e];
          *(undefined1 *)(param_1 + 0x1e) = 0;
          uVar1 = (**(code **)(*param_1 + 0xa0))
                            (param_1,&local_2c,param_2,param_3,param_4,param_5,param_6);
          *(char *)(param_1 + 0x1e) = (char)iVar2;
          VariantClear(&local_2c);
          iVar2 = local_1c;
          iVar3 = local_18;
        } while (local_18 < local_8);
      }
      if (local_c != (int *)0x0) {
        (**(code **)(*local_c + 8))(local_c);
      }
      VariantClear(&local_3c);
    } while (iVar2 < local_10);
  }
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  return uVar1;
}


