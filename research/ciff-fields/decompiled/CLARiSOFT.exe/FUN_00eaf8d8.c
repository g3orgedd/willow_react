// Source: CLARiSOFT.exe @ 00eaf8d8; FUN_00eaf8d8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_00eaf8d8(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  LCID LVar4;
  
  *param_1 = CCiffChecker::vftable;
  piVar1 = param_1 + 6;
  *piVar1 = 0;
  param_1[7] = 0;
  iVar2 = FUN_00e461da((int *)0x0,(int *)0x0);
  *piVar1 = iVar2;
  param_1[8] = 0;
  puVar3 = (undefined4 *)FUN_00eca369(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = FUN_00e4b2e4(puVar3);
  }
  param_1[3] = puVar3;
  puVar3 = (undefined4 *)FUN_00eca369(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = FUN_00eaf85b(puVar3);
  }
  param_1[4] = puVar3;
  FUN_00eb7275((int)param_1);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  LVar4 = GetSystemDefaultLCID();
  FUN_00eb70d6(piVar1,0xc00000,LVar4);
  return param_1;
}


