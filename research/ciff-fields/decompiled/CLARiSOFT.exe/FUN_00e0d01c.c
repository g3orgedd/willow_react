// Source: CLARiSOFT.exe @ 00e0d01c; FUN_00e0d01c

void __thiscall FUN_00e0d01c(void *this,int *param_1)

{
  if (param_1 != (int *)0x0) {
    FUN_00e11de5((void *)((int)this + 0xc),(int *)&param_1);
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  return;
}


