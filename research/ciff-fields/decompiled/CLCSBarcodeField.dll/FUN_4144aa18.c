// Source: CLCSBarcodeField.dll @ 4144aa18; FUN_4144aa18

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_4144aa18(void *this,int *param_1,undefined4 param_2,int param_3,BSTR param_4,char param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int local_20 [3];
  void *local_14;
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  uVar3 = 0xffffffff;
  local_8 = 0;
  uStack_7 = 0;
  if (param_1 == (int *)0x13) {
    param_1 = (int *)FUN_41460343(0xc70);
    local_8 = 1;
    if (param_1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = FUN_41448049(param_1,param_2,param_3,0x16,(uint)(param_5 != '\0'));
    }
    local_8 = 0;
  }
  else {
    if (param_1 != (int *)0x14) goto LAB_4144ab4a;
    CComQIPtr<>(&param_1,*(undefined4 **)((int)this + 0xf4));
    local_8 = 2;
    if (param_1 != (int *)0x0) {
      piVar1 = (int *)((int)this + 0x9c);
      (**(code **)(*param_1 + 0x174))(param_1,piVar1);
      iVar2 = *piVar1;
      if (*piVar1 < 2) {
        iVar2 = 2;
      }
      if (0x16 < iVar2) {
        iVar2 = 0x16;
      }
      *piVar1 = iVar2;
    }
    local_14 = (void *)FUN_41460343(0xc70);
    local_8 = 3;
    if (local_14 == (void *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = FUN_41448049(local_14,param_2,param_3,*(undefined4 *)((int)this + 0x9c),
                            (uint)(param_5 != '\0'));
    }
    local_8 = 0;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  if (piVar1 != (int *)0x0) {
    local_20[0] = 0;
    local_20[1] = 0;
    local_20[2] = 0;
    local_8 = 4;
    iVar2 = (**(code **)(*piVar1 + 4))(&param_4,local_20,(int)this + 0x74);
    if (-1 < iVar2) {
      uVar3 = (**(code **)(*piVar1 + 0xc))();
    }
    (**(code **)*piVar1)(1);
    FUN_41449652(local_20);
  }
LAB_4144ab4a:
  SysFreeString(param_4);
  return uVar3;
}


