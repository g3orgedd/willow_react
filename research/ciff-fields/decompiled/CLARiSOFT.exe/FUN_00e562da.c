// Source: CLARiSOFT.exe @ 00e562da; FUN_00e562da

bool __fastcall FUN_00e562da(int param_1)

{
  int iVar1;
  bool bVar2;
  int local_8;
  
  bVar2 = false;
  if (*(int *)(param_1 + 4) != 0) {
    local_8 = 0;
    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x3ac))(*(int **)(param_1 + 4),&local_8);
    if (-1 < iVar1) {
      bVar2 = local_8 == 1;
    }
  }
  return bVar2;
}


