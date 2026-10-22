// Source: CLCSSmallBarcode.dll @ 4200b2f6; FUN_4200b2f6

undefined4 __thiscall
FUN_4200b2f6(void *this,int *param_1,int *param_2,uint param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_8;
  
  iVar3 = param_5;
  if (*(int *)((int)this + 0x1c) != 0) {
    iVar2 = (**(code **)(*param_1 + 0xc))();
    iVar2 = iVar2 * *(int *)((int)this + 0xf8);
    if (0 < iVar2) {
      (*DAT_420be868)(param_4,param_5,iVar2);
      iVar3 = param_5 + iVar2;
    }
  }
  local_8 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *(uint *)(*param_2 + local_8 * 8);
      uVar4 = 1 << ((char)*(undefined4 *)(*param_2 + 4 + local_8 * 8) - 1U & 0x1f);
      while (uVar4 != 0) {
        iVar2 = 1;
        if ((uVar1 & uVar4) == 0) {
          while ((uVar4 = uVar4 >> 1, uVar4 != 0 && ((uVar1 & uVar4) == 0))) {
            iVar2 = iVar2 + 1;
          }
          param_5 = *(int *)((int)this + 0xf8) * iVar2;
          (*DAT_420be868)(param_4,iVar3,param_5);
        }
        else {
          while (uVar4 = uVar4 >> 1, (uVar1 & uVar4) != 0) {
            iVar2 = iVar2 + 1;
          }
          param_5 = *(int *)((int)this + 0xf8) * iVar2;
          (*DAT_420be870)(param_4,iVar3,param_5);
        }
        iVar3 = iVar3 + param_5;
      }
      local_8 = local_8 + 1;
    } while (local_8 < param_3);
  }
  if (*(int *)((int)this + 0x1c) != 0) {
    iVar2 = (**(code **)(*param_1 + 0x10))();
    iVar2 = iVar2 * *(int *)((int)this + 0xf8);
    if (0 < iVar2) {
      (*DAT_420be868)(param_4,iVar3,iVar2);
    }
  }
  return 0;
}


