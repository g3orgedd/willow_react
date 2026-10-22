// Source: CiffMgr.dll @ 68112452; FUN_68112452

uint __thiscall FUN_68112452(void *this,int param_1)

{
  uint uVar1;
  
  if ((param_1 == 0) || (*(int *)((int)this + 0xc) == 0)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FUN_6811152d(this,param_1,0,*(int *)((int)this + 0xc) - 1);
  }
  return uVar1;
}


