// Source: CLCiffConversion_Data.dll @ 45009b90; FUN_45009b90

void __cdecl FUN_45009b90(int *param_1,uint param_2,int param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  
  if (((param_1 == (int *)0x0) || ((int)param_2 < 0)) || (param_3 == 0)) {
    iVar2 = -0x7ff8ffa9;
    goto LAB_45009bf6;
  }
  if (*param_1 == param_3) {
    if ((int)param_2 <= param_4) goto LAB_45009bd3;
    pvVar1 = FUN_450238a4(param_2,1);
LAB_45009bed:
    *param_1 = (int)pvVar1;
LAB_45009bd5:
    if (*param_1 != 0) {
      return;
    }
  }
  else {
    if ((int)param_2 <= param_4) {
      FID_conflict__free((void *)*param_1);
LAB_45009bd3:
      *param_1 = param_3;
      goto LAB_45009bd5;
    }
    pvVar1 = FUN_4502391c((LPCVOID)*param_1,param_2,1);
    if (pvVar1 != (void *)0x0) goto LAB_45009bed;
  }
  iVar2 = -0x7ff8fff2;
LAB_45009bf6:
                    /* WARNING: Subroutine does not return */
  FUN_45002735(iVar2);
}


