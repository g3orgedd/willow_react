// Source: CLCiffConversion_Data.dll @ 45006df5; FUN_45006df5

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_45006df5(OLECHAR *param_1,char *param_2,char param_3)

{
  char *pcVar1;
  OLECHAR *bstrString;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  LPCSTR **pppCVar6;
  int *extraout_ECX;
  int *piVar7;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *extraout_ECX_08;
  int *extraout_ECX_09;
  int *extraout_ECX_10;
  int *piVar8;
  void **ppvVar9;
  int *piVar10;
  int *local_90;
  OLECHAR *local_8c;
  undefined1 *local_88;
  undefined **local_84 [4];
  IUnknown *local_74;
  undefined1 *local_70;
  int *local_6c;
  OLECHAR *local_68;
  OLECHAR *local_64;
  int *local_60;
  LPCSTR *local_5c [5];
  uint local_48;
  _SYSTEMTIME local_44;
  char local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pcVar1 = param_2;
  uStack_4 = 0x88;
  local_8 = 0;
  FUN_45001f5d(&local_8c,param_1);
  GetLocalTime(&local_44);
  _sprintf_s(local_34,0x1e,"%02d/%02d/%4d at %02d:%02d:%02d - ");
  HVar2 = CoInitialize((LPVOID)0x0);
  local_8._0_1_ = 2;
  FUN_45001e66(&local_60,(IID *)&DAT_4503d5b0,(LPUNKNOWN)0x0,0x17);
  local_6c = (int *)&stack0xffffff54;
  local_8._0_1_ = 3;
  piVar8 = (int *)0x45006e96;
  piVar7 = extraout_ECX;
  FUN_450021a8(&stack0xffffff54,local_8c);
  local_8._0_1_ = 4;
  if (local_60 != (int *)0x0) {
    local_8._0_1_ = 3;
    iVar3 = FUN_45003795(local_60,piVar7);
    piVar7 = (int *)0xffffffff;
    if ((short)iVar3 == 0) {
      ppvVar9 = (void **)0xffffffff;
      local_6c = (int *)&stack0xffffff4c;
      piVar8 = (int *)0xffffffff;
      FUN_450021a8(&stack0xffffff4c,local_8c);
      local_8._0_1_ = 5;
      if (local_60 == (int *)0x0) goto LAB_45006ea1;
      local_8._0_1_ = 3;
      FUN_4500370a(local_60,&local_64,piVar8,ppvVar9);
      piVar7 = extraout_ECX_00;
      if (local_64 != (OLECHAR *)0x0) {
        (**(code **)(*(int *)local_64 + 8))();
        piVar7 = extraout_ECX_01;
      }
    }
    local_6c = (int *)&stack0xffffff48;
    FUN_450021a8(&stack0xffffff48,local_8c);
    local_8._0_1_ = 6;
    if (local_60 != (int *)0x0) {
      local_8 = CONCAT31(local_8._1_3_,3);
      puVar4 = FUN_45003ce6(local_60,&local_90,piVar7);
      piVar7 = (int *)*puVar4;
      piVar10 = extraout_ECX_02;
      local_6c = piVar7;
      if (piVar7 != (int *)0x0) {
        (**(code **)(*piVar7 + 4))();
        piVar10 = extraout_ECX_03;
      }
      local_8._0_1_ = 7;
      if (local_90 != (int *)0x0) {
        (**(code **)(*local_90 + 8))();
        piVar10 = extraout_ECX_04;
      }
      if (piVar7 == (int *)0x0) {
        ppvVar9 = (void **)0xffffffff;
        local_68 = (OLECHAR *)&stack0xffffff40;
        FUN_450021a8(&stack0xffffff40,local_8c);
        local_8._0_1_ = 8;
        if (local_60 == (int *)0x0) goto LAB_45006ea1;
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_4500370a(local_60,&local_64,piVar10,ppvVar9);
        piVar10 = extraout_ECX_05;
        if (local_64 != (OLECHAR *)0x0) {
          (**(code **)(*(int *)local_64 + 8))();
          piVar10 = extraout_ECX_06;
        }
      }
      else {
        FUN_45001f8d((uint *)local_84);
        local_8._0_1_ = 9;
        (**(code **)(*piVar7 + 0x4c))();
        if ((local_84[0]._0_2_ == 3) && (0x400000 < (int)local_84[2])) {
          if (param_3 != '\0') {
            FUN_45002050(&local_68,".1");
            local_8._0_1_ = 10;
            FUN_450059c5(&local_64,&param_1,&local_68);
            local_8._0_1_ = 0xc;
            FUN_45002256((int *)&local_68);
            FUN_45001f5d(&local_68,local_64);
            bstrString = local_68;
            local_88 = &stack0xffffff54;
            local_8._0_1_ = 0xd;
            piVar8 = (int *)0x45007009;
            FUN_450021a8(&stack0xffffff54,local_68);
            local_8._0_1_ = 0xe;
            if (local_60 == (int *)0x0) goto LAB_45006ea1;
            local_8._0_1_ = 0xd;
            iVar3 = FUN_45003795(local_60,piVar8);
            if ((short)iVar3 == -1) {
              iVar3 = -1;
              local_88 = &stack0xffffff50;
              FUN_450021a8(&stack0xffffff50,bstrString);
              local_8._0_1_ = 0xf;
              if (local_60 == (int *)0x0) goto LAB_45006ea1;
              local_8._0_1_ = 0xd;
              FUN_450072a5(local_60,(int *)0x45007051,iVar3);
            }
            iVar3 = -1;
            local_88 = &stack0xffffff50;
            piVar10 = (int *)0xffffffff;
            FUN_450021a8(&stack0xffffff50,bstrString);
            local_70 = &stack0xffffff4c;
            local_8._0_1_ = 0x10;
            piVar8 = extraout_ECX_07;
            FUN_450021a8(&stack0xffffff4c,local_8c);
            local_8._0_1_ = 0x11;
            if (local_60 == (int *)0x0) goto LAB_45006ea1;
            local_8._0_1_ = 0xd;
            FUN_45007233(local_60,piVar8,piVar10,iVar3);
            SysFreeString(bstrString);
            local_8._0_1_ = 9;
            FUN_45002256((int *)&local_64);
          }
          FUN_4500376b(piVar7,(IID *)0xffffffff);
          ppvVar9 = (void **)0xffffffff;
          local_70 = &stack0xffffff4c;
          piVar8 = extraout_ECX_08;
          FUN_450021a8(&stack0xffffff4c,local_8c);
          local_8._0_1_ = 0x12;
          if (local_60 == (int *)0x0) goto LAB_45006ea1;
          local_8._0_1_ = 9;
          FUN_4500370a(local_60,&local_64,piVar8,ppvVar9);
          if (local_64 != (OLECHAR *)0x0) {
            (**(code **)(*(int *)local_64 + 8))();
          }
        }
        local_8 = CONCAT31(local_8._1_3_,7);
        VariantClear((VARIANTARG *)local_84);
        local_6c = (int *)0x0;
        piVar10 = extraout_ECX_09;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 8))();
          piVar10 = extraout_ECX_10;
        }
      }
      local_70 = &stack0xffffff3c;
      FUN_450021a8(&stack0xffffff3c,local_8c);
      local_8._0_1_ = 0x13;
      if (local_60 != (int *)0x0) {
        local_8._0_1_ = 7;
        FUN_450040de(local_60,&local_74,piVar10);
        local_8._0_1_ = 0x14;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_5c,
                   local_34);
        local_8._0_1_ = 0x15;
        uVar5 = std::char_traits<char>::length(pcVar1);
        FUN_450047ff(local_5c,pcVar1,uVar5);
        local_70 = &stack0xffffff48;
        pppCVar6 = local_5c;
        if (0xf < local_48) {
          pppCVar6 = (LPCSTR **)local_5c[0];
        }
        FUN_4500215e(&stack0xffffff48,(LPCSTR)pppCVar6);
        local_8._0_1_ = 0x16;
        if (local_74 != (IUnknown *)0x0) {
          local_8._0_1_ = 0x15;
          local_84[1] = (undefined **)FUN_450042d1(local_74,piVar8);
          if (-1 < (int)local_84[1]) {
            if (local_74 == (IUnknown *)0x0) goto LAB_45006ea1;
            local_84[1] = (undefined **)FUN_450034d3(local_74);
            if (-1 < (int)local_84[1]) {
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                        ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_5c
                         ,true,0);
              local_8._0_1_ = 7;
              if (local_74 != (IUnknown *)0x0) {
                (*local_74->lpVtbl->Release)(local_74);
              }
              local_8 = CONCAT31(local_8._1_3_,2);
              if (local_60 != (int *)0x0) {
                (**(code **)(*local_60 + 8))();
              }
              if (-1 < HVar2) {
                CoUninitialize();
              }
              SysFreeString(local_8c);
              FUN_45002256((int *)&param_1);
              FUN_45022eb8();
              return;
            }
          }
          local_84[2] = (undefined **)0x0;
          local_84[3] = (undefined **)0x0;
          local_84[0] = _com_error::vftable;
                    /* WARNING: Subroutine does not return */
          FUN_45022e41((int *)local_84,&DAT_4504c0c4);
        }
      }
    }
  }
LAB_45006ea1:
                    /* WARNING: Subroutine does not return */
  _com_issue_error(-0x7fffbffd);
}


