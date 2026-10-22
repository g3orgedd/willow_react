// Source: CLCiffConversion_Layout.dll @ 45421480; FUN_45421480

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_45421480(void *this,BSTR param_1)

{
  undefined4 *puVar1;
  undefined4 uStackY_28;
  
  uStackY_28 = 0x4542149f;
  FUN_45404d15((void *)((int)this + 0xe0),(int *)&param_1);
  puVar1 = &uStackY_28;
  uStackY_28 = 0x454214a8;
  SysFreeString(param_1);
  puVar1[-1] = 0x454214ad;
  return;
}


