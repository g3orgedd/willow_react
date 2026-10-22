// Source: CLCiffConversion_Data.dll @ 4501bb4b; FUN_4501bb4b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_4501bb4b(void *this,BSTR param_1,int param_2,undefined4 *param_3)

{
  BSTR pOVar1;
  int iVar2;
  UINT UVar3;
  UINT local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_1;
  uStack_4 = 0xc;
  local_8 = 0x4501bb57;
  if ((param_1 == (BSTR)0x0) || (param_3 == (undefined4 *)0x0)) {
    return -0x7fffbffd;
  }
  local_14[0] = 0;
  iVar2 = (**(code **)(*(int *)param_1 + 0x3c))(param_1,local_14);
  if (iVar2 < 0) {
    return iVar2;
  }
  param_1 = (BSTR)0x0;
  local_8 = 0;
  if (param_2 == 0) {
LAB_4501bbd4:
    param_1 = (BSTR)0x0;
    iVar2 = (**(code **)(*(int *)pOVar1 + 0x44))(pOVar1,&param_1);
    if (-1 < iVar2) {
      (**(code **)(*(int *)pOVar1 + 0x58))(pOVar1,param_1);
    }
  }
  else if (param_2 == 1) {
    iVar2 = (**(code **)(*(int *)pOVar1 + 0x54))(pOVar1,&param_1);
    if ((-1 < iVar2) && (UVar3 = SysStringLen(param_1), UVar3 == 0)) {
      SysFreeString(param_1);
      goto LAB_4501bbd4;
    }
  }
  else if (param_2 == 2) {
    (**(code **)(*(int *)pOVar1 + 0x54))(pOVar1,&param_1);
    *(undefined1 *)((int)this + 8) = 1;
  }
  if (local_14[0] == 1) {
    iVar2 = (**(code **)(*(int *)pOVar1 + 0x34))(pOVar1,&local_18);
    if (iVar2 < 0) goto LAB_4501bc44;
    param_2 = 0;
    iVar2 = (**(code **)(*(int *)pOVar1 + 0x2c))(pOVar1,&param_2);
    if (iVar2 < 0) goto LAB_4501bc44;
    iVar2 = FUN_4501bfd4(local_18,(int *)&param_1,(OLECHAR)param_2);
    if (iVar2 < 0) goto LAB_4501bc44;
    if (iVar2 == 0) {
      (**(code **)(*(int *)pOVar1 + 0x58))(pOVar1,param_1);
    }
  }
  pOVar1 = param_1;
  iVar2 = 0;
  param_1 = (BSTR)0x0;
  *param_3 = pOVar1;
LAB_4501bc44:
  SysFreeString(param_1);
  return iVar2;
}


