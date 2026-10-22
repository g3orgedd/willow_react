// Source: CiffHelper.dll @ 4081660d; FUN_4081660d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_4081660d(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  LPCWSTR pWVar2;
  WCHAR local_18 [8];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_1;
  uStack_4 = 8;
  local_8 = 0;
  param_1[1] = 0;
  *param_1 = 0;
  if (param_2 != (int *)0x0) {
    param_1 = (undefined4 *)0x0;
    (**(code **)(*param_2 + 0xc4))(param_2,&param_1);
    if (param_1 == (undefined4 *)0x0) {
      pWVar2 = FUN_40805c31(local_18);
      *puVar1 = *(undefined4 *)pWVar2;
      puVar1[1] = *(undefined4 *)(pWVar2 + 2);
    }
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return puVar1;
}


