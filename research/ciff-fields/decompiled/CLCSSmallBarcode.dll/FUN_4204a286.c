// Source: CLCSSmallBarcode.dll @ 4204a286; FUN_4204a286

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4204a286(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_1470 [2];
  float local_1468;
  undefined4 *local_1464;
  double local_1460;
  undefined8 local_1458;
  uint local_1450;
  undefined8 local_144c;
  float local_1444;
  int local_1440;
  int *local_143c;
  int local_1438;
  int local_1434;
  undefined4 local_1430 [1281];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [24];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_4208579f;
  local_10 = ExceptionList;
  uVar3 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_144c._4_4_ = param_2;
  local_1458._4_4_ = param_3;
  local_1464 = param_4;
  local_14 = uVar3;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCLCSSmallBarcodeObj::DoDataMatrixResize");
  iVar4 = param_1[3];
  iVar5 = param_1[2];
  local_8 = 0;
  iVar6 = param_1[1];
  iVar1 = *param_1;
  (**(code **)(*(int *)*local_144c._4_4_ + 0x54))((int *)*local_144c._4_4_,local_1470,uVar3);
  puVar2 = local_1458._4_4_;
  local_144c = (double)(iVar5 - iVar1);
  local_1460 = (double)(iVar4 - iVar6);
  (**(code **)(*(int *)*local_1458._4_4_ + 0x2c))((int *)*local_1458._4_4_,&local_1444);
  (**(code **)(*(int *)*puVar2 + 0x34))((int *)*puVar2,&local_1468);
  iVar4 = FUN_4200434d(local_1444 * _DAT_4208982c);
  local_1458 = (double)iVar4 / DAT_42089810;
  iVar4 = FUN_4200434d(local_1468 * _DAT_4208982c);
  puVar2 = local_1464;
  if (local_1470[0] == 1) {
    local_144c = local_144c / local_1458;
    local_1460 = local_1460 / ((double)iVar4 / DAT_42089810);
  }
  CComQIPtr<>(&local_143c,(undefined4 *)*local_1464);
  local_1470[1] = 0xffffffff;
  local_8._0_1_ = 1;
  local_1450 = 2;
  if (local_143c != (int *)0x0) {
    (**(code **)(*local_143c + 0x164))(local_143c,&local_1450);
    (**(code **)(*local_143c + 0x15c))(local_143c,local_1470 + 1);
  }
  local_1438 = 0xe;
  local_1434 = 0xe;
  FUN_4202be47(local_1430);
  local_8._0_1_ = 2;
  FUN_4202c07e(local_1450,&local_1438,&local_1434);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4202be75(local_1430);
  local_1440 = 0;
  (**(code **)(*(int *)*puVar2 + 0x108))((int *)*puVar2,&local_1440);
  if (local_1440 == 1) {
    local_1438 = local_1438 + 2;
    local_1434 = local_1434 + 2;
  }
  iVar4 = (int)(local_144c / (double)local_1438);
  if ((int)(local_1460 / (double)local_1434) < (int)(local_144c / (double)local_1438)) {
    iVar4 = (int)(local_1460 / (double)local_1434);
  }
  if (500 < iVar4) {
    iVar4 = 500;
  }
  iVar5 = (int)((float)iVar4 * local_1444);
  if ((int)((float)iVar4 * local_1444) < 1) {
    iVar5 = 1;
  }
  iVar4 = FUN_4200434d((float)iVar5 / local_1444);
  FUN_420034ad(0x4209d828);
  if (local_143c != (int *)0x0) {
    (**(code **)(*local_143c + 0x160))(local_143c,iVar4);
  }
  iVar5 = iVar4 * local_1438;
  iVar6 = iVar4 * local_1434;
  if (local_1440 == 1) {
    iVar5 = iVar5 + iVar4 * 2;
    iVar6 = iVar6 + iVar4 * 2;
  }
  (**(code **)(*(int *)*puVar2 + 0x7c))((int *)*puVar2,iVar5);
  (**(code **)(*(int *)*puVar2 + 0x84))((int *)*puVar2,iVar6);
  (**(code **)(*(int *)*puVar2 + 0xbc))((int *)*puVar2,iVar6);
  local_8 = local_8 & 0xffffff00;
  if (local_143c != (int *)0x0) {
    (**(code **)(*local_143c + 8))(local_143c);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  ExceptionList = local_10;
  FUN_4206a5c8(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


