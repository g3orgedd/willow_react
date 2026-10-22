// Source: CLCiffConversion_Layout.dll @ 4541c12a; FUN_4541c12a

undefined4 __thiscall FUN_4541c12a(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  bool bVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar4 = 0;
  if (*(int *)((int)this + 0x1c) - *(int *)((int)this + 0x18) >> 2 != 0) {
    do {
      uVar1 = *(undefined4 *)(*(int *)((int)this + 0x18) + uVar4 * 4);
      puVar5 = param_1;
      puVar3 = (undefined4 *)FUN_45421dcf(uVar1);
      bVar2 = FUN_45402d7b(puVar3,puVar5);
      if (bVar2) {
        return uVar1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(*(int *)((int)this + 0x1c) - *(int *)((int)this + 0x18) >> 2));
  }
  return 0;
}


