// Source: CLCiffConversion_Data.dll @ 4500761c; FUN_4500761c

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500761c(void *this,void *param_1)

{
  int iVar1;
  int *piVar2;
  UINT UVar3;
  OLECHAR *pOVar4;
  _union_2683 local_50;
  int local_40;
  BSTR local_3c;
  int *local_38;
  int *local_34;
  BSTR local_30;
  wchar_t local_2c [18];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x45007628;
  if (param_1 != (void *)0x0) {
    local_38 = (int *)0x0;
    local_8 = 0;
    (**(code **)(**(int **)((int)param_1 + 4) + 0x5c))(*(int **)((int)param_1 + 4),&local_38);
    if (local_38 != (int *)0x0) {
      local_40 = 0;
      iVar1 = (**(code **)(*local_38 + 0x1c))(local_38,&local_40);
      if ((-1 < iVar1) && (local_40 == 1)) {
        FUN_45001f8d((uint *)&local_50);
        local_8._0_1_ = 1;
        iVar1 = (**(code **)(*local_38 + 0x24))(local_38,1,&local_50);
        if ((-1 < iVar1) && (local_50.n2.vt == 9)) {
          local_34 = (int *)0x0;
          local_8._0_1_ = 2;
          iVar1 = (*(code *)**(undefined4 **)local_50._8_4_)(local_50._8_4_,&DAT_4503d82c,&local_34)
          ;
          if ((-1 < iVar1) && (local_34 != (int *)0x0)) {
            local_3c = (BSTR)0x0;
            local_8._0_1_ = 3;
            piVar2 = FUN_45007442(param_1,&local_30);
            FUN_450058c3(&local_3c,piVar2);
            SysFreeString(local_30);
            UVar3 = SysStringLen(local_3c);
            if (UVar3 != 0) {
              basic_string<>(local_2c,local_3c);
              local_8._0_1_ = 4;
              FUN_45007e32((void *)((int)this + 4),(int *)&local_30,local_2c);
              if (local_30 != *(BSTR *)((int)this + 4)) {
                pOVar4 = local_30 + 0x14;
                if (7 < *(uint *)(local_30 + 0x1e)) {
                  pOVar4 = *(OLECHAR **)pOVar4;
                }
                FUN_45001f5d(&local_30,pOVar4);
                local_8._0_1_ = 5;
                (**(code **)(**(int **)((int)param_1 + 4) + 0x9c))
                          (*(int **)((int)param_1 + 4),local_30);
                (**(code **)(*local_34 + 0x5c))(local_34,local_30);
                SysFreeString(local_30);
              }
              FUN_450046d9(local_2c,'\x01',0);
            }
            SysFreeString(local_3c);
          }
          local_8._0_1_ = 1;
          if (local_34 != (int *)0x0) {
            (**(code **)(*local_34 + 8))(local_34);
          }
        }
        VariantClear((VARIANTARG *)&local_50.n2);
      }
    }
    local_8 = 0xffffffff;
    if (local_38 != (int *)0x0) {
      (**(code **)(*local_38 + 8))(local_38);
    }
  }
  FUN_45022eb8();
  return;
}


