// Source: CiffHelper.dll @ 40816672; FUN_40816672

bool FUN_40816672(void *param_1,int *param_2)

{
  undefined4 uVar1;
  VARIANTARG local_18;
  int *local_8;
  
  CComQIPtr<>(&local_8,(undefined4 *)param_2[2]);
  FUN_40802e76((uint *)&local_18);
  (**(code **)(*local_8 + 100))(local_8,&local_18);
  CComQIPtr<>(&param_2,(undefined4 *)local_18.n1._8_4_);
  uVar1 = FUN_4081c2ec(param_1,(int *)&param_2);
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  VariantClear(&local_18);
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return (char)uVar1 == '\0';
}


