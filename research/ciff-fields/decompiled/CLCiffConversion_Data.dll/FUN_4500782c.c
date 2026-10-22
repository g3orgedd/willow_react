// Source: CLCiffConversion_Data.dll @ 4500782c; FUN_4500782c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * FUN_4500782c(undefined2 *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  wchar_t wVar6;
  
  iVar5 = 0;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  iVar1 = param_2[4];
  if (0 < iVar1) {
    do {
      puVar4 = param_2;
      if (7 < (uint)param_2[5]) {
        puVar4 = (undefined4 *)*param_2;
      }
      uVar2 = _tolower((uint)*(ushort *)((int)puVar4 + iVar5 * 2));
      iVar3 = FUN_450075f7(uVar2);
      if ((char)iVar3 == '\0') {
        puVar4 = param_2;
        if (7 < (uint)param_2[5]) {
          puVar4 = (undefined4 *)*param_2;
        }
        wVar6 = *(wchar_t *)((int)puVar4 + iVar5 * 2);
      }
      else {
        wVar6 = L'Z';
      }
      FUN_45007a89(param_1,1,wVar6);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  return param_1;
}


