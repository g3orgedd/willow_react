// Source: CLCiffConversion_Data.dll @ 4502e390; __handle_exc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __handle_exc
   
   Library: Visual Studio 2019 Release */

bool __cdecl __handle_exc(uint param_1,double *param_2,uint param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  float10 fVar8;
  float10 fVar9;
  uint local_10;
  byte bStack_c;
  undefined1 uStack_b;
  ushort uStack_a;
  
  uVar4 = param_1;
  uVar6 = param_1 & 0x1f;
  if (((param_1 & 8) != 0) && ((param_3 & 1) != 0)) {
    FUN_4502ea43();
    uVar6 = uVar4 & 0x17;
    goto LAB_4502e54b;
  }
  if (((param_1 & 4) != 0) && ((param_3 & 4) != 0)) {
    FUN_4502ea43();
    uVar6 = uVar4 & 0x1b;
    goto LAB_4502e54b;
  }
  if (((param_1 & 1) == 0) || ((param_3 & 8) == 0)) {
    if (((param_1 & 2) != 0) && ((param_3 & 0x10) != 0)) {
      bVar7 = (param_1 & 0x10) != 0;
      if (*param_2 == 0.0) {
        bVar7 = true;
      }
      else {
        fVar8 = (float10)FUN_4502e13a(SUB84(*param_2,0),(uint)((ulonglong)*param_2 >> 0x20),
                                      (int *)&param_1);
        param_1 = param_1 - 0x600;
        dVar2 = (double)fVar8;
        local_10 = SUB84(dVar2,0);
        bStack_c = (byte)((ulonglong)dVar2 >> 0x20);
        uStack_b = (undefined1)((ulonglong)dVar2 >> 0x28);
        uStack_a = (ushort)((ulonglong)dVar2 >> 0x30);
        if ((int)param_1 < -0x432) {
          fVar9 = (float10)0 * fVar8;
          bVar7 = true;
        }
        else {
          uStack_a = uStack_a & 0xf | 0x10;
          if ((int)param_1 < -0x3fd) {
            iVar5 = -0x3fd - param_1;
            do {
              if (((local_10 & 1) != 0) && (!bVar7)) {
                bVar7 = true;
              }
              local_10 = local_10 >> 1;
              if ((bStack_c & 1) != 0) {
                local_10 = local_10 | 0x80000000;
              }
              uVar6 = CONCAT22(uStack_a,CONCAT11(uStack_b,bStack_c)) >> 1;
              bStack_c = (byte)uVar6;
              uStack_b = (undefined1)(uVar6 >> 8);
              uStack_a = uStack_a >> 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          fVar9 = (float10)(double)CONCAT26(uStack_a,CONCAT15(uStack_b,CONCAT14(bStack_c,local_10)))
          ;
          if (fVar8 < (float10)0) {
            fVar9 = -fVar9;
          }
        }
        *param_2 = (double)fVar9;
      }
      if (bVar7) {
        FUN_4502ea43();
      }
      uVar6 = uVar4 & 0x1d;
    }
    goto LAB_4502e54b;
  }
  FUN_4502ea43();
  uVar6 = param_3 & 0xc00;
  dVar2 = _DAT_45052228;
  dVar3 = _DAT_45052228;
  if (uVar6 == 0) {
    dVar1 = *param_2;
joined_r0x4502e431:
    if (dVar1 <= 0.0) {
      dVar2 = -dVar3;
    }
    *param_2 = dVar2;
  }
  else {
    if (uVar6 == 0x400) {
      dVar1 = *param_2;
      dVar2 = _DAT_45052238;
      goto joined_r0x4502e431;
    }
    dVar3 = _DAT_45052238;
    if (uVar6 == 0x800) {
      dVar1 = *param_2;
      goto joined_r0x4502e431;
    }
    if (uVar6 == 0xc00) {
      dVar1 = *param_2;
      dVar2 = _DAT_45052238;
      goto joined_r0x4502e431;
    }
  }
  uVar6 = uVar4 & 0x1e;
LAB_4502e54b:
  if (((uVar4 & 0x10) != 0) && ((param_3 & 0x20) != 0)) {
    FUN_4502ea43();
    uVar6 = uVar6 & 0xffffffef;
  }
  return uVar6 == 0;
}


