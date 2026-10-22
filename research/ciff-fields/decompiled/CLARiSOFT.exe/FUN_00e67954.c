// Source: CLARiSOFT.exe @ 00e67954; FUN_00e67954

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e67954(void *this,void *param_1,int *param_2)

{
  void *this_00;
  char cVar1;
  HRESULT HVar2;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR pOVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  BSTR *ppOVar7;
  BSTR local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  if (param_1 != (void *)0x0) {
    local_14[0] = (BSTR)0x0;
    ppOVar7 = local_14;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    piVar5 = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    FUN_00e61bd8(param_1,piVar5,ppOVar7);
    iVar4 = 0;
    local_18 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,2);
    piVar5 = (int *)**(int **)((int)this + 0x10);
    if (piVar5 != *(int **)((int)this + 0x10)) {
      do {
        this_00 = (void *)piVar5[2];
        cVar1 = FUN_00e62111((int)this_00);
        pOVar3 = extraout_ECX;
        if (cVar1 != '\0') {
          ppOVar7 = &local_18;
          piVar6 = param_2;
          if (param_2 != (int *)0x0) {
            (**(code **)(*param_2 + 4))(param_2);
          }
          FUN_00e61bd8(this_00,piVar6,ppOVar7);
          HVar2 = VarBstrCmp(local_18,local_14[0],0x400,0);
          pOVar3 = extraout_ECX_00;
          if (HVar2 == 1) {
            iVar4 = iVar4 + 1;
          }
        }
        piVar5 = (int *)*piVar5;
      } while (piVar5 != (int *)*(int *)((int)this + 0x10));
      if (iVar4 == 1) {
        FUN_00e03ab8(&stack0xffffffc8,(int *)local_14);
        piVar5 = param_2;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 4))(param_2);
        }
        FUN_00e62982(param_1,piVar5,pOVar3);
      }
    }
    SysFreeString(local_18);
    SysFreeString(local_14[0]);
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))();
  }
  return;
}


