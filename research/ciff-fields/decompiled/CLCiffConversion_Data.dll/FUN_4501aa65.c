// Source: CLCiffConversion_Data.dll @ 4501aa65; FUN_4501aa65

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_4501aa65(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  HRESULT HVar3;
  int iVar4;
  BSTR pOVar5;
  BSTR bstrString;
  _union_2683 local_3c;
  int local_2c;
  int local_28;
  void *local_24;
  int local_20;
  BSTR local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x4501aa71;
  (**(code **)(*(int *)*param_1 + 0x10c))((int *)*param_1,&local_28);
  local_14[0] = (BSTR)0x0;
  bstrString = (BSTR)0x0;
  local_1c = (BSTR)0x0;
  local_20 = 0;
  local_8 = 1;
  iVar2 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_20);
  if (-1 < iVar2) {
    local_18 = (BSTR)0x0;
    iVar4 = 0;
    if (0 < local_20) {
      do {
        FUN_45001f8d((uint *)&local_3c);
        iVar4 = iVar4 + 1;
        local_8 = CONCAT31(local_8._1_3_,3);
        local_2c = iVar4;
        iVar2 = (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,iVar4,&local_3c);
        if ((-1 < iVar2) && (local_3c.n2.vt == 9)) {
          iVar2 = (*(code *)**(undefined4 **)local_3c._8_4_)(local_3c._8_4_,&DAT_4503d83c,&local_18)
          ;
          if ((iVar2 < 0) || (local_18 == (BSTR)0x0)) {
            iVar2 = -0x7fffbffb;
          }
          else {
            iVar2 = FUN_4501bb4b(local_24,local_18,local_28,local_14);
            pOVar5 = local_14[0];
            if (-1 < iVar2) {
              if (bstrString == (BSTR)0x0) {
                pOVar5 = (BSTR)0x0;
                if (local_14[0] != (BSTR)0x0) {
                  SysFreeString((BSTR)0x0);
                  local_1c = local_14[0];
                  bstrString = local_14[0];
                }
              }
              else {
                HVar3 = FUN_4500263d(&local_1c,local_14[0]);
                bstrString = local_1c;
                if (HVar3 < 0) {
                    /* WARNING: Subroutine does not return */
                  FUN_45002735(HVar3);
                }
              }
            }
            SysFreeString(pOVar5);
            local_14[0] = (BSTR)0x0;
            iVar4 = local_2c;
          }
          pOVar5 = local_18;
          if (local_18 != (BSTR)0x0) {
            local_18 = (BSTR)0x0;
            (**(code **)(*(int *)pOVar5 + 8))(pOVar5);
          }
        }
        VariantClear((VARIANTARG *)&local_3c.n2);
      } while (iVar4 < local_20);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (local_18 != (BSTR)0x0) {
      (**(code **)(*(int *)local_18 + 8))(local_18);
    }
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,bstrString);
    }
  }
  iVar4 = *(int *)(*(int *)((int)local_24 + 4) + 4);
  if (((*(char *)(iVar4 + 0x100 + (int)local_24) == '\0') &&
      (bVar1 = FUN_450023b0((void *)((int)local_24 + iVar4 + 0xe4),L"Capi"), bVar1)) &&
     (local_28 == 2)) {
    (**(code **)(*(int *)*param_1 + 0x110))((int *)*param_1,1);
  }
  SysFreeString(bstrString);
  SysFreeString((BSTR)0x0);
  return iVar2;
}


