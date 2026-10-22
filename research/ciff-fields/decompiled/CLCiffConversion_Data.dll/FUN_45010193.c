// Source: CLCiffConversion_Data.dll @ 45010193; FUN_45010193

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_45010193(void *this,BSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  UINT UVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  BSTR pOVar8;
  uint local_20;
  int local_1c;
  uint local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x4501019f;
  uVar5 = 0;
  FUN_45001f5d(local_14,L"");
  pOVar8 = param_1;
  local_8 = 0;
  UVar4 = SysStringLen(*(BSTR *)param_1);
  uVar3 = *(uint *)pOVar8;
  local_1c = UVar4 - 1;
  sVar1 = *(short *)(uVar3 + local_1c * 2);
  while ((sVar1 != 0x3d && (local_1c = local_1c + -1, 0 < local_1c))) {
    sVar1 = *(short *)(uVar3 + local_1c * 2);
  }
  local_20 = uVar3;
  local_18 = UVar4;
  if (-1 < local_1c) {
    pOVar8 = (BSTR)0x0;
    param_1 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,1);
    sVar1 = *(short *)(uVar3 + local_1c * 2);
    iVar6 = local_1c;
    while (sVar1 != 0x27) {
      iVar6 = iVar6 + 1;
      sVar1 = *(short *)(uVar3 + iVar6 * 2);
    }
    if (iVar6 < (int)UVar4) {
      iVar6 = iVar6 + 1;
      uVar2 = *(ushort *)(uVar3 + iVar6 * 2);
      while (uVar2 != 0x27) {
        local_18 = (uint)uVar2;
        FUN_45002522(&param_1,(wchar_t *)&local_18);
        iVar6 = iVar6 + 1;
        if ((int)UVar4 <= iVar6) break;
        uVar2 = *(ushort *)(uVar3 + iVar6 * 2);
      }
      iVar6 = local_1c;
      pOVar8 = param_1;
      UVar4 = SysStringLen(param_1);
      uVar3 = local_20;
      if (UVar4 != 0) {
        if (-1 < iVar6) {
          iVar7 = 0;
          do {
            local_20 = (uint)*(ushort *)(uVar3 + iVar7 * 2);
            FUN_45002522(local_14,(wchar_t *)&local_20);
            iVar7 = iVar7 + 1;
            pOVar8 = param_1;
          } while (iVar7 <= iVar6);
        }
        FUN_4500263d(local_14,pOVar8);
      }
      uVar5 = (**(code **)(**(int **)((int)this + 0x20) + 0x40))
                        (*(int **)((int)this + 0x20),local_14[0],param_2,param_3,param_4);
    }
    else {
      uVar5 = 0;
    }
    SysFreeString(pOVar8);
  }
  SysFreeString(local_14[0]);
  return uVar5;
}


