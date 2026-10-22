// Source: CLCiffConversion_Data.dll @ 45037a27; FUN_45037a27

void __cdecl FUN_45037a27(char *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  bool bVar2;
  uint *puVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint local_10;
  uint local_c;
  
  puVar3 = param_3;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  if (param_2 != 0) {
    param_3 = (uint *)0x0;
    local_10 = 0;
    local_c = 0;
    do {
      uVar7 = *puVar3;
      uVar6 = puVar3[1];
      uVar10 = puVar3[2];
      uVar1 = local_10 * 4;
      uVar8 = ((int)param_3 * 2 | local_10 >> 0x1f) * 2 | (local_10 & 0x7fffffff) >> 0x1e;
      *puVar3 = uVar1;
      uVar11 = (local_c * 2 | (uint)param_3 >> 0x1f) * 2 | ((uint)param_3 & 0x7fffffff) >> 0x1e;
      puVar3[1] = uVar8;
      uVar5 = uVar7 + uVar1;
      puVar3[2] = uVar11;
      bVar2 = false;
      if ((uVar5 < uVar1) || (uVar5 < uVar7)) {
        bVar2 = true;
      }
      *puVar3 = uVar5;
      uVar7 = uVar8;
      if (bVar2) {
        bVar2 = false;
        uVar7 = uVar8 + 1;
        if ((uVar7 < uVar8) || (uVar7 == 0)) {
          bVar2 = true;
        }
        puVar3[1] = uVar7;
        if (bVar2) {
          uVar11 = uVar11 + 1;
          puVar3[2] = uVar11;
        }
      }
      bVar2 = false;
      uVar1 = uVar7 + uVar6;
      if ((uVar1 < uVar7) || (uVar1 < uVar6)) {
        bVar2 = true;
      }
      puVar3[1] = uVar1;
      if (bVar2) {
        uVar11 = uVar11 + 1;
        puVar3[2] = uVar11;
      }
      uVar7 = uVar5 * 2;
      puVar9 = (uint *)(uVar1 * 2 | uVar5 >> 0x1f);
      local_c = (uVar11 + uVar10) * 2 | uVar1 >> 0x1f;
      *puVar3 = uVar7;
      puVar3[1] = (uint)puVar9;
      puVar3[2] = local_c;
      local_10 = uVar7 + (int)*param_1;
      if ((local_10 < uVar7) || (local_10 < (uint)(int)*param_1)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      *puVar3 = local_10;
      param_3 = puVar9;
      if (bVar2) {
        bVar2 = false;
        param_3 = (uint *)((int)puVar9 + 1);
        if ((param_3 < puVar9) || (param_3 == (uint *)0x0)) {
          bVar2 = true;
        }
        puVar3[1] = (uint)param_3;
        if (bVar2) {
          local_c = local_c + 1;
          puVar3[2] = local_c;
        }
      }
      param_2 = param_2 + -1;
      puVar3[1] = (uint)param_3;
      param_1 = param_1 + 1;
      puVar3[2] = local_c;
    } while (param_2 != 0);
  }
  sVar4 = 0x404e;
  if (puVar3[2] == 0) {
    uVar7 = puVar3[1];
    sVar4 = 0x404e;
    do {
      uVar6 = uVar7 << 0x10 | *puVar3 >> 0x10;
      uVar10 = uVar7 >> 0x10;
      sVar4 = sVar4 + -0x10;
      *puVar3 = *puVar3 << 0x10;
      uVar7 = uVar6;
    } while (uVar10 == 0);
    puVar3[1] = uVar6;
    puVar3[2] = uVar10;
  }
  uVar7 = puVar3[2];
  if ((uVar7 & 0x8000) == 0) {
    uVar6 = *puVar3;
    uVar10 = puVar3[1];
    do {
      uVar5 = uVar10 * 2 | uVar6 >> 0x1f;
      uVar1 = uVar7 * 2;
      uVar7 = uVar1 | uVar10 >> 0x1f;
      sVar4 = sVar4 + -1;
      uVar6 = uVar6 * 2;
      uVar10 = uVar5;
    } while ((uVar1 & 0x8000) == 0);
    *puVar3 = uVar6;
    puVar3[1] = uVar5;
    puVar3[2] = uVar7;
  }
  *(short *)((int)puVar3 + 10) = sVar4;
  return;
}


