// Source: CLCiffConversion_Layout.dll @ 4543a525; FUN_4543a525

void __cdecl FUN_4543a525(byte *param_1,undefined4 *param_2,byte *param_3,int *param_4,int *param_5)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  *param_5 = 0;
  *param_4 = 1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_3;
    param_2 = param_2 + 1;
  }
  bVar2 = false;
  do {
    if (*param_1 == 0x22) {
      bVar2 = !bVar2;
      pbVar6 = param_1 + 1;
      bVar3 = 0x22;
    }
    else {
      *param_5 = *param_5 + 1;
      if (param_3 != (byte *)0x0) {
        *param_3 = *param_1;
        param_3 = param_3 + 1;
      }
      bVar3 = *param_1;
      pbVar6 = param_1 + 1;
      iVar4 = FUN_4543958f((uint)bVar3);
      if (iVar4 != 0) {
        *param_5 = *param_5 + 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        pbVar6 = param_1 + 2;
      }
      if (bVar3 == 0) {
        pbVar6 = pbVar6 + -1;
        goto LAB_4543a5b6;
      }
    }
    param_1 = pbVar6;
  } while ((bVar2) || ((bVar3 != 0x20 && (bVar3 != 9))));
  if (param_3 != (byte *)0x0) {
    param_3[-1] = 0;
  }
LAB_4543a5b6:
  bVar2 = false;
  while (pbVar7 = pbVar6, *pbVar6 != 0) {
    for (; (*pbVar7 == 0x20 || (*pbVar7 == 9)); pbVar7 = pbVar7 + 1) {
    }
    if (*pbVar7 == 0) break;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_3;
      param_2 = param_2 + 1;
    }
    *param_4 = *param_4 + 1;
    while( true ) {
      bVar1 = true;
      uVar5 = 0;
      for (; *pbVar7 == 0x5c; pbVar7 = pbVar7 + 1) {
        uVar5 = uVar5 + 1;
      }
      pbVar6 = pbVar7;
      if (*pbVar7 == 0x22) {
        if (((uVar5 & 1) == 0) && ((!bVar2 || (pbVar6 = pbVar7 + 1, *pbVar6 != 0x22)))) {
          bVar1 = false;
          bVar2 = !bVar2;
          pbVar6 = pbVar7;
        }
        uVar5 = uVar5 >> 1;
      }
      while (uVar5 != 0) {
        uVar5 = uVar5 - 1;
        if (param_3 != (byte *)0x0) {
          *param_3 = 0x5c;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      bVar3 = *pbVar6;
      if ((bVar3 == 0) || ((!bVar2 && ((bVar3 == 0x20 || (bVar3 == 9)))))) break;
      if (bVar1) {
        iVar4 = FUN_4543958f((int)(char)bVar3);
        if (param_3 == (byte *)0x0) {
          if (iVar4 != 0) {
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
        }
        else {
          if (iVar4 != 0) {
            *param_3 = *pbVar6;
            param_3 = param_3 + 1;
            pbVar6 = pbVar6 + 1;
            *param_5 = *param_5 + 1;
          }
          *param_3 = *pbVar6;
          param_3 = param_3 + 1;
        }
        *param_5 = *param_5 + 1;
      }
      pbVar7 = pbVar6 + 1;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = 0;
      param_3 = param_3 + 1;
    }
    *param_5 = *param_5 + 1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  *param_4 = *param_4 + 1;
  return;
}


