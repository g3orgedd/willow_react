// Source: CiffMgr.dll @ 6811152d; FUN_6811152d

uint __thiscall FUN_6811152d(void *this,undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  while( true ) {
    if (param_3 < param_2) {
      return 0xffffffff;
    }
    uVar2 = param_2 + param_3 >> 1;
    iVar1 = (*(code *)**(undefined4 **)this)
                      (param_1,*(undefined4 *)(*(int *)((int)this + 4) + uVar2 * 8));
    if (iVar1 == 0) break;
    if (iVar1 < 0) {
      if (uVar2 == 0) {
        return 0xffffffff;
      }
      param_3 = uVar2 - 1;
    }
    else {
      param_2 = uVar2 + 1;
    }
  }
  return uVar2;
}


