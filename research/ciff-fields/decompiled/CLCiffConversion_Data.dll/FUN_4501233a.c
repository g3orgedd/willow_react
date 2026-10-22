// Source: CLCiffConversion_Data.dll @ 4501233a; FUN_4501233a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_4501233a(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  _union_2683 local_44;
  _union_2683 local_34;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x45012346;
  iVar2 = 0;
  local_20 = param_1;
  FUN_45001f8d((uint *)&local_44);
  local_8 = 0;
  if ((*(int *)(*(int *)(*param_1 + 4) + 0x34 + (int)param_1) == 0) ||
     (piVar3 = *(int **)(*(int *)(*param_1 + 4) + 0x34 + (int)param_1),
     (**(code **)(*piVar3 + 100))(piVar3,&local_44), local_44.n2.vt == 0)) {
    iVar2 = -0x7fffbffb;
  }
  else {
    CComQIPtr<>(&local_18,(undefined4 *)local_44._8_4_);
    local_8._0_1_ = 1;
    if (local_18 == (int *)0x0) {
      iVar2 = -0x7fffbffb;
    }
    else {
      local_1c = 0;
      (**(code **)(*local_18 + 0x1c))(local_18,&local_1c);
      iVar1 = 0;
      if (0 < local_1c) {
        do {
          FUN_45001f8d((uint *)&local_34);
          iVar1 = iVar1 + 1;
          local_8._0_1_ = 2;
          (**(code **)(*local_18 + 0x30))(local_18,iVar1,&local_34);
          if (local_34.n2.vt != 0) {
            CComQIPtr<>(local_14,(undefined4 *)local_34._8_4_);
            local_8._0_1_ = 3;
            if (local_14[0] != (int *)0x0) {
              piVar3 = local_14[0];
              if (local_14[0] != (int *)0x0) {
                (**(code **)(*local_14[0] + 4))(local_14[0]);
              }
              iVar2 = FUN_4500cb62(local_20,piVar3);
              if (iVar2 < 0) {
                FUN_4500274d(0x4503f188);
                local_8._0_1_ = 2;
                if (local_14[0] != (int *)0x0) {
                  (**(code **)(*local_14[0] + 8))(local_14[0]);
                }
                VariantClear((VARIANTARG *)&local_34.n2);
                iVar2 = -0x7fffbffb;
                goto LAB_4501245f;
              }
              VariantClear((VARIANTARG *)&local_34.n2);
              FUN_4500aeef(&local_34,0);
              local_8._0_1_ = 2;
              if (local_14[0] != (int *)0x0) {
                (**(code **)(*local_14[0] + 8))(local_14[0]);
              }
            }
          }
          local_8._0_1_ = 1;
          VariantClear((VARIANTARG *)&local_34.n2);
        } while (iVar1 < local_1c);
      }
      VariantClear((VARIANTARG *)&local_44.n2);
      FUN_4500aeef(&local_44,0);
    }
LAB_4501245f:
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  VariantClear((VARIANTARG *)&local_44.n2);
  return iVar2;
}


