// Source: CLPrintPreview.ocx @ 3f4175db; FUN_3f4175db

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_3f4175db(void *this,short param_1,undefined4 param_2,int *param_3,undefined4 param_4,
            short param_5,undefined4 param_6,int *param_7,undefined4 param_8,short param_9,
            undefined4 param_10,OLECHAR *param_11,undefined4 param_12,short param_13,
            undefined4 param_14,OLECHAR *param_15,undefined4 param_16,short param_17,
            undefined4 param_18,OLECHAR *param_19,undefined4 param_20,short param_21,
            undefined4 param_22,OLECHAR *param_23,undefined4 param_24,int param_25)

{
  int *this_00;
  int iVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  code *pcVar4;
  _union_2683 local_48;
  _union_2683 local_38;
  HCURSOR local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_1c;
  LPVOID *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x3f4175e7;
  uVar3 = 0;
  *(undefined4 *)((int)this + 0x1dc) = 0;
  local_1c = this;
  if ((param_13 == 8) && (param_17 == 8)) {
    FUN_3f4059a8((void *)((int)this + 0x118),param_15);
    FUN_3f4059a8((void *)((int)this + 0x120),param_19);
  }
  local_24 = 0;
  local_20 = 0;
  local_28 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
  FUN_3f4153c1(&local_28);
  local_8 = 0;
  if (param_1 == 9) {
    FUN_3f40a273((void *)((int)this + 0xe0),param_3);
  }
  if (param_5 == 9) {
    this_00 = (int *)((int)this + 0xe4);
    FUN_3f40a273(this_00,param_7);
    if (*this_00 != 0) {
      FUN_3f4272e0((uint *)&local_48,0,0x10);
      VariantInit((VARIANTARG *)&local_48.n2);
      local_8._0_1_ = 1;
      iVar1 = (**(code **)(*(int *)*this_00 + 0x3c))((int *)*this_00,&local_48);
      if ((-1 < iVar1) && (local_48.n2.vt == 9)) {
        CComQIPtr<>(local_14,(undefined4 *)local_48._8_4_);
        if (local_14[0] != (int *)0x0) {
          FUN_3f4272e0((uint *)&local_38,0,0x10);
          VariantInit((VARIANTARG *)&local_38.n2);
          local_8._0_1_ = 3;
          iVar1 = (**(code **)(*local_14[0] + 0x30))
                            (local_14[0],*(undefined4 *)((int)this + 0x118),&local_38);
          if ((-1 < iVar1) && (local_38.n2.vt == 9)) {
            FUN_3f40a273((void *)((int)this + 0xe8),(int *)local_38._8_4_);
          }
          VariantClear((VARIANTARG *)&local_38.n2);
        }
        local_8._0_1_ = 1;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      VariantClear((VARIANTARG *)&local_48.n2);
    }
    if (*(int *)((int)this + 0xe8) == 0) {
      uVar3 = 0x80004003;
    }
    else {
      if (param_9 == 8) {
        FUN_3f4059a8((void *)((int)this + 0x11c),param_11);
      }
      if (param_17 == 8) {
        FUN_3f4272e0((uint *)&local_38,0,0x10);
        VariantInit((VARIANTARG *)&local_38.n2);
        local_8._0_1_ = 4;
        iVar1 = (**(code **)(**(int **)((int)this + 0xe8) + 0x470))
                          (*(int **)((int)this + 0xe8),&local_38);
        if ((-1 < iVar1) && (local_38.n2.vt == 9)) {
          local_18 = (LPVOID *)local_38._8_4_;
          if ((LPVOID *)local_38._8_4_ != (LPVOID *)0x0) {
            (**(code **)((int)*(LPVOID *)local_38._8_4_ + 4))(local_38._8_4_);
            FUN_3f4272e0((uint *)&local_48,0,0x10);
            VariantInit((VARIANTARG *)&local_48.n2);
            local_8._0_1_ = 6;
            iVar1 = (**(code **)((int)*(LPVOID *)local_38._8_4_ + 0x30))
                              (local_38._8_4_,*(undefined4 *)((int)this + 0x120),&local_48);
            if ((-1 < iVar1) && (local_48.n2.vt == 9)) {
              FUN_3f40a273((void *)((int)this + 0x124),(int *)local_48._8_4_);
              FUN_3f417eee((int)this);
            }
            VariantClear((VARIANTARG *)&local_48.n2);
          }
          local_8._0_1_ = 4;
          if ((LPVOID *)local_38._8_4_ != (LPVOID *)0x0) {
            (**(code **)((int)*(LPVOID *)local_38._8_4_ + 8))(local_38._8_4_);
          }
        }
        local_8 = (uint)local_8._1_3_ << 8;
        VariantClear((VARIANTARG *)&local_38.n2);
      }
      if (param_21 == 8) {
        FUN_3f4059a8((void *)((int)this + 0x128),param_23);
      }
      pcVar4 = CoCreateInstance_exref;
      if ((((*(LPVOID *)((int)this + 0xec) == (LPVOID)0x0) &&
           (HVar2 = CoCreateInstance((IID *)&DAT_3f4414b8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_3f44333c,
                                     (LPVOID *)((int)this + 0xec)), -1 < HVar2)) &&
          (local_18 = (LPVOID *)((int)this + 0x108), *local_18 == (LPVOID)0x0)) &&
         (HVar2 = CoCreateInstance((IID *)&DAT_3f441248,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_3f44334c,
                                   local_18), -1 < HVar2)) {
        CComQIPtr<>(local_14,*(undefined4 **)((int)this + 0xec));
        local_8._0_1_ = 7;
        if (local_14[0] != (int *)0x0) {
          local_48.n2.vt = 9;
          local_48._8_4_ = *local_18;
          if ((int *)local_48._8_4_ != (int *)0x0) {
            (**(code **)(*(int *)local_48._8_4_ + 4))(local_48._8_4_);
          }
          local_8._0_1_ = 8;
          (**(code **)(*local_14[0] + 0xc))
                    (local_14[0],local_48._0_4_,local_48.decVal.Hi32,local_48._8_4_,local_48._12_4_)
          ;
          VariantClear((VARIANTARG *)&local_48.n2);
          pcVar4 = CoCreateInstance_exref;
          this = local_1c;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
      }
      if (*(int *)((int)this + 0xf0) == 0) {
        (*pcVar4)(&DAT_3f4414e4,0,0x17,&DAT_3f44333c,(int *)((int)this + 0xf0));
      }
      if (*(int *)((int)this + 0xf4) == 0) {
        (*pcVar4)(&DAT_3f441238,0,0x17,&DAT_3f44333c,(int *)((int)this + 0xf4));
      }
      if (*(int *)((int)this + 0xf8) == 0) {
        (*pcVar4)(&DAT_3f4414f4,0,0x17,&DAT_3f44333c,(int *)((int)this + 0xf8));
      }
      if (*(int *)((int)this + 0xfc) == 0) {
        (*pcVar4)(&DAT_3f4411c4,0,0x17,&DAT_3f44333c,(int *)((int)this + 0xfc));
      }
      if (*(int *)((int)this + 0x100) == 0) {
        (*pcVar4)(&DAT_3f441510,0,0x17,&DAT_3f44333c,(int *)((int)this + 0x100));
      }
      if (*(int *)((int)this + 0x104) == 0) {
        (*pcVar4)(&DAT_3f4411d4,0,0x17,&DAT_3f44333c,(int *)((int)this + 0x104));
      }
      *(undefined4 *)((int)this + 0x178) = 0;
      *(undefined4 *)((int)this + 0x180) = 0;
      *(undefined4 *)((int)this + 0x1d4) = 1;
      *(undefined4 *)((int)this + 0x1d8) = 1;
      FUN_3f414b05((int)this);
      if (param_25 == 1) {
        FUN_3f4169ef((int)this);
      }
      FUN_3f40d1f7((int)this + 4);
      FUN_3f4033f3((void *)((int)this + 300),(char *)&PTR_3f440d00);
    }
  }
  else {
    uVar3 = 0x80004005;
  }
  FUN_3f4153a2((int)&local_28);
  return uVar3;
}


