// Source: CiffMgr.dll @ 68108af8; FUN_68108af8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 * __cdecl FUN_68108af8(undefined4 *param_1,undefined4 *param_2,BSTR param_3)

{
  bool bVar1;
  undefined1 *puVar2;
  
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    bVar1 = FUN_68108d47(&param_3,*param_1,param_1[1],(undefined4 *)param_1[2]);
    if (bVar1) break;
  }
  puVar2 = &stack0xffffffd8;
  SysFreeString(param_3);
  *(undefined4 *)(puVar2 + -4) = 0x68108b3c;
  return param_1;
}


