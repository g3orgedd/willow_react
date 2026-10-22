// Source: CLCSSmallBarcode.dll @ 4202a289; FUN_4202a289

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_4202a289(void *this,int *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  UINT UVar4;
  undefined4 uVar5;
  int iVar6;
  double dVar7;
  uint local_20;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  if (param_1 == (int *)0x0) {
    return -0x7fffbffd;
  }
  *(undefined4 *)((int)this + 0xdc) = 0;
  local_8 = 1;
  SysFreeString(*(BSTR *)((int)this + 0x74));
  *(undefined4 *)((int)this + 0x74) = 0;
  puVar1 = (undefined4 *)((int)this + 0x6c);
  *(undefined4 *)((int)this + 0x78) = 1;
  SysFreeString((BSTR)*puVar1);
  *puVar1 = 0;
  iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,puVar1);
  if (iVar3 < 0) goto LAB_4202a693;
  SysFreeString(*(BSTR *)((int)this + 0x70));
  *(undefined4 *)((int)this + 0x70) = 0;
  iVar3 = (**(code **)(*param_1 + 0x98))(param_1,(undefined4 *)((int)this + 0x70));
  if ((iVar3 < 0) || (UVar4 = SysStringLen(*(BSTR *)((int)this + 0x70)), iVar3 = 1, UVar4 == 0))
  goto LAB_4202a693;
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x84) = *(undefined4 *)((int)this + 0xe8);
  *(undefined4 *)((int)this + 0xcc) = *(undefined4 *)((int)this + 0xe8);
  *(undefined4 *)((int)this + 0x88) = *(undefined4 *)((int)this + 0xec);
  *(undefined4 *)((int)this + 0xd0) = *(undefined4 *)((int)this + 0xec);
  iVar3 = (**(code **)(*param_1 + 0x80))(param_1,(int)this + 0xc4);
  if (iVar3 < 0) goto LAB_4202a693;
  if (param_2 == 0) {
    if ((*(int *)((int)this + 0x7c) == 0x5a) || (*(int *)((int)this + 0x7c) == 0x10e)) {
      iVar3 = *(int *)((int)this + 0xa0);
    }
    else {
      iVar3 = *(int *)((int)this + 0xa4);
    }
    iVar3 = (*(int *)((int)this + 0xc4) * iVar3 + 5000) / 10000;
  }
  else {
    iVar3 = *(int *)((int)this + 0xc4);
  }
  *(int *)((int)this + 0xc4) = iVar3;
  iVar3 = (**(code **)(*param_1 + 0x4c))(param_1,local_14);
  if ((iVar3 < 0) || (iVar3 = (**(code **)(*param_1 + 0x44))(param_1,local_14), iVar3 < 0))
  goto LAB_4202a693;
  *(undefined4 *)((int)this + 0x98) = local_14[0];
  iVar3 = (**(code **)(*param_1 + 0x54))(param_1,(int)this + 0xe0);
  if ((iVar3 < 0) || (iVar3 = (**(code **)(*param_1 + 0xa8))(param_1,(int)this + 0x68), iVar3 < 0))
  goto LAB_4202a693;
  uVar5 = FUN_4202ae76(*(int *)((int)this + 0x68));
  if ((char)uVar5 == '\0') {
    iVar3 = -0x7fffbfff;
    goto LAB_4202a693;
  }
  iVar3 = (**(code **)(*param_1 + 0x100))(param_1,local_14);
  if (iVar3 < 0) goto LAB_4202a693;
  *(undefined4 *)((int)this + 0xbc) = local_14[0];
  iVar3 = (**(code **)(*param_1 + 0x108))(param_1,local_14);
  if (iVar3 < 0) goto LAB_4202a693;
  *(undefined4 *)((int)this + 0xc0) = local_14[0];
  iVar3 = (**(code **)(*param_1 + 0xb0))(param_1,(int)this + 0x8c);
  if (iVar3 < 0) goto LAB_4202a693;
  iVar3 = (**(code **)(*param_1 + 0xb8))(param_1,(int)this + 0x60);
  if (param_2 == 0) {
    if ((*(int *)((int)this + 0x7c) == 0x5a) || (*(int *)((int)this + 0x7c) == 0x10e)) {
      iVar6 = *(int *)((int)this + 0xa0);
    }
    else {
      iVar6 = *(int *)((int)this + 0xa4);
    }
    iVar6 = (*(int *)((int)this + 0x60) * iVar6 + 5000) / 10000;
  }
  else {
    iVar6 = *(int *)((int)this + 0x60);
  }
  *(int *)((int)this + 0x60) = iVar6;
  if ((iVar3 < 0) || (iVar3 = (**(code **)(*param_1 + 0xc0))(param_1,local_14), iVar3 < 0))
  goto LAB_4202a693;
  *(undefined4 *)((int)this + 100) = local_14[0];
  iVar3 = (**(code **)(*param_1 + 200))(param_1,local_14);
  if (iVar3 < 0) goto LAB_4202a693;
  puVar1 = (undefined4 *)((int)this + 0xa8);
  *(undefined4 *)((int)this + 0x90) = local_14[0];
  SysFreeString((BSTR)*puVar1);
  *puVar1 = 0;
  iVar3 = (**(code **)(*param_1 + 0xd0))(param_1,puVar1);
  if ((((iVar3 < 0) || (iVar3 = (**(code **)(*param_1 + 0xd8))(param_1,(int)this + 0xac), iVar3 < 0)
       ) || (iVar3 = (**(code **)(*param_1 + 0xe8))(param_1,(int)this + 0xb0), iVar3 < 0)) ||
     (iVar3 = (**(code **)(*param_1 + 0xe0))(param_1,(int)this + 0xb4), iVar3 < 0))
  goto LAB_4202a693;
  piVar2 = (int *)((int)this + 0xb4);
  if (*(int *)((int)this + 0x8c) < 1000) {
    *piVar2 = (*piVar2 * *(int *)((int)this + 0x8c)) / 1000;
  }
  if (*piVar2 < 3) {
    *piVar2 = 3;
  }
  iVar3 = *(int *)((int)this + 0x7c);
  if (iVar3 == 0) {
LAB_4202a5f5:
    dVar7 = (double)*(int *)((int)this + 0xa0) * (double)*(int *)((int)this + 0x8c);
    iVar3 = *(int *)((int)this + 0xa4);
LAB_4202a615:
    dVar7 = (dVar7 * _DAT_42089800) / _DAT_42093e90;
    *(int *)((int)this + 0x94) = (int)((double)iVar3 * _DAT_42089800 + DAT_42093e88) / 100;
  }
  else {
    if (iVar3 == 0x5a) {
LAB_4202a5d3:
      dVar7 = (double)*(int *)((int)this + 0xa4) * (double)*(int *)((int)this + 0x8c);
      iVar3 = *(int *)((int)this + 0xa0);
      goto LAB_4202a615;
    }
    if (iVar3 == 0xb4) goto LAB_4202a5f5;
    if (iVar3 == 0x10e) goto LAB_4202a5d3;
    dVar7 = (double)(ulonglong)local_20;
  }
  *(int *)((int)this + 0x5c) = (int)(dVar7 + DAT_42089808);
  if (*(int *)((int)this + 0x7c) == 0x10e) {
    *(int *)((int)this + 0x84) =
         *(int *)((int)this + 0x84) + (*(int *)((int)this + 0xc4) - *(int *)((int)this + 0x60));
  }
  else if (*(int *)((int)this + 0x7c) == 0xb4) {
    *(int *)((int)this + 0x88) =
         *(int *)((int)this + 0x88) + (*(int *)((int)this + 0xc4) - *(int *)((int)this + 0x60));
  }
  iVar3 = FUN_4202a891((int)this);
LAB_4202a693:
  SysFreeString((BSTR)0x0);
  return iVar3;
}


