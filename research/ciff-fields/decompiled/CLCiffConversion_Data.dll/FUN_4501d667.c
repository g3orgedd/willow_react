// Source: CLCiffConversion_Data.dll @ 4501d667; FUN_4501d667

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_4501d667(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,uint *param_4)

{
  wchar_t wVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int *piVar7;
  double local_46c;
  int local_464;
  int local_460;
  int local_45c;
  int local_458;
  int local_454;
  int local_450;
  int local_44c;
  int local_448;
  int local_444;
  int local_440;
  int local_43c;
  int local_438;
  int local_434;
  int local_430;
  int local_42c;
  undefined4 *local_428;
  wchar_t *local_424;
  undefined4 *local_420;
  wchar_t *local_41c;
  WCHAR local_418 [256];
  WCHAR local_218 [264];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar2 = param_4;
  puVar5 = param_2;
  uStack_4 = 0x45c;
  local_428 = param_2;
  local_420 = param_3;
  local_8 = 1;
  local_424 = (wchar_t *)FUN_4501d466();
  if (local_424 == (wchar_t *)0x0) {
    puVar3 = FUN_4500403e(&param_1,&local_440,4,2);
    uVar4 = FUN_45022835((wchar_t *)*puVar3);
    *puVar5 = uVar4;
    FUN_45002256(&local_440);
    puVar5 = FUN_4500403e(&param_1,&local_448,2,2);
    uVar4 = FUN_45022835((wchar_t *)*puVar5);
    *local_420 = uVar4;
    FUN_45002256(&local_448);
    puVar5 = FUN_45003e81(&param_1,&local_450,2);
    uVar6 = FUN_45022835((wchar_t *)*puVar5);
    piVar7 = &local_450;
  }
  else if (local_424 == (wchar_t *)0x1) {
    puVar3 = FUN_45003e81(&param_1,&local_44c,2);
    uVar4 = FUN_45022835((wchar_t *)*puVar3);
    *puVar5 = uVar4;
    FUN_45002256(&local_44c);
    puVar5 = FUN_4500403e(&param_1,&local_430,2,2);
    uVar4 = FUN_45022835((wchar_t *)*puVar5);
    *local_420 = uVar4;
    FUN_45002256(&local_430);
    puVar5 = FUN_4500403e(&param_1,&local_438,4,2);
    uVar6 = FUN_45022835((wchar_t *)*puVar5);
    piVar7 = &local_438;
  }
  else if (local_424 == (wchar_t *)0x2) {
    puVar3 = FUN_4500403e(&param_1,&local_42c,2,2);
    uVar4 = FUN_45022835((wchar_t *)*puVar3);
    *puVar5 = uVar4;
    FUN_45002256(&local_42c);
    puVar5 = FUN_45003e81(&param_1,&local_444,2);
    uVar4 = FUN_45022835((wchar_t *)*puVar5);
    *local_420 = uVar4;
    FUN_45002256(&local_444);
    puVar5 = FUN_4500403e(&param_1,&local_458,4,2);
    uVar6 = FUN_45022835((wchar_t *)*puVar5);
    piVar7 = &local_458;
  }
  else if (local_424 == (wchar_t *)0x3) {
    puVar3 = FUN_45003e81(&param_1,&local_434,2);
    uVar4 = FUN_45022835((wchar_t *)*puVar3);
    *puVar5 = uVar4;
    FUN_45002256(&local_434);
    puVar5 = FUN_4500403e(&param_1,&local_45c,2,2);
    uVar4 = FUN_45022835((wchar_t *)*puVar5);
    *local_420 = uVar4;
    FUN_45002256(&local_45c);
    puVar5 = FUN_4500403e(&param_1,&local_43c,4,4);
    uVar6 = FUN_45022835((wchar_t *)*puVar5);
    piVar7 = &local_43c;
  }
  else {
    if (local_424 != (wchar_t *)0x4) {
      FUN_45002256(&param_1);
      FUN_45022ec7();
      return;
    }
    puVar3 = FUN_4500403e(&param_1,&local_454,6,2);
    uVar4 = FUN_45022835((wchar_t *)*puVar3);
    *puVar5 = uVar4;
    FUN_45002256(&local_454);
    puVar5 = FUN_4500403e(&param_1,&local_464,4,2);
    uVar4 = FUN_45022835((wchar_t *)*puVar5);
    *local_420 = uVar4;
    FUN_45002256(&local_464);
    puVar5 = FUN_45003e81(&param_1,&local_460,4);
    uVar6 = FUN_45022835((wchar_t *)*puVar5);
    piVar7 = &local_460;
  }
  *puVar2 = uVar6;
  FUN_45002256(piVar7);
  if (local_424 < (wchar_t *)0x3) {
    FUN_450040a4(&local_46c);
    uVar6 = FUN_4501e220(&local_46c);
    FUN_45023625(uVar6,local_218,0x100,10);
    FUN_450020a5(&local_41c,local_218);
    local_8._0_1_ = 2;
    FUN_45023625(*puVar2,local_418,0x100,10);
    FUN_450020a5(&local_424,local_418);
    local_8 = CONCAT31(local_8._1_3_,3);
    if (*(int *)(local_424 + -4) == 1) {
      wVar1 = *local_424;
      FUN_4500363c((int *)&local_41c);
      local_41c[3] = wVar1;
      FUN_4500363c((int *)&local_41c);
      local_41c[2] = L'0';
    }
    else if (*(int *)(local_424 + -4) == 2) {
      wVar1 = local_424[1];
      FUN_4500363c((int *)&local_41c);
      local_41c[3] = wVar1;
      wVar1 = *local_424;
      FUN_4500363c((int *)&local_41c);
      local_41c[2] = wVar1;
    }
    uVar6 = __wtol(local_41c);
    *puVar2 = uVar6;
    FUN_45002256((int *)&local_424);
    FUN_45002256((int *)&local_41c);
  }
  FUN_4501da5f();
  return;
}


