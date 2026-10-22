// Source: CLCiffConversion_Data.dll @ 4501b5ab; FUN_4501b5ab

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

BSTR FUN_4501b5ab(int *param_1)

{
  int *piVar1;
  BSTR pOVar2;
  UINT UVar3;
  int iVar4;
  int local_24;
  BSTR local_20;
  UINT local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x14;
  local_8 = 0x4501b5b7;
  if (param_1 == (int *)0x0) {
    return (BSTR)0x80004003;
  }
  pOVar2 = (BSTR)(**(code **)(*param_1 + 0x94))(param_1,&local_1c);
  if ((int)pOVar2 < 0) {
    return pOVar2;
  }
  pOVar2 = (BSTR)(**(code **)(*piVar1 + 0xa4))(piVar1,&param_1);
  if ((int)pOVar2 < 0) {
    return pOVar2;
  }
  pOVar2 = (BSTR)(**(code **)(*piVar1 + 0xac))(piVar1,&local_24);
  if ((int)pOVar2 < 0) {
    return pOVar2;
  }
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  local_20 = (BSTR)(**(code **)(*piVar1 + 0x60))(piVar1,local_14);
  if (-1 < (int)local_20) {
    if (local_1c == 0) {
      local_18 = (BSTR)0x0;
      local_8._0_1_ = 1;
      local_20 = (BSTR)(**(code **)(*piVar1 + 0x58))(piVar1,&local_18);
      local_1c = SysStringLen(local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      SysFreeString(local_18);
    }
    UVar3 = SysStringLen(local_14[0]);
    iVar4 = UVar3 - local_1c;
    if ((iVar4 == 0) || ((int)local_1c < 1)) {
      if (local_1c != 0) goto LAB_4501b787;
      SysFreeString(local_14[0]);
      local_14[0] = (BSTR)0x0;
    }
    else {
      local_18 = (BSTR)0x0;
      if (iVar4 < 1) {
        if (iVar4 < 0) {
          iVar4 = -iVar4;
          if (local_24 == 1) {
            local_18 = SysAllocStringLen((OLECHAR *)0x0,local_1c);
            pOVar2 = local_18;
            if (local_18 != (BSTR)0x0) {
              for (; local_20 = pOVar2, 0 < iVar4; iVar4 = iVar4 + -1) {
                *local_20 = (OLECHAR)param_1;
                pOVar2 = local_20 + 1;
              }
              UVar3 = SysStringLen(local_14[0]);
              FUN_45021540((undefined8 *)local_20,(undefined8 *)local_14[0],UVar3 * 2);
              local_18[local_1c] = L'\0';
            }
          }
          else {
            local_18 = SysAllocStringLen((OLECHAR *)0x0,local_1c);
            if (local_18 != (BSTR)0x0) {
              UVar3 = SysStringLen(local_14[0]);
              FUN_45021540((undefined8 *)local_18,(undefined8 *)local_14[0],UVar3 * 2);
              UVar3 = SysStringLen(local_14[0]);
              pOVar2 = local_18 + UVar3;
              for (; 0 < iVar4; iVar4 = iVar4 + -1) {
                *pOVar2 = (OLECHAR)param_1;
                pOVar2 = pOVar2 + 1;
              }
              *pOVar2 = L'\0';
            }
          }
        }
      }
      else if (local_24 == 1) {
        local_18 = SysAllocString(local_14[0] + iVar4);
      }
      else {
        local_18 = SysAllocStringLen(local_14[0],local_1c);
      }
      SysFreeString(local_14[0]);
      local_14[0] = (BSTR)0x0;
      if (local_18 != (BSTR)0x0) {
        SysFreeString((BSTR)0x0);
        local_14[0] = local_18;
      }
    }
    local_20 = (BSTR)(**(code **)(*piVar1 + 100))(piVar1,local_14[0]);
  }
LAB_4501b787:
  SysFreeString(local_14[0]);
  return local_20;
}


