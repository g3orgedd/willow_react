// Source: CLCiffConversion_Data.dll @ 450163ae; FUN_450163ae

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_450163ae(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  ulong uVar2;
  char cVar3;
  undefined4 *puVar4;
  int *piVar5;
  long lVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *local_14;
  ulong local_10;
  int *local_c;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if (param_2 == (undefined4 *)0x0) goto LAB_450164ef;
  *param_2 = 0;
  puVar4 = (undefined4 *)FUN_45025ad0(0x1c);
  if (puVar4 == (undefined4 *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = FUN_450145f7(puVar4);
  }
  if (piVar5 == (int *)0x0) goto LAB_450164ef;
  local_10 = 0;
  local_14 = (int *)0x0;
  local_c = (int *)0x0;
  lVar6 = ATL::AtlMultiply<unsigned_long>(&local_10,4,0);
  uVar2 = local_10;
  if (lVar6 < 0) {
LAB_450164d5:
    puVar4 = (undefined4 *)*piVar5;
LAB_450164d7:
    (*(code *)puVar4[7])(1);
  }
  else {
    if ((local_10 < 0x401) && (cVar3 = FUN_45018921(local_10), cVar3 != '\0')) {
      piVar7 = (int *)&stack0xffffffe4;
    }
    else {
      piVar7 = FUN_450151d2(&local_c,uVar2);
      local_14 = local_c;
    }
    if (piVar7 == (int *)0x0) {
      (**(code **)(*piVar5 + 0x1c))(1);
    }
    else {
      iVar9 = *(int *)PTR_DAT_45051038;
      piVar1 = piVar7;
      piVar8 = (int *)PTR_DAT_45051038;
      while (iVar9 != -1) {
        if (iVar9 == -2) {
          local_c = piVar1;
          piVar8 = (int *)(*(code *)piVar8[1])(0);
        }
        else {
          *piVar1 = iVar9 + (int)param_1;
          local_c = piVar1 + 1;
          piVar8 = piVar8 + 1;
        }
        piVar1 = local_c;
        iVar9 = *piVar8;
      }
      iVar9 = FUN_45016b04(piVar5,piVar7,piVar7,param_1,3);
      puVar4 = (undefined4 *)*piVar5;
      if (iVar9 < 0) goto LAB_450164d7;
      iVar9 = (*(code *)*puVar4)(piVar5,&DAT_4503fd9c,param_2);
      if (iVar9 < 0) goto LAB_450164d5;
    }
  }
  while (local_14 != (int *)0x0) {
    piVar5 = (int *)*local_14;
    FID_conflict__free(local_14);
    local_14 = piVar5;
  }
LAB_450164ef:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


