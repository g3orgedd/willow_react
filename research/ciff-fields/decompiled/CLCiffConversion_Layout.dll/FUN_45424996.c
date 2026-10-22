// Source: CLCiffConversion_Layout.dll @ 45424996; FUN_45424996

int FUN_45424996(int *param_1,LPCRITICAL_SECTION param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  PVOID pvVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  piVar2 = param_4;
  piVar1 = param_1;
  if (param_4 == (int *)0x0) {
    iVar4 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    if (param_1 == (int *)0x0) {
      iVar4 = -0x7ff8ffa9;
    }
    else if (*param_1 == 0) {
      iVar4 = -0x7fff0001;
    }
    else {
      for (piVar7 = (int *)param_1[2]; piVar7 < (int *)piVar1[3]; piVar7 = piVar7 + 1) {
        param_4 = (int *)*piVar7;
        if (((param_4 != (int *)0x0) && (param_4[2] != 0)) &&
           (iVar4 = _InlineIsEqualGUID((int *)param_2,(int *)*param_4), piVar3 = param_4, iVar4 != 0
           )) {
          param_4 = (int *)param_4[4];
          pvVar5 = (PVOID)*param_4;
          if (pvVar5 == (PVOID)0x0) {
            param_2 = (LPCRITICAL_SECTION)(piVar1 + 4);
            EnterCriticalSection(param_2);
            iVar4 = 0;
            if (*param_4 == 0) {
              param_1 = (int *)0x0;
              iVar4 = (*(code *)piVar3[2])(piVar3[3],&DAT_4544768c,&param_1);
              if (-1 < iVar4) {
                pvVar5 = EncodePointer(param_1);
                *param_4 = (int)pvVar5;
              }
            }
            piVar1 = param_4;
            LeaveCriticalSection(param_2);
            pvVar5 = (PVOID)*piVar1;
            if (pvVar5 != (PVOID)0x0) goto LAB_45424a5d;
          }
          else {
LAB_45424a5d:
            puVar6 = DecodePointer(pvVar5);
            iVar4 = (**(code **)*puVar6)(puVar6,param_3,piVar2);
          }
          if (*piVar2 != 0) {
            return iVar4;
          }
          if (iVar4 != 0) {
            return iVar4;
          }
          break;
        }
      }
      iVar4 = -0x7ffbfeef;
    }
  }
  return iVar4;
}


