// Source: CLCiffConversion_Data.dll @ 4502c8d6; ___FrameUnwindFilter

/* Library Function - Single Match
    ___FrameUnwindFilter
   
   Library: Visual Studio 2012 Release */

undefined4 __cdecl ___FrameUnwindFilter(undefined4 *param_1)

{
  int *piVar1;
  _ptiddata p_Var2;
  undefined4 extraout_EAX;
  
  piVar1 = (int *)*param_1;
  if ((*piVar1 == -0x1fbcbcae) || (*piVar1 == -0x1fbcb0b3)) {
    p_Var2 = __getptd();
    if (0 < p_Var2->_ProcessingThrow) {
      p_Var2 = __getptd();
      p_Var2->_ProcessingThrow = p_Var2->_ProcessingThrow + -1;
    }
  }
  else if (*piVar1 == -0x1f928c9d) {
    p_Var2 = __getptd();
    p_Var2->_ProcessingThrow = 0;
    terminate();
    return extraout_EAX;
  }
  return 0;
}


