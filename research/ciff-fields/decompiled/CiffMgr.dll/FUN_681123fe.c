// Source: CiffMgr.dll @ 681123fe; FUN_681123fe

uint __thiscall FUN_681123fe(void *this,uint param_1)

{
  uint in_EAX;
  undefined8 *puVar1;
  uint uVar2;
  
  if (param_1 < *(uint *)((int)this + 0xc)) {
    if (*(int *)(*(int *)((int)this + 4) + param_1 * 8) != 0) {
      SysFreeString(*(BSTR *)(*(int *)((int)this + 4) + param_1 * 8));
      *(undefined4 *)(*(int *)((int)this + 4) + param_1 * 8) = 0;
    }
    *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + -1;
    puVar1 = (undefined8 *)(*(int *)((int)this + 4) + param_1 * 8);
    puVar1 = FUN_681317c0(puVar1,puVar1 + 1,
                          (*(int *)((int)this + 0xc) - param_1) * *(int *)((int)this + 0x10));
    uVar2 = CONCAT31((int3)((uint)puVar1 >> 8),1);
  }
  else {
    uVar2 = in_EAX & 0xffffff00;
  }
  return uVar2;
}


