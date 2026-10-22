// Source: CiffMgr.dll @ 6810bbc5; FUN_6810bbc5

ulong __cdecl FUN_6810bbc5(ulong param_1,ulong param_2)

{
  long lVar1;
  ulong local_8;
  
  lVar1 = ATL::AtlMultiply<unsigned_long>(&local_8,param_1,param_2);
  if (-1 < lVar1) {
    return local_8;
  }
                    /* WARNING: Subroutine does not return */
  FUN_681024d6(lVar1);
}


