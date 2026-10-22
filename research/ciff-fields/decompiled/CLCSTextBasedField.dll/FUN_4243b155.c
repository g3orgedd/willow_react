// Source: CLCSTextBasedField.dll @ 4243b155; FUN_4243b155

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_4243b155(void *this,undefined4 param_1,OLECHAR *param_2,LPRECT param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x4243b161;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"DrawUniscribe::CalcTextRect");
  local_8 = 0;
  if ((param_2 != (OLECHAR *)0x0) && (param_3 != (LPRECT)0x0)) {
    FUN_4246d990((uint *)((int)this + 0x10),0,0x10);
    FUN_4246d2c0((undefined8 *)((int)this + 0x20),(undefined8 *)param_3,0x10);
    *(undefined4 *)((int)this + 8) = param_1;
    *(undefined4 *)((int)this + 0x34) = param_5;
    *(undefined4 *)((int)this + 0x30) = param_4;
    FUN_42403b70((void *)((int)this + 0x38),param_2);
    iVar1 = SetBkMode(*(HDC *)((int)this + 8),1);
    *(int *)((int)this + 0x44) = iVar1;
    *(LPRECT *)((int)this + 0x204) = param_3;
    FUN_4243b804((int)this);
    if (*(int *)((int)this + 0xb0) != 0) {
      FUN_4243b35d((int)this);
    }
    FUN_4243b117(this,*(HDC *)((int)this + 8),*(HFONT *)((int)this + 0x38),param_3,
                 *(uint *)((int)this + 0x30) | 0x420);
    if (*(int *)((int)this + 0xb0) != 0) {
      FUN_4243b41c((int)this);
      *(undefined4 *)((int)this + 0xb0) = 0;
    }
    FUN_4243b339((int)this);
    if (-1 < *(int *)((int)this + 0x44)) {
      SetBkMode(*(HDC *)((int)this + 8),*(int *)((int)this + 0x44));
    }
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined4 *)((int)this + 0xbc) = 0;
    FUN_42403b70((void *)((int)this + 0x38),L"");
    *(undefined4 *)((int)this + 0x44) = 0xffffffff;
    *(undefined4 *)((int)this + 0x30) = 0;
    *(undefined4 *)((int)this + 0x34) = 0;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4246ecf6();
  return;
}


