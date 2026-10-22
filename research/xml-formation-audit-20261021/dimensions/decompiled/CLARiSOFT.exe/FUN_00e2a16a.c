// Source: CLARiSOFT.exe @ 00e2a16a; FUN_00e2a16a

void __fastcall FUN_00e2a16a(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  BSTR pOVar4;
  BSTR pOVar5;
  
  piVar1 = (int *)FUN_00e77808((void *)(param_1 + 4),0);
  if (*piVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar1 + -100;
  }
  pOVar5 = *(BSTR *)(param_1 + 0x160);
  if (pOVar5 != (BSTR)0x0) {
    (**(code **)(*(int *)pOVar5 + 4))(pOVar5);
  }
  pOVar4 = *(BSTR *)(param_1 + 0x19c);
  if (pOVar4 != (BSTR)0x0) {
    (**(code **)(*(int *)pOVar4 + 4))(pOVar4);
  }
  uVar2 = FUN_00eb1fd0((void *)(param_1 + 0x1ac),pOVar4,pOVar5);
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  InvalidateRect(*(HWND *)(iVar3 + 4),(RECT *)0x0,1);
  return;
}


