// Source: CLCiffConversion_Layout.dll @ 45424ffd; FUN_45424ffd

undefined4 FUN_45424ffd(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    puVar2 = (undefined4 *)FUN_4542ee51(0xc);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      *puVar2 = param_2;
      puVar2[1] = param_3;
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
      puVar2[2] = *(undefined4 *)(param_1 + 8);
      *(undefined4 **)(param_1 + 8) = puVar2;
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
      uVar1 = 0;
    }
  }
  return uVar1;
}


