// Source: CLCiffConversion_Layout.dll @ 4540629a; FUN_4540629a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_4540629a(void *this,undefined4 *param_1,rsize_t param_2)

{
  if ((int)param_2 < 0) {
    param_2 = 0;
  }
  else if (*(int *)(*(int *)this + -8) < (int)param_2) {
    param_2 = *(rsize_t *)(*(int *)this + -8);
  }
  *param_1 = PTR_DAT_4545d110;
  FUN_45404e1b(this,param_1,param_2,0,0);
  return param_1;
}


