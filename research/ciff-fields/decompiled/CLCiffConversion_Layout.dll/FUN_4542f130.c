// Source: CLCiffConversion_Layout.dll @ 4542f130; ___DllMainCRTStartup

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2012 Release */

uint __cdecl ___DllMainCRTStartup(HMODULE param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 1;
  if ((param_2 == 0) && (DAT_45460b70 == 0)) {
LAB_4542f236:
    uVar2 = 0;
  }
  else {
    if ((param_2 == 1) || (param_2 == 2)) {
      if (DAT_4544c070 != (code *)0x0) {
        iVar1 = (*DAT_4544c070)(param_1,param_2,param_3);
      }
      if ((iVar1 == 0) || (iVar1 = FUN_4542ef9b(param_1,param_2,param_3), iVar1 == 0))
      goto LAB_4542f236;
    }
    uVar2 = FUN_45428526(param_1,param_2);
    if ((param_2 == 1) && (uVar2 == 0)) {
      FUN_45428526(param_1,0);
      FUN_4542ef9b(param_1,0,param_3);
      if (DAT_4544c070 != (code *)0x0) {
        (*DAT_4544c070)(param_1,0,param_3);
      }
    }
    if ((param_2 == 0) || (param_2 == 3)) {
      iVar1 = FUN_4542ef9b(param_1,param_2,param_3);
      uVar2 = uVar2 & -(uint)(iVar1 != 0);
      if ((uVar2 != 0) && (DAT_4544c070 != (code *)0x0)) {
        uVar2 = (*DAT_4544c070)(param_1,param_2,param_3);
      }
    }
  }
  return uVar2;
}


