// Source: CiffHelper.dll @ 40816c1e; FUN_40816c1e

undefined4 FUN_40816c1e(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  void *pvVar1;
  bool bVar2;
  BSTR pOVar3;
  int *piVar4;
  double *pdVar5;
  int iVar6;
  float10 fVar7;
  int *piVar8;
  int *piVar9;
  undefined1 local_70 [16];
  VARIANTARG local_60;
  VARIANTARG local_50;
  double local_40;
  double local_38;
  OLECHAR local_30 [4];
  double local_28;
  double local_20;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  FUN_40802e76((uint *)&local_60);
  CComQIPtr<>(&local_10,param_4);
  (**(code **)(*local_10 + 100))();
  CComQIPtr<>(&local_8,(undefined4 *)local_60.n1._8_4_);
  pvVar1 = param_1;
  FUN_4081c2ec(param_1,(int *)&local_8);
  piVar9 = local_8;
  (**(code **)(*local_8 + 0x1c))();
  iVar6 = 0;
  if (0 < local_14) {
    do {
      FUN_40802e76((uint *)&local_50);
      iVar6 = iVar6 + 1;
      (**(code **)(*local_8 + 0x30))(local_8,iVar6);
      CComQIPtr<>(&local_c,(undefined4 *)local_50.n1._8_4_);
      FUN_40805bf7(&local_20);
      bVar2 = FUN_4081d4ef();
      if (bVar2) {
        piVar4 = local_c;
        if (local_c != (int *)0x0) {
          (**(code **)(*local_c + 4))(local_c);
        }
        piVar8 = local_10;
        if (local_10 != (int *)0x0) {
          (**(code **)(*local_10 + 4))(local_10);
        }
        pOVar3 = FUN_4080e73f(local_30,piVar8,piVar4);
        piVar4 = FUN_4080e725(local_70,*(int *)pOVar3);
        pdVar5 = FUN_408294b5(&local_38,&local_20,piVar4);
        local_20 = *pdVar5;
      }
      if (pvVar1 == (void *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)((int)pvVar1 + 4);
      }
      fVar7 = FUN_4082fa70(local_20,(short)piVar9);
      local_28 = (double)fVar7;
      FUN_40828cca((void *)((int)&param_1 + 3),&local_40,piVar4,local_8,local_c,&local_28);
      if (local_c != (int *)0x0) {
        (**(code **)(*local_c + 8))();
      }
      VariantClear(&local_50);
    } while (iVar6 < local_14);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))();
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))();
  }
  VariantClear(&local_60);
  return 0;
}


