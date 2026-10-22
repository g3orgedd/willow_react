// Source: CLCSSmallBarcode.dll @ 4200b68d; FUN_4200b68d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4200b68d(void *this,BSTR param_1,int *param_2,BSTR param_3)

{
  longlong lVar1;
  BSTR bstrString;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  UINT UVar5;
  int *piVar6;
  int iVar7;
  BSTR pOVar8;
  wchar_t local_30 [2];
  short *local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  void *local_1c;
  UINT local_18;
  char local_11;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar8 = param_1;
  uStack_4 = 0x20;
  local_8 = 0x4200b699;
  if (param_1 == (BSTR)0x0) {
    local_24 = 0x80004005;
  }
  else {
    local_1c = this;
    local_18 = SysStringLen(*(BSTR *)((int)this + 0x28));
    local_24 = 0;
    local_20 = 0;
    lVar1 = (ulonglong)(local_18 + 3) * 4;
    uVar2 = FUN_42067510(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    piVar6 = param_2;
    *(undefined4 *)pOVar8 = uVar2;
    *param_2 = 0;
    if (*(undefined4 **)pOVar8 == (undefined4 *)0x0) {
      local_24 = 0x8007000e;
    }
    else {
      **(undefined4 **)pOVar8 = 0x2b;
      iVar7 = 0;
      *param_2 = *param_2 + 1;
      local_11 = '\0';
      if (0 < (int)local_18) {
        do {
          local_2c = *(short **)((int)local_1c + 0x28);
          iVar3 = FUN_4200c145(local_2c[iVar7],&local_28);
          if (iVar3 == 0) {
            if ((((iVar7 == 0) || (iVar7 == local_18 - 1)) && (*local_2c == 0x2a)) &&
               (local_2c[local_18 - 1] == 0x2a)) {
              local_11 = '\x01';
            }
            else {
              if (local_20 == 0) {
                local_20 = 1;
                iVar3 = FUN_420059bf(param_3,
                                     L"Code 39 Encountered invalid barcode characters in field data: \'"
                                    );
                if (iVar3 < 0) goto LAB_4200b7f8;
                local_24 = 0x4022a;
              }
              _swprintf_s(local_30,2,L"%c",
                          (uint)*(ushort *)(*(int *)((int)local_1c + 0x28) + iVar7 * 2));
              iVar3 = FUN_420059bf(param_3,local_30);
              if (iVar3 < 0) {
LAB_4200b7f8:
                    /* WARNING: Subroutine does not return */
                FUN_4200345c(iVar3);
              }
            }
          }
          else {
            *(int *)(*(int *)pOVar8 + *piVar6 * 4) = local_28;
            *piVar6 = *piVar6 + 1;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < (int)local_18);
      }
      if (*(int *)((int)local_1c + 0x44) != 0) {
        iVar7 = *piVar6;
        iVar3 = *(int *)param_1;
        iVar4 = FUN_4200b405(iVar3 + 4,iVar7 + -1);
        *(int *)(iVar3 + iVar7 * 4) = iVar4;
        *piVar6 = *piVar6 + 1;
        pOVar8 = param_1;
      }
      *(undefined4 *)(*(int *)pOVar8 + *piVar6 * 4) = 0x2b;
      *piVar6 = *piVar6 + 1;
      if (local_11 == '\0') {
        UVar5 = *piVar6 - 1;
      }
      else {
        UVar5 = *piVar6 + 1;
      }
      FUN_4200ad97(&param_3,UVar5);
      bstrString = param_3;
      UVar5 = 0;
      local_8 = 0;
      param_1 = (BSTR)0x0;
      if (0 < *piVar6) {
        do {
          iVar7 = *(int *)(*(int *)pOVar8 + (int)param_1 * 4);
          if ((iVar7 != 0x2b) || (local_11 != '\0')) {
            param_3[UVar5] = *(OLECHAR *)(&DAT_4208a63c + iVar7 * 8);
            UVar5 = UVar5 + 1;
          }
          *(undefined4 *)(*(int *)pOVar8 + (int)param_1 * 4) =
               *(undefined4 *)(&DAT_4208a638 + *(int *)(*(int *)pOVar8 + (int)param_1 * 4) * 8);
          param_1 = (BSTR)((int)param_1 + 1);
        } while ((int)param_1 < *param_2);
      }
      param_3[UVar5] = L'\0';
      piVar6 = FUN_420055da(&param_1,UVar5,param_3);
      FUN_4200af88((void *)((int)local_1c + 0x58),piVar6);
      SysFreeString(param_1);
      SysFreeString(bstrString);
    }
  }
  return local_24;
}


