// Source: CLCiffConversion_Layout.dll @ 4543020f; FUN_4543020f

undefined4 FUN_4543020f(void)

{
  int iVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  
  FUN_45432250();
  iVar1 = FUN_4543aa1c();
  if (iVar1 != 0) {
    DAT_4545da34 = FUN_45439660(FUN_4542ff6a);
    if (DAT_4545da34 != 0xffffffff) {
      pDVar2 = FUN_454375c4(1,0x3bc);
      if (pDVar2 != (DWORD *)0x0) {
        iVar1 = FUN_454396bc(DAT_4545da34,pDVar2);
        if (iVar1 != 0) {
          FUN_4543015c((int)pDVar2,0);
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


