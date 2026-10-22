// Source: CLCiffConversion_Layout.dll @ 4543400b; write_char

/* Library Function - Single Match
    _write_char
   
   Library: Visual Studio 2019 Release */

void __cdecl write_char(byte param_1,FILE *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  if (((param_2->_flag & 0x40) == 0) || (param_2->_base != (char *)0x0)) {
    piVar1 = &param_2->_cnt;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      uVar2 = FUN_45433320((int)(char)param_1,param_2);
    }
    else {
      *param_2->_ptr = param_1;
      param_2->_ptr = param_2->_ptr + 1;
      uVar2 = (uint)param_1;
    }
    if (uVar2 == 0xffffffff) {
      *param_3 = -1;
      return;
    }
  }
  *param_3 = *param_3 + 1;
  return;
}


