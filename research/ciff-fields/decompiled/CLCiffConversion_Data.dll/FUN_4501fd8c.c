// Source: CLCiffConversion_Data.dll @ 4501fd8c; FUN_4501fd8c

undefined4 __thiscall FUN_4501fd8c(void *this,undefined4 param_1)

{
  undefined4 uVar1;
  
  if ((short)param_1 == *(short *)((int)this + 0xf4)) {
    FUN_4501f875(this,(short)param_1);
    *(int *)((int)this + 0xf8) = *(int *)((int)this + 0xf8) + 1;
    uVar1 = 3;
  }
  else if (((short)param_1 == 0x6c) && (*(short *)((int)this + 0xf4) == 99)) {
    FUN_4501f875(this,0x6c);
    *(undefined4 *)((int)this + 0xf8) = 0;
    *(undefined2 *)((int)this + 0xf4) = 0;
    uVar1 = 4;
  }
  else {
    uVar1 = FUN_4502086a((int)this);
    *(undefined4 *)((int)this + 0xa8) = uVar1;
    FUN_45020885(this,param_1,0);
    uVar1 = *(undefined4 *)((int)this + 0xa8);
  }
  return uVar1;
}


