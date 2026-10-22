// Source: CLCiffConversion_Data.dll @ 45023882; FUN_45023882

void FUN_45023882(void)

{
  code *pcVar1;
  
  pcVar1 = DecodePointer(DAT_450553dc);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  FUN_4502e008(0,1);
                    /* WARNING: Subroutine does not return */
  _abort();
}


