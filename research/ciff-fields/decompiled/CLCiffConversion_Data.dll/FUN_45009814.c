// Source: CLCiffConversion_Data.dll @ 45009814; FUN_45009814

undefined4 __cdecl FUN_45009814(int *param_1,int *param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  bool bVar4;
  UINT UVar5;
  UINT UVar6;
  uint uVar7;
  uint local_1c;
  uint local_18;
  uint local_10;
  int local_8;
  
  UVar5 = SysStringLen((BSTR)*param_2);
  UVar6 = SysStringLen((BSTR)*param_1);
  if ((UVar5 != 0) && (local_1c = 0, UVar6 != 0)) {
    do {
      if (UVar5 == 1) {
        if (*(short *)(*param_1 + local_1c * 2) != *(short *)*param_2) {
          return 1;
        }
      }
      else {
        bVar4 = false;
        uVar7 = 0;
        if (UVar5 == 0) {
          return 1;
        }
        local_10 = 2;
        local_18 = 1;
        local_8 = 4;
        do {
          if (bVar4) goto LAB_4500996c;
          if (local_18 < UVar5) {
            iVar3 = *param_2;
            sVar1 = *(short *)(iVar3 + 2 + uVar7 * 2);
            if (sVar1 == 0x2d) {
              if (UVar5 <= local_10) {
                return 0;
              }
              uVar2 = *(ushort *)(*param_1 + local_1c * 2);
              if ((*(ushort *)(iVar3 + uVar7 * 2) <= uVar2) &&
                 (uVar2 <= *(ushort *)(local_8 + iVar3))) {
                bVar4 = true;
              }
              uVar7 = uVar7 + 3;
              local_18 = local_18 + 3;
              local_10 = local_10 + 3;
              local_8 = local_8 + 6;
            }
            else {
              if (sVar1 != 0x2c) {
                return 0;
              }
              if (*(short *)(*param_1 + local_1c * 2) == *(short *)(iVar3 + uVar7 * 2)) {
                bVar4 = true;
              }
              uVar7 = uVar7 + 1;
              local_18 = local_18 + 1;
              local_10 = local_10 + 1;
              local_8 = local_8 + 2;
            }
          }
          else if (*(short *)(*param_1 + local_1c * 2) == *(short *)(*param_2 + uVar7 * 2)) {
            bVar4 = true;
          }
          local_8 = local_8 + 2;
          uVar7 = uVar7 + 1;
          local_18 = local_18 + 1;
          local_10 = local_10 + 1;
        } while (uVar7 < UVar5);
        if (!bVar4) {
          return 1;
        }
      }
LAB_4500996c:
      local_1c = local_1c + 1;
    } while (local_1c < UVar6);
  }
  return 0;
}


