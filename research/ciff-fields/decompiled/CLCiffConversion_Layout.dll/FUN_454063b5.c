// Source: CLCiffConversion_Layout.dll @ 454063b5; FUN_454063b5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x454064a5) */
/* WARNING: Removing unreachable block (ram,0x454064ad) */
/* WARNING: Removing unreachable block (ram,0x454064a0) */
/* WARNING: Removing unreachable block (ram,0x454064b2) */
/* WARNING: Removing unreachable block (ram,0x454064c5) */
/* WARNING: Removing unreachable block (ram,0x454064d5) */
/* WARNING: Removing unreachable block (ram,0x454064d8) */
/* WARNING: Removing unreachable block (ram,0x454064e1) */
/* WARNING: Removing unreachable block (ram,0x454064dc) */
/* WARNING: Removing unreachable block (ram,0x4540648f) */
/* WARNING: Removing unreachable block (ram,0x454064f7) */

int __cdecl FUN_454063b5(int *param_1,IUnknown *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  BSTR extraout_ECX;
  BSTR pOVar4;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x454063c1;
  piVar1 = (int *)*param_1;
  if ((piVar1 == (int *)0x0) || (param_2->lpVtbl == (IUnknownVtbl *)0x0)) {
    iVar2 = -0x7fffbffd;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0x140))(piVar1);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*(int *)*param_1 + 0x124))((int *)*param_1);
    }
    local_14[0] = (BSTR)0x0;
    local_8 = 0;
    if ((-1 < iVar2) &&
       (iVar2 = (**(code **)(*(int *)*param_1 + 0xa8))((int *)*param_1), -1 < iVar2)) {
      pOVar4 = extraout_ECX;
      FUN_4540288a(&stack0xffffffcc,(int *)local_14);
      uVar3 = FUN_4540611b(param_2,pOVar4);
      if (uVar3 == 0) {
        iVar2 = (**(code **)(*(int *)*param_1 + 0x158))((int *)*param_1);
      }
    }
    SysFreeString(local_14[0]);
  }
  return iVar2;
}


