// Source: CLARiSOFT.exe @ 00e0429d; FUN_00e0429d

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_00e0429d(int param_1)

{
  LPCWSTR pWVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  LPCSTR ***ppppCVar6;
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
  OLECHAR *local_10b0;
  undefined1 *local_10ac;
  int *local_10a8;
  IUnknown *local_10a4;
  HRESULT local_10a0;
  int *local_109c;
  OLECHAR *local_1098;
  int *local_1094;
  _union_2683 local_1090;
  LPCSTR **local_1080 [5];
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
  
  puStack_c = &LAB_00ee6ad6;
  local_10 = ExceptionList;
  uStack_10e4 = DAT_00f385b8 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_10e4;
  ExceptionList = &local_10;
  local_8 = 1;
  uStack_7 = 0;
  local_18 = uStack_10e4;
  GetLocalTime(&local_1068);
  _sprintf_s(local_38,0x1e,"%02d/%02d/%4d at %02d:%02d:%02d - ");
  FUN_00ecd0d1(local_1058,0x1000,0xfff,param_1,&stack0x00000008);
  pWVar1 = (LPCWSTR)FUN_00eb82a0();
  FUN_00e03bc2(&local_10b0,pWVar1);
  local_8 = 2;
  FUN_00e03b6d(&local_10a4,"claricomsystem.log");
  local_8 = 3;
  FUN_00e04ebd(&local_10b0,(int)local_10a4[-2].lpVtbl,local_10a4);
  local_8 = 2;
  FUN_00e01f81((int *)&local_10a4);
  FUN_00e03b21(&local_1098,local_10b0);
  HVar2 = CoInitialize((LPVOID)0x0);
  local_8 = 5;
  local_10a0 = HVar2;
  FUN_00e029ff(&local_1094,(IID *)&DAT_00efcbd8,(LPUNKNOWN)0x0,0x17);
  local_10a8 = (int *)&stack0xffffef18;
  local_8 = 6;
  piVar10 = (int *)0xe043e7;
  piVar8 = extraout_ECX;
  FUN_00e03ccf(&stack0xffffef18,local_1098);
  local_8 = 7;
  if (local_1094 != (int *)0x0) {
    local_8 = 6;
    iVar3 = FUN_00e05090(local_1094,piVar8);
    piVar8 = extraout_ECX_00;
    if ((short)iVar3 == 0) {
      ppvVar11 = (void **)0xffffffff;
      local_10a8 = (int *)&stack0xffffef10;
      piVar10 = extraout_ECX_00;
      FUN_00e03ccf(&stack0xffffef10,local_1098);
      local_8 = 8;
      if (local_1094 == (int *)0x0) goto LAB_00e043f5;
      local_8 = 6;
      FUN_00e05005(local_1094,&local_109c,piVar10,ppvVar11);
      piVar8 = extraout_ECX_01;
      if (local_109c != (int *)0x0) {
        (**(code **)(*local_109c + 8))();
        piVar8 = extraout_ECX_02;
      }
    }
    local_10a8 = (int *)&stack0xffffef0c;
    FUN_00e03ccf(&stack0xffffef0c,local_1098);
    local_8 = 9;
    if (local_1094 != (int *)0x0) {
      _local_8 = CONCAT31(uStack_7,6);
      puVar4 = FUN_00e05810(local_1094,&local_109c,piVar8);
      piVar8 = (int *)*puVar4;
      piVar9 = extraout_ECX_03;
      local_10a8 = piVar8;
      if (piVar8 != (int *)0x0) {
        (**(code **)(*piVar8 + 4))();
        piVar9 = extraout_ECX_04;
      }
      local_8 = 10;
      if (local_109c != (int *)0x0) {
        (**(code **)(*local_109c + 8))();
        piVar9 = extraout_ECX_05;
      }
      if (piVar8 == (int *)0x0) {
        ppvVar11 = (void **)0xffffffff;
        local_10ac = &stack0xffffef04;
        FUN_00e03ccf(&stack0xffffef04,local_1098);
        local_8 = 0xb;
        if (local_1094 == (int *)0x0) goto LAB_00e043f5;
        _local_8 = CONCAT31(uStack_7,10);
        FUN_00e05005(local_1094,&local_10b4,piVar9,ppvVar11);
        piVar9 = extraout_ECX_06;
        if (local_10b4 != (int *)0x0) {
          (**(code **)(*local_10b4 + 8))();
          piVar9 = extraout_ECX_07;
        }
      }
      else {
        FUN_00e03b51((uint *)&local_1090);
        local_8 = 0xc;
        (**(code **)(*piVar8 + 0x4c))();
        if ((local_1090.n2.vt == 3) && (0x400000 < (int)local_1090._8_4_)) {
          FUN_00e05066(piVar8,(IID *)0xffffffff);
          ppvVar11 = (void **)0xffffffff;
          local_10ac = &stack0xffffef10;
          piVar10 = extraout_ECX_08;
          FUN_00e03ccf(&stack0xffffef10,local_1098);
          local_8 = 0xd;
          if (local_1094 == (int *)0x0) goto LAB_00e043f5;
          local_8 = 0xc;
          FUN_00e05005(local_1094,&local_10b4,piVar10,ppvVar11);
          if (local_10b4 != (int *)0x0) {
            (**(code **)(*local_10b4 + 8))();
          }
        }
        _local_8 = CONCAT31(uStack_7,10);
        VariantClear((VARIANTARG *)&local_1090.n2);
        local_10a8 = (int *)0x0;
        piVar9 = extraout_ECX_09;
        if (piVar8 != (int *)0x0) {
          (**(code **)(*piVar8 + 8))();
          piVar9 = extraout_ECX_10;
        }
      }
      local_10ac = &stack0xffffef00;
      FUN_00e03ccf(&stack0xffffef00,local_1098);
      local_8 = 0xe;
      if (local_1094 != (int *)0x0) {
        local_8 = 10;
        FUN_00e05ebf(local_1094,&local_10a4,piVar9);
        local_8 = 0xf;
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
        basic_string<char,std::char_traits<char>,std::allocator<char>_>
                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_1080,
                   local_38);
        local_8 = 0x10;
        if (local_1058[0] == '\0') {
          uVar5 = 0;
        }
        else {
          uVar5 = _strlen(local_1058);
        }
        FUN_00e067fa(local_1080,local_1058,uVar5);
        local_10ac = &stack0xffffef0c;
        ppppCVar6 = local_1080;
        if (0xf < local_106c) {
          ppppCVar6 = (LPCSTR ***)local_1080[0];
        }
        FUN_00e03c85(&stack0xffffef0c,(LPCSTR)ppppCVar6);
        local_8 = 0x11;
        if (local_10a4 != (IUnknown *)0x0) {
          local_8 = 0x10;
          iVar3 = FUN_00e061dd(local_10a4,piVar10);
          if (iVar3 < 0) {
            pppuVar7 = &local_10c4;
            local_10c4 = _com_error::vftable;
            local_10bc = 0;
            local_10b8 = 0;
            local_10c0 = iVar3;
          }
          else {
            if (local_10a4 == (IUnknown *)0x0) goto LAB_00e043f5;
            local_10d0 = FUN_00e04e23(local_10a4);
            if (-1 < (int)local_10d0) {
              std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                        ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                         local_1080,true,0);
              local_8 = 10;
              if (local_10a4 != (IUnknown *)0x0) {
                (*local_10a4->lpVtbl->Release)(local_10a4);
              }
              _local_8 = CONCAT31(uStack_7,5);
              if (local_1094 != (int *)0x0) {
                (**(code **)(*local_1094 + 8))();
              }
              if (-1 < HVar2) {
                CoUninitialize();
              }
              SysFreeString(local_1098);
              FUN_00e01f81((int *)&local_10b0);
              ExceptionList = local_10;
              uStack_10e4 = 0xe04744;
              FUN_00ec9db6(local_18 ^ (uint)&stack0xfffffffc);
              return;
            }
            pppuVar7 = &local_10d4;
            local_10d4 = _com_error::vftable;
            local_10cc = 0;
            local_10c8 = 0;
          }
                    /* WARNING: Subroutine does not return */
          FUN_00ec9dc5((int *)pppuVar7,&DAT_00f1c640);
        }
      }
    }
  }
LAB_00e043f5:
                    /* WARNING: Subroutine does not return */
  _com_issue_error(-0x7fffbffd);
}


