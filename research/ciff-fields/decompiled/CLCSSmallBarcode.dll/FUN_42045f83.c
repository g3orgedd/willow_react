// Source: CLCSSmallBarcode.dll @ 42045f83; FUN_42045f83

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_42045f83(void *this,int *param_1,int *param_2,int *param_3,undefined4 *param_4,BSTR param_5)

{
  int iVar1;
  int *piVar2;
  UINT UVar3;
  undefined4 *puVar4;
  BSTR pOVar5;
  undefined4 local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x42045f8f;
  FUN_42002e41(&local_18);
  local_8 = 0;
  (**(code **)(*(int *)this + 0x18))(param_3);
  local_14[0] = 1;
  (**(code **)(*(int *)*param_1 + 0x54))((int *)*param_1,local_14);
  if (local_14[0] == 0) {
    (**(code **)(*(int *)*param_3 + 0x7c))((int *)*param_3,(int)*(double *)((int)this + 0x30));
    piVar2 = (int *)*param_3;
    iVar1 = *piVar2;
    pOVar5 = param_5;
    if ((int)*(double *)((int)this + 0x38) <= (int)param_5) {
      pOVar5 = (BSTR)(int)*(double *)((int)this + 0x38);
    }
  }
  else {
    piVar2 = (int *)*param_2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    iVar1 = FUN_42003ac3((int)*(double *)((int)this + 0x30),1.4013e-45,piVar2);
    (**(code **)(*(int *)*param_3 + 0x7c))((int *)*param_3,iVar1);
    piVar2 = (int *)*param_2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    iVar1 = FUN_42003ac3((int)*(double *)((int)this + 0x38),0.0,piVar2);
    if (iVar1 <= (int)param_5) {
      (**(code **)(*(int *)*param_3 + 0x84))((int *)*param_3,iVar1);
      goto LAB_42046053;
    }
    piVar2 = (int *)*param_3;
    iVar1 = *piVar2;
    pOVar5 = param_5;
  }
  (**(code **)(iVar1 + 0x84))(piVar2,pOVar5);
LAB_42046053:
  (**(code **)(*(int *)*param_4 + 0x54))((int *)*param_4,*(undefined4 *)((int)this + 0x1c));
  (**(code **)(*(int *)*param_4 + 0x5c))((int *)*param_4,*(undefined4 *)((int)this + 0x20));
  (**(code **)(*(int *)*param_4 + 100))((int *)*param_4,*(undefined4 *)((int)this + 0x20));
  piVar2 = (int *)*param_4;
  UVar3 = SysStringLen(*(BSTR *)((int)this + 0x20));
  (**(code **)(*piVar2 + 0x98))(piVar2,UVar3);
  (**(code **)(*(int *)*param_3 + 0x9c))((int *)*param_3,*(undefined4 *)((int)this + 0x20));
  piVar2 = (int *)*param_3;
  puVar4 = FUN_42002eae(&param_5,L"OCRB");
  local_8._0_1_ = 1;
  (**(code **)(*piVar2 + 0xd4))(piVar2,*puVar4);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(param_5);
  (**(code **)(*(int *)*param_3 + 0xdc))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0xe4))((int *)*param_3,10);
  (**(code **)(*(int *)*param_3 + 0x28))((int *)*param_3,1);
  (**(code **)(*(int *)*param_3 + 0x48))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x50))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x40))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x58))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x94))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0xb4))((int *)*param_3,0x14d);
  (**(code **)(*(int *)*param_3 + 0xc4))((int *)*param_3,1);
  (**(code **)(*(int *)*param_3 + 0xcc))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x104))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x10c))((int *)*param_3,1);
  FUN_42066bbc(param_1,param_2,param_3);
  local_8 = 0xffffffff;
  FUN_420030e8(&local_18);
  return 0;
}


