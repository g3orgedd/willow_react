// Source: CLCiffConversion_Data.dll @ 45013412; FUN_45013412

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_45013412(IID *param_1,IID *param_2,wchar_t *param_3)

{
  int iVar1;
  IUnknown *This;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  HRESULT HVar5;
  undefined ***pppuVar6;
  ULONG UVar7;
  IID *pIVar8;
  undefined1 auStack_e4 [16];
  IUnknown *local_d4;
  undefined **local_cc;
  ULONG local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined **local_bc;
  HRESULT local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined **local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined **local_9c;
  HRESULT local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined **local_8c;
  HRESULT local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined **local_7c;
  ULONG local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined **local_6c;
  HRESULT local_68;
  undefined4 local_64;
  undefined4 local_60;
  IID *local_5c;
  MULTI_QI local_58;
  int local_4c;
  IID local_48;
  uint local_34;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_30 [28];
  undefined1 *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc4;
  local_5c = param_1;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_30,"ADOConnection::SaveFileDbg");
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 != (wchar_t *)0x0) {
    sVar2 = _wcslen(param_3);
    iVar3 = sVar2 + 1;
    if (iVar3 < 0x40000000) {
      iVar1 = iVar3 * -2;
      local_14 = auStack_e4;
      *(undefined4 *)(&stack0xffffff18 + iVar1) = 3;
      *(int *)(&stack0xffffff14 + iVar1) = iVar3 * 2;
      *(wchar_t **)(&stack0xffffff10 + iVar1) = param_3;
      *(undefined1 **)(&stack0xffffff0c + iVar1) = auStack_e4;
      *(undefined4 *)(auStack_e4 + iVar1 + -0x14) = 0x45013470;
      pcVar4 = FUN_4500b2c8(*(LPSTR *)(&stack0xffffff0c + iVar1),
                            *(LPCWSTR *)(&stack0xffffff10 + iVar1),
                            *(int *)(&stack0xffffff14 + iVar1),*(UINT *)(&stack0xffffff18 + iVar1));
      goto LAB_45013470;
    }
  }
  pcVar4 = (char *)0x0;
LAB_45013470:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&local_48,pcVar4);
  local_8._0_1_ = 3;
  pIVar8 = (IID *)0x1;
  local_58.pIID = (IID *)&DAT_4503d9b0;
  local_58.pItf = (IUnknown *)0x0;
  local_58.hr = 0;
  HVar5 = CoCreateInstanceEx((IID *)&DAT_4503d9a0,(IUnknown *)0x0,0x15,(COSERVERINFO *)0x0,1,
                             &local_58);
  This = local_58.pItf;
  if (HVar5 < 0) {
    pppuVar6 = &local_bc;
    local_bc = _com_error::vftable;
    local_b4 = 0;
    local_b0 = 0;
    param_2 = pIVar8;
    local_b8 = HVar5;
  }
  else if (local_58.hr < 0) {
    pppuVar6 = &local_6c;
    local_6c = _com_error::vftable;
    local_64 = 0;
    local_60 = 0;
    param_2 = pIVar8;
    local_68 = HVar5;
  }
  else {
    local_d4 = local_58.pItf;
    if (local_58.pItf != (IUnknown *)0x0) {
      (*(local_58.pItf)->lpVtbl->AddRef)(local_58.pItf);
    }
    local_8._0_1_ = 4;
    (*(local_58.pItf)->lpVtbl->Release)(local_58.pItf);
    pIVar8 = &local_48;
    if (0xf < local_34) {
      pIVar8 = (IID *)local_48.Data1;
    }
    HVar5 = (*This->lpVtbl[1].QueryInterface)(This,pIVar8,(void **)0x20);
    if (HVar5 < 0) {
      pppuVar6 = &local_9c;
      local_9c = _com_error::vftable;
      local_94 = 0;
      local_90 = 0;
      param_2 = pIVar8;
      local_98 = HVar5;
    }
    else {
      local_4c = 0;
      UVar7 = (*This->lpVtbl[1].Release)(This);
      if ((int)UVar7 < 0) {
        pppuVar6 = &local_cc;
        local_cc = _com_error::vftable;
        local_c4 = 0;
        local_c0 = 0;
        param_2 = (IID *)&DAT_4504c0c4;
        local_c8 = UVar7;
      }
      else if (local_4c == 0) {
        local_ac = _com_error::vftable;
        pppuVar6 = &local_ac;
        local_a8 = 0x8004e013;
        local_a4 = 0;
        local_a0 = 0;
        param_2 = (IID *)&DAT_4504c0c4;
      }
      else {
        pIVar8 = local_5c;
        UVar7 = (*This->lpVtbl[3].Release)(This);
        if ((int)UVar7 < 0) {
          pppuVar6 = &local_7c;
          local_7c = _com_error::vftable;
          local_74 = 0;
          local_70 = 0;
          local_78 = UVar7;
        }
        else {
          local_88 = (*This->lpVtbl[3].QueryInterface)(This,pIVar8,(void **)param_2);
          if (-1 < local_88) {
            local_8 = CONCAT31(local_8._1_3_,3);
            (*This->lpVtbl->Release)(This);
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                      ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&local_48,
                       true,0);
            std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                      (local_30,true,0);
            SysFreeString(param_3);
            FUN_450136a7();
            return;
          }
          local_8c = _com_error::vftable;
          pppuVar6 = &local_8c;
          local_84 = 0;
          local_80 = 0;
          param_2 = (IID *)&DAT_4504c0c4;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_45022e41((int *)pppuVar6,(byte *)param_2);
}


