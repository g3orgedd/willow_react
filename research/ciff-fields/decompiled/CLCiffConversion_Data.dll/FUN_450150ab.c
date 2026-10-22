// Source: CLCiffConversion_Data.dll @ 450150ab; FUN_450150ab

void FUN_450150ab(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  DWORD unaff_EBX;
  uint unaff_EBP;
  DWORD unaff_ESI;
  undefined4 uStack0000000c;
  
  if (*(int *)(unaff_EBP - 0x2118) == 0) {
    if (unaff_EBP != 0x2114) {
      FUN_45016630((undefined4 *)(unaff_EBP - 0x2118));
    }
  }
  else {
    FUN_45021c10(*(uint **)(unaff_EBP - 0x2118),(byte)unaff_EBX,unaff_ESI);
    *(DWORD *)(unaff_EBP - 0x211c) = unaff_EBX;
    if (0 < *(int *)(unaff_EBP - 0x2124)) {
      iVar2 = *(int *)(unaff_EBP - 0x2124);
      do {
        iVar3 = *(int *)(unaff_EBP - 0x2118);
        iVar5 = FUN_45015f01((uint)*(ushort *)((unaff_EBP - 0x2014) + unaff_EBX * 2));
        iVar4 = *(int *)(unaff_EBP - 0x211c);
        pbVar1 = (byte *)((int)unaff_EBX / 2 + iVar3);
        *pbVar1 = *pbVar1 | (char)iVar5 <<
                            (4U - (char)((*(uint *)(unaff_EBP - 0x211c) & 1) << 2) & 0x1f);
        unaff_EBX = iVar4 + 1;
        *(DWORD *)(unaff_EBP - 0x211c) = unaff_EBX;
      } while ((int)unaff_EBX < iVar2);
      unaff_ESI = *(DWORD *)(unaff_EBP - 0x2128);
      unaff_EBX = 0;
    }
    uVar6 = RegSetValueExW((HKEY)**(undefined4 **)(unaff_EBP - 0x2130),
                           *(LPCWSTR *)(unaff_EBP - 0x212c),unaff_EBX,3,
                           *(BYTE **)(unaff_EBP - 0x2118),unaff_ESI);
    if (*(int *)(unaff_EBP - 0x2118) != unaff_EBP - 0x2114) {
      FUN_45016630((undefined4 *)(unaff_EBP - 0x2118));
    }
    if (uVar6 == 0) {
      FUN_4501703e(*(void **)(unaff_EBP - 0x2120),*(undefined2 **)(unaff_EBP - 0x2138));
    }
    else {
      FUN_450155fb(uVar6);
    }
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x450151cc;
  FUN_45022e32(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}


