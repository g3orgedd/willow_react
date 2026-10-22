// Source: CLCiffConversion_Data.dll @ 45018b7b; FUN_45018b7b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_45018b7b(void *this,uint param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
            undefined4 param_5,undefined4 param_6,undefined1 param_7)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xffff) * 0x30;
  *(uint *)(iVar1 + 0x40 + (int)this) = param_1;
  FUN_45008a06((void *)((int)this + iVar1 + 0x44),&param_2);
  *(undefined2 *)(iVar1 + 0x48 + (int)this) = 3;
  *(undefined4 *)(iVar1 + 0x50 + (int)this) = param_3;
  *(undefined1 *)(iVar1 + 0x58 + (int)this) = param_4;
  *(undefined4 *)(iVar1 + 0x5c + (int)this) = param_5;
  *(undefined4 *)(((param_1 & 0xffff) + 2) * 0x30 + (int)this) = param_6;
  *(undefined1 *)(iVar1 + 100 + (int)this) = param_7;
  *(undefined1 *)(iVar1 + 0x65 + (int)this) = 1;
  FUN_45002256(&param_2);
  return;
}


