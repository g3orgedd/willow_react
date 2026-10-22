// Source: CLCSSmallBarcode.dll @ 42031bfe; FUN_42031bfe

void __thiscall FUN_42031bfe(void *this,uint param_1)

{
  int iVar1;
  uint3 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined2 uVar10;
  uint local_20 [7];
  
  local_20[6] = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  if (param_1 % 6 == 0) {
    uVar10 = 0x39c;
  }
  else {
    uVar10 = 0x385;
  }
  iVar3 = FUN_42031972(this,uVar10);
  while ((5 < param_1 && (iVar3 == 0))) {
    iVar3 = *(int *)((int)this + 0xad0);
    uVar2 = CONCAT21(CONCAT11(*(undefined1 *)((int)this + iVar3 + 0x34),
                              *(undefined1 *)((int)this + iVar3 + 0x35)),
                     *(undefined1 *)((int)this + iVar3 + 0x36));
    uVar8 = (uint)uVar2;
    uVar9 = (uint)CONCAT21(CONCAT11(*(undefined1 *)((int)this + iVar3 + 0x37),
                                    *(undefined1 *)((int)this + iVar3 + 0x38)),
                           *(undefined1 *)((int)this + iVar3 + 0x39));
    FUN_420698e0(local_20 + 3,0,0xc);
    FUN_420698e0(local_20,0,0xc);
    iVar3 = 0;
    uVar4 = uVar8;
    if (899 < uVar2) {
      do {
        uVar4 = (int)uVar8 / 900;
        local_20[iVar3 + 3] = (int)uVar8 % 900;
        iVar3 = iVar3 + 1;
        uVar8 = uVar4;
      } while (899 < (int)uVar4);
    }
    local_20[iVar3 + 3] = uVar4;
    iVar3 = 0;
    uVar8 = uVar9;
    if (899 < uVar9) {
      do {
        uVar9 = (int)uVar8 / 900;
        local_20[iVar3] = (int)uVar8 % 900;
        iVar3 = iVar3 + 1;
        uVar8 = uVar9;
      } while (899 < (int)uVar9);
    }
    local_20[iVar3] = uVar9;
    iVar5 = local_20[0] + local_20[3] * 0x13c;
    iVar6 = iVar5 / 900 + local_20[4] * 0x13c + local_20[3] * 0x281 + local_20[1];
    iVar7 = iVar6 / 900 +
            local_20[3] * 0x14 + local_20[5] * 0x13c + local_20[2] + local_20[4] * 0x281;
    iVar1 = local_20[4] * 0x14 + iVar7 / 900 + local_20[5] * 0x281;
    iVar3 = FUN_42031972(this,(short)((int)(local_20[5] * 0x14 + iVar1 / 900) % 900));
    if ((((iVar3 == 0) && (iVar3 = FUN_42031972(this,(short)(iVar1 % 900)), iVar3 == 0)) &&
        (iVar3 = FUN_42031972(this,(short)(iVar7 % 900)), iVar3 == 0)) &&
       (iVar3 = FUN_42031972(this,(short)(iVar6 % 900)), iVar3 == 0)) {
      iVar3 = FUN_42031972(this,(short)(iVar5 % 900));
    }
    *(int *)((int)this + 0xad0) = *(int *)((int)this + 0xad0) + 6;
    param_1 = param_1 - 6;
  }
  while ((param_1 != 0 && (iVar3 == 0))) {
    iVar3 = FUN_42031972(this,(ushort)*(byte *)((int)this + *(int *)((int)this + 0xad0) + 0x34));
    *(int *)((int)this + 0xad0) = *(int *)((int)this + 0xad0) + 1;
    param_1 = param_1 - 1;
  }
  FUN_4206a5c8(local_20[6] ^ (uint)&stack0xfffffffc);
  return;
}


