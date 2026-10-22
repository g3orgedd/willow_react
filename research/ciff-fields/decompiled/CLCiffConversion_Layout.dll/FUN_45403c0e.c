// Source: CLCiffConversion_Layout.dll @ 45403c0e; FUN_45403c0e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_45403c0e(int *param_1,undefined4 param_2,int *param_3)

{
  bool bVar1;
  bool bVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *local_40;
  undefined4 local_3c;
  int local_38;
  byte *local_34;
  wchar_t *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCapabilitiesHelper::IsAlphabetValidForFont");
  bVar1 = false;
  local_8._0_1_ = 2;
  local_3c = 0;
  local_40 = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_45404963((int *)&local_40);
  local_38 = 0;
  (**(code **)(*param_3 + 0x110))(param_3,&local_38);
  FUN_4540303d(0x45447800);
  iVar4 = 0;
  if (0 < local_38) {
    do {
      local_30 = (wchar_t *)0x0;
      local_8._0_1_ = 4;
      (**(code **)(*param_3 + 0x108))(param_3,iVar4,&local_30);
      FUN_45402ac2(&local_34,local_30);
      local_8._0_1_ = 5;
      FUN_454025d8(&local_40,local_40,(int *)&local_34);
      local_8._0_1_ = 4;
      FUN_45402c5d((int *)&local_34);
      FUN_4540409b(&local_30);
      bVar2 = FUN_45402d4b(&local_30,L"UNICODE");
      local_8 = CONCAT31(local_8._1_3_,3);
      if (bVar2) {
        bVar1 = true;
      }
      SysFreeString(local_30);
      iVar4 = iVar4 + 1;
    } while (iVar4 < local_38);
  }
  if (local_38 == 0) {
    bVar1 = true;
    local_38 = 1;
    FUN_45402a65(&local_34,"UNICODE");
    local_8._0_1_ = 6;
    FUN_454025d8(&local_40,local_40,(int *)&local_34);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_45402c5d((int *)&local_34);
  }
  if (!bVar1) {
    FUN_4540303d(0x45447838);
    piVar6 = (int *)*param_1;
    if (piVar6 != param_1) {
      do {
        FUN_45402a2f(&local_34,piVar6 + 2);
        pbVar3 = local_34;
        local_8._0_1_ = 7;
        iVar4 = FUN_4542cae1(local_34,&DAT_45447858);
        if (iVar4 == 0) {
          FUN_4540303d(0x4544785c);
          FUN_45402cd0(&local_34,"ARABICNUM");
          pbVar3 = local_34;
        }
        piVar5 = (int *)*local_40;
        if (piVar5 != local_40) {
          do {
            FUN_45402a2f(&local_30,piVar5 + 2);
            local_8._0_1_ = 8;
            FUN_4540303d(0x45447888);
            iVar4 = FUN_4542cae1((byte *)local_30,pbVar3);
            if (iVar4 == 0) {
              FUN_45402c5d((int *)&local_30);
              break;
            }
            local_8._0_1_ = 7;
            FUN_45402c5d((int *)&local_30);
            piVar5 = (int *)*piVar5;
          } while (piVar5 != local_40);
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_45402c5d((int *)&local_34);
        piVar6 = (int *)*piVar6;
      } while (piVar6 != param_1);
    }
    FUN_4540303d(0x454478ac);
  }
  FUN_45404963((int *)&local_40);
  FID_conflict__free(local_40);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45404963((int *)&param_1);
  FID_conflict__free(param_1);
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  FUN_4542a957();
  return;
}


