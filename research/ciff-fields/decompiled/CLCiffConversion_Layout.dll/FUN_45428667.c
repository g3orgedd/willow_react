// Source: CLCiffConversion_Layout.dll @ 45428667; FUN_45428667

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_45428667(void *this,uint param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
            undefined4 param_5,undefined4 param_6,undefined1 param_7)

{
  int iVar1;
  VARIANTARG *pvarg;
  
  iVar1 = (param_1 & 0xffff) * 0x30;
  *(uint *)(iVar1 + 0x50 + (int)this) = param_1;
  FUN_454077ad((void *)((int)this + iVar1 + 0x54),&param_2);
  pvarg = (VARIANTARG *)((int)this + iVar1 + 0x58);
  VariantInit(pvarg);
  (pvarg->n1).n2.vt = 3;
  *(undefined4 *)(((param_1 & 0xffff) + 2) * 0x30 + (int)this) = param_3;
  *(undefined1 *)(iVar1 + 0x68 + (int)this) = param_4;
  *(undefined4 *)(iVar1 + 0x6c + (int)this) = param_5;
  *(undefined4 *)(iVar1 + 0x70 + (int)this) = param_6;
  *(undefined1 *)(iVar1 + 0x74 + (int)this) = param_7;
  *(undefined1 *)(iVar1 + 0x75 + (int)this) = 1;
  FUN_45402c5d(&param_2);
  return;
}


