// Source: CLARiSOFT.exe @ 00e310e9; FUN_00e310e9

void __thiscall FUN_00e310e9(void *this,int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)((int)this + 0x1e0);
  if ((*piVar1 != 0) && (piVar2 = (int *)*piVar1, piVar2 != (int *)0x0)) {
    *piVar1 = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  iVar3 = (**(code **)(**(int **)((int)this + 0x230) + 0x20))
                    (*(int **)((int)this + 0x230),*(undefined4 *)(param_1 + 8),piVar1);
  if ((-1 < iVar3) && (*piVar1 != 0)) {
    FUN_00e353ea(this,(int *)(param_1 + 4));
  }
  return;
}


