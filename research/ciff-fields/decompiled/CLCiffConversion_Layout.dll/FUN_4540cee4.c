// Source: CLCiffConversion_Layout.dll @ 4540cee4; FUN_4540cee4

undefined4 __thiscall FUN_4540cee4(void *this,uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    if (0x7ffffff < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45429486("vector<T> too long");
    }
    iVar2 = _Allocate<>(param_1);
    *(int *)this = iVar2;
    *(int *)((int)this + 4) = iVar2;
    uVar1 = CONCAT31((int3)((uint)iVar2 >> 8),1);
    *(uint *)((int)this + 8) = param_1 * 0x20 + iVar2;
  }
  return uVar1;
}


