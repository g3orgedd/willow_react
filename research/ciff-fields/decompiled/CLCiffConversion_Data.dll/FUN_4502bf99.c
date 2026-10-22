// Source: CLCiffConversion_Data.dll @ 4502bf99; FUN_4502bf99

void FUN_4502bf99(void)

{
  _ptiddata p_Var1;
  int iVar2;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + -4) = *(undefined4 *)(unaff_EBP + -0x28);
  __FindAndUnlinkFrame(*(void **)(unaff_EBP + -0x2c));
  p_Var1 = __getptd();
  p_Var1->_curexception = *(void **)(unaff_EBP + -0x30);
  p_Var1 = __getptd();
  p_Var1->_curcontext = *(void **)(unaff_EBP + -0x34);
  if (((((*unaff_ESI == -0x1f928c9d) && (unaff_ESI[4] == 3)) &&
       ((unaff_ESI[5] == 0x19930520 ||
        ((unaff_ESI[5] == 0x19930521 || (unaff_ESI[5] == 0x19930522)))))) &&
      (*(int *)(unaff_EBP + -0x38) == 0)) &&
     ((*(int *)(unaff_EBP + -0x1c) != 0 &&
      (iVar2 = __IsExceptionObjectToBeDestroyed(unaff_ESI[6]), iVar2 != 0)))) {
    ___DestructExceptionObject(unaff_ESI);
  }
  return;
}


