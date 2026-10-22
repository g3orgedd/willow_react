// Source: CLCiffConversion_Layout.dll @ 454285d0; FUN_454285d0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_454285d0(void *this,uint param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
            undefined4 param_5,undefined4 param_6,undefined1 param_7)

{
  BSTR pOVar1;
  int iVar2;
  VARIANTARG *pvarg;
  
  iVar2 = (param_1 & 0xffff) * 0x30;
  *(uint *)(iVar2 + 0x50 + (int)this) = param_1;
  FUN_454077ad((void *)((int)this + iVar2 + 0x54),&param_2);
  pvarg = (VARIANTARG *)((int)this + iVar2 + 0x58);
  VariantInit(pvarg);
  (pvarg->n1).n2.vt = 8;
  pOVar1 = FUN_45428782(&param_3);
  *(BSTR *)(((param_1 & 0xffff) + 2) * 0x30 + (int)this) = pOVar1;
  *(undefined1 *)(iVar2 + 0x68 + (int)this) = param_4;
  *(undefined4 *)(iVar2 + 0x6c + (int)this) = param_5;
  *(undefined4 *)(iVar2 + 0x70 + (int)this) = param_6;
  *(undefined1 *)(iVar2 + 0x74 + (int)this) = param_7;
  *(undefined1 *)(iVar2 + 0x75 + (int)this) = 1;
  FUN_45402c5d(&param_2);
  FUN_45402c5d(&param_3);
  return;
}


