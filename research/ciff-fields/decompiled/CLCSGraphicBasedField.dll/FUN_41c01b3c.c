// Source: CLCSGraphicBasedField.dll @ 41c01b3c; FUN_41c01b3c

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_41c01b3c(int param_1)

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
  int *piVar8;
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
  int *extraout_ECX_11;
  int *piVar9;
  int *extraout_ECX_12;
  void **ppvVar10;
  int *piVar11;
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
  
  puStack_c = &LAB_41c2dc49;
  local_10 = ExceptionList;
  uStack_10e4 = DAT_41c3f5d0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_10e4;
  ExceptionList = &local_10;
  local_8 = 1;
  uStack_7 = 0;
  local_18 = uStack_10e4;
  GetLocalTime(&local_1068);
  _sprintf_s(local_38,0x1e,"%02d/%02d/%4d at %02d:%02d:%02d - ",(uint)local_1068.wDay,
             (uint)local_1068.wMonth);
  FUN_41c19df8(local_1058,0x1000,0xfff,param_1,&stack0x00000008);
  pWVar1 = (LPCWSTR)FUN_41c11dee();
  FUN_41c0146c(&local_10b0,pWVar1);
  local_8 = 2;
  FUN_41c01417(&local_10a4,"claricomsystem.log");
  local_8 = 3;
  FUN_41c028ec(&local_10b0,(int)local_10a4[-2].lpVtbl,local_10a4);
  local_8 = 2;
  FUN_41c01627((int *)&local_10a4);
  FUN_41c013b1(&local_1098,local_10b0);
  HVar2 = CoInitialize((LPVOID)0x0);
  local_8 = 5;
  local_10a0 = HVar2;
  FUN_41c012f5(&local_1094,(IID *)&DAT_41c306ac,(LPUNKNOWN)0x0,0x17);
  local_10a8 = (int *)&stack0xffffef18;
  local_8 = 6;
  piVar11 = extraout_ECX;
  FUN_41c0156f(&stack0xffffef18,local_1098);
  local_8 = 7;
  piVar8 = local_1094;
  if (local_1094 != (int *)0x0) goto LAB_41c01c9e;
LAB_41c01c94:
  do {
    _com_issue_error(-0x7fffbffd);
    piVar8 = extraout_ECX_00;
LAB_41c01c9e:
    local_8 = 6;
    iVar3 = FUN_41c02aff(piVar8,piVar11);
    piVar11 = extraout_ECX_01;
    if ((short)iVar3 == 0) {
      piVar11 = (int *)0x0;
      ppvVar10 = (void **)0xffffffff;
      local_10a8 = (int *)&stack0xffffef10;
      piVar8 = extraout_ECX_01;
      FUN_41c0156f(&stack0xffffef10,local_1098);
      local_8 = 8;
      if (local_1094 == (int *)0x0) goto LAB_41c01c94;
      local_8 = 6;
      FUN_41c02a74(local_1094,&local_109c,piVar8,ppvVar10);
      piVar11 = extraout_ECX_02;
      if (local_109c != (int *)0x0) {
        (**(code **)(*local_109c + 8))();
        piVar11 = extraout_ECX_03;
      }
    }
    local_10a8 = (int *)&stack0xffffef18;
    FUN_41c0156f(&stack0xffffef18,local_1098);
    local_8 = 9;
  } while (local_1094 == (int *)0x0);
  _local_8 = CONCAT31(uStack_7,6);
  puVar4 = FUN_41c03240(local_1094,&local_109c,piVar11);
  piVar8 = (int *)*puVar4;
  piVar9 = extraout_ECX_04;
  local_10a8 = piVar8;
  if (piVar8 != (int *)0x0) {
    (**(code **)(*piVar8 + 4))();
    piVar9 = extraout_ECX_05;
  }
  local_8 = 10;
  if (local_109c != (int *)0x0) {
    (**(code **)(*local_109c + 8))();
    piVar9 = extraout_ECX_06;
  }
  if (piVar8 == (int *)0x0) {
    piVar11 = (int *)0x0;
    ppvVar10 = (void **)0xffffffff;
    local_10ac = &stack0xffffef10;
    FUN_41c0156f(&stack0xffffef10,local_1098);
    local_8 = 0xb;
    if (local_1094 == (int *)0x0) goto LAB_41c01c94;
    _local_8 = CONCAT31(uStack_7,10);
    FUN_41c02a74(local_1094,&local_10b4,piVar9,ppvVar10);
    piVar9 = extraout_ECX_07;
    if (local_10b4 != (int *)0x0) {
      (**(code **)(*local_10b4 + 8))();
      piVar9 = extraout_ECX_08;
    }
  }
  else {
    FUN_41c18d70((uint *)&local_1090,0,0x10);
    VariantInit((VARIANTARG *)&local_1090.n2);
    local_8 = 0xc;
    (**(code **)(*piVar8 + 0x4c))();
    if ((local_1090.n2.vt == 3) && (0x400000 < (int)local_1090._8_4_)) {
      FUN_41c02ad5(piVar8,(IID *)0xffffffff);
      piVar11 = (int *)0x0;
      ppvVar10 = (void **)0xffffffff;
      local_10ac = &stack0xffffef10;
      piVar9 = extraout_ECX_09;
      FUN_41c0156f(&stack0xffffef10,local_1098);
      local_8 = 0xd;
      if (local_1094 == (int *)0x0) goto LAB_41c01c94;
      local_8 = 0xc;
      FUN_41c02a74(local_1094,&local_10b4,piVar9,ppvVar10);
      if (local_10b4 != (int *)0x0) {
        (**(code **)(*local_10b4 + 8))();
      }
    }
    _local_8 = CONCAT31(uStack_7,10);
    VariantClear((VARIANTARG *)&local_1090.n2);
    local_10a8 = (int *)0x0;
    piVar9 = extraout_ECX_10;
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 8))();
      piVar9 = extraout_ECX_11;
    }
  }
  piVar11 = (int *)0x0;
  local_10ac = &stack0xffffef0c;
  FUN_41c0156f(&stack0xffffef0c,local_1098);
  local_8 = 0xe;
  if (local_1094 != (int *)0x0) {
    local_8 = 10;
    FUN_41c0340b(local_1094,&local_10a4,piVar9);
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
    FUN_41c03a49(local_1080,local_1058,uVar5);
    local_10ac = &stack0xffffef18;
    ppppCVar6 = local_1080;
    if (0xf < local_106c) {
      ppppCVar6 = (LPCSTR ***)local_1080[0];
    }
    piVar11 = extraout_ECX_12;
    FUN_41c01525(&stack0xffffef18,(LPCSTR)ppppCVar6);
    local_8 = 0x11;
    if (local_10a4 != (IUnknown *)0x0) {
      local_8 = 0x10;
      iVar3 = FUN_41c0351b(local_10a4,piVar11);
      if (iVar3 < 0) {
        pppuVar7 = &local_10c4;
        local_10c4 = _com_error::vftable;
        local_10bc = 0;
        local_10b8 = 0;
        local_10c0 = iVar3;
        goto LAB_41c01f42;
      }
      if (local_10a4 != (IUnknown *)0x0) {
        local_10d0 = FUN_41c0281c(local_10a4);
        if (-1 < (int)local_10d0) {
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_1080,
                     true,0);
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
          FUN_41c01627((int *)&local_10b0);
          ExceptionList = local_10;
          FUN_41c19fdc(local_18 ^ (uint)&stack0xfffffffc);
          return;
        }
        pppuVar7 = &local_10d4;
        local_10d4 = _com_error::vftable;
        local_10cc = 0;
        local_10c8 = 0;
LAB_41c01f42:
                    /* WARNING: Subroutine does not return */
        FUN_41c19feb((int *)pppuVar7,&DAT_41c3a8ec);
      }
    }
  }
  goto LAB_41c01c94;
}


