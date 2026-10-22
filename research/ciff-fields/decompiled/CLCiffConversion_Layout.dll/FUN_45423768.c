// Source: CLCiffConversion_Layout.dll @ 45423768; FUN_45423768

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_45423768(void *param_1)

{
  int iVar1;
  int iVar2;
  _union_2683 local_2c;
  int local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x45423774;
  if (*(int *)((int)param_1 + 0x4c) == 0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    FUN_4540303d(0x4544a788);
    FUN_4540303d(0x4544a7a8);
    FUN_4540303d(0x4544a788);
    iVar1 = FUN_454238c8((int)param_1);
    if (-1 < iVar1) {
      iVar2 = 1;
      local_1c = 1;
      iVar1 = (**(code **)(**(int **)((int)param_1 + 0x34) + 0x54))
                        (*(int **)((int)param_1 + 0x34),&local_1c);
      if ((-1 < iVar1) && (local_1c == 0)) {
        local_18 = 0;
        iVar1 = (**(code **)(**(int **)((int)param_1 + 0x34) + 0x1c))
                          (*(int **)((int)param_1 + 0x34),&local_18);
        if (0 < local_18) {
          do {
            if (iVar1 < 0) {
              return iVar1;
            }
            FUN_45429f70((uint *)&local_2c,0,0x10);
            VariantInit((VARIANTARG *)&local_2c.n2);
            local_8 = 0;
            iVar1 = (**(code **)(**(int **)((int)param_1 + 0x34) + 0x24))
                              (*(int **)((int)param_1 + 0x34),iVar2,&local_2c);
            if ((-1 < iVar1) && (local_2c.n2.vt == 9)) {
              CComQIPtr<>(local_14,(undefined4 *)local_2c._8_4_);
              local_8._0_1_ = 1;
              if (local_14[0] != (int *)0x0) {
                iVar1 = FUN_45423890(param_1,(int *)local_14);
              }
              local_8 = (uint)local_8._1_3_ << 8;
              if (local_14[0] != (int *)0x0) {
                (**(code **)(*local_14[0] + 8))(local_14[0]);
              }
            }
            local_8 = 0xffffffff;
            VariantClear((VARIANTARG *)&local_2c.n2);
            iVar2 = iVar2 + 1;
          } while (iVar2 <= local_18);
        }
      }
    }
  }
  return iVar1;
}


