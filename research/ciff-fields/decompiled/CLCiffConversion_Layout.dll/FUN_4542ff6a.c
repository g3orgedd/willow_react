// Source: CLCiffConversion_Layout.dll @ 4542ff6a; FUN_4542ff6a

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

void FUN_4542ff6a(void *param_1)

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
    if (*(undefined **)((int)param_1 + 0x5c) != &DAT_45450e20) {
      FID_conflict__free(*(void **)((int)param_1 + 0x5c));
    }
    __lock(0xd);
    piVar2 = *(int **)((int)param_1 + 0x68);
    if (piVar2 != (int *)0x0) {
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = iVar1 + -1;
      UNLOCK();
      if ((iVar1 + -1 == 0) && (piVar2 != &DAT_4545dde0)) {
        FID_conflict__free(piVar2);
      }
    }
    FUN_4543008a();
    __lock(0xc);
    piVar2 = *(int **)((int)param_1 + 0x6c);
    if (piVar2 != (int *)0x0) {
      FUN_454329c2(piVar2);
      if (((piVar2 != (int *)PTR_DAT_4545e264) && (piVar2 != (int *)&DAT_4545e268)) &&
         (*piVar2 == 0)) {
        FUN_45432868(piVar2);
      }
    }
    FUN_45430096();
    FID_conflict__free(param_1);
  }
  return;
}


