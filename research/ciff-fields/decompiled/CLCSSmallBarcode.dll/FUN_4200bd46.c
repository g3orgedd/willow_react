// Source: CLCSSmallBarcode.dll @ 4200bd46; FUN_4200bd46

int __thiscall FUN_4200bd46(void *this,ushort *param_1)

{
  undefined4 uVar1;
  int iVar2;
  void *this_00;
  
  iVar2 = 0;
  if (0 < *(int *)((int)this + 0x1448)) {
    this_00 = (void *)((int)this + 0x10);
    do {
      uVar1 = FUN_4200afae(this_00,param_1);
      if ((char)uVar1 != '\0') {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      this_00 = (void *)((int)this_00 + 0xd8);
    } while (iVar2 < *(int *)((int)this + 0x1448));
  }
  return -1;
}


