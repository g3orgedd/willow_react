// Source: CiffMgr.dll @ 6810f3fa; FUN_6810f3fa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void * __thiscall FUN_6810f3fa(void *this,BSTR param_1)

{
  undefined4 *puVar1;
  undefined4 uStackY_28;
  
  uStackY_28 = 0x6810f415;
  FUN_6810794a(this,(int *)&param_1);
  puVar1 = &uStackY_28;
  uStackY_28 = 0x6810f41e;
  SysFreeString(param_1);
  puVar1[-1] = 0x6810f425;
  return this;
}


