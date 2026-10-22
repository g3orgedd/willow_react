// Source: CLCSGraphicBasedField.dll @ 41c0bc21; FUN_41c0bc21

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

bool __cdecl FUN_41c0bc21(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 uStack_2c;
  int *piStack_28;
  int **ppiStack_24;
  undefined1 auStack_20 [24];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  puVar2 = (undefined4 *)auStack_20;
  piStack_28 = (int *)*param_1;
  bVar3 = piStack_28 == (int *)0x0;
  if (!bVar3) {
    param_1 = (int *)0x0;
    ppiStack_24 = &param_1;
    local_8 = 0;
    puVar1 = &uStack_2c;
    uStack_2c = 0x41c0bc4b;
    (**(code **)(*piStack_28 + 0x1c))();
    puVar1[-1] = L"Generic";
    puVar1[-2] = 0x41c0bc58;
    FUN_41c01781(&param_1,(OLECHAR *)puVar1[-1]);
    puVar1[-1] = param_1;
    puVar2 = puVar1 + -2;
    puVar1[-2] = 0x41c0bc61;
    SysFreeString((BSTR)puVar1[-1]);
  }
  *(undefined4 *)((int)puVar2 + -4) = 0x41c0bc68;
  return bVar3;
}


