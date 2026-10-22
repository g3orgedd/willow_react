// Source: CiffMgr.dll @ 681114df; FUN_681114df

void __fastcall FUN_681114df(int param_1)

{
  int iVar1;
  undefined8 *_Memory;
  undefined8 *puVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 0x14) + iVar1;
  _Memory = *(undefined8 **)(param_1 + 4);
  *(int *)(param_1 + 8) = iVar3;
  puVar2 = (undefined8 *)FUN_68130f16(*(int *)(param_1 + 0x10) * iVar3);
  *(undefined8 **)(param_1 + 4) = puVar2;
  if (puVar2 == (undefined8 *)0x0) {
    *(undefined8 **)(param_1 + 4) = _Memory;
    *(int *)(param_1 + 8) = iVar1;
  }
  else if (_Memory != (undefined8 *)0x0) {
    FUN_681310e0(puVar2,_Memory,*(int *)(param_1 + 0x10) * iVar1);
    FID_conflict__free(_Memory);
  }
  return;
}


