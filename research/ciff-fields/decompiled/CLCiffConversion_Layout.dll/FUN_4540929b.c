// Source: CLCiffConversion_Layout.dll @ 4540929b; FUN_4540929b

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4540929b(void *this,uint param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  
  pvVar2 = (void *)_Allocate<>(param_1);
  FUN_454087fe(*(int **)this,*(int **)((int)this + 4),pvVar2);
  puVar1 = *(undefined4 **)((int)this + 4);
  puVar4 = *(undefined4 **)this;
  iVar3 = (int)puVar1 - (int)puVar4;
  if (puVar4 != (undefined4 *)0x0) {
    for (; puVar4 != puVar1; puVar4 = puVar4 + 5) {
      SysFreeString((BSTR)*puVar4);
    }
    FID_conflict__free(*(void **)this);
  }
  *(void **)this = pvVar2;
  *(void **)((int)this + 8) = (void *)(param_1 * 0x14 + (int)pvVar2);
  *(void **)((int)this + 4) = (void *)((iVar3 / 0x14) * 0x14 + (int)pvVar2);
  return;
}


