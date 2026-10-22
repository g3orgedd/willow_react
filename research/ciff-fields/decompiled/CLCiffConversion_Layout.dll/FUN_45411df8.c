// Source: CLCiffConversion_Layout.dll @ 45411df8; FUN_45411df8

undefined4 __fastcall FUN_45411df8(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  UNRECOVERED_JUMPTABLE = (code *)FUN_45410be5(param_1);
  *(code **)(param_1 + 0xcc) = UNRECOVERED_JUMPTABLE;
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x45411e0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0;
}


