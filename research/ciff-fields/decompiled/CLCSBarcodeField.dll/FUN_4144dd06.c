// Source: CLCSBarcodeField.dll @ 4144dd06; FUN_4144dd06

void __fastcall FUN_4144dd06(void *param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  HGDIOBJ local_84;
  byte *local_80;
  int local_7c;
  byte *local_78;
  byte *local_74;
  uint local_70;
  HGDIOBJ local_6c;
  HDC local_68;
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
    iVar2 = *(int *)((int)param_1 + 0x1c);
    local_78 = local_40;
    local_7c = local_3c;
    iVar3 = FUN_4144dc26(param_1,(int *)&local_68,&local_84,&local_60,&local_6c);
    if (-1 < iVar3) {
      iVar3 = FUN_4144db37(param_1,(LONG)local_40,local_3c,1,*(LONG *)((int)param_1 + 4),
                           *(LONG *)((int)param_1 + 8));
      if (iVar3 < 0) {
        FUN_4144da6c(param_1,local_68,local_6c);
      }
      else {
        local_64 = local_60;
        local_80 = (byte *)((local_3c + -1) * *(int *)((int)param_1 + 0x1c) +
                            ((uint)(local_78 + -1) >> 3) + *(int *)((int)param_1 + 0x18));
        if (local_3c != 0) {
          uVar4 = -(int)local_78;
          pbVar5 = local_78;
          do {
            pbVar1 = local_78;
            local_60 = (byte *)0x0;
            local_74 = local_80;
            local_70 = uVar4 & 7;
            if (pbVar5 != (byte *)0x0) {
              do {
                uVar6 = (uint)local_60 & 7;
                FUN_4144db0d(local_64,7 - (char)uVar6,local_74,(byte)local_70);
                if (uVar6 == 7) {
                  local_64 = local_64 + 1;
                }
                local_70 = local_70 + 1;
                if (7 < local_70) {
                  local_74 = local_74 + -1;
                  local_70 = 0;
                }
                local_60 = local_60 + 1;
                pbVar5 = local_78;
                local_3c = local_7c;
              } while (local_60 < pbVar1);
            }
            local_64 = local_64 + (iVar2 - ((uint)local_40 >> 3));
            local_80 = local_80 + -*(int *)((int)param_1 + 0x1c);
            local_3c = local_3c + -1;
            local_7c = local_3c;
          } while (local_3c != 0);
        }
        if ((local_84 != (HGDIOBJ)0x0) && (local_6c != (HGDIOBJ)0x0)) {
          SelectObject(local_68,local_6c);
        }
        DeleteDC(local_68);
        if (local_84 != (HGDIOBJ)0x0) {
          DeleteObject(local_84);
        }
      }
    }
  }
  FUN_41461e5c(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


