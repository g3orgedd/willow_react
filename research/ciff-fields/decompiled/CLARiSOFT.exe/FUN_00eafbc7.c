// Source: CLARiSOFT.exe @ 00eafbc7; FUN_00eafbc7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00eafbc7(void *this,CComBSTR *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  CComBSTR *pCVar3;
  
  piVar1 = param_2;
  uVar2 = FUN_00eb6b0d(this,param_1,param_2);
  if ((char)uVar2 == '\0') {
    pCVar3 = (CComBSTR *)FUN_00eca369(8);
    param_2 = (int *)pCVar3;
    if (pCVar3 == (CComBSTR *)0x0) {
      param_1 = (CComBSTR *)0x0;
    }
    else {
      *(int **)pCVar3 = piVar1;
      FUN_00e03ab8(pCVar3 + 4,(int *)param_1);
      param_1 = pCVar3;
    }
    FUN_00e4aee3((undefined4 *)((int)this + 4),*(int **)((int)this + 4),&param_1);
  }
  return;
}


