// Source: CiffHelper.dll @ 40804d06; FUN_40804d06

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_40804d06(void *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  LPCWSTR local_18;
  undefined *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x40804d12;
  iVar3 = 1;
  iVar2 = FUN_40804db2();
  if (0 < iVar2) {
    do {
      FUN_40804c79(&local_18);
      local_8 = 0;
      bVar1 = FUN_40805005(local_18,(ushort *)*param_2);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        local_14[0] = PTR_DAT_40862014;
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_408051a5(local_14,L"%s_%s");
        FUN_408030ad(param_1,(int *)local_14);
        FUN_40803143((int *)local_14);
        FUN_40803143((int *)&local_18);
        return param_1;
      }
      local_8 = 0xffffffff;
      FUN_40803143((int *)&local_18);
      iVar3 = iVar3 + 1;
      iVar2 = FUN_40804db2();
    } while (iVar3 <= iVar2);
  }
  FUN_40803c8a(param_1,"");
  return param_1;
}


