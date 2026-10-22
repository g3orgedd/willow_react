// Source: CLCiffConversion_Data.dll @ 4500a81b; FUN_4500a81b

undefined4 * __cdecl FUN_4500a81b(undefined4 *param_1,short *param_2,short *param_3)

{
  short *psVar1;
  
  psVar1 = (short *)FUN_4500a4b2(param_2,param_3);
  if (psVar1 != param_3) {
    psVar1 = (short *)FUN_4500a78f(psVar1,param_3);
  }
  *param_1 = psVar1;
  return param_1;
}


