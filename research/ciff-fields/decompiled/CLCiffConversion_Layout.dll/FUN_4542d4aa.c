// Source: CLCiffConversion_Layout.dll @ 4542d4aa; FUN_4542d4aa

/* WARNING: Removing unreachable block (ram,0x4542d4df) */

void __cdecl FUN_4542d4aa(longlong *param_1)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __aulldiv(local_c.dwLowDateTime + 0x2ac18000,
                    local_c.dwHighDateTime + 0xfe624e21 + (uint)(0xd53e7fff < local_c.dwLowDateTime)
                    ,10000000,0);
  if (0x793406fff < lVar1) {
    lVar1 = -1;
  }
  if (param_1 != (longlong *)0x0) {
    *param_1 = lVar1;
  }
  return;
}


