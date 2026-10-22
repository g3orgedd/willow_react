// Source: CLCiffConversion_Data.dll @ 4503623f; FUN_4503623f

undefined4 __cdecl FUN_4503623f(FILE *param_1)

{
  WCHAR *pWVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  WCHAR *pWVar5;
  
  uVar3 = 0;
  if (((((byte)param_1->_flag & 3) == 2) && ((param_1->_flag & 0x108U) != 0)) &&
     (uVar4 = (int)param_1->_ptr - (int)param_1->_base, 0 < (int)uVar4)) {
    pWVar5 = (WCHAR *)param_1->_base;
    uVar2 = uVar4;
    pWVar1 = (WCHAR *)__fileno(param_1);
    uVar2 = FUN_45032a82(pWVar1,pWVar5,uVar2);
    if (uVar2 == uVar4) {
      if ((char)param_1->_flag < '\0') {
        param_1->_flag = param_1->_flag & 0xfffffffd;
      }
    }
    else {
      param_1->_flag = param_1->_flag | 0x20;
      uVar3 = 0xffffffff;
    }
  }
  param_1->_cnt = 0;
  param_1->_ptr = param_1->_base;
  return uVar3;
}


