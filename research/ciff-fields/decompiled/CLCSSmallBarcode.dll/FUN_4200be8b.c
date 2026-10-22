// Source: CLCSSmallBarcode.dll @ 4200be8b; FUN_4200be8b

int __thiscall FUN_4200be8b(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = (int *)FUN_4200be36(this,*(int *)((int)this + 0x38));
  if (param_1 == 5) {
    if (((*(int *)((int)this + 0x1c) == 0) && (*(int *)((int)this + 0x18) != 0)) &&
       (piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 0xc))();
      iVar2 = *(int *)((int)this + 0xf8) * 7;
    }
  }
  else if (((param_1 - 6U < 2) && (*(int *)((int)this + 0x1c) == 0)) &&
          ((*(int *)((int)this + 0x18) != 0 && (piVar1 != (int *)0x0)))) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    iVar2 = (iVar2 + -3) * *(int *)((int)this + 0xf8);
  }
  return iVar2;
}


