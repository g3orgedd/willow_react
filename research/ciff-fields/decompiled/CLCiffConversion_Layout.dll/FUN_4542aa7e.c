// Source: CLCiffConversion_Layout.dll @ 4542aa7e; __TranslatorGuardHandler

/* Library Function - Single Match
    __TranslatorGuardHandler
   
   Library: Visual Studio 2015 Release */

undefined4 __cdecl
__TranslatorGuardHandler(_CONTEXT *param_1,EHRegistrationNode *param_2,_CONTEXT *param_3)

{
  undefined4 uVar1;
  code *local_8;
  
  FUN_4542a8d1(*(uint *)(param_2 + 8) ^ (uint)param_2);
  if ((param_1->Dr0 & 0x66) != 0) {
    *(undefined4 *)(param_2 + 0x24) = 1;
    return 1;
  }
  FUN_4543100d(param_1,*(EHRegistrationNode **)(param_2 + 0x10),param_3,(void *)0x0,
               *(uint **)(param_2 + 0xc),*(int *)(param_2 + 0x14),
               *(EHRegistrationNode **)(param_2 + 0x18),'\x01');
  if (*(int *)(param_2 + 0x24) == 0) {
    _UnwindNestedFrames(param_2,(EHExceptionRecord *)param_1);
  }
  FUN_4542ab84((undefined4 *)0x123,&local_8,0,0,0,0,0);
                    /* WARNING: Could not recover jumptable at 0x4542ab13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*local_8)();
  return uVar1;
}


