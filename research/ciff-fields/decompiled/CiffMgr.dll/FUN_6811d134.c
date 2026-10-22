// Source: CiffMgr.dll @ 6811d134; FUN_6811d134

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6811d134(void *this,int *param_1,undefined4 *param_2)

{
  IUnknownVtbl *pIVar1;
  IUnknown *pIVar2;
  int iVar3;
  int iVar4;
  IID *riid;
  void **ppvObject;
  VARIANTARG local_7c;
  _union_2683 local_6c;
  _union_2683 local_5c;
  _union_2683 local_4c;
  _union_2683 local_3c;
  int *local_2c;
  void *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  void **local_18;
  IUnknown *local_14 [3];
  int *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_28 = this;
  if (param_1 == (int *)0x0) {
    iVar3 = -0x7fffbffd;
  }
  else {
    do {
      local_24 = (int *)0x0;
      local_8 = local_24;
      iVar3 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_24);
      if ((iVar3 == 0) && (local_24 != (int *)0x0)) {
        local_14[0] = (IUnknown *)0x0;
        local_18 = (void **)0x0;
        local_8._0_1_ = 2;
        iVar4 = (**(code **)(*local_24 + 0x44))(local_24,&local_18);
        if ((-1 < iVar4) && (local_18 != (void **)0x0)) {
          local_1c = (int *)0x0;
          local_8._0_1_ = 3;
          iVar4 = (**(code **)((int)*local_18 + 0x1c))(local_18,PTR_u_Name_68160030,&local_1c);
          if ((-1 < iVar4) && (local_1c != (int *)0x0)) {
            FUN_68132710((uint *)&local_3c,0,0x10);
            VariantInit((VARIANTARG *)&local_3c.n2);
            local_8._0_1_ = 4;
            iVar4 = (**(code **)(*local_1c + 0x20))(local_1c,&local_3c);
            if ((local_3c.n2.vt == 8) &&
               (((short *)local_3c._8_4_ != (short *)0x0 && (*(short *)local_3c._8_4_ != 0)))) {
              FUN_68132710((uint *)&local_7c,0,0x10);
              VariantInit(&local_7c);
              local_8._0_1_ = 5;
              iVar4 = (**(code **)(*param_1 + 0x20))(param_1,local_3c._8_4_,&local_7c);
              if ((-1 < iVar4) && (local_14[0] != (IUnknown *)local_7c.n1._8_4_)) {
                ATL::AtlComQIPtrAssign
                          (local_14,(IUnknown *)local_7c.n1._8_4_,(_GUID *)&DAT_6814b614);
              }
              VariantClear(&local_7c);
            }
            VariantClear((VARIANTARG *)&local_3c.n2);
          }
          local_8._0_1_ = 2;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
        }
        if (local_14[0] != (IUnknown *)0x0) {
          local_1c = (int *)0x0;
          local_8._0_1_ = 6;
          iVar4 = (**(code **)((int)*local_18 + 0x1c))(local_18,PTR_u_StaticDate_68160034,&local_1c)
          ;
          if ((iVar4 == 0) && (local_1c != (int *)0x0)) {
            FUN_68132710((uint *)&local_4c,0,0x10);
            VariantInit((VARIANTARG *)&local_4c.n2);
            local_8._0_1_ = 7;
            (**(code **)(*local_1c + 0x20))(local_1c,&local_4c);
            pIVar2 = local_14[0];
            if (local_4c.n2.vt == 8) {
              pIVar1 = local_14[0]->lpVtbl;
              FUN_6812e988((wchar_t *)local_4c._8_4_);
              (*pIVar1[3].AddRef)(pIVar2);
            }
            VariantClear((VARIANTARG *)&local_4c.n2);
          }
          local_8._0_1_ = 2;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
          local_1c = (int *)0x0;
          local_8._0_1_ = 8;
          ppvObject = local_18;
          iVar4 = (**(code **)((int)*local_18 + 0x1c))(local_18,PTR_u_AutoUpdate_68160038,&local_1c)
          ;
          if ((iVar4 == 0) && (local_1c != (int *)0x0)) {
            FUN_68132710((uint *)&local_5c,0,0x10);
            VariantInit((VARIANTARG *)&local_5c.n2);
            local_8._0_1_ = 9;
            (**(code **)(*local_1c + 0x20))(local_1c,&local_5c);
            pIVar2 = local_14[0];
            if (local_5c.n2.vt == 8) {
              pIVar1 = local_14[0]->lpVtbl;
              riid = (IID *)FUN_6812e988((wchar_t *)local_5c._8_4_);
              (*pIVar1[10].QueryInterface)(pIVar2,riid,ppvObject);
            }
            VariantClear((VARIANTARG *)&local_5c.n2);
          }
          local_8._0_1_ = 2;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
          local_20 = (int *)0x0;
          local_8._0_1_ = 10;
          iVar4 = (**(code **)((int)*local_18 + 0x1c))(local_18,PTR_u_Type_6816003c,&local_20);
          if ((iVar4 == 0) && (local_20 != (int *)0x0)) {
            FUN_68132710((uint *)&local_6c,0,0x10);
            VariantInit((VARIANTARG *)&local_6c.n2);
            local_8._0_1_ = 0xb;
            (**(code **)(*local_20 + 0x20))(local_20,&local_6c);
            pIVar2 = local_14[0];
            if (local_6c.n2.vt == 8) {
              pIVar1 = local_14[0]->lpVtbl;
              FUN_6812f24c((wchar_t *)local_6c._8_4_);
              (*pIVar1[6].Release)(pIVar2);
            }
            VariantClear((VARIANTARG *)&local_6c.n2);
          }
          local_8._0_1_ = 2;
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
          }
          local_2c = (int *)0x0;
          local_8 = (int *)CONCAT31(local_8._1_3_,0xc);
          iVar4 = (**(code **)(*local_24 + 0x30))(local_24,&local_2c);
          if (local_2c != (int *)0x0) {
            iVar4 = FUN_6811cb20((int *)local_14[0],&local_2c);
          }
          local_8._0_1_ = 2;
          if (local_2c != (int *)0x0) {
            (**(code **)(*local_2c + 8))(local_2c);
          }
        }
        local_8._0_1_ = 1;
        if (iVar4 < 0) {
          iVar3 = iVar4;
        }
        if (local_18 != (void **)0x0) {
          (**(code **)((int)*local_18 + 8))(local_18);
        }
        local_8 = (int *)((uint)local_8._1_3_ << 8);
        if (local_14[0] != (IUnknown *)0x0) {
          (*local_14[0]->lpVtbl->Release)(local_14[0]);
        }
      }
      local_8 = (int *)0xffffffff;
      if (local_24 != (int *)0x0) {
        (**(code **)(*local_24 + 8))(local_24);
      }
    } while (iVar3 == 0);
    if (iVar3 == 1) {
      iVar3 = 0;
    }
  }
  return iVar3;
}


