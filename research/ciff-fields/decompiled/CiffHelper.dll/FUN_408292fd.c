// Source: CiffHelper.dll @ 408292fd; FUN_408292fd

DOUBLE * __thiscall FUN_408292fd(void *this,WORD *param_1)

{
  char cVar1;
  
  cVar1 = FUN_40829b60(this,*param_1,(uint)param_1[1],param_1[3],param_1[4],param_1[5],param_1[6]);
  if (cVar1 == '\0') {
    *(undefined8 *)this = DAT_4084abe0;
  }
  return this;
}


