// Source: CLCiffConversion_Layout.dll @ 45432080; FUN_45432080

void FUN_45432080(void)

{
  int iVar1;
  PVOID _Memory;
  int *piVar2;
  
  _Memory = DecodePointer(DAT_4546278c);
  for (piVar2 = DAT_45460bb4; (piVar2 != (int *)0x0 && (*piVar2 != 0)); piVar2 = piVar2 + 1) {
    FID_conflict__free((void *)*piVar2);
  }
  FID_conflict__free(DAT_45460bb4);
  DAT_45460bb4 = (int *)0x0;
  for (piVar2 = DAT_45460bb0; (piVar2 != (int *)0x0 && (*piVar2 != 0)); piVar2 = piVar2 + 1) {
    FID_conflict__free((void *)*piVar2);
  }
  FID_conflict__free(DAT_45460bb0);
  DAT_45460bb0 = (int *)0x0;
  FID_conflict__free(DAT_45460bac);
  FID_conflict__free(DAT_45460ba8);
  DAT_45460bac = (void *)0x0;
  DAT_45460ba8 = (void *)0x0;
  if ((_Memory != (PVOID)0xffffffff) && (DAT_4546278c != (PVOID)0x0)) {
    FID_conflict__free(_Memory);
  }
  DAT_4546278c = EncodePointer((PVOID)0xffffffff);
  if (DAT_454616a8 != (void *)0x0) {
    FID_conflict__free(DAT_454616a8);
    DAT_454616a8 = (void *)0x0;
  }
  if (DAT_454616ac != (void *)0x0) {
    FID_conflict__free(DAT_454616ac);
    DAT_454616ac = (void *)0x0;
  }
  LOCK();
  iVar1 = *(int *)PTR_DAT_4545e004;
  *(int *)PTR_DAT_4545e004 = *(int *)PTR_DAT_4545e004 + -1;
  UNLOCK();
  if ((iVar1 == 1) && ((undefined4 *)PTR_DAT_4545e004 != &DAT_4545dde0)) {
    FID_conflict__free(PTR_DAT_4545e004);
    PTR_DAT_4545e004 = (undefined *)&DAT_4545dde0;
  }
  return;
}


