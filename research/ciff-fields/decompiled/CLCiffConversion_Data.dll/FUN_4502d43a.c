// Source: CLCiffConversion_Data.dll @ 4502d43a; FUN_4502d43a

void __cdecl
FUN_4502d43a(undefined4 *param_1,char *param_2,uint param_3,uint param_4,int param_5,int *param_6)

{
  char *pcVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int local_34;
  int local_30;
  int local_24;
  char local_20 [24];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  FUN_4503452f(*param_1,param_1[1],&local_34,local_20,0x16);
  if (param_2 == (char *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_45027e29();
  }
  else if (param_3 == 0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_45027e29();
  }
  else {
    local_24 = local_30 + -1;
    uVar3 = 0xffffffff;
    if (param_3 != 0xffffffff) {
      uVar3 = param_3 - (local_34 == 0x2d);
    }
    iVar4 = FUN_450343b7(param_2 + (local_34 == 0x2d),uVar3,param_4,(int)&local_34);
    if (iVar4 == 0) {
      local_30 = local_30 + -1;
      if ((local_30 < -4) || ((int)param_4 <= local_30)) {
        FUN_4502d06e(param_2,param_3,param_4,param_5,&local_34,'\x01',param_6);
      }
      else {
        pcVar1 = param_2 + (local_34 == 0x2d);
        if (local_24 < local_30) {
          do {
            pcVar5 = pcVar1;
            pcVar1 = pcVar5 + 1;
          } while (*pcVar5 != '\0');
          pcVar5[-1] = '\0';
        }
        FUN_4502d28d(param_2,param_3,param_4,&local_34,'\x01',param_6);
      }
    }
    else {
      *param_2 = '\0';
    }
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


