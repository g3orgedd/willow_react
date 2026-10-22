// Source: CLCiffConversion_Layout.dll @ 4542064b; FUN_4542064b

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4542064b(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined ***pppuVar3;
  int *piVar4;
  undefined **local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  VARIANTARG local_68;
  VARIANTARG local_58;
  undefined **local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  BSTR local_38;
  int *local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8 = 0x45420657;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"CCiffConversion_Layout::ResolveCapabilitiesCoderReference");
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if ((*(short *)(param_1 + 0x1a8) == 0xd) && (*(int *)(param_1 + 0x1b0) != 0)) {
    piVar4 = (int *)(param_1 + 0x38);
    if (*piVar4 != 0) {
      piVar1 = (int *)*piVar4;
      if (piVar1 != (int *)0x0) {
        *piVar4 = 0;
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      piVar1 = (int *)*piVar4;
      if ((piVar1 != (int *)0x0) && (*piVar4 = 0, piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
    }
    FUN_45413189(piVar4,*(int **)(param_1 + 0x1b0));
  }
  else if (*(short *)(param_1 + 0x118) == 8) {
    FUN_45429f70((uint *)&local_68,0,0x10);
    VariantInit(&local_68);
    local_8._0_1_ = 2;
    iVar2 = (**(code **)(**(int **)(param_1 + 0x34) + 0x3c))(*(int **)(param_1 + 0x34),&local_68);
    if (iVar2 < 0) {
      local_40 = 0;
      local_3c = 0;
      pppuVar3 = &local_48;
      local_48 = _com_error::vftable;
      local_44 = iVar2;
    }
    else {
      CComQIPtr<>(&local_34,(undefined4 *)local_68.n1._8_4_);
      FUN_45429f70((uint *)&local_58,0,0x10);
      VariantInit(&local_58);
      local_8._0_1_ = 4;
      FUN_454028ee(&local_38,*(OLECHAR **)(param_1 + 0x120));
      local_8._0_1_ = 5;
      local_74 = (**(code **)(*local_34 + 0x30))(local_34,local_38,&local_58);
      if (-1 < local_74) {
        piVar4 = (int *)(param_1 + 0x38);
        if (*piVar4 != 0) {
          piVar1 = (int *)*piVar4;
          if (piVar1 != (int *)0x0) {
            *piVar4 = 0;
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          piVar1 = (int *)*piVar4;
          if ((piVar1 != (int *)0x0) && (*piVar4 = 0, piVar1 != (int *)0x0)) {
            (**(code **)(*piVar1 + 8))(piVar1);
          }
        }
        (*(code *)**(undefined4 **)local_58.n1._8_4_)(local_58.n1._8_4_,&DAT_45447e4c,piVar4);
        SysFreeString(local_38);
        VariantClear(&local_58);
        local_8._0_1_ = 2;
        if (local_34 != (int *)0x0) {
          (**(code **)(*local_34 + 8))(local_34);
        }
        VariantClear(&local_68);
        goto LAB_454206b7;
      }
      local_70 = 0;
      pppuVar3 = &local_78;
      local_6c = 0;
      local_78 = _com_error::vftable;
    }
                    /* WARNING: Subroutine does not return */
    FUN_4542a8e0((int *)pppuVar3,&DAT_4545636c);
  }
LAB_454206b7:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_30,true,0);
  FUN_4542a966();
  return;
}


