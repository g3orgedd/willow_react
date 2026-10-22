// Source: CLARiSOFT.exe @ 00eca603; FUN_00eca603

int __cdecl FUN_00eca603(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 == 0) {
    return 0;
  }
  if (param_3 == 1) {
    uVar3 = (uint)(byte)*param_1;
    uVar1 = (uint)(byte)*param_2;
LAB_00ecbc50:
    if (uVar3 == uVar1) {
      return 0;
    }
    return (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
  }
  if (param_3 == 2) {
    uVar3 = (uint)(byte)*param_1;
    uVar1 = (uint)(byte)*param_2;
    if ((uVar3 != uVar1) &&
       (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
      return iVar2;
    }
    uVar3 = (uint)*(byte *)((int)param_1 + 1);
    uVar1 = (uint)*(byte *)((int)param_2 + 1);
    goto LAB_00ecbc50;
  }
  if (param_3 == 3) {
    uVar3 = (uint)(byte)*param_1;
    uVar1 = (uint)(byte)*param_2;
    if ((uVar3 != uVar1) &&
       (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
      return iVar2;
    }
    uVar3 = (uint)*(byte *)((int)param_1 + 1);
    uVar1 = (uint)*(byte *)((int)param_2 + 1);
    if ((uVar3 != uVar1) &&
       (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
      return iVar2;
    }
    uVar3 = (uint)*(byte *)((int)param_1 + 2);
    uVar1 = (uint)*(byte *)((int)param_2 + 2);
    goto LAB_00ecbc50;
  }
  if (param_3 == 4) {
    uVar1 = (uint)(byte)*param_2;
    uVar3 = (uint)(byte)*param_1;
    if ((uVar3 != uVar1) &&
       (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
      return iVar2;
    }
    uVar3 = (uint)*(byte *)((int)param_1 + 1);
    uVar1 = (uint)*(byte *)((int)param_2 + 1);
    if ((uVar3 != uVar1) &&
       (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
      return iVar2;
    }
    uVar3 = (uint)*(byte *)((int)param_1 + 2);
    uVar1 = (uint)*(byte *)((int)param_2 + 2);
    if ((uVar3 != uVar1) &&
       (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
      return iVar2;
    }
    uVar3 = (uint)*(byte *)((int)param_1 + 3);
    uVar1 = (uint)*(byte *)((int)param_2 + 3);
    goto LAB_00ecbc50;
  }
  for (; 0x1f < param_3; param_3 = param_3 - 0x20) {
    if (*param_1 == *param_2) {
      iVar2 = 0;
    }
    else {
      uVar3 = *param_1 & 0xff;
      uVar1 = (uint)(byte)*param_2;
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 1);
      uVar1 = (uint)*(byte *)((int)param_2 + 1);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 2);
      uVar1 = (uint)*(byte *)((int)param_2 + 2);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      iVar2 = 0;
      if ((uint)*(byte *)((int)param_1 + 3) != (uint)*(byte *)((int)param_2 + 3)) {
        iVar2 = (uint)(0 < (int)((uint)*(byte *)((int)param_1 + 3) -
                                (uint)*(byte *)((int)param_2 + 3))) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_1[1] == param_2[1]) {
      iVar2 = 0;
    }
    else {
      uVar3 = param_1[1] & 0xff;
      uVar1 = (uint)(byte)param_2[1];
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 5);
      uVar1 = (uint)*(byte *)((int)param_2 + 5);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 6);
      uVar1 = (uint)*(byte *)((int)param_2 + 6);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      iVar2 = 0;
      if ((uint)*(byte *)((int)param_1 + 7) != (uint)*(byte *)((int)param_2 + 7)) {
        iVar2 = (uint)(0 < (int)((uint)*(byte *)((int)param_1 + 7) -
                                (uint)*(byte *)((int)param_2 + 7))) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_1[2] == param_2[2]) {
      iVar2 = 0;
    }
    else {
      uVar3 = param_1[2] & 0xff;
      uVar1 = (uint)(byte)param_2[2];
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 9);
      uVar1 = (uint)*(byte *)((int)param_2 + 9);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 10);
      uVar1 = (uint)*(byte *)((int)param_2 + 10);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      iVar2 = 0;
      if ((uint)*(byte *)((int)param_1 + 0xb) != (uint)*(byte *)((int)param_2 + 0xb)) {
        iVar2 = (uint)(0 < (int)((uint)*(byte *)((int)param_1 + 0xb) -
                                (uint)*(byte *)((int)param_2 + 0xb))) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_1[3] == param_2[3]) {
      iVar2 = 0;
    }
    else {
      uVar3 = param_1[3] & 0xff;
      uVar1 = (uint)(byte)param_2[3];
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 0xd);
      uVar1 = (uint)*(byte *)((int)param_2 + 0xd);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 0xe);
      uVar1 = (uint)*(byte *)((int)param_2 + 0xe);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      iVar2 = 0;
      if ((uint)*(byte *)((int)param_1 + 0xf) != (uint)*(byte *)((int)param_2 + 0xf)) {
        iVar2 = (uint)(0 < (int)((uint)*(byte *)((int)param_1 + 0xf) -
                                (uint)*(byte *)((int)param_2 + 0xf))) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_1[4] == param_2[4]) {
      iVar2 = 0;
    }
    else {
      uVar1 = (uint)(byte)param_2[4];
      uVar3 = (uint)(byte)param_1[4];
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 0x11);
      uVar1 = (uint)*(byte *)((int)param_2 + 0x11);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 0x12);
      uVar1 = (uint)*(byte *)((int)param_2 + 0x12);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      iVar2 = 0;
      if ((uint)*(byte *)((int)param_1 + 0x13) != (uint)*(byte *)((int)param_2 + 0x13)) {
        iVar2 = (uint)(0 < (int)((uint)*(byte *)((int)param_1 + 0x13) -
                                (uint)*(byte *)((int)param_2 + 0x13))) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_1[5] == param_2[5]) {
      iVar2 = 0;
    }
    else {
      uVar3 = param_1[5] & 0xff;
      uVar1 = (uint)(byte)param_2[5];
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 0x15);
      uVar1 = (uint)*(byte *)((int)param_2 + 0x15);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 0x16);
      uVar1 = (uint)*(byte *)((int)param_2 + 0x16);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      iVar2 = 0;
      if ((uint)*(byte *)((int)param_1 + 0x17) != (uint)*(byte *)((int)param_2 + 0x17)) {
        iVar2 = (uint)(0 < (int)((uint)*(byte *)((int)param_1 + 0x17) -
                                (uint)*(byte *)((int)param_2 + 0x17))) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_1[6] == param_2[6]) {
      iVar2 = 0;
    }
    else {
      uVar3 = param_1[6] & 0xff;
      uVar1 = (uint)(byte)param_2[6];
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 0x19);
      uVar1 = (uint)*(byte *)((int)param_2 + 0x19);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 0x1a);
      uVar1 = (uint)*(byte *)((int)param_2 + 0x1a);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      iVar2 = 0;
      if ((uint)*(byte *)((int)param_1 + 0x1b) != (uint)*(byte *)((int)param_2 + 0x1b)) {
        iVar2 = (uint)(0 < (int)((uint)*(byte *)((int)param_1 + 0x1b) -
                                (uint)*(byte *)((int)param_2 + 0x1b))) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    if (param_1[7] == param_2[7]) {
      iVar2 = 0;
    }
    else {
      uVar3 = param_1[7] & 0xff;
      uVar1 = (uint)(byte)param_2[7];
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 0x1d);
      uVar1 = (uint)*(byte *)((int)param_2 + 0x1d);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + 0x1e);
      uVar1 = (uint)*(byte *)((int)param_2 + 0x1e);
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      iVar2 = 0;
      if ((uint)*(byte *)((int)param_1 + 0x1f) != (uint)*(byte *)((int)param_2 + 0x1f)) {
        iVar2 = (uint)(0 < (int)((uint)*(byte *)((int)param_1 + 0x1f) -
                                (uint)*(byte *)((int)param_2 + 0x1f))) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    param_1 = param_1 + 8;
    param_2 = param_2 + 8;
  }
  switch(param_3) {
  default:
    goto switchD_00ecaaf0_caseD_0;
  case 1:
    goto switchD_00ecaaf0_caseD_1;
  case 2:
    goto switchD_00ecaaf0_caseD_2;
  case 3:
    goto switchD_00ecaaf0_caseD_3;
  case 4:
    goto switchD_00ecaaf0_caseD_4;
  case 5:
    goto switchD_00ecaaf0_caseD_5;
  case 6:
    goto switchD_00ecaaf0_caseD_6;
  case 7:
    goto switchD_00ecaaf0_caseD_7;
  case 8:
    goto switchD_00ecaaf0_caseD_8;
  case 9:
    goto switchD_00ecaaf0_caseD_9;
  case 10:
    goto switchD_00ecaaf0_caseD_a;
  case 0xb:
    goto switchD_00ecaaf0_caseD_b;
  case 0xc:
    goto switchD_00ecaaf0_caseD_c;
  case 0xd:
    goto switchD_00ecaaf0_caseD_d;
  case 0xe:
    goto switchD_00ecaaf0_caseD_e;
  case 0xf:
    goto switchD_00ecaaf0_caseD_f;
  case 0x10:
    goto switchD_00ecaaf0_caseD_10;
  case 0x11:
    goto switchD_00ecaaf0_caseD_11;
  case 0x12:
    goto switchD_00ecaaf0_caseD_12;
  case 0x13:
    goto switchD_00ecaaf0_caseD_13;
  case 0x14:
    goto switchD_00ecaaf0_caseD_14;
  case 0x15:
    goto switchD_00ecaaf0_caseD_15;
  case 0x16:
    goto switchD_00ecaaf0_caseD_16;
  case 0x17:
    goto switchD_00ecaaf0_caseD_17;
  case 0x18:
    goto switchD_00ecaaf0_caseD_18;
  case 0x1a:
    goto switchD_00ecaaf0_caseD_1a;
  case 0x1b:
    goto switchD_00ecaaf0_caseD_1b;
  case 0x1c:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x1c));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x1c))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1c));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1b));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1b));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1a));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1a));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x19));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x19));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_18:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x18));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x18))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x18));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x17));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x17));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x16));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x16));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x15));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x15));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_14:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x14));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x14))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x14));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x13));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x13));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x12));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x12));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x11));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x11));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_10:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x10));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x10))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x10));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xf));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xf));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xe));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xe));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xd));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xd));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_c:
    if (*(int *)((int)param_1 + (param_3 - 0xc)) == *(int *)((int)param_2 + (param_3 - 0xc))) {
      iVar2 = 0;
    }
    else {
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xc));
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xc));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xb));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xb));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 10));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 10));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 9));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 9));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_8:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 8));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 8))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 8));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 7));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 7));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 6));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 6));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 5));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 5));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_4:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 4));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 4))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 4));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 3));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 3));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 2));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 2));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 1));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 1));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 == 0) {
switchD_00ecaaf0_caseD_0:
      iVar2 = 0;
    }
    return iVar2;
  case 0x1d:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x1d));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x1d))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1d));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1c));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1c));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1b));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1b));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1a));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1a));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
  case 0x19:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x19));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x19))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x19));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x18));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x18));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x17));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x17));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x16));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x16));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_15:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x15));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x15))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x15));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x14));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x14));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x13));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x13));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x12));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x12));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_11:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x11));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x11))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x11));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x10));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x10));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xf));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xf));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xe));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xe));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_d:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0xd));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0xd))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0xd));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xc));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xc));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xb));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xb));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 10));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 10));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_9:
    if (*(int *)((int)param_1 + (param_3 - 9)) == *(int *)((int)param_2 + (param_3 - 9))) {
      iVar2 = 0;
    }
    else {
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 9));
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 9));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 8));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 8));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 7));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 7));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 6));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 6));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_5:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 5));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 5))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 5));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 4));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 4));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 3));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 3));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 2));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 2));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
LAB_00ecb319:
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_1:
    uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 1));
    uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 1));
    if (uVar3 == uVar1) {
      return 0;
    }
    return (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
  case 0x1e:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x1e));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x1e))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1e));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1d));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1d));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1c));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1c));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1b));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1b));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_1a:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x1a));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x1a))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1a));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x19));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x19));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x18));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x18));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x17));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x17));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_16:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x16));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x16))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x16));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x15));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x15));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x14));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x14));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x13));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x13));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_12:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x12));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x12))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x12));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x11));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x11));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x10));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x10));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xf));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xf));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_e:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0xe));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0xe))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0xe));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xd));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xd));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xc));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xc));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xb));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xb));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_a:
    if (*(int *)((int)param_1 + (param_3 - 10)) == *(int *)((int)param_2 + (param_3 - 10))) {
      iVar2 = 0;
    }
    else {
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 10));
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 10));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 9));
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 9));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 8));
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 8));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 7));
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 7));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_6:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 6));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 6))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 6));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 5));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 5));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 4));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 4));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 3));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 3));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_2:
    if (*(short *)((int)param_1 + (param_3 - 2)) != *(short *)((int)param_2 + (param_3 - 2))) {
LAB_00ecbbbe:
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 2));
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 2));
      if (uVar3 == uVar1) goto switchD_00ecaaf0_caseD_1;
      iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1;
      goto LAB_00ecb319;
    }
    goto switchD_00ecaaf0_caseD_0;
  case 0x1f:
    if (*(int *)((int)param_1 + (param_3 - 0x1f)) == *(int *)((int)param_2 + (param_3 - 0x1f))) {
      iVar2 = 0;
    }
    else {
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1f));
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1f));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1e));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1e));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1d));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1d));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1c));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1c));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_1b:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x1b));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x1b))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1b));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x1a));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x1a));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x19));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x19));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x18));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x18));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_17:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x17));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x17))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x17));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x16));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x16));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x15));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x15));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x14));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x14));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_13:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0x13));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0x13))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0x13));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x12));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x12));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x11));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x11));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0x10));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0x10));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_f:
    if (*(int *)((int)param_1 + (param_3 - 0xf)) == *(int *)((int)param_2 + (param_3 - 0xf))) {
      iVar2 = 0;
    }
    else {
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xf));
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xf));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xe));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xe));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xd));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xd));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 0xc));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 0xc));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_b:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 0xb));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 0xb))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 0xb));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 10));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 10));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 9));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 9));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 8));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 8));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_7:
    uVar1 = *(uint *)((int)param_1 + (param_3 - 7));
    if (uVar1 == *(uint *)((int)param_2 + (param_3 - 7))) {
      iVar2 = 0;
    }
    else {
      uVar1 = uVar1 & 0xff;
      uVar3 = (uint)*(byte *)((int)param_2 + (param_3 - 7));
      if ((uVar1 != uVar3) &&
         (iVar2 = (uint)(uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 6));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 6));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 5));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 5));
      if ((uVar3 != uVar1) &&
         (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
        return iVar2;
      }
      uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 4));
      uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 4));
      iVar2 = 0;
      if (uVar3 != uVar1) {
        iVar2 = (uint)(0 < (int)(uVar3 - uVar1)) * 2 + -1;
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
switchD_00ecaaf0_caseD_3:
    uVar3 = (uint)*(byte *)((int)param_1 + (param_3 - 3));
    uVar1 = (uint)*(byte *)((int)param_2 + (param_3 - 3));
    if ((uVar3 != uVar1) &&
       (iVar2 = (uint)(uVar3 != uVar1 && -1 < (int)(uVar3 - uVar1)) * 2 + -1, iVar2 != 0)) {
      return iVar2;
    }
    goto LAB_00ecbbbe;
  }
}


