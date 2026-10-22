// Source: CLCiffConversion_Data.dll @ 450077a4; FUN_450077a4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined2 * FUN_450077a4(undefined2 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  wchar_t wVar5;
  
  iVar4 = 0;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  iVar1 = param_2[4];
  if (0 < iVar1) {
    do {
      puVar3 = param_2;
      if (7 < (uint)param_2[5]) {
        puVar3 = (undefined4 *)*param_2;
      }
      iVar2 = FUN_450075d2((uint)*(ushort *)((int)puVar3 + iVar4 * 2));
      if ((char)iVar2 == '\0') {
        puVar3 = param_2;
        if (7 < (uint)param_2[5]) {
          puVar3 = (undefined4 *)*param_2;
        }
        wVar5 = *(wchar_t *)((int)puVar3 + iVar4 * 2);
      }
      else {
        wVar5 = L'2';
      }
      FUN_45007a89(param_1,1,wVar5);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return param_1;
}


