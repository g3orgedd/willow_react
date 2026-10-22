// Source: CLCiffConversion_Layout.dll @ 454246e4; FUN_454246e4

/* WARNING: Unable to track spacebase fully for stack */

void FUN_454246e4(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  DWORD unaff_EBX;
  uint unaff_EBP;
  DWORD unaff_ESI;
  
  if (*(int *)(unaff_EBP - 0x1118) == 0) {
    if (unaff_EBP != 0x1114) {
      FUN_454037d2((undefined4 *)(unaff_EBP - 0x1118));
    }
  }
  else {
    FUN_45429f70(*(uint **)(unaff_EBP - 0x1118),(byte)unaff_EBX,unaff_ESI);
    *(DWORD *)(unaff_EBP - 0x111c) = unaff_EBX;
    if (0 < *(int *)(unaff_EBP - 0x1134)) {
      iVar3 = *(int *)(unaff_EBP - 0x1134);
      do {
        iVar4 = *(int *)(unaff_EBP - 0x1118);
        bVar2 = *(byte *)((unaff_EBP - 0x1014) + unaff_EBX);
        uVar6 = FUN_45425671((void *)(uint)bVar2,bVar2);
        iVar5 = *(int *)(unaff_EBP - 0x111c);
        pbVar1 = (byte *)((int)unaff_EBX / 2 + iVar4);
        *pbVar1 = *pbVar1 | (char)uVar6 <<
                            (4U - (char)((*(uint *)(unaff_EBP - 0x111c) & 1) << 2) & 0x1f);
        unaff_EBX = iVar5 + 1;
        *(DWORD *)(unaff_EBP - 0x111c) = unaff_EBX;
      } while ((int)unaff_EBX < iVar3);
      unaff_ESI = *(DWORD *)(unaff_EBP - 0x1130);
      unaff_EBX = 0;
    }
    uVar6 = RegSetValueExA((HKEY)**(undefined4 **)(unaff_EBP - 0x1128),
                           *(LPCSTR *)(unaff_EBP - 0x1124),unaff_EBX,3,
                           *(BYTE **)(unaff_EBP - 0x1118),unaff_ESI);
    if (*(int *)(unaff_EBP - 0x1118) != unaff_EBP - 0x1114) {
      FUN_454037d2((undefined4 *)(unaff_EBP - 0x1118));
    }
    if (uVar6 == 0) {
      FUN_45426781(*(void **)(unaff_EBP - 0x112c),*(undefined1 **)(unaff_EBP - 0x1138));
    }
    else {
      FUN_45424c03(uVar6);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar6 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x113c) = 0x4542480b;
  FUN_4542a8d1(uVar6 ^ unaff_EBP);
  return;
}


