// Source: CLCiffConversion_Data.dll @ 4501484c; thunk_FUN_45014993

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall thunk_FUN_45014993(int param_1)

{
  int *piVar1;
  int iVar2;
  VARIANTARG *pvarg;
  
  FUN_45005aac(0x4503fe78);
  FUN_4500b59c(param_1);
  pvarg = (VARIANTARG *)(param_1 + 0x48);
  iVar2 = 0x19;
  do {
    VariantClear(pvarg);
    pvarg = pvarg + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_45005aac(0x4503fea4);
  SysFreeString(*(BSTR *)(param_1 + 0x4f4));
  FUN_45002256((int *)(param_1 + 0x4f0));
  FUN_4501423d((int *)(param_1 + 0x4e8));
  FID_conflict__free(*(void **)(param_1 + 0x4e8));
  _eh_vector_destructor_iterator_((void *)(param_1 + 0x38),0x30,0x19,FUN_45014a7d);
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45014972(param_1 + 0xc);
  return;
}


