// Source: CLARiSOFT.exe @ 00eb7275; FUN_00eb7275

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_00eb7275(int param_1)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  puVar2 = &LAB_00ef8fb8;
  local_8 = 0xeb7281;
  if (DAT_00f371d8 != 0) {
    puVar4 = &DAT_00f371f0;
    do {
      local_14[0] = (int *)FUN_00eca369(0x20);
      local_8 = 0;
      if (local_14[0] == (int *)0x0) {
        local_14[0] = (int *)0x0;
      }
      else {
        local_14[0] = FUN_00e4b21c(local_14[0],puVar4[-6],puVar4[-4],puVar4[-3],puVar4[-5],
                                   puVar4[-2],puVar4[-1],*puVar4,puVar4[1]);
      }
      local_8 = 0xffffffff;
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0xc) + 4);
      puVar2 = (undefined1 *)FUN_00e4aee3(puVar3,(int *)*puVar3,local_14);
      puVar1 = puVar4 + 2;
      puVar4 = puVar4 + 8;
    } while (*puVar1 != 0);
  }
  if (DAT_00f37398 != 0) {
    puVar4 = &DAT_00f373b0;
    do {
      local_14[0] = (int *)FUN_00eca369(0x20);
      local_8 = 1;
      if (local_14[0] == (int *)0x0) {
        local_14[0] = (int *)0x0;
      }
      else {
        local_14[0] = FUN_00e4b21c(local_14[0],puVar4[-6],puVar4[-4],puVar4[-3],puVar4[-5],
                                   puVar4[-2],puVar4[-1],*puVar4,puVar4[1]);
      }
      local_8 = 0xffffffff;
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0xc) + 4);
      puVar2 = (undefined1 *)FUN_00e4aee3(puVar3,(int *)*puVar3,local_14);
      puVar1 = puVar4 + 2;
      puVar4 = puVar4 + 8;
    } while (*puVar1 != 0);
  }
  return puVar2;
}


