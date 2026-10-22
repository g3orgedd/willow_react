// Source: CLARiSOFT.exe @ 00e2b99e; FUN_00e2b99e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_00e2b99e(int param_1)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  void *this;
  int iVar6;
  VARIANTARG *pVVar7;
  VARIANTARG local_4c;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int *local_28;
  int local_24 [7];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0xe2b9aa;
  piVar2 = (int *)FUN_00e77808((void *)(param_1 + 4),0);
  if (*piVar2 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *piVar2 + -100;
  }
  if ((iVar6 == 0) ||
     (iVar4 = *(int *)(param_1 + 0x194), iVar5 = *(int *)(param_1 + 400),
     uVar3 = FUN_00e3e85d(iVar6), (uint)(iVar4 - iVar5 >> 2) <= uVar3)) goto LAB_00e2bb52;
  local_24[0] = 0;
  local_24[1] = 0;
  local_24[2] = 0;
  local_24[3] = 0;
  iVar4 = FUN_00e3e85d(iVar6);
  FUN_00e6600f(*(void **)(*(int *)(param_1 + 400) + iVar4 * 4),local_24);
  iVar4 = local_24[2];
  local_34 = local_24[2];
  local_2c = local_24[3];
  iVar5 = FUN_00e3e85d(iVar6);
  FUN_00e67cdb(*(void **)(*(int *)(param_1 + 400) + iVar5 * 4),iVar4,local_2c);
  iVar6 = FUN_00e3e85d(iVar6);
  bVar1 = FUN_00e66fde(*(int *)(*(int *)(param_1 + 400) + iVar6 * 4));
  if ((!bVar1) || (*(int *)(param_1 + 0x19c) == 0)) goto LAB_00e2bb52;
  piVar2 = (int *)FUN_00e77808((void *)(param_1 + 4),0);
  if (*piVar2 == 0) {
    local_30 = 0;
  }
  else {
    local_30 = *piVar2 + -100;
  }
  FUN_00e03b51((uint *)&local_4c);
  pVVar7 = &local_4c;
  local_8 = 0;
  piVar2 = *(int **)(param_1 + 0x19c);
  iVar6 = *piVar2;
  iVar4 = FUN_00e3e85d(local_30);
  (**(code **)(iVar6 + 0x24))(piVar2,iVar4 + 1,pVVar7);
  CComQIPtr<>(&local_28,(undefined4 *)local_4c.n1._8_4_);
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*local_28 + 0x5c))(local_28,&local_38);
  (**(code **)(*local_28 + 100))(local_28,&local_3c);
  iVar6 = local_34;
  if (local_38 < local_34) {
    (**(code **)(*local_28 + 0x60))(local_28,local_34);
LAB_00e2bae4:
    *(int *)(param_1 + 0x90) = local_2c;
    *(int *)(param_1 + 0x8c) = iVar6;
    (**(code **)(*local_28 + 100))(local_28,param_1 + 0x138);
    (**(code **)(*local_28 + 0x5c))(local_28,param_1 + 0x13c);
    FUN_00e34f42(param_1);
    piVar2 = (int *)FUN_00e77808((void *)(param_1 + 4),0);
    if (*piVar2 == 0) {
      this = (void *)0x0;
    }
    else {
      this = (void *)(*piVar2 + -100);
    }
    FUN_00e42135(this,iVar6,local_2c);
  }
  else if (local_3c < local_2c) goto LAB_00e2bae4;
  local_8 = local_8 & 0xffffff00;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  VariantClear(&local_4c);
LAB_00e2bb52:
  FUN_00ec9e3c();
  return;
}


