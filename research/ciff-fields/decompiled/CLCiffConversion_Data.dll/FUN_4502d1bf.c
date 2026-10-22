// Source: CLCiffConversion_Data.dll @ 4502d1bf; FUN_4502d1bf

void __cdecl
FUN_4502d1bf(undefined4 *param_1,undefined1 *param_2,uint param_3,int param_4,int param_5,
            int *param_6)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int local_30 [4];
  char local_20 [24];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  FUN_4503452f(*param_1,param_1[1],local_30,local_20,0x16);
  if (param_2 == (undefined1 *)0x0) {
    piVar1 = __errno();
  }
  else {
    if (param_3 != 0) {
      uVar3 = 0xffffffff;
      if (param_3 != 0xffffffff) {
        uVar3 = (param_3 - (local_30[0] == 0x2d)) - (uint)(0 < param_4);
      }
      iVar2 = FUN_450343b7(param_2 + (uint)(0 < param_4) + (uint)(local_30[0] == 0x2d),uVar3,
                           param_4 + 1,(int)local_30);
      if (iVar2 == 0) {
        FUN_4502d06e(param_2,param_3,param_4,param_5,local_30,'\0',param_6);
      }
      else {
        *param_2 = 0;
      }
      goto LAB_4502d27c;
    }
    piVar1 = __errno();
  }
  *piVar1 = 0x16;
  FUN_45027e29();
LAB_4502d27c:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


