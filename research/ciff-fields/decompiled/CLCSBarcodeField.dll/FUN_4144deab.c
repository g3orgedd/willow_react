// Source: CLCSBarcodeField.dll @ 4144deab; FUN_4144deab

void __fastcall FUN_4144deab(void *param_1)

{
  HGDIOBJ ho;
  byte *pbVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  HGDIOBJ local_80;
  int local_7c;
  byte *local_78;
  byte *local_74;
  HDC local_70;
  byte *local_6c;
  HGDIOBJ local_68;
  byte *local_64;
  byte *local_60;
  undefined1 local_5c [28];
  byte *local_40;
  int local_3c;
  short local_36;
  uint local_8;
  
  local_8 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  iVar2 = GetObjectW(*(HANDLE *)((int)param_1 + 0x10),0x54,local_5c);
  if ((iVar2 != 0) && (local_36 == 1)) {
    local_74 = local_40;
    local_7c = local_3c;
    iVar2 = FUN_4144db09((int)param_1);
    iVar3 = FUN_4144dc26(param_1,(int *)&local_70,&local_80,&local_64,&local_68);
    if (-1 < iVar3) {
      iVar3 = FUN_4144db37(param_1,local_3c,(LONG)local_40,1,*(LONG *)((int)param_1 + 8),
                           *(LONG *)((int)param_1 + 4));
      if (iVar3 < 0) {
        FUN_4144da6c(param_1,local_70,local_68);
      }
      else {
        local_78 = (byte *)((local_3c - 1U >> 3) + *(int *)((int)param_1 + 0x18));
        uVar5 = -local_3c & 7;
        pbVar4 = local_78;
        local_60 = local_64;
        ho = local_80;
        iVar3 = local_7c;
        pbVar1 = local_6c;
        local_7c = local_3c;
        while (local_6c = pbVar4, local_7c != 0) {
          local_64 = (byte *)0x0;
          pbVar4 = local_6c;
          local_80 = ho;
          if (local_74 != (byte *)0x0) {
            do {
              local_7c = iVar3;
              uVar6 = (uint)local_64 & 7;
              FUN_4144db0d(local_60,7 - (char)uVar6,local_6c,(byte)uVar5);
              if (uVar6 == 7) {
                local_60 = local_60 + 1;
              }
              local_6c = local_6c + *(int *)((int)param_1 + 0x1c);
              local_64 = local_64 + 1;
              pbVar4 = local_78;
              iVar3 = local_7c;
            } while (local_64 < local_74);
          }
          local_60 = local_60 + (iVar2 - ((uint)local_40 >> 3));
          uVar5 = uVar5 + 1;
          if (7 < uVar5) {
            pbVar4 = pbVar4 + -1;
            uVar5 = 0;
            local_78 = pbVar4;
          }
          iVar3 = local_7c + -1;
          ho = local_80;
          pbVar1 = local_6c;
          local_7c = iVar3;
        }
        local_7c = iVar3;
        local_6c = pbVar1;
        if ((ho != (HGDIOBJ)0x0) && (local_68 != (HGDIOBJ)0x0)) {
          SelectObject(local_70,local_68);
        }
        DeleteDC(local_70);
        if (ho != (HGDIOBJ)0x0) {
          DeleteObject(ho);
        }
      }
    }
  }
  FUN_41461e5c(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


