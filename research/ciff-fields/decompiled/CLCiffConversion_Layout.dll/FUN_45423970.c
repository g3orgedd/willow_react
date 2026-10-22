// Source: CLCiffConversion_Layout.dll @ 45423970; FUN_45423970

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_45423970(void *this,int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  void *this_00;
  int *piVar2;
  _union_2683 local_2c;
  int *local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_1;
  uStack_4 = 0x1c;
  local_8 = 0x4542397c;
  if (*(char *)((int)this + 0x100) == '\0') {
    iVar1 = (**(code **)(**(int **)((int)this + 0x38) + 0x2c))(*(int **)((int)this + 0x38),param_2);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(**(int **)((int)this + 0x38) + 0x34))
                        (*(int **)((int)this + 0x38),param_3);
    }
  }
  else {
    local_18 = (BSTR)0x0;
    local_8 = 0;
    iVar1 = (**(code **)(*(int *)*param_1 + 0x9c))((int *)*param_1,&local_18);
    if (-1 < iVar1) {
      local_14[0] = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar1 = (**(code **)(*(int *)*piVar2 + 0x4c))((int *)*piVar2,local_14);
      if (-1 < iVar1) {
        this_00 = (void *)FUN_4541b899((void *)(*(int *)((int)this + 0x4c) + 0x4d0),&local_18);
        if (this_00 == (void *)0x0) {
          iVar1 = -0x7fffbffb;
        }
        else {
          piVar2 = FUN_45415515(this_00,(int *)&param_1);
          piVar2 = (int *)*piVar2;
          local_1c = piVar2;
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 4))(piVar2);
          }
          local_8._0_1_ = 2;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
          if (piVar2 == (int *)0x0) {
            iVar1 = -0x7fffbffb;
          }
          else {
            FUN_45429f70((uint *)&local_2c,0,0x10);
            VariantInit((VARIANTARG *)&local_2c.n2);
            local_8._0_1_ = 3;
            iVar1 = (**(code **)(*piVar2 + 0x4c0))(piVar2,local_14[0],&local_2c);
            if (((-1 < iVar1) && (local_2c.n2.vt == 9)) &&
               ((undefined4 *)local_2c._8_4_ != (undefined4 *)0x0)) {
              CComQIPtr<>(&param_1,(undefined4 *)local_2c._8_4_);
              local_8._0_1_ = 4;
              if (param_1 == (int *)0x0) {
                iVar1 = -0x7fffbffb;
              }
              else {
                iVar1 = (**(code **)(*param_1 + 0x2c))(param_1,param_2);
                if (-1 < iVar1) {
                  iVar1 = (**(code **)(*param_1 + 0x34))(param_1,param_3);
                }
              }
              local_8._0_1_ = 3;
              if (param_1 != (int *)0x0) {
                (**(code **)(*param_1 + 8))(param_1);
              }
            }
            VariantClear((VARIANTARG *)&local_2c.n2);
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))(piVar2);
          }
        }
      }
      SysFreeString(local_14[0]);
    }
    SysFreeString(local_18);
  }
  return iVar1;
}


