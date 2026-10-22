// Source: CLCSTextBasedField.dll @ 42467666; FUN_42467666

int __thiscall FUN_42467666(void *this,wchar_t *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x30));
  iVar3 = 0;
  piVar1 = this;
  if (0 < *(int *)((int)this + 0x2c)) {
    do {
      iVar2 = _wcscmp(param_1,(wchar_t *)(piVar1[1] + 4));
      if (iVar2 == 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar3 < *(int *)((int)this + 0x2c));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x30));
  return -1;
}


