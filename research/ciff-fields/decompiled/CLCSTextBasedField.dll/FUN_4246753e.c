// Source: CLCSTextBasedField.dll @ 4246753e; FUN_4246753e

void __thiscall FUN_4246753e(void *this,int param_1)

{
  void *_Memory;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x30));
  iVar5 = 0;
  piVar1 = this;
  if (0 < *(int *)((int)this + 0x2c)) {
    do {
      if (piVar1[1] == param_1) {
        puVar2 = (undefined4 *)((int)this + iVar5 * 4 + 4);
        _Memory = (void *)*puVar2;
        if (_Memory != (void *)0x0) {
          FUN_424672ad((int)_Memory);
          FID_conflict__free(_Memory);
          puVar2 = (undefined4 *)((int)this + iVar5 * 4 + 4);
        }
        if (iVar5 < 9) {
          puVar4 = (undefined4 *)((int)this + iVar5 * 4 + 8);
          for (iVar3 = 9 - iVar5; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar2 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar2 = puVar2 + 1;
          }
        }
        *(undefined4 *)((int)this + 0x28) = 0;
        *(int *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + -1;
        break;
      }
      iVar5 = iVar5 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar5 < *(int *)((int)this + 0x2c));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x30));
  return;
}


