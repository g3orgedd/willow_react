// Source: CLARiSOFT.exe @ 00e2c4ea; FUN_00e2c4ea

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_00e2c4ea(ushort *param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  LPCWSTR local_14 [3];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0;
  uStack_7 = 0;
  iVar3 = 1;
  iVar2 = FUN_00e0ecf4();
  iVar4 = iVar3;
  if (0 < iVar2) {
    do {
      FUN_00e298a2(local_14);
      local_8 = 1;
      bVar1 = FUN_00e0ef26(local_14[0],param_1);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        FUN_00e01f81((int *)local_14);
        goto LAB_00e2c53e;
      }
      local_8 = bVar1;
      FUN_00e01f81((int *)local_14);
      iVar4 = iVar4 + 1;
      iVar2 = FUN_00e0ecf4();
    } while (iVar4 <= iVar2);
  }
  iVar3 = 0;
LAB_00e2c53e:
  FUN_00e01f81((int *)&param_1);
  return iVar3;
}


