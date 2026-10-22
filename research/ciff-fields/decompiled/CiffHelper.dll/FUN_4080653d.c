// Source: CiffHelper.dll @ 4080653d; FUN_4080653d

void __thiscall FUN_4080653d(void *this,char param_1,int param_2)

{
  undefined8 *_Memory;
  
  if ((param_1 != '\0') && (7 < *(uint *)((int)this + 0x14))) {
    _Memory = *(undefined8 **)this;
    if (param_2 != 0) {
      copy(this,_Memory,param_2);
    }
    FID_conflict__free(_Memory);
  }
  *(int *)((int)this + 0x10) = param_2;
  *(undefined4 *)((int)this + 0x14) = 7;
  *(undefined2 *)((int)this + param_2 * 2) = 0;
  return;
}


