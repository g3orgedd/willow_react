// Source: CLCiffConversion_Data.dll @ 4501d127; FUN_4501d127

DOUBLE * __thiscall FUN_4501d127(void *this,WORD *param_1)

{
  char cVar1;
  
  cVar1 = FUN_4501dcf2(this,*param_1,(uint)param_1[1],param_1[3],param_1[4],param_1[5],param_1[6]);
  if (cVar1 == '\0') {
    *(undefined8 *)this = DAT_4503d998;
  }
  return this;
}


