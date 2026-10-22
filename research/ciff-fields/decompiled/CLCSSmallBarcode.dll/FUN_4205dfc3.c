// Source: CLCSSmallBarcode.dll @ 4205dfc3; FUN_4205dfc3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_4205dfc3(void *this,undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  UINT UVar2;
  int *piVar3;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x4205dfcf;
  FUN_42002e41(local_14);
  local_8 = 0;
  (**(code **)(*(int *)this + 0x18))(param_3);
  piVar3 = (int *)*param_2;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(piVar3);
  }
  iVar1 = FUN_42003ac3((int)*(double *)((int)this + 0x30),1.4013e-45,piVar3);
  (**(code **)(*(int *)*param_3 + 0x7c))((int *)*param_3,iVar1);
  (**(code **)(*(int *)*param_3 + 0x84))((int *)*param_3,iVar1);
  (**(code **)(*(int *)*param_4 + 0x54))((int *)*param_4,*(undefined4 *)((int)this + 0x1c));
  (**(code **)(*(int *)*param_4 + 0x5c))((int *)*param_4,*(undefined4 *)((int)this + 0x20));
  (**(code **)(*(int *)*param_4 + 100))((int *)*param_4,*(undefined4 *)((int)this + 0x20));
  piVar3 = (int *)*param_4;
  UVar2 = SysStringLen(*(BSTR *)((int)this + 0x20));
  (**(code **)(*piVar3 + 0x98))(piVar3,UVar2);
  (**(code **)(*(int *)*param_3 + 0x9c))((int *)*param_3,*(undefined4 *)((int)this + 0x20));
  (**(code **)(*(int *)*param_3 + 0x28))((int *)*param_3,1);
  (**(code **)(*(int *)*param_3 + 0x48))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x50))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x40))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x58))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x94))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0xb4))((int *)*param_3,1000);
  (**(code **)(*(int *)*param_3 + 0x10c))((int *)*param_3,1);
  local_8 = 0xffffffff;
  FUN_420030e8(local_14);
  return 0;
}


