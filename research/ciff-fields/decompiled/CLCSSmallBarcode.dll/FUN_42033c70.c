// Source: CLCSSmallBarcode.dll @ 42033c70; FUN_42033c70

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_42033c70(void *this,int *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  UINT UVar5;
  int iVar6;
  int local_20;
  int *local_1c;
  int local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  piVar2 = param_1;
  uStack_4 = 0x10;
  local_8 = 0x42033c7c;
  CComQIPtr<>(local_14,param_1);
  local_8 = 0;
  CComQIPtr<>(&local_1c,piVar2);
  *(undefined4 *)((int)this + 0xe8) = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  SysFreeString(*(BSTR *)((int)this + 0xec));
  *(undefined4 *)((int)this + 0xec) = 0;
  puVar1 = (undefined4 *)((int)this + 0xc4);
  SysFreeString((BSTR)*puVar1);
  *puVar1 = 0;
  SysFreeString(*(BSTR *)((int)this + 200));
  piVar2 = param_1;
  *(undefined4 *)((int)this + 200) = 0;
  *(undefined4 *)((int)this + 0xa8) = 0;
  *(undefined4 *)((int)this + 0xac) = 0;
  *(undefined4 *)((int)this + 0x90) = 1;
  *(undefined4 *)((int)this + 0x94) = 1;
  *(undefined4 *)((int)this + 0x98) = 1;
  *(undefined4 *)((int)this + 0x9c) = 1;
  *(undefined4 *)((int)this + 0xcc) = 0;
  *(undefined4 *)((int)this + 0xe4) = 1;
  *(undefined4 *)((int)this + 0xb8) = 1;
  *(undefined1 *)((int)this + 0xc0) = 0;
  *(undefined4 *)((int)this + 0xbc) = 0;
  *(undefined1 *)((int)this + 0xd0) = 0;
  *(undefined4 *)((int)this + 0xd4) = 0;
  *(undefined4 *)((int)this + 0xd8) = 0x12;
  *(undefined1 *)((int)this + 0xdc) = 0;
  iVar4 = (**(code **)(*param_1 + 0x1c))(param_1,puVar1);
  if ((iVar4 < 0) || (iVar4 = (**(code **)(*piVar2 + 0x98))(piVar2,(int)this + 200), iVar4 < 0))
  goto LAB_42034043;
  UVar5 = SysStringLen(*(BSTR *)((int)this + 200));
  param_1 = (int *)0x2710;
  if (UVar5 == 0) {
    iVar4 = -0x7fffbffb;
  }
  else {
    *(undefined4 *)((int)this + 0xcc) = 0;
    iVar4 = (**(code **)(*piVar2 + 0x80))(piVar2,(int)this + 0xe4);
    if (iVar4 < 0) goto LAB_42034043;
    if (param_2 == 0) {
      iVar4 = (*(int *)((int)this + 0x80) * *(int *)((int)this + 0xe4) + 5000) / 10000;
    }
    else {
      iVar4 = *(int *)((int)this + 0xe4);
    }
    *(int *)((int)this + 0xe4) = iVar4;
    iVar4 = (**(code **)(*piVar2 + 0x15c))(piVar2,(int)this + 0x90);
    if (iVar4 < 0) goto LAB_42034043;
    iVar4 = *(int *)((int)this + 0x90);
    iVar6 = iVar4;
    if (param_2 == 0) {
      iVar6 = (*(int *)((int)this + 0x80) * iVar4 + 5000) / (int)param_1;
    }
    if (iVar6 == 0) {
      iVar6 = 1;
    }
    *(int *)((int)this + 0x94) = iVar6;
    if (param_2 == 0) {
      iVar4 = (*(int *)((int)this + 0x7c) * iVar4 + 5000) / 10000;
    }
    if (iVar4 == 0) {
      iVar4 = 1;
    }
    *(int *)((int)this + 0x90) = iVar4;
    iVar4 = (**(code **)(*local_14[0] + 0x1b4))(local_14[0],(int)this + 0xb8);
    if ((iVar4 < 0) ||
       (iVar4 = (**(code **)(*local_14[0] + 0x1bc))(local_14[0],&param_1), iVar4 < 0))
    goto LAB_42034043;
    *(bool *)((int)this + 0xc0) = param_1 == (int *)0x1;
    iVar4 = (**(code **)(*local_14[0] + 0x1ac))(local_14[0],(int)this + 0xbc);
  }
  if ((-1 < iVar4) && (iVar4 = (**(code **)(*piVar2 + 0x44))(piVar2,&param_1), -1 < iVar4)) {
    *(bool *)((int)this + 0xd0) = param_1 == (int *)0x1;
    iVar4 = (**(code **)(*piVar2 + 0x54))(piVar2,(int)this + 0xd4);
    if ((-1 < iVar4) && (iVar4 = (**(code **)(*local_1c + 0x22c))(local_1c,&param_1), -1 < iVar4)) {
      *(uint *)((int)this + 0xf4) = (uint)(param_1 == (int *)0x1);
      iVar4 = (**(code **)(*piVar2 + 0xa8))(piVar2,(int)this + 0xd8);
      if (-1 < iVar4) {
        bVar3 = FUN_42034350(*(int *)((int)this + 0xd8));
        if (bVar3) {
          iVar4 = (**(code **)(*piVar2 + 0x108))(piVar2,&local_20);
          if (iVar4 < 0) goto LAB_42034043;
          *(bool *)((int)this + 0xdc) = local_20 == 1;
          iVar4 = (**(code **)(*piVar2 + 0xb8))(piVar2,(int)this + 0x9c);
          if (iVar4 < 0) goto LAB_42034043;
          iVar4 = *(int *)((int)this + 0x9c);
          *(int *)((int)this + 0x98) = iVar4;
          if (param_2 == 0) {
            iVar4 = (*(int *)((int)this + 0x80) * iVar4 + 5000) / 10000;
          }
          if (iVar4 == 0) {
            iVar4 = 1;
          }
          *(int *)((int)this + 0x9c) = iVar4;
          if (param_2 == 0) {
            iVar4 = (*(int *)((int)this + 0x7c) * *(int *)((int)this + 0x98) + 5000) / 10000;
          }
          else {
            iVar4 = *(int *)((int)this + 0x98);
          }
          if (iVar4 == 0) {
            iVar4 = 1;
          }
          *(int *)((int)this + 0x98) = iVar4;
          iVar4 = (**(code **)(*piVar2 + 0x14c))(piVar2,&local_18);
          if (iVar4 < 0) goto LAB_42034043;
          if (param_2 == 0) {
            local_18 = (*(int *)((int)this + 0x7c) * local_18 + 5000) / 10000;
          }
        }
        else {
          iVar4 = -0x7fffbfff;
        }
        if (-1 < iVar4) {
          *(int *)((int)this + 0xa8) = *(int *)((int)this + 0xa8) + local_18;
          iVar4 = FUN_420279b1((int)this);
        }
      }
    }
  }
LAB_42034043:
  local_8 = local_8 & 0xffffff00;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar4;
}


