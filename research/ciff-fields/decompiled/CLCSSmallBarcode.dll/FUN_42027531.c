// Source: CLCSSmallBarcode.dll @ 42027531; FUN_42027531

void __thiscall FUN_42027531(void *this,uint *param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  void *local_8;
  
  local_8 = this;
  iVar4 = (param_3 - 1) + param_2;
  iVar5 = (int)((iVar4 >> 0x1f & 0x1fU) + iVar4) >> 5;
  uVar1 = 0x80000000 >> ((byte)param_2 & 0x1f);
  if (iVar5 == 0) {
    uVar3 = 0;
    param_3 = ~(uVar1 * 2 - 1) | 0x7fffffff >> ((byte)iVar4 & 0x1f);
    do {
      *(undefined1 *)((int)&param_2 + uVar3) = *(undefined1 *)((int)&param_3 + (~uVar3 & 3));
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 4);
    while (param_4 = param_4 + -1, -1 < param_4) {
      *param_1 = *param_1 & param_2;
      param_1 = param_1 + -*(int *)((int)this + 0x14);
    }
  }
  else {
    param_3 = ~(uVar1 * 2 - 1);
    uVar1 = 0;
    local_8 = (void *)(0x7fffffff >> ((byte)iVar4 & 0x1f));
    do {
      *(undefined1 *)((int)&param_2 + uVar1) = *(undefined1 *)((int)&param_3 + (~uVar1 & 3));
      uVar3 = param_2;
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < 4);
    uVar1 = 0;
    param_3 = param_2;
    do {
      *(undefined1 *)((int)&param_2 + uVar1) = *(undefined1 *)((int)&local_8 + (~uVar1 & 3));
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < 4);
    while (param_4 = param_4 + -1, -1 < param_4) {
      *param_1 = *param_1 & uVar3;
      puVar2 = param_1;
      iVar4 = iVar5;
      while (iVar4 = iVar4 + -1, iVar4 != 0) {
        puVar2 = puVar2 + 1;
        *puVar2 = 0;
      }
      puVar2[1] = puVar2[1] & param_2;
      param_1 = param_1 + -*(int *)((int)this + 0x14);
      uVar3 = param_3;
    }
  }
  return;
}


