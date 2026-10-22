// Source: CLARiSOFT.exe @ 00e61d8e; FUN_00e61d8e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_00e61d8e(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_1;
  uStack_4 = 0x1c;
  local_8 = 0xe61d9a;
  piVar1 = *(int **)((int)this + 4);
  iVar3 = *piVar1;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  (**(code **)(iVar3 + 0x2c))(piVar1,&local_24);
  (**(code **)(**(int **)((int)this + 4) + 0x34))(*(int **)((int)this + 4),&local_28);
  (**(code **)(**(int **)((int)this + 4) + 0x3c))(*(int **)((int)this + 4),&local_2c);
  (**(code **)(**(int **)((int)this + 4) + 0x78))(*(int **)((int)this + 4),&local_18);
  (**(code **)(**(int **)((int)this + 4) + 0x80))(*(int **)((int)this + 4),&param_1);
  (**(code **)(**(int **)((int)this + 4) + 100))(*(int **)((int)this + 4),&local_1c);
  if (local_1c == 1) {
    CComQIPtr<>(local_14,*(undefined4 **)((int)this + 4));
    local_8 = 0;
    if (((local_14[0] != (int *)0x0) &&
        (iVar3 = (**(code **)(*local_14[0] + 0xa8))(local_14[0],&local_20), -1 < iVar3)) &&
       (local_20 - 10U < 5)) {
      param_1 = param_1 + 0xfa;
    }
    local_8 = 0xffffffff;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  *piVar2 = local_24;
  piVar2[1] = local_28;
  if (local_2c == 0) {
LAB_00e61e8c:
    piVar2[2] = (int)local_18 + local_24;
    piVar2[3] = (int)param_1 + local_28;
  }
  else {
    if (local_2c == 0x5a) {
LAB_00e61e7a:
      piVar2[2] = (int)param_1 + local_24;
      param_1 = local_18;
    }
    else {
      if (local_2c == 0xb4) goto LAB_00e61e8c;
      if (local_2c == 0x10e) goto LAB_00e61e7a;
      piVar2[2] = (int)local_18 + local_24;
    }
    piVar2[3] = (int)param_1 + local_28;
  }
  return piVar2;
}


