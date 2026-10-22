// Source: CLCSTextBasedField.dll @ 42467d82; FUN_42467d82

void __fastcall FUN_42467d82(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  HGDIOBJ ho;
  void *unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  
  *(uint *)(unaff_EBP + -4) = unaff_ESI;
  if (param_1 < 0) {
    piVar3 = (int *)FUN_42468007(unaff_EBX,(undefined4 *)(unaff_EBP + -0x30));
    *(void **)(unaff_EBP + -0x38) = (void *)((int)unaff_EBX + 0x38);
    FUN_4241115f((void *)((int)unaff_EBX + 0x38),piVar3);
    SysFreeString(*(BSTR *)(unaff_EBP + -0x30));
    iVar4 = (**(code **)(**(int **)((int)unaff_EBX + 8) + 0xc))
                      (*(int **)((int)unaff_EBX + 8),*(undefined4 *)((int)unaff_EBX + 0x38));
    if (iVar4 < 0) {
      FUN_42403ff7(0x4249ba50);
      goto LAB_42467e4f;
    }
  }
  piVar3 = *(int **)((int)unaff_EBX + 8);
  *(uint *)(unaff_EBP + -0x34) = unaff_ESI;
  uVar1 = *(undefined4 *)((int)unaff_EBX + 0x34);
  *(uint *)(unaff_EBP + -0x30) = unaff_ESI;
  (**(code **)(*piVar3 + 0x18))
            (piVar3,*(undefined4 *)(unaff_EBP + -0x3c),uVar1,unaff_EBP + -0x34,unaff_EBP + -0x30);
  puVar2 = *(undefined4 **)(unaff_EBP + -0x40);
  *puVar2 = *(undefined4 *)(unaff_EBP + -0x34);
  puVar2[1] = *(undefined4 *)(unaff_EBP + -0x30);
  iVar4 = (**(code **)(**(int **)((int)unaff_EBX + 8) + 0x10))
                    (*(int **)((int)unaff_EBX + 8),*(undefined4 *)((int)unaff_EBX + 0x38));
  if (iVar4 < 0) {
    FUN_42403ff7(0x4249ba9c);
  }
LAB_42467e4f:
  if (*(HGDIOBJ *)(unaff_EBP + -0x48) != (HGDIOBJ)0x0) {
    ho = SelectObject(*(HDC *)(unaff_EBP + -0x3c),*(HGDIOBJ *)(unaff_EBP + -0x48));
    DeleteObject(ho);
  }
  DeleteDC(*(HDC *)(unaff_EBP + -0x3c));
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(unaff_EBP + -0x2c),
             true,unaff_ESI);
  FUN_4246ed05();
  return;
}


