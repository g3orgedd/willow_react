// Source: CLCiffConversion_Layout.dll @ 4543ad80; _isdigit

/* Library Function - Single Match
    _isdigit
   
   Library: Visual Studio 2012 Release */

int __cdecl _isdigit(int _C)

{
  ushort uVar1;
  undefined2 extraout_var;
  
  if (DAT_4546122c == 0) {
    return *(ushort *)(PTR_DAT_4545e2f8 + _C * 2) & 4;
  }
  uVar1 = FUN_4543acd6(_C,(int *)0x0);
  return CONCAT22(extraout_var,uVar1);
}


