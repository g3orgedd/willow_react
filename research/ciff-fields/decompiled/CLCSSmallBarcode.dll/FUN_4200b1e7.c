// Source: CLCSSmallBarcode.dll @ 4200b1e7; FUN_4200b1e7

undefined4 __thiscall
FUN_4200b1e7(void *this,int param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_c;
  int local_8;
  
  uVar4 = param_4;
  param_4 = 1;
  if (*(int *)((int)this + 0x1c) != 0) {
    (*DAT_420be868)(param_3,uVar4,*(undefined4 *)((int)this + 0xf4));
    uVar4 = uVar4 + *(int *)((int)this + 0xf4);
  }
  uVar2 = 1;
  local_8 = 0;
  if (0 < param_2) {
    do {
      uVar1 = *(uint *)(param_1 + local_8 * 4);
      local_c = 0x100;
      uVar2 = param_4;
      do {
        param_4 = uVar2;
        if ((uVar1 & local_c) == 0) {
          iVar3 = *(int *)((int)this + 0xec);
        }
        else {
          iVar3 = *(int *)((int)this + 0xf0);
        }
        (*(&DAT_420be868)[param_4 * 2])(param_3,uVar4,iVar3);
        uVar4 = uVar4 + iVar3;
        uVar2 = param_4 ^ 1;
        local_c = local_c >> 1;
      } while (local_c != 0);
      if (local_8 != param_2 + -1) {
        iVar3 = *(int *)((int)this + 0xec);
        (*(&DAT_420be868)[uVar2 * 2])(param_3,uVar4,iVar3);
        uVar4 = uVar4 + iVar3;
        uVar2 = param_4;
      }
      local_8 = local_8 + 1;
      param_4 = uVar2;
    } while (local_8 < param_2);
  }
  if (*(int *)((int)this + 0x1c) != 0) {
    (*(&DAT_420be868)[uVar2 * 2])(param_3,uVar4,*(undefined4 *)((int)this + 0xf4));
  }
  return 0;
}


