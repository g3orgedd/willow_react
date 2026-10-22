// Source: CLCiffConversion_Data.dll @ 450277ec; FUN_450277ec

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void FUN_450277ec(void *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != (void *)0x0) {
    if (*(int *)((int)param_1 + 0x24) != 0) {
      FID_conflict__free(*(void **)((int)param_1 + 0x24));
    }
    if (*(int *)((int)param_1 + 0x2c) != 0) {
      FID_conflict__free(*(void **)((int)param_1 + 0x2c));
    }
    if (*(int *)((int)param_1 + 0x34) != 0) {
      FID_conflict__free(*(void **)((int)param_1 + 0x34));
    }
    if (*(int *)((int)param_1 + 0x3c) != 0) {
      FID_conflict__free(*(void **)((int)param_1 + 0x3c));
    }
    if (*(int *)((int)param_1 + 0x40) != 0) {
      FID_conflict__free(*(void **)((int)param_1 + 0x40));
    }
    if (*(int *)((int)param_1 + 0x44) != 0) {
      FID_conflict__free(*(void **)((int)param_1 + 0x44));
    }
    if (*(int *)((int)param_1 + 0x48) != 0) {
      FID_conflict__free(*(void **)((int)param_1 + 0x48));
    }
    if (*(undefined **)((int)param_1 + 0x5c) != &DAT_450474f8) {
      FID_conflict__free(*(void **)((int)param_1 + 0x5c));
    }
    __lock(0xd);
    piVar2 = *(int **)((int)param_1 + 0x68);
    if (piVar2 != (int *)0x0) {
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = iVar1 + -1;
      UNLOCK();
      if ((iVar1 + -1 == 0) && (piVar2 != &DAT_45051b08)) {
        FID_conflict__free(piVar2);
      }
    }
    FUN_4502790c();
    __lock(0xc);
    piVar2 = *(int **)((int)param_1 + 0x6c);
    if (piVar2 != (int *)0x0) {
      FUN_45026f3b(piVar2);
      if (((piVar2 != (int *)PTR_DAT_45051f94) && (piVar2 != (int *)&DAT_45051f98)) &&
         (*piVar2 == 0)) {
        FUN_45026de1(piVar2);
      }
    }
    FUN_45027918();
    FID_conflict__free(param_1);
  }
  return;
}


