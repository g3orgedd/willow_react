// Source: CLCSTextBasedField.dll @ 42459491; FUN_42459491

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_42459491(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  iVar2 = 0;
  if (param_3 != (int *)0x0) {
    local_14[0] = 0;
    iVar1 = (**(code **)(*param_3 + 0x4ec))(param_3,local_14);
    if ((-1 < iVar1) && (iVar2 = param_1, local_14[0] != 0)) {
      piVar3 = param_3;
      if (param_3 != (int *)0x0) {
        (**(code **)(*param_3 + 4))(param_3);
      }
      iVar2 = FUN_424589da(param_1,0.0,piVar3);
    }
  }
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  return iVar2;
}


