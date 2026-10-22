// Source: CLCiffConversion_Data.dll @ 4501da6f; FUN_4501da6f

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_4501da6f(void *this,int *param_1,int *param_2,undefined8 *param_3,int param_4)

{
  BSTR pOVar1;
  undefined1 auStack_141c [12];
  undefined4 uStack_1410;
  int local_13ec [1270];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_4503c74d;
  local_10 = ExceptionList;
  local_14 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  basic_string<>(auStack_141c,param_3);
  FUN_4500abff(local_13ec,*(DOUBLE *)this);
  local_8 = 0;
  SysFreeString((BSTR)*param_2);
  *param_2 = 0;
  uStack_1410 = 0x4501daf8;
  pOVar1 = FUN_4501feaa(local_13ec,param_1,param_4);
  if ((BSTR)*param_2 != pOVar1) {
    SysFreeString((BSTR)*param_2);
    *param_2 = (int)pOVar1;
  }
  local_8 = 0xffffffff;
  FUN_4500ada0(local_13ec);
  ExceptionList = local_10;
  FUN_45022e32(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


