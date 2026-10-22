// Source: CiffMgr.dll @ 68109ad9; FUN_68109ad9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 * __cdecl FUN_68109ad9(undefined4 *param_1,undefined4 *param_2,BSTR param_3)

{
  bool bVar1;
  undefined1 *puVar2;
  
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    bVar1 = FUN_68109bf9(&param_3,*param_1,param_1[1],(undefined4 *)param_1[2]);
    if (bVar1) break;
  }
  puVar2 = &stack0xffffffd8;
  SysFreeString(param_3);
  *(undefined4 *)(puVar2 + -4) = 0x68109b1d;
  return param_1;
}


