// Source: CLCiffConversion_Layout.dll @ 454214e8; FUN_454214e8

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_454214e8(void *this,void *param_1,undefined4 param_2,int *param_3)

{
  BSTR bstrString;
  void *pvVar1;
  UINT UVar2;
  undefined4 *puVar3;
  bool bVar4;
  BSTR local_4c;
  BSTR local_48;
  BSTR local_44;
  BSTR local_40;
  undefined4 local_3c;
  undefined4 local_38;
  BSTR local_34;
  void *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x454214f4;
  local_44 = (BSTR)0x0;
  local_30 = param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFTextField::SetFont");
  local_8 = 0;
  UVar2 = SysStringLen((BSTR)*param_3);
  bVar4 = UVar2 != 0;
  if (bVar4) {
    puVar3 = FUN_4540288a(&local_48,param_3);
  }
  else {
    puVar3 = FUN_4541db3e(param_1,&local_4c);
  }
  bstrString = (BSTR)*puVar3;
  *puVar3 = 0;
  local_8 = 2;
  local_44 = bstrString;
  if (bVar4) {
    SysFreeString(local_48);
  }
  local_8._0_1_ = 3;
  if (!bVar4) {
    SysFreeString(local_4c);
  }
  pvVar1 = local_30;
  FUN_4541db0b(local_30,&local_34);
  local_8._0_1_ = 4;
  FUN_4541cdb6(this,&local_40);
  local_8._0_1_ = 5;
  FUN_45404c34(&local_38);
  local_8 = CONCAT31(local_8._1_3_,6);
  local_30 = (void *)FUN_454062e6(&local_34);
  local_3c = 0;
  (**(code **)(**(int **)((int)this + 4) + 0x124))(*(int **)((int)this + 4),&local_3c);
  bVar4 = FUN_4541e8f1(pvVar1);
  if (bVar4) {
    (**(code **)(**(int **)((int)this + 4) + 0x128))(*(int **)((int)this + 4),1);
  }
  else {
    bVar4 = FUN_4541e8b5(pvVar1);
    if (bVar4) {
      (**(code **)(**(int **)((int)this + 4) + 0x128))(*(int **)((int)this + 4),1);
      (**(code **)(**(int **)((int)this + 4) + 0xbc))(*(int **)((int)this + 4),100);
    }
  }
  (**(code **)(**(int **)((int)this + 4) + 0xac))(*(int **)((int)this + 4),bstrString);
  (**(code **)(**(int **)((int)this + 4) + 0x100))(*(int **)((int)this + 4),local_30);
  (**(code **)(**(int **)((int)this + 4) + 0xb4))(*(int **)((int)this + 4),param_2);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_45404cb7(&local_38);
  SysFreeString(local_40);
  SysFreeString(local_34);
  SysFreeString(bstrString);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


