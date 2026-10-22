// Source: CLCSSmallBarcode.dll @ 4200c87e; FUN_4200c87e

undefined4 __thiscall FUN_4200c87e(void *this,HDC param_1,int *param_2)

{
  HGDIOBJ h;
  undefined4 uVar1;
  int iVar2;
  int *this_00;
  void *local_8;
  
  local_8 = this;
  h = GetCurrentObject(param_1,7);
  if ((h == (HGDIOBJ)0x0) || (iVar2 = GetObjectW(h,0x54,(LPVOID)((int)this + 0x8c)), iVar2 == 0)) {
    uVar1 = 0x80004005;
  }
  else {
    iVar2 = *(int *)((int)this + 0x98) + 3;
    *(int *)((int)this + 4) = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
    this_00 = (int *)FUN_4200be36(this,*(int *)((int)this + 0x38));
    if (this_00 != (int *)0x0) {
      FUN_4200a125(this_00,*(undefined4 *)((int)this + 0x4c),*(undefined4 *)((int)this + 0x44),
                   *(undefined4 *)((int)this + 0x1c),*(undefined4 *)((int)this + 0x20),
                   *(undefined4 *)((int)this + 0x18),*(undefined4 *)((int)this + 0x3c),
                   *(undefined4 *)((int)this + 0x40));
      iVar2 = (**(code **)(*this_00 + 4))
                        (*(undefined4 *)((int)this + 0x28),(int)this + 0x2b8,&local_8,
                         (int)this + 0x100);
      if (-1 < iVar2) {
        iVar2 = (**(code **)(*this_00 + 8))();
        *(int *)((int)this + 0x70) = *(int *)((int)this + 0xf8) * iVar2;
        iVar2 = FUN_4200b42d((int)this);
        if (((-1 < iVar2) && (0 < *(int *)((int)this + 0x70))) && (0 < *(int *)((int)this + 0x78)))
        {
          iVar2 = (**(code **)(*(int *)this + 0x1c))(*(undefined4 *)((int)this + 0x38));
          *(int *)((int)this + 0x84) = *(int *)((int)this + 0x84) + iVar2;
          iVar2 = FUN_4200ca84(this,this_00,(int)this + 0x2b8,local_8);
          if ((-1 < iVar2) && (iVar2 = FUN_4200c60d(this,this_00), -1 < iVar2)) {
            FUN_4200cc74(this,this_00,param_1,param_2);
          }
        }
      }
    }
    *(undefined4 *)((int)this + 0x84) = 0;
    uVar1 = 0;
  }
  return uVar1;
}


