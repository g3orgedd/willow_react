// Source: CLARiSOFT.exe @ 00e09b75; FUN_00e09b75

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_00e09b75(void *this,int *param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  uVar1 = FUN_00e0d154();
  *(undefined4 *)this = uVar1;
  local_18 = local_18 & 0xffffff00;
  FUN_00e082fa(this,param_1,local_18);
  return this;
}


