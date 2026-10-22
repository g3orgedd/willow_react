// Source: CLARiSOFT.exe @ 00e35557; FUN_00e35557

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e35557(void *this,int param_1,int *param_2,BSTR param_3)

{
  bool bVar1;
  BSTR extraout_ECX;
  code *pcVar2;
  int *piVar3;
  undefined4 uVar4;
  BSTR pOVar5;
  VARIANTARG local_44;
  VARIANTARG local_34;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int *local_18;
  undefined4 local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  pcVar2 = SysFreeString_exref;
  uStack_4 = 0x34;
  local_8 = 0;
  if (*(int *)((int)this + 0x15c) != 0) {
    FUN_00e01fd0((int *)((int)this + 0x208),&param_1);
    *(int **)((int)this + 0x20c) = param_2;
    *(BSTR *)((int)this + 0x210) = param_3;
    FUN_00eae6d1(local_14);
    uVar4 = *(undefined4 *)((int)this + 0x20c);
    local_8 = CONCAT31(local_8._1_3_,1);
    piVar3 = *(int **)((int)this + 0x15c);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))(piVar3);
    }
    bVar1 = FUN_00eaed3b(piVar3,uVar4);
    param_2 = (int *)CONCAT13(bVar1,param_2._0_3_);
    pOVar5 = extraout_ECX;
    FUN_00e03ab8(&stack0xffffffa8,(int *)((int)this + 0x208));
    piVar3 = *(int **)((int)this + 0x160);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))(piVar3);
    }
    bVar1 = FUN_00eaeb3c(piVar3,pOVar5);
    if ((param_2._3_1_ == '\0') || (!bVar1)) {
      FUN_00e03b51((uint *)&local_44);
      local_8._0_1_ = 2;
      (**(code **)(**(int **)((int)this + 0x160) + 0x474))(*(int **)((int)this + 0x160));
      CComQIPtr<>(&local_18,(undefined4 *)local_44.n1._8_4_);
      local_8 = CONCAT31(local_8._1_3_,3);
      (**(code **)(*local_18 + 0x24))(local_18,&local_1c);
      param_3 = (BSTR)0x0;
      if (0 < local_1c) {
        do {
          FUN_00e03b51((uint *)&local_34);
          param_3 = (BSTR)((int)param_3 + 1);
          local_8._0_1_ = 4;
          (**(code **)(*local_18 + 0x20))(local_18,param_3);
          CComQIPtr<>(&param_2,(undefined4 *)local_34.n1._8_4_);
          local_8 = CONCAT31(local_8._1_3_,5);
          (**(code **)(*param_2 + 0x3c))(param_2,&local_20);
          pcVar2 = SysFreeString_exref;
          piVar3 = *(int **)((int)this + 0x15c);
          uVar4 = local_20;
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 4))(piVar3);
          }
          bVar1 = FUN_00eaed3b(piVar3,uVar4);
          if (bVar1) {
            param_3 = (BSTR)0x0;
            local_8._0_1_ = 6;
            (**(code **)(*param_2 + 0x1c))(param_2);
            (**(code **)(*param_2 + 0x3c))(param_2,&local_24);
            FUN_00e01fd0((void *)((int)this + 0x208),(int *)&param_3);
            *(undefined4 *)((int)this + 0x20c) = local_24;
            SysFreeString(param_3);
            local_8 = CONCAT31(local_8._1_3_,4);
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 8))();
            }
            VariantClear(&local_34);
            break;
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          if (param_2 != (int *)0x0) {
            (**(code **)(*param_2 + 8))();
          }
          VariantClear(&local_34);
        } while ((int)param_3 < local_1c);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))();
      }
      VariantClear(&local_44);
    }
    local_8 = local_8 & 0xffffff00;
    FUN_00eae7b2(local_14);
  }
  (*pcVar2)();
  return;
}


