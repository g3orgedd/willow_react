// Source: CLCiffConversion_Layout.dll @ 4541e626; FUN_4541e626

bool __fastcall FUN_4541e626(int *param_1)

{
  int *piVar1;
  int local_8;
  
  local_8 = 0;
  piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  (**(code **)(*piVar1 + 0x184))(piVar1,&local_8);
  return local_8 == 1;
}


