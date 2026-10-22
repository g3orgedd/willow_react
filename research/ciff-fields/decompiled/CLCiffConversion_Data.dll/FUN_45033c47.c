// Source: CLCiffConversion_Data.dll @ 45033c47; _isdigit

/* Library Function - Single Match
    _isdigit
   
   Library: Visual Studio 2012 Release */

int __cdecl _isdigit(int _C)

{
  ushort uVar1;
  undefined2 extraout_var;
  
  if (DAT_45055394 == 0) {
    return *(ushort *)(PTR_DAT_45052028 + _C * 2) & 4;
  }
  uVar1 = FUN_45033b9d(_C,(int *)0x0);
  return CONCAT22(extraout_var,uVar1);
}


