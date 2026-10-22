// Source: CiffMgr.dll @ 6810c585; FUN_6810c585

undefined4 __thiscall FUN_6810c585(void *this,void *param_1,int param_2)

{
  ulong uVar1;
  LPVOID pvVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_2 + 1 + *(int *)this;
  if ((*(int *)this < iVar3) && (param_2 < iVar3)) {
    if (*(int *)((int)this + 4) <= iVar3) {
      do {
        if (0x3fffffff < *(int *)((int)this + 4)) {
          return 0;
        }
        uVar1 = *(int *)((int)this + 4) * 2;
        *(ulong *)((int)this + 4) = uVar1;
      } while ((int)uVar1 <= iVar3);
      pvVar2 = FUN_6810c684(*(LPVOID *)((int)this + 8),uVar1,2);
      if (pvVar2 == (LPVOID)0x0) {
        return 0;
      }
      *(LPVOID *)((int)this + 8) = pvVar2;
    }
    iVar3 = *(int *)this;
    if (((-1 < iVar3) && (iVar3 < *(int *)((int)this + 4))) &&
       (iVar4 = *(int *)((int)this + 4) - iVar3, iVar4 <= *(int *)((int)this + 4))) {
      FUN_68104847((void *)(*(int *)((int)this + 8) + iVar3 * 2),iVar4 * 2,param_1,param_2 * 2);
      *(int *)this = *(int *)this + param_2;
      *(undefined2 *)(*(int *)((int)this + 8) + *(int *)this * 2) = 0;
      return 1;
    }
  }
  return 0;
}


