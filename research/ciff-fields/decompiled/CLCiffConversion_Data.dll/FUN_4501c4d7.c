// Source: CLCiffConversion_Data.dll @ 4501c4d7; FUN_4501c4d7

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __thiscall FUN_4501c4d7(void *this,undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  BSTR pOVar5;
  BSTR bstrString;
  int *local_141c;
  int local_1418;
  int local_1414;
  undefined4 local_1410;
  int local_140c;
  int local_1408;
  int local_1404;
  int local_1400;
  int local_13fc;
  BSTR local_13f8;
  int *local_13f4;
  int *local_13f0;
  int local_13ec [1270];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_4503c207;
  local_10 = ExceptionList;
  uVar1 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  puVar2 = FUN_4501b97e(param_1,&local_141c,
                        (int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x38 + (int)this));
  CComQIPtr<>(&local_13f0,(undefined4 *)*puVar2);
  local_8 = 0;
  if (local_141c != (int *)0x0) {
    (**(code **)(*local_141c + 8))(local_141c,uVar1);
  }
  CComQIPtr<>(&local_13f4,(undefined4 *)*param_1);
  local_8._0_1_ = 1;
  if ((local_13f0 == (int *)0x0) || (local_13f4 == (int *)0x0)) goto LAB_4501c851;
  local_1408 = 0;
  (**(code **)(*local_13f4 + 0x158))(local_13f4,&local_1408);
  local_1410 = 2;
  (**(code **)(*local_13f0 + 0x7c))(local_13f0,&local_1410);
  local_1404 = 0;
  (**(code **)(*local_13f0 + 0x74))(local_13f0,&local_1404);
  local_13fc = -1;
  if (local_1404 == 1) {
    *(undefined1 *)((int)this + 8) = 1;
    (**(code **)(*local_13f0 + 0x2c))();
  }
  else {
    iVar3 = (**(code **)(*local_13f0 + 0x24))(local_13f0,&local_13fc);
    if (-1 < iVar3) {
      (**(code **)(*local_13f0 + 0x30))(local_13f0,local_13fc);
    }
  }
  iVar3 = local_13fc;
  local_140c = 0;
  local_1414 = 0;
  iVar4 = (**(code **)(*local_13f0 + 0x3c))(local_13f0,&local_1414);
  if ((-1 < iVar4) && (local_1414 != 0)) {
    (**(code **)(*local_13f0 + 0x34))(local_13f0,&local_140c);
  }
  local_1400 = 0;
  local_1418 = 0;
  iVar4 = (**(code **)(*local_13f0 + 0x4c))(local_13f0,&local_1418);
  if ((-1 < iVar4) && (local_1418 != 0)) {
    (**(code **)(*local_13f0 + 0x44))(local_13f0,&local_1400);
  }
  if ((local_140c != 0) && (iVar3 < local_140c)) {
    iVar3 = local_140c;
  }
  if ((local_1400 != 0) && (local_1400 < iVar3)) {
    iVar3 = local_1400;
  }
  local_13f8 = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (iVar3 < local_1408) {
    iVar4 = (**(code **)(*local_13f4 + 0x150))(local_13f4,&local_13f8);
    if (iVar4 < 0) {
      SysFreeString(local_13f8);
      local_13f8 = (BSTR)0x0;
    }
    if (local_13f8 == (BSTR)0x0) goto LAB_4501c6fd;
  }
  else {
LAB_4501c6fd:
    (**(code **)(*local_13f4 + 0x148))(local_13f4,&local_13f8);
  }
  local_8._0_1_ = 3;
  FUN_45019c2f(local_13ec,iVar3,local_1410);
  local_8 = CONCAT31(local_8._1_3_,5);
  pOVar5 = FUN_4501feaa(local_13ec,(int *)&local_13f8,0);
  bstrString = (BSTR)0x0;
  if (pOVar5 != (BSTR)0x0) {
    SysFreeString((BSTR)0x0);
    bstrString = pOVar5;
  }
  (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,bstrString);
  if (*(char *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x100 + (int)this) == '\0') {
    (**(code **)(*local_13f0 + 0x78))(local_13f0,0);
    (**(code **)(*local_13f0 + 0x88))(local_13f0,0);
    (**(code **)(*local_13f0 + 0x90))(local_13f0,0);
    (**(code **)(*local_13f4 + 0x144))(local_13f4,0);
    (**(code **)(*local_13f4 + 0x2c))(local_13f4,0);
    (**(code **)(*local_13f4 + 0x3c))(local_13f4,1);
    (**(code **)(*local_13f4 + 0x44))(local_13f4,0);
    (**(code **)(*local_13f4 + 0x84))(local_13f4,L"en-GB");
    (**(code **)(*local_13f4 + 0x54))(local_13f4,0);
    (**(code **)(*local_13f4 + 0x5c))(local_13f4,bstrString);
  }
  SysFreeString(bstrString);
  local_8._0_1_ = 3;
  FUN_4500ada0(local_13ec);
  SysFreeString((BSTR)0x0);
  SysFreeString(local_13f8);
LAB_4501c851:
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_13f4 != (int *)0x0) {
    (**(code **)(*local_13f4 + 8))(local_13f4);
  }
  local_8 = 0xffffffff;
  if (local_13f0 != (int *)0x0) {
    (**(code **)(*local_13f0 + 8))(local_13f0);
  }
  ExceptionList = local_10;
  FUN_45022e32(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


