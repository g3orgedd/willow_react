// Source: CLCSSmallBarcode.dll @ 4200a198; FUN_4200a198

undefined4 __thiscall FUN_4200a198(void *this,uint *param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  int local_c;
  
  if (param_1 == (uint *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    if (*(int *)((int)this + 8) != 0) {
      iVar7 = 0;
      bVar1 = true;
      local_20 = 0;
      local_1c = 0;
      local_c = 0;
      local_14 = 0;
      local_10 = 0;
      puVar6 = param_1;
      if (0 < param_2) {
        do {
          iVar8 = 0;
          if (*puVar6 != 0xff) {
            do {
              uVar3 = 0x80000000 >> ((byte)iVar8 & 0x1f);
              if (bVar1) {
                if ((*puVar6 & uVar3) == 0) {
                  local_10 = 1;
                  bVar1 = false;
                  local_20 = iVar7;
                  local_1c = iVar8;
                }
              }
              else if ((*puVar6 & uVar3) == 0) {
                local_10 = local_10 + 1;
                local_14 = iVar8;
                local_c = iVar7;
              }
              else {
                iVar5 = *(int *)((int)this + 0xc);
                if (local_10 <= iVar5) {
                  iVar5 = local_10 + -1;
                }
                if (0 < iVar5) {
                  iVar4 = iVar5 / 2;
                  if (iVar5 - iVar4 != 0) {
                    FUN_4200a2e3((int)(param_1 + local_20),local_1c,iVar5 - iVar4);
                  }
                  if (iVar4 != 0) {
                    uVar3 = iVar4 - 1;
                    if (0x20 < (int)uVar3) {
                      local_c = local_c - ((int)(uVar3 + ((int)uVar3 >> 0x1f & 0x1fU)) >> 5);
                      uVar3 = uVar3 & 0x1f;
                    }
                    if (local_14 < (int)uVar3) {
                      local_c = local_c + -1;
                      iVar5 = 0x20 - uVar3;
                    }
                    else {
                      iVar5 = -uVar3;
                    }
                    local_14 = local_14 + iVar5;
                    FUN_4200a2e3((int)(param_1 + local_c),local_14,iVar4);
                  }
                }
                bVar1 = true;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < 0x20);
          }
          iVar7 = iVar7 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar7 < param_2);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


