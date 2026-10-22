// Source: CLCiffConversion_Data.dll @ 4502796f; __getptd_noexit

/* Library Function - Single Match
    __getptd_noexit
   
   Library: Visual Studio 2012 Release */

_ptiddata __cdecl __getptd_noexit(void)

{
  DWORD dwErrCode;
  _ptiddata _Memory;
  int iVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  _Memory = (_ptiddata)FUN_4502ec32(DAT_45051e20);
  if (_Memory == (_ptiddata)0x0) {
    _Memory = FUN_4502dee1(1,0x3bc);
    if (_Memory != (_ptiddata)0x0) {
      iVar1 = FUN_4502ec51(DAT_45051e20,_Memory);
      if (iVar1 == 0) {
        FID_conflict__free(_Memory);
        _Memory = (_ptiddata)0x0;
      }
      else {
        FUN_450279de((int)_Memory,0);
        DVar2 = GetCurrentThreadId();
        _Memory->_thandle = 0xffffffff;
        _Memory->_tid = DVar2;
      }
    }
  }
  SetLastError(dwErrCode);
  return _Memory;
}


