// Source: CLCSTextBasedField.dll @ 42459daa; FUN_42459daa

undefined2 * FUN_42459daa(void)

{
  undefined2 *puVar1;
  
  if (DAT_424bfff0 == 0) {
    puVar1 = FUN_42459e10();
    _swprintf_s(&DAT_424bfff0,0x104,L"%sFonts\\",puVar1);
  }
  return &DAT_424bfff0;
}


