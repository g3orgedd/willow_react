// Source: CLCiffConversion_Data.dll @ 4502bd7c; ___DestructExceptionObject

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___DestructExceptionObject
   
   Library: Visual Studio 2012 Release */

void __cdecl ___DestructExceptionObject(int *param_1)

{
  byte *pbVar1;
  int *piVar2;
  
  if ((((param_1 != (int *)0x0) && (*param_1 == -0x1f928c9d)) && (param_1[4] == 3)) &&
     ((((param_1[5] == 0x19930520 || (param_1[5] == 0x19930521)) || (param_1[5] == 0x19930522)) &&
      (pbVar1 = (byte *)param_1[7], pbVar1 != (byte *)0x0)))) {
    if (*(undefined **)(pbVar1 + 4) == (undefined *)0x0) {
      if (((*pbVar1 & 0x10) != 0) && (piVar2 = *(int **)param_1[6], piVar2 != (int *)0x0)) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
    }
    else {
      FID_conflict__CallMemberFunction1(param_1[6],*(undefined **)(pbVar1 + 4));
    }
  }
  return;
}


