// Source: CLARiSOFT.exe @ 00e34641; FUN_00e34641

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_00e34641(void *param_1)

{
  BSTR this;
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  void *this_00;
  int *piVar5;
  int *piVar6;
  BSTR pOVar7;
  BSTR pOVar8;
  BSTR pOVar9;
  undefined4 local_58 [10];
  int local_30;
  int local_2c;
  int local_28;
  LPCWSTR local_24;
  LPCWSTR local_20;
  int local_1c;
  undefined4 *local_18;
  char local_11 [9];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0xe3464d;
  piVar1 = (int *)FUN_00e77808((void *)((int)param_1 + 4),0);
  if (*piVar1 == 0) {
    this_00 = (void *)0x0;
  }
  else {
    this_00 = (void *)(*piVar1 + -100);
  }
  iVar2 = FUN_00e3e85d((int)this_00);
  iVar2 = FUN_00e68567(*(int *)(*(int *)((int)param_1 + 400) + iVar2 * 4));
  local_28 = iVar2;
  iVar3 = FUN_00e3e85d((int)this_00);
  FUN_00e68547(*(void **)(*(int *)((int)param_1 + 400) + iVar3 * 4),&local_18);
  if (0 < iVar2) {
    do {
      this = (BSTR)local_18[2];
      local_18 = (undefined4 *)*local_18;
      FUN_00eaf8d8(local_58);
      local_8 = 0;
      pOVar9 = (BSTR)local_11;
      pOVar8 = (BSTR)0x0;
      pOVar7 = *(BSTR *)((int)param_1 + 0x19c);
      local_11[0] = '\x01';
      if (pOVar7 != (BSTR)0x0) {
        (**(code **)(*(int *)pOVar7 + 4))(pOVar7);
      }
      piVar1 = *(int **)((int)param_1 + 0x160);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      piVar6 = (int *)((int)param_1 + 0x15c);
      piVar5 = *(int **)(this + 2);
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 4))(piVar5);
      }
      FUN_00eb1420(local_58,piVar5,piVar6,piVar1,pOVar7,pOVar8,pOVar9);
      if (local_11[0] == '\0') {
        FUN_00e616d4(this,&local_24);
        local_8._0_1_ = 1;
        FUN_00e03bc2(&local_1c,L"Cannot display ");
        local_8._0_1_ = 2;
        puVar4 = FUN_00e28cb6(&local_30,&local_1c,local_24);
        local_8._0_1_ = 3;
        puVar4 = FUN_00e28cb6(&local_2c,puVar4,
                              L" because this field type is not supported by the target coder.");
        local_8._0_1_ = 4;
        FUN_00e03b21(&local_20,(OLECHAR *)*puVar4);
        FUN_00e01f81(&local_2c);
        FUN_00e01f81(&local_30);
        local_8 = CONCAT31(local_8._1_3_,8);
        FUN_00e01f81(&local_1c);
        MessageBoxW((HWND)0x0,local_20,L"ERROR",0);
        FUN_00e41bff(this_00,(int)this);
        FUN_00e2ca77(param_1,this);
        SysFreeString(local_20);
        SysFreeString(local_24);
      }
      else {
        piVar1 = *(int **)((int)param_1 + 0x19c);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        piVar6 = *(int **)((int)param_1 + 0x160);
        if (piVar6 != (int *)0x0) {
          (**(code **)(*piVar6 + 4))(piVar6);
        }
        FUN_00e631d6(this,piVar6,piVar1);
      }
      local_8 = 0xffffffff;
      FUN_00eafabc(local_58);
      local_28 = local_28 + -1;
    } while (local_28 != 0);
  }
  return;
}


