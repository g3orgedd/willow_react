// Source: CLCSGraphicBasedField.dll @ 41c12fb7; FUN_41c12fb7

undefined4 __thiscall FUN_41c12fb7(void *this,undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int iVar3;
  HDC hdc;
  HBITMAP h;
  HGDIOBJ pvVar4;
  
  puVar1 = param_1;
  if (param_1 == (undefined8 *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    iVar3 = FUN_41c135ab((int)this);
    if (iVar3 != 0) {
      FUN_41c12eeb((int)this);
    }
    iVar3 = *(int *)((int)puVar1 + 10);
    hdc = CreateCompatibleDC((HDC)0x0);
    *(HDC *)((int)this + 0xc) = hdc;
    if (hdc != (HDC)0x0) {
      h = CreateDIBSection(hdc,(BITMAPINFO *)((int)puVar1 + 0xe),0,&param_1,(HANDLE)0x0,0);
      *(HBITMAP *)((int)this + 0x10) = h;
      if (h == (HBITMAP)0x0) {
        FUN_41c12eeb((int)this);
        return 0;
      }
      pvVar4 = SelectObject(*(HDC *)((int)this + 0xc),h);
      *(HGDIOBJ *)((int)this + 0x14) = pvVar4;
      FUN_41c1356d(this,(int)puVar1 + 0xe);
      *(uint *)((int)this + 0x1c) =
           (uint)*(ushort *)((int)puVar1 + 0x1c) * *(int *)((int)puVar1 + 0x12) + 0x1f >> 3 &
           0x1ffffffc;
      FUN_41c186a0(param_1,(undefined8 *)(iVar3 + (int)puVar1),*(uint *)((int)puVar1 + 0x22));
      *(undefined8 **)((int)this + 0x18) = param_1;
    }
    uVar2 = 1;
  }
  return uVar2;
}


