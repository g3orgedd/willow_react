// Source: CLARiSOFT.exe @ 00e5630b; FUN_00e5630b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __fastcall FUN_00e5630b(int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  UINT UVar4;
  undefined1 uVar5;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  uVar5 = 0;
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  if (*param_1 != 0) {
    piVar1 = param_1 + 3;
    SysFreeString((BSTR)*piVar1);
    *piVar1 = 0;
    iVar3 = (**(code **)(*(int *)*param_1 + 0x44))((int *)*param_1,piVar1);
    if (-1 < iVar3) {
      piVar1 = param_1 + 4;
      iVar3 = FUN_00e563e9(piVar1);
      if (iVar3 < 0) {
        UVar4 = SysStringLen((BSTR)*piVar1);
        if (UVar4 == 0) {
          bVar2 = FUN_00e562da((int)param_1);
          *(bool *)(param_1 + 5) = bVar2;
        }
      }
      else {
        iVar3 = (**(code **)(*(int *)param_1[2] + 0x20))((int *)param_1[2],local_14);
      }
      if (-1 < iVar3) {
        FUN_00e061b9(piVar1);
        FUN_00e061b9(local_14);
        bVar2 = FUN_00e562da((int)param_1);
        if ((bVar2) &&
           (iVar3 = FUN_00ecf1ea((ushort *)*piVar1,(ushort *)local_14[0],100), iVar3 == 0)) {
          uVar5 = 1;
        }
        *(undefined1 *)(param_1 + 5) = uVar5;
      }
    }
  }
  iVar3 = param_1[5];
  SysFreeString(local_14[0]);
  return (char)iVar3;
}


