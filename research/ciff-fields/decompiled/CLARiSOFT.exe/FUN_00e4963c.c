// Source: CLARiSOFT.exe @ 00e4963c; FUN_00e4963c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_00e4963c(void *this,OLECHAR *param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_00e050e5(param_2,param_1);
  if (iVar1 == 0) {
    uVar2 = 0x80004005;
  }
  else {
    FUN_00e11de5((void *)((int)this + 0x1c),(int *)(iVar1 + 0x30));
  }
  SysFreeString(param_1);
  return uVar2;
}


