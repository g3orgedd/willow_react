// Source: CLCiffConversion_Layout.dll @ 4541b11f; FUN_4541b11f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_4541b11f(char *param_1,char *param_2,char param_3)

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
  IUnknown *local_84;
  undefined **local_80 [4];
  undefined1 *local_70;
  OLECHAR *local_6c;
  int *local_68;
  int *local_64;
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
  FUN_454028b9(&local_8c,param_1);
  GetLocalTime(&local_44);
  _sprintf_s(local_34,0x1e,"%02d/%02d/%4d at %02d:%02d:%02d - ");
  HVar2 = CoInitialize((LPVOID)0x0);
  local_8._0_1_ = 2;
  FUN_454027ae(&local_60,(IID *)&DAT_45447724,(LPUNKNOWN)0x0,0x17);
  local_68 = (int *)&stack0xffffff54;
  local_8._0_1_ = 3;
  piVar8 = (int *)0x4541b1c0;
  piVar7 = extraout_ECX;
  FUN_45402bbb(&stack0xffffff54,local_8c);
  local_8._0_1_ = 4;
  if (local_60 != (int *)0x0) {
    local_8._0_1_ = 3;
    iVar3 = FUN_4540377d(local_60,piVar7);
    piVar7 = (int *)0xffffffff;
    if ((short)iVar3 == 0) {
      ppvVar9 = (void **)0xffffffff;
      local_68 = (int *)&stack0xffffff4c;
      piVar8 = (int *)0xffffffff;
      FUN_45402bbb(&stack0xffffff4c,local_8c);
      local_8._0_1_ = 5;
      if (local_60 == (int *)0x0) goto LAB_4541b1cb;
      local_8._0_1_ = 3;
      FUN_4540371c(local_60,&local_64,piVar8,ppvVar9);
      piVar7 = extraout_ECX_00;
      if (local_64 != (int *)0x0) {
        (**(code **)(*local_64 + 8))();
        piVar7 = extraout_ECX_01;
      }
    }
    local_68 = (int *)&stack0xffffff48;
    FUN_45402bbb(&stack0xffffff48,local_8c);
    local_8._0_1_ = 6;
    if (local_60 != (int *)0x0) {
      local_8 = CONCAT31(local_8._1_3_,3);
      puVar4 = FUN_45405f60(local_60,&local_90,piVar7);
      piVar7 = (int *)*puVar4;
      piVar10 = extraout_ECX_02;
      local_68 = piVar7;
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
        local_6c = (OLECHAR *)&stack0xffffff40;
        FUN_45402bbb(&stack0xffffff40,local_8c);
        local_8._0_1_ = 8;
        if (local_60 == (int *)0x0) goto LAB_4541b1cb;
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_4540371c(local_60,&local_64,piVar10,ppvVar9);
        piVar10 = extraout_ECX_05;
        if (local_64 != (int *)0x0) {
          (**(code **)(*local_64 + 8))();
          piVar10 = extraout_ECX_06;
        }
      }
      else {
        FUN_45429f70((uint *)local_80,0,0x10);
        VariantInit((VARIANTARG *)local_80);
        local_8._0_1_ = 9;
        (**(code **)(*piVar7 + 0x4c))();
        if ((local_80[0]._0_2_ == 3) && (0x400000 < (int)local_80[2])) {
          if (param_3 != '\0') {
            FUN_45413224(&local_64,&param_1,".1");
            local_8._0_1_ = 10;
            FUN_454028b9(&local_6c,(char *)local_64);
            bstrString = local_6c;
            local_88 = &stack0xffffff54;
            local_8._0_1_ = 0xb;
            piVar8 = (int *)0x4541b32d;
            FUN_45402bbb(&stack0xffffff54,local_6c);
            local_8._0_1_ = 0xc;
            if (local_60 == (int *)0x0) goto LAB_4541b1cb;
            local_8._0_1_ = 0xb;
            iVar3 = FUN_4540377d(local_60,piVar8);
            if ((short)iVar3 == -1) {
              iVar3 = -1;
              local_88 = &stack0xffffff50;
              FUN_45402bbb(&stack0xffffff50,bstrString);
              local_8._0_1_ = 0xd;
              if (local_60 == (int *)0x0) goto LAB_4541b1cb;
              local_8._0_1_ = 0xb;
              FUN_4541b771(local_60,(int *)0x4541b375,iVar3);
            }
            iVar3 = -1;
            local_88 = &stack0xffffff50;
            piVar10 = (int *)0xffffffff;
            FUN_45402bbb(&stack0xffffff50,bstrString);
            local_70 = &stack0xffffff4c;
            local_8._0_1_ = 0xe;
            piVar8 = extraout_ECX_07;
            FUN_45402bbb(&stack0xffffff4c,local_8c);
            local_8._0_1_ = 0xf;
            if (local_60 == (int *)0x0) goto LAB_4541b1cb;
            local_8._0_1_ = 0xb;
            FUN_4541b6ff(local_60,piVar8,piVar10,iVar3);
            SysFreeString(bstrString);
            local_8._0_1_ = 9;
            FUN_45402c5d((int *)&local_64);
          }
          FUN_45405c1c(piVar7,(IID *)0xffffffff);
          ppvVar9 = (void **)0xffffffff;
          local_70 = &stack0xffffff4c;
          piVar8 = extraout_ECX_08;
          FUN_45402bbb(&stack0xffffff4c,local_8c);
          local_8._0_1_ = 0x10;
          if (local_60 == (int *)0x0) goto LAB_4541b1cb;
          local_8._0_1_ = 9;
          FUN_4540371c(local_60,&local_6c,piVar8,ppvVar9);
          if (local_6c != (OLECHAR *)0x0) {
            (**(code **)(*(int *)local_6c + 8))();
          }
        }
        local_8 = CONCAT31(local_8._1_3_,7);
        VariantClear((VARIANTARG *)local_80);
        local_68 = (int *)0x0;
        piVar10 = extraout_ECX_09;
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 8))();
          piVar10 = extraout_ECX_10;
        }
      }
      local_70 = &stack0xffffff3c;
      FUN_45402bbb(&stack0xffffff3c,local_8c);
      local_8._0_1_ = 0x11;
      if (local_60 != (int *)0x0) {
        local_8._0_1_ = 7;
        FUN_45403f64(local_60,&local_84,piVar10);
        local_8._0_1_ = 0x12;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_5c,
                   local_34);
        local_8._0_1_ = 0x13;
        uVar5 = std::char_traits<char>::length(pcVar1);
        FUN_45404764(local_5c,pcVar1,uVar5);
        local_70 = &stack0xffffff48;
        pppCVar6 = local_5c;
        if (0xf < local_48) {
          pppCVar6 = (LPCSTR **)local_5c[0];
        }
        FUN_45402b71(&stack0xffffff48,(LPCSTR)pppCVar6);
        local_8._0_1_ = 0x14;
        if (local_84 != (IUnknown *)0x0) {
          local_8._0_1_ = 0x13;
          local_80[1] = (undefined **)FUN_454042e6(local_84,piVar8);
          if (-1 < (int)local_80[1]) {
            if (local_84 == (IUnknown *)0x0) goto LAB_4541b1cb;
            local_80[1] = (undefined **)FUN_45403562(local_84);
            if (-1 < (int)local_80[1]) {
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                        ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_5c
                         ,true,0);
              local_8._0_1_ = 7;
              if (local_84 != (IUnknown *)0x0) {
                (*local_84->lpVtbl->Release)(local_84);
              }
              local_8 = CONCAT31(local_8._1_3_,2);
              if (local_60 != (int *)0x0) {
                (**(code **)(*local_60 + 8))();
              }
              if (-1 < HVar2) {
                CoUninitialize();
              }
              SysFreeString(local_8c);
              FUN_45402c5d((int *)&param_1);
              FUN_4542a957();
              return;
            }
          }
          local_80[2] = (undefined **)0x0;
          local_80[3] = (undefined **)0x0;
          local_80[0] = _com_error::vftable;
                    /* WARNING: Subroutine does not return */
          FUN_4542a8e0((int *)local_80,&DAT_4545636c);
        }
      }
    }
  }
LAB_4541b1cb:
                    /* WARNING: Subroutine does not return */
  _com_issue_error(-0x7fffbffd);
}


