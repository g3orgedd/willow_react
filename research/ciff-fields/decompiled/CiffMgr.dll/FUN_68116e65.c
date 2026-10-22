// Source: CiffMgr.dll @ 68116e65; FUN_68116e65

void __thiscall FUN_68116e65(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = *(undefined4 **)((int)this + 4);
  if ((param_1 < puVar1) && (*(undefined4 **)this <= param_1)) {
    iVar4 = (int)param_1 - *(int *)this >> 2;
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_681161f3(this,1);
    }
    puVar1 = *(undefined4 **)((int)this + 4);
    if (puVar1 != (undefined4 *)0x0) {
      iVar2 = *(int *)this;
      *puVar1 = 0;
      uVar3 = *(undefined4 *)(iVar2 + iVar4 * 4);
      *(undefined4 *)(iVar2 + iVar4 * 4) = 0;
      *puVar1 = uVar3;
    }
  }
  else {
    if (puVar1 == *(undefined4 **)((int)this + 8)) {
      FUN_681161f3(this,1);
    }
    puVar1 = *(undefined4 **)((int)this + 4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
      uVar3 = *param_1;
      *param_1 = 0;
      *puVar1 = uVar3;
    }
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  return;
}


