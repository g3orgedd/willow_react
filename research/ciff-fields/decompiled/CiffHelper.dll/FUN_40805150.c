// Source: CiffHelper.dll @ 40805150; FUN_40805150

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_40805150(void *this,int *param_1)

{
  undefined2 uVar1;
  int extraout_EAX;
  undefined2 uVar2;
  int iVar3;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  iVar3 = 0;
  local_8 = 0;
  local_14[0] = 0;
  if (param_1 != (int *)0x0) {
    iVar3 = *param_1;
  }
  iVar3 = (**(code **)(*(int *)this + 0x44))(this,iVar3,local_14);
  if (iVar3 < 0) {
    _com_issue_errorex(iVar3,this,(_GUID *)&DAT_4084a7f0);
    iVar3 = extraout_EAX;
  }
  uVar2 = (undefined2)((uint)iVar3 >> 0x10);
  uVar1 = (undefined2)local_14[0];
  if (param_1 != (int *)0x0) {
    iVar3 = FUN_40806039(param_1);
    uVar2 = (undefined2)((uint)iVar3 >> 0x10);
  }
  return CONCAT22(uVar2,uVar1);
}


