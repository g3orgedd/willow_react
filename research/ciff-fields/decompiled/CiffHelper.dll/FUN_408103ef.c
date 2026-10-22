// Source: CiffHelper.dll @ 408103ef; FUN_408103ef

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_408103ef(int *param_1,int *param_2,int *param_3)

{
  uint uVar1;
  DOUBLE *pDVar2;
  OLECHAR *pOVar3;
  size_t sVar4;
  wchar_t ****ppppwVar5;
  uint uVar6;
  undefined1 *puVar7;
  uint uVar8;
  bool bVar9;
  OLECHAR *in_stack_00000028;
  uint in_stack_0000003c;
  undefined1 auStack_1470 [8];
  undefined4 uStack_1468;
  undefined1 local_143c [4];
  uint local_1438;
  int *local_1434;
  uint local_1430;
  BSTR local_142c;
  uint local_1428;
  undefined1 *local_1424;
  uint local_1420;
  int local_141c [1270];
  undefined1 local_44 [24];
  wchar_t ***local_2c [4];
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_408464c1;
  local_10 = ExceptionList;
  local_14 = DAT_40862970 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1434 = param_3;
  local_1424 = auStack_1470;
  local_8 = 1;
  basic_string<>(auStack_1470,L"EN-GB");
  local_8._0_1_ = 2;
  pDVar2 = (DOUBLE *)FUN_40805bf7(local_143c);
  local_8._0_1_ = 1;
  FUN_4080ebfe(local_141c,*pDVar2);
  local_8._0_1_ = 3;
  pOVar3 = (OLECHAR *)&stack0x00000028;
  if (7 < in_stack_0000003c) {
    pOVar3 = in_stack_00000028;
  }
  FUN_40802e40(&local_142c,pOVar3);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_4082bcaf(local_141c,(int *)&local_142c,0);
  local_1424 = (undefined1 *)SysStringLen(local_142c);
  local_1428 = 0;
  bVar9 = false;
  local_1420 = 0;
  uVar8 = 0;
  local_1438 = local_1438 & 0xffffff00;
  local_1430 = 0;
  if (0 < (int)local_1424) {
    do {
      uVar1 = local_1420;
      local_1c = 0;
      local_18 = 7;
      local_2c[0] = (wchar_t ***)((uint)local_2c[0] & 0xffff0000);
      sVar4 = _wcslen(L"\'");
      FID_conflict_assign(local_2c,(undefined8 *)&DAT_4084b994,sVar4);
      ppppwVar5 = local_2c;
      if (7 < local_18) {
        ppppwVar5 = (wchar_t ****)local_2c[0];
      }
      uStack_1468 = 0x40810536;
      uVar6 = FUN_40811716(&stack0x00000028,(wchar_t *)ppppwVar5,uVar1,local_1c);
      FUN_4080653d(local_2c,'\x01',0);
      puVar7 = local_1424;
      uVar1 = local_1430;
      if ((uVar6 != 0xffffffff) &&
         (bVar9 = bVar9 == false, puVar7 = (undefined1 *)uVar6, uVar1 = uVar6, bVar9)) {
        uVar8 = uVar6;
        uVar1 = local_1430;
      }
      local_1430 = uVar1;
      uStack_1468 = 0x4081057d;
      FUN_40811cd5(&stack0x00000028,local_44,local_1420,(int)puVar7 - local_1420);
      local_8._0_1_ = 5;
      basic_string<>(&stack0xffffeb88,(undefined8 *)&stack0x00000010);
      FUN_4081c793(param_1,param_2,local_1434,&local_1428);
      if ((bVar9 == false) && ((int)uVar8 < (int)local_1430)) {
        local_1428 = (local_1428 - 1) + (local_1430 - uVar8);
      }
      local_1420 = (int)puVar7 + 1;
      local_1438 = CONCAT31(local_1438._1_3_,bVar9);
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_4080653d(local_44,'\x01',0);
    } while ((int)puVar7 < (int)local_1424);
  }
  SysFreeString(local_142c);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4080d11c(local_141c);
  FUN_4080653d(&stack0x00000010,'\x01',0);
  FUN_4080653d(&stack0x00000028,'\x01',0);
  ExceptionList = local_10;
  FUN_4082d440(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


