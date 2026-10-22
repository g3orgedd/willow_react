// Source: CLCiffConversion_Layout.dll @ 45401d5f; FUN_45401d5f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_45401d5f(void *this,undefined4 param_1,OLECHAR *param_2,LPRECT param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x45401d6b;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"DrawUniscribe::CalcTextRect");
  local_8 = 0;
  if ((param_2 != (OLECHAR *)0x0) && (param_3 != (LPRECT)0x0)) {
    FUN_45429f70((uint *)((int)this + 0x10),0,0x10);
    FUN_45429920((undefined8 *)((int)this + 0x20),(undefined8 *)param_3,0x10);
    *(undefined4 *)((int)this + 8) = param_1;
    *(undefined4 *)((int)this + 0x34) = param_5;
    *(undefined4 *)((int)this + 0x30) = param_4;
    FUN_45401cab((void *)((int)this + 0x38),param_2);
    iVar1 = SetBkMode(*(HDC *)((int)this + 8),1);
    *(int *)((int)this + 0x44) = iVar1;
    *(LPRECT *)((int)this + 0x1e4) = param_3;
    FUN_454020bb((int)this);
    if (*(int *)((int)this + 0x90) != 0) {
      FUN_45401e99((int)this);
    }
    FUN_45401d21(this,*(HDC *)((int)this + 8),*(HFONT *)((int)this + 0x38),param_3,
                 *(uint *)((int)this + 0x30) | 0x420);
    if (*(int *)((int)this + 0x90) != 0) {
      FUN_45401f58((int)this);
      *(undefined4 *)((int)this + 0x90) = 0;
    }
    FUN_45401e75((int)this);
    if (-1 < *(int *)((int)this + 0x44)) {
      SetBkMode(*(HDC *)((int)this + 8),*(int *)((int)this + 0x44));
    }
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined4 *)((int)this + 0x9c) = 0;
    FUN_45401cab((void *)((int)this + 0x38),L"");
    *(undefined4 *)((int)this + 0x44) = 0xffffffff;
    *(undefined4 *)((int)this + 0x30) = 0;
    *(undefined4 *)((int)this + 0x34) = 0;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


