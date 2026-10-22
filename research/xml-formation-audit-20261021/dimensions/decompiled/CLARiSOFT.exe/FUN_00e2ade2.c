// Source: CLARiSOFT.exe @ 00e2ade2; FUN_00e2ade2

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_00e2ade2(int param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  BSTR extraout_ECX_02;
  BSTR extraout_ECX_03;
  BSTR extraout_ECX_04;
  BSTR extraout_ECX_05;
  BSTR extraout_ECX_06;
  BSTR extraout_ECX_07;
  int *piVar7;
  code *pcVar8;
  LPCWSTR *ppWVar9;
  BSTR pOVar10;
  int *piVar11;
  BSTR pOVar12;
  int **ppiVar13;
  _union_2683 local_f8;
  int local_e8;
  _union_2683 local_e4;
  _union_2683 local_d4;
  int *local_c4;
  int *local_c0;
  undefined4 local_bc;
  int local_b8;
  int local_b4;
  int *local_b0;
  int *local_ac;
  uint local_a8;
  undefined1 *local_a4;
  BSTR local_a0;
  int *local_9c;
  BSTR local_98;
  BSTR local_94;
  int local_90;
  uint local_8c;
  LPCWSTR local_88;
  undefined1 *local_84;
  int *local_80;
  int *local_7c;
  int *local_78;
  LPCWSTR local_74;
  int *local_70;
  BSTR local_6c;
  char local_65;
  undefined1 local_64 [8];
  int local_5c [21];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xe8;
  local_8 = 0xe2adf1;
  local_b8 = param_1;
  local_80 = (int *)FUN_00eca369(0xc);
  local_8 = 0;
  if (local_80 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_00e1acb2(local_80);
  }
  local_8 = 0xffffffff;
  if ((piVar3 == (int *)0x0) || (*(int *)(param_1 + 0x19c) == 0)) goto LAB_00e2b529;
  local_6c = (BSTR)0x0;
  local_8 = 1;
  iVar4 = (**(code **)(**(int **)(param_1 + 0x19c) + 0x44))();
  local_c4 = (int *)0x0;
  local_c0 = (int *)0x0;
  local_bc = 0;
  local_8._0_1_ = 2;
  if (iVar4 == 0) {
    ppiVar13 = &local_c4;
    pOVar12 = (BSTR)0x0;
    FUN_00e03ab8(&stack0xfffffee8,(int *)&local_6c);
    FUN_00e1c79c(piVar3,pOVar12,ppiVar13);
  }
  FUN_00e03b51((uint *)&local_f8);
  local_8._0_1_ = 3;
  iVar4 = (**(code **)(**(int **)(param_1 + 0x19c) + 0x80))();
  pcVar8 = VariantClear_exref;
  if ((-1 < iVar4) && (local_f8.n2.vt == 9)) {
    CComQIPtr<>(&local_b0,(undefined4 *)local_f8._8_4_);
    if (local_b0 != (int *)0x0) {
      FUN_00e03b51((uint *)&local_d4);
      local_8._0_1_ = 5;
      iVar4 = (**(code **)(*local_b0 + 0x4c))();
      if ((-1 < iVar4) && (local_d4.n2.vt == 9)) {
        local_7c = (int *)0x0;
        local_8._0_1_ = 6;
        iVar4 = (*(code *)**(undefined4 **)local_d4._8_4_)(local_d4._8_4_);
        if ((-1 < iVar4) && (local_7c != (int *)0x0)) {
          local_b4 = 0;
          iVar4 = (**(code **)(*local_7c + 0x1c))();
          if ((-1 < iVar4) && (0 < local_b4)) {
            local_9c = (int *)0x0;
            local_8._0_1_ = 7;
            puVar5 = (undefined1 *)(**(code **)(*local_7c + 0x20))();
            CComQIPtr<>(&local_78,local_9c);
            local_70 = (int *)0x0;
            local_8._0_1_ = 9;
            if ((-1 < (int)puVar5) && (local_78 != (int *)0x0)) {
              FUN_00ecd355(local_64,0x10,5,FUN_00e03b51);
              local_8c = 5;
              local_8 = CONCAT31(local_8._1_3_,10);
              (**(code **)(*local_78 + 0x14))();
              do {
                if ((local_8c != 5) || ((int)puVar5 < 0)) goto LAB_00e2b35b;
                puVar5 = (undefined1 *)(**(code **)(*local_78 + 0xc))(local_78,5);
                local_a8 = 0;
                if (local_8c != 0) {
                  local_ac = local_5c;
                  do {
                    if ((int)puVar5 < 0) break;
                    local_80 = local_ac + -2;
                    if (((short)*local_80 == 9) &&
                       (puVar6 = (undefined4 *)*local_ac, puVar6 != (undefined4 *)0x0)) {
                      puVar5 = (undefined1 *)(**(code **)*puVar6)(puVar6);
                    }
                    if ((int)puVar5 < 0) {
LAB_00e2b31a:
                      piVar7 = local_70;
                      if (local_70 != (int *)0x0) {
                        local_70 = (int *)0x0;
                        (**(code **)(*piVar7 + 8))();
                      }
                    }
                    else if (local_70 != (int *)0x0) {
                      FUN_00e03b51((uint *)&local_e4);
                      local_e4._8_4_ = (OLECHAR *)0x0;
                      local_e4.n2.vt = 8;
                      local_8._0_1_ = 0xb;
                      puVar5 = (undefined1 *)(**(code **)(*local_70 + 0x34))();
                      local_84 = puVar5;
                      FUN_00e03b21(&local_94,(OLECHAR *)local_e4._8_4_);
                      local_8 = CONCAT31(local_8._1_3_,0xc);
                      bVar1 = FUN_00e03edc(&local_94,L"Claricom");
                      if ((!bVar1) && (bVar1 = FUN_00e03edc(&local_94,L"Local"), !bVar1)) {
                        piVar7 = local_c4;
                        local_65 = bVar1;
                        if (local_c4 == local_c0) {
LAB_00e2b284:
                          FUN_00e03b21(&local_a0,(OLECHAR *)local_e4._8_4_);
                          local_a4 = &stack0xfffffedc;
                          local_8._0_1_ = 0x11;
                          pOVar10 = extraout_ECX_02;
                          FUN_00e03ab8(&stack0xfffffedc,(int *)&local_a0);
                          local_8._0_1_ = 0x12;
                          pOVar12 = extraout_ECX_03;
                          FUN_00e03ab8(&stack0xfffffed8,(int *)&local_6c);
                          local_8 = CONCAT31(local_8._1_3_,0x11);
                          FUN_00e1b8fb(piVar3,pOVar12,pOVar10);
                          puVar5 = (undefined1 *)
                                   FUN_00e1adbc(piVar3,(int *)&local_6c,(int *)&local_a0,
                                                (int *)&local_70);
                          if (-1 < (int)puVar5) {
                            FUN_00e1ca59(piVar3);
                          }
                          SysFreeString(local_a0);
                        }
                        else {
                          do {
                            if (local_65 != '\0') goto LAB_00e2b2f8;
                            FUN_00e03ab8(&local_74,piVar7);
                            local_8._0_1_ = 0xd;
                            bVar1 = FUN_00e03edc(&local_74,(OLECHAR *)local_e4._8_4_);
                            if (bVar1) {
                              local_65 = '\x01';
                              cVar2 = FUN_00e1bd2e(piVar3,(int *)&local_6c,(int *)&local_74,
                                                   (int *)&local_70);
                              if (cVar2 == '\0') {
                                FUN_00e03bc2(&local_88,local_74);
                                local_8._0_1_ = 0xe;
                                puVar6 = FUN_00eb9380(&local_e8,0x711b);
                                local_8._0_1_ = 0xf;
                                FUN_00e06fd2(&local_88,(LPCWSTR)*puVar6);
                                local_8._0_1_ = 0xe;
                                FUN_00e01f81(&local_e8);
                                FUN_00e191ef(&local_88,(undefined1 (*) [16])&DAT_00efdf58,L"\n");
                                puVar6 = FUN_00eb9380(&local_90,0x7108);
                                iVar4 = MessageBoxW((HWND)0x0,local_88,(LPCWSTR)*puVar6,0x34);
                                FUN_00e01f81(&local_90);
                                puVar5 = local_84;
                                if (iVar4 == 6) {
                                  ppWVar9 = &local_74;
                                  pOVar12 = extraout_ECX;
                                  FUN_00e03ab8(&stack0xfffffed8,(int *)&local_6c);
                                  FUN_00e1c3cd(piVar3,pOVar12,(int *)ppWVar9);
                                  local_84 = &stack0xfffffedc;
                                  pOVar10 = extraout_ECX_00;
                                  FUN_00e03ab8(&stack0xfffffedc,(int *)&local_74);
                                  local_8._0_1_ = 0x10;
                                  pOVar12 = extraout_ECX_01;
                                  FUN_00e03ab8(&stack0xfffffed8,(int *)&local_6c);
                                  local_8._0_1_ = 0xe;
                                  FUN_00e1b8fb(piVar3,pOVar12,pOVar10);
                                  puVar5 = (undefined1 *)
                                           FUN_00e1adbc(piVar3,(int *)&local_6c,(int *)&local_74,
                                                        (int *)&local_70);
                                  local_84 = puVar5;
                                  if (-1 < (int)puVar5) {
                                    FUN_00e1ca59(piVar3);
                                  }
                                }
                                FUN_00e01f81((int *)&local_88);
                              }
                            }
                            local_8 = CONCAT31(local_8._1_3_,0xc);
                            SysFreeString(local_74);
                            piVar7 = piVar7 + 1;
                          } while (piVar7 != local_c0);
                          if (local_65 == '\0') goto LAB_00e2b284;
                        }
LAB_00e2b2f8:
                        SysFreeString(local_94);
                        pcVar8 = VariantClear_exref;
                        local_8 = CONCAT31(local_8._1_3_,10);
                        VariantClear((VARIANTARG *)&local_e4.n2);
                        goto LAB_00e2b31a;
                      }
                      piVar7 = local_70;
                      if (local_70 != (int *)0x0) {
                        local_70 = (int *)0x0;
                        (**(code **)(*piVar7 + 8))();
                      }
                      SysFreeString(local_94);
                      local_8 = CONCAT31(local_8._1_3_,10);
                      (*pcVar8)();
                    }
                    local_a8 = local_a8 + 1;
                    local_ac = local_ac + 4;
                    (*pcVar8)();
                  } while (local_a8 < local_8c);
                }
              } while( true );
            }
            goto LAB_00e2b379;
          }
        }
        goto LAB_00e2b3af;
      }
      goto LAB_00e2b3c3;
    }
    goto LAB_00e2b3d2;
  }
LAB_00e2b3e0:
  puVar6 = FUN_00eb9400(&local_80,L"Default");
  local_8._0_1_ = 0x13;
  FUN_00e03b21(&local_98,(OLECHAR *)*puVar6);
  local_8._0_1_ = 0x15;
  FUN_00e01f81((int *)&local_80);
  cVar2 = FUN_00e1c9dd(piVar3,(BSTR)&local_6c,(CComBSTR *)&local_98);
  if (cVar2 == '\0') {
    local_a4 = &stack0xfffffee4;
    pOVar10 = extraout_ECX_04;
    FUN_00e03ab8(&stack0xfffffee4,(int *)&local_98);
    local_8._0_1_ = 0x16;
    pOVar12 = extraout_ECX_05;
    FUN_00e03ab8(&stack0xfffffee0,(int *)&local_6c);
    local_8._0_1_ = 0x15;
    FUN_00e1b8fb(piVar3,pOVar12,pOVar10);
    local_a4 = &stack0xfffffee4;
    pOVar10 = extraout_ECX_06;
    FUN_00e03ab8(&stack0xfffffee4,(int *)&local_98);
    local_8 = CONCAT31(local_8._1_3_,0x17);
    pOVar12 = extraout_ECX_07;
    FUN_00e03ab8(&stack0xfffffee0,(int *)&local_6c);
    piVar7 = *(int **)(param_1 + 0x160);
    piVar11 = piVar3;
    if (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 4))(piVar7);
    }
    local_8._0_1_ = 0x15;
    FUN_00e13b8b(piVar7,piVar11,pOVar12,pOVar10);
    FUN_00e1ca59(piVar3);
  }
  FUN_00e6def7(piVar3);
  FID_conflict__free(piVar3);
  piVar3 = *(int **)(param_1 + 0x1a8);
  local_d4._8_4_ = *(undefined4 *)(param_1 + 0x19c);
  local_d4.n2.vt = 9;
  if ((int *)local_d4._8_4_ != (int *)0x0) {
    (**(code **)(*(int *)local_d4._8_4_ + 4))();
  }
  local_8 = CONCAT31(local_8._1_3_,0x18);
  (**(code **)(*piVar3 + 200))();
  VariantClear((VARIANTARG *)&local_d4.n2);
  SysFreeString(local_98);
  VariantClear((VARIANTARG *)&local_f8.n2);
  FUN_00e066bc((int *)&local_c4);
  SysFreeString(local_6c);
LAB_00e2b529:
  FUN_00ec9e3c();
  return;
LAB_00e2b35b:
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 9;
  _eh_vector_destructor_iterator_(local_64,0x10,5,FUN_00e03dea);
LAB_00e2b379:
  local_8._0_1_ = 8;
  if (local_70 != (int *)0x0) {
    (**(code **)(*local_70 + 8))();
  }
  local_8._0_1_ = 7;
  if (local_78 != (int *)0x0) {
    (**(code **)(*local_78 + 8))();
  }
  local_8._0_1_ = 6;
  if (local_9c != (int *)0x0) {
    (**(code **)(*local_9c + 8))();
  }
LAB_00e2b3af:
  local_8._0_1_ = 5;
  param_1 = local_b8;
  if (local_7c != (int *)0x0) {
    (**(code **)(*local_7c + 8))();
    param_1 = local_b8;
  }
LAB_00e2b3c3:
  (*pcVar8)();
LAB_00e2b3d2:
  local_8._0_1_ = 3;
  if (local_b0 != (int *)0x0) {
    (**(code **)(*local_b0 + 8))();
  }
  goto LAB_00e2b3e0;
}


