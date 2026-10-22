// Source: CiffMgr.dll @ 6810551c; FUN_6810551c

undefined4 FUN_6810551c(int param_1,VARTYPE param_2,undefined4 param_3,int param_4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  undefined4 *puVar2;
  VARIANTARG *pVVar3;
  undefined4 local_8;
  
  iVar1 = param_1;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xf8);
  EnterCriticalSection(lpCriticalSection);
  pVVar3 = *(VARIANTARG **)(param_1 + 4);
  if (pVVar3 != *(VARIANTARG **)(param_1 + 8)) {
    param_1._3_1_ = (char)((uint)lpCriticalSection >> 0x18);
    do {
      if (param_2 == (pVVar3->n1).n2.vt) {
        param_1._3_1_ = '\0';
        if (param_2 == 9) {
          if (*(int *)((int)&pVVar3->n1 + 8) == param_4) {
            param_1._3_1_ = '\x01';
            goto LAB_6810556c;
          }
        }
        else {
          param_1._3_1_ = '\0';
          if ((param_2 == 0xd) && (*(int *)((int)&pVVar3->n1 + 8) == param_4)) {
            param_1._3_1_ = '\x01';
            goto LAB_68105570;
          }
        }
LAB_68105588:
        pVVar3 = pVVar3 + 1;
      }
      else {
LAB_6810556c:
        if (param_1._3_1_ == '\0') goto LAB_68105588;
LAB_68105570:
        puVar2 = (undefined4 *)FUN_68104800((void *)(iVar1 + 4),&local_8,pVVar3);
        pVVar3 = (VARIANTARG *)*puVar2;
      }
    } while (pVVar3 != *(VARIANTARG **)(iVar1 + 8));
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


