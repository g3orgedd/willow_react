// Source: CiffMgr.dll @ 681208e1; FUN_681208e1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_681208e1(void *this,int *param_1,undefined4 *param_2)

{
  IUnknownVtbl *pIVar1;
  IUnknown *This;
  int iVar2;
  int iVar3;
  IID *riid;
  void **in_stack_ffffff94;
  VARIANTARG local_5c;
  _union_2683 local_4c;
  _union_2683 local_3c;
  void *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  IUnknown *local_18;
  int *local_14 [3];
  int *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_2c = this;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    do {
      local_20 = (int *)0x0;
      local_8 = local_20;
      iVar2 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_20);
      if ((iVar2 == 0) && (local_20 != (int *)0x0)) {
        local_18 = (IUnknown *)0x0;
        local_14[0] = (int *)0x0;
        local_8._0_1_ = 2;
        iVar3 = (**(code **)(*local_20 + 0x44))(local_20,local_14);
        if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
          local_24 = (int *)0x0;
          local_8._0_1_ = 3;
          iVar3 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_Name_68160030,&local_24);
          if ((-1 < iVar3) && (local_24 != (int *)0x0)) {
            FUN_68132710((uint *)&local_3c,0,0x10);
            VariantInit((VARIANTARG *)&local_3c.n2);
            local_8._0_1_ = 4;
            iVar3 = (**(code **)(*local_24 + 0x20))(local_24,&local_3c);
            if ((local_3c.n2.vt == 8) &&
               (((short *)local_3c._8_4_ != (short *)0x0 && (*(short *)local_3c._8_4_ != 0)))) {
              FUN_68132710((uint *)&local_5c,0,0x10);
              VariantInit(&local_5c);
              local_8._0_1_ = 5;
              iVar3 = (**(code **)(*param_1 + 0x20))(param_1,local_3c._8_4_,&local_5c);
              *(undefined4 *)((int)local_2c + 4) = 1;
              if ((-1 < iVar3) && (local_18 != (IUnknown *)local_5c.n1._8_4_)) {
                ATL::AtlComQIPtrAssign
                          (&local_18,(IUnknown *)local_5c.n1._8_4_,(_GUID *)&DAT_6814b8d4);
              }
              VariantClear(&local_5c);
            }
            VariantClear((VARIANTARG *)&local_3c.n2);
          }
          if (local_18 != (IUnknown *)0x0) {
            local_1c = (int *)0x0;
            local_8._0_1_ = 6;
            iVar3 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_Type_6816003c,&local_1c);
            if ((iVar3 == 0) && (local_1c != (int *)0x0)) {
              FUN_68132710((uint *)&local_4c,0,0x10);
              VariantInit((VARIANTARG *)&local_4c.n2);
              local_8._0_1_ = 7;
              iVar3 = (**(code **)(*local_1c + 0x20))(local_1c,&local_4c);
              This = local_18;
              if (local_4c.n2.vt == 8) {
                pIVar1 = local_18->lpVtbl;
                riid = (IID *)FUN_6812f511((wchar_t *)local_4c._8_4_);
                iVar3 = (*pIVar1[10].QueryInterface)(This,riid,in_stack_ffffff94);
              }
              VariantClear((VARIANTARG *)&local_4c.n2);
            }
            local_8._0_1_ = 3;
            if (local_1c != (int *)0x0) {
              (**(code **)(*local_1c + 8))(local_1c);
            }
          }
          local_8._0_1_ = 2;
          if (local_24 != (int *)0x0) {
            (**(code **)(*local_24 + 8))(local_24);
          }
        }
        if (local_18 != (IUnknown *)0x0) {
          local_28 = (int *)0x0;
          local_8 = (int *)CONCAT31(local_8._1_3_,8);
          iVar3 = (**(code **)(*local_20 + 0x30))(local_20,&local_28);
          if (local_28 != (int *)0x0) {
            iVar3 = FUN_68120227(local_2c,(int *)local_18,&local_28);
          }
          local_8._0_1_ = 2;
          if (local_28 != (int *)0x0) {
            (**(code **)(*local_28 + 8))(local_28);
          }
        }
        local_8._0_1_ = 1;
        if (iVar3 < 0) {
          iVar2 = iVar3;
        }
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        local_8 = (int *)((uint)local_8._1_3_ << 8);
        if (local_18 != (IUnknown *)0x0) {
          (*local_18->lpVtbl->Release)(local_18);
        }
      }
      local_8 = (int *)0xffffffff;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
    } while (iVar2 == 0);
    if (iVar2 == 1) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


