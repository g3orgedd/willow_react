// Source: CLARiSOFT.exe @ 00e2de25; FUN_00e2de25

bool __fastcall FUN_00e2de25(int param_1)

{
  bool bVar1;
  int local_8;
  
  bVar1 = false;
  if (*(int *)(param_1 + 0x15c) != 0) {
    local_8 = param_1;
    (**(code **)(**(int **)(param_1 + 0x15c) + 0x74))(*(int **)(param_1 + 0x15c),&local_8);
    bVar1 = local_8 == 1;
  }
  return bVar1;
}


