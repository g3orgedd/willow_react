// Source: CLCiffConversion_Data.dll @ 4500fff6; FUN_4500fff6

HRESULT FUN_4500fff6(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  HRESULT HVar3;
  SAFEARRAY *psa;
  
  piVar2 = param_2;
  piVar1 = param_1;
  if (param_1 == (int *)0x0) {
    HVar3 = -0x7fffbffd;
  }
  else if ((*param_1 == 0) && (param_2[1] != 0)) {
    param_1 = (int *)0x0;
    psa = SafeArrayCreateVector(8,0,param_2[1]);
    *piVar1 = (int)psa;
    if (psa == (SAFEARRAY *)0x0) {
      HVar3 = -0x7ff8fff2;
    }
    else {
      HVar3 = SafeArrayAccessData(psa,&param_1);
      if (HVar3 < 0) {
        SafeArrayDestroy((SAFEARRAY *)*piVar1);
        *piVar1 = 0;
      }
      else {
        param_2 = (int *)&param_1;
        FUN_4500a4d6(*(int *)*piVar2,*piVar2,&param_2);
        HVar3 = SafeArrayUnaccessData((SAFEARRAY *)*piVar1);
      }
    }
  }
  else {
    HVar3 = -0x7ff8ffa9;
  }
  return HVar3;
}


