// Source: CLCiffConversion_Layout.dll @ 45413006; FUN_45413006

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_45413006(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  piVar1 = (int *)(param_1 + 0x4c8);
  piVar2 = *(int **)*piVar1;
  if (piVar2 != (int *)*piVar1) {
    do {
      if ((undefined4 *)piVar2[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar2[2])(1);
      }
      piVar2[2] = 0;
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*piVar1);
  }
  FUN_454224ff(piVar1);
  puVar3 = *(undefined4 **)(param_1 + 0x4d0);
  if (puVar3 != *(undefined4 **)(param_1 + 0x4d4)) {
    do {
      piVar2 = (int *)*puVar3;
      if (piVar2 != (int *)0x0) {
        FUN_45412f6f(piVar2);
        FID_conflict__free(piVar2);
      }
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    } while (puVar3 != *(undefined4 **)(param_1 + 0x4d4));
  }
  *(undefined4 *)(param_1 + 0x4d4) = *(undefined4 *)(param_1 + 0x4d0);
  FUN_45402c5d((int *)(param_1 + 0x4e0));
  FUN_45402c5d((int *)(param_1 + 0x4dc));
  FUN_454223fd((int *)(param_1 + 0x4d0));
  FUN_454224ff(piVar1);
  FID_conflict__free((void *)*piVar1);
  _eh_vector_destructor_iterator_((void *)(param_1 + 0x48),0x30,0x18,FUN_4541316d);
  piVar1 = *(int **)(param_1 + 0x40);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x2c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45412d4f(param_1 + 0xc);
  return;
}


