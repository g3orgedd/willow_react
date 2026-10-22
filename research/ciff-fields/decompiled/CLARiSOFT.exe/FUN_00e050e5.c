// Source: CLARiSOFT.exe @ 00e050e5; FUN_00e050e5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_00e050e5(void *this,OLECHAR *param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  UINT UVar5;
  HRESULT HVar6;
  undefined4 *puVar7;
  int iVar8;
  int local_24;
  LPCWSTR local_20;
  BSTR local_1c;
  ushort *local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0xe050f1;
  FUN_00e03b21(&local_20,param_1);
  local_8 = 0;
  iVar1 = *(int *)((int)this + 8);
  if (iVar1 != 0) {
    local_1c = (BSTR)0x0;
    puVar7 = (undefined4 *)**(undefined4 **)((int)this + 4);
    if (0 < iVar1) {
      do {
        iVar8 = puVar7[2];
        FUN_00e03bc2(local_14,*(LPCWSTR *)(iVar8 + 4));
        local_8._0_1_ = 1;
        FUN_00e03bc2(&local_18,local_20);
        iVar3 = FUN_00ecce60((ushort *)local_14[0],local_18);
        if (iVar3 == 0) {
          FUN_00e01f81((int *)&local_18);
          FUN_00e01f81((int *)local_14);
          goto LAB_00e052b2;
        }
        puVar7 = (undefined4 *)*puVar7;
        FUN_00e01f81((int *)&local_18);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00e01f81((int *)local_14);
        local_1c = (BSTR)((int)local_1c + 1);
      } while ((int)local_1c < iVar1);
    }
  }
  local_1c = (BSTR)0x0;
  puVar7 = (undefined4 *)**(undefined4 **)((int)this + 4);
  if (0 < iVar1) {
    do {
      iVar8 = puVar7[2];
      FUN_00e03bc2(&local_18,*(LPCWSTR *)(iVar8 + 4));
      local_8._0_1_ = 2;
      puVar4 = FUN_00e03bc2(local_14,param_1);
      iVar3 = FUN_00e052c5(&local_18,(undefined1 (*) [16])*puVar4,0);
      FUN_00e01f81((int *)local_14);
      if (iVar3 != -1) {
        FUN_00e01f81((int *)&local_18);
        goto LAB_00e052b2;
      }
      puVar7 = (undefined4 *)*puVar7;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00e01f81((int *)&local_18);
      local_1c = (BSTR)((int)local_1c + 1);
    } while ((int)local_1c < iVar1);
  }
  puVar7 = (undefined4 *)**(undefined4 **)((int)this + 4);
  FUN_00e03ab8(&local_1c,(int *)&local_20);
  local_8._0_1_ = 3;
  FUN_00e061b9(&local_1c);
  local_24 = 0;
  if (0 < iVar1) {
    do {
      iVar8 = puVar7[2];
      bVar2 = false;
      local_18 = (ushort *)0x0;
      do {
        local_14[0] = (BSTR)0x0;
        local_8._0_1_ = 4;
        (**(code **)(**(int **)(iVar8 + 0x30) + 0x4b8))(*(int **)(iVar8 + 0x30),local_18,local_14);
        local_18 = (ushort *)((int)local_18 + 1);
        UVar5 = SysStringLen(local_14[0]);
        if (UVar5 == 0) {
          bVar2 = true;
        }
        else {
          FUN_00e061b9(local_14);
          HVar6 = VarBstrCmp(local_14[0],local_1c,0x400,0);
          if (HVar6 == 1) {
            SysFreeString(local_14[0]);
            goto LAB_00e052a9;
          }
        }
        local_8._0_1_ = 3;
        SysFreeString(local_14[0]);
      } while (!bVar2);
      puVar7 = (undefined4 *)*puVar7;
      local_24 = local_24 + 1;
    } while (local_24 < iVar1);
  }
  iVar8 = 0;
LAB_00e052a9:
  SysFreeString(local_1c);
LAB_00e052b2:
  SysFreeString(local_20);
  return iVar8;
}


