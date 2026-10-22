// Source: CLCSBarcodeField.dll @ 414625da; FUN_414625da

void FUN_414625da(void)

{
  code *pcVar1;
  
  pcVar1 = DecodePointer(DAT_414b1be4);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  FUN_4146c765(0,1);
                    /* WARNING: Subroutine does not return */
  _abort();
}


