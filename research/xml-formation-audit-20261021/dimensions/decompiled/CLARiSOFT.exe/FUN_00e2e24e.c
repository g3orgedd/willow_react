// Source: CLARiSOFT.exe @ 00e2e24e; FUN_00e2e24e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_00e2e24e(void *this,wchar_t *param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_EAX;
  undefined1 uVar3;
  int iVar4;
  int local_24;
  uint local_1c;
  undefined4 *local_18;
  wchar_t *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0xe2e25a;
  uVar3 = 0;
  iVar1 = 0;
  iVar4 = *(int *)((int)this + 0x194) - *(int *)((int)this + 400) >> 2;
  local_24 = 0;
  if (0 < iVar4) {
    do {
      uVar2 = FUN_00e68567(*(int *)(*(int *)((int)this + 400) + local_24 * 4));
      FUN_00e68547(*(void **)(*(int *)((int)this + 400) + local_24 * 4),&local_18);
      local_1c = 0;
      if (uVar2 != 0) {
        do {
          local_14[0] = (wchar_t *)0x0;
          local_8 = 0;
          (**(code **)(**(int **)(local_18[2] + 4) + 0x1c))(*(int **)(local_18[2] + 4),local_14);
          iVar1 = _wcscmp(local_14[0],param_1);
          if (iVar1 == 0) {
            uVar3 = 1;
            SysFreeString(local_14[0]);
            iVar1 = extraout_EAX;
            goto LAB_00e2e310;
          }
          local_8 = 0xffffffff;
          local_18 = (undefined4 *)*local_18;
          SysFreeString(local_14[0]);
          local_1c = local_1c + 1;
        } while (local_1c < uVar2);
      }
      iVar1 = local_24 + 1;
      local_24 = iVar1;
    } while (iVar1 < iVar4);
  }
LAB_00e2e310:
  return CONCAT31((int3)((uint)iVar1 >> 8),uVar3);
}


