// Source: CLCiffConversion_Data.dll @ 4502f17e; __FF_MSGBANNER

/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 2012 Release */

void __cdecl __FF_MSGBANNER(void)

{
  int iVar1;
  
  iVar1 = __set_error_mode(3);
  if (iVar1 != 1) {
    iVar1 = __set_error_mode(3);
    if (iVar1 != 0) {
      return;
    }
    if (DAT_450553e8 != 1) {
      return;
    }
  }
  FUN_4502f1db(0xfc);
  FUN_4502f1db(0xff);
  return;
}


