// Source: CLCiffConversion_Layout.dll @ 4540e541; FUN_4540e541

void __fastcall FUN_4540e541(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  HGDIOBJ ho;
  void *unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  
  *(uint *)(unaff_EBP + -4) = unaff_ESI;
  if (param_1 < 0) {
    piVar3 = (int *)FUN_4540e7c9(unaff_EBX,(undefined4 *)(unaff_EBP + -0x3c));
    puVar1 = (undefined4 *)((int)unaff_EBX + 0x38);
    *(undefined4 **)(unaff_EBP + -0x34) = puVar1;
    FUN_454066f3(puVar1,piVar3);
    SysFreeString(*(BSTR *)(unaff_EBP + -0x3c));
    iVar4 = (**(code **)(**(int **)((int)unaff_EBX + 8) + 0xc))
                      (*(int **)((int)unaff_EBX + 8),*puVar1,*(undefined4 *)(unaff_EBP + -0x30));
    if (iVar4 < 0) {
      FUN_4540500e(0x45448670);
      goto LAB_4540e611;
    }
  }
  piVar3 = *(int **)((int)unaff_EBX + 8);
  *(uint *)(unaff_EBP + -0x38) = unaff_ESI;
  uVar2 = *(undefined4 *)((int)unaff_EBX + 0x34);
  *(uint *)(unaff_EBP + -0x34) = unaff_ESI;
  (**(code **)(*piVar3 + 0x18))
            (piVar3,*(undefined4 *)(unaff_EBP + -0x40),uVar2,unaff_EBP + -0x38,unaff_EBP + -0x34);
  puVar1 = *(undefined4 **)(unaff_EBP + -0x44);
  *puVar1 = *(undefined4 *)(unaff_EBP + -0x38);
  puVar1[1] = *(undefined4 *)(unaff_EBP + -0x34);
  iVar4 = (**(code **)(**(int **)((int)unaff_EBX + 8) + 0x10))
                    (*(int **)((int)unaff_EBX + 8),*(undefined4 *)((int)unaff_EBX + 0x38));
  if (iVar4 < 0) {
    FUN_4540500e(0x454486bc);
  }
LAB_4540e611:
  if (*(HGDIOBJ *)(unaff_EBP + -0x48) != (HGDIOBJ)0x0) {
    ho = SelectObject(*(HDC *)(unaff_EBP + -0x40),*(HGDIOBJ *)(unaff_EBP + -0x48));
    DeleteObject(ho);
  }
  DeleteDC(*(HDC *)(unaff_EBP + -0x40));
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(unaff_EBP + -0x2c),
             true,unaff_ESI);
  FUN_4542a966();
  return;
}


