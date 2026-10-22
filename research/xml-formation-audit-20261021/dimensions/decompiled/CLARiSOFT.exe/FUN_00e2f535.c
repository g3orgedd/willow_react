// Source: CLARiSOFT.exe @ 00e2f535; FUN_00e2f535

float10 __thiscall FUN_00e2f535(int param_1,char param_2)

{
  int iVar1;
  float local_8;
  
  local_8 = 1.0;
  if (*(int *)(param_1 + 0x160) != 0) {
    iVar1 = **(int **)(param_1 + 0x160);
    if (param_2 == '\x01') {
      (**(code **)(iVar1 + 0x34))();
    }
    else {
      (**(code **)(iVar1 + 0x2c))(*(int **)(param_1 + 0x160),&local_8);
    }
  }
  return (float10)local_8;
}


