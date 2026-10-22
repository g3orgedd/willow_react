// Source: CLCSSmallBarcode.dll @ 42031722; FUN_42031722

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __fastcall FUN_42031722(void *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  uint auStack_58 [5];
  uint auStack_44 [2];
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  undefined1 *local_14;
  uint local_10;
  char local_b;
  char local_a;
  bool local_9;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  iVar6 = 0;
  local_b = '\0';
  local_a = '\0';
  iVar2 = *(int *)((int)param_1 + 0x74);
  local_24 = *(uint *)((int)param_1 + 0x98);
  local_28 = *(int *)((int)param_1 + 0x9c);
  bVar8 = false;
  local_9 = false;
  if (iVar2 == 0) {
LAB_42031782:
    local_1c = *(int *)((int)param_1 + 0xd0);
    local_2c = local_1c + local_24;
    local_b = '\0';
    uVar7 = local_24;
  }
  else {
    if (iVar2 == 0x5a) {
      bVar8 = true;
      local_a = '\x01';
    }
    else {
      if (iVar2 == 0xb4) {
        local_a = '\x01';
        local_9 = true;
        goto LAB_42031782;
      }
      uVar7 = local_10;
      if (iVar2 != 0x10e) goto LAB_42031795;
    }
    local_2c = *(int *)((int)param_1 + 0xd0);
    local_b = '\x01';
    local_9 = !bVar8;
    uVar7 = 0;
    local_1c = local_2c;
  }
LAB_42031795:
  local_10 = uVar7 & 0x8000001f;
  if ((int)local_10 < 0) {
    local_10 = (local_10 - 1 | 0xffffffe0) + 1;
  }
  iVar4 = (int)(((int)uVar7 >> 0x1f & 0x1fU) + uVar7) >> 5;
  iVar2 = ((int)(local_2c + 0x1f + (local_2c + 0x1f >> 0x1f & 0x1fU)) >> 5) - iVar4;
  auStack_44[1] = 0x420317cd;
  local_14 = &stack0xffffffc4 + iVar2 * -4;
  if (&stack0xffffffc4 + iVar2 * -4 != (undefined1 *)0x0) {
    uVar7 = *(uint *)((int)param_1 + 0x108);
    if (*(char *)((int)param_1 + 0xed) != '\0') {
      uVar7 = uVar7 + 2;
    }
    local_20 = 0;
    if (uVar7 != 0) {
      do {
        puVar1 = local_14;
        if (iVar6 < 0) break;
        auStack_44[1 - iVar2] = iVar2 * 4;
        auStack_44[-iVar2] = 0xffffffff;
        auStack_58[4 - iVar2] = (uint)puVar1;
        auStack_58[3 - iVar2] = 0x42031809;
        FUN_420698e0((uint *)auStack_58[4 - iVar2],(byte)auStack_44[-iVar2],auStack_44[1 - iVar2]);
        auStack_44[1 - iVar2] = (uint)&local_18;
        auStack_44[-iVar2] = local_1c;
        auStack_58[4 - iVar2] = local_10;
        uVar5 = (uVar7 - local_20) - 1;
        bVar8 = local_a == '\0';
        auStack_58[3 - iVar2] = (uint)local_14;
        if (bVar8) {
          uVar3 = local_20;
          if (local_9 != false) {
            uVar3 = uVar5;
          }
          auStack_58[2 - iVar2] = uVar3;
          auStack_58[1 - iVar2] = 0x42031836;
          iVar6 = FUN_42030a6a(param_1,auStack_58[2 - iVar2],auStack_58[3 - iVar2],
                               auStack_58[4 - iVar2],auStack_44[-iVar2],(int *)auStack_44[1 - iVar2]
                              );
        }
        else {
          uVar3 = local_20;
          if (local_9 != false) {
            uVar3 = uVar5;
          }
          auStack_58[2 - iVar2] = uVar3;
          auStack_58[1 - iVar2] = 0x4203186d;
          iVar6 = FUN_42030bef(param_1,auStack_58[2 - iVar2],auStack_58[3 - iVar2],
                               auStack_58[4 - iVar2],auStack_44[-iVar2],(int *)auStack_44[1 - iVar2]
                              );
        }
        bVar8 = local_b == '\0';
        auStack_44[1 - iVar2] = local_18;
        if (bVar8) {
          auStack_44[-iVar2] = local_28;
          auStack_58[4 - iVar2] = local_1c;
          auStack_58[3 - iVar2] = local_10;
          auStack_58[2 - iVar2] = iVar4;
          auStack_58[1 - iVar2] = (uint)local_14;
          auStack_58[-iVar2] = 0x4203188e;
          FUN_42030ed2(param_1,(uint *)auStack_58[1 - iVar2],auStack_58[2 - iVar2],
                       auStack_58[3 - iVar2],auStack_58[4 - iVar2],auStack_44[-iVar2],
                       auStack_44[1 - iVar2]);
          local_28 = local_28 + local_18;
        }
        else {
          auStack_44[-iVar2] = local_24;
          auStack_58[4 - iVar2] = local_1c;
          auStack_58[3 - iVar2] = (uint)local_14;
          auStack_58[2 - iVar2] = 0x420318a7;
          FUN_42030d7f(param_1,auStack_58[3 - iVar2],auStack_58[4 - iVar2],
                       (uint *)auStack_44[-iVar2],auStack_44[1 - iVar2]);
          local_24 = local_24 + local_18;
        }
        local_20 = local_20 + 1;
      } while (local_20 < uVar7);
    }
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


