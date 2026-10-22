// Source: CiffMgr.dll @ 68118e92; FUN_68118e92

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_68118e92(void *this,IUnknownVtbl *param_1,int *param_2,undefined4 *param_3)

{
  OLECHAR OVar1;
  uint uVar2;
  OLECHAR *pOVar3;
  char cVar4;
  int iVar5;
  UINT UVar6;
  BSTR pOVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  BSTR pOVar11;
  BSTR pOVar12;
  undefined1 (*pauVar13) [16];
  ULONG UVar14;
  IUnknown _Dst;
  BSTR pOVar15;
  IUnknown bstrString;
  code *pcVar16;
  uint local_ec [3];
  IUnknownVtbl *local_e0;
  undefined4 local_dc;
  int *local_d8;
  OLECHAR *local_d4;
  IUnknown local_d0;
  int local_cc;
  uint local_c8;
  BSTR local_c4;
  BSTR local_c0;
  undefined1 (*local_bc) [16];
  int local_b8;
  BSTR local_b4;
  undefined4 local_b0;
  undefined1 (*local_ac) [16];
  undefined4 local_a8;
  BSTR local_a4;
  IUnknownVtbl *local_a0;
  int local_9c;
  int *local_98;
  BSTR local_94;
  IUnknown local_90;
  BSTR local_8c;
  BSTR local_88;
  void *local_84;
  undefined1 (*local_80) [16];
  BSTR local_7c;
  BSTR local_78;
  ULONG local_74;
  OLECHAR *local_70;
  wchar_t local_6c [22];
  wchar_t local_40 [28];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xdc;
  local_8 = 0x68118ea1;
  local_d8 = param_2;
  local_a0 = param_1;
  local_84 = this;
  if (param_1 == (IUnknownVtbl *)0x0) goto LAB_681196c4;
  local_ec[1] = 0;
  CComQIPtr<>(&local_98,param_3);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if (local_98 == (int *)0x0) {
    local_9c = 1;
    local_b8 = 0;
  }
  else {
    iVar5 = (**(code **)(*local_98 + 0xc))(local_98,&local_b8);
    if (iVar5 < 0) {
      local_b8 = 0;
    }
    iVar5 = (**(code **)(*local_98 + 0x10))(local_98,&local_9c);
    if (iVar5 < 0) {
      local_9c = 1;
    }
    else {
      local_9c = local_9c + 1;
    }
    CComQIPtr<>(&local_78,local_98);
    local_8._0_1_ = 1;
    if (local_78 != (BSTR)0x0) {
      (**(code **)(*(int *)local_78 + 0x18))(local_78,local_ec + 1);
    }
    local_8._0_1_ = 0;
    if (local_78 != (BSTR)0x0) {
      (**(code **)(*(int *)local_78 + 8))(local_78);
    }
  }
  if ((local_b8 != 0) && (*(int *)((int)this + 4) == 0)) {
    local_8 = 0xffffffff;
    if (local_98 != (int *)0x0) {
      (**(code **)(*local_98 + 8))(local_98);
    }
    goto LAB_681196c4;
  }
  local_c0 = (BSTR)0x0;
  local_8._0_1_ = 2;
  (**(code **)(param_1->QueryInterface + 0x78))(param_1,&local_c0);
  UVar6 = SysStringLen(local_c0);
  UVar14 = 0x80040241;
  pcVar16 = SysFreeString_exref;
  if (UVar6 == 0) {
LAB_6811961f:
    if (UVar14 == 0x80040241) goto LAB_68119629;
  }
  else {
    local_cc = 0;
    if (0 < local_9c) {
      local_d0.lpVtbl = param_1;
      local_dc = 0x1f;
      local_80 = (undefined1 (*) [16])((int)local_84 + 0x10);
      do {
        local_8c = (BSTR)0x0;
        local_a8 = 0;
        local_b0 = 0;
        local_ac = (undefined1 (*) [16])0x0;
        local_88 = (BSTR)0x0;
        local_b4 = (BSTR)0x0;
        local_bc = (undefined1 (*) [16])0x0;
        local_8._0_1_ = 5;
        if (local_cc == 0) {
          local_8c = *(BSTR *)((int)local_84 + 0xaf4);
          local_a8 = *(undefined4 *)((int)local_84 + 0xafc);
          pOVar7 = *(BSTR *)((int)local_84 + 0xaf8);
        }
        else {
          iVar5 = (**(code **)(*local_98 + 0x14))
                            (local_98,local_cc + -1,&local_88,&local_b4,&local_a8,&local_bc);
          param_1 = local_a0;
          pOVar7 = (BSTR)0x0;
          if (-1 < iVar5) {
            local_8c = local_88;
            local_b0 = 1;
            local_ac = local_bc;
            pOVar7 = local_b4;
          }
        }
        local_70 = (OLECHAR *)0x0;
        local_8._0_1_ = 6;
        (**(code **)(param_1->QueryInterface + 4))(param_1);
        local_8._0_1_ = 7;
        (**(code **)(*(int *)*local_80 + 4))(local_80,local_c0,pOVar7,local_a8,local_b0,&local_70);
        local_74 = FUN_68118879(&local_d0,(int *)local_ec,local_ec + 2,(int *)&local_c8);
        if (-1 < (int)local_74) {
          pOVar7 = SysAllocStringLen(local_70,0x18);
          local_c4 = pOVar7;
          if (pOVar7 == (BSTR)0x0) {
LAB_68119539:
                    /* WARNING: Subroutine does not return */
            FUN_681024d6(-0x7ff8fff2);
          }
          local_94 = (BSTR)0x0;
          local_e0 = (IUnknownVtbl *)0x0;
          local_8._0_1_ = 10;
          local_90.lpVtbl = (IUnknownVtbl *)SysAllocStringLen((OLECHAR *)0x0,6);
          _Dst.lpVtbl = (IUnknownVtbl *)0x0;
          if (local_90.lpVtbl != (IUnknownVtbl *)0x0) {
            (*pcVar16)(0);
            local_e0 = local_90.lpVtbl;
            _Dst.lpVtbl = local_90.lpVtbl;
          }
          uVar2 = 99;
          uVar8 = local_c8;
          if (99 < (int)local_c8) {
            uVar8 = uVar2;
          }
          uVar9 = local_ec[2];
          if (99 < (int)local_ec[2]) {
            uVar9 = uVar2;
          }
          uVar10 = local_ec[0];
          if (99 < (int)local_ec[0]) {
            uVar10 = uVar2;
          }
          _swprintf_s((wchar_t *)_Dst.lpVtbl,7,L"%02ld%02ld%02ld",uVar10,uVar9,uVar8);
          local_a4 = (BSTR)0x0;
          iVar5 = (**(code **)(*(int *)*local_80 + 4))
                            (local_80,pOVar7,_Dst.lpVtbl,local_a8,local_b0,&local_94);
          if ((iVar5 < 0) || (UVar6 = SysStringLen(local_94), UVar6 != 8)) {
            local_74 = 0x80040241;
LAB_6811932e:
            if (-1 < (int)local_74) {
              UVar6 = SysStringLen(local_70);
              if (UVar6 < 0x18) {
                local_74 = 0x80040241;
              }
              else {
                local_90.lpVtbl = (IUnknownVtbl *)0x0;
                local_7c = (BSTR)0x0;
                local_8._0_1_ = 0xe;
                local_74 = FUN_68118a19(&local_d0,local_a4,&local_90);
                bstrString.lpVtbl = local_90.lpVtbl;
                if (-1 < (int)local_74) {
                  FUN_6810210e(&local_78,local_70 + 0x18);
                  local_8._0_1_ = 0xf;
                  (**(code **)(*(int *)*local_80 + 4))
                            (local_80,local_78,local_8c,local_a8,local_b0,&local_7c);
                  local_8c = (BSTR)SysStringLen(local_7c);
                  pOVar11 = (BSTR)SysStringLen((BSTR)bstrString.lpVtbl);
                  if ((local_8c == (BSTR)0x0) || (pOVar11 == (BSTR)0x0)) {
                    cVar4 = local_8c == pOVar11;
                  }
                  else {
                    pOVar12 = local_8c;
                    if ((BSTR)0x14 < local_8c) {
                      pOVar12 = (BSTR)0x14;
                    }
                    local_8c = (BSTR)0x0;
                    local_a4 = (BSTR)0x0;
                    if (pOVar12 != (BSTR)0x0) {
                      local_8c = (BSTR)0x0;
                      pOVar15 = local_8c;
                      do {
                        if ((ushort)(OLECHAR)local_dc < (ushort)local_7c[(int)pOVar15]) {
                          local_40[(int)local_8c] = local_7c[(int)pOVar15];
                          local_8c = (BSTR)((int)local_8c + 1);
                        }
                        pOVar15 = (BSTR)((int)pOVar15 + 1);
                        pOVar7 = local_c4;
                        _Dst.lpVtbl = local_e0;
                        bstrString.lpVtbl = local_90.lpVtbl;
                      } while (pOVar15 < pOVar12);
                    }
                    pOVar12 = (BSTR)0x0;
                    if ((BSTR)0x14 < pOVar11) {
                      pOVar11 = (BSTR)0x14;
                    }
                    pOVar15 = (BSTR)0x0;
                    if (pOVar11 != (BSTR)0x0) {
                      do {
                        OVar1 = *(BSTR)((int)&(bstrString.lpVtbl)->QueryInterface + (int)pOVar15 * 2
                                       );
                        if ((ushort)(OLECHAR)local_dc < (ushort)OVar1) {
                          local_6c[(int)pOVar12] = OVar1;
                          pOVar12 = (BSTR)((int)pOVar12 + 1);
                        }
                        pOVar15 = (BSTR)((int)pOVar15 + 1);
                        pOVar7 = local_c4;
                      } while (pOVar15 < pOVar11);
                    }
                    if (local_8c < pOVar12) {
                      pOVar12 = local_8c;
                    }
                    if (0x29 < (uint)((int)pOVar12 * 2)) {
                    /* WARNING: Subroutine does not return */
                      ___report_rangecheckfailure();
                    }
                    local_6c[(int)pOVar12] = L'\0';
                    local_40[(int)pOVar12] = L'\0';
                    iVar5 = _wcscmp(local_40,local_6c);
                    cVar4 = '\x01' - (iVar5 != 0);
                  }
                  if (cVar4 != '\0') {
                    if ((local_ac != (undefined1 (*) [16])0x0) && (*(OLECHAR *)*local_ac != L'\0'))
                    {
                      local_80 = (undefined1 (*) [16])0x0;
                      local_8._0_1_ = 0x10;
                      iVar5 = (**(code **)(local_a0->QueryInterface + 0x4c))(local_a0,&local_80);
                      if (iVar5 < 0) {
LAB_681195ab:
                        (**(code **)(local_a0->QueryInterface + 0x50))(local_a0,local_ac);
                      }
                      else {
                        local_c8 = SysStringLen((BSTR)local_80);
                        UVar6 = SysStringLen((BSTR)local_ac);
                        if ((local_c8 < UVar6) ||
                           (pauVar13 = FUN_68134a98(local_80,local_ac),
                           pauVar13 == (undefined1 (*) [16])0x0)) goto LAB_681195ab;
                      }
                      SysFreeString((BSTR)local_80);
                    }
                    SysFreeString(local_78);
                    SysFreeString(local_7c);
                    pcVar16 = SysFreeString_exref;
                    SysFreeString((BSTR)bstrString.lpVtbl);
                    SysFreeString((BSTR)_Dst.lpVtbl);
                    SysFreeString(local_94);
                    SysFreeString(pOVar7);
                    param_1 = local_a0;
                    local_8._0_1_ = 6;
                    (**(code **)(local_a0->QueryInterface + 8))(local_a0);
                    SysFreeString(local_70);
                    SysFreeString((BSTR)local_bc);
                    SysFreeString(local_b4);
                    SysFreeString(local_88);
                    UVar14 = local_74;
                    break;
                  }
                  local_74 = 0x80040241;
                  SysFreeString(local_78);
                }
                SysFreeString(local_7c);
                pcVar16 = SysFreeString_exref;
                SysFreeString((BSTR)bstrString.lpVtbl);
              }
            }
          }
          else {
            local_74 = FUN_68118280((int *)&local_94,(int *)&local_a4);
            if (-1 < (int)local_74) {
              local_7c = (BSTR)0x0;
              local_8._0_1_ = 0xb;
              local_74 = (**(code **)(local_a0->QueryInterface + 0x84))(local_a0,&local_7c);
              cVar4 = FUN_68118c55((BSTR)&local_70,(BSTR)&local_94,&local_7c);
              *(char *)((int)local_84 + 0xc) = cVar4;
              if (cVar4 != '\0') {
                FUN_6810210e(&local_d4,local_70 + (int)(local_a4 + 0xc));
                local_8._0_1_ = 0xc;
                (*pcVar16)(local_70);
                pOVar3 = local_d4;
                local_d4 = (OLECHAR *)0x0;
                local_70 = (OLECHAR *)0x0;
                if (pOVar3 != (OLECHAR *)0x0) {
                  (*pcVar16)(0);
                  local_70 = pOVar3;
                }
                local_90.lpVtbl = (IUnknownVtbl *)SysAllocStringLen(local_70,0x18);
                if (local_90.lpVtbl == (IUnknownVtbl *)0x0) goto LAB_68119539;
                FUN_681181da(&local_c4,(int *)&local_90);
                (*pcVar16)(local_90.lpVtbl);
                pOVar7 = local_c4;
                (**(code **)(*(int *)*local_80 + 4))
                          (local_80,local_c4,_Dst.lpVtbl,local_a8,local_b0,&local_94);
                local_74 = FUN_68118280((int *)&local_94,(int *)&local_a4);
                if ((int)local_74 < 0) {
                  local_74 = 0x80040241;
                }
                (*pcVar16)(0);
              }
              (*pcVar16)(local_7c);
              goto LAB_6811932e;
            }
          }
          (*pcVar16)(_Dst.lpVtbl);
          (*pcVar16)(local_94);
          (*pcVar16)(pOVar7);
          param_1 = local_a0;
        }
        local_8._0_1_ = 6;
        (**(code **)(param_1->QueryInterface + 8))(param_1);
        (*pcVar16)(local_70);
        (*pcVar16)(local_bc);
        (*pcVar16)(local_b4);
        (*pcVar16)(local_88);
        local_cc = local_cc + 1;
        UVar14 = local_74;
      } while (local_cc < local_9c);
      goto LAB_6811961f;
    }
LAB_68119629:
    if (local_d8 != (int *)0x0) {
      local_88 = (BSTR)0x0;
      local_8._0_1_ = 0x11;
      (**(code **)(param_1->QueryInterface + 0xa4))(param_1,&local_88);
      UVar6 = SysStringLen(local_88);
      if (UVar6 != 0) {
        local_78 = (BSTR)0x0;
        local_8._0_1_ = 0x12;
        iVar5 = (**(code **)(*local_d8 + 0xc))(local_d8,local_88,&local_78);
        if (-1 < iVar5) {
          (**(code **)(param_1->QueryInterface + 0x50))(param_1,local_78);
          UVar14 = 0;
        }
        (*pcVar16)(local_78);
      }
      (*pcVar16)(local_88);
    }
  }
  *(uint *)((int)local_84 + 8) = (uint)(-1 < (int)UVar14);
  (*pcVar16)(local_c0);
  local_8 = 0xffffffff;
  if (local_98 != (int *)0x0) {
    (**(code **)(*local_98 + 8))(local_98);
  }
LAB_681196c4:
  FUN_681320d7();
  return;
}


