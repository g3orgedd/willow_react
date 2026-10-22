// Source: CLCiffConversion_Layout.dll @ 45409334; FUN_45409334

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_45409334(void *this,uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar2 = (undefined4 *)_Allocate<>(param_1);
  FUN_45408822(*(undefined4 **)this,*(undefined4 **)((int)this + 4),puVar2);
  puVar1 = *(undefined4 **)((int)this + 4);
  puVar4 = *(undefined4 **)this;
  iVar3 = (int)puVar1 - (int)puVar4;
  if (puVar4 != (undefined4 *)0x0) {
    for (; puVar4 != puVar1; puVar4 = puVar4 + 1) {
      SysFreeString((BSTR)*puVar4);
    }
    FID_conflict__free(*(void **)this);
  }
  *(undefined4 **)this = puVar2;
  *(undefined4 **)((int)this + 8) = puVar2 + param_1;
  *(undefined4 **)((int)this + 4) = puVar2 + (iVar3 >> 2);
  return;
}


