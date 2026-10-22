// Source: CLARiSOFT.exe @ 00e3532f; FUN_00e3532f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_00e3532f(int param_1)

{
  int *this;
  int iVar1;
  _union_2683 local_28;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  this = (int *)(param_1 + 0x160);
  if ((*this == 0) || (*(int *)(param_1 + 0x15c) == 0)) {
    iVar1 = -0x7fffbffd;
  }
  else {
    local_18 = (BSTR)0x0;
    local_8 = 0;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x15c) + 0x1c))(*(int **)(param_1 + 0x15c),&local_18);
    if (-1 < iVar1) {
      FUN_00e03b51((uint *)&local_28);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar1 = (**(code **)(*(int *)*this + 0x4c0))((int *)*this,local_18,&local_28);
      if (((-1 < iVar1) && (local_28.n2.vt == 9)) &&
         ((undefined4 *)local_28._8_4_ != (undefined4 *)0x0)) {
        CComQIPtr<>(local_14,(undefined4 *)local_28._8_4_);
        if (local_14[0] != (int *)0x0) {
          FUN_00e11de5(this,(int *)local_14);
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
        }
      }
      VariantClear((VARIANTARG *)&local_28.n2);
    }
    SysFreeString(local_18);
  }
  return iVar1;
}


