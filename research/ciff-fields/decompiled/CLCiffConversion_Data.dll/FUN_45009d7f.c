// Source: CLCiffConversion_Data.dll @ 45009d7f; FUN_45009d7f

void FUN_45009d7f(void)

{
  DWORD DVar1;
  uint uVar2;
  
  DVar1 = GetLastError();
  uVar2 = DVar1 & 0xffff | 0x80070000;
  if ((int)DVar1 < 1) {
    uVar2 = DVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_45002735(uVar2);
}


