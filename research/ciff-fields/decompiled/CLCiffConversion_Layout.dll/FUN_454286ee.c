// Source: CLCiffConversion_Layout.dll @ 454286ee; FUN_454286ee

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_454286ee(void *this,uint param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
            undefined4 param_5,undefined4 param_6,undefined1 param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  VARIANTARG *pvarg;
  
  iVar3 = (param_1 & 0xffff) * 0x30;
  *(uint *)(iVar3 + 0x50 + (int)this) = param_1;
  FUN_454077ad((void *)((int)this + iVar3 + 0x54),&param_2);
  pvarg = (VARIANTARG *)((int)this + iVar3 + 0x58);
  VariantInit(pvarg);
  (pvarg->n1).n2.vt = 0xd;
  iVar2 = ((param_1 & 0xffff) + 2) * 0x30;
  *(undefined4 *)(iVar2 + (int)this) = param_3;
  *(undefined1 *)(iVar3 + 0x68 + (int)this) = param_4;
  *(undefined4 *)(iVar3 + 0x6c + (int)this) = param_5;
  *(undefined4 *)(iVar3 + 0x70 + (int)this) = param_6;
  *(undefined1 *)(iVar3 + 0x74 + (int)this) = param_7;
  *(undefined1 *)(iVar3 + 0x75 + (int)this) = 1;
  piVar1 = *(int **)(iVar2 + (int)this);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  FUN_45402c5d(&param_2);
  return;
}


