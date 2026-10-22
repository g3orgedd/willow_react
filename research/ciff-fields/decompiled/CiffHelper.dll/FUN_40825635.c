// Source: CiffHelper.dll @ 40825635; FUN_40825635

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_40825635(void *this,int *param_1)

{
  bool bVar1;
  int iVar2;
  _union_2683 local_38;
  _union_2683 local_28;
  BSTR local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x40825641;
  FUN_40802e76((uint *)&local_38);
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)*param_1 + 0x4c))((int *)*param_1,&local_38);
  if ((-1 < iVar2) && (local_38.n2.vt == 9)) {
    local_14[0] = (int *)0x0;
    local_8._0_1_ = 1;
    iVar2 = (*(code *)**(undefined4 **)local_38._8_4_)(local_38._8_4_,&DAT_4084aae4,local_14);
    if ((-1 < iVar2) && (local_14[0] != (int *)0x0)) {
      FUN_40802e40(&local_18,L"Claricom");
      FUN_40802e76((uint *)&local_28);
      local_8._0_1_ = 3;
      iVar2 = (**(code **)(*local_14[0] + 0x30))(local_14[0],local_18,&local_28);
      if ((iVar2 < 0) || (local_28.n2.vt != 9)) {
        if (iVar2 == -0x7ff8ffa9) {
          iVar2 = 0;
        }
      }
      else {
        param_1 = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,4);
        iVar2 = (*(code *)**(undefined4 **)local_28._8_4_)(local_28._8_4_,&DAT_4084aaf4,&param_1);
        if ((((-1 < iVar2) && (param_1 != (int *)0x0)) && (*(int *)((int)this + 8) < 9)) &&
           (bVar1 = FUN_40803ed6((void *)((int)this + 0xc),L"WSI 43s"), bVar1)) {
          iVar2 = FUN_40823f95((int *)&param_1);
        }
        local_8._0_1_ = 3;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      VariantClear((VARIANTARG *)&local_28.n2);
      SysFreeString(local_18);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  VariantClear((VARIANTARG *)&local_38.n2);
  return iVar2;
}


