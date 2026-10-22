// Source: CLARiSOFT.exe @ 00e2a511; FUN_00e2a511

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_00e2a511(int param_1)

{
  undefined4 uVar1;
  undefined1 local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0xe2a51d;
  if (*(char *)(param_1 + 0x21c) != '\0') {
    FUN_00eade22((void *)(param_1 + 0x2c),local_2c);
    local_8 = 0;
    uVar1 = FUN_00e2a15b(param_1);
    *(undefined4 *)(param_1 + 0x1e8) = uVar1;
    FUN_00e06641(local_2c,'\x01',0);
  }
  FUN_00ec9e3c();
  return;
}


