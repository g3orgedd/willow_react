// Source: CiffMgr.dll @ 6810c684; FUN_6810c684

LPVOID __cdecl FUN_6810c684(LPVOID param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  LPVOID pvVar2;
  ulong local_8;
  
  local_8 = 0;
  lVar1 = ATL::AtlMultiply<unsigned_long>(&local_8,param_2,param_3);
  if (lVar1 < 0) {
    pvVar2 = (LPVOID)0x0;
  }
  else {
    pvVar2 = CoTaskMemRealloc(param_1,local_8);
  }
  return pvVar2;
}


