// Source: CiffHelper.dll @ 408139f8; FUN_408139f8

undefined4 FUN_408139f8(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 *in_stack_00000010;
  OLECHAR *in_stack_00000018;
  VARIANTARG *in_stack_0000001c;
  _union_2683 local_40;
  _union_2683 local_30;
  int *local_20;
  int local_1c;
  int local_18;
  IID *local_14;
  IUnknown *local_10;
  BSTR local_c;
  IUnknown *local_8;
  
  uVar3 = 0;
  local_10 = (IUnknown *)0x0;
  CComQIPtr<>(&local_20,in_stack_00000010);
  local_1c = 0;
  (**(code **)(*local_20 + 0x1c))(local_20,&local_1c);
  iVar2 = 1;
  pcVar4 = VariantClear_exref;
  if (0 < local_1c) {
    do {
      FUN_40802e76((uint *)&local_40);
      (**(code **)(*local_20 + 0x24))(local_20,iVar2,&local_40);
      if (((local_40.n2.vt == 9) &&
          (local_8 = (IUnknown *)0x0, (IUnknown *)local_40._8_4_ != (IUnknown *)0x0)) &&
         (ATL::AtlComQIPtrAssign(&local_8,(IUnknown *)local_40._8_4_,(_GUID *)&DAT_4084a928),
         local_8 != (IUnknown *)0x0)) {
        local_18 = 0;
        (*local_8->lpVtbl[2].AddRef)(local_8);
        local_14 = (IID *)0x0;
        if (0 < local_18) {
          do {
            FUN_40802e76((uint *)&local_30);
            local_14 = (IID *)((int)&local_14->Data1 + 1);
            (*local_8->lpVtbl[3].QueryInterface)(local_8,local_14,(void **)&local_30);
            pcVar4 = VariantClear_exref;
            if (local_30.n2.vt != 1) {
              if (local_10 != (IUnknown *)local_30._8_4_) {
                ATL::AtlComQIPtrAssign(&local_10,(IUnknown *)local_30._8_4_,(_GUID *)&DAT_4084a938);
              }
              local_c = (BSTR)0x0;
              (*local_10->lpVtbl[2].AddRef)(local_10);
              bVar1 = FUN_40803ed6(&local_c,in_stack_00000018);
              if (bVar1) {
                VariantCopy(in_stack_0000001c,(VARIANTARG *)&local_30.n2);
                SysFreeString(local_c);
                VariantClear((VARIANTARG *)&local_30.n2);
                if (local_8 != (IUnknown *)0x0) {
                  (*local_8->lpVtbl->Release)(local_8);
                }
                VariantClear((VARIANTARG *)&local_40.n2);
                goto LAB_40813b3e;
              }
              SysFreeString(local_c);
            }
            VariantClear((VARIANTARG *)&local_30.n2);
            VariantClear((VARIANTARG *)&local_30.n2);
          } while ((int)local_14 < local_18);
        }
        if (local_8 != (IUnknown *)0x0) {
          (*local_8->lpVtbl->Release)(local_8);
        }
      }
      (*pcVar4)(&local_40);
      iVar2 = iVar2 + 1;
    } while (iVar2 <= local_1c);
  }
  uVar3 = 0x80004005;
LAB_40813b3e:
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  if (local_10 != (IUnknown *)0x0) {
    (*local_10->lpVtbl->Release)(local_10);
  }
  return uVar3;
}


