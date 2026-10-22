// Source: CLCSSmallBarcode.dll @ 4206b65f; FUN_4206b65f

void FUN_4206b65f(void)

{
  code *pcVar1;
  
  pcVar1 = DecodePointer(DAT_420c6958);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  FUN_420742d5(0,1);
                    /* WARNING: Subroutine does not return */
  _abort();
}


