// Source: CiffHelper.dll @ 4081ccc2; FUN_4081ccc2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_4081ccc2(short param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined1 *puVar2;
  BSTR extraout_ECX;
  int iVar3;
  int iVar4;
  BSTR pOVar5;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  int local_28;
  int *local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  LPCWSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  puVar2 = &LAB_408473e6;
  local_8 = 0x4081ccce;
  iVar3 = -0x7fffbffb;
  if (param_1 == 0xd) {
    CComQIPtr<>(&local_1c,param_3);
    local_8 = 0;
    if (local_1c != (int *)0x0) {
      FUN_40802e76((uint *)&local_4c);
      local_8._0_1_ = 1;
      iVar3 = (**(code **)(*local_1c + 100))(local_1c);
      if (-1 < iVar3) {
        iVar3 = -0x7fffbffb;
        CComQIPtr<>(&local_18,(undefined4 *)local_4c.n1._8_4_);
        local_8._0_1_ = 2;
        if (((local_18 != (int *)0x0) &&
            (iVar3 = (**(code **)(*local_18 + 0x1c))(local_18), -1 < iVar3)) &&
           (iVar4 = 0, 0 < local_20)) {
          do {
            if (iVar3 < 0) break;
            FUN_40802e76((uint *)&local_3c);
            local_8._0_1_ = 3;
            iVar3 = (**(code **)(*local_18 + 0x30))(local_18,iVar4 + 1);
            if (-1 < iVar3) {
              iVar3 = -0x7fffbffb;
              CComQIPtr<>(&local_24,(undefined4 *)local_3c.n1._8_4_);
              if (local_24 != (int *)0x0) {
                local_14[0] = (LPCWSTR)0x0;
                local_8._0_1_ = 5;
                iVar3 = (**(code **)(*local_24 + 0x1c))(local_24);
                if (-1 < iVar3) {
                  pOVar5 = extraout_ECX;
                  FUN_40803baf(&stack0xffffffa0,(int *)local_14);
                  cVar1 = FUN_40805c54(&local_1c,pOVar5);
                  if (cVar1 == '\0') {
                    FUN_408030e3(&local_28,local_14[0]);
                    local_8._0_1_ = 6;
                    FUN_40819678(0x4084ca34);
                    local_8._0_1_ = 5;
                    FUN_40803143(&local_28);
                    (**(code **)(*local_18 + 0x24))(local_18);
                    iVar4 = iVar4 + -1;
                    iVar3 = (**(code **)(*local_18 + 0x1c))(local_18,&local_20);
                  }
                }
                SysFreeString(local_14[0]);
              }
              local_8._0_1_ = 3;
              if (local_24 != (int *)0x0) {
                (**(code **)(*local_24 + 8))();
              }
            }
            iVar4 = iVar4 + 1;
            VariantClear(&local_3c);
          } while (iVar4 < local_20);
        }
        local_8._0_1_ = 1;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))();
        }
      }
      VariantClear(&local_4c);
    }
    local_8 = 0xffffffff;
    puVar2 = (undefined1 *)0x0;
    if (local_1c != (int *)0x0) {
      puVar2 = (undefined1 *)(**(code **)(*local_1c + 8))();
    }
    if (-1 < iVar3) {
      return CONCAT31((int3)((uint)puVar2 >> 8),1);
    }
  }
  return (uint)puVar2 & 0xffffff00;
}


