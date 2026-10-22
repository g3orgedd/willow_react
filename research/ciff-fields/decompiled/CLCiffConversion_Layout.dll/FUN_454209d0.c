// Source: CLCiffConversion_Layout.dll @ 454209d0; FUN_454209d0

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_454209d0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined ***pppuVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined **local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  VARIANTARG local_68;
  undefined **local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  _union_2683 local_48;
  int *local_38;
  BSTR local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0x454209dc;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::ResolveCapabilitiesFormatReference");
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if ((*(short *)(param_1 + 0x1d8) == 0xd) && (*(int *)(param_1 + 0x1e0) != 0)) {
    piVar5 = (int *)(param_1 + 0x40);
    if (*piVar5 != 0) {
      piVar1 = (int *)*piVar5;
      if (piVar1 != (int *)0x0) {
        *piVar5 = 0;
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar1 = (int *)*piVar5;
      if ((piVar1 != (int *)0x0) && (*piVar5 = 0, piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
    FUN_45413189(piVar5,*(int **)(param_1 + 0x1e0));
    goto LAB_45420a3f;
  }
  if ((*(int *)(param_1 + 0x38) == 0) || (*(short *)(param_1 + 0x148) != 8)) goto LAB_45420a3f;
  FUN_45429f70((uint *)&local_68,0,0x10);
  VariantInit(&local_68);
  local_8._0_1_ = 2;
  iVar2 = (**(code **)(**(int **)(param_1 + 0x38) + 0x470))(*(int **)(param_1 + 0x38),&local_68);
  if (iVar2 < 0) {
    pppuVar3 = &local_78;
    local_78 = _com_error::vftable;
    local_70 = 0;
    local_6c = 0;
    local_74 = iVar2;
    goto LAB_45420aad;
  }
  CComQIPtr<>(&local_38,(undefined4 *)local_68.n1._8_4_);
  FUN_45429f70((uint *)&local_48,0,0x10);
  VariantInit((VARIANTARG *)&local_48.n2);
  piVar5 = local_38;
  local_8._0_1_ = 4;
  if (local_38 == (int *)0x0) {
    local_54 = -0x7fffbffb;
LAB_45420b45:
    if (-1 < local_54) {
LAB_45420b66:
      piVar5 = (int *)(param_1 + 0x40);
      if (*piVar5 != 0) {
        piVar1 = (int *)*piVar5;
        if (piVar1 != (int *)0x0) {
          *piVar5 = 0;
          (**(code **)(*piVar1 + 8))(piVar1);
        }
        piVar1 = (int *)*piVar5;
        if (piVar1 != (int *)0x0) {
          *piVar5 = 0;
          (**(code **)(*piVar1 + 8))(piVar1);
        }
      }
      if ((local_48.n2.vt == 9) && ((undefined4 *)local_48._8_4_ != (undefined4 *)0x0)) {
        (*(code *)**(undefined4 **)local_48._8_4_)(local_48._8_4_,&DAT_45447e5c,piVar5);
      }
      VariantClear((VARIANTARG *)&local_48.n2);
      local_8._0_1_ = 2;
      if (local_38 != (int *)0x0) {
        (**(code **)(*local_38 + 8))(local_38);
      }
      VariantClear(&local_68);
LAB_45420a3f:
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
      FUN_4542a966();
      return;
    }
  }
  else {
    puVar4 = FUN_454028ee(&local_34,*(OLECHAR **)(param_1 + 0x150));
    local_8._0_1_ = 5;
    iVar2 = (**(code **)(*piVar5 + 0x30))(piVar5,*puVar4,&local_48);
    local_8._0_1_ = 4;
    SysFreeString(local_34);
    if (-1 < iVar2) goto LAB_45420b66;
    local_34 = (BSTR)0x0;
    local_54 = (**(code **)(*local_38 + 0x24))(local_38,&local_34);
    if (-1 < local_54) {
      if (local_34 != (BSTR)0x0) {
        local_54 = (**(code **)(*local_38 + 0x20))(local_38,1,&local_48);
      }
      goto LAB_45420b45;
    }
  }
  local_58 = _com_error::vftable;
  pppuVar3 = &local_58;
  local_50 = 0;
  local_4c = 0;
LAB_45420aad:
                    /* WARNING: Subroutine does not return */
  FUN_4542a8e0((int *)pppuVar3,&DAT_4545636c);
}


