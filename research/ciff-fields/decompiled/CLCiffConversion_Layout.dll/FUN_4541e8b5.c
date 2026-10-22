// Source: CLCiffConversion_Layout.dll @ 4541e8b5; FUN_4541e8b5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __fastcall FUN_4541e8b5(void *param_1)

{
  bool bVar1;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x4541e8c1;
  FUN_4541d03c(param_1,local_14);
  local_8 = 0;
  bVar1 = FUN_45402d4b(local_14,L"FixedBitmap");
  SysFreeString(local_14[0]);
  return bVar1;
}


