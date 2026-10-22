// Source: CLCiffConversion_Layout.dll @ 4542acd9; _JumpToContinuation

/* Library Function - Single Match
    void __stdcall _JumpToContinuation(void *,struct EHRegistrationNode *)
   
   Library: Visual Studio 2015 Release */

void _JumpToContinuation(void *param_1,EHRegistrationNode *param_2)

{
  ExceptionList = *(void **)ExceptionList;
                    /* WARNING: Could not recover jumptable at 0x4542ad02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)();
  return;
}


