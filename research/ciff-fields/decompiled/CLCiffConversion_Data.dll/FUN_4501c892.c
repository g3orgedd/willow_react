// Source: CLCiffConversion_Data.dll @ 4501c892; FUN_4501c892

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4501c892(void *this,int *param_1,double *param_2)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int extraout_EAX;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 8;
  local_8 = 0x4501c89e;
  local_14[0] = 0;
  (**(code **)(*param_1 + 0xc4))(param_1,local_14);
  bVar2 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0xe4),L"Capi");
  iVar3 = CONCAT31(extraout_var,bVar2);
  if (bVar2) {
    iVar3 = *(int *)(*(int *)((int)this + 4) + 4);
    if ((*(char *)(iVar3 + 0x100 + (int)this) != '\0') && (local_14[0] != 0)) goto LAB_4501c981;
    iVar3 = (**(code **)(*piVar1 + 0x4c))(piVar1,&param_1);
    if (param_1 == (int *)0x1) {
      (**(code **)(*piVar1 + 0x50))(piVar1,0);
      (**(code **)(*piVar1 + 0xa0))(piVar1,0);
      iVar3 = (**(code **)(*piVar1 + 0x98))(piVar1,0);
    }
  }
  if (local_14[0] == 0) {
    (**(code **)(*piVar1 + 0x24))(piVar1,&local_18);
    if (local_18 == 0) {
      (**(code **)(*piVar1 + 0x28))(piVar1,1);
      iVar3 = *piVar1;
      uVar4 = FUN_4501e220(param_2);
      (**(code **)(iVar3 + 0x40))(piVar1,uVar4);
      iVar3 = *piVar1;
      uVar4 = FUN_4501de65(param_2);
      (**(code **)(iVar3 + 0x38))(piVar1,uVar4);
      iVar3 = *piVar1;
      uVar4 = FUN_4501d4ad(param_2);
      (**(code **)(iVar3 + 0x30))(piVar1,uVar4);
    }
    puVar5 = FUN_45001f5d(&param_2,L"CurrentDate");
    local_8 = 0;
    (**(code **)(*piVar1 + 0xc0))(piVar1,*puVar5);
    SysFreeString((BSTR)param_2);
    iVar3 = extraout_EAX;
  }
LAB_4501c981:
  return CONCAT31((int3)((uint)iVar3 >> 8),1);
}


