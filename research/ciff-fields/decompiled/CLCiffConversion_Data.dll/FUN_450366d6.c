// Source: CLCiffConversion_Data.dll @ 450366d6; FUN_450366d6

uint __cdecl FUN_450366d6(FILE *param_1)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  LPWSTR pWVar7;
  
  if (param_1 == (FILE *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_45027e29();
  }
  else {
    uVar4 = param_1->_flag;
    if (((uVar4 & 0x83) != 0) && ((uVar4 & 0x40) == 0)) {
      if ((uVar4 & 2) == 0) {
        param_1->_flag = uVar4 | 1;
        if ((uVar4 & 0x10c) == 0) {
          __getbuf(param_1);
        }
        else {
          param_1->_ptr = param_1->_base;
        }
        uVar4 = param_1->_bufsiz;
        pWVar7 = (LPWSTR)param_1->_base;
        uVar3 = __fileno(param_1);
        uVar4 = FUN_45037e09(uVar3,pWVar7,uVar4);
        param_1->_cnt = uVar4;
        if ((uVar4 != 0) && (uVar4 != 0xffffffff)) {
          if ((param_1->_flag & 0x82) == 0) {
            iVar5 = __fileno(param_1);
            if ((iVar5 == -1) || (iVar5 = __fileno(param_1), iVar5 == -2)) {
              puVar6 = &DAT_45052420;
            }
            else {
              iVar5 = __fileno(param_1);
              uVar4 = __fileno(param_1);
              puVar6 = (undefined *)((uVar4 & 0x1f) * 0x40 + (&DAT_45055ae0)[iVar5 >> 5]);
            }
            if ((puVar6[4] & 0x82) == 0x82) {
              param_1->_flag = param_1->_flag | 0x2000;
            }
          }
          if (((param_1->_bufsiz == 0x200) && ((param_1->_flag & 8) != 0)) &&
             ((param_1->_flag & 0x400U) == 0)) {
            param_1->_bufsiz = 0x1000;
          }
          param_1->_cnt = param_1->_cnt + -1;
          bVar1 = *param_1->_ptr;
          param_1->_ptr = param_1->_ptr + 1;
          return (uint)bVar1;
        }
        param_1->_flag = param_1->_flag | (-(uint)(uVar4 != 0) & 0x10) + 0x10;
        param_1->_cnt = 0;
      }
      else {
        param_1->_flag = uVar4 | 0x20;
      }
    }
  }
  return 0xffffffff;
}


