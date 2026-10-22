// Source: CLCiffConversion_Data.dll @ 45006518; FUN_45006518

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45006518(void *this,int *param_1)

{
  int *this_00;
  int iVar1;
  int iVar2;
  ULONG UVar3;
  HRESULT HVar4;
  UINT UVar5;
  wchar_t *this_01;
  IID *riid;
  _union_2683 local_9c;
  _union_2683 local_8c;
  _union_2683 local_7c;
  int local_6c;
  int local_68;
  int *local_64;
  int local_60;
  int local_5c;
  int *local_58;
  int *local_54;
  int *local_50;
  IUnknown *local_4c;
  wchar_t *local_48;
  wchar_t local_44 [12];
  wchar_t local_2c [18];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x8c;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  local_64 = (int *)((int)this + 4);
  FUN_45007aec(local_64);
  if (param_1 != (int *)0x0) {
    local_5c = 0;
    iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,&local_5c);
    if (-1 < iVar1) {
      local_4c = (IUnknown *)0x0;
      iVar1 = 0;
      if (0 < local_5c) {
        do {
          FUN_45001f8d((uint *)&local_7c);
          iVar1 = iVar1 + 1;
          local_8._0_1_ = 2;
          local_6c = iVar1;
          iVar2 = (**(code **)(*param_1 + 0x24))(param_1,iVar1,&local_7c);
          if ((-1 < iVar2) && (local_7c.n2.vt == 9)) {
            if (local_4c != (IUnknown *)local_7c._8_4_) {
              ATL::AtlComQIPtrAssign(&local_4c,(IUnknown *)local_7c._8_4_,(_GUID *)&DAT_4503d678);
            }
            if (local_4c != (IUnknown *)0x0) {
              local_60 = 0;
              UVar3 = (*local_4c->lpVtbl[2].AddRef)(local_4c);
              this_00 = local_64;
              if ((-1 < (int)UVar3) && (riid = (IID *)0x0, 0 < local_60)) {
                do {
                  FUN_45001f8d((uint *)&local_8c);
                  riid = (IID *)((int)&riid->Data1 + 1);
                  local_8._0_1_ = 3;
                  HVar4 = (*local_4c->lpVtbl[3].QueryInterface)(local_4c,riid,(void **)&local_8c);
                  if ((-1 < HVar4) && (local_8c.n2.vt == 9)) {
                    CComQIPtr<>(&local_54,(undefined4 *)local_8c._8_4_);
                    if (local_54 != (int *)0x0) {
                      local_48 = (wchar_t *)0x0;
                      local_8._0_1_ = 5;
                      (**(code **)(*local_54 + 0x1c))(local_54,&local_48);
                      local_50 = (int *)0x0;
                      local_8._0_1_ = 6;
                      (**(code **)(*local_54 + 0x5c))(local_54,&local_50);
                      if (((local_50 != (int *)0x0) &&
                          (iVar1 = (**(code **)(*local_50 + 0x1c))(local_50,&local_68), -1 < iVar1))
                         && (local_68 == 1)) {
                        FUN_45001f8d((uint *)&local_9c);
                        local_8._0_1_ = 7;
                        iVar1 = (**(code **)(*local_50 + 0x24))(local_50,1,&local_9c);
                        if ((-1 < iVar1) && (local_9c.n2.vt == 9)) {
                          CComQIPtr<>(&local_58,(undefined4 *)local_9c._8_4_);
                          local_8._0_1_ = 8;
                          if (local_58 != (int *)0x0) {
                            basic_string<>(local_44,local_48);
                            local_8._0_1_ = 9;
                            SysFreeString(local_48);
                            local_48 = (BSTR)0x0;
                            iVar1 = (**(code **)(*local_58 + 0x58))(local_58,&local_48);
                            if ((-1 < iVar1) && (UVar5 = SysStringLen(local_48), UVar5 != 0)) {
                              basic_string<>(local_2c,local_48);
                              local_8._0_1_ = 10;
                              this_01 = FUN_450058e9(this_00,local_44);
                              if (this_01 != local_2c) {
                                FUN_450049ae(this_01,(undefined8 *)local_2c,0,0xffffffff);
                              }
                              FUN_450046d9(local_2c,'\x01',0);
                            }
                            FUN_450046d9(local_44,'\x01',0);
                          }
                          local_8._0_1_ = 7;
                          if (local_58 != (int *)0x0) {
                            (**(code **)(*local_58 + 8))(local_58);
                          }
                        }
                        VariantClear((VARIANTARG *)&local_9c.n2);
                      }
                      local_8._0_1_ = 5;
                      if (local_50 != (int *)0x0) {
                        (**(code **)(*local_50 + 8))(local_50);
                      }
                      SysFreeString(local_48);
                    }
                    local_8._0_1_ = 3;
                    if (local_54 != (int *)0x0) {
                      (**(code **)(*local_54 + 8))(local_54);
                    }
                  }
                  VariantClear((VARIANTARG *)&local_8c.n2);
                  iVar1 = local_6c;
                } while ((int)riid < local_60);
              }
            }
          }
          VariantClear((VARIANTARG *)&local_7c.n2);
        } while (iVar1 < local_5c);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_4c != (IUnknown *)0x0) {
        (*local_4c->lpVtbl->Release)(local_4c);
      }
    }
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_45022eb8();
  return;
}


