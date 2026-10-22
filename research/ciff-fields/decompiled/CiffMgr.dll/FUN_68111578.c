// Source: CiffMgr.dll @ 68111578; FUN_68111578

uint __thiscall
FUN_68111578(void *this,undefined4 param_1,uint param_2,uint param_3,undefined1 *param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  *param_4 = 0;
  if (param_2 <= param_3) {
    do {
      uVar2 = param_2 + param_3 >> 1;
      iVar1 = (*(code *)**(undefined4 **)this)
                        (param_1,*(undefined4 *)(*(int *)((int)this + 4) + uVar2 * 8));
      if (iVar1 == 0) {
        *param_4 = 1;
        return uVar2;
      }
      if (iVar1 < 0) {
        if (uVar2 == 0) break;
        param_3 = uVar2 - 1;
      }
      else {
        param_2 = uVar2 + 1;
      }
    } while (param_2 <= param_3);
    if (0 < iVar1) {
      uVar2 = uVar2 + 1;
    }
  }
  return uVar2;
}


