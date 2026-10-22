// Source: CLCSSmallBarcode.dll @ 420344de; FUN_420344de

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */

void __fastcall FUN_420344de(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  int iVar12;
  undefined4 uStack_5c;
  char acStack_58 [4];
  char acStack_54 [4];
  uint auStack_50 [6];
  undefined4 uStack_38;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  uint local_10;
  char local_9;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  local_14 = 0;
  local_20 = param_1[0x2a];
  iVar3 = param_1[0x2b];
  uStack_38 = 0x4203450e;
  local_28 = iVar3;
  (**(code **)(*param_1 + 0x20))();
  local_9 = (char)param_1[0x37];
  iVar12 = 0;
  if (local_9 == '\x01') {
    iVar12 = 8;
  }
  uVar1 = param_1[0x2a];
  iVar12 = (iVar12 + param_1[0x38]) * param_1[0x24];
  if (iVar3 < param_1[0x2b]) {
    param_1[0x2b] = iVar3;
  }
  local_10 = uVar1 & 0x8000001f;
  if ((int)local_10 < 0) {
    local_10 = (local_10 - 1 | 0xffffffe0) + 1;
  }
  local_1c = (int)(((int)uVar1 >> 0x1f & 0x1fU) + uVar1) >> 5;
  iVar3 = param_1[0x2a] + 0x1f + iVar12;
  iVar4 = ((int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5) - local_1c;
  local_24 = iVar4 * 4;
  uStack_38 = 0x42034583;
  iVar3 = iVar4 * -4;
  if (&stack0xffffffcc + iVar3 != (undefined1 *)0x0) {
    if (local_9 == '\x01') {
      auStack_50[6 - iVar4] = iVar4 * 4;
      auStack_50[5 - iVar4] = ((char)param_1[0x34] == '\x01') - 1;
      auStack_50[4 - iVar4] = (uint)(&stack0xffffffcc + iVar3);
      auStack_50[3 - iVar4] = 0x420345aa;
      FUN_420698e0((uint *)auStack_50[4 - iVar4],(byte)auStack_50[5 - iVar4],auStack_50[6 - iVar4]);
      auStack_50[6 - iVar4] = 4;
      auStack_50[5 - iVar4] = iVar12;
      auStack_50[4 - iVar4] = local_10;
      auStack_50[3 - iVar4] = local_1c;
      auStack_50[2 - iVar4] = (uint)(&stack0xffffffcc + iVar3);
      auStack_50[1 - iVar4] = (uint)&local_20;
      auStack_50[-iVar4] = (uint)&local_28;
      pcVar6 = acStack_54 + iVar3;
      pcVar6[0] = '\0';
      pcVar6[1] = '\0';
      pcVar6[2] = '\0';
      pcVar6[3] = '\0';
      pcVar7 = acStack_58 + iVar3;
      pcVar7[0] = '\0';
      pcVar7[1] = '\0';
      pcVar7[2] = '\0';
      pcVar7[3] = '\0';
      (&uStack_5c)[-iVar4] = 0x420345ca;
      FUN_42034693(param_1,acStack_58[iVar3],acStack_54[iVar3],(int *)auStack_50[-iVar4],
                   (int *)auStack_50[1 - iVar4],(uint *)auStack_50[2 - iVar4],auStack_50[3 - iVar4],
                   auStack_50[4 - iVar4],auStack_50[5 - iVar4],auStack_50[6 - iVar4]);
    }
    local_18 = 0;
    if (0 < param_1[0x38]) {
      do {
        auStack_50[6 - iVar4] = local_24;
        auStack_50[5 - iVar4] = 0xffffffff;
        auStack_50[4 - iVar4] = (uint)(&stack0xffffffcc + iVar3);
        auStack_50[3 - iVar4] = 0x420345e2;
        FUN_420698e0((uint *)auStack_50[4 - iVar4],(byte)auStack_50[5 - iVar4],auStack_50[6 - iVar4]
                    );
        iVar2 = param_1[0x30];
        auStack_50[6 - iVar4] = local_18;
        auStack_50[5 - iVar4] = iVar12;
        auStack_50[4 - iVar4] = local_10;
        auStack_50[3 - iVar4] = (uint)(&stack0xffffffcc + iVar3);
        if ((char)iVar2 == '\0') {
          auStack_50[2 - iVar4] = 0x42034604;
          uVar5 = FUN_4203383b(param_1,auStack_50[3 - iVar4],auStack_50[4 - iVar4],
                               auStack_50[5 - iVar4],auStack_50[6 - iVar4]);
        }
        else {
          auStack_50[2 - iVar4] = 0x420345fd;
          uVar5 = FUN_4203399a(param_1,auStack_50[3 - iVar4],auStack_50[4 - iVar4],
                               auStack_50[5 - iVar4],auStack_50[6 - iVar4]);
        }
        auStack_50[6 - iVar4] = 1;
        auStack_50[5 - iVar4] = iVar12;
        auStack_50[4 - iVar4] = local_10;
        local_14 = uVar5;
        auStack_50[3 - iVar4] = local_1c;
        auStack_50[2 - iVar4] = (uint)(&stack0xffffffcc + iVar3);
        auStack_50[1 - iVar4] = (uint)&local_20;
        auStack_50[-iVar4] = (uint)&local_28;
        pcVar8 = acStack_54 + iVar3;
        pcVar8[0] = '\0';
        pcVar8[1] = '\0';
        pcVar8[2] = '\0';
        pcVar8[3] = '\0';
        pcVar9 = acStack_58 + iVar3;
        pcVar9[0] = '\0';
        pcVar9[1] = '\0';
        pcVar9[2] = '\0';
        pcVar9[3] = '\0';
        (&uStack_5c)[-iVar4] = 0x42034624;
        FUN_42034693(param_1,acStack_58[iVar3],acStack_54[iVar3],(int *)auStack_50[-iVar4],
                     (int *)auStack_50[1 - iVar4],(uint *)auStack_50[2 - iVar4],
                     auStack_50[3 - iVar4],auStack_50[4 - iVar4],auStack_50[5 - iVar4],
                     auStack_50[6 - iVar4]);
        local_18 = local_18 + 1;
      } while (local_18 < param_1[0x38]);
    }
    if ((char)param_1[0x37] == '\x01') {
      auStack_50[6 - iVar4] = local_24;
      auStack_50[5 - iVar4] = ((char)param_1[0x34] == '\x01') - 1;
      auStack_50[4 - iVar4] = (uint)(&stack0xffffffcc + iVar3);
      auStack_50[3 - iVar4] = 0x42034653;
      FUN_420698e0((uint *)auStack_50[4 - iVar4],(byte)auStack_50[5 - iVar4],auStack_50[6 - iVar4]);
      auStack_50[6 - iVar4] = 4;
      auStack_50[5 - iVar4] = iVar12;
      auStack_50[4 - iVar4] = local_10;
      auStack_50[3 - iVar4] = local_1c;
      auStack_50[2 - iVar4] = (uint)(&stack0xffffffcc + iVar3);
      auStack_50[1 - iVar4] = (uint)&local_20;
      auStack_50[-iVar4] = (uint)&local_28;
      pcVar10 = acStack_54 + iVar3;
      pcVar10[0] = '\0';
      pcVar10[1] = '\0';
      pcVar10[2] = '\0';
      pcVar10[3] = '\0';
      pcVar11 = acStack_58 + iVar3;
      pcVar11[0] = '\0';
      pcVar11[1] = '\0';
      pcVar11[2] = '\0';
      pcVar11[3] = '\0';
      (&uStack_5c)[-iVar4] = 0x42034673;
      FUN_42034693(param_1,acStack_58[iVar3],acStack_54[iVar3],(int *)auStack_50[-iVar4],
                   (int *)auStack_50[1 - iVar4],(uint *)auStack_50[2 - iVar4],auStack_50[3 - iVar4],
                   auStack_50[4 - iVar4],auStack_50[5 - iVar4],auStack_50[6 - iVar4]);
    }
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


