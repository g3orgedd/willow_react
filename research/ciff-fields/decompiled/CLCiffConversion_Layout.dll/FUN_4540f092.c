// Source: CLCiffConversion_Layout.dll @ 4540f092; FUN_4540f092

DOUBLE * __thiscall FUN_4540f092(void *this,WORD *param_1)

{
  char cVar1;
  
  cVar1 = FUN_4540f3e8(this,*param_1,(uint)param_1[1],param_1[3],param_1[4],param_1[5],param_1[6]);
  if (cVar1 == '\0') {
    *(undefined8 *)this = DAT_45447ce0;
  }
  return this;
}


