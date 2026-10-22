// Source: CLCiffConversion_Layout.dll @ 4541b7e2; FUN_4541b7e2

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_4541b7e2(void *this,undefined4 *param_1)

{
  wchar_t *_Str;
  int iVar1;
  size_t sVar2;
  int iVar3;
  LPCSTR pCVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uStackY_40;
  undefined4 auStackY_3c [2];
  undefined1 local_2c [16];
  byte *local_1c;
  byte *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x4541b7ee;
  _Str = (wchar_t *)*param_1;
  if (_Str != (wchar_t *)0x0) {
    sVar2 = _wcslen(_Str);
    iVar3 = sVar2 + 1;
    if (iVar3 < 0x40000000) {
      iVar1 = iVar3 * -2;
      *(undefined4 *)((int)local_18 + iVar1 + -0x18) = 3;
      *(int *)((int)local_18 + iVar1 + -0x1c) = iVar3 * 2;
      *(wchar_t **)((int)auStackY_3c + iVar1 + 4) = _Str;
      *(undefined1 **)((int)auStackY_3c + iVar1) = local_2c;
      *(undefined4 *)((int)&uStackY_40 + iVar1) = 0x4541b822;
      pCVar4 = AtlW2AHelper(*(char **)((int)auStackY_3c + iVar1),
                            *(wchar_t **)((int)auStackY_3c + iVar1 + 4),
                            *(int *)((int)local_18 + iVar1 + -0x1c),
                            *(uint *)((int)local_18 + iVar1 + -0x18));
      goto LAB_4541b822;
    }
  }
  pCVar4 = (LPCSTR)0x0;
LAB_4541b822:
  FUN_45402a65(&local_1c,pCVar4);
  uVar6 = 0;
  local_8 = 0;
  if (*(int *)((int)this + 0x10) - *(int *)((int)this + 0xc) >> 2 != 0) {
    do {
      piVar5 = (int *)FUN_45421dcf(*(undefined4 *)(*(int *)((int)this + 0xc) + uVar6 * 4));
      FUN_45402a2f(local_18,piVar5);
      auStackY_3c[1] = 0x4541b85f;
      iVar3 = FUN_4542d0d6(local_1c,local_18[0]);
      if (iVar3 == 0) {
        FUN_45402c5d((int *)local_18);
        break;
      }
      FUN_45402c5d((int *)local_18);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)(*(int *)((int)this + 0x10) - *(int *)((int)this + 0xc) >> 2));
  }
  FUN_45402c5d((int *)&local_1c);
  FUN_4542a957();
  return;
}


