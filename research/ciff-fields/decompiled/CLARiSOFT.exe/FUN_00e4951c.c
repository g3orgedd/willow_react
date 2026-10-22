// Source: CLARiSOFT.exe @ 00e4951c; FUN_00e4951c

uint __thiscall FUN_00e4951c(void *this,void *param_1)

{
  uint in_EAX;
  uint uVar1;
  HGLOBAL hMem;
  LPVOID pvVar2;
  SIZE_T dwBytes;
  
  if (param_1 == (void *)0x0) {
    uVar1 = in_EAX & 0xffffff00;
  }
  else {
    dwBytes = (uint)*(ushort *)((int)param_1 + 0x46) + (uint)*(ushort *)((int)param_1 + 0x44);
    hMem = GlobalAlloc(2,dwBytes);
    if (hMem != (HGLOBAL)0x0) {
      pvVar2 = GlobalLock(hMem);
      FUN_00e06e7b(pvVar2,dwBytes,param_1,dwBytes);
      GlobalUnlock(hMem);
    }
    FUN_00e487e5(this,hMem);
    uVar1 = (uint)(hMem != (HGLOBAL)0x0);
  }
  return uVar1;
}


