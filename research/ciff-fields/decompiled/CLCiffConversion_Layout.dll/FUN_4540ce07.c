// Source: CLCiffConversion_Layout.dll @ 4540ce07; FUN_4540ce07

undefined4 __thiscall FUN_4540ce07(void *this,uint param_1)

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
    if (0x3fffffff < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_45429486("vector<T> too long");
    }
    iVar2 = _Allocate<>(param_1);
    *(int *)this = iVar2;
    *(int *)((int)this + 4) = iVar2;
    iVar2 = iVar2 + param_1 * 4;
    *(int *)((int)this + 8) = iVar2;
    uVar1 = CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  return uVar1;
}


