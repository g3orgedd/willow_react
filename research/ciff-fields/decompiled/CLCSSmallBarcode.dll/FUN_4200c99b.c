// Source: CLCSSmallBarcode.dll @ 4200c99b; FUN_4200c99b

/* WARNING: Function: __SEH_prolog4_GS replaced with injection: SEH_prolog4 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_4200c99b(void *this,int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint auStack_5c [5];
  uint uStack_48;
  undefined1 local_44 [4];
  
  if (param_1 != 0) {
    uVar1 = *(uint *)((int)this + 0x84);
    iVar2 = *(int *)((int)this + 0x70);
    uVar6 = uVar1 & 0x8000001f;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xffffffe0) + 1;
    }
    iVar3 = (int)(uVar1 + ((int)uVar1 >> 0x1f & 0x1fU)) >> 5;
    iVar4 = uVar1 + 0x1f + iVar2;
    iVar5 = ((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) - iVar3;
    uStack_48 = 0x4200ca05;
    iVar4 = iVar5 * -4;
    if (local_44 + iVar4 != (undefined1 *)0x0) {
      *(int *)(local_44 + iVar4 + -4) = iVar5 * 4;
      auStack_5c[4 - iVar5] = 0xffffffff;
      auStack_5c[3 - iVar5] = (uint)(local_44 + iVar4);
      auStack_5c[2 - iVar5] = 0x4200ca1d;
      FUN_420698e0((uint *)auStack_5c[3 - iVar5],(byte)auStack_5c[4 - iVar5],
                   *(uint *)(local_44 + iVar4 + -4));
      *(int *)(local_44 + iVar4 + -4) = iVar2;
      auStack_5c[4 - iVar5] = uVar6;
      auStack_5c[3 - iVar5] = (uint)(local_44 + iVar4);
      auStack_5c[2 - iVar5] = param_2;
      auStack_5c[1 - iVar5] = param_1;
      auStack_5c[-iVar5] = 0x4200ca32;
      FUN_4200b1e7(this,auStack_5c[1 - iVar5],auStack_5c[2 - iVar5],auStack_5c[3 - iVar5],
                   auStack_5c[4 - iVar5]);
      *(int *)(local_44 + iVar4 + -4) = iVar5;
      auStack_5c[4 - iVar5] = (uint)(local_44 + iVar4);
      auStack_5c[3 - iVar5] = 0x4200ca42;
      FUN_4200a198(this,(uint *)auStack_5c[4 - iVar5],*(int *)(local_44 + iVar4 + -4));
      *(int *)(local_44 + iVar4 + -4) = iVar2;
      auStack_5c[4 - iVar5] = uVar6;
      auStack_5c[3 - iVar5] = iVar3;
      auStack_5c[2 - iVar5] = (uint)(local_44 + iVar4);
      auStack_5c[1 - iVar5] = 0x4200ca53;
      FUN_4200b4a1(this,(uint *)auStack_5c[2 - iVar5],auStack_5c[3 - iVar5],auStack_5c[4 - iVar5],
                   *(uint **)(local_44 + iVar4 + -4));
    }
  }
  uStack_48 = 0x4200ca81;
  FUN_4206b878();
  return;
}


