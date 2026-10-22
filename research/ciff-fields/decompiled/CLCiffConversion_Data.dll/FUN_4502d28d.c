// Source: CLCiffConversion_Data.dll @ 4502d28d; FUN_4502d28d

undefined4 __cdecl
FUN_4502d28d(char *param_1,int param_2,uint param_3,int *param_4,char param_5,int *param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  char *pcVar4;
  int local_18 [2];
  int local_10;
  char local_c;
  uint local_8;
  
  local_8 = param_4[1] - 1;
  FUN_45021444(local_18,param_6);
  if ((param_1 == (char *)0x0) || (param_2 == 0)) {
    piVar2 = __errno();
    uVar3 = 0x16;
    *piVar2 = 0x16;
    FUN_45027e29();
  }
  else {
    uVar3 = 0;
    if ((param_5 != '\0') && (local_8 == param_3)) {
      iVar1 = *param_4;
      (param_1 + (iVar1 == 0x2d) + local_8)[0] = '0';
      (param_1 + (iVar1 == 0x2d) + local_8)[1] = '\0';
    }
    if (*param_4 == 0x2d) {
      *param_1 = '-';
      param_1 = param_1 + 1;
    }
    if (param_4[1] < 1) {
      __shift(param_1,1);
      *param_1 = '0';
      pcVar4 = param_1 + 1;
    }
    else {
      pcVar4 = param_1 + param_4[1];
    }
    if (0 < (int)param_3) {
      __shift(pcVar4,1);
      *pcVar4 = *(char *)**(undefined4 **)(local_18[0] + 0x84);
      iVar1 = param_4[1];
      if (iVar1 < 0) {
        if (param_5 == '\0') {
          if (-iVar1 <= (int)param_3) {
            param_3 = -iVar1;
          }
        }
        else {
          param_3 = -iVar1;
        }
        __shift(pcVar4 + 1,param_3);
        FUN_45021c10((uint *)(pcVar4 + 1),0x30,param_3);
      }
    }
  }
  if (local_c != '\0') {
    *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
  }
  return uVar3;
}


