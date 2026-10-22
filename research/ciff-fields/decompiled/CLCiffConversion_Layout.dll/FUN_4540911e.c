// Source: CLCiffConversion_Layout.dll @ 4540911e; FUN_4540911e

void __fastcall FUN_4540911e(int *param_1)

{
  short sVar1;
  UINT UVar2;
  uint uVar3;
  uint uVar4;
  UINT UVar5;
  UINT UVar6;
  int iVar7;
  int iStackY_10;
  
  UVar2 = SysStringLen((BSTR)*param_1);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  iVar7 = UVar2 - 1;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (UVar2 != 0) {
    iStackY_10 = 0;
    do {
      UVar6 = UVar2 - 1;
      if ((UVar6 == 0) && (iStackY_10 == 0)) {
        iStackY_10 = 1;
      }
      if (iStackY_10 == 0) {
        if (*(short *)(*param_1 + UVar6 * 2) == 0x2e) {
          param_1[6] = UVar2;
          uVar4 = (iVar7 - UVar6) + 1;
          iVar7 = UVar2 - 2;
          uVar3 = 0xff;
          if (uVar4 < 0xff) {
            uVar3 = uVar4;
          }
          param_1[7] = uVar3;
          iStackY_10 = 1;
        }
LAB_454091f3:
        sVar1 = *(short *)(*param_1 + UVar6 * 2);
        if (((sVar1 == 0x5c) || (sVar1 == 0x2f)) || (UVar6 == 0)) {
          iStackY_10 = 2;
          uVar3 = ((UVar6 == 0) - UVar6) + iVar7;
          uVar4 = 0xff;
          if (uVar3 < 0xff) {
            uVar4 = uVar3;
          }
          param_1[5] = uVar4;
          UVar5 = UVar6;
          if (UVar6 != 0) {
            UVar5 = UVar2;
          }
          param_1[4] = UVar5;
LAB_45409230:
          iVar7 = UVar2 - 2;
        }
      }
      else {
        if (iStackY_10 == 1) goto LAB_454091f3;
        if (iStackY_10 == 2) {
          if ((*(short *)(*param_1 + UVar6 * 2) != 0x3a) && (UVar6 != 0)) goto LAB_45409236;
          iStackY_10 = 3;
          uVar3 = ((UVar6 == 0) - UVar6) + iVar7;
          uVar4 = 0xff;
          if (uVar3 < 0xff) {
            uVar4 = uVar3;
          }
          param_1[3] = uVar4;
          UVar5 = UVar6;
          if (UVar6 != 0) {
            UVar5 = UVar2;
          }
          param_1[2] = UVar5;
          goto LAB_45409230;
        }
        if ((iStackY_10 == 3) && (UVar6 == 0)) {
          uVar4 = 2;
          if (iVar7 + 1U < 2) {
            uVar4 = iVar7 + 1U;
          }
          param_1[1] = uVar4;
        }
      }
LAB_45409236:
      UVar2 = UVar6;
    } while (UVar6 != 0);
  }
  return;
}


