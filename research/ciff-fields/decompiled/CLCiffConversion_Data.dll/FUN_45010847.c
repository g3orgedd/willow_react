// Source: CLCiffConversion_Data.dll @ 45010847; FUN_45010847

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_45010847(wchar_t *param_1,short param_2,undefined4 param_3,LPCWSTR param_4,
                 undefined4 param_5,VARIANTARG *param_6)

{
  undefined3 uVar1;
  undefined4 *puVar2;
  int iVar3;
  VARIANTARG *pvargSrc;
  wchar_t *extraout_ECX;
  LPCWSTR pWVar4;
  char cVar5;
  wchar_t *pwVar6;
  wchar_t *local_40;
  wchar_t *local_3c;
  wchar_t *local_38;
  int local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x45010853;
  local_38 = param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Data::Parameter");
  local_8._1_3_ = 0;
  uVar1 = local_8._1_3_;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (param_2 == 8) {
    FUN_450020a5(&local_3c,param_4);
    local_8._0_1_ = 2;
    FUN_45002050(&local_40,"IDI_");
    local_8._0_1_ = 3;
    puVar2 = FUN_45003e81(&local_3c,&local_34,4);
    iVar3 = _wcscmp((wchar_t *)*puVar2,local_40);
    FUN_45002256(&local_34);
    local_8._0_1_ = 2;
    FUN_45002256((int *)&local_40);
    pwVar6 = local_38;
    if (iVar3 == 0) {
      for (local_34 = 1; local_34 < 0x18; local_34 = local_34 + 1) {
        local_40 = (wchar_t *)(local_34 * 0x30);
        FUN_4500201a(&local_38,(int *)((int)(local_40 + 0x1e) + (int)pwVar6));
        local_8._0_1_ = 4;
        iVar3 = _wcscmp(local_38,local_3c);
        if (iVar3 == 0) {
          pvargSrc = (VARIANTARG *)((int)(local_40 + 0x20) + (int)pwVar6);
          if ((param_6->n1).n2.vt == 0) {
            VariantCopy(param_6,pvargSrc);
          }
          else {
            FUN_45019660((short *)pvargSrc,(short *)param_6);
          }
          FUN_45002256((int *)&local_38);
          FUN_45002256((int *)&local_3c);
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                    (local_30,true,0);
          FUN_45010a5c();
          return;
        }
        local_8._0_1_ = 2;
        FUN_45002256((int *)&local_38);
      }
    }
    else {
      cVar5 = (param_6->n1).n2.vt != 0;
      iVar3 = 0;
      pwVar6 = extraout_ECX;
      FUN_4500201a(&stack0xffffff8c,(int *)&local_3c);
      FUN_450191ec(pwVar6,iVar3,param_6,cVar5);
    }
    FUN_45002256((int *)&local_3c);
  }
  else {
    local_8._1_3_ = uVar1;
    if ((param_2 == 2) || (param_2 == 3)) {
      pWVar4 = (LPCWSTR)0x0;
      if (param_2 == 2) {
        pWVar4 = (LPCWSTR)(int)(short)param_4;
      }
      if (param_2 == 3) {
        pWVar4 = param_4;
      }
      cVar5 = (param_6->n1).n2.vt != 0;
      FUN_45002050(&stack0xffffff8c,"");
      FUN_450191ec(param_4,(int)pWVar4,param_6,cVar5);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_45010a5c();
  return;
}


