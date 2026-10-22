// Source: CLCSBarcodeField.dll @ 414436a8; FUN_414436a8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_414436a8(void *this,undefined4 *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 param_5,BSTR param_6)

{
  void *this_00;
  int iVar1;
  int *piVar2;
  UINT UVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  BSTR pOVar6;
  undefined4 local_1c;
  void *local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x414436b4;
  local_18 = this;
  FUN_4144c328(&local_1c);
  local_8 = 0;
  (**(code **)(*(int *)this + 0x24))(param_3);
  (**(code **)(*(int *)*param_1 + 0x54))((int *)*param_1,local_14);
  if (local_14[0] == 0) {
    (**(code **)(*(int *)*param_3 + 0x7c))((int *)*param_3,(int)*(double *)((int)this + 0x30));
    piVar2 = (int *)*param_3;
    iVar1 = *piVar2;
    pOVar6 = param_6;
    if ((int)*(double *)((int)this + 0x38) <= (int)param_6) {
      pOVar6 = (BSTR)(int)*(double *)((int)this + 0x38);
    }
  }
  else {
    piVar2 = (int *)*param_2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    iVar1 = FUN_4144c3fb((int)*(double *)((int)this + 0x30),1.4013e-45,piVar2);
    (**(code **)(*(int *)*param_3 + 0x7c))((int *)*param_3,iVar1);
    piVar2 = (int *)*param_2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    iVar1 = FUN_4144c3fb((int)*(double *)((int)this + 0x38),0.0,piVar2);
    if (iVar1 <= (int)param_6) {
      (**(code **)(*(int *)*param_3 + 0x84))((int *)*param_3,iVar1);
      goto LAB_41443773;
    }
    piVar2 = (int *)*param_3;
    iVar1 = *piVar2;
    pOVar6 = param_6;
  }
  (**(code **)(iVar1 + 0x84))(piVar2,pOVar6);
LAB_41443773:
  (**(code **)(*(int *)*param_4 + 0x54))((int *)*param_4,*(undefined4 *)((int)this + 0x1c));
  (**(code **)(*(int *)*param_4 + 0x5c))((int *)*param_4,*(undefined4 *)((int)this + 0x20));
  (**(code **)(*(int *)*param_4 + 100))((int *)*param_4,*(undefined4 *)((int)this + 0x20));
  piVar2 = (int *)*param_4;
  UVar3 = SysStringLen(*(BSTR *)((int)this + 0x20));
  (**(code **)(*piVar2 + 0x98))(piVar2,UVar3);
  piVar2 = (int *)*param_3;
  puVar4 = FUN_41402f15(&param_6,L"æ0105012345123455");
  local_8._0_1_ = 1;
  (**(code **)(*piVar2 + 0x9c))(piVar2,*puVar4);
  local_8._0_1_ = 0;
  SysFreeString(param_6);
  piVar2 = (int *)*param_3;
  puVar4 = FUN_41402f15(&param_6,L"OCRB");
  local_8._0_1_ = 2;
  (**(code **)(*piVar2 + 0xd4))(piVar2,*puVar4);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(param_6);
  (**(code **)(*(int *)*param_3 + 0xdc))((int *)*param_3,0);
  this_00 = local_18;
  if (*(int *)((int)local_18 + 0x14) - 0xcU < 3) {
    uVar5 = 6;
  }
  else {
    uVar5 = 10;
  }
  (**(code **)(*(int *)*param_3 + 0xe4))((int *)*param_3,uVar5);
  (**(code **)(*(int *)*param_3 + 0x28))((int *)*param_3,1);
  (**(code **)(*(int *)*param_3 + 0x48))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x50))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x40))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x58))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x94))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0xb4))((int *)*param_3,1000);
  (**(code **)(*(int *)*param_3 + 0xc4))((int *)*param_3,1);
  (**(code **)(*(int *)*param_3 + 0xcc))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x104))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x10c))((int *)*param_3,1);
  FUN_41443ef9(this_00,param_1,param_2,param_3);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_1c);
  return 0;
}


