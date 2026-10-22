// Source: CLARiSOFT.exe @ 00e56577; FUN_00e56577

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e56577(void *this,int *param_1)

{
  if (param_1 != (int *)0x0) {
    FUN_00e11de5((void *)((int)this + 4),(int *)&param_1);
    FUN_00e5630b(this);
  }
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return;
}


