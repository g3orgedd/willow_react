// Source: CiffHelper.dll @ 408267f8; FUN_408267f8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_408267f8(int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  VARIANTARG local_30;
  _union_2683 local_20;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_2;
  piVar3 = param_1;
  uStack_4 = 0x20;
  local_8 = 0x40826804;
  if ((*param_1 == 0) || (piVar1 = (int *)*param_2, piVar1 == (int *)0x0)) {
    iVar4 = -0x7fffbffd;
  }
  else {
    param_1 = (int *)0x0;
    iVar4 = (**(code **)(*piVar1 + 0x24))(piVar1,&param_1);
    if ((-1 < iVar4) && (param_1 == (int *)0x1)) {
      FUN_40802e76((uint *)&local_20);
      local_8 = 0;
      iVar4 = (**(code **)(*(int *)*piVar2 + 0x2c))((int *)*piVar2,&local_20);
      if (-1 < iVar4) {
        if (local_20.n2.vt == 3) {
          local_20._8_4_ = local_20._8_4_ * 100;
        }
        piVar2 = (int *)*piVar3;
        iVar4 = (**(code **)(*piVar2 + 0x2c))(piVar2,*param_3);
        if (-1 < iVar4) {
          FUN_40802e76((uint *)&local_30);
          piVar3 = (int *)*piVar3;
          local_8 = CONCAT31(local_8._1_3_,1);
          iVar4 = (**(code **)(*piVar3 + 0x28))
                            (piVar3,*param_4,param_1,local_20._0_4_,local_20.decVal.Hi32,
                             local_20._8_4_,local_20._12_4_,&local_30);
          VariantClear(&local_30);
        }
      }
      VariantClear((VARIANTARG *)&local_20.n2);
    }
  }
  return iVar4;
}


