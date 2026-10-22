// Source: CLCSSmallBarcode.dll @ 4203435e; FUN_4203435e

uint __thiscall FUN_4203435e(void *this,HDC param_1)

{
  void *this_00;
  HDC pHVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  LONG local_10;
  LONG local_c;
  HANDLE local_8;
  
  uVar6 = 0x80004005;
  this_00 = *(void **)((int)this + 0xf0);
  if (this_00 != (void *)0x0) {
    if (*(int *)((int)this + 0xf4) == 0) {
      iVar2 = FUN_42035049(this_00,(int *)((int)this + 200),*(byte **)((int)this + 0xbc),
                           *(int *)((int)this + 0xb8));
    }
    else {
      iVar2 = FUN_42034eaa(this_00,(int *)((int)this + 200),*(byte **)((int)this + 0xbc),
                           *(int *)((int)this + 0xb8));
    }
    if (-1 < iVar2) {
      iVar2 = FUN_420351bb(*(int *)((int)this + 0xf0));
      iVar4 = *(int *)((int)this + 0x90) * iVar2;
      iVar5 = *(int *)((int)this + 0x94) * iVar2;
      *(int *)((int)this + 0xe0) = iVar2;
      *(int *)((int)this + 0xa0) = iVar4;
      *(int *)((int)this + 0xa4) = iVar5;
      if (*(char *)((int)this + 0xdc) == '\x01') {
        *(int *)((int)this + 0xa0) = iVar4 + *(int *)((int)this + 0x90) * 8;
        *(int *)((int)this + 0xa4) = iVar5 + *(int *)((int)this + 0x94) * 8;
      }
      FUN_42033afa(this,&local_10);
      pHVar1 = param_1;
      local_8 = (HANDLE)FUN_420276ca(param_1,local_10,local_c);
      if (local_8 != (HANDLE)0xffffffff) {
        FUN_4202743c(this,local_8,pHVar1,&param_1,local_10,local_c);
        iVar2 = *(int *)((int)this + 0x24) + 3;
        *(int *)((int)this + 0x14) = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
        uVar3 = (**(code **)(*(int *)this + 0x1c))();
        *(undefined4 *)((int)this + 0x6c) = uVar3;
        uVar3 = (**(code **)(*(int *)this + 0x20))();
        *(undefined4 *)((int)this + 0x70) = uVar3;
        uVar6 = FUN_42029e72(*(int *)((int)this + 0xa8),*(int *)((int)this + 0xac),
                             *(int *)((int)this + 0x98),*(int *)((int)this + 0x9c),
                             *(int *)((int)this + 0xb0),*(int *)((int)this + 0xb4),
                             (uint *)((int)this + 0xe8),(void *)((int)this + 0xec));
        if (-1 < (int)uVar6) {
          uVar6 = FUN_420344de(this);
        }
        iVar2 = (**(code **)(*(int *)this + 0x20))();
        iVar4 = (**(code **)(*(int *)this + 0x1c))();
        FUN_42027798(this,pHVar1,param_1,iVar4,iVar2);
        FUN_42027631(this,local_8,pHVar1,param_1);
      }
    }
  }
  return uVar6;
}


