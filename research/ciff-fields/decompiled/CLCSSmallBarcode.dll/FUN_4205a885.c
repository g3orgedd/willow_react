// Source: CLCSSmallBarcode.dll @ 4205a885; FUN_4205a885

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_4205a885(void *this,int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  float10 fVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  int local_1c [2];
  double local_14;
  undefined1 local_c [4];
  float local_8;
  
  iVar6 = param_1[3];
  iVar1 = param_1[2];
  iVar2 = param_1[1];
  iVar3 = *param_1;
  (**(code **)(*(int *)*param_4 + 0xb0))((int *)*param_4,local_c);
  (**(code **)(*(int *)*param_4 + 0x84))((int *)*param_4,iVar6 - iVar2);
  piVar4 = param_3;
  dVar8 = (double)(iVar1 - iVar3);
  (**(code **)(*(int *)*param_3 + 0x2c))((int *)*param_3,&local_8);
  iVar6 = FUN_4200434d(local_8 * _DAT_4208982c);
  local_14 = (double)iVar6 / DAT_42089810;
  (**(code **)(*(int *)*param_2 + 0x54))((int *)*param_2,&param_1);
  if (param_1 == (int *)0x1) {
    dVar8 = dVar8 / local_14;
  }
  dVar8 = (dVar8 * DAT_42089818) / *(double *)((int)this + 0x30);
  if (_DAT_4209e1b0 < dVar8) {
    fVar7 = FUN_42066adf((int)this,piVar4);
    dVar8 = (double)fVar7;
  }
  iVar6 = FUN_42004376((((*(double *)((int)this + 0x28) * dVar8) / DAT_42089818) *
                       local_14 * DAT_42089810) / DAT_42089810);
  piVar5 = param_4;
  dVar8 = *(double *)((int)this + 0x28) * local_14;
  if (iVar6 < 1) {
    iVar6 = 1;
  }
  local_1c[0] = 0;
  local_1c[1] = 0;
  dVar10 = (double)iVar6 * DAT_42089818;
  (**(code **)(*(int *)this + 0xc))(local_1c,param_2,piVar4,param_4);
  dVar9 = (double)local_1c[0];
  if (param_1 == (int *)0x1) {
    dVar9 = dVar9 * local_14;
  }
  (**(code **)(*(int *)*piVar5 + 0x7c))((int *)*piVar5,(int)dVar9);
  (**(code **)(*(int *)*piVar5 + 0xb4))((int *)*piVar5,(int)(dVar10 / dVar8));
  FUN_42066bbc(param_2,piVar4,piVar5);
  return 0;
}


