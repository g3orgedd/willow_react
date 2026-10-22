// Source: CLARiSOFT.exe @ 00e41bff; FUN_00e41bff

void __thiscall FUN_00e41bff(void *this,int param_1)

{
  int *piVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    uVar2 = 0;
    piVar1 = (int *)**(undefined4 **)((int)this + 0xa0);
    if (*(uint *)((int)this + 0xa4) != 0) {
      do {
        if (piVar1[2] == param_1) {
          FUN_00e42a72((undefined4 *)((int)this + 0xa0),&param_1,piVar1);
          return;
        }
        piVar1 = (int *)*piVar1;
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)((int)this + 0xa4));
    }
  }
  return;
}


