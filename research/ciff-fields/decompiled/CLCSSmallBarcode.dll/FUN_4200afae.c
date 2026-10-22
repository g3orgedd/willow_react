// Source: CLCSSmallBarcode.dll @ 4200afae; FUN_4200afae

undefined4 __thiscall FUN_4200afae(void *this,ushort *param_1)

{
  int iVar1;
  
  if (((((*(int *)((int)this + 0x44) == *(int *)(param_1 + 0x22)) &&
        (*(int *)((int)this + 0x48) == *(int *)(param_1 + 0x24))) &&
       (*(int *)((int)this + 0x4c) == *(int *)(param_1 + 0x26))) &&
      ((iVar1 = FUN_4206a1e1(this,param_1), iVar1 == 0 &&
       (*(int *)((int)this + 0x50) == *(int *)(param_1 + 0x28))))) &&
     ((*(int *)((int)this + 0x54) == *(int *)(param_1 + 0x2a) &&
      ((*(int *)((int)this + 0x58) == *(int *)(param_1 + 0x2c) &&
       (*(int *)((int)this + 0x40) == *(int *)(param_1 + 0x20))))))) {
    return 1;
  }
  return 0;
}


