// Source: CLCiffConversion_Layout.dll @ 45440038; FUN_45440038

undefined2 __cdecl FUN_45440038(undefined2 param_1,FILE *param_2)

{
  uint uVar1;
  WCHAR *pWVar2;
  FILE *pFVar3;
  byte bVar4;
  WCHAR *pWVar5;
  int *piVar6;
  undefined **ppuVar7;
  undefined3 extraout_var;
  FILE *pFVar8;
  undefined *puVar9;
  FILE *pFVar10;
  longlong lVar11;
  WCHAR local_8;
  undefined2 uStack_6;
  
  pFVar3 = param_2;
  pWVar5 = (WCHAR *)__fileno(param_2);
  uVar1 = param_2->_flag;
  if ((uVar1 & 0x82) == 0) {
    piVar6 = __errno();
    *piVar6 = 9;
LAB_4544005d:
    param_2->_flag = param_2->_flag | 0x20;
    return 0xffff;
  }
  if ((uVar1 & 0x40) != 0) {
    piVar6 = __errno();
    *piVar6 = 0x22;
    goto LAB_4544005d;
  }
  pFVar10 = (FILE *)0x0;
  if ((uVar1 & 1) != 0) {
    param_2->_cnt = 0;
    if ((uVar1 & 0x10) == 0) {
      param_2->_flag = uVar1 | 0x20;
      return 0xffff;
    }
    param_2->_ptr = param_2->_base;
    param_2->_flag = uVar1 & 0xfffffffe;
  }
  uVar1 = param_2->_flag;
  param_2->_cnt = 0;
  param_2->_flag = uVar1 & 0xffffffef | 2;
  if (((uVar1 & 0x10c) == 0) &&
     (((ppuVar7 = FUN_4543c1b0(), param_2 != (FILE *)(ppuVar7 + 8) &&
       (ppuVar7 = FUN_4543c1b0(), param_2 != (FILE *)(ppuVar7 + 0x10))) ||
      (bVar4 = FUN_4543c2b0((uint)pWVar5), CONCAT31(extraout_var,bVar4) == 0)))) {
    __getbuf(param_2);
  }
  if ((param_2->_flag & 0x108U) == 0) {
    _local_8 = CONCAT22(uStack_6,param_1);
    param_2 = (FILE *)0x2;
    pFVar10 = (FILE *)FUN_4543c304(pWVar5,&local_8,2);
  }
  else {
    pWVar2 = (WCHAR *)param_2->_base;
    pFVar8 = (FILE *)(param_2->_ptr + -(int)pWVar2);
    param_2->_ptr = (char *)(pWVar2 + 1);
    param_2->_cnt = param_2->_bufsiz + -2;
    if ((int)pFVar8 < 1) {
      if ((pWVar5 == (WCHAR *)0xffffffff) || (pWVar5 == (WCHAR *)0xfffffffe)) {
        puVar9 = &DAT_4545e540;
      }
      else {
        puVar9 = (undefined *)(((uint)pWVar5 & 0x1f) * 0x40 + (&DAT_454612f8)[(int)pWVar5 >> 5]);
      }
      if (((puVar9[4] & 0x20) != 0) &&
         (lVar11 = FUN_4543cc58((uint)pWVar5,0,0,(PLARGE_INTEGER)0x2), lVar11 == -1))
      goto LAB_45440185;
    }
    else {
      pFVar10 = (FILE *)FUN_4543c304(pWVar5,pWVar2,(uint)pFVar8);
    }
    *(undefined2 *)param_2->_base = param_1;
    param_2 = pFVar8;
  }
  if (pFVar10 == param_2) {
    return param_1;
  }
LAB_45440185:
  pFVar3->_flag = pFVar3->_flag | 0x20;
  return 0xffff;
}


