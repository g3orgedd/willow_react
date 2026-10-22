// Source: CLCSSmallBarcode.dll @ 4200b92e; FUN_4200b92e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_4200b92e(int *param_1,int *param_2)

{
  int iVar1;
  UINT UVar2;
  int *piVar3;
  int *piVar4;
  int unaff_ESI;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined4 local_18;
  uint auStack_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar4 = param_2;
  uStack_4 = 8;
  local_8 = 0x4200b93a;
  if (param_2 == (int *)0x0) {
    return unaff_ESI;
  }
  param_1[0x3f] = 0;
  SysFreeString((BSTR)param_1[0x40]);
  param_1[0x40] = 0;
  piVar3 = param_1 + 9;
  param_1[0x1c] = 1;
  SysFreeString((BSTR)*piVar3);
  *piVar3 = 0;
  iVar1 = (**(code **)(*piVar4 + 0x1c))(piVar4,piVar3);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  piVar3 = param_1 + 10;
  SysFreeString((BSTR)*piVar3);
  *piVar3 = 0;
  iVar1 = (**(code **)(*piVar4 + 0x98))(piVar4,piVar3);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  UVar2 = SysStringLen((BSTR)*piVar3);
  if (UVar2 == 0) {
    return (int)piVar3;
  }
  param_1[0x21] = 0;
  piVar3 = param_1 + 0xb;
  param_1[0x22] = 0;
  iVar1 = (**(code **)(*piVar4 + 0x3c))(piVar4,piVar3);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  if (*piVar3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0x168 - *piVar3;
  }
  *piVar3 = iVar1;
  iVar1 = (**(code **)(*piVar4 + 0x44))(piVar4,param_1 + 0xc);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  iVar1 = (**(code **)(*piVar4 + 0x54))(piVar4,param_1 + 0xd);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  piVar3 = param_1 + 0xe;
  iVar1 = (**(code **)(*piVar4 + 0xa8))(piVar4,piVar3);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  iVar1 = (**(code **)(*param_1 + 0x18))(*piVar3);
  if (iVar1 == 0) {
    return (int)piVar3;
  }
  iVar1 = (**(code **)(*piVar4 + 0x100))(piVar4,param_1 + 0x11);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  iVar1 = (**(code **)(*piVar4 + 0x108))(piVar4,param_1 + 7);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  iVar1 = (**(code **)(*piVar4 + 0xb0))(piVar4,param_1 + 0x13);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  iVar1 = (**(code **)(*piVar4 + 0xf0))(piVar4,auStack_14);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  dVar5 = (double)(auStack_14[0] >> 8 & 0xff) + _DAT_4208a8b0;
  dVar6 = (double)(auStack_14[0] & 0xff) + _DAT_4208a8b0;
  if (dVar5 <= dVar6) {
    *(double *)(param_1 + 0x14) = dVar6 / dVar5;
  }
  else {
    *(double *)(param_1 + 0x14) = dVar5 / dVar6;
  }
  if ((((*piVar3 == 4) || (*piVar3 == 5)) || (*piVar3 == 6)) || (*piVar3 == 7)) {
    iVar1 = (**(code **)(*piVar4 + 0x110))(piVar4,param_1 + 8);
  }
  else {
    piVar3 = param_1 + 0x12;
    SysFreeString((BSTR)*piVar3);
    *piVar3 = 0;
    iVar1 = (**(code **)(*piVar4 + 0xf8))(piVar4,piVar3);
  }
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  iVar1 = (**(code **)(*piVar4 + 0xc0))(piVar4,param_1 + 6);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  iVar1 = (**(code **)(*piVar4 + 200))(piVar4,param_1 + 0xf);
  if (iVar1 < 0) {
    return (int)piVar3;
  }
  CComQIPtr<>(&param_2,piVar4);
  local_8 = 0;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 0x214))(param_2,param_1 + 0x10);
  }
  piVar3 = param_1 + 0x17;
  SysFreeString((BSTR)*piVar3);
  *piVar3 = 0;
  iVar1 = (**(code **)(*piVar4 + 0xd0))(piVar4,piVar3);
  if (((iVar1 < 0) || (iVar1 = (**(code **)(*piVar4 + 0xd8))(piVar4,param_1 + 0x18), iVar1 < 0)) ||
     ((iVar1 = (**(code **)(*piVar4 + 0xe8))(piVar4,param_1 + 0x19), iVar1 < 0 ||
      (iVar1 = (**(code **)(*piVar4 + 0xe0))(piVar4,param_1 + 0x1a), iVar1 < 0))))
  goto LAB_4200bd2b;
  piVar4 = param_1 + 0x1a;
  if (param_1[0x13] < 0x14d) {
    *piVar4 = (*piVar4 * param_1[0x13]) / 0x14d;
  }
  if (*piVar4 < 3) {
    *piVar4 = 3;
  }
  dVar5 = DAT_42089808;
  iVar1 = param_1[0xb];
  if (iVar1 == 0) {
LAB_4200bc7d:
    dVar7 = (double)param_1[4];
    dVar8 = (double)param_1[0x13] * dVar7;
    iVar1 = (int)(dVar8 / DAT_42089818 + DAT_42089808);
    param_1[0x3b] = iVar1;
    dVar6 = (double)iVar1 * *(double *)(param_1 + 0x14);
    iVar1 = param_1[5];
LAB_4200bcc2:
    dVar7 = dVar7 * _DAT_4208a8a0;
    param_1[0x3c] = (int)dVar6;
    dVar6 = (dVar8 * _DAT_42089800) / DAT_42089818;
    piVar4 = (int *)(int)(dVar7 + dVar5);
    param_1[0x3a] = (int)((double)iVar1 * _DAT_4208a890 + dVar5);
  }
  else {
    if (iVar1 == 0x5a) {
LAB_4200bc36:
      dVar7 = (double)param_1[5];
      dVar8 = (double)param_1[0x13] * dVar7;
      iVar1 = (int)(dVar8 / DAT_42089818 + DAT_42089808);
      param_1[0x3b] = iVar1;
      dVar6 = (double)iVar1 * *(double *)(param_1 + 0x14);
      iVar1 = param_1[4];
      goto LAB_4200bcc2;
    }
    if (iVar1 == 0xb4) goto LAB_4200bc7d;
    if (iVar1 == 0x10e) goto LAB_4200bc36;
    dVar6 = (double)CONCAT44(auStack_14[0],local_18);
    piVar4 = param_2;
  }
  piVar3 = (int *)(param_1[0x3b] * 10);
  if ((int)piVar3 - (int)piVar4 != 0 && (int)piVar4 <= (int)piVar3) {
    piVar4 = piVar3;
  }
  param_1[0x3d] = (int)piVar4;
  param_1[0x3e] = (int)(dVar6 + dVar5);
  iVar1 = FUN_4200a18d((int)param_1);
LAB_4200bd2b:
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return iVar1;
}


