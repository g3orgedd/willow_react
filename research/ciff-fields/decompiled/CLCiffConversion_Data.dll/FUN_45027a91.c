// Source: CLCiffConversion_Data.dll @ 45027a91; FUN_45027a91

undefined4 FUN_45027a91(void)

{
  int iVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  
  FUN_4502dcdf();
  iVar1 = FUN_45031f08();
  if (iVar1 != 0) {
    DAT_45051e20 = FUN_4502ebf5(FUN_450277ec);
    if (DAT_45051e20 != 0xffffffff) {
      pDVar2 = FUN_4502dee1(1,0x3bc);
      if (pDVar2 != (DWORD *)0x0) {
        iVar1 = FUN_4502ec51(DAT_45051e20,pDVar2);
        if (iVar1 != 0) {
          FUN_450279de((int)pDVar2,0);
          DVar3 = GetCurrentThreadId();
          pDVar2[1] = 0xffffffff;
          *pDVar2 = DVar3;
          return 1;
        }
      }
      __mtterm();
      return 0;
    }
  }
  __mtterm();
  return 0;
}


