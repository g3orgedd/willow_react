// Source: CLCiffConversion_Layout.dll @ 45410eee; FUN_45410eee

undefined4 __thiscall FUN_45410eee(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  if ((short)param_1 == *(short *)((int)this + 0xf4)) {
    FUN_454109d7(this,(short)param_1);
    *(int *)((int)this + 0xf8) = *(int *)((int)this + 0xf8) + 1;
    uVar1 = 3;
  }
  else if (((short)param_1 == 0x6c) && (*(short *)((int)this + 0xf4) == 99)) {
    FUN_454109d7(this,0x6c);
    *(undefined4 *)((int)this + 0xf8) = 0;
    *(undefined2 *)((int)this + 0xf4) = 0;
    uVar1 = 4;
  }
  else {
    uVar1 = FUN_45411df8((int)this);
    *(undefined4 *)((int)this + 0xa8) = uVar1;
    FUN_45411e13(this,param_1,0);
    uVar1 = *(undefined4 *)((int)this + 0xa8);
  }
  return uVar1;
}


