// Source: CLCiffConversion_Layout.dll @ 4540500e; FUN_4540500e

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_4540500e(int param_1)

{
  LPCSTR pCVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  LPCSTR **pppCVar6;
  undefined ***pppuVar7;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *piVar8;
  int *extraout_ECX_03;
  int *extraout_ECX_04;
  int *extraout_ECX_05;
  int *extraout_ECX_06;
  int *extraout_ECX_07;
  int *extraout_ECX_08;
  int *extraout_ECX_09;
  int *extraout_ECX_10;
  int *piVar9;
  int *piVar10;
  void **ppvVar11;
  uint uStack_10e4;
  undefined **local_10d4;
  ULONG local_10d0;
  undefined4 local_10cc;
  undefined4 local_10c8;
  undefined **local_10c4;
  int local_10c0;
  undefined4 local_10bc;
  undefined4 local_10b8;
  int *local_10b4;
  char *local_10b0;
  undefined1 *local_10ac;
  IUnknown *local_10a8;
  int *local_10a4;
  HRESULT local_10a0;
  int *local_109c;
  OLECHAR *local_1098;
  int *local_1094;
  _union_2683 local_1090;
  LPCSTR *local_1080 [5];
  uint local_106c;
  _SYSTEMTIME local_1068;
  char local_1058 [4128];
  char local_38 [32];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_454423d8;
  local_10 = ExceptionList;
  uStack_10e4 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_10e4;
  ExceptionList = &local_10;
  local_8 = 1;
  uStack_7 = 0;
  local_18 = uStack_10e4;
  GetLocalTime(&local_1068);
  _sprintf_s(local_38,0x1e,"%02d/%02d/%4d at %02d:%02d:%02d - ");
  FUN_4542cca5(local_1058,0x1000,0xfff,param_1,&stack0x00000008);
  pCVar1 = (LPCSTR)FUN_45408666();
  FUN_45402a65(&local_10b0,pCVar1);
  local_8 = 2;
  FUN_45404db2(&local_10b0,"claricomsystem.log");
  FUN_454028b9(&local_1098,local_10b0);
  HVar2 = CoInitialize((LPVOID)0x0);
  local_8 = 4;
  local_10a0 = HVar2;
  FUN_454027ae(&local_1094,(IID *)&DAT_45447724,(LPUNKNOWN)0x0,0x17);
  local_10a4 = (int *)&stack0xffffef18;
  local_8 = 5;
  piVar10 = (int *)0x4540512e;
  piVar8 = extraout_ECX;
  FUN_45402bbb(&stack0xffffef18,local_1098);
  local_8 = 6;
  if (local_1094 != (int *)0x0) {
    local_8 = 5;
    iVar3 = FUN_4540377d(local_1094,piVar8);
    piVar8 = extraout_ECX_00;
    if ((short)iVar3 == 0) {
      ppvVar11 = (void **)0xffffffff;
      local_10a4 = (int *)&stack0xffffef10;
      piVar10 = extraout_ECX_00;
      FUN_45402bbb(&stack0xffffef10,local_1098);
      local_8 = 7;
      if (local_1094 == (int *)0x0) goto LAB_4540513c;
      local_8 = 5;
      FUN_4540371c(local_1094,&local_109c,piVar10,ppvVar11);
      piVar8 = extraout_ECX_01;
      if (local_109c != (int *)0x0) {
        (**(code **)(*local_109c + 8))();
        piVar8 = extraout_ECX_02;
      }
    }
    local_10a4 = (int *)&stack0xffffef0c;
    FUN_45402bbb(&stack0xffffef0c,local_1098);
    local_8 = 8;
    if (local_1094 != (int *)0x0) {
      _local_8 = CONCAT31(uStack_7,5);
      puVar4 = FUN_45405f60(local_1094,&local_109c,piVar8);
      piVar8 = (int *)*puVar4;
      piVar9 = extraout_ECX_03;
      local_10a4 = piVar8;
      if (piVar8 != (int *)0x0) {
        (**(code **)(*piVar8 + 4))();
        piVar9 = extraout_ECX_04;
      }
      local_8 = 9;
      if (local_109c != (int *)0x0) {
        (**(code **)(*local_109c + 8))();
        piVar9 = extraout_ECX_05;
      }
      if (piVar8 == (int *)0x0) {
        ppvVar11 = (void **)0xffffffff;
        local_10ac = &stack0xffffef04;
        FUN_45402bbb(&stack0xffffef04,local_1098);
        local_8 = 10;
        if (local_1094 == (int *)0x0) goto LAB_4540513c;
        _local_8 = CONCAT31(uStack_7,9);
        FUN_4540371c(local_1094,&local_10b4,piVar9,ppvVar11);
        piVar9 = extraout_ECX_06;
        if (local_10b4 != (int *)0x0) {
          (**(code **)(*local_10b4 + 8))();
          piVar9 = extraout_ECX_07;
        }
      }
      else {
        FUN_45429f70((uint *)&local_1090,0,0x10);
        VariantInit((VARIANTARG *)&local_1090.n2);
        local_8 = 0xb;
        (**(code **)(*piVar8 + 0x4c))();
        if ((local_1090.n2.vt == 3) && (0x400000 < (int)local_1090._8_4_)) {
          FUN_45405c1c(piVar8,(IID *)0xffffffff);
          ppvVar11 = (void **)0xffffffff;
          local_10ac = &stack0xffffef10;
          piVar10 = extraout_ECX_08;
          FUN_45402bbb(&stack0xffffef10,local_1098);
          local_8 = 0xc;
          if (local_1094 == (int *)0x0) goto LAB_4540513c;
          local_8 = 0xb;
          FUN_4540371c(local_1094,&local_10b4,piVar10,ppvVar11);
          if (local_10b4 != (int *)0x0) {
            (**(code **)(*local_10b4 + 8))();
          }
        }
        _local_8 = CONCAT31(uStack_7,9);
        VariantClear((VARIANTARG *)&local_1090.n2);
        local_10a4 = (int *)0x0;
        piVar9 = extraout_ECX_09;
        if (piVar8 != (int *)0x0) {
          (**(code **)(*piVar8 + 8))();
          piVar9 = extraout_ECX_10;
        }
      }
      local_10ac = &stack0xffffef00;
      FUN_45402bbb(&stack0xffffef00,local_1098);
      local_8 = 0xd;
      if (local_1094 != (int *)0x0) {
        local_8 = 9;
        FUN_45403f64(local_1094,&local_10a8,piVar9);
        local_8 = 0xe;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_1080,
                   local_38);
        local_8 = 0xf;
        if (local_1058[0] == '\0') {
          uVar5 = 0;
        }
        else {
          uVar5 = _strlen(local_1058);
        }
        FUN_45404764(local_1080,local_1058,uVar5);
        local_10ac = &stack0xffffef0c;
        pppCVar6 = local_1080;
        if (0xf < local_106c) {
          pppCVar6 = (LPCSTR **)local_1080[0];
        }
        FUN_45402b71(&stack0xffffef0c,(LPCSTR)pppCVar6);
        local_8 = 0x10;
        if (local_10a8 != (IUnknown *)0x0) {
          local_8 = 0xf;
          iVar3 = FUN_454042e6(local_10a8,piVar10);
          if (iVar3 < 0) {
            pppuVar7 = &local_10c4;
            local_10c4 = _com_error::vftable;
            local_10bc = 0;
            local_10b8 = 0;
            local_10c0 = iVar3;
          }
          else {
            if (local_10a8 == (IUnknown *)0x0) goto LAB_4540513c;
            local_10d0 = FUN_45403562(local_10a8);
            if (-1 < (int)local_10d0) {
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                        ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                         local_1080,true,0);
              local_8 = 9;
              if (local_10a8 != (IUnknown *)0x0) {
                (*local_10a8->lpVtbl->Release)(local_10a8);
              }
              _local_8 = CONCAT31(uStack_7,4);
              if (local_1094 != (int *)0x0) {
                (**(code **)(*local_1094 + 8))();
              }
              if (-1 < HVar2) {
                CoUninitialize();
              }
              SysFreeString(local_1098);
              FUN_45402c5d((int *)&local_10b0);
              ExceptionList = local_10;
              uStack_10e4 = 0x4540549d;
              FUN_4542a8d1(local_18 ^ (uint)&stack0xfffffffc);
              return;
            }
            pppuVar7 = &local_10d4;
            local_10d4 = _com_error::vftable;
            local_10cc = 0;
            local_10c8 = 0;
          }
                    /* WARNING: Subroutine does not return */
          FUN_4542a8e0((int *)pppuVar7,&DAT_4545636c);
        }
      }
    }
  }
LAB_4540513c:
                    /* WARNING: Subroutine does not return */
  _com_issue_error(-0x7fffbffd);
}


