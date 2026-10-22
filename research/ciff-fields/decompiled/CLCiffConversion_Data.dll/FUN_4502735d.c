// Source: CLCiffConversion_Data.dll @ 4502735d; FUN_4502735d

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

pthreadmbcinfo FUN_4502735d(void)

{
  int iVar1;
  _ptiddata p_Var2;
  pthreadmbcinfo _Memory;
  
  p_Var2 = __getptd();
  if (((p_Var2->_ownlocale & DAT_45052058) == 0) || (p_Var2->ptlocinfo == (pthreadlocinfo)0x0)) {
    __lock(0xd);
    _Memory = p_Var2->ptmbcinfo;
    if (_Memory != (pthreadmbcinfo)PTR_DAT_45051d2c) {
      if (_Memory != (pthreadmbcinfo)0x0) {
        LOCK();
        iVar1 = _Memory->refcount + -1;
        _Memory->refcount = iVar1;
        UNLOCK();
        if ((iVar1 == 0) && (_Memory != (pthreadmbcinfo)&DAT_45051b08)) {
          FID_conflict__free(_Memory);
        }
      }
      p_Var2->ptmbcinfo = (pthreadmbcinfo)PTR_DAT_45051d2c;
      _Memory = (pthreadmbcinfo)PTR_DAT_45051d2c;
      LOCK();
      *(int *)PTR_DAT_45051d2c = *(int *)PTR_DAT_45051d2c + 1;
      UNLOCK();
    }
    FUN_450273fa();
  }
  else {
    _Memory = p_Var2->ptmbcinfo;
  }
  if (_Memory == (pthreadmbcinfo)0x0) {
    __amsg_exit(0x20);
  }
  return _Memory;
}


