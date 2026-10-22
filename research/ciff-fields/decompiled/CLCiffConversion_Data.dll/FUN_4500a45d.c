// Source: CLCiffConversion_Data.dll @ 4500a45d; FUN_4500a45d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_4500a45d(void *this,undefined8 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_45007936(this);
  *(undefined2 *)(puVar1 + 3) = 0;
  if (puVar1 + 4 != (undefined4 *)0x0) {
    FUN_4500aa5d(puVar1 + 4,param_1);
  }
  return puVar1;
}


