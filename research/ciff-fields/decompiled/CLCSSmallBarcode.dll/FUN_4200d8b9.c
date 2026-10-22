// Source: CLCSSmallBarcode.dll @ 4200d8b9; FUN_4200d8b9

void __fastcall FUN_4200d8b9(void *param_1)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  HGDIOBJ local_8c;
  int local_88;
  int local_84;
  byte *local_80;
  uint local_7c;
  byte *local_78;
  HDC local_74;
  byte *local_70;
  HGDIOBJ local_6c;
  byte *local_68;
  byte *local_64;
  int local_60;
  undefined1 local_5c [28];
  uint local_40;
  byte *local_3c;
  short local_36;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  iVar1 = GetObjectW(*(HANDLE *)((int)param_1 + 0x10),0x54,local_5c);
  if ((iVar1 != 0) && (local_36 == 1)) {
    local_80 = local_3c;
    local_84 = FUN_4200d3a0((int)param_1);
    local_84 = local_84 - (local_40 >> 3);
    iVar1 = FUN_4200d4bd(param_1,(int *)&local_74,&local_8c,&local_64,&local_6c);
    if (-1 < iVar1) {
      local_88 = FUN_4200d3ce(param_1,(LONG)local_3c,local_40,1,*(LONG *)((int)param_1 + 8),
                              *(LONG *)((int)param_1 + 4));
      pbVar3 = local_64;
      if (local_88 < 0) {
        FUN_4200d303(param_1,local_74,local_6c);
      }
      else {
        local_68 = local_64;
        local_64 = (byte *)0x0;
        pbVar2 = (byte *)((local_40 - 1) * *(int *)((int)param_1 + 0x1c) +
                         *(int *)((int)param_1 + 0x18));
        local_78 = pbVar2;
        if (local_80 != (byte *)0x0) {
          do {
            local_60 = 7 - ((uint)local_64 & 7);
            local_7c = 0;
            local_70 = pbVar2;
            local_68 = pbVar3;
            if (local_40 != 0) {
              do {
                uVar4 = local_7c & 7;
                FUN_4200d3a4(pbVar3,7 - (char)uVar4,local_70,(byte)local_60);
                if (uVar4 == 7) {
                  pbVar3 = pbVar3 + 1;
                }
                local_70 = local_70 + -*(int *)((int)param_1 + 0x1c);
                local_7c = local_7c + 1;
                pbVar2 = local_78;
              } while (local_7c < local_40);
            }
            pbVar3 = pbVar3 + local_84;
            if (local_60 == 0) {
              pbVar2 = pbVar2 + 1;
              local_78 = pbVar2;
            }
            local_64 = local_64 + 1;
            local_68 = pbVar3;
          } while (local_64 < local_80);
        }
        if ((local_8c != (HGDIOBJ)0x0) && (local_6c != (HGDIOBJ)0x0)) {
          SelectObject(local_74,local_6c);
        }
        DeleteDC(local_74);
        if (local_8c != (HGDIOBJ)0x0) {
          DeleteObject(local_8c);
        }
      }
    }
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


