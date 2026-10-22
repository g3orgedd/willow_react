// Source: CiffHelper.dll @ 408268cb; FUN_408268cb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_408268cb(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  BSTR bstrString;
  code *pcVar5;
  _union_2683 local_58;
  _union_2683 local_48;
  _union_2683 local_38;
  undefined4 local_28;
  BSTR local_24 [2];
  BSTR local_1c;
  undefined4 local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x48;
  iVar3 = 0;
  if (*param_1 == 0) {
    return 0;
  }
  local_14[0] = (int *)0x0;
  local_8 = 0;
  FUN_40802e76((uint *)&local_58);
  local_8._0_1_ = 1;
  iVar2 = (**(code **)(*(int *)*piVar1 + 0x4c))((int *)*piVar1,&local_58);
  pcVar5 = SysFreeString_exref;
  if (((-1 < iVar2) && (local_58.n2.vt == 9)) && ((undefined4 *)local_58._8_4_ != (undefined4 *)0x0)
     ) {
    param_1 = (int *)0x0;
    local_8._0_1_ = 2;
    iVar2 = (*(code *)**(undefined4 **)local_58._8_4_)(local_58._8_4_,&DAT_4084aae4,&param_1);
    if ((-1 < iVar2) && (param_1 != (int *)0x0)) {
      FUN_40802e40(&local_1c,L"Claricom");
      FUN_40802e76((uint *)&local_48);
      local_8._0_1_ = 4;
      iVar2 = (**(code **)(*param_1 + 0x30))(param_1,local_1c,&local_48);
      if ((-1 < iVar2) &&
         ((local_48.n2.vt == 9 && ((undefined4 *)local_48._8_4_ != (undefined4 *)0x0)))) {
        (*(code *)**(undefined4 **)local_48._8_4_)(local_48._8_4_,&DAT_4084aaf4,local_14);
      }
      VariantClear((VARIANTARG *)&local_48.n2);
      SysFreeString(local_1c);
    }
    local_8._0_1_ = 1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  if (local_14[0] == (int *)0x0) goto LAB_40826b72;
  FUN_40802e40(&local_18,L"Width(mm)");
  local_8._0_1_ = 5;
  FUN_40802e40(&local_28,L"Width(hundredths mm)");
  FUN_40802e76((uint *)&local_38);
  uVar4 = local_18;
  local_8._0_1_ = 7;
  iVar2 = (**(code **)(*local_14[0] + 0x30))(local_14[0],local_18,&local_38);
  if (iVar2 < 0) {
    FUN_40803e97(&local_18,L"Width");
    iVar2 = (**(code **)(*local_14[0] + 0x30))(local_14[0],local_18,&local_38);
    uVar4 = local_18;
    if (-1 < iVar2) goto LAB_40826a2b;
  }
  else {
LAB_40826a2b:
    if ((local_38.n2.vt == 9) && ((undefined4 *)local_38._8_4_ != (undefined4 *)0x0)) {
      param_1 = (int *)0x0;
      local_8._0_1_ = 8;
      iVar2 = (*(code *)**(undefined4 **)local_38._8_4_)(local_38._8_4_,&DAT_4084ab18,&param_1);
      if ((-1 < iVar2) && (param_1 != (int *)0x0)) {
        FUN_408267f8((int *)local_14,(int *)&param_1,&local_18,&local_28);
        FUN_40802e40(&local_1c,L"ProductDelay(mm)");
        local_8._0_1_ = 9;
        FUN_40802e40(local_24,L"ProductDelay(hundredths mm)");
        local_8._0_1_ = 10;
        VariantClear((VARIANTARG *)&local_38.n2);
        bstrString = local_1c;
        iVar2 = (**(code **)(*local_14[0] + 0x30))(local_14[0],local_1c,&local_38);
        if (iVar2 < 0) {
          FUN_40803e97(&local_1c,L"ProductDelay");
          iVar2 = (**(code **)(*local_14[0] + 0x30))(local_14[0],local_1c,&local_38);
          bstrString = local_1c;
          if (-1 < iVar2) goto LAB_40826ae8;
        }
        else {
LAB_40826ae8:
          piVar1 = param_1;
          if ((local_38.n2.vt == 9) && ((undefined4 *)local_38._8_4_ != (undefined4 *)0x0)) {
            if (param_1 != (int *)0x0) {
              param_1 = (int *)0x0;
              (**(code **)(*piVar1 + 8))(piVar1);
            }
            iVar2 = (*(code *)**(undefined4 **)local_38._8_4_)
                              (local_38._8_4_,&DAT_4084ab18,&param_1);
          }
          if ((-1 < iVar2) && (param_1 != (int *)0x0)) {
            iVar3 = FUN_408267f8((int *)local_14,(int *)&param_1,&local_1c,local_24);
          }
        }
        SysFreeString(local_24[0]);
        pcVar5 = SysFreeString_exref;
        SysFreeString(bstrString);
      }
      local_8._0_1_ = 7;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    }
  }
  VariantClear((VARIANTARG *)&local_38.n2);
  (*pcVar5)(local_28);
  (*pcVar5)(uVar4);
LAB_40826b72:
  VariantClear((VARIANTARG *)&local_58.n2);
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar3;
}


