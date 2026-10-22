// Source: CiffHelper.dll @ 40829d89; FUN_40829d89

void __thiscall
FUN_40829d89(void *this,WORD param_1,uint param_2,WORD param_3,WORD param_4,WORD param_5,
            WORD param_6)

{
  char cVar1;
  
  cVar1 = FUN_40829b60(this,param_1,param_2,param_3,param_4,param_5,param_6);
  if (cVar1 == '\0') {
    *(undefined8 *)this = DAT_4084abe0;
  }
  FUN_40829b07(this);
  return;
}


