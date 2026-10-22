// Source: CiffMgr.dll @ 681046fc; FUN_681046fc

uint __thiscall FUN_681046fc(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)((int)this + 8) - *(int *)this >> 4;
  if (0xfffffff - (uVar1 >> 1) < uVar1) {
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 + (uVar1 >> 1);
  }
  if (uVar1 < param_1) {
    uVar1 = param_1;
  }
  return uVar1;
}


