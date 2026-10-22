// Source: CLCSSmallBarcode.dll @ 4200b048; FUN_4200b048

int __thiscall FUN_4200b048(void *this,undefined4 *param_1)

{
  int iVar1;
  double *pdVar2;
  int iVar3;
  undefined4 *puVar4;
  double dVar5;
  int local_8;
  
  iVar3 = *(int *)((int)this + 0x1448);
  if (iVar3 == 0x18) {
    iVar3 = 0;
    iVar1 = 0;
    dVar5 = DAT_4208a8a8;
    pdVar2 = this;
    do {
      pdVar2 = pdVar2 + 0x1b;
      if (*pdVar2 <= dVar5 && dVar5 != *pdVar2) {
        dVar5 = *pdVar2;
        iVar3 = iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x18);
    local_8 = 0;
    if (0 < *(int *)((int)this + 0x147c)) {
      puVar4 = (undefined4 *)((int)this + 0x1450);
      do {
        if (puVar4[1] == iVar3) {
          SelectObject((HDC)puVar4[-1],(HGDIOBJ)*puVar4);
          *puVar4 = 0;
          puVar4[1] = 0xffffffff;
        }
        local_8 = local_8 + 1;
        puVar4 = puVar4 + 3;
      } while (local_8 < *(int *)((int)this + 0x147c));
    }
    FUN_4200c57b((int)this + iVar3 * 0xd8 + 8);
  }
  else {
    *(int *)((int)this + 0x1448) = iVar3 + 1;
  }
  if (iVar3 != -1) {
    puVar4 = (undefined4 *)((int)this + iVar3 * 0xd8 + 0x10);
    for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *param_1;
      param_1 = param_1 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_4200d262((int)this + iVar3 * 0xd8 + 8);
  }
  return iVar3;
}


