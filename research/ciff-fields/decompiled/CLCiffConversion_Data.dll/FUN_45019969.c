// Source: CLCiffConversion_Data.dll @ 45019969; FUN_45019969

int __cdecl FUN_45019969(int *param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  int *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = param_1;
  iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&param_1);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,&local_8);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,&local_c);
      if (-1 < iVar2) {
        local_18 = param_1;
        local_14 = local_8;
        local_10 = local_c;
        FUN_45019b27(param_2,&local_18);
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}


