// Source: CLCiffConversion_Data.dll @ 4502e027; _abort

/* Library Function - Single Match
    _abort
   
   Library: Visual Studio 2012 Release */

void __cdecl _abort(void)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  
  iVar2 = FUN_45034725();
  if (iVar2 != 0) {
    FUN_4503474e(0x16);
  }
  if (((byte)DAT_45052210 & 2) != 0) {
    BVar3 = IsProcessorFeaturePresent(0x17);
    if (BVar3 != 0) {
      pcVar1 = (code *)swi(0x29);
      (*pcVar1)();
    }
    FUN_45027ccc(3,0x40000015,1);
  }
                    /* WARNING: Subroutine does not return */
  __exit(3);
}


