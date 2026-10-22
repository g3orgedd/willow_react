// Source: CLCiffConversion_Layout.dll @ 45431d41; FUN_45431d41

uint __cdecl FUN_45431d41(int *param_1,byte *param_2,undefined4 *param_3,uint param_4,uint param_5)

{
  byte *pbVar1;
  ushort uVar2;
  int *piVar3;
  undefined2 extraout_var;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  byte *pbVar8;
  int local_28 [2];
  int local_20;
  char local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  byte local_5;
  
  FUN_4542c8eb(local_28,param_1);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = param_2;
  }
  if ((param_2 == (byte *)0x0) || ((param_4 != 0 && (((int)param_4 < 2 || (0x24 < (int)param_4))))))
  {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_45432798();
  }
  else {
    local_10 = 0;
    bVar7 = *param_2;
    iVar6 = local_28[0];
    pbVar1 = param_2;
    while( true ) {
      pbVar8 = pbVar1 + 1;
      if (*(int *)(iVar6 + 0x74) < 2) {
        uVar4 = *(ushort *)(*(int *)(iVar6 + 0x90) + (uint)bVar7 * 2) & 8;
      }
      else {
        uVar2 = FUN_454344e5((uint)bVar7,8,local_28);
        uVar4 = CONCAT22(extraout_var,uVar2);
        iVar6 = local_28[0];
      }
      if (uVar4 == 0) break;
      bVar7 = *pbVar8;
      pbVar1 = pbVar8;
    }
    if (bVar7 == 0x2d) {
      param_5 = param_5 | 2;
LAB_45431ddf:
      bVar7 = *pbVar8;
      pbVar8 = pbVar1 + 2;
    }
    else if (bVar7 == 0x2b) goto LAB_45431ddf;
    if (((-1 < (int)param_4) && (param_4 != 1)) && ((int)param_4 < 0x25)) {
      local_5 = bVar7;
      if (param_4 == 0) {
        if (bVar7 != 0x30) {
          param_4 = 10;
          goto LAB_45431e50;
        }
        if ((*pbVar8 != 0x78) && (*pbVar8 != 0x58)) {
          param_4 = 8;
          goto LAB_45431e50;
        }
        param_4 = 0x10;
      }
      else if ((param_4 != 0x10) || (bVar7 != 0x30)) goto LAB_45431e50;
      if ((*pbVar8 == 0x78) || (*pbVar8 == 0x58)) {
        pbVar1 = pbVar8 + 1;
        pbVar8 = pbVar8 + 2;
        local_5 = *pbVar1;
      }
LAB_45431e50:
      uVar4 = (uint)(0xffffffff / (ulonglong)param_4);
      local_14 = (uint)(0xffffffff % (ulonglong)param_4);
      local_18 = *(int *)(local_28[0] + 0x90);
      do {
        uVar2 = *(ushort *)(local_18 + (uint)local_5 * 2);
        if ((uVar2 & 4) == 0) {
          if ((uVar2 & 0x103) == 0) goto LAB_45431ed1;
          iVar6 = (int)(char)local_5;
          if ((byte)(local_5 + 0x9f) < 0x1a) {
            iVar6 = iVar6 + -0x20;
          }
          uVar5 = iVar6 - 0x37;
        }
        else {
          uVar5 = (int)(char)local_5 - 0x30;
        }
        if (param_4 <= uVar5) goto LAB_45431ed1;
        if ((local_10 < uVar4) || ((local_10 == uVar4 && (uVar5 <= local_14)))) {
          local_10 = local_10 * param_4 + uVar5;
          param_5 = param_5 | 8;
        }
        else {
          param_5 = param_5 | 0xc;
          if (param_3 == (undefined4 *)0x0) goto LAB_45431ed1;
        }
        local_5 = *pbVar8;
        pbVar8 = pbVar8 + 1;
      } while( true );
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = param_2;
    }
  }
  local_10 = 0;
LAB_45431f51:
  if (local_1c != '\0') {
    *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
  }
  return local_10;
LAB_45431ed1:
  pbVar8 = pbVar8 + -1;
  if ((param_5 & 8) == 0) {
    if (param_3 != (undefined4 *)0x0) {
      pbVar8 = param_2;
    }
    local_10 = 0;
  }
  else if (((param_5 & 4) != 0) ||
          (((param_5 & 1) == 0 &&
           ((((param_5 & 2) != 0 && (0x80000000 < local_10)) ||
            (((param_5 & 2) == 0 && (0x7fffffff < local_10)))))))) {
    local_10 = uVar4;
    local_c = param_5;
    piVar3 = __errno();
    *piVar3 = 0x22;
    param_5 = local_c;
    if ((local_c & 1) == 0) {
      local_10 = ((local_c & 2) != 0) + 0x7fffffff;
    }
    else {
      local_10 = 0xffffffff;
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = pbVar8;
  }
  if ((param_5 & 2) != 0) {
    local_10 = -local_10;
  }
  goto LAB_45431f51;
}


