// Source: CLCiffConversion_Data.dll @ 4502086a; FUN_4502086a

undefined4 __fastcall FUN_4502086a(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_4501fa83(param_1);
  *(code **)(param_1 + 0xcc) = UNRECOVERED_JUMPTABLE;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x4502087f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0;
}


