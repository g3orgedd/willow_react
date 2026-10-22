// Source: CLCSSmallBarcode.dll @ 4200c21a; FUN_4200c21a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_4200c21a(void *this,HDC param_1,int *param_2,int *param_3,int *param_4,int param_5,int *param_6)

{
  int iVar1;
  int *piVar2;
  double dVar3;
  int iVar4;
  int iVar5;
  LONG LVar6;
  HDC pHVar7;
  tagSIZE local_74;
  int local_6c;
  int local_68;
  HDC local_64;
  int *local_60;
  tagTEXTMETRICW local_5c;
  int local_20 [6];
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  local_64 = param_1;
  local_68 = param_5;
  local_60 = param_6;
  if (param_2[10] == 0) goto LAB_4200c568;
  local_5c.tmHeight = 0;
  FUN_420698e0((uint *)&local_5c.tmAscent,0,0x38);
  if ((*(double *)(param_2 + 6) != DAT_4208a1a8) &&
     (iVar4 = (**(code **)*local_60)
                        (local_60,&local_64,*(undefined4 *)((int)this + 0x5c),
                         *(undefined4 *)((int)this + 0x60),*(undefined4 *)((int)this + 0x68),
                         *(undefined4 *)((int)this + 100),0,0,3,*(undefined4 *)((int)this + 0x10),
                         *(undefined4 *)((int)this + 0x14)), -1 < iVar4)) {
    GetTextMetricsW(local_64,&local_5c);
    (**(code **)(*local_60 + 4))(local_60,&local_64);
  }
  iVar4 = (**(code **)*local_60)
                    (local_60,&local_64,*(undefined4 *)((int)this + 0x5c),
                     *(undefined4 *)((int)this + 0x60),
                     (int)((double)*(int *)((int)this + 0x68) * *(double *)(param_2 + 6)),
                     *(undefined4 *)((int)this + 100),0,0,3,*(undefined4 *)((int)this + 0x10),
                     *(undefined4 *)((int)this + 0x14));
  if (iVar4 < 0) goto LAB_4200c568;
  *param_4 = 0;
  param_4[1] = 0;
  if ((*(int *)((int)this + 0x2c) == 0) || (*(int *)((int)this + 0x2c) == 0xb4)) {
    local_60 = *(int **)((int)this + 0x14);
  }
  else {
    local_60 = *(int **)((int)this + 0x10);
  }
  local_74.cx = 0;
  local_74.cy = 0;
  GetTextExtentExPointW
            (local_64,(LPCWSTR)(param_2 + 0xb),param_2[10],0,(LPINT)0x0,local_20,&local_74);
  dVar3 = DAT_42089808;
  if (param_2[9] == 0) {
    param_4[1] = *(int *)((int)this + 0xe8);
    if (*(double *)(param_2 + 6) == DAT_4208a1a8) {
      GetTextMetricsW(local_64,&local_5c);
    }
  }
  else {
    local_6c = 100;
    LVar6 = local_5c.tmHeight;
    if (*(double *)(param_2 + 6) == DAT_4208a1a8) {
      LVar6 = local_74.cy;
    }
    iVar4 = (int)((double)(param_2[2] * (int)local_60) + DAT_42089808);
    param_4[1] = iVar4;
    iVar4 = (param_2[3] * LVar6) / 100 + iVar4;
    param_4[1] = iVar4;
    if ((param_2[4] != 0) &&
       (iVar5 = *(int *)((int)this + 0xe8) * param_2[4] -
                (int)((double)(int)local_60 * _DAT_4208a898 + dVar3), iVar4 < iVar5)) {
      param_4[1] = iVar5;
    }
  }
  if (*(double *)(param_2 + 6) != DAT_4208a1a8) {
    param_4[1] = param_4[1] + local_5c.tmAscent;
    GetTextMetricsW(local_64,&local_5c);
    param_4[1] = param_4[1] - local_5c.tmAscent;
  }
  iVar5 = local_68;
  iVar4 = param_2[8];
  if (iVar4 == 0) {
    iVar4 = *(int *)((int)this + 0xf8) * *param_2;
LAB_4200c50d:
    *param_4 = iVar4;
  }
  else {
    if (iVar4 == 1) {
      iVar4 = (param_2[1] + *param_2) * *(int *)((int)this + 0xf8) - local_74.cx;
      goto LAB_4200c50d;
    }
    if (iVar4 == 2) {
      iVar4 = (*(int *)((int)this + 0xf8) * param_2[1] - local_74.cx) / 2;
      goto LAB_4200c50d;
    }
    if (iVar4 == 3) {
      *param_4 = *param_2 * *(int *)((int)this + 0xf8);
      local_64 = (HDC)(param_2[10] + -1);
      if (0 < (int)local_64) {
        local_6c = param_2[1] * *(int *)((int)this + 0xf8) - local_74.cx;
        local_60 = (int *)0x0;
        iVar4 = local_6c;
        pHVar7 = local_64;
        if (0 < (int)local_64) {
          do {
            if ((int)local_60 < 1) {
              local_68 = 0;
            }
            else {
              local_68 = local_20[(int)local_60 + -1];
            }
            piVar2 = local_20 + (int)local_60;
            iVar1 = (int)local_60 * 4;
            local_60 = (int *)((int)local_60 + 1);
            *(int *)(iVar5 + iVar1) = (*piVar2 - local_68) + iVar4 / (int)pHVar7;
            iVar4 = iVar4 - iVar4 / (int)pHVar7;
            pHVar7 = (HDC)((int)&pHVar7[-1].unused + 3);
          } while ((int)local_60 < (int)local_64);
        }
      }
    }
  }
  *param_4 = *param_4 + *(int *)((int)this + 0x84);
  if (param_2[9] == 1) {
    param_4[1] = param_4[1] + *(int *)((int)this + 0x88) + *(int *)((int)this + 0x78);
  }
  iVar4 = *param_2 * *(int *)((int)this + 0xf8) + *(int *)((int)this + 0x84);
  *param_3 = iVar4;
  param_3[2] = param_2[1] * *(int *)((int)this + 0xf8) + iVar4;
  param_3[1] = param_4[1];
  param_3[3] = param_4[1] + local_74.cy;
  FUN_4200c1f4(param_3);
LAB_4200c568:
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


