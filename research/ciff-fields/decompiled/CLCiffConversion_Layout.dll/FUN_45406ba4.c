// Source: CLCiffConversion_Layout.dll @ 45406ba4; FUN_45406ba4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_45406ba4(int *param_1)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  UINT UVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *local_20;
  undefined4 local_1c;
  int *local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x45406bb0;
  bVar2 = false;
  local_14[0] = (BSTR)0x0;
  local_1c = 0;
  local_20 = (undefined4 *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8 = 0;
  FUN_45406e39(param_1,param_1 + 0xd,&local_20);
  *(undefined1 *)(param_1 + 0x40) = 0;
  UVar4 = SysStringLen((BSTR)param_1[0x12]);
  if (UVar4 != 0) {
    if (param_1[0x13] != 0) {
      puVar5 = FUN_45402ac2(&local_18,(wchar_t *)param_1[0x12]);
      local_14[0] = (BSTR)0x1;
      local_8 = CONCAT31(local_8._1_3_,1);
      if (*(void **)(param_1[0x13] + 0x3c) == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_4541c12a(*(void **)(param_1[0x13] + 0x3c),puVar5);
      }
      if (iVar6 != 0) {
        bVar2 = true;
      }
    }
    local_8 = 0;
    if (((uint)local_14[0] & 1) != 0) {
      FUN_45402c5d((int *)&local_18);
    }
    if (bVar2) {
      *(undefined1 *)(param_1 + 0x40) = 1;
    }
  }
  if ((char)param_1[0x40] == '\0') {
    local_14[0] = (BSTR)0x0;
    local_8._0_1_ = 2;
    (**(code **)(*(int *)param_1[0xe] + 0x1c))((int *)param_1[0xe],local_14);
    piVar1 = (int *)param_1[0xd];
    (**(code **)(*piVar1 + 0x48))(piVar1,local_14[0]);
    local_8 = (uint)local_8._1_3_ << 8;
    SysFreeString(local_14[0]);
  }
  puVar3 = local_20;
  for (puVar5 = (undefined4 *)*local_20; puVar5 != puVar3; puVar5 = (undefined4 *)*puVar5) {
    local_18 = (int *)puVar5[2];
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 4))(local_18);
    }
    local_8._0_1_ = 3;
    (**(code **)(*param_1 + 4))(&local_18);
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  FUN_454065bf((int *)&local_20);
  FUN_454224ff((int *)&local_20);
  FID_conflict__free(local_20);
  return 0;
}


