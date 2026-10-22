// Source: CiffHelper.dll @ 40805870; FUN_40805870

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_40805870(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  UINT UVar4;
  int *piVar5;
  int local_20;
  int *local_1c;
  int local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_2;
  piVar5 = param_1;
  uStack_4 = 0x10;
  local_8 = 0x4080587c;
  if (*param_1 == 0) {
    iVar3 = -0x7fffbffd;
  }
  else {
    UVar4 = SysStringLen((BSTR)*param_2);
    piVar1 = param_3;
    if (UVar4 == 0) {
      SysFreeString((BSTR)*param_3);
      *piVar1 = 0;
      iVar3 = 0;
    }
    else {
      local_14[0] = (int *)0x0;
      param_1 = (int *)0x0;
      iVar3 = (**(code **)(*(int *)*piVar5 + 0xec))((int *)*piVar5,local_14);
      if ((-1 < iVar3) &&
         (iVar3 = (**(code **)(*(int *)*piVar5 + 0xf4))((int *)*piVar5,&param_1), -1 < iVar3)) {
        CComQIPtr<>(&local_1c,(undefined4 *)*piVar5);
        local_8 = 0;
        local_18 = 0;
        if (((local_1c == (int *)0x0) ||
            (iVar3 = (**(code **)(*local_1c + 400))(local_1c,&local_18), -1 < iVar3)) &&
           (piVar5 = (int *)SysStringLen((BSTR)*piVar2), local_14[0] < piVar5)) {
          if (param_1 == (int *)0x0) {
            param_1 = piVar5;
          }
          if (piVar5 < (int *)((int)param_1 + (int)local_14[0])) {
            param_1 = (int *)((int)piVar5 - (int)local_14[0]);
          }
          piVar1 = local_14[0];
          if (local_18 != 0) {
            piVar1 = (int *)((int)piVar5 + (-(int)local_14[0] - (int)param_1));
          }
          FUN_40803bde(&local_20,(UINT)param_1,(OLECHAR *)(*piVar2 + (int)piVar1 * 2));
          piVar5 = param_3;
          SysFreeString((BSTR)*param_3);
          *piVar5 = 0;
          if (local_20 != 0) {
            SysFreeString((BSTR)0x0);
            *param_3 = local_20;
          }
          SysFreeString((BSTR)0x0);
        }
        local_8 = 0xffffffff;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
      }
    }
  }
  return iVar3;
}


