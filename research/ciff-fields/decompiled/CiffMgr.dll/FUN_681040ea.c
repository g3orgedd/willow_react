// Source: CiffMgr.dll @ 681040ea; FUN_681040ea

undefined4 __thiscall
FUN_681040ea(void *this,undefined4 param_1,int *param_2,int param_3,LCID param_4,undefined4 *param_5
            )

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)((int)this + 0x14) == 0)) {
    uVar1 = FUN_68104199(this,param_4);
  }
  if (*(int *)((int)this + 0xc) != 0) {
    if ((*(int *)((int)this + 0x14) != 0) && (param_3 == 1)) {
      if (*param_2 == 0) {
        sVar2 = 0;
      }
      else {
        sVar2 = _wcslen((wchar_t *)*param_2);
      }
      iVar5 = *(int *)((int)this + 0x18) + -1;
      if (-1 < iVar5) {
        iVar4 = iVar5 * 0xc;
        do {
          iVar3 = *(int *)((int)this + 0x14);
          if ((sVar2 == *(size_t *)(iVar4 + 4 + iVar3)) &&
             (iVar3 = FUN_68132cf1(*(uint **)(iVar4 + iVar3),(uint *)*param_2,
                                   *(int *)(iVar4 + 4 + iVar3) * 2), iVar3 == 0)) {
            *param_5 = *(undefined4 *)(iVar5 * 0xc + 8 + *(int *)((int)this + 0x14));
            return 0;
          }
          iVar4 = iVar4 + -0xc;
          iVar5 = iVar5 + -1;
        } while (-1 < iVar5);
      }
    }
    uVar1 = (**(code **)(**(int **)((int)this + 0xc) + 0x28))
                      (*(int **)((int)this + 0xc),param_2,param_3,param_5);
  }
  return uVar1;
}


