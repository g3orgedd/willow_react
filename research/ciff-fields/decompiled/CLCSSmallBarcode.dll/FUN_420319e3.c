// Source: CLCSSmallBarcode.dll @ 420319e3; FUN_420319e3

undefined4 __thiscall FUN_420319e3(void *this,uint *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint local_10;
  undefined4 local_c;
  
  local_c = 0;
  iVar1 = *(int *)((int)this + 0xad0);
  iVar2 = *(int *)((int)this + 0xacc);
  pbVar9 = (byte *)((int)this + iVar1 + 0x34);
  *param_1 = 0;
  uVar6 = iVar2 - iVar1;
  if (0xc < uVar6) {
    while (((byte)(*pbVar9 - 0x30) < 10 && (*param_1 < uVar6))) {
      pbVar9 = pbVar9 + 1;
      *param_1 = *param_1 + 1;
    }
    if (0xc < *param_1) {
      return 1;
    }
  }
  if (4 < uVar6) {
    iVar1 = *(int *)((int)this + 0xad0);
    *param_1 = 0;
    pbVar9 = (byte *)(iVar1 + 0x34 + (int)this);
    uVar5 = FUN_42033105(*pbVar9);
    if ((char)uVar5 != '\0') {
      do {
        if (uVar6 <= *param_1) break;
        pbVar9 = pbVar9 + 1;
        *param_1 = *param_1 + 1;
        uVar5 = FUN_42033105(*pbVar9);
      } while ((char)uVar5 != '\0');
      if (4 < *param_1) {
        return 2;
      }
    }
  }
  if (uVar6 != 0) {
    local_c = 3;
    if (5 < uVar6) {
      bVar3 = false;
      do {
        if ((*(char *)((int)this + 8) == '\0') || (*(int *)((int)this + 0x1c) == 0)) {
          while ((uVar5 = FUN_42033105(*pbVar9), (char)uVar5 == '\0' && (*param_1 < uVar6))) {
            pbVar9 = pbVar9 + 1;
            *param_1 = *param_1 + 1;
          }
        }
        else {
          bVar4 = *pbVar9;
          if ((bVar4 == 0x91) || (bVar4 == 0x92)) {
            pbVar9 = pbVar9 + 1;
            bVar3 = true;
            *param_1 = *param_1 + 1;
          }
          else {
            while (uVar5 = FUN_42033105(bVar4), (char)uVar5 == '\0') {
              if (bVar4 == 0x91) goto LAB_42031af9;
              if ((bVar4 == 0x92) || (uVar6 <= *param_1)) break;
              pbVar9 = pbVar9 + 1;
              *param_1 = *param_1 + 1;
              bVar4 = *pbVar9;
            }
            if ((*pbVar9 == 0x91) || (*pbVar9 == 0x92)) {
LAB_42031af9:
              bVar3 = true;
            }
          }
        }
        uVar8 = 0;
        uVar7 = uVar6 - *param_1;
        if (uVar7 == 0) {
          return 3;
        }
        if (bVar3) {
          return 3;
        }
        if (0xc < uVar7) {
          for (; ((byte)(pbVar9[uVar8] - 0x30) < 10 && (uVar8 < uVar7)); uVar8 = uVar8 + 1) {
          }
          if (0xc < uVar8) {
            if (4 < uVar7) {
              return 3;
            }
            goto LAB_42031bc2;
          }
        }
        if (uVar7 < 5) {
LAB_42031bc2:
          *param_1 = *param_1 + uVar7;
          return 3;
        }
        local_10 = 0;
        uVar5 = FUN_42033105(*pbVar9);
        if ((char)uVar5 == '\0') {
          local_10 = 0;
        }
        else {
          do {
            if (uVar7 <= local_10) break;
            local_10 = local_10 + 1;
            uVar5 = FUN_42033105(pbVar9[local_10]);
          } while ((char)uVar5 != '\0');
          if (4 < local_10) {
            return 3;
          }
        }
        pbVar9 = pbVar9 + local_10;
        *param_1 = *param_1 + local_10;
      } while( true );
    }
    if ((*(char *)((int)this + 8) == '\0') || (*(int *)((int)this + 0x1c) == 0)) {
      *param_1 = uVar6;
      local_c = 3;
    }
    else {
      bVar4 = *pbVar9;
      if ((bVar4 == 0x91) || (bVar4 == 0x92)) {
        *param_1 = 1;
      }
      else {
        do {
          if (bVar4 == 0x92) {
            return 3;
          }
          if (uVar6 <= *param_1) {
            return 3;
          }
          pbVar9 = pbVar9 + 1;
          *param_1 = *param_1 + 1;
          bVar4 = *pbVar9;
        } while (bVar4 != 0x91);
      }
    }
  }
  return local_c;
}


