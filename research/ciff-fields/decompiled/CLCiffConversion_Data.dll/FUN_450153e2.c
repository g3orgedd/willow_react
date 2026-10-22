// Source: CLCiffConversion_Data.dll @ 450153e2; FUN_450153e2

int FUN_450153e2(int *param_1,LPCRITICAL_SECTION param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  PVOID pvVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  piVar1 = param_4;
  if (param_4 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    if (*param_1 == 0) {
      iVar2 = -0x7fff0001;
    }
    else {
      piVar3 = (int *)param_1[3];
      param_4 = piVar3;
      for (piVar6 = (int *)param_1[2]; piVar6 < piVar3; piVar6 = piVar6 + 1) {
        puVar5 = (undefined4 *)*piVar6;
        if (((puVar5 != (undefined4 *)0x0) && (puVar5[2] != 0)) &&
           (iVar2 = FUN_45018a9f((int *)param_2,(int *)*puVar5), piVar3 = param_4, iVar2 != 0)) {
          param_4 = (int *)puVar5[4];
          pvVar4 = (PVOID)*param_4;
          if (pvVar4 == (PVOID)0x0) {
            param_2 = (LPCRITICAL_SECTION)(param_1 + 4);
            EnterCriticalSection(param_2);
            iVar2 = 0;
            if (*param_4 == 0) {
              param_1 = (int *)0x0;
              iVar2 = (*(code *)puVar5[2])(puVar5[3],&DAT_4503d450,&param_1);
              if (-1 < iVar2) {
                pvVar4 = EncodePointer(param_1);
                *param_4 = (int)pvVar4;
              }
            }
            piVar6 = param_4;
            LeaveCriticalSection(param_2);
            pvVar4 = (PVOID)*piVar6;
            if (pvVar4 != (PVOID)0x0) goto LAB_450154a0;
          }
          else {
LAB_450154a0:
            puVar5 = DecodePointer(pvVar4);
            iVar2 = (**(code **)*puVar5)(puVar5,param_3,piVar1);
          }
          if (*piVar1 != 0) {
            return iVar2;
          }
          if (iVar2 != 0) {
            return iVar2;
          }
          break;
        }
      }
      iVar2 = -0x7ffbfeef;
    }
  }
  return iVar2;
}


