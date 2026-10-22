// Source: CLCSSmallBarcode.dll @ 42027a20; FUN_42027a20

void __thiscall FUN_42027a20(void *this,uint *param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  void *local_c;
  void *local_8;
  
  local_c = this;
  local_8 = this;
  iVar7 = (param_3 - 1) + param_2;
  bVar4 = (byte)iVar7 & 0x1f;
  iVar7 = (int)((iVar7 >> 0x1f & 0x1fU) + iVar7) >> 5;
  if (iVar7 == 0) {
    uVar5 = 0;
    param_3 = ~(0x7fffffff >> bVar4) & (0x80000000U >> ((byte)param_2 & 0x1f)) * 2 - 1;
    do {
      *(undefined1 *)((int)&param_2 + uVar5) = *(undefined1 *)((int)&param_3 + (~uVar5 & 3));
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 4);
    while (param_4 = param_4 + -1, -1 < param_4) {
      *param_1 = *param_1 | param_2;
      param_1 = param_1 + -*(int *)((int)this + 0x14);
    }
  }
  else {
    param_3 = (0x80000000U >> ((byte)param_2 & 0x1f)) * 2 - 1;
    uVar5 = 0;
    uVar6 = 0;
    local_c = (void *)~(0x7fffffff >> bVar4);
    do {
      *(undefined1 *)((int)&param_2 + uVar6) = *(undefined1 *)((int)&param_3 + (~uVar6 & 3));
      uVar2 = param_2;
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 4);
    param_3 = param_2;
    do {
      *(undefined1 *)((int)&param_2 + uVar5) = *(undefined1 *)((int)&local_c + (~uVar5 & 3));
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 4);
    while (param_4 = param_4 + -1, -1 < param_4) {
      *param_1 = *param_1 | uVar2;
      puVar3 = param_1;
      iVar1 = iVar7;
      while (iVar1 = iVar1 + -1, iVar1 != 0) {
        puVar3 = puVar3 + 1;
        *puVar3 = 0xffffffff;
      }
      puVar3[1] = puVar3[1] | param_2;
      param_1 = param_1 + -*(int *)((int)this + 0x14);
      uVar2 = param_3;
    }
  }
  return;
}


