// Source: CLCiffConversion_Layout.dll @ 4541e74b; FUN_4541e74b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541e74b(void *this,void *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  HRESULT HVar3;
  _union_2683 local_54;
  int *local_44;
  void *local_40;
  undefined4 local_3c;
  int local_38;
  BSTR local_34;
  int *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x4541e757;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCiffPriceVerifierBarcodes::IsFieldAnEAN13PriceVerifier");
  local_8 = 0;
  FUN_4540303d(0x454491ec);
  local_3c = 0;
  local_40 = (void *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_44 = (int *)((int)this + 0x60);
  local_8._0_1_ = 1;
  FUN_45404ce5(local_44,(int *)((int)param_1 + 4));
  puVar2 = FUN_4541cbbe(param_1,&local_34);
  local_8._0_1_ = 2;
  FUN_45407800((void *)((int)this + 100),(wchar_t *)*puVar2);
  local_8._0_1_ = 1;
  SysFreeString(local_34);
  FUN_4540303d(0x4544a270);
  piVar1 = *(int **)((int)param_1 + 4);
  (**(code **)(*piVar1 + 100))(piVar1,&local_34);
  if (local_34 == (BSTR)0x1) {
    local_38 = 0;
    local_30 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    HVar3 = CoCreateInstance((IID *)&DAT_45447d6c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_454496b0,&local_30
                            );
    piVar1 = local_30;
    if ((-1 < HVar3) && (local_30 != (int *)0x0)) {
      local_54.n2.vt = 9;
      local_54._8_4_ = *local_44;
      if ((int *)local_54._8_4_ != (int *)0x0) {
        (**(code **)(*(int *)local_54._8_4_ + 4))(local_54._8_4_);
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      (**(code **)(*piVar1 + 0xd0))(piVar1,&local_54,&local_38);
      VariantClear((VARIANTARG *)&local_54.n2);
    }
    local_8._0_1_ = 1;
    if (local_30 != (int *)0x0) {
      (**(code **)(*local_30 + 8))(local_30);
    }
  }
  FUN_454224ff((int *)&local_40);
  FID_conflict__free(local_40);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


