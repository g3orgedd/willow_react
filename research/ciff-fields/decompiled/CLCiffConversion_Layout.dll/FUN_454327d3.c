// Source: CLCiffConversion_Layout.dll @ 454327d3; FUN_454327d3

void __cdecl FUN_454327d3(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  LOCK();
  *param_1 = *param_1 + 1;
  UNLOCK();
  piVar3 = (int *)param_1[0x1e];
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + 1;
    UNLOCK();
  }
  piVar3 = (int *)param_1[0x20];
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + 1;
    UNLOCK();
  }
  piVar3 = (int *)param_1[0x1f];
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + 1;
    UNLOCK();
  }
  piVar3 = (int *)param_1[0x22];
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + 1;
    UNLOCK();
  }
  piVar3 = param_1 + 7;
  iVar2 = 6;
  do {
    if (((undefined *)piVar3[-2] != &DAT_4545e0fc) &&
       (piVar1 = (int *)*piVar3, piVar1 != (int *)0x0)) {
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    if ((piVar3[-3] != 0) && (piVar1 = (int *)piVar3[-1], piVar1 != (int *)0x0)) {
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    piVar3 = piVar3 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  LOCK();
  *(int *)(param_1[0x27] + 0xb0) = *(int *)(param_1[0x27] + 0xb0) + 1;
  UNLOCK();
  return;
}


