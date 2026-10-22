// Source: CLCiffConversion_Layout.dll @ 4541b8d6; FUN_4541b8d6

undefined4 __thiscall FUN_4541b8d6(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  uVar5 = 0;
  iVar4 = *(int *)this;
  if (*(int *)((int)this + 4) - iVar4 >> 2 != 0) {
    do {
      uVar1 = *(undefined4 *)(iVar4 + uVar5 * 4);
      puVar6 = param_1;
      puVar3 = (undefined4 *)FUN_45421dcf(uVar1);
      bVar2 = FUN_45402d7b(puVar3,puVar6);
      if (bVar2) {
        return uVar1;
      }
      uVar5 = uVar5 + 1;
      iVar4 = *(int *)this;
    } while (uVar5 < (uint)(*(int *)((int)this + 4) - iVar4 >> 2));
  }
  return 0;
}


