// Source: CLCiffConversion_Data.dll @ 450136b5; FUN_450136b5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_450136b5(void *this,BSTR param_1)

{
  undefined4 *puVar1;
  undefined4 uStackY_28;
  
  uStackY_28 = 0x450136d4;
  FUN_450022ea((void *)((int)this + 0xe0),(int *)&param_1);
  puVar1 = &uStackY_28;
  uStackY_28 = 0x450136dd;
  SysFreeString(param_1);
  puVar1[-1] = 0x450136e2;
  return;
}


