// Source: CLARiSOFT.exe @ 00e2c555; FUN_00e2c555

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_00e2c555(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  LPCWSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0xe2c561;
  iVar3 = 1;
  iVar2 = FUN_00e0ecf4();
  if (0 < iVar2) {
    do {
      FUN_00e0ea98(local_14);
      local_8 = 0;
      bVar1 = FUN_00e0ef26(local_14[0],(ushort *)*param_1);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        FUN_00e01f81((int *)local_14);
        return 1;
      }
      local_8 = 0xffffffff;
      FUN_00e01f81((int *)local_14);
      iVar3 = iVar3 + 1;
      iVar2 = FUN_00e0ecf4();
    } while (iVar3 <= iVar2);
  }
  return 0;
}


