// Source: CLARiSOFT.exe @ 00e4cac1; FUN_00e4cac1

int * __thiscall FUN_00e4cac1(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = (undefined4 *)**(undefined4 **)((int)this + 4);
  if (0 < *(int *)((int)this + 8)) {
    do {
      puVar1 = puVar2 + 2;
      puVar2 = (undefined4 *)*puVar2;
      if (*(int *)*puVar1 == param_1) {
        return (int *)*puVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)((int)this + 8));
  }
  return (int *)0x0;
}


