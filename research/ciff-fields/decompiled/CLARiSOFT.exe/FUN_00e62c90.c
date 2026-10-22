// Source: CLARiSOFT.exe @ 00e62c90; FUN_00e62c90

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e62c90(void *this,int param_1,int *param_2)

{
  bool bVar1;
  int *piVar2;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int *local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_1c = *(int *)((int)this + 0x38);
  local_8 = 0;
  if (local_1c == param_1) goto LAB_00e62f30;
  FUN_00e6166f(this,&local_34);
  FUN_00eae6d1(&local_24);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_1 == 1) {
    piVar2 = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    local_34 = FUN_00eaeae0(local_34,1.4013e-45,piVar2);
    piVar2 = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    local_2c = FUN_00eaeae0(local_2c,1.4013e-45,piVar2);
    piVar2 = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    local_30 = FUN_00eaeae0(local_30,0.0,piVar2);
    piVar2 = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    local_28 = FUN_00eaeae0(local_28,0.0,piVar2);
    *(undefined4 *)((int)this + 0x38) = 1;
  }
  else {
    piVar2 = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    local_34 = FUN_00eae95c(local_34,1.4013e-45,piVar2);
    piVar2 = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    local_2c = FUN_00eae95c(local_2c,1.4013e-45,piVar2);
    piVar2 = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    local_30 = FUN_00eae95c(local_30,0.0,piVar2);
    piVar2 = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    local_28 = FUN_00eae95c(local_28,0.0,piVar2);
    *(undefined4 *)((int)this + 0x38) = 0;
  }
  (**(code **)(**(int **)((int)this + 4) + 0x88))(*(int **)((int)this + 4),&local_20);
  FUN_00e62bd7(this,local_34,local_30,local_2c,local_28,local_20,'\x01');
  local_14[0] = (BSTR)0x0;
  local_8._0_1_ = 2;
  (**(code **)(**(int **)((int)this + 4) + 0x68))(*(int **)((int)this + 4),local_14);
  bVar1 = FUN_00e03edc(local_14,L"Barcode");
  if (bVar1) {
    CComQIPtr<>(&local_18,*(undefined4 **)((int)this + 4));
    local_8 = CONCAT31(local_8._1_3_,3);
    (**(code **)(*local_18 + 0xb8))(local_18,&param_1);
    if (local_1c == 0) {
      piVar2 = param_2;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 4))(param_2);
      }
      param_1 = FUN_00eaeae0(param_1,1.4013e-45,piVar2);
    }
    else {
      piVar2 = param_2;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 4))(param_2);
      }
      param_1 = FUN_00eae95c(param_1,1.4013e-45,piVar2);
    }
    (**(code **)(*local_18 + 0xbc))(local_18,param_1);
LAB_00e62f0a:
    local_8._0_1_ = 2;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  else {
    bVar1 = FUN_00e03edc(local_14,L"GraphicPrimitive");
    if (bVar1) {
      CComQIPtr<>(&local_18,*(undefined4 **)((int)this + 4));
      local_8 = CONCAT31(local_8._1_3_,4);
      (**(code **)(*local_18 + 0xd4))(local_18,&param_1);
      if (local_1c == 0) {
        piVar2 = param_2;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 4))(param_2);
        }
        param_1 = FUN_00eaeae0(param_1,1.4013e-45,piVar2);
      }
      else {
        piVar2 = param_2;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 4))(param_2);
        }
        param_1 = FUN_00eae95c(param_1,1.4013e-45,piVar2);
      }
      (**(code **)(*local_18 + 0xd8))(local_18,param_1);
      goto LAB_00e62f0a;
    }
  }
  SysFreeString(local_14[0]);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00eae7b2(&local_24);
LAB_00e62f30:
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}


