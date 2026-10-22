// Source: CiffMgr.dll @ 68111467; FUN_68111467

void __thiscall FUN_68111467(void *this,int param_1)

{
  int iVar1;
  undefined8 *_Memory;
  undefined8 *puVar2;
  int iVar3;
  
  iVar1 = *(int *)((int)this + 8);
  iVar3 = *(int *)((int)this + 0x14) + iVar1;
  _Memory = *(undefined8 **)((int)this + 4);
  *(int *)((int)this + 8) = iVar3;
  puVar2 = (undefined8 *)FUN_68130f16(*(int *)((int)this + 0x10) * iVar3);
  *(undefined8 **)((int)this + 4) = puVar2;
  if (puVar2 == (undefined8 *)0x0) {
    *(undefined8 **)((int)this + 4) = _Memory;
    *(int *)((int)this + 8) = iVar1;
  }
  else {
    FUN_681310e0(puVar2,_Memory,*(int *)((int)this + 0x10) * param_1);
    FUN_681310e0((undefined8 *)(*(int *)((int)this + 4) + param_1 * 8 + 8),_Memory + param_1,
                 (iVar1 - param_1) * *(int *)((int)this + 0x10));
    FID_conflict__free(_Memory);
  }
  return;
}


