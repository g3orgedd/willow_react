// Source: CLARiSOFT.exe @ 00e67d5d; FUN_00e67d5d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int __thiscall FUN_00e67d5d(void *this,BSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStackY_28;
  
  uStackY_28 = 0xe67d7b;
  FUN_00e01fd0((void *)((int)this + 0x3c),(int *)&param_1);
  iVar1 = FUN_00e66867(this);
  puVar2 = &uStackY_28;
  uStackY_28 = 0xe67d8d;
  SysFreeString(param_1);
  puVar2[-1] = 0xe67d94;
  return iVar1;
}


