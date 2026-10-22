// Source: CLCiffConversion_Layout.dll @ 45433320; FUN_45433320

uint __cdecl FUN_45433320(uint param_1,FILE *param_2)

{
  uint uVar1;
  WCHAR *pWVar2;
  FILE *_File;
  byte bVar3;
  WCHAR *pWVar4;
  int *piVar5;
  undefined **ppuVar6;
  undefined3 extraout_var;
  undefined *puVar7;
  FILE *pFVar8;
  longlong lVar9;
  
  _File = param_2;
  pWVar4 = (WCHAR *)__fileno(param_2);
  uVar1 = _File->_flag;
  if ((uVar1 & 0x82) == 0) {
    piVar5 = __errno();
    *piVar5 = 9;
LAB_45433344:
    _File->_flag = _File->_flag | 0x20;
    return 0xffffffff;
  }
  if ((uVar1 & 0x40) != 0) {
    piVar5 = __errno();
    *piVar5 = 0x22;
    goto LAB_45433344;
  }
  pFVar8 = (FILE *)0x0;
  if ((uVar1 & 1) != 0) {
    _File->_cnt = 0;
    if ((uVar1 & 0x10) == 0) {
      _File->_flag = uVar1 | 0x20;
      return 0xffffffff;
    }
    _File->_ptr = _File->_base;
    _File->_flag = uVar1 & 0xfffffffe;
  }
  uVar1 = _File->_flag;
  _File->_cnt = 0;
  _File->_flag = uVar1 & 0xffffffef | 2;
  if (((uVar1 & 0x10c) == 0) &&
     (((ppuVar6 = FUN_4543c1b0(), _File != (FILE *)(ppuVar6 + 8) &&
       (ppuVar6 = FUN_4543c1b0(), _File != (FILE *)(ppuVar6 + 0x10))) ||
      (bVar3 = FUN_4543c2b0((uint)pWVar4), CONCAT31(extraout_var,bVar3) == 0)))) {
    __getbuf(_File);
  }
  if ((_File->_flag & 0x108U) == 0) {
    param_2 = (FILE *)0x1;
    pFVar8 = (FILE *)FUN_4543c304(pWVar4,(WCHAR *)&param_1,1);
  }
  else {
    pWVar2 = (WCHAR *)_File->_base;
    param_2 = (FILE *)(_File->_ptr + -(int)pWVar2);
    _File->_ptr = (char *)((int)pWVar2 + 1);
    _File->_cnt = _File->_bufsiz + -1;
    if ((int)param_2 < 1) {
      if ((pWVar4 == (WCHAR *)0xffffffff) || (pWVar4 == (WCHAR *)0xfffffffe)) {
        puVar7 = &DAT_4545e540;
      }
      else {
        puVar7 = (undefined *)(((uint)pWVar4 & 0x1f) * 0x40 + (&DAT_454612f8)[(int)pWVar4 >> 5]);
      }
      if (((puVar7[4] & 0x20) != 0) &&
         (lVar9 = FUN_4543cc58((uint)pWVar4,0,0,(PLARGE_INTEGER)0x2), lVar9 == -1))
      goto LAB_4543345b;
    }
    else {
      pFVar8 = (FILE *)FUN_4543c304(pWVar4,pWVar2,(uint)param_2);
    }
    *_File->_base = (char)param_1;
  }
  if (pFVar8 == param_2) {
    return param_1 & 0xff;
  }
LAB_4543345b:
  _File->_flag = _File->_flag | 0x20;
  return 0xffffffff;
}


