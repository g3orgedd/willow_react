// Source: CLARiSOFT.exe @ 00e35f1e; FUN_00e35f1e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e35f1e(void *this,int *param_1,int *param_2,int *param_3,BSTR param_4)

{
  BSTR pOVar1;
  UINT UVar2;
  BSTR this_00;
  int *piVar3;
  int iVar4;
  void *this_01;
  undefined4 *puVar5;
  int *piVar6;
  char cVar7;
  
  if (*(int *)(*(int *)((int)this + 0x1e4) + 8) != 0) {
    if ((char)param_3 == '\0') {
      piVar3 = *(int **)((int)this + 0x160);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))(piVar3);
      }
      FUN_00e56577(*(void **)((int)this + 500),piVar3);
      piVar3 = *(int **)((int)this + 0x160);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))(piVar3);
      }
      FUN_00e0d01c(*(void **)((int)this + 0x1f8),piVar3);
    }
    else {
      if (*(int *)((int)this + 500) != 0) {
        FUN_00e2f27c((int *)((int)this + 500));
      }
      if (*(int *)((int)this + 0x1f8) != 0) {
        FUN_00e2f25e((int *)((int)this + 0x1f8));
      }
      pOVar1 = param_4;
      UVar2 = SysStringLen(*(BSTR *)param_4);
      if (UVar2 == 0) {
        (**(code **)(*param_1 + 0x84))(param_1);
      }
      this_00 = (BSTR)FUN_00eca369(0x18);
      param_4 = this_00;
      if (this_00 == (BSTR)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = *(int **)((int)this + 0x160);
        piVar6 = param_2;
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 4))(piVar3);
        }
        cVar7 = (char)piVar6;
        piVar6 = param_1;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 4))(param_1);
        }
        piVar3 = FUN_00e56184(this_00,(int *)pOVar1,piVar6,piVar3,cVar7);
      }
      param_3 = (int *)0x0;
      *(int **)((int)this + 500) = piVar3;
      iVar4 = (**(code **)(**(int **)((int)this + 0x1a0) + 0x24))(*(int **)((int)this + 0x1a0));
      if ((-1 < iVar4) && (param_3 != (int *)0x0)) {
        CComQIPtr<>(&param_2,param_3);
        if (param_2 != (int *)0x0) {
          param_4 = (BSTR)0x0;
          iVar4 = (**(code **)(*param_1 + 0x38))(param_1);
          if ((-1 < iVar4) && (iVar4 = (**(code **)(*param_2 + 0xb0))(param_2), -1 < iVar4)) {
            this_01 = (void *)FUN_00eca369(0x30);
            if (this_01 == (void *)0x0) {
              puVar5 = (undefined4 *)0x0;
            }
            else {
              piVar3 = param_3;
              if (param_3 != (int *)0x0) {
                (**(code **)(*param_3 + 4))(param_3);
              }
              piVar6 = *(int **)((int)this + 0x160);
              if (piVar6 != (int *)0x0) {
                (**(code **)(*piVar6 + 4))(piVar6);
              }
              puVar5 = FUN_00e09d71(this_01,piVar6,piVar3);
            }
            *(undefined4 **)((int)this + 0x1f8) = puVar5;
          }
          SysFreeString(param_4);
        }
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 8))();
        }
      }
      if (param_3 != (int *)0x0) {
        (**(code **)(*param_3 + 8))();
      }
    }
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  return;
}


