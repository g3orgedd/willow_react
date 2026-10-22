// Source: CLCiffConversion_Layout.dll @ 4540cb87; FUN_4540cb87

void __thiscall FUN_4540cb87(void *this,int *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint local_8;
  
  piVar3 = param_2;
  param_2[1] = *param_2;
  if (*(char *)((int)this + 0x128) == '\0') {
    FUN_4540d5f2(param_2,1);
    *(int *)*param_2 = *param_1;
    *(int *)(*param_2 + 4) = param_1[1];
    return;
  }
  iVar4 = *param_1 - *(int *)((int)this + 0x100) >> 1;
  uVar5 = ((*(int **)((int)this + 0x124))[1] - **(int **)((int)this + 0x124)) / 0xc;
  uVar8 = 0;
  local_8 = 1;
  *param_3 = 0;
  uVar10 = 1;
  if (uVar5 != 0) {
    iVar9 = 0;
    do {
      iVar6 = *(int *)(**(int **)((int)this + 0x124) + iVar9) - iVar4;
      if (iVar6 < 1) {
        *param_3 = uVar8;
      }
      else if (iVar6 < param_1[1]) {
        local_8 = local_8 + 1;
      }
      uVar8 = uVar8 + 1;
      iVar9 = iVar9 + 0xc;
      uVar10 = local_8;
    } while (uVar8 < uVar5);
  }
  FUN_4540d5f2(param_2,uVar10);
  param_2 = (int *)(uVar10 * 8 + -8);
  iVar9 = *param_1 + param_1[1] * 2;
  uVar5 = uVar5 - 1;
  iVar6 = uVar5 * 0xc;
  do {
    iVar2 = *(int *)(**(int **)((int)this + 0x124) + iVar6);
    iVar7 = iVar2 - iVar4;
    if ((iVar7 < 1) || (param_1[1] <= iVar7)) {
      if (uVar5 == *param_3) {
        *(int *)*piVar3 = *param_1;
        *(int *)(*piVar3 + 4) = iVar9 - *param_1 >> 1;
        return;
      }
    }
    else {
      *(int *)((int)param_2 + *piVar3) = *(int *)((int)this + 0x100) + iVar2 * 2;
      *(int *)((int)param_2 + *piVar3 + 4) = iVar9 - *(int *)((int)param_2 + *piVar3) >> 1;
      piVar1 = (int *)((int)param_2 + *piVar3 + 4);
      param_2 = param_2 + -2;
      iVar9 = iVar9 + *piVar1 * -2;
    }
    uVar5 = uVar5 - 1;
    iVar6 = iVar6 + -0xc;
  } while( true );
}


