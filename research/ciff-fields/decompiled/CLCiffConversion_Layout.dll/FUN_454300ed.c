// Source: CLCiffConversion_Layout.dll @ 454300ed; __getptd_noexit

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
  _Memory = (_ptiddata)FUN_4543969d(DAT_4545da34);
  if (_Memory == (_ptiddata)0x0) {
    _Memory = FUN_454375c4(1,0x3bc);
    if (_Memory != (_ptiddata)0x0) {
      iVar1 = FUN_454396bc(DAT_4545da34,_Memory);
      if (iVar1 == 0) {
        FID_conflict__free(_Memory);
        _Memory = (_ptiddata)0x0;
      }
      else {
        FUN_4543015c((int)_Memory,0);
        DVar2 = GetCurrentThreadId();
        _Memory->_thandle = 0xffffffff;
        _Memory->_tid = DVar2;
      }
    }
  }
  SetLastError(dwErrCode);
  return _Memory;
}


