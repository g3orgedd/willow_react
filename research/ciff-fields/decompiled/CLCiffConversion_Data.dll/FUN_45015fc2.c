// Source: CLCiffConversion_Data.dll @ 45015fc2; FUN_45015fc2

int FUN_45015fc2(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int *local_c;
  uint local_8;
  
  iVar1 = -0x7fffbffd;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    iVar1 = FUN_4501626f(&local_c);
    if (-1 < iVar1) {
      if ((*(byte *)(param_1 + 5) & 2) == 0) {
        piVar2 = (int *)param_1[1];
        local_8 = 2;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 4))(piVar2);
        }
      }
      else {
        local_8 = 1;
        (**(code **)(*param_1 + 4))(param_1);
        piVar2 = param_1;
      }
      iVar1 = FUN_45016b04(local_c,(int *)param_1[2],(int *)param_1[3],piVar2,0);
      if (((local_8 & 2) != 0) && (local_8 = local_8 & 0xfffffffd, piVar2 != (int *)0x0)) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      if (((local_8 & 1) != 0) && (piVar2 != (int *)0x0)) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      if (-1 < iVar1) {
        local_c[4] = param_1[4];
        iVar1 = FUN_45015610((int)local_c,(int *)&PTR_DAT_45040018,(_GUID *)&DAT_4503fd9c,param_2);
        if (-1 < iVar1) {
          return iVar1;
        }
      }
      if (local_c != (int *)0x0) {
        (**(code **)(*local_c + 0x1c))(1);
      }
    }
  }
  return iVar1;
}


