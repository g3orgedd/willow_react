// Source: CLCiffConversion_Data.dll @ 4500bed0; FUN_4500bed0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4500bed0(int param_1)

{
  LPVOID *ppv;
  int *piVar1;
  HRESULT HVar2;
  int iVar3;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x4500bedc;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFCharTranslate::Convert");
  local_8 = 0;
  FUN_45005aac(0x4503f70c);
  FUN_45005aac(0x4503db14);
  FUN_45005aac(0x4503f70c);
  ppv = (LPVOID *)(param_1 + -4);
  if (*ppv != (LPVOID)0x0) {
    piVar1 = *ppv;
    if (piVar1 != (int *)0x0) {
      *ppv = (LPVOID)0x0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    piVar1 = *ppv;
    if (piVar1 != (int *)0x0) {
      *ppv = (LPVOID)0x0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
  }
  HVar2 = CoCreateInstance((IID *)&DAT_4503e230,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4503f6a4,ppv);
  if (((-1 < HVar2) &&
      (iVar3 = (**(code **)(*(int *)*ppv + 0x1c))
                         (*ppv,*(undefined4 *)
                                (*(int *)(*(int *)(param_1 + -8) + 4) + 0x38 + param_1)), -1 < iVar3
      )) && (iVar3 = FUN_45006a05((int *)(param_1 + -8 + *(int *)(*(int *)(param_1 + -8) + 4))),
            -1 < iVar3)) {
    FUN_45005aac(0x4503f734);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45022eb8();
  return;
}


