// Source: CLCiffConversion_Data.dll @ 45026f3b; FUN_45026f3b

int * __cdecl FUN_45026f3b(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    LOCK();
    *param_1 = *param_1 + -1;
    UNLOCK();
    piVar2 = (int *)param_1[0x1e];
    if (piVar2 != (int *)0x0) {
      LOCK();
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    piVar2 = (int *)param_1[0x20];
    if (piVar2 != (int *)0x0) {
      LOCK();
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    piVar2 = (int *)param_1[0x1f];
    if (piVar2 != (int *)0x0) {
      LOCK();
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    piVar2 = (int *)param_1[0x22];
    if (piVar2 != (int *)0x0) {
      LOCK();
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    piVar2 = param_1 + 7;
    iVar3 = 6;
    do {
      if (((undefined *)piVar2[-2] != &DAT_45051e28) &&
         (piVar1 = (int *)*piVar2, piVar1 != (int *)0x0)) {
        LOCK();
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if ((piVar2[-3] != 0) && (piVar1 = (int *)piVar2[-1], piVar1 != (int *)0x0)) {
        LOCK();
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      piVar2 = piVar2 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    LOCK();
    *(int *)(param_1[0x27] + 0xb0) = *(int *)(param_1[0x27] + 0xb0) + -1;
    UNLOCK();
  }
  return param_1;
}


