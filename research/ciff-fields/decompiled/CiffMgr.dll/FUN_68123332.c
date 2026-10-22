// Source: CiffMgr.dll @ 68123332; FUN_68123332

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68123332(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  VARIANTARG local_44;
  _union_2683 local_34;
  BSTR local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x34;
  local_8 = 0x6812333e;
  if (param_1 == (int *)0x0) {
    iVar3 = -0x7fffbffd;
  }
  else {
    do {
      puVar2 = param_2;
      local_1c = 0;
      (**(code **)(*(int *)*param_2 + 0x20))((int *)*param_2,&local_1c);
      if (local_1c == 0) {
        return 0;
      }
      param_1 = (int *)0x0;
      local_8 = 0;
      iVar3 = (**(code **)(*(int *)*puVar2 + 0x24))((int *)*puVar2,&param_1);
      if ((iVar3 == 0) && (param_1 != (int *)0x0)) {
        FUN_68132710((uint *)&local_34,0,0x10);
        VariantInit((VARIANTARG *)&local_34.n2);
        local_18 = (int *)0x0;
        local_8._0_1_ = 2;
        iVar3 = (**(code **)(*param_1 + 0x44))(param_1,&local_18);
        if ((-1 < iVar3) && (local_18 != (int *)0x0)) {
          local_14[0] = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,3);
          iVar4 = (**(code **)(*local_18 + 0x1c))(local_18,PTR_DAT_68160100,local_14);
          if ((-1 < iVar4) && (local_14[0] != (int *)0x0)) {
            (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_34);
          }
          local_8._0_1_ = 2;
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
        }
        iVar4 = (**(code **)(*param_1 + 0x68))(param_1,&local_24);
        if (-1 < iVar3) {
          FUN_68132710((uint *)&local_44,0,0x10);
          VariantInit(&local_44);
          local_8._0_1_ = 4;
          iVar4 = (**(code **)(*piVar1 + 0x28))(piVar1,local_24,&local_44);
          CComQIPtr<>(&local_20,(undefined4 *)local_44.n1._8_4_);
          local_8._0_1_ = 5;
          if ((local_20 != (int *)0x0) && (local_34.n2.vt == 8)) {
            (**(code **)(*local_20 + 0x28))(local_20,local_34._8_4_);
          }
          local_8._0_1_ = 4;
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
          }
          VariantClear(&local_44);
        }
        SysFreeString(local_24);
        local_8 = CONCAT31(local_8._1_3_,1);
        if (iVar4 < 0) {
          iVar3 = iVar4;
        }
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        VariantClear((VARIANTARG *)&local_34.n2);
      }
      local_8 = 0xffffffff;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    } while (iVar3 == 0);
  }
  return iVar3;
}


