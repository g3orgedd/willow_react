// Source: CiffMgr.dll @ 68104729; FUN_68104729

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_68104729(void *this,uint param_1)

{
  VARIANTARG *pVVar1;
  undefined2 *puVar2;
  VARIANTARG *pvarg;
  uint uVar3;
  
  puVar2 = (undefined2 *)_Allocate<>(param_1);
  FUN_68103b7f(*(VARIANTARG **)this,*(VARIANTARG **)((int)this + 4),puVar2);
  pVVar1 = *(VARIANTARG **)((int)this + 4);
  pvarg = *(VARIANTARG **)this;
  uVar3 = (int)pVVar1 - (int)pvarg;
  if (pvarg != (VARIANTARG *)0x0) {
    for (; pvarg != pVVar1; pvarg = pvarg + 1) {
      VariantClear(pvarg);
    }
    FID_conflict__free(*(void **)this);
  }
  *(undefined2 **)this = puVar2;
  *(undefined2 **)((int)this + 8) = puVar2 + param_1 * 8;
  *(uint *)((int)this + 4) = (uVar3 & 0xfffffff0) + (int)puVar2;
  return;
}


