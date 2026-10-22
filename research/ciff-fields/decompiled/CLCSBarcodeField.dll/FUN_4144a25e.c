// Source: CLCSBarcodeField.dll @ 4144a25e; FUN_4144a25e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_4144a25e(void *this,int *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  UINT UVar4;
  int iVar5;
  int *piVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  uint local_20;
  int *local_14 [3];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  piVar2 = param_1;
  uStack_4 = 0x10;
  if (param_1 == (int *)0x0) {
    return -0x7fffbffd;
  }
  *(undefined4 *)((int)this + 0xe0) = 0;
  local_8 = 1;
  uStack_7 = 0;
  SysFreeString(*(BSTR *)((int)this + 0x74));
  *(undefined4 *)((int)this + 0x74) = 0;
  puVar1 = (undefined4 *)((int)this + 0x6c);
  *(undefined4 *)((int)this + 0x78) = 1;
  SysFreeString((BSTR)*puVar1);
  *puVar1 = 0;
  iVar3 = (**(code **)(*piVar2 + 0x1c))(piVar2,puVar1);
  if (iVar3 < 0) goto LAB_4144a2e6;
  puVar1 = (undefined4 *)((int)this + 0x70);
  SysFreeString((BSTR)*puVar1);
  *puVar1 = 0;
  iVar3 = (**(code **)(*piVar2 + 0x98))(piVar2,puVar1);
  if (iVar3 < 0) goto LAB_4144a2e6;
  UVar4 = SysStringLen((BSTR)*puVar1);
  if (UVar4 == 0) {
    iVar3 = 1;
    goto LAB_4144a2e6;
  }
  *(undefined4 *)((int)this + 0x7c) = 0;
  *(undefined4 *)((int)this + 0x84) = *(undefined4 *)((int)this + 0xec);
  *(undefined4 *)((int)this + 0xd0) = *(undefined4 *)((int)this + 0xec);
  *(undefined4 *)((int)this + 0x88) = *(undefined4 *)((int)this + 0xf0);
  *(undefined4 *)((int)this + 0xd4) = *(undefined4 *)((int)this + 0xf0);
  iVar3 = (**(code **)(*piVar2 + 0x80))(piVar2,(int)this + 200);
  if (iVar3 < 0) goto LAB_4144a2e6;
  if (param_2 == 0) {
    if ((*(int *)((int)this + 0x7c) == 0x5a) || (*(int *)((int)this + 0x7c) == 0x10e)) {
      iVar3 = *(int *)((int)this + 0xa4);
    }
    else {
      iVar3 = *(int *)((int)this + 0xa8);
    }
    iVar3 = (*(int *)((int)this + 200) * iVar3 + 5000) / 10000;
  }
  else {
    iVar3 = *(int *)((int)this + 200);
  }
  *(int *)((int)this + 200) = iVar3;
  iVar3 = (**(code **)(*piVar2 + 0x4c))(piVar2,&param_1);
  if ((iVar3 < 0) || (iVar3 = (**(code **)(*piVar2 + 0x44))(piVar2,&param_1), iVar3 < 0))
  goto LAB_4144a2e6;
  *(int **)((int)this + 0x98) = param_1;
  iVar3 = (**(code **)(*piVar2 + 0x54))(piVar2,(int)this + 0xe4);
  if ((iVar3 < 0) || (iVar3 = (**(code **)(*piVar2 + 0xa8))(piVar2,(int)this + 0x68), iVar3 < 0))
  goto LAB_4144a2e6;
  if ((*(int *)((int)this + 0x68) != 0x13) && (*(int *)((int)this + 0x68) != 0x14)) {
    iVar3 = -0x7fffbfff;
    goto LAB_4144a2e6;
  }
  iVar3 = (**(code **)(*piVar2 + 0x100))(piVar2,&param_1);
  if (iVar3 < 0) goto LAB_4144a2e6;
  *(int **)((int)this + 0xc0) = param_1;
  iVar3 = (**(code **)(*piVar2 + 0x108))(piVar2,&param_1);
  if (iVar3 < 0) goto LAB_4144a2e6;
  *(int **)((int)this + 0xc4) = param_1;
  iVar3 = (**(code **)(*piVar2 + 0xb0))(piVar2,(int)this + 0x8c);
  if (iVar3 < 0) goto LAB_4144a2e6;
  iVar3 = (**(code **)(*piVar2 + 0xb8))(piVar2,(int)this + 0x60);
  if (param_2 == 0) {
    if ((*(int *)((int)this + 0x7c) == 0x5a) || (*(int *)((int)this + 0x7c) == 0x10e)) {
      iVar5 = *(int *)((int)this + 0xa4);
    }
    else {
      iVar5 = *(int *)((int)this + 0xa8);
    }
    iVar5 = (*(int *)((int)this + 0x60) * iVar5 + 5000) / 10000;
  }
  else {
    iVar5 = *(int *)((int)this + 0x60);
  }
  *(int *)((int)this + 0x60) = iVar5;
  if (iVar3 < 0) goto LAB_4144a2e6;
  CComQIPtr<>(local_14,piVar2);
  _local_8 = CONCAT31(uStack_7,2);
  if (local_14[0] == (int *)0x0) {
    iVar3 = -0x7fffbffb;
  }
  else {
    iVar3 = (**(code **)(*local_14[0] + 0x174))(local_14[0],(int)this + 0x9c);
    if (*(int *)((int)this + 0x68) == 0x14) {
      iVar5 = *(int *)((int)this + 0x9c);
      if (iVar5 < 2) {
        iVar5 = 2;
      }
      if (0x16 < iVar5) {
        iVar5 = 0x16;
      }
      *(int *)((int)this + 0x9c) = iVar5;
    }
  }
  if ((-1 < iVar3) && (iVar3 = (**(code **)(*piVar2 + 0xc0))(piVar2,&param_1), -1 < iVar3)) {
    *(int **)((int)this + 100) = param_1;
    iVar3 = (**(code **)(*piVar2 + 200))(piVar2,&param_1);
    if (-1 < iVar3) {
      puVar1 = (undefined4 *)((int)this + 0xac);
      *(int **)((int)this + 0x90) = param_1;
      SysFreeString((BSTR)*puVar1);
      *puVar1 = 0;
      iVar3 = (**(code **)(*piVar2 + 0xd0))(piVar2,puVar1);
      if ((((-1 < iVar3) &&
           (iVar3 = (**(code **)(*piVar2 + 0xd8))(piVar2,(int)this + 0xb0), -1 < iVar3)) &&
          (iVar3 = (**(code **)(*piVar2 + 0xe8))(piVar2,(int)this + 0xb4), -1 < iVar3)) &&
         (iVar3 = (**(code **)(*piVar2 + 0xe0))(piVar2,(int)this + 0xb8), -1 < iVar3)) {
        piVar2 = (int *)((int)this + 0xb8);
        if (*(int *)((int)this + 0x8c) < 1000) {
          *piVar2 = (*piVar2 * *(int *)((int)this + 0x8c)) / 1000;
        }
        piVar6 = (int *)((int)this + 0x8c);
        if (*piVar2 < 3) {
          *piVar2 = 3;
        }
        iVar3 = *(int *)((int)this + 0x7c);
        if (*(int *)((int)this + 0x68) - 0x13U < 2) {
          if (iVar3 == 0) {
LAB_4144a652:
            dVar7 = (double)*(int *)((int)this + 0xa8);
            dVar10 = (double)*(int *)((int)this + 0xa4) * (double)*piVar6;
            dVar8 = (double)*piVar6 * dVar7;
LAB_4144a68e:
            dVar9 = (dVar8 * DAT_414825d0) / _DAT_41484818;
            dVar8 = (dVar10 * DAT_414825d0) / _DAT_41484818;
            *(int *)((int)this + 0x94) = (int)(dVar7 * DAT_414825d0 + _DAT_41484810) / 100;
          }
          else {
            if (iVar3 == 0x5a) {
LAB_4144a610:
              dVar7 = (double)*(int *)((int)this + 0xa4);
              dVar10 = (double)*(int *)((int)this + 0xa8) * (double)*piVar6;
              dVar8 = dVar7 * (double)*piVar6;
              goto LAB_4144a68e;
            }
            if (iVar3 == 0xb4) goto LAB_4144a652;
            if (iVar3 == 0x10e) goto LAB_4144a610;
            dVar8 = (double)(ulonglong)local_20;
            dVar9 = (double)(ulonglong)local_20;
          }
          dVar9 = dVar9 + DAT_41480ff8;
          *(int *)((int)this + 0x5c) = (int)(dVar8 + DAT_41480ff8);
          *(int *)((int)this + 0x60) = (int)dVar9;
        }
        else {
          if (iVar3 == 0) {
LAB_4144a716:
            dVar7 = (double)*(int *)((int)this + 0xa4) * (double)*piVar6;
            iVar5 = *(int *)((int)this + 0xa8);
LAB_4144a736:
            dVar7 = (dVar7 * DAT_414825d0) / _DAT_41484818;
            *(int *)((int)this + 0x94) = (int)((double)iVar5 * DAT_414825d0 + _DAT_41484810) / 100;
          }
          else {
            if (iVar3 == 0x5a) {
LAB_4144a6f4:
              dVar7 = (double)*(int *)((int)this + 0xa8) * (double)*piVar6;
              iVar5 = *(int *)((int)this + 0xa4);
              goto LAB_4144a736;
            }
            if (iVar3 == 0xb4) goto LAB_4144a716;
            if (iVar3 == 0x10e) goto LAB_4144a6f4;
            dVar7 = (double)(ulonglong)local_20;
          }
          *(int *)((int)this + 0x5c) = (int)(dVar7 + DAT_41480ff8);
        }
        if (iVar3 == 0x10e) {
          *(int *)((int)this + 0x84) =
               *(int *)((int)this + 0x84) + (*(int *)((int)this + 200) - *(int *)((int)this + 0x60))
          ;
        }
        else if (iVar3 == 0xb4) {
          *(int *)((int)this + 0x88) =
               *(int *)((int)this + 0x88) + (*(int *)((int)this + 200) - *(int *)((int)this + 0x60))
          ;
        }
        iVar3 = FUN_4144a9b8((int)this);
      }
    }
  }
  local_8 = 1;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
LAB_4144a2e6:
  SysFreeString((BSTR)0x0);
  return iVar3;
}


