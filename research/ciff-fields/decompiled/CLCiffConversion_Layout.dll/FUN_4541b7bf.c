// Source: CLCiffConversion_Layout.dll @ 4541b7bf; FUN_4541b7bf

void __fastcall FUN_4541b7bf(int *param_1)

{
  LPUNKNOWN punkOuter;
  LPUNKNOWN *ppunkMarshal;
  
  ppunkMarshal = (LPUNKNOWN *)(param_1 + 0xb);
  punkOuter = (LPUNKNOWN)(**(code **)(*param_1 + 0x10))();
  CoCreateFreeThreadedMarshaler(punkOuter,ppunkMarshal);
  return;
}


