// Source: CLCSSmallBarcode.dll @ 4203318e; FUN_4203318e

void __thiscall FUN_4203318e(void *this,uint param_1)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int local_4c;
  uint local_48 [16];
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  local_4c = 0;
  do {
    if (param_1 == 0) {
      FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    uVar7 = param_1;
    if (0x2c < param_1) {
      uVar7 = 0x2c;
    }
    FUN_420698e0(local_48,0,0x40);
    iVar4 = uVar7 - 1;
    if (-2 < iVar4) {
      piVar2 = &DAT_420956ec + ((uVar7 - iVar4) + -1) * 0x10;
      do {
        if (iVar4 < 0) {
          iVar8 = 1;
        }
        else {
          iVar8 = *(byte *)((int)this + iVar4 + *(int *)((int)this + 0xad0) + 0x34) - 0x30;
        }
        if (0 < iVar8) {
          do {
            uVar5 = 0;
            uVar6 = 0xf;
            piVar3 = piVar2;
            do {
              local_48[uVar6] = local_48[uVar6] + *piVar3 + uVar5;
              uVar5 = local_48[uVar6];
              if (899 < (int)uVar5) {
                local_48[uVar6] = local_48[uVar6] - 900;
              }
              uVar5 = (uint)(899 < (int)uVar5);
              uVar6 = uVar6 - 1;
              piVar3 = piVar3 + -1;
            } while (uVar6 < 0x80000000);
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        iVar4 = iVar4 + -1;
        piVar2 = piVar2 + 0x10;
      } while (-2 < iVar4);
    }
    bVar1 = false;
    iVar4 = 0;
    do {
      if (local_4c != 0) break;
      if ((local_48[iVar4] != 0) || (bVar1)) {
        local_4c = FUN_42031972(this,(short)local_48[iVar4]);
        bVar1 = true;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x10);
    param_1 = param_1 - uVar7;
    *(int *)((int)this + 0xad0) = *(int *)((int)this + 0xad0) + uVar7;
  } while( true );
}


