// Source: CLCiffConversion_Data.dll @ 45033c72; _isxdigit

/* Library Function - Single Match
    _isxdigit
   
   Library: Visual Studio 2012 Release */

int __cdecl _isxdigit(int _C)

{
  ushort uVar1;
  undefined2 extraout_var;
  
  if (DAT_45055394 == 0) {
    return *(ushort *)(PTR_DAT_45052028 + _C * 2) & 0x80;
  }
  uVar1 = FUN_45033bef(_C,(int *)0x0);
  return CONCAT22(extraout_var,uVar1);
}


