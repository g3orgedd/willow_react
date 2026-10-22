// Source: CLCSSmallBarcode.dll @ 42044704; FUN_42044704

INT_PTR __thiscall FUN_42044704(void *this,HWND param_1,LPARAM param_2)

{
  int iVar1;
  INT_PTR IVar2;
  
  iVar1 = FUN_420239c1((void *)((int)this + 0x14),0,(void *)0x0);
  if (iVar1 == 0) {
    SetLastError(0xe);
    IVar2 = -1;
  }
  else {
    FUN_42022bbe(0x420be8c8,(int *)((int)this + 8),(int)this);
    IVar2 = DialogBoxParamW(DAT_420c6598,(LPCWSTR)(uint)*(ushort *)((int)this + 0x38),param_1,
                            FUN_42039848,param_2);
  }
  return IVar2;
}


