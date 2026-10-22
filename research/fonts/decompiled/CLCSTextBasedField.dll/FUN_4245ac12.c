// Source: CLCSTextBasedField.dll @ 4245ac12; FUN_4245ac12

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4245ac12(void *this,undefined4 *param_1)

{
  undefined4 *_Memory;
  HDC hdc;
  void *this_00;
  undefined4 uVar1;
  int nNumerator;
  HFONT pHVar2;
  BSTR pOVar3;
  int nDenominator;
  LOGFONTW local_70;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0x4245ac1e;
  hdc = GetDC(*(HWND *)((int)this + 4));
  _Memory = *(undefined4 **)((int)this + 0x38);
  *(undefined1 *)((int)this + 0x44) = 0;
  if (_Memory != (undefined4 *)0x0) {
    SysFreeString((BSTR)*_Memory);
    FID_conflict__free(_Memory);
    *(undefined4 *)((int)this + 0x38) = 0;
  }
  pOVar3 = (BSTR)0x10;
  this_00 = (void *)FUN_4246d133(0x10);
  local_8 = 0;
  if (this_00 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    FUN_424037d2(&stack0xffffff70,(OLECHAR *)*param_1);
    uVar1 = FUN_42428844(this_00,hdc,pOVar3);
  }
  *(undefined4 *)((int)this + 0x38) = uVar1;
  if (*(int *)((int)this + 0x30) != 0) {
    DeleteObject(*(HGDIOBJ *)((int)this + 0x30));
  }
  FUN_4246d990((uint *)&local_70,0,0x5c);
  FUN_4246f507(local_70.lfFaceName,0x20,(short *)*param_1,0x1f);
  local_70.lfWeight = 400;
  local_70.lfCharSet = '\x01';
  local_70.lfOutPrecision = '\a';
  local_70.lfQuality = '\x01';
  nDenominator = 0x48;
  nNumerator = GetDeviceCaps(hdc,0x5a);
  local_70.lfHeight = MulDiv(8,nNumerator,nDenominator);
  local_70.lfHeight = -local_70.lfHeight;
  ReleaseDC(*(HWND *)((int)this + 4),hdc);
  pHVar2 = CreateFontIndirectW(&local_70);
  *(HFONT *)((int)this + 0x30) = pHVar2;
  FUN_4246ecf6();
  return;
}


