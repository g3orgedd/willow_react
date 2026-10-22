// Source: CLCiffConversion_Data.dll @ 45018ae9; FUN_45018ae9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall
FUN_45018ae9(void *this,uint param_1,undefined4 param_2,OLECHAR *param_3,undefined1 param_4,
            undefined4 param_5,undefined4 param_6,undefined1 param_7)

{
  BSTR pOVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uStackY_2c;
  
  iVar3 = (param_1 & 0xffff) * 0x30;
  *(uint *)(iVar3 + 0x40 + (int)this) = param_1;
  FUN_45008a06((void *)((int)this + iVar3 + 0x44),&param_2);
  *(undefined4 *)(iVar3 + 0x50 + (int)this) = 0;
  *(undefined2 *)(iVar3 + 0x48 + (int)this) = 8;
  puVar2 = &uStackY_2c;
  uStackY_2c = 0x45018b39;
  pOVar1 = SysAllocStringLen(param_3,*(UINT *)(param_3 + -4));
  *(BSTR *)(iVar3 + 0x50 + (int)this) = pOVar1;
  *(undefined1 *)(iVar3 + 0x58 + (int)this) = param_4;
  *(undefined4 *)(iVar3 + 0x5c + (int)this) = param_5;
  *(undefined4 *)(((param_1 & 0xffff) + 2) * 0x30 + (int)this) = param_6;
  *(undefined1 *)(iVar3 + 100 + (int)this) = param_7;
  *(undefined1 *)(iVar3 + 0x65 + (int)this) = 1;
  puVar2[-1] = 0x45018b6b;
  FUN_45002256(&param_2);
  puVar2[-1] = 0x45018b73;
  FUN_45002256((int *)&param_3);
  puVar2[-1] = 0x45018b78;
  return;
}


