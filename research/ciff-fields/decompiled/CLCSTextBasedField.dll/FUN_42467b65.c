// Source: CLCSTextBasedField.dll @ 42467b65; FUN_42467b65

bool __thiscall FUN_42467b65(void *this,uint param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if ((int)(param_1 % 10) < *(int *)((int)this + 0x2c)) {
    bVar1 = *(uint *)(*(int *)((int)this + (param_1 % 10) * 4 + 4) + 0x70) == param_1;
  }
  return bVar1;
}


