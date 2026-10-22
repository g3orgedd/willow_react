// Source: CLCiffConversion_Data.dll @ 45009bfc; FUN_45009bfc

void __cdecl FUN_45009bfc(int *param_1,uint param_2,int param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  
  if (((param_1 == (int *)0x0) || ((int)param_2 < 0)) || (param_3 == 0)) {
    iVar2 = -0x7ff8ffa9;
    goto LAB_45009c62;
  }
  if (*param_1 == param_3) {
    if ((int)param_2 <= param_4) goto LAB_45009c3f;
    pvVar1 = FUN_450238a4(param_2,2);
LAB_45009c59:
    *param_1 = (int)pvVar1;
LAB_45009c41:
    if (*param_1 != 0) {
      return;
    }
  }
  else {
    if ((int)param_2 <= param_4) {
      FID_conflict__free((void *)*param_1);
LAB_45009c3f:
      *param_1 = param_3;
      goto LAB_45009c41;
    }
    pvVar1 = FUN_4502391c((LPCVOID)*param_1,param_2,2);
    if (pvVar1 != (void *)0x0) goto LAB_45009c59;
  }
  iVar2 = -0x7ff8fff2;
LAB_45009c62:
                    /* WARNING: Subroutine does not return */
  FUN_45002735(iVar2);
}


