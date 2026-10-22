// Source: CLCiffConversion_Data.dll @ 45018cf8; FUN_45018cf8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_45018cf8(void *this,uint param_1)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xffff) * 0x30;
  *(uint *)(iVar1 + 0x40 + (int)this) = param_1;
  FUN_45008a06((void *)((int)this + iVar1 + 0x44),(int *)&stack0x00000008);
  *(undefined4 *)(iVar1 + 0x50 + (int)this) = 0;
  *(undefined2 *)(iVar1 + 0x48 + (int)this) = 9;
  *(undefined1 *)(iVar1 + 0x58 + (int)this) = 0;
  *(undefined4 *)(iVar1 + 0x5c + (int)this) = 0xffffffff;
  *(undefined4 *)(((param_1 & 0xffff) + 2) * 0x30 + (int)this) = 0xffffffff;
  *(undefined2 *)(iVar1 + 100 + (int)this) = 0x100;
  *(undefined4 *)(iVar1 + 0x50 + (int)this) = 0;
  FUN_45002256((int *)&stack0x00000008);
  return;
}


