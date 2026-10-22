// Source: CLCSSmallBarcode.dll @ 4200ce9a; FUN_4200ce9a

void __thiscall FUN_4200ce9a(void *this,int param_1,ushort *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  LOGFONTW local_64;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  if ((param_2 == (ushort *)0x0) || (iVar2 = FUN_4200b114(this,param_1), iVar2 == -1))
  goto LAB_4200d035;
  iVar3 = FUN_4200bd46(this,param_2);
  if (iVar3 == -1) {
    local_64.lfHeight = *(LONG *)(param_2 + 0x22);
    local_64.lfEscapement = ((0x168 - *(int *)(param_2 + 0x26)) % 0x168) * 10;
    local_64.lfWidth = 0;
    local_64.lfWeight = 400;
    if ((*(uint *)(param_2 + 0x28) & 1) != 0) {
      local_64.lfWeight = 700;
    }
    local_64.lfUnderline = '\0';
    local_64.lfStrikeOut = '\0';
    local_64.lfCharSet = '\x01';
    local_64.lfOutPrecision = '\0';
    local_64.lfPitchAndFamily = (BYTE)param_2[0x20];
    local_64.lfItalic = (byte)(*(uint *)(param_2 + 0x28) >> 1) & 1;
    local_64.lfClipPrecision = '\0';
    local_64.lfQuality = '\0';
    local_64.lfOrientation = local_64.lfEscapement;
    FUN_4206a09b(local_64.lfFaceName,0x20,(short *)param_2,0x1f);
    local_64.lfFaceName[0x1f] = L'\0';
    iVar3 = *(int *)(param_2 + 0x24);
    if (iVar3 != 100) {
      param_2[0x24] = 100;
      param_2[0x25] = 0;
      iVar4 = FUN_4200bd46(this,param_2);
      if ((iVar4 == -1) && (iVar4 = FUN_4200b608(this,&local_64,(undefined4 *)param_2), iVar4 != -1)
         ) {
        FUN_4200d122(this,iVar2,iVar4);
      }
      *(int *)(param_2 + 0x24) = iVar3;
      if (iVar4 != -1) {
        iVar1 = *(int *)((int)this + iVar4 * 0xd8 + 200);
        if ((*(int *)((int)this + iVar4 * 0xd8 + 100) * 100) /
            *(int *)((int)this + iVar4 * 0xd8 + 0x68) - 0x62U < 5) {
          local_64.lfWidth = iVar1 * iVar3 + 0x32;
        }
        else {
          local_64.lfWidth = iVar1 * iVar3;
        }
        local_64.lfWidth = local_64.lfWidth / 100;
        if (local_64.lfWidth == iVar1) {
          local_64.lfWidth = 0;
        }
      }
    }
    iVar3 = FUN_4200b608(this,&local_64,(undefined4 *)param_2);
    if (iVar3 == -1) goto LAB_4200d035;
  }
  else {
    if (*(int *)(iVar2 * 0xc + 0x1454 + (int)this) == iVar3) goto LAB_4200d035;
    if (*(char *)(iVar3 * 0xd8 + 0xcc + (int)this) != '\0') {
      FUN_4200ce9a(this,param_1,(ushort *)(iVar3 * 0xd8 + 0x6c + (int)this));
      goto LAB_4200d035;
    }
  }
  FUN_4200d122(this,iVar2,iVar3);
LAB_4200d035:
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


