// Source: CLCiffConversion_Data.dll @ 4501469d; FUN_4501469d

int __fastcall FUN_4501469d(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + 4);
  FUN_450147ad((int)puVar1);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_45053870 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_4500a222((LPCRITICAL_SECTION)(param_1 + 0x10));
  *puVar1 = 0x24;
  return param_1;
}


