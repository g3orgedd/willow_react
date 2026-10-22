// Source: CLCiffConversion_Data.dll @ 4502dc47; FUN_4502dc47

int __cdecl FUN_4502dc47(int param_1)

{
  BOOL BVar1;
  int iVar2;
  
  if (PTR_FUN_45042600 != (undefined *)0x0) {
    BVar1 = __IsNonwritableInCurrentImage((PBYTE)&PTR_FUN_45042600);
    if (BVar1 != 0) {
      (*(code *)PTR_FUN_45042600)(param_1);
    }
  }
  FUN_4502d712();
  iVar2 = __initterm_e((undefined4 *)&DAT_4503d2b8,(undefined4 *)&DAT_4503d2d0);
  if (iVar2 == 0) {
    FUN_4502386d(&LAB_45031d62);
    FUN_4502dd17((undefined4 *)&DAT_4503d288,(undefined4 *)&DAT_4503d2b4);
    if (DAT_45056f88 != (code *)0x0) {
      BVar1 = __IsNonwritableInCurrentImage((PBYTE)&DAT_45056f88);
      if (BVar1 != 0) {
        (*DAT_45056f88)(0,2,0);
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}


