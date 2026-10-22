// Source: CLCiffConversion_Layout.dll @ 4541f219; FUN_4541f219

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_4541f219(byte *param_1,short param_2,undefined4 param_3,wchar_t *param_4,undefined4 param_5
                 ,VARIANTARG *param_6)

{
  undefined3 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  VARIANTARG *pvargSrc;
  byte *extraout_ECX;
  wchar_t *pwVar5;
  char cVar6;
  byte *pbVar7;
  wchar_t *pwVar8;
  byte *local_3c;
  byte *local_38;
  int local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x4541f225;
  local_38 = param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::Parameter");
  local_8._1_3_ = 0;
  uVar1 = local_8._1_3_;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (param_2 == 8) {
    FUN_45402ac2(&local_3c,param_4);
    local_8._0_1_ = 2;
    puVar2 = FUN_4540629a(&local_3c,&local_34,4);
    iVar3 = FUN_4542cae1((byte *)*puVar2,&DAT_4544a408);
    FUN_45402c5d(&local_34);
    pbVar7 = local_38;
    if (iVar3 == 0) {
      for (local_34 = 1; local_34 < 0x17; local_34 = local_34 + 1) {
        iVar3 = local_34 * 0x30;
        FUN_45402a2f(&local_38,(int *)(pbVar7 + iVar3 + 0x4c));
        local_8._0_1_ = 3;
        iVar4 = FUN_4542cae1(local_38,local_3c);
        if (iVar4 == 0) {
          pvargSrc = (VARIANTARG *)(pbVar7 + iVar3 + 0x50);
          if ((param_6->n1).n2.vt == 0) {
            VariantCopy(param_6,pvargSrc);
          }
          else {
            FUN_4542909b((short *)pvargSrc,(short *)param_6);
          }
          FUN_45402c5d((int *)&local_38);
          break;
        }
        local_8._0_1_ = 2;
        FUN_45402c5d((int *)&local_38);
      }
    }
    else {
      cVar6 = (param_6->n1).n2.vt != 0;
      iVar3 = 0;
      pbVar7 = extraout_ECX;
      FUN_45402a2f(&stack0xffffff8c,(int *)&local_3c);
      FUN_45428c0b(local_38 + -8,pbVar7,iVar3,param_6,cVar6);
    }
    FUN_45402c5d((int *)&local_3c);
  }
  else {
    local_8._1_3_ = uVar1;
    if ((param_2 == 2) || (param_2 == 3)) {
      pwVar5 = (wchar_t *)0x0;
      if (param_2 == 2) {
        pwVar5 = (wchar_t *)(int)(short)param_4;
      }
      if (param_2 == 3) {
        pwVar5 = param_4;
      }
      cVar6 = (param_6->n1).n2.vt != 0;
      pwVar8 = pwVar5;
      FUN_45402a65(&stack0xffffff8c,"");
      FUN_45428c0b(param_1 + -8,(byte *)pwVar5,(int)pwVar8,param_6,cVar6);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4541f3fd();
  return;
}


