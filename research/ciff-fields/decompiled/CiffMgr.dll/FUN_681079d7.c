// Source: CiffMgr.dll @ 681079d7; FUN_681079d7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

char __thiscall FUN_681079d7(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  char cVar2;
  int *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x681079e3;
  CComQIPtr<>(&local_18,param_3);
  local_14[0] = (BSTR)0x0;
  cVar2 = '\x01';
  local_8 = 1;
  (**(code **)(*local_18 + 0x1c))(local_18,local_14);
  if (*(int *)this == 0) {
    if (local_14[0] == (BSTR)0x0) goto LAB_68107a19;
  }
  else if (local_14[0] != (BSTR)0x0) {
    iVar1 = FUN_68134501((ushort *)local_14[0],*(ushort **)this);
    cVar2 = '\x01' - (iVar1 != 0);
    goto LAB_68107a19;
  }
  cVar2 = '\0';
LAB_68107a19:
  SysFreeString(local_14[0]);
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return cVar2;
}


