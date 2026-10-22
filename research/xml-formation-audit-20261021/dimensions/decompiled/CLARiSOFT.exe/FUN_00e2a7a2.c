// Source: CLARiSOFT.exe @ 00e2a7a2; FUN_00e2a7a2

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_00e2a7a2(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  HRESULT HVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  VARIANTARG *pVVar8;
  BSTR bstrString;
  int local_108;
  BSTR local_104;
  int *local_100;
  BSTR local_fc;
  uint local_f8;
  int *local_f4;
  uint local_f0;
  int *local_ec;
  int *local_e8;
  undefined4 local_e4;
  uint local_e0;
  int *local_dc;
  uint local_d8;
  int *local_d4;
  int *local_d0;
  VARIANTARG *local_cc;
  VARIANTARG *local_c8;
  BSTR local_c4;
  int *local_c0;
  int *local_bc;
  int *local_b8;
  VARTYPE local_b4 [4];
  int local_ac [18];
  undefined1 local_64 [8];
  int local_5c [21];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xf8;
  local_8 = 0xe2a7b1;
  local_108 = 0;
  if (*(int *)(param_1 + 0x160) != 0) {
    (**(code **)(**(int **)(param_1 + 0x160) + 0x3fc))(*(int **)(param_1 + 0x160),&local_108);
  }
  local_ec = (int *)0x0;
  local_e8 = (int *)0x0;
  local_e4 = 0;
  local_8 = 0;
  FUN_00e1d1d3(&local_ec);
  local_100 = (int *)0x0;
  local_8._0_1_ = 1;
  iVar2 = (**(code **)(**(int **)(param_1 + 0x19c) + 0x20))(*(int **)(param_1 + 0x19c),&local_100);
  CComQIPtr<>(&local_dc,local_100);
  local_b8 = (int *)0x0;
  local_8._0_1_ = 3;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 3;
  if ((-1 < iVar2) && (uVar1 = (undefined1)local_8, local_dc != (int *)0x0)) {
    FUN_00ecd355(local_64,0x10,5,FUN_00e03b51);
    local_d8 = 5;
    local_8 = CONCAT31(local_8._1_3_,4);
    (**(code **)(*local_dc + 0x14))(local_dc);
joined_r0x00e2a882:
    do {
      if ((local_d8 != 5) || (iVar2 < 0)) goto LAB_00e2ac34;
      iVar2 = (**(code **)(*local_dc + 0xc))(local_dc,5,local_64,&local_d8);
      local_f8 = 0;
      if (local_d8 != 0) {
        piVar7 = local_5c;
        local_f4 = piVar7;
LAB_00e2a8c8:
        if (-1 < iVar2) {
          pVVar8 = (VARIANTARG *)(piVar7 + -2);
          local_cc = pVVar8;
          if (((pVVar8->n1).n2.vt == 9) &&
             (puVar4 = (undefined4 *)*piVar7, puVar4 != (undefined4 *)0x0)) {
            iVar2 = (**(code **)*puVar4)(puVar4,&DAT_00efcfe8,&local_b8);
          }
          if (iVar2 < 0) goto LAB_00e2abea;
          if (local_b8 != (int *)0x0) {
            local_d4 = (int *)0x0;
            local_8._0_1_ = 5;
            iVar2 = (**(code **)(*local_b8 + 0x20))(local_b8,&local_d4);
            CComQIPtr<>(&local_bc,local_d4);
            local_c0 = (int *)0x0;
            local_8._0_1_ = 7;
            if ((-1 < iVar2) && (local_bc != (int *)0x0)) {
              FUN_00ecd355(local_b4,0x10,5,FUN_00e03b51);
              local_e0 = 5;
              local_8 = CONCAT31(local_8._1_3_,8);
              (**(code **)(*local_bc + 0x14))(local_bc);
              do {
                if ((local_e0 != 5) || (piVar7 = local_f4, pVVar8 = local_cc, iVar2 < 0))
                goto LAB_00e2ab8f;
                (**(code **)(*local_bc + 0xc))(local_bc,5,local_b4,&local_e0);
                local_f0 = 0;
                pVVar8 = local_cc;
                piVar7 = local_f4;
                if (local_e0 != 0) {
                  piVar6 = local_ac;
                  do {
                    pVVar8 = local_cc;
                    piVar7 = local_f4;
                    if (iVar2 < 0) break;
                    pVVar8 = (VARIANTARG *)(piVar6 + -2);
                    local_c8 = pVVar8;
                    if (((pVVar8->n1).n2.vt == 9) &&
                       (puVar4 = (undefined4 *)*piVar6, puVar4 != (undefined4 *)0x0)) {
                      iVar2 = (**(code **)*puVar4)(puVar4,&DAT_00efd008,&local_c0);
                    }
                    if ((-1 < iVar2) && (local_c0 != (int *)0x0)) {
                      CComQIPtr<>(&local_d0,local_c0);
                      local_8 = CONCAT31(local_8._1_3_,9);
                      if (local_d0 != (int *)0x0) {
                        local_c4 = (BSTR)0x0;
                        local_8 = CONCAT31(local_8._1_3_,10);
                        iVar2 = (**(code **)(*local_d0 + 0x1c))(local_d0,&local_c4);
                        if ((iVar2 == 0) && (piVar7 = local_ec, local_c4 != (BSTR)0x0)) {
                          for (; piVar7 != local_e8; piVar7 = piVar7 + 1) {
                            FUN_00e03ab8(&local_fc,piVar7);
                            HVar3 = VarBstrCmp(local_fc,local_c4,0x400,0);
                            bstrString = local_fc;
                            if (HVar3 == 1) goto LAB_00e2ab09;
                            SysFreeString(local_fc);
                          }
                          if (local_108 <= (int)local_e8 - (int)local_ec >> 2) {
                            puVar4 = FUN_00eb9380(&local_c8,0x7108);
                            local_8._0_1_ = 0xb;
                            puVar5 = FUN_00eb9380(&local_cc,0x711e);
                            MessageBoxW((HWND)0x0,(LPCWSTR)*puVar5,(LPCWSTR)*puVar4,0);
                            FUN_00e01f81((int *)&local_cc);
                            FUN_00e01f81((int *)&local_c8);
                            SysFreeString(local_c4);
                            local_8._0_1_ = 8;
                            if (local_d0 != (int *)0x0) {
                              (**(code **)(*local_d0 + 8))(local_d0);
                            }
                            local_8._0_1_ = 7;
                            _eh_vector_destructor_iterator_(local_b4,0x10,5,FUN_00e03dea);
                            local_8._0_1_ = 6;
                            if (local_c0 != (int *)0x0) {
                              (**(code **)(*local_c0 + 8))(local_c0);
                            }
                            local_8._0_1_ = 5;
                            if (local_bc != (int *)0x0) {
                              (**(code **)(*local_bc + 8))(local_bc);
                            }
                            local_8._0_1_ = 4;
                            if (local_d4 != (int *)0x0) {
                              (**(code **)(*local_d4 + 8))(local_d4);
                            }
                            local_8._0_1_ = 3;
                            _eh_vector_destructor_iterator_(local_64,0x10,5,FUN_00e03dea);
                            goto LAB_00e2acbc;
                          }
                          FUN_00e03ab8(&local_104,(int *)&local_c4);
                          local_8 = CONCAT31(local_8._1_3_,0xc);
                          FUN_00e1cb7e(&local_ec,&local_104);
                          bstrString = local_104;
LAB_00e2ab09:
                          SysFreeString(bstrString);
                          pVVar8 = local_c8;
                        }
                        local_8 = CONCAT31(local_8._1_3_,9);
                        SysFreeString(local_c4);
                      }
                      piVar7 = local_c0;
                      if (local_c0 != (int *)0x0) {
                        local_c0 = (int *)0x0;
                        (**(code **)(*piVar7 + 8))(piVar7);
                      }
                      local_8 = CONCAT31(local_8._1_3_,8);
                      if (local_d0 != (int *)0x0) {
                        (**(code **)(*local_d0 + 8))(local_d0);
                      }
                    }
                    local_f0 = local_f0 + 1;
                    piVar6 = piVar6 + 4;
                    VariantClear(pVVar8);
                    pVVar8 = local_cc;
                    piVar7 = local_f4;
                  } while (local_f0 < local_e0);
                }
              } while( true );
            }
            goto LAB_00e2abb4;
          }
          goto LAB_00e2ac01;
        }
      }
    } while( true );
  }
LAB_00e2ac50:
  local_8._0_1_ = uVar1;
  if (((int)local_e8 - (int)local_ec & 0xfffffffcU) == 0) {
    puVar4 = FUN_00eb9380(&local_c8,0x7108);
    local_8._0_1_ = 0xd;
    puVar5 = FUN_00eb9380(&local_cc,0x7125);
    MessageBoxW((HWND)0x0,(LPCWSTR)*puVar5,(LPCWSTR)*puVar4,0);
    FUN_00e01f81((int *)&local_cc);
    FUN_00e01f81((int *)&local_c8);
  }
LAB_00e2acbc:
  local_8._0_1_ = 2;
  if (local_b8 != (int *)0x0) {
    (**(code **)(*local_b8 + 8))(local_b8);
  }
  local_8._0_1_ = 1;
  if (local_dc != (int *)0x0) {
    (**(code **)(*local_dc + 8))(local_dc);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_100 != (int *)0x0) {
    (**(code **)(*local_100 + 8))(local_100);
  }
  FUN_00e066bc((int *)&local_ec);
  FUN_00ec9e3c();
  return;
LAB_00e2ac34:
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 3;
  _eh_vector_destructor_iterator_(local_64,0x10,5,FUN_00e03dea);
  uVar1 = (undefined1)local_8;
  goto LAB_00e2ac50;
LAB_00e2ab8f:
  local_8._1_3_ = (uint3)((uint)local_8 >> 8);
  local_8._0_1_ = 7;
  _eh_vector_destructor_iterator_(local_b4,0x10,5,FUN_00e03dea);
LAB_00e2abb4:
  local_8._0_1_ = 6;
  if (local_c0 != (int *)0x0) {
    (**(code **)(*local_c0 + 8))(local_c0);
  }
  local_8._0_1_ = 5;
  if (local_bc != (int *)0x0) {
    (**(code **)(*local_bc + 8))(local_bc);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  if (local_d4 != (int *)0x0) {
    (**(code **)(*local_d4 + 8))(local_d4);
  }
LAB_00e2abea:
  piVar6 = local_b8;
  if (local_b8 != (int *)0x0) {
    local_b8 = (int *)0x0;
    (**(code **)(*piVar6 + 8))(piVar6);
  }
LAB_00e2ac01:
  local_f8 = local_f8 + 1;
  piVar7 = piVar7 + 4;
  local_f4 = piVar7;
  VariantClear(pVVar8);
  if (local_d8 <= local_f8) goto joined_r0x00e2a882;
  goto LAB_00e2a8c8;
}


