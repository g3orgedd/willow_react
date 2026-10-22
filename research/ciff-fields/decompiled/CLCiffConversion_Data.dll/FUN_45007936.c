// Source: CLCiffConversion_Data.dll @ 45007936; FUN_45007936

undefined4 * __fastcall FUN_45007936(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_Allocate<>(1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = *param_1;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *param_1;
  }
  return puVar1;
}


