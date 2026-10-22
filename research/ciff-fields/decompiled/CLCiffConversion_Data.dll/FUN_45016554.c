// Source: CLCiffConversion_Data.dll @ 45016554; FUN_45016554

void FUN_45016554(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int local_18 [4];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
    iVar3 = *(int *)PTR_DAT_45051038;
    piVar2 = (int *)PTR_DAT_45051038;
    while (iVar3 != -1) {
      if (iVar3 == -2) {
        piVar2 = (int *)(*(code *)piVar2[1])(0);
      }
      else {
        piVar1 = (int *)(iVar3 + param_1);
        iVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,local_18);
        if ((-1 < iVar3) && (iVar3 = FUN_45018a9f(param_2,local_18), iVar3 != 0)) {
          *param_3 = (int)piVar1;
          (**(code **)(*piVar1 + 4))(piVar1);
          break;
        }
        piVar2 = piVar2 + 1;
      }
      iVar3 = *piVar2;
    }
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


