// Source: CiffMgr.dll @ 68114b73; FUN_68114b73

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_68114b73(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  undefined1 uVar3;
  int *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x68114b7f;
  CComQIPtr<>(&local_18,param_3);
  uVar3 = 0;
  local_14[0] = (BSTR)0x0;
  local_8 = 1;
  (**(code **)(*local_18 + 0x1c))(local_18,local_14);
  if (local_14[0] != (BSTR)0x0) {
    if (*(int *)this == 0) goto LAB_68114bc3;
    iVar1 = FUN_68134501((ushort *)local_14[0],*(ushort **)this);
    if (iVar1 != 0) goto LAB_68114bc3;
  }
  uVar3 = 1;
LAB_68114bc3:
  SysFreeString(local_14[0]);
  local_8 = 0xffffffff;
  uVar2 = extraout_EAX;
  if (local_18 != (int *)0x0) {
    uVar2 = (**(code **)(*local_18 + 8))(local_18);
  }
  return CONCAT31((int3)((uint)uVar2 >> 8),uVar3);
}


