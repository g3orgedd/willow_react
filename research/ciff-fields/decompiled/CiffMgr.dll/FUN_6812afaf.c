// Source: CiffMgr.dll @ 6812afaf; FUN_6812afaf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6812afaf(BSTR param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 8;
  local_8 = 0x6812afbb;
  local_14[0] = 0;
  iVar2 = (**(code **)(*(int *)*param_2 + 0x1c))((int *)*param_2,local_14);
  if ((-1 < iVar2) && (0 < local_14[0])) {
    param_2 = (int *)0x0;
    local_8 = 0;
    iVar2 = (**(code **)(**(int **)param_1 + 0xbc))
                      (*(int **)param_1,PTR_u_Parameters_6815fefc,&param_2);
    if ((-1 < iVar2) &&
       ((param_2 != (int *)0x0 && (iVar2 = FUN_6812adb8(param_1,piVar1,&param_2), iVar2 == 0)))) {
      iVar2 = (**(code **)(*(int *)*param_3 + 0x54))((int *)*param_3,param_2,0);
    }
    local_8 = 0xffffffff;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
  }
  return iVar2;
}


