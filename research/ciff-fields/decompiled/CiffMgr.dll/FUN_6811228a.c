// Source: CiffMgr.dll @ 6811228a; FUN_6811228a

void __thiscall FUN_6811228a(void *this,int param_1)

{
  undefined4 uVar1;
  
  if (((*(int *)((int)this + 0xc) == 0) && (*(int *)((int)this + 4) != 0)) &&
     (param_1 != *(int *)((int)this + 8))) {
    FID_conflict__free(*(void **)((int)this + 4));
    *(undefined4 *)((int)this + 4) = 0;
    *(undefined4 *)((int)this + 8) = 0;
  }
  if (((*(int *)((int)this + 8) == 0) && (*(int *)((int)this + 4) == 0)) && (param_1 != 0)) {
    *(int *)((int)this + 8) = param_1;
    uVar1 = FUN_68130f16(*(int *)((int)this + 0x10) * param_1);
    *(undefined4 *)((int)this + 4) = uVar1;
  }
  return;
}


