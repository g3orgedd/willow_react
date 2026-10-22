// Source: CLCSTextBasedField.dll @ 424155bd; FUN_424155bd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_424155bd(void *this,int *param_1)

{
  FUN_4240388f(this,param_1);
  FUN_4240388f((void *)((int)this + 4),param_1 + 1);
  FUN_4240388f((void *)((int)this + 8),param_1 + 2);
  FUN_4240388f((void *)((int)this + 0xc),param_1 + 3);
  *(int *)((int)this + 0x10) = param_1[4];
  FUN_4240388f((void *)((int)this + 0x14),param_1 + 5);
  return this;
}


