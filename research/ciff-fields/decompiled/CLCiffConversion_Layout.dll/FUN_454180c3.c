// Source: CLCiffConversion_Layout.dll @ 454180c3; FUN_454180c3

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_454180c3(int param_1,BSTR param_2)

{
  void *this;
  int iVar1;
  HRESULT HVar2;
  LPCSTR pCVar3;
  undefined4 *puVar4;
  int *piVar5;
  char *local_3c;
  BSTR local_38;
  int *local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x454180cf;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::Convert");
  this = (void *)(param_1 + -8);
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  iVar1 = FUN_45428bd2();
  if (iVar1 == 0) {
    if (*(short *)(param_1 + 0x410) == 3) {
      *(undefined4 *)(param_1 + 0x4e0) = *(undefined4 *)(param_1 + 0x418);
    }
    else {
      *(undefined4 *)(param_1 + 0x4e0) = 0;
    }
    FUN_45420c22(this,param_2);
    FUN_4542084f(this);
    FUN_4542064b((int)this);
    FUN_454209d0((int)this);
    FUN_45420554((int)this);
    local_34 = (int *)0x0;
    local_8._0_1_ = 2;
    HVar2 = CoCreateInstance((IID *)&DAT_45447d7c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_454496c0,&local_34
                            );
    if ((-1 < HVar2) && (local_34 != (int *)0x0)) {
      pCVar3 = FUN_45408541();
      FUN_45402a65(&local_3c,pCVar3);
      piVar5 = local_34;
      local_8._0_1_ = 3;
      puVar4 = FUN_454028b9(&local_38,local_3c);
      local_8._0_1_ = 4;
      (**(code **)(*piVar5 + 0x30))(piVar5,*puVar4);
      local_8._0_1_ = 3;
      SysFreeString(local_38);
      if (*(short *)(param_1 + 0x200) == 8) {
        FUN_45407800((void *)(param_1 + 0x4d4),*(wchar_t **)(param_1 + 0x208));
      }
      else {
        FUN_45402cd0((void *)(param_1 + 0x4d4),"");
      }
      piVar5 = local_34;
      if (local_34 != (int *)0x0) {
        (**(code **)(*local_34 + 4))(local_34);
      }
      iVar1 = FUN_4541a4f7(this,piVar5);
      if ((-1 < iVar1) && (iVar1 = FUN_45417ff4((int)this), -1 < iVar1)) {
        FUN_45421216((int)this);
      }
      FUN_454287c9(this,'\0');
      FUN_45416083((int)this);
      FUN_45402c5d((int *)&local_3c);
    }
    local_8._0_1_ = 1;
    if (local_34 != (int *)0x0) {
      (**(code **)(*local_34 + 8))(local_34);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4541829e();
  return;
}


