// Source: CiffMgr.dll @ 6811d8ed; FUN_6811d8ed

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6811d8ed(void *this,SAFEARRAY *param_1,int *param_2,ULONG param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int extraout_EAX;
  wchar_t *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 4;
  if (param_1 == (SAFEARRAY *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    *(undefined4 *)((int)this + 4) = 1;
    do {
      param_2 = (int *)0x0;
      local_8 = 0;
      iVar2 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,&param_2);
      if ((iVar2 == 0) && (param_2 != (int *)0x0)) {
        local_14[0] = (wchar_t *)0x0;
        iVar2 = (**(code **)(*param_2 + 0x1c))(param_2,local_14);
        if ((-1 < iVar2) && (iVar3 = FUN_6812e15e(0x6815fbc0,local_14[0],0,0), iVar3 == 0xa0)) {
          FUN_6811d4d5(param_1,(SAFEARRAY *)&param_2,param_3);
          iVar2 = extraout_EAX;
        }
        SysFreeString(local_14[0]);
      }
      local_8 = 0xffffffff;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    } while (iVar2 == 0);
    if (iVar2 == 1) {
      iVar2 = 0;
    }
  }
  return iVar2;
}


