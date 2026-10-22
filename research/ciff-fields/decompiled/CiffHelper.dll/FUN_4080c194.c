// Source: CiffHelper.dll @ 4080c194; FUN_4080c194

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4080c194(void *this,LPVOID *param_1,undefined1 param_2)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  UINT UVar4;
  undefined4 *puVar5;
  LPVOID *ppv;
  code *pcVar6;
  LPVOID *ppvVar7;
  LPVOID *local_44;
  HRESULT local_40;
  LPVOID *local_3c;
  int *local_38;
  LPVOID *local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x4080c1a0;
  local_34 = param_1;
  if (*(int *)((int)this + 0x14) != 0) {
    iVar3 = FUN_4080cf99((void *)((int)this + 4),*param_1);
    if (iVar3 == 0) {
      FUN_4082d4d5();
      return;
    }
    FUN_4080c146((int)this);
  }
  FUN_40806c52((void *)((int)this + 4),0);
  FUN_4080cecf((void *)((int)this + 4),*param_1);
  *(undefined1 *)this = param_2;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CADOConnection::Connect");
  ppvVar7 = local_34;
  local_8 = 0;
  local_40 = 0;
  UVar4 = SysStringLen(*local_34);
  if (UVar4 == 0) {
    FUN_4080c4da();
    return;
  }
  local_8._0_1_ = 1;
  FUN_40803c8a(&local_34,"Provider");
  local_8._0_1_ = 2;
  puVar5 = FUN_408030e3(&local_38,*ppvVar7);
  local_8._0_1_ = 3;
  puVar5 = FUN_40805a92(puVar5,&local_44,8);
  bVar2 = FUN_4080bebe(puVar5,&local_34);
  FUN_40803143((int *)&local_44);
  FUN_40803143((int *)&local_38);
  local_8._0_1_ = 1;
  FUN_40803143((int *)&local_34);
  pcVar6 = SysFreeString_exref;
  if (bVar2) {
    FUN_40802e40(&local_34,L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=");
    local_8._0_1_ = 4;
    FUN_408040a6(&local_34,*ppvVar7);
    local_40 = FUN_40803f8b(&local_34,L";");
    FUN_40803e5b(ppvVar7,(int *)&local_34);
    pcVar6 = SysFreeString_exref;
    local_8._0_1_ = 1;
    SysFreeString((BSTR)local_34);
  }
  ppv = (LPVOID *)((int)this + 0x20);
  local_34 = ppv;
  local_40 = CoCreateInstance((IID *)&DAT_4084a5a8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4084bc58,ppv);
  FUN_4080c114(local_40);
  local_40 = (**(code **)(*(int *)*ppv + 0x24))(*ppv,*ppvVar7);
  FUN_4080c114(local_40);
  puVar5 = FUN_408030e3(&local_38,*ppvVar7);
  iVar3 = FUN_4080c78f(puVar5,(undefined1 (*) [16])L"Password",0);
  FUN_40803143((int *)&local_38);
  if (iVar3 == -1) {
    puVar5 = FUN_408030e3(&local_3c,*ppvVar7);
    iVar3 = FUN_4080c78f(puVar5,(undefined1 (*) [16])L"USER ID",0);
    FUN_40803143((int *)&local_3c);
    if (iVar3 == -1) {
      local_3c = *local_34;
      local_38 = FUN_40802e40(&local_34,L"");
      local_8._0_1_ = 9;
      puVar5 = FUN_40802e40(&local_44,L"");
      local_8 = CONCAT31(local_8._1_3_,10);
      local_40 = (**(code **)((int)*local_3c + 0x50))
                           (local_3c,*ppvVar7,*puVar5,*local_38,0xffffffff);
      FUN_4080c114(local_40);
      (*pcVar6)(local_44);
      ppvVar7 = local_34;
    }
    else {
      piVar1 = *local_34;
      local_3c = (LPVOID *)FUN_40802e40(&local_44,L"");
      local_8._0_1_ = 7;
      puVar5 = FUN_40802e40(&local_38,L"Admin");
      local_8 = CONCAT31(local_8._1_3_,8);
      local_40 = (**(code **)(*piVar1 + 0x50))(piVar1,*ppvVar7,*puVar5,*local_3c,0xffffffff);
      FUN_4080c114(local_40);
      (*pcVar6)(local_38);
      ppvVar7 = local_44;
    }
  }
  else {
    local_38 = *local_34;
    local_44 = (LPVOID *)FUN_40802e40(&local_3c,L"");
    local_8._0_1_ = 5;
    puVar5 = FUN_40802e40(&local_34,L"");
    local_8 = CONCAT31(local_8._1_3_,6);
    local_40 = (**(code **)(*local_38 + 0x50))(local_38,*ppvVar7,*puVar5,*local_44,0xffffffff);
    FUN_4080c114(local_40);
    (*pcVar6)(local_34);
    ppvVar7 = local_3c;
  }
  (*pcVar6)(ppvVar7);
  *(undefined1 *)((int)this + 0x1c) = 1;
  FUN_4080c4da();
  return;
}


