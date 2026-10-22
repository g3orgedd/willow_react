// Source: CiffMgr.dll @ 6812fe7f; FUN_6812fe7f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6812fe7f(void *this,int *param_1,ULONG param_2,ULONG param_3,PVOID param_4)

{
  int *piVar1;
  int iVar2;
  int *local_14 [3];
  PVOID local_8;
  ULONG UStack_4;
  
  piVar1 = param_1;
  UStack_4 = 4;
  if ((param_1 == (int *)0x0) || (param_4 == (PVOID)0x0)) {
    iVar2 = -0x7fffbffd;
  }
  else {
    param_1 = (int *)0x0;
    local_8 = (PVOID)0x0;
    iVar2 = FUN_68102520(&param_1);
    if (-1 < iVar2) {
      if (param_1 == (int *)0x0) {
        iVar2 = -0x7fffbffb;
      }
      else {
        local_14[0] = piVar1;
        (**(code **)(*piVar1 + 4))(piVar1);
        local_8 = (PVOID)CONCAT31(local_8._1_3_,1);
        if ((param_3 == 1) && (*(int *)((int)this + 8) != 0)) {
          FUN_6811861c(this,(BSTR)local_14);
        }
        iVar2 = FUN_68129209((SAFEARRAY *)&param_1,(SAFEARRAY *)local_14,param_2,(int *)0x0);
        if (-1 < iVar2) {
          iVar2 = (**(code **)(*param_1 + 0x88))(param_1,param_4);
        }
        piVar1 = param_1;
        if (param_1 != (int *)0x0) {
          param_1 = (int *)0x0;
          (**(code **)(*piVar1 + 8))(piVar1);
        }
        local_8 = (PVOID)((uint)local_8 & 0xffffff00);
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
      }
    }
    local_8 = (PVOID)0xffffffff;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  return iVar2;
}


