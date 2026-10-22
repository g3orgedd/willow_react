// Source: CiffMgr.dll @ 6810c0b5; FUN_6810c0b5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6810c0b5(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  if ((param_2 == (wchar_t *)0x0) || (param_3 == (wchar_t *)0x0)) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    bVar1 = FUN_6810bf60((void *)(param_1 + 4),param_2,param_3);
    iVar2 = (-(uint)(CONCAT31(extraout_var,bVar1) != 0) & 0x7ff8fff2) + 0x8007000e;
  }
  return iVar2;
}


