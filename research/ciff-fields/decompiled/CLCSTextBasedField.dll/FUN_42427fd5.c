// Source: CLCSTextBasedField.dll @ 42427fd5; FUN_42427fd5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __thiscall FUN_42427fd5(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_2c [2];
  wchar_t *local_24;
  int local_18;
  undefined1 *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  puVar2 = &LAB_4248d39d;
  local_8 = 0x42427fe1;
  if ((*(int *)this != 0) && (*(int *)this != 0x409)) {
    iVar6 = 0;
    puVar2 = *(undefined1 **)((int)this + 8);
    puVar5 = (undefined4 *)**(undefined4 **)((int)this + 4);
    local_14 = puVar2;
    if (0 < (int)puVar2) {
      do {
        puVar1 = (undefined4 *)*puVar5;
        FUN_424155bd(local_2c,puVar5 + 2);
        local_8 = 0;
        if (((0 < *(int *)(local_24 + -4)) &&
            (iVar3 = _wcscmp(local_24,(wchar_t *)*param_1), iVar3 == 0)) &&
           (0 < *(int *)(local_18 + -8))) {
          FUN_42407350(param_1,&local_18);
          uVar4 = FUN_4241694e(local_2c);
          return CONCAT31((int3)((uint)uVar4 >> 8),1);
        }
        local_8 = 0xffffffff;
        puVar2 = (undefined1 *)FUN_4241694e(local_2c);
        iVar6 = iVar6 + 1;
        puVar5 = puVar1;
      } while (iVar6 < (int)local_14);
    }
  }
  return (uint)puVar2 & 0xffffff00;
}


