// Source: CLCSBarcodeField.dll @ 4141508b; FUN_4141508b

INT_PTR __thiscall FUN_4141508b(void *this,HWND param_1,LPARAM param_2)

{
  int iVar1;
  INT_PTR IVar2;
  
  iVar1 = FUN_41415aad((void *)((int)this + 0x14),0,(void *)0x0);
  if (iVar1 == 0) {
    SetLastError(0xe);
    IVar2 = -1;
  }
  else {
    FUN_41413c6d(0x414ae484,(int *)((int)this + 8),(int)this);
    IVar2 = DialogBoxParamW(DAT_414b1828,(LPCWSTR)(uint)*(ushort *)((int)this + 0x38),param_1,
                            FUN_41415fae,param_2);
  }
  return IVar2;
}


