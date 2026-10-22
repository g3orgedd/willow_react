// Source: CLCiffConversion_Layout.dll @ 4544040b; FUN_4544040b

undefined2 __cdecl FUN_4544040b(FILE *param_1)

{
  char cVar1;
  undefined2 uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  bool bVar8;
  LPWSTR pWVar9;
  char local_5;
  
  bVar8 = false;
  local_5 = '\0';
  cVar1 = local_5;
  local_5 = '\0';
  if (param_1 == (FILE *)0x0) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_45432798();
  }
  else {
    uVar5 = param_1->_flag;
    if (((uVar5 & 0x83) != 0) && ((uVar5 & 0x40) == 0)) {
      if ((uVar5 & 2) == 0) {
        param_1->_flag = uVar5 | 1;
        if ((uVar5 & 0x10c) == 0) {
          __getbuf(param_1);
        }
        else {
          bVar8 = param_1->_cnt == 1;
          local_5 = cVar1;
          if (bVar8) {
            local_5 = *param_1->_ptr;
          }
          param_1->_ptr = param_1->_base;
        }
        uVar5 = param_1->_bufsiz;
        pWVar9 = (LPWSTR)param_1->_base;
        uVar4 = __fileno(param_1);
        uVar5 = FUN_45440ab7(uVar4,pWVar9,uVar5);
        param_1->_cnt = uVar5;
        if (((uVar5 != 0) && (uVar5 != 1)) && (uVar5 != 0xffffffff)) {
          if ((param_1->_flag & 0x82) == 0) {
            iVar6 = __fileno(param_1);
            if ((iVar6 == -1) || (iVar6 = __fileno(param_1), iVar6 == -2)) {
              puVar7 = &DAT_4545e540;
            }
            else {
              iVar6 = __fileno(param_1);
              uVar5 = __fileno(param_1);
              puVar7 = (undefined *)((uVar5 & 0x1f) * 0x40 + (&DAT_454612f8)[iVar6 >> 5]);
            }
            if ((puVar7[4] & 0x82) == 0x82) {
              param_1->_flag = param_1->_flag | 0x2000;
            }
          }
          if (((param_1->_bufsiz == 0x200) && ((param_1->_flag & 8) != 0)) &&
             ((param_1->_flag & 0x400U) == 0)) {
            param_1->_bufsiz = 0x1000;
          }
          if (bVar8) {
            cVar1 = *param_1->_ptr;
            param_1->_cnt = param_1->_cnt + -1;
            param_1->_ptr = param_1->_ptr + 1;
            return CONCAT11(cVar1,local_5);
          }
          param_1->_cnt = param_1->_cnt + -2;
          uVar2 = *(undefined2 *)param_1->_ptr;
          param_1->_ptr = param_1->_ptr + 2;
          return uVar2;
        }
        param_1->_flag = param_1->_flag | (-(uint)(uVar5 != 0) & 0x10) + 0x10;
        param_1->_cnt = 0;
      }
      else {
        param_1->_flag = uVar5 | 0x20;
      }
    }
  }
  return 0xffff;
}


