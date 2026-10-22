// Source: CLARiSOFT.exe @ 00e353ea; FUN_00e353ea

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_00e353ea(void *this,int *param_1)

{
  int *this_00;
  int *piVar1;
  int iVar2;
  _union_2683 local_34;
  _union_2683 local_24;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0xe353f6;
  this_00 = (int *)((int)this + 0x160);
  piVar1 = (int *)*this_00;
  if (piVar1 != (int *)0x0) {
    *this_00 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_00e03b51((uint *)&local_34);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  iVar2 = (**(code **)(**(int **)((int)this + 0x1e0) + 0x3c))
                    (*(int **)((int)this + 0x1e0),&local_34);
  if (((-1 < iVar2) && (local_34.n2.vt == 9)) && ((undefined4 *)local_34._8_4_ != (undefined4 *)0x0)
     ) {
    CComQIPtr<>(local_14,(undefined4 *)local_34._8_4_);
    if (local_14[0] == (int *)0x0) {
      iVar2 = -0x7fffbffb;
    }
    else {
      FUN_00e03b51((uint *)&local_24);
      local_8._0_1_ = 2;
      iVar2 = (**(code **)(*local_14[0] + 0x30))(local_14[0],*param_1,&local_24);
      if (((-1 < iVar2) && (local_24.n2.vt == 9)) &&
         ((undefined4 *)local_24._8_4_ != (undefined4 *)0x0)) {
        CComQIPtr<>(&param_1,(undefined4 *)local_24._8_4_);
        local_8._0_1_ = 3;
        if (param_1 == (int *)0x0) {
          iVar2 = -0x7fffbffb;
        }
        else {
          FUN_00e11de5(this_00,(int *)&param_1);
          (**(code **)(*(int *)*this_00 + 0x6c))((int *)*this_00,(int)this + 0x164);
        }
        local_8._0_1_ = 2;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      VariantClear((VARIANTARG *)&local_24.n2);
    }
    local_8._0_1_ = 0;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  VariantClear((VARIANTARG *)&local_34.n2);
  return iVar2;
}


