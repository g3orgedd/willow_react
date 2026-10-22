// Source: CiffMgr.dll @ 6812ee95; FUN_6812ee95

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_6812ee95(wchar_t *param_1)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uStackY_20;
  int aiStackY_1c [3];
  
  uVar2 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  if (param_1 != (wchar_t *)0x0) {
    aiStackY_1c[2] = 0x6812eeb6;
    sVar3 = _wcslen(param_1);
    iVar4 = sVar3 + 1;
    if (iVar4 < 0x40000000) {
      iVar1 = iVar4 * -2;
      *(undefined4 *)(&stack0xfffffff0 + iVar1) = 3;
      *(int *)((int)aiStackY_1c + iVar1 + 8) = iVar4 * 2;
      *(wchar_t **)((int)aiStackY_1c + iVar1 + 4) = param_1;
      *(undefined1 **)((int)aiStackY_1c + iVar1) = &stack0xfffffff4 + iVar1;
      *(undefined4 *)((int)&uStackY_20 + iVar1) = 0x6812eedb;
      pbVar5 = (byte *)AtlW2AHelper(*(char **)((int)aiStackY_1c + iVar1),
                                    *(wchar_t **)((int)aiStackY_1c + iVar1 + 4),
                                    *(int *)((int)aiStackY_1c + iVar1 + 8),
                                    *(uint *)(&stack0xfffffff0 + iVar1));
    }
    else {
      pbVar5 = (byte *)0x0;
    }
    aiStackY_1c[2] = 0x6812eee1;
    FUN_68135225(pbVar5);
  }
  FUN_68132051(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}


