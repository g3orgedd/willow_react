// Source: CLCSSmallBarcode.dll @ 4203106e; FUN_4203106e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_4203106e(int param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  UINT UVar4;
  int unaff_ESI;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  piVar2 = param_2;
  uStack_4 = 0x10;
  local_8 = 0x4203107a;
  if (param_2 == (int *)0x0) {
    return unaff_ESI;
  }
  CComQIPtr<>(&param_2,param_2);
  local_8 = 0;
  if (param_2 == (int *)0x0) {
LAB_4203115d:
    iVar3 = -0x7fffbffb;
    goto LAB_42031382;
  }
  *(undefined4 *)(param_1 + 0x80) = 0;
  SysFreeString(*(BSTR *)(param_1 + 0x7c));
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 1;
  iVar3 = (**(code **)(*piVar2 + 0x80))(piVar2,param_1 + 0xa0);
  if (iVar3 < 0) goto LAB_42031382;
  if (param_3 == 0) {
    iVar3 = (*(int *)(param_1 + 0xb0) * *(int *)(param_1 + 0xa0) + 5000) / 10000;
  }
  else {
    iVar3 = *(int *)(param_1 + 0xa0);
  }
  *(int *)(param_1 + 0xa0) = iVar3;
  puVar1 = (undefined4 *)(param_1 + 0x84);
  SysFreeString((BSTR)*puVar1);
  *puVar1 = 0;
  iVar3 = (**(code **)(*piVar2 + 0x1c))(piVar2,puVar1);
  if (iVar3 < 0) goto LAB_42031382;
  puVar1 = (undefined4 *)(param_1 + 0x88);
  SysFreeString((BSTR)*puVar1);
  *puVar1 = 0;
  iVar3 = (**(code **)(*piVar2 + 0x98))(piVar2,puVar1);
  if (iVar3 < 0) goto LAB_42031382;
  UVar4 = SysStringLen(*(BSTR *)(param_1 + 0x88));
  if (UVar4 == 0) goto LAB_4203115d;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  local_18 = 0;
  iVar3 = (**(code **)(*piVar2 + 0x44))(piVar2,&local_18);
  if (iVar3 < 0) goto LAB_42031382;
  *(bool *)(param_1 + 0x90) = local_18 != 0;
  iVar3 = (**(code **)(*piVar2 + 0x54))(piVar2,param_1 + 0x94);
  if (iVar3 < 0) goto LAB_42031382;
  (**(code **)(*piVar2 + 0xa8))(piVar2,param_1 + 0x1b08);
  iVar3 = (**(code **)(*piVar2 + 0x108))(piVar2,param_1 + 0x1b0c);
  if ((iVar3 < 0) || (iVar3 = (**(code **)(*piVar2 + 0x15c))(piVar2,param_1 + 0x8c), iVar3 < 0))
  goto LAB_42031382;
  FUN_42002e41(&local_1c);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_42003a92(*(int *)(param_1 + 0x8c),*(int *)(param_1 + 0xac),&local_20);
  if (local_20 < 1) {
    local_20 = 1;
  }
  *(int *)(param_1 + 0x8c) = local_20;
  iVar3 = (**(code **)(*param_2 + 0x16c))(param_2,param_1 + 0xc0);
  if (-1 < iVar3) {
    *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc0) * *(int *)(param_1 + 0x8c);
    iVar3 = (**(code **)(*param_2 + 0x174))(param_2,param_1 + 200);
    if ((-1 < iVar3) &&
       (iVar3 = (**(code **)(*param_2 + 0x17c))(param_2,param_1 + 0xcc), -1 < iVar3)) {
      if (*(int *)(param_1 + 0x1b08) == 0x10) {
        iVar3 = (**(code **)(*param_2 + 0x184))(param_2,param_1 + 0xd8);
        if (-1 < iVar3) {
          iVar3 = (**(code **)(*param_2 + 0x18c))(param_2,param_1 + 0xdc);
LAB_420312cf:
          if (-1 < iVar3) goto LAB_420312d9;
        }
      }
      else {
        if (*(int *)(param_1 + 0x1b08) == 0x11) {
          iVar3 = (**(code **)(*param_2 + 0x194))(param_2,param_1 + 0xe0);
          goto LAB_420312cf;
        }
LAB_420312d9:
        local_14[0] = 0;
        iVar3 = (**(code **)(*piVar2 + 0x14c))(piVar2,local_14);
        if (param_3 == 0) {
          local_14[0] = (*(int *)(param_1 + 0xac) * local_14[0] + 5000) / 10000;
        }
        if (-1 < iVar3) {
          *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + local_14[0];
          iVar3 = (**(code **)(*piVar2 + 0xb8))(piVar2,param_1 + 0x70);
          if (-1 < iVar3) {
            if (param_3 == 0) {
              iVar3 = (*(int *)(param_1 + 0xb0) * *(int *)(param_1 + 0x70) + 5000) / 10000;
            }
            else {
              iVar3 = *(int *)(param_1 + 0x70);
            }
            *(int *)(param_1 + 0x70) = iVar3;
            iVar3 = FUN_420279b1(param_1);
          }
        }
      }
    }
  }
  local_8 = local_8 & 0xffffff00;
  FUN_420030e8(&local_1c);
LAB_42031382:
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return iVar3;
}


