// Source: CLCiffConversion_Data.dll @ 45037c73; FUN_45037c73

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

int __cdecl FUN_45037c73(FILE *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = -1;
  if (param_1 == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45027e29();
  }
  else if ((param_1->_flag & 0x40) == 0) {
    __lock_file(param_1);
    iVar2 = __fclose_nolock(param_1);
    FUN_45037ce2();
  }
  else {
    param_1->_flag = 0;
  }
  return iVar2;
}


