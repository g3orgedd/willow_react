// Source: CLCSTextBasedField.dll @ 42420e0e; FUN_42420e0e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_42420e0e(int *param_1)

{
  longlong lVar1;
  UINT UVar2;
  undefined4 ****_Memory;
  wchar_t *_Dst;
  int iVar3;
  int iVar4;
  undefined4 ****ppppuVar5;
  undefined4 ****ppppuVar6;
  int local_70;
  int local_6c;
  undefined2 local_68 [2];
  int local_64;
  BSTR local_60;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_5c [24];
  undefined2 local_44 [8];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 ***local_2c [5];
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_5c,"CCLCSTextBasedFieldObj::ApplyFixedLen");
  local_6c = 0;
  local_8._0_1_ = 1;
  (**(code **)(*param_1 + 0x9c))(param_1,&local_6c);
  if (local_6c == 1) {
    (**(code **)(*param_1 + 0x94))(param_1,&local_64);
    local_60 = (BSTR)0x0;
    local_8._0_1_ = 2;
    (**(code **)(*param_1 + 0x60))(param_1,&local_60);
    UVar2 = SysStringLen(local_60);
    if ((0 < (int)UVar2) && ((int)UVar2 < local_64)) {
      (**(code **)(*param_1 + 0xa4))(param_1,local_68);
      UVar2 = SysStringLen(local_60);
      iVar4 = local_64 - UVar2;
      local_30 = 7;
      local_34 = 0;
      local_44[0] = 0;
      local_8._0_1_ = 3;
      basic_string<>(local_2c,local_60);
      local_8._0_1_ = 4;
      lVar1 = (ulonglong)(iVar4 + 1) * 2;
      _Memory = (undefined4 ****)
                FUN_4246cbfd(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
      iVar3 = 0;
      if (0 < iVar4) {
        do {
          *(undefined2 *)((int)_Memory + iVar3 * 2) = local_68[0];
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar4);
      }
      *(undefined2 *)((int)_Memory + iVar3 * 2) = 0;
      (**(code **)(*param_1 + 0xac))(param_1,&local_70);
      lVar1 = (ulonglong)(local_64 + 1U) * 2;
      _Dst = (wchar_t *)FUN_4246cbfd(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
      if (local_70 == 0) {
        ppppuVar5 = local_2c;
        ppppuVar6 = _Memory;
        if (7 < local_18) {
          ppppuVar5 = (undefined4 ****)local_2c[0];
        }
      }
      else {
        ppppuVar5 = _Memory;
        ppppuVar6 = local_2c;
        if (7 < local_18) {
          ppppuVar6 = (undefined4 ****)local_2c[0];
        }
      }
      _swprintf_s(_Dst,local_64 + 1U,L"%s%s",ppppuVar5,ppppuVar6);
      (**(code **)(*param_1 + 100))(param_1,_Dst);
      FID_conflict__free(_Dst);
      FID_conflict__free(_Memory);
      FUN_42406591(local_2c,'\x01',0);
      FUN_42406591(local_44,'\x01',0);
    }
    SysFreeString(local_60);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_5c,true,0);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_4246ecf6();
  return;
}


