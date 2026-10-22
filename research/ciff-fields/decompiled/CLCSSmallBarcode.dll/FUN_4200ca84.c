// Source: CLCSSmallBarcode.dll @ 4200ca84; FUN_4200ca84

/* WARNING: Function: __SEH_prolog4_GS replaced with injection: SEH_prolog4 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_4200ca84(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint auStack_60 [6];
  uint uStack_48;
  undefined1 local_44 [4];
  
  uVar1 = *(uint *)((int)this + 0x84);
  iVar2 = *(int *)((int)this + 0x70);
  uVar3 = uVar1 & 0x8000001f;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xffffffe0) + 1;
  }
  iVar6 = (int)(((int)uVar1 >> 0x1f & 0x1fU) + uVar1) >> 5;
  iVar4 = uVar1 + 0x1f + iVar2;
  iVar5 = ((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) - iVar6;
  uStack_48 = 0x4200cae1;
  iVar4 = iVar5 * -4;
  if (local_44 + iVar4 != (undefined1 *)0x0) {
    *(int *)(local_44 + iVar4 + -4) = iVar5 * 4;
    auStack_60[5 - iVar5] = 0xffffffff;
    auStack_60[4 - iVar5] = (uint)(local_44 + iVar4);
    auStack_60[3 - iVar5] = 0x4200caf3;
    FUN_420698e0((uint *)auStack_60[4 - iVar5],(byte)auStack_60[5 - iVar5],
                 *(uint *)(local_44 + iVar4 + -4));
    *(int *)(local_44 + iVar4 + -4) = iVar2;
    auStack_60[5 - iVar5] = uVar3;
    auStack_60[4 - iVar5] = (uint)(local_44 + iVar4);
    auStack_60[3 - iVar5] = param_3;
    auStack_60[2 - iVar5] = param_2;
    auStack_60[1 - iVar5] = param_1;
    auStack_60[-iVar5] = 0x4200cb0d;
    FUN_4200b2f6(this,(int *)auStack_60[1 - iVar5],(int *)auStack_60[2 - iVar5],
                 auStack_60[3 - iVar5],auStack_60[4 - iVar5],auStack_60[5 - iVar5]);
    *(int *)(local_44 + iVar4 + -4) = iVar5;
    auStack_60[5 - iVar5] = (uint)(local_44 + iVar4);
    auStack_60[4 - iVar5] = 0x4200cb1d;
    FUN_4200a198(this,(uint *)auStack_60[5 - iVar5],*(int *)(local_44 + iVar4 + -4));
    *(int *)(local_44 + iVar4 + -4) = iVar2;
    auStack_60[5 - iVar5] = uVar3;
    auStack_60[4 - iVar5] = iVar6;
    auStack_60[3 - iVar5] = (uint)(local_44 + iVar4);
    auStack_60[2 - iVar5] = 0x4200cb2e;
    FUN_4200b4a1(this,(uint *)auStack_60[3 - iVar5],auStack_60[4 - iVar5],auStack_60[5 - iVar5],
                 *(uint **)(local_44 + iVar4 + -4));
  }
  uStack_48 = 0x4200cb5c;
  FUN_4206b878();
  return;
}


