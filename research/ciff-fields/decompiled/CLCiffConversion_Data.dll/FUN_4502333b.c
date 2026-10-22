// Source: CLCiffConversion_Data.dll @ 4502333b; __IsExceptionObjectToBeDestroyed

/* Library Function - Single Match
    __IsExceptionObjectToBeDestroyed
   
   Library: Visual Studio 2012 Release */

undefined4 __cdecl __IsExceptionObjectToBeDestroyed(int param_1)

{
  int *piVar1;
  _ptiddata p_Var2;
  
  p_Var2 = __getptd();
  piVar1 = p_Var2->_pFrameInfoChain;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 1;
    }
    if (*piVar1 == param_1) break;
    piVar1 = (int *)piVar1[1];
  }
  return 0;
}


