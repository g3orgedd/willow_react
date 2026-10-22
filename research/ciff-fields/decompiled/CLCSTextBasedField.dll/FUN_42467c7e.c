// Source: CLCSTextBasedField.dll @ 42467c7e; FUN_42467c7e

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_42467c7e(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4
            )

{
  HDC hdc;
  HGDIOBJ pvVar1;
  int iVar2;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x42467c8a;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"ZipherBitmapFont::CalculateSize");
  local_8 = 0;
  hdc = CreateCompatibleDC((HDC)0x0);
  pvVar1 = (HGDIOBJ)FUN_42468ee3(hdc);
  iVar2 = FUN_42467e85((int)this);
  if (iVar2 == 0) {
    iVar2 = FUN_42467f03((int)this);
    if (iVar2 == 0) {
      FUN_42468f57(this,param_2,param_3,param_4);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = (**(code **)(**(int **)((int)this + 8) + 0xc))
                        (*(int **)((int)this + 8),*(undefined4 *)((int)this + 0x38),
                         *(int *)((int)this + 0xc) != 0,0,*(undefined4 *)((int)this + 0x24),
                         *(undefined4 *)((int)this + 0x28),*(undefined4 *)((int)this + 0x2c),
                         *(int *)((int)this + 0x1c) == 1);
      FUN_42467d82(iVar2);
      return;
    }
  }
  if (pvVar1 != (HGDIOBJ)0x0) {
    pvVar1 = SelectObject(hdc,pvVar1);
    DeleteObject(pvVar1);
  }
  DeleteDC(hdc);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4246ed05();
  return;
}


