// Source: CLCiffConversion_Layout.dll @ 45426231; FUN_45426231

undefined4 __cdecl FUN_45426231(LPCSTR param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    iVar1 = lstrcmpiA(param_1,(&PTR_DAT_4544a870)[uVar2 * 2]);
    if (iVar1 == 0) {
      return (&DAT_4544a874)[uVar2 * 2];
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xe);
  return 0;
}


