// Source: CLCiffConversion_Data.dll @ 45024089; FUN_45024089

undefined4 __cdecl
FUN_45024089(undefined *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_24;
  undefined4 local_20 [7];
  
  local_24 = 0;
  puVar4 = local_20;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  if (param_2 == 0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45027e29();
    uVar2 = 0xffffffff;
  }
  else {
    local_20[0] = 0x7fffffff;
    local_20[2] = 0x42;
    local_20[1] = 0;
    local_24 = 0;
    uVar2 = (*(code *)param_1)(&local_24,param_2,param_3,param_4);
  }
  return uVar2;
}


