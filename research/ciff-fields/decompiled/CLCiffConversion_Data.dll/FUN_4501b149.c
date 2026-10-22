// Source: CLCiffConversion_Data.dll @ 4501b149; FUN_4501b149

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_4501b149(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if ((undefined4 *)*param_1 == (undefined4 *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    iVar1 = 0;
    CComQIPtr<>(&param_1,(undefined4 *)*param_1);
    if (param_1 != (int *)0x0) {
      piVar2 = param_1;
      piVar3 = param_2;
      (**(code **)(*param_1 + 4))(param_1);
      iVar1 = FUN_4501b1aa(piVar2,piVar3);
    }
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  return iVar1;
}


