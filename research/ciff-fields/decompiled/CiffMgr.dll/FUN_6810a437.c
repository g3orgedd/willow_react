// Source: CiffMgr.dll @ 6810a437; FUN_6810a437

undefined4 FUN_6810a437(int param_1,uint param_2,undefined4 param_3)

{
  undefined8 *_Memory;
  longlong lVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x88) != 0) {
    return 0x80070005;
  }
  if (99 < param_2) {
    return 0x80070057;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (*(int *)(param_1 + 0xa4) <= (int)param_2) {
    _Memory = *(undefined8 **)(param_1 + 0xa8);
    lVar1 = (ulonglong)(*(int *)(param_1 + 0xa4) + 0x19) * 8;
    puVar2 = (undefined8 *)FUN_68130f16(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1)
    ;
    *(undefined8 **)(param_1 + 0xa8) = puVar2;
    if (puVar2 == (undefined8 *)0x0) {
      uVar3 = 0x8007000e;
      *(undefined8 **)(param_1 + 0xa8) = _Memory;
      goto LAB_6810a50c;
    }
    FUN_681310e0(puVar2,_Memory,*(int *)(param_1 + 0xa4) << 3);
    FUN_68132710((uint *)(*(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0xa4) * 8),0,200);
    FID_conflict__free(_Memory);
    *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + 0x19;
  }
  *(undefined4 *)(*(int *)(param_1 + 0xa8) + param_2 * 8) = param_3;
  *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 4;
  if (*(int *)(param_1 + 0xa0) <= (int)param_2) {
    *(uint *)(param_1 + 0xa0) = param_2 + 1;
  }
LAB_6810a50c:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return uVar3;
}


