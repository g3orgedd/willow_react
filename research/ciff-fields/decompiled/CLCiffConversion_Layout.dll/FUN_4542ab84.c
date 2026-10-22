// Source: CLCiffConversion_Layout.dll @ 4542ab84; FUN_4542ab84

undefined4 __cdecl
FUN_4542ab84(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  _ptiddata p_Var1;
  undefined4 *local_3c;
  code *local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  int local_18;
  undefined4 *local_14;
  undefined4 local_10;
  code *local_c;
  undefined4 local_8;
  
  local_1c = &stack0xfffffffc;
  local_20 = &stack0xffffffc0;
  if (param_1 == (undefined4 *)0x123) {
    *param_2 = 0x4542ac2d;
    local_8 = 1;
  }
  else {
    local_38 = __TranslatorGuardHandler;
    local_34 = DAT_4545d9f0 ^ (uint)&local_3c;
    local_30 = param_5;
    local_2c = param_2;
    local_28 = param_6;
    local_24 = param_7;
    local_18 = 0;
    local_3c = ExceptionList;
    ExceptionList = &local_3c;
    local_8 = 1;
    local_14 = param_1;
    local_10 = param_3;
    p_Var1 = __getptd();
    local_c = p_Var1->_translator;
    (*local_c)(*param_1,&local_14);
    local_8 = 0;
    if (local_18 != 0) {
      *local_3c = *(undefined4 *)ExceptionList;
    }
    ExceptionList = local_3c;
  }
  return local_8;
}


