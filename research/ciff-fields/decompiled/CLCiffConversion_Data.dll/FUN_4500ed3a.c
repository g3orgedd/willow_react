// Source: CLCiffConversion_Data.dll @ 4500ed3a; FUN_4500ed3a

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_4500ed3a(void *param_1,wchar_t *param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  wchar_t *****pppppwVar5;
  LPWSTR _Str;
  char **_Str_00;
  uint in_stack_00000020;
  wchar_t *in_stack_00000024;
  undefined4 uStackY_58;
  undefined4 auStackY_54 [2];
  undefined1 local_44 [16];
  undefined4 local_34;
  void *local_30;
  wchar_t ****local_2c [4];
  undefined4 local_1c;
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_30 = param_1;
  local_34 = 0;
  local_18 = 7;
  local_1c = 0;
  local_2c[0] = (wchar_t ****)((uint)local_2c[0] & 0xffff0000);
  local_8 = 1;
  if (param_2 != (wchar_t *)0x0) {
    if (*param_2 == L'\0') {
      uVar3 = 0;
    }
    else {
      uVar3 = _wcslen(param_2);
    }
    auStackY_54[1] = 0x4500ed8c;
    FUN_45014125(local_2c,(undefined8 *)param_2,uVar3);
    sVar4 = _wcslen(L", ");
    auStackY_54[1] = 0x4500eda2;
    FUN_45014125(local_2c,(undefined8 *)&DAT_4503e490,sVar4);
  }
  sVar4 = _wcslen(L"method ");
  auStackY_54[1] = 0x4500edb8;
  FUN_45014125(local_2c,(undefined8 *)L"method ",sVar4);
  _Str_00 = &param_3;
  if (0xf < in_stack_00000020) {
    _Str_00 = (char **)param_3;
  }
  if (_Str_00 != (char **)0x0) {
    sVar4 = _strlen((char *)_Str_00);
    iVar1 = sVar4 + 1;
    if (iVar1 < 0x40000000) {
      iVar2 = iVar1 * -2;
      *(undefined4 *)((int)local_2c + iVar2 + -0x1c) = 3;
      *(int *)((int)local_2c + iVar2 + -0x20) = iVar1;
      *(char ***)((int)auStackY_54 + iVar2 + 4) = _Str_00;
      *(undefined1 **)((int)auStackY_54 + iVar2) = local_44;
      *(undefined4 *)((int)&uStackY_58 + iVar2) = 0x4500edf3;
      _Str = FUN_4500b102(*(LPWSTR *)((int)auStackY_54 + iVar2),
                          *(LPCSTR *)((int)auStackY_54 + iVar2 + 4),
                          *(int *)((int)local_2c + iVar2 + -0x20),
                          *(UINT *)((int)local_2c + iVar2 + -0x1c));
      goto LAB_4500edf7;
    }
  }
  _Str = (wchar_t *)0x0;
LAB_4500edf7:
  if (*_Str == L'\0') {
    uVar3 = 0;
  }
  else {
    uVar3 = _wcslen(_Str);
  }
  auStackY_54[1] = 0x4500ee11;
  FUN_45014125(local_2c,(undefined8 *)_Str,uVar3);
  sVar4 = _wcslen(L",  ");
  auStackY_54[1] = 0x4500ee27;
  FUN_45014125(local_2c,(undefined8 *)&DAT_4503e4a8,sVar4);
  if (*in_stack_00000024 == L'\0') {
    uVar3 = 0;
  }
  else {
    uVar3 = _wcslen(in_stack_00000024);
  }
  auStackY_54[1] = 0x4500ee41;
  FUN_45014125(local_2c,(undefined8 *)in_stack_00000024,uVar3);
  pppppwVar5 = local_2c;
  if (7 < local_18) {
    pppppwVar5 = (wchar_t *****)local_2c[0];
  }
  basic_string<>(local_30,(wchar_t *)pppppwVar5);
  auStackY_54[1] = 0x4500ee60;
  FUN_450046d9(local_2c,'\x01',0);
  auStackY_54[1] = 0x4500ee6b;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&param_3,true,0);
  FUN_45022eb8();
  return;
}


