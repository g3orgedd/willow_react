// Source: CLPrintPreview.ocx @ 3f414b05; FUN_3f414b05

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __fastcall FUN_3f414b05(int param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  HRESULT HVar3;
  code *pcVar4;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  int local_2c;
  int *local_28;
  int local_24;
  int local_20;
  int *local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  puVar2 = &LAB_3f43e2bd;
  local_8 = 0x3f414b11;
  if ((*(int *)(param_1 + 0xe8) != 0) && (piVar1 = *(int **)(param_1 + 0x108), piVar1 != (int *)0x0)
     ) {
    (**(code **)(*piVar1 + 0x30))(piVar1,*(undefined4 *)(param_1 + 0x128));
    FUN_3f4272e0((uint *)&local_4c,0,0x10);
    VariantInit(&local_4c);
    local_8 = 0;
    (**(code **)(**(int **)(param_1 + 0xe8) + 0x474))(*(int **)(param_1 + 0xe8),&local_4c);
    CComQIPtr<>(&local_28,(undefined4 *)local_4c.n1._8_4_);
    local_24 = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    (**(code **)(*local_28 + 0x24))(local_28,&local_24);
    local_20 = 0;
    pcVar4 = VariantClear_exref;
    if (0 < local_24) {
      do {
        FUN_3f4272e0((uint *)&local_3c,0,0x10);
        VariantInit(&local_3c);
        local_20 = local_20 + 1;
        local_8._0_1_ = 2;
        (**(code **)(*local_28 + 0x20))(local_28,local_20,&local_3c);
        CComQIPtr<>(&local_1c,(undefined4 *)local_3c.n1._8_4_);
        local_18 = (BSTR)0x0;
        local_8._0_1_ = 4;
        (**(code **)(*local_1c + 0x1c))(local_1c,&local_18);
        (**(code **)(**(int **)(param_1 + 0x108) + 0x24))(*(int **)(param_1 + 0x108),local_18);
        (**(code **)(*local_1c + 0x5c))(local_1c,&local_2c);
        pcVar4 = VariantClear_exref;
        if (local_2c == 1) {
          local_14[0] = (BSTR)0x0;
          local_8._0_1_ = 5;
          (**(code **)(*local_1c + 100))(local_1c,local_14);
          HVar3 = VarBstrCmp(local_18,local_14[0],0x400,0);
          if (HVar3 != 1) {
            (**(code **)(**(int **)(param_1 + 0x108) + 0x24))
                      (*(int **)(param_1 + 0x108),local_14[0]);
          }
          SysFreeString(local_14[0]);
        }
        SysFreeString(local_18);
        local_8 = CONCAT31(local_8._1_3_,2);
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        VariantClear(&local_3c);
      } while (local_20 < local_24);
    }
    local_8 = local_8 & 0xffffff00;
    if (local_28 != (int *)0x0) {
      (**(code **)(*local_28 + 8))(local_28);
    }
    puVar2 = (undefined1 *)(*pcVar4)(&local_4c);
  }
  return puVar2;
}


