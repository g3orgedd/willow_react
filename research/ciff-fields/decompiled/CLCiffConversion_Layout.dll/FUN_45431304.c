// Source: CLCiffConversion_Layout.dll @ 45431304; FUN_45431304

int __cdecl
FUN_45431304(int *param_1,undefined1 *param_2,uint param_3,uint param_4,int param_5,int *param_6)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  undefined1 (*pauVar4) [16];
  uint *puVar5;
  uint uVar6;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint *puVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  int iVar13;
  int local_30 [2];
  int local_28;
  char local_24;
  uint local_1c;
  int local_18;
  int local_14;
  uint *local_10;
  uint local_c;
  int local_8;
  
  local_c = 0x3ff;
  local_8 = 0x30;
  FUN_4542c8eb(local_30,param_6);
  if ((int)param_4 < 0) {
    param_4 = 0;
  }
  if ((param_2 == (undefined1 *)0x0) || (param_3 == 0)) {
    piVar2 = __errno();
    iVar13 = 0x16;
  }
  else {
    *param_2 = 0;
    if (param_4 + 0xb < param_3) {
      local_18 = *param_1;
      if (((uint)param_1[1] >> 0x14 & 0x7ff) == 0x7ff) {
        uVar3 = 0xffffffff;
        if (param_3 != 0xffffffff) {
          uVar3 = param_3 - 2;
        }
        iVar13 = FUN_45431660(param_1,param_2 + 2,uVar3,param_4,0);
        if (iVar13 == 0) {
          if (param_2[2] == '-') {
            *param_2 = 0x2d;
            param_2 = param_2 + 1;
          }
          *param_2 = 0x30;
          param_2[1] = ((param_5 == 0) - 1U & 0xe0) + 0x78;
          pauVar4 = FUN_4543af50((undefined1 (*) [16])(param_2 + 2),0x65);
          if (pauVar4 != (undefined1 (*) [16])0x0) {
            (*pauVar4)[0] = ((param_5 == 0) - 1U & 0xe0) + 0x70;
            (*pauVar4)[3] = 0;
          }
          iVar13 = 0;
        }
        else {
          *param_2 = 0;
        }
        goto LAB_4543164a;
      }
      if ((param_1[1] & 0x80000000U) != 0) {
        *param_2 = 0x2d;
        param_2 = param_2 + 1;
      }
      *param_2 = 0x30;
      param_2[1] = ((param_5 == 0) - 1U & 0xe0) + 0x78;
      iVar13 = (-(uint)(param_5 != 0) & 0xffffffe0) + 0x27;
      if ((param_1[1] & 0x7ff00000U) == 0) {
        param_2[2] = 0x30;
        if (*param_1 == 0 && (param_1[1] & 0xfffffU) == 0) {
          local_c = 0;
        }
        else {
          local_c = 0x3fe;
        }
      }
      else {
        param_2[2] = 0x31;
      }
      local_10 = (uint *)(param_2 + 3);
      puVar7 = (uint *)(param_2 + 4);
      if (param_4 == 0) {
        *(char *)local_10 = '\0';
      }
      else {
        *(char *)local_10 = *(char *)**(undefined4 **)(local_30[0] + 0x84);
      }
      local_1c = param_1[1] & 0xfffff;
      local_14 = iVar13;
      if ((local_1c != 0) || (*param_1 != 0)) {
        param_2 = (undefined1 *)0xf0000;
        do {
          if ((int)param_4 < 1) break;
          uVar11 = __aullshr((byte)local_8,param_1[1] & (uint)param_2);
          uVar3 = (uint)(ushort)((short)uVar11 + 0x30);
          if (0x39 < uVar3) {
            uVar3 = uVar3 + iVar13;
          }
          *(char *)puVar7 = (char)uVar3;
          puVar7 = (uint *)((int)puVar7 + 1);
          param_2 = (undefined1 *)((uint)param_2 >> 4);
          local_8 = local_8 + -4;
          param_4 = param_4 - 1;
        } while (-1 < (short)local_8);
        if ((-1 < (short)local_8) &&
           (uVar11 = __aullshr((byte)local_8,param_1[1] & (uint)param_2), puVar1 = puVar7,
           8 < (ushort)uVar11)) {
          while( true ) {
            puVar5 = (uint *)((int)puVar1 + -1);
            if ((*(char *)puVar5 != 'f') && (*(char *)puVar5 != 'F')) break;
            *(char *)puVar5 = '0';
            puVar1 = puVar5;
          }
          if (puVar5 == local_10) {
            *(char *)((int)puVar1 + -2) = *(char *)((int)puVar1 + -2) + '\x01';
          }
          else if (*(char *)puVar5 == '9') {
            *(char *)puVar5 = (char)local_14 + ':';
          }
          else {
            *(char *)puVar5 = *(char *)puVar5 + '\x01';
          }
        }
      }
      if (0 < (int)param_4) {
        FUN_45429f70(puVar7,0x30,param_4);
        puVar7 = (uint *)((int)puVar7 + param_4);
      }
      if ((char)*local_10 == '\0') {
        puVar7 = local_10;
      }
      *(byte *)puVar7 = ((param_5 == 0) - 1U & 0xe0) + 0x70;
      uVar11 = __aullshr(0x34,param_1[1]);
      uVar3 = (uint)(uVar11 & 0x7ff);
      uVar6 = uVar3 - local_c;
      uVar3 = -(uint)(uVar3 < local_c);
      if ((int)uVar3 < 0) {
        *(char *)((int)puVar7 + 1) = '-';
        bVar10 = uVar6 != 0;
        uVar6 = -uVar6;
        uVar3 = -(uVar3 + bVar10);
      }
      else {
        *(char *)((int)puVar7 + 1) = '+';
      }
      pcVar8 = (char *)((int)puVar7 + 2);
      *pcVar8 = '0';
      pcVar9 = pcVar8;
      if (-1 < (int)uVar3) {
        if (((int)uVar3 < 1) && (uVar6 < 1000)) {
LAB_454315fb:
          if (((int)uVar3 < 0) || (((int)uVar3 < 1 && (uVar6 < 100)))) goto LAB_4543161a;
        }
        else {
          uVar12 = __alldvrm(uVar6,uVar3,1000,0);
          local_1c = (uint)((ulonglong)uVar12 >> 0x20);
          *pcVar8 = (char)uVar12 + '0';
          pcVar9 = (char *)((int)puVar7 + 3);
          uVar6 = extraout_ECX;
          if (pcVar9 == pcVar8) goto LAB_454315fb;
        }
        uVar12 = __alldvrm(uVar6,uVar3,100,0);
        local_1c = (uint)((ulonglong)uVar12 >> 0x20);
        *pcVar9 = (char)uVar12 + '0';
        pcVar9 = pcVar9 + 1;
        uVar6 = extraout_ECX_00;
      }
LAB_4543161a:
      if ((pcVar9 != pcVar8) || ((-1 < (int)uVar3 && ((0 < (int)uVar3 || (9 < uVar6)))))) {
        uVar12 = __alldvrm(uVar6,uVar3,10,0);
        *pcVar9 = (char)uVar12 + '0';
        pcVar9 = pcVar9 + 1;
        uVar6 = extraout_ECX_01;
      }
      iVar13 = 0;
      *pcVar9 = (char)uVar6 + '0';
      pcVar9[1] = '\0';
      goto LAB_4543164a;
    }
    piVar2 = __errno();
    iVar13 = 0x22;
  }
  *piVar2 = iVar13;
  FUN_45432798();
LAB_4543164a:
  if (local_24 != '\0') {
    *(uint *)(local_28 + 0x70) = *(uint *)(local_28 + 0x70) & 0xfffffffd;
  }
  return iVar13;
}


