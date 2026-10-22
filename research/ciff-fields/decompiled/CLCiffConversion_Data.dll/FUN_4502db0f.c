// Source: CLCiffConversion_Data.dll @ 4502db0f; FUN_4502db0f

void FUN_4502db0f(void)

{
  int iVar1;
  PVOID _Memory;
  int *piVar2;
  
  _Memory = DecodePointer(DAT_45056f90);
  for (piVar2 = DAT_450553b8; (piVar2 != (int *)0x0 && (*piVar2 != 0)); piVar2 = piVar2 + 1) {
    FID_conflict__free((void *)*piVar2);
  }
  FID_conflict__free(DAT_450553b8);
  DAT_450553b8 = (int *)0x0;
  for (piVar2 = DAT_450553b4; (piVar2 != (int *)0x0 && (*piVar2 != 0)); piVar2 = piVar2 + 1) {
    FID_conflict__free((void *)*piVar2);
  }
  FID_conflict__free(DAT_450553b4);
  DAT_450553b4 = (int *)0x0;
  FID_conflict__free(DAT_450553b0);
  FID_conflict__free(DAT_450553ac);
  DAT_450553b0 = (void *)0x0;
  DAT_450553ac = (void *)0x0;
  if ((_Memory != (PVOID)0xffffffff) && (DAT_45056f90 != (PVOID)0x0)) {
    FID_conflict__free(_Memory);
  }
  DAT_45056f90 = EncodePointer((PVOID)0xffffffff);
  if (DAT_45055ea4 != (void *)0x0) {
    FID_conflict__free(DAT_45055ea4);
    DAT_45055ea4 = (void *)0x0;
  }
  if (DAT_45055ea8 != (void *)0x0) {
    FID_conflict__free(DAT_45055ea8);
    DAT_45055ea8 = (void *)0x0;
  }
  LOCK();
  iVar1 = *(int *)PTR_DAT_45051d2c;
  *(int *)PTR_DAT_45051d2c = *(int *)PTR_DAT_45051d2c + -1;
  UNLOCK();
  if ((iVar1 == 1) && ((undefined4 *)PTR_DAT_45051d2c != &DAT_45051b08)) {
    FID_conflict__free(PTR_DAT_45051d2c);
    PTR_DAT_45051d2c = (undefined *)&DAT_45051b08;
  }
  return;
}


