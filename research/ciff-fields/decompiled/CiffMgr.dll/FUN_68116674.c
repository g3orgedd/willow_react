// Source: CiffMgr.dll @ 68116674; FUN_68116674

void FUN_68116674(int param_1,undefined4 *param_2)

{
  int iVar1;
  INT IVar2;
  int iVar3;
  uint local_24;
  int local_20;
  int *local_1c;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    if ((((*(int **)(param_1 + 0xa4) != (int *)0x0) &&
         (iVar1 = (**(code **)(**(int **)(param_1 + 0xa4) + 0x24))(), -1 < iVar1)) &&
        (local_20 != 0)) &&
       ((IVar2 = VariantTimeToSystemTime(*(DOUBLE *)(param_1 + 0x70),&local_18), IVar2 != 0 &&
        (iVar1 = 0, 0 < local_20)))) {
      do {
        local_1c = (int *)0x0;
        iVar1 = iVar1 + 1;
        iVar3 = (**(code **)(**(int **)(param_1 + 0xa4) + 0x20))
                          (*(int **)(param_1 + 0xa4),iVar1,&local_1c);
        if ((iVar3 < 0) || (iVar3 = (**(code **)(*local_1c + 0x1c))(), iVar3 < 0)) {
LAB_68116788:
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))();
          }
          break;
        }
        if (local_24 == local_18.wDay) {
          iVar3 = (**(code **)(*local_1c + 0x24))();
          if (iVar3 < 0) goto LAB_68116788;
          if (local_24 == local_18.wMonth) {
            *param_2 = 1;
            if (local_1c != (int *)0x0) {
              (**(code **)(*local_1c + 8))();
            }
            break;
          }
        }
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))();
        }
      } while (iVar1 < local_20);
    }
  }
  FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


