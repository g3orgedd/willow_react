// Source: CiffMgr.dll @ 6812fd3a; FUN_6812fd3a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ULONG __thiscall FUN_6812fd3a(void *this,int *param_1,int *param_2,ULONG param_3)

{
  int *piVar1;
  ULONG UVar2;
  _union_2683 local_24;
  int *local_14 [3];
  PVOID local_8;
  ULONG UStack_4;
  
  piVar1 = param_1;
  UStack_4 = 0x14;
  if ((param_3 == 0) || (param_1 == (int *)0x0)) {
    UVar2 = 0x80004003;
  }
  else {
    param_1 = (int *)0x0;
    local_8 = (PVOID)0x0;
    UVar2 = FUN_68102520(&param_1);
    if (-1 < (int)UVar2) {
      if (param_1 == (int *)0x0) {
        UVar2 = 0x80004005;
      }
      else {
        local_14[0] = piVar1;
        (**(code **)(*piVar1 + 4))(piVar1);
        local_8 = (PVOID)CONCAT31(local_8._1_3_,1);
        UVar2 = FUN_6811861c(this,(BSTR)local_14);
        if ((-1 < (int)UVar2) &&
           (UVar2 = FUN_68129209((SAFEARRAY *)&param_1,(SAFEARRAY *)local_14,(int)param_2,(int *)0x1
                                ), -1 < (int)UVar2)) {
          FUN_6812e1be(&param_2);
          piVar1 = param_2;
          if (param_2 != (int *)0x0) {
            (**(code **)(*param_2 + 4))(param_2);
          }
          local_8._0_1_ = 2;
          if (piVar1 != (int *)0x0) {
            local_24.n2.vt = 0xd;
            local_24._8_4_ = piVar1;
            (**(code **)(*piVar1 + 4))(piVar1);
            local_8._0_1_ = 3;
            UVar2 = (**(code **)(*param_1 + 0x108))
                              (param_1,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,
                               local_24._12_4_);
            if (-1 < (int)UVar2) {
              UVar2 = (**(code **)(*piVar1 + 0x38))(piVar1,param_3);
            }
            VariantClear((VARIANTARG *)&local_24.n2);
          }
          local_8 = (PVOID)CONCAT31(local_8._1_3_,1);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
          }
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
  return UVar2;
}


