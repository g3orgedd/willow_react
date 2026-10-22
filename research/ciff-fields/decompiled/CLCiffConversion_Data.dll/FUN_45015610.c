// Source: CLCiffConversion_Data.dll @ 45015610; FUN_45015610

int FUN_45015610(int param_1,int *param_2,_GUID *param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_4 == (undefined4 *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    iVar3 = ATL::InlineIsEqualUnknown(param_3);
    if (iVar3 == 0) {
      for (; pcVar1 = (code *)param_2[2], pcVar1 != (code *)0x0; param_2 = param_2 + 3) {
        iVar3 = *param_2;
        if ((iVar3 == 0) || (iVar2 = FUN_45018a9f((int *)*param_2,(int *)param_3), iVar2 != 0)) {
          if (pcVar1 == (code *)0x1) {
            piVar4 = (int *)(param_2[1] + param_1);
            (**(code **)(*piVar4 + 4))(piVar4);
            *param_4 = piVar4;
            return 0;
          }
          iVar2 = (*pcVar1)(param_1,param_3,param_4,param_2[1]);
          if (iVar2 == 0) {
            return 0;
          }
          if ((iVar3 != 0) && (iVar2 < 0)) goto LAB_45015696;
        }
      }
      iVar2 = -0x7fffbffe;
LAB_45015696:
      *param_4 = 0;
    }
    else {
      piVar4 = (int *)(param_2[1] + param_1);
      (**(code **)(*piVar4 + 4))(piVar4);
      *param_4 = piVar4;
      iVar2 = 0;
    }
  }
  return iVar2;
}


