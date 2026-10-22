// Source: CiffMgr.dll @ 6810c3ac; FUN_6810c3ac

void FUN_6810c3ac(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  DWORD unaff_EBX;
  uint unaff_EBP;
  DWORD unaff_ESI;
  undefined4 uStack0000000c;
  
  if (*(int *)(unaff_EBP - 0x2118) == 0) {
    if (unaff_EBP != 0x2114) {
      FUN_6810d431((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    FUN_68132710(*(uint **)(unaff_EBP - 0x2118),(byte)unaff_EBX,unaff_ESI);
    *(DWORD *)(unaff_EBP - 0x211c) = unaff_EBX;
    if (0 < *(int *)(unaff_EBP - 0x2124)) {
      iVar2 = *(int *)(unaff_EBP - 0x2124);
      do {
        iVar3 = *(int *)(unaff_EBP - 0x2118);
        uVar5 = FUN_6810d07b((uint)*(ushort *)((unaff_EBP - 0x2014) + unaff_EBX * 2));
        iVar4 = *(int *)(unaff_EBP - 0x211c);
        pbVar1 = (byte *)((int)unaff_EBX / 2 + iVar3);
        *pbVar1 = *pbVar1 | (char)uVar5 <<
                            (4U - (char)((*(uint *)(unaff_EBP - 0x211c) & 1) << 2) & 0x1f);
        unaff_EBX = iVar4 + 1;
        *(DWORD *)(unaff_EBP - 0x211c) = unaff_EBX;
      } while ((int)unaff_EBX < iVar2);
      unaff_ESI = *(DWORD *)(unaff_EBP - 0x2128);
      unaff_EBX = 0;
    }
    uVar5 = RegSetValueExW((HKEY)**(undefined4 **)(unaff_EBP - 0x2130),
                           *(LPCWSTR *)(unaff_EBP - 0x212c),unaff_EBX,3,
                           *(BYTE **)(unaff_EBP - 0x2118),unaff_ESI);
    if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
      FUN_6810d431((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar5 == 0) {
      FUN_6810d73a(*(void **)(unaff_EBP - 0x2120),*(undefined2 **)(unaff_EBP - 0x2138));
    }
    else {
      FUN_6810c93a(uVar5);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x6810c4cd;
  FUN_68132051(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}


