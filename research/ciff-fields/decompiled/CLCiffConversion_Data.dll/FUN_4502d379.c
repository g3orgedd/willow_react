// Source: CLCiffConversion_Data.dll @ 4502d379; FUN_4502d379

void __cdecl FUN_4502d379(undefined4 *param_1,char *param_2,int param_3,uint param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int local_30;
  int local_2c;
  char local_20 [24];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  FUN_4503452f(*param_1,param_1[1],&local_30,local_20,0x16);
  if (param_2 == (char *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45027e29();
  }
  else if (param_3 == 0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45027e29();
  }
  else {
    uVar3 = 0xffffffff;
    if (param_3 != -1) {
      uVar3 = param_3 - (uint)(local_30 == 0x2d);
    }
    iVar2 = FUN_450343b7(param_2 + (local_30 == 0x2d),uVar3,local_2c + param_4,(int)&local_30);
    if (iVar2 == 0) {
      FUN_4502d28d(param_2,param_3,param_4,&local_30,'\0',param_5);
    }
    else {
      *param_2 = '\0';
    }
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


