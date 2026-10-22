// Source: CLCSBarcodeField.dll @ 41442e16; FUN_41442e16

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_41442e16(BSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 int param_9,int *param_10,int *param_11,int *param_12)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_1a38 [2];
  char local_1a2f;
  int local_1a14;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  piVar3 = param_12;
  piVar2 = param_11;
  piVar1 = param_10;
  puStack_c = &LAB_4147d95e;
  local_10 = ExceptionList;
  local_14 = DAT_414aacf0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_4145ddcf(local_1a38);
  local_8._0_1_ = 1;
  FUN_4145f5a7(local_1a38,(char)param_2,(char)param_3,param_4,param_5,param_6,param_7,param_8);
  FUN_4145e65f(local_1a38,&param_1);
  if (local_1a2f != '\0') {
    local_1a14 = local_1a14 + 2;
  }
  *piVar1 = local_1a14;
  iVar4 = FUN_41442daf(local_1a38,param_9);
  *piVar2 = iVar4;
  iVar4 = FUN_41442dd4((int)local_1a38);
  *piVar3 = iVar4;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_4145de0c(local_1a38);
  SysFreeString(param_1);
  ExceptionList = local_10;
  FUN_41461e5c(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


