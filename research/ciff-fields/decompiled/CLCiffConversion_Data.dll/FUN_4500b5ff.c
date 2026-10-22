// Source: CLCiffConversion_Data.dll @ 4500b5ff; FUN_4500b5ff

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500b5ff(void *this,LPVOID *param_1,undefined1 param_2)

{
  int *piVar1;
  bool bVar2;
  UINT UVar3;
  undefined4 *puVar4;
  int iVar5;
  LPVOID *ppv;
  code *pcVar6;
  LPVOID *ppvVar7;
  LPVOID *local_44;
  BSTR local_40;
  int local_3c;
  int *local_38;
  LPVOID *local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x4500b60b;
  local_44 = param_1;
  local_3c = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CADOConnection::ConnectEX");
  local_8 = 0;
  if (*(int *)((int)this + 0x14) == 0) {
    UVar3 = SysStringLen(*param_1);
    if (UVar3 == 0) {
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
      goto LAB_4500b930;
    }
    FUN_45004dee((void *)((int)this + 4),0);
    FUN_450140fe((void *)((int)this + 4),*param_1);
    local_8._0_1_ = 1;
    *(undefined1 *)this = param_2;
    FUN_45002050(&local_34,"Provider");
    ppvVar7 = local_44;
    local_8._0_1_ = 2;
    puVar4 = FUN_450020a5(&local_38,*local_44);
    local_8._0_1_ = 3;
    puVar4 = FUN_45003e81(puVar4,&local_40,8);
    bVar2 = FUN_4500af60(puVar4,&local_34);
    FUN_45002256((int *)&local_40);
    FUN_45002256((int *)&local_38);
    local_8._0_1_ = 1;
    FUN_45002256((int *)&local_34);
    if (bVar2) {
      FUN_45001f5d(&local_34,L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=");
      local_8._0_1_ = 4;
      FUN_4500263d(&local_34,*ppvVar7);
      local_3c = FUN_45002522(&local_34,L";");
      FUN_450022ea(ppvVar7,(int *)&local_34);
      local_8._0_1_ = 1;
      SysFreeString((BSTR)local_34);
    }
    ppv = (LPVOID *)((int)this + 0x20);
    local_34 = ppv;
    local_3c = CoCreateInstance((IID *)&DAT_4503d9c0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4503e500,ppv);
    FUN_4500b385(local_3c);
    local_3c = (**(code **)(*(int *)*ppv + 0x24))(*ppv,*ppvVar7);
    FUN_4500b385(local_3c);
    puVar4 = FUN_450020a5(&local_38,*ppvVar7);
    iVar5 = FUN_4500f8a2(puVar4,(undefined1 (*) [16])L"Password",0);
    FUN_45002256((int *)&local_38);
    if (iVar5 == -1) {
      puVar4 = FUN_450020a5(&local_38,*ppvVar7);
      iVar5 = FUN_4500f8a2(puVar4,(undefined1 (*) [16])L"USER ID",0);
      FUN_45002256((int *)&local_38);
      if (iVar5 == -1) {
        local_38 = *local_34;
        local_40 = (BSTR)FUN_45001f5d(&local_34,L"");
        local_8._0_1_ = 9;
        puVar4 = FUN_45001f5d(&local_44,L"");
        local_8 = CONCAT31(local_8._1_3_,10);
        goto LAB_4500b86b;
      }
      piVar1 = *local_34;
      local_38 = FUN_45001f5d(&local_44,L"");
      local_8._0_1_ = 7;
      puVar4 = FUN_45001f5d(&local_40,L"Admin");
      local_8 = CONCAT31(local_8._1_3_,8);
      local_3c = (**(code **)(*piVar1 + 0x50))(piVar1,*ppvVar7,*puVar4,*local_38,0xffffffff);
      FUN_4500b385(local_3c);
      pcVar6 = SysFreeString_exref;
      SysFreeString(local_40);
      ppvVar7 = local_44;
    }
    else {
      local_38 = *local_34;
      local_40 = (BSTR)FUN_45001f5d(&local_34,L"");
      local_8._0_1_ = 5;
      puVar4 = FUN_45001f5d(&local_44,L"");
      local_8 = CONCAT31(local_8._1_3_,6);
LAB_4500b86b:
      local_3c = (**(code **)(*local_38 + 0x50))
                           (local_38,*ppvVar7,*puVar4,*(undefined4 *)local_40,0xffffffff);
      FUN_4500b385(local_3c);
      pcVar6 = SysFreeString_exref;
      SysFreeString((BSTR)local_44);
      ppvVar7 = local_34;
    }
    (*pcVar6)(ppvVar7);
    *(undefined1 *)((int)this + 0x1c) = 1;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
LAB_4500b930:
  FUN_45022ec7();
  return;
}


