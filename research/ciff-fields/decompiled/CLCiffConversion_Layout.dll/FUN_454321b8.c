// Source: CLCiffConversion_Layout.dll @ 454321b8; FUN_454321b8

int __cdecl FUN_454321b8(int param_1)

{
  BOOL BVar1;
  int iVar2;
  
  if (PTR_FUN_4544bf88 != (undefined *)0x0) {
    BVar1 = __IsNonwritableInCurrentImage((PBYTE)&PTR_FUN_4544bf88);
    if (BVar1 != 0) {
      (*(code *)PTR_FUN_4544bf88)(param_1);
    }
  }
  FUN_45431d22();
  iVar2 = __initterm_e((undefined4 *)&DAT_4544733c,(undefined4 *)&DAT_45447354);
  if (iVar2 == 0) {
    FUN_4542db10(&LAB_4543a8cb);
    FUN_45432288((undefined4 *)&DAT_4544730c,(undefined4 *)&DAT_45447338);
    if (DAT_45462784 != (code *)0x0) {
      BVar1 = __IsNonwritableInCurrentImage((PBYTE)&DAT_45462784);
      if (BVar1 != 0) {
        (*DAT_45462784)(0,2,0);
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}


