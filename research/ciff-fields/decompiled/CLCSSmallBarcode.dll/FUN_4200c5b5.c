// Source: CLCSSmallBarcode.dll @ 4200c5b5; FUN_4200c5b5

undefined4 __thiscall FUN_4200c5b5(void *this,int param_1)

{
  HGDIOBJ h;
  int iVar1;
  
  iVar1 = param_1 * 0xc;
  h = *(HGDIOBJ *)(iVar1 + 0x1450 + (int)this);
  if (h != (HGDIOBJ)0x0) {
    SelectObject(*(HDC *)((param_1 + 0x1b1) * 0xc + (int)this),h);
    *(undefined4 *)(iVar1 + 0x1450 + (int)this) = 0;
    *(undefined4 *)(iVar1 + 0x1454 + (int)this) = 0xffffffff;
  }
  iVar1 = (param_1 + 0x1b1) * 0xc;
  *(undefined4 *)(iVar1 + (int)this) = 0;
  *(int *)((int)this + 0x147c) = *(int *)((int)this + 0x147c) + -1;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


