// Source: CLARiSOFT.exe @ 00e37009; FUN_00e37009

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __thiscall
FUN_00e37009(void *this,LPCWSTR param_1,BSTR param_2,BSTR param_3,int param_4,int param_5,
            BSTR param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  bool bVar11;
  HRESULT HVar12;
  UINT UVar13;
  int *piVar14;
  int iVar15;
  undefined4 uVar16;
  int extraout_ECX;
  int extraout_ECX_00;
  BSTR extraout_ECX_01;
  int extraout_ECX_02;
  BSTR extraout_ECX_03;
  BSTR extraout_ECX_04;
  BSTR pOVar17;
  int extraout_ECX_05;
  int extraout_ECX_06;
  undefined1 uVar18;
  LPVOID *ppvVar19;
  code *pcVar20;
  BSTR pOVar21;
  int *piVar22;
  int *piVar23;
  LPVOID **pppvVar24;
  _union_2683 local_a8;
  _union_2683 local_98;
  _union_2683 local_88;
  _union_2683 local_78;
  _union_2683 local_68;
  OLECHAR *local_58;
  VARIANTARG local_54;
  LPVOID *local_44;
  int *local_40;
  int local_3c;
  int *local_38;
  int *local_34;
  LPVOID *local_30;
  LPVOID *local_2c;
  LPVOID *local_28;
  _union_2683 local_24;
  char local_12;
  char local_11;
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 200;
  local_8 = 3;
  uStack_7 = 0;
  local_40 = this;
  bVar11 = ATL::CComBSTR::operator==
                     ((CComBSTR *)&param_1,(CComBSTR *)(*(int *)((int)this + 0x158) + 4));
  uVar18 = 0;
  local_12 = '\x01' - bVar11;
  HVar12 = VarBstrCmp(param_2,param_3,0x400,0);
  if (HVar12 == 1) {
    bVar11 = ATL::CComBSTR::operator==((CComBSTR *)&param_6,(CComBSTR *)((int)this + 0x1d8));
    local_11 = '\0';
    if (!bVar11) goto LAB_00e3706b;
  }
  else {
LAB_00e3706b:
    local_11 = '\x01';
  }
  if ((param_4 != *(int *)((int)this + 0x138)) ||
     (bVar11 = false, param_5 != *(int *)((int)this + 0x13c))) {
    bVar11 = true;
  }
  if (local_12 == '\0') {
    if ((local_11 == '\0') && (pcVar20 = SysFreeString_exref, !bVar11)) goto LAB_00e37ca6;
  }
  else {
    local_11 = '\x01';
  }
  *(undefined4 *)((int)this + 0x10) = 1;
  FUN_00e03bc2(&local_58,param_1);
  _local_8 = CONCAT31(uStack_7,4);
  SysFreeString(*(BSTR *)((int)this + 0x1d8));
  *(undefined4 *)((int)this + 0x1d8) = 0;
  UVar13 = SysStringLen(param_6);
  iVar15 = extraout_ECX;
  if (UVar13 != 0) {
    FUN_00e01fd0((void *)((int)this + 0x1d8),(int *)&param_6);
    iVar15 = extraout_ECX_00;
  }
  if ((local_12 != '\0') || (local_11 != '\0')) {
    local_12 = FUN_00eaf51f((int *)((int)this + 0x160));
    local_30 = (LPVOID *)FUN_00e050e5(*(void **)((int)this + 0x1e4),local_58);
    if (local_30 != (LPVOID *)0x0) {
      FUN_00e310e9(this,(int)local_30);
      *(LPVOID **)((int)this + 0x158) = local_30;
      local_2c = (LPVOID *)0x0;
      pppvVar24 = &local_2c;
      local_8 = 5;
      piVar23 = (int *)0x0;
      piVar22 = (int *)0x0;
      piVar14 = *(int **)((int)this + 0x19c);
      if (piVar14 != (int *)0x0) {
        (**(code **)(*piVar14 + 4))(piVar14);
      }
      FUN_00e35f1e(this,piVar14,piVar22,piVar23,(BSTR)pppvVar24);
      _local_8 = CONCAT31(uStack_7,4);
      SysFreeString((BSTR)local_2c);
    }
    local_11 = FUN_00eaf51f((int *)(*(int *)((int)this + 0x158) + 0x30));
    FUN_00e28d47(this,(int *)&param_2);
    FUN_00e2a1d4((int)this);
    pOVar17 = extraout_ECX_01;
    FUN_00e03ab8(&stack0xffffff14,(int *)(*(int *)((int)this + 0x158) + 4));
    FUN_00e34ec9(pOVar17);
    FUN_00e30971((int)this);
    (**(code **)(**(int **)((int)this + 0x19c) + 0x1c))();
    local_28 = (LPVOID *)0x0;
    iVar15 = extraout_ECX_02;
    if (0 < local_3c) {
      local_44 = local_30 + 2;
      do {
        ppvVar19 = local_28;
        FUN_00e03b51((uint *)&local_68);
        _local_8 = CONCAT31(uStack_7,6);
        local_30 = (LPVOID *)((int)ppvVar19 + 1);
        (**(code **)(**(int **)((int)this + 0x19c) + 0x24))();
        uVar16 = local_68._8_4_;
        local_34 = (int *)local_68._8_4_;
        if ((int *)local_68._8_4_ != (int *)0x0) {
          (**(code **)(*(int *)local_68._8_4_ + 4))();
        }
        local_8 = 7;
        ppvVar19 = (LPVOID *)((int)ppvVar19 + 1);
        if ((int *)uVar16 != (int *)0x0) {
          iVar15 = *(int *)uVar16;
          FUN_00e2f535((int)local_40,'\x01');
          (**(code **)(iVar15 + 0x78))();
          iVar15 = *(int *)uVar16;
          FUN_00e2f535((int)local_40,'\0');
          (**(code **)(iVar15 + 0x70))(uVar16);
          (**(code **)(*(int *)uVar16 + 0x50))(uVar16,param_2);
          CComQIPtr<>(&local_2c,(undefined4 *)uVar16);
          local_8 = 8;
          if (local_2c != (LPVOID *)0x0) {
            (**(code **)((int)*local_2c + 0xd0))();
          }
          local_8 = 7;
          ppvVar19 = local_30;
          this = local_40;
          if (local_2c != (LPVOID *)0x0) {
            (**(code **)((int)*local_2c + 8))();
            ppvVar19 = local_30;
            this = local_40;
          }
        }
        CComQIPtr<>(&local_38,(undefined4 *)uVar16);
        local_8 = 9;
        pOVar17 = extraout_ECX_03;
        if (local_38 != (int *)0x0) {
          (**(code **)(*local_38 + 0xa0))();
          pOVar17 = extraout_ECX_04;
        }
        FUN_00e03ab8(&stack0xffffff14,(int *)local_44);
        FUN_00e67d5d(*(void **)(*(int *)((int)this + 400) + (int)local_28 * 4),pOVar17);
        local_8 = 7;
        if (local_38 != (int *)0x0) {
          (**(code **)(*local_38 + 8))();
        }
        local_8 = 6;
        if ((int *)uVar16 != (int *)0x0) {
          (**(code **)(*(int *)uVar16 + 8))();
        }
        _local_8 = CONCAT31(uStack_7,4);
        VariantClear((VARIANTARG *)&local_68.n2);
        iVar15 = extraout_ECX_05;
        local_28 = ppvVar19;
      } while ((int)ppvVar19 < local_3c);
    }
    if ((local_12 != '\0') && (local_11 == '\0')) {
      FUN_00e34b9c((int)this);
      iVar15 = extraout_ECX_06;
    }
  }
  pOVar17 = *(BSTR *)((int)this + 0x210);
  piVar14 = *(int **)((int)this + 0x20c);
  FUN_00e03ab8(&stack0xffffff0c,(int *)((int)this + 0x208));
  FUN_00e35557(this,iVar15,piVar14,pOVar17);
  piVar14 = (int *)FUN_00e77808((int *)((int)this + 4),0);
  if (*piVar14 == 0) {
    local_38 = (int *)0x0;
  }
  else {
    local_38 = (int *)(*piVar14 + -100);
  }
  if ((param_4 != *(int *)((int)this + 0x138)) || (param_5 != *(int *)((int)this + 0x13c))) {
    iVar15 = FUN_00e3e85d((int)local_38);
    piVar14 = *(int **)(*(int *)(*(int *)((int)this + 400) + iVar15 * 4) + 0x18);
    local_34 = piVar14;
    if (piVar14 != (int *)0x0) {
      (**(code **)(*piVar14 + 4))();
    }
    local_8 = 10;
    (**(code **)(*piVar14 + 0x48))();
    (**(code **)(*piVar14 + 0x68))(piVar14);
    *(int *)((int)this + 0x138) = param_4;
    (**(code **)(*piVar14 + 0x40))(piVar14,param_5);
    (**(code **)(*piVar14 + 0x60))(piVar14,param_5);
    *(int *)((int)this + 0x13c) = param_5;
    _local_8 = CONCAT31(uStack_7,4);
    (**(code **)(*piVar14 + 8))(piVar14);
  }
  piVar14 = (int *)((int)this + 0x19c);
  local_34 = piVar14;
  (**(code **)(*(int *)*piVar14 + 0x48))();
  pcVar20 = SysFreeString_exref;
  if (((char)*(int *)((int)this + 0x204) != '\0') && ((char)*(int *)((int)this + 0x88) != '\0')) {
    pOVar17 = *(BSTR *)((int)this + 0x160);
    if (pOVar17 != (BSTR)0x0) {
      (**(code **)(*(int *)pOVar17 + 4))(pOVar17);
    }
    pOVar21 = (BSTR)*piVar14;
    if (pOVar21 != (BSTR)0x0) {
      (**(code **)(*(int *)pOVar21 + 4))(pOVar21);
    }
    iVar15 = FUN_00eb1fd0((int *)((int)this + 0x1ac),pOVar21,pOVar17);
    *(int *)((int)this + 0x28) = iVar15;
    local_2c = (LPVOID *)((int)this + 0x248);
    if (*local_2c == (LPVOID)0x0) {
      CoCreateInstance((IID *)&DAT_00eff2f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00eff480,local_2c);
    }
    ppvVar19 = (LPVOID *)((int)this + 0x24c);
    local_28 = ppvVar19;
    if (*ppvVar19 == (LPVOID)0x0) {
      CoCreateInstance((IID *)&DAT_00eff300,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00eff490,ppvVar19);
      iVar15 = *(int *)((int)this + 0x1e4);
      if (*(int *)(iVar15 + 8) == 0) {
        local_24._0_4_ = local_24._0_4_ & 0xffff0000;
        FUN_00e03e6b(&local_24,(int *)((int)this + 0x18));
        _local_8 = CONCAT31(uStack_7,0xf);
        (**(code **)(*(int *)*ppvVar19 + 0x24))
                  (*ppvVar19,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_);
        VariantClear((VARIANTARG *)&local_24.n2);
        this = local_40;
      }
      else {
        piVar14 = (int *)**(int **)(iVar15 + 4);
        if (piVar14 != *(int **)(iVar15 + 4)) {
          local_44 = (LPVOID *)((int)this + 0x18);
          do {
            local_3c = piVar14[2];
            local_24._8_4_ = *(int *)(local_3c + 0x28);
            local_24.n2.vt = 9;
            if ((int *)local_24._8_4_ != (int *)0x0) {
              (**(code **)(*(int *)local_24._8_4_ + 4))();
            }
            uVar10 = local_24._8_4_;
            uVar9 = local_24.decVal.Hi32;
            uVar8 = local_24._0_4_;
            local_8 = 0xb;
            local_a8._0_4_ = local_a8._0_4_ & 0xffff0000;
            FUN_00e03e6b(&local_a8,(int *)(local_3c + 4));
            uVar3 = local_a8._12_4_;
            uVar2 = local_a8._8_4_;
            uVar1 = local_a8.decVal.Hi32;
            uVar16 = local_a8._0_4_;
            local_8 = 0xc;
            local_98._0_4_ = local_98._0_4_ & 0xffff0000;
            FUN_00e03e6b(&local_98,(int *)(local_3c + 0x24));
            uVar7 = local_98._12_4_;
            uVar6 = local_98._8_4_;
            uVar5 = local_98.decVal.Hi32;
            uVar4 = local_98._0_4_;
            local_8 = 0xd;
            local_88._0_4_ = local_88._0_4_ & 0xffff0000;
            FUN_00e03e6b(&local_88,(int *)local_44);
            local_8 = 0xe;
            (**(code **)(*(int *)*local_28 + 0x28))
                      (*local_28,local_88._0_4_,local_88.decVal.Hi32,local_88._8_4_,local_88._12_4_,
                       uVar4,uVar5,uVar6,uVar7,uVar16,uVar1,uVar2,uVar3,uVar8,uVar9,uVar10);
            VariantClear((VARIANTARG *)&local_88.n2);
            VariantClear((VARIANTARG *)&local_98.n2);
            VariantClear((VARIANTARG *)&local_a8.n2);
            _local_8 = CONCAT31(uStack_7,4);
            VariantClear((VARIANTARG *)&local_24.n2);
            piVar14 = (int *)*piVar14;
            this = local_40;
          } while (piVar14 != (int *)*(int *)(local_40[0x79] + 4));
        }
      }
    }
    FUN_00e03b51((uint *)&local_54);
    local_30 = (LPVOID *)0x0;
    local_8 = 0x11;
    (**(code **)(**(int **)((int)this + 0x15c) + 0x1c))(*(int **)((int)this + 0x15c));
    FUN_00e6e048(&local_54,0);
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CS Field Resolve");
    local_8 = 0x12;
    (**(code **)(**(int **)((int)this + 0x248) + 0x20))
              (*(int **)((int)this + 0x248),local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,
               local_24._12_4_,&local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    FUN_00e11e15(&local_54,L"CLARISOFT");
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"ConversionRequestSource");
    local_8 = 0x13;
    (**(code **)(*(int *)*local_2c + 0x20))
              (*local_2c,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    FUN_00e6e048(&local_54,1);
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CS Font Convert");
    local_8 = 0x14;
    (**(code **)(*(int *)*local_28 + 0x20))
              (*local_28,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CS Cull");
    local_8 = 0x15;
    (**(code **)(*(int *)*local_28 + 0x20))
              (*local_28,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CS Resolution Adjust");
    local_8 = 0x16;
    (**(code **)(*(int *)*local_28 + 0x20))
              (*local_28,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CS Resolve Field Width");
    local_8 = 0x17;
    (**(code **)(*(int *)*local_28 + 0x20))
              (*local_28,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CS Field Order");
    local_8 = 0x18;
    (**(code **)(*(int *)*local_28 + 0x20))
              (*local_28,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CS Position");
    local_8 = 0x19;
    (**(code **)(*(int *)*local_28 + 0x20))
              (*local_28,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CS Tag");
    local_8 = 0x1a;
    (**(code **)(*(int *)*local_28 + 0x20))
              (*local_28,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    FUN_00e6e048(&local_54,0);
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CS Demo Field");
    local_8 = 0x1b;
    (**(code **)(*(int *)*local_28 + 0x20))
              (*local_28,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    FUN_00e11e15(&local_54,L"CLARISOFT");
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"ConversionRequestSource");
    local_8 = 0x1c;
    (**(code **)(*(int *)*local_28 + 0x20))
              (*local_28,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    piVar14 = local_40;
    FUN_00e03e6b(&local_54,(int *)(local_40[0x56] + 8));
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CapsFile");
    local_8 = 0x1d;
    (**(code **)(*(int *)piVar14[0x93] + 0x20))
              ((int *)piVar14[0x93],local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,
               local_24._12_4_,&local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    FUN_00e03e6b(&local_54,(int *)(piVar14[0x56] + 4));
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CapsCoder");
    local_8 = 0x1e;
    (**(code **)(*(int *)piVar14[0x93] + 0x20))
              ((int *)piVar14[0x93],local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,
               local_24._12_4_,&local_54);
    local_8 = 0x11;
    VariantClear((VARIANTARG *)&local_24.n2);
    FUN_00e03e6b(&local_54,(int *)&local_30);
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CapsFormat");
    local_8 = 0x1f;
    (**(code **)(*(int *)*local_28 + 0x20))
              (*local_28,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_54);
    VariantClear((VARIANTARG *)&local_24.n2);
    local_78.n2.vt = 3;
    local_78._8_4_ = 0;
    local_8 = 0x20;
    local_24._0_4_ = local_24._0_4_ & 0xffff0000;
    FUN_00e11e15(&local_24,L"CS Demo Field");
    local_8 = 0x21;
    (**(code **)(*(int *)*local_2c + 0x20))
              (*local_2c,local_24._0_4_,local_24.decVal.Hi32,local_24._8_4_,local_24._12_4_,
               &local_78);
    _local_8 = CONCAT31(uStack_7,0x20);
    VariantClear((VARIANTARG *)&local_24.n2);
    local_68._8_4_ = *local_34;
    local_68.n2.vt = 9;
    if ((int *)local_68._8_4_ != (int *)0x0) {
      (**(code **)(*(int *)local_68._8_4_ + 4))(local_68._8_4_);
    }
    _local_8 = CONCAT31(uStack_7,0x22);
    (**(code **)(*(int *)*local_2c + 0x1c))(*local_2c,&local_68);
    (**(code **)(*(int *)*local_28 + 0x1c))(*local_28,&local_68);
    iVar15 = FUN_00e3e85d((int)local_38);
    this = local_40;
    ppvVar19 = *(LPVOID **)(*(int *)(local_40[100] + iVar15 * 4) + 0x18);
    local_44 = ppvVar19;
    if (ppvVar19 != (LPVOID *)0x0) {
      (**(code **)((int)*ppvVar19 + 4))();
    }
    _local_8 = CONCAT31(uStack_7,0x23);
    bVar11 = FUN_00e03edc(&local_30,L"Default");
    if (!bVar11) {
      local_3c = 0;
      if ((*(int *)((int)this + 0x160) == 0) ||
         ((**(code **)(**(int **)((int)this + 0x160) + 0x3ec))(*(int **)((int)this + 0x160)),
         local_3c == 0)) {
        (**(code **)(**(int **)((int)this + 0x15c) + 0x24))(*(int **)((int)this + 0x15c));
        if (*(int *)((int)this + 0x22c) != 0) {
          FUN_00eae6d1(&local_34);
          _local_8 = CONCAT31(uStack_7,0x24);
          if (local_2c == (LPVOID *)0x0) {
            (**(code **)((int)*ppvVar19 + 0x68))(ppvVar19,param_4);
          }
          else {
            piVar14 = *(int **)((int)this + 0x160);
            if (piVar14 != (int *)0x0) {
              (**(code **)(*piVar14 + 4))(piVar14);
            }
            local_2c = (LPVOID *)FUN_00eae95c((int)local_2c,0.0,piVar14);
            (**(code **)((int)*ppvVar19 + 0x68))(ppvVar19,local_2c);
          }
          _local_8 = CONCAT31(uStack_7,0x23);
          FUN_00eae7b2(&local_34);
        }
      }
      else {
        (**(code **)((int)*ppvVar19 + 0x68))(ppvVar19);
      }
      (**(code **)((int)*ppvVar19 + 0x60))(ppvVar19,param_5);
    }
    local_8 = 0x22;
    if (ppvVar19 != (LPVOID *)0x0) {
      (**(code **)((int)*ppvVar19 + 8))();
    }
    VariantClear((VARIANTARG *)&local_68.n2);
    VariantClear((VARIANTARG *)&local_78.n2);
    pcVar20 = SysFreeString_exref;
    SysFreeString((BSTR)local_30);
    _local_8 = CONCAT31(uStack_7,4);
    VariantClear(&local_54);
  }
  FUN_00e03b21(&param_4,local_58);
  local_8 = 0x25;
  uVar16 = FUN_00e4661c(&param_4);
  local_8 = 4;
  (*pcVar20)();
  if ((char)uVar16 != '\0') {
    local_78._8_4_ = ZEXT14((char)*(int *)((int)this + 0x1d4) == '\0');
    local_78.n2.vt = 3;
    local_8 = 0x26;
    FUN_00e03b21(&param_4,L"RasterSubstitution");
    local_8 = 0x27;
    FUN_00e4668d((int *)((int)this + 0x19c),&param_4,0,(LPVARIANT)&local_78.n2);
    (*pcVar20)(param_4);
    local_8 = 4;
    VariantClear((VARIANTARG *)&local_78.n2);
  }
  FUN_00e2b99e((int)this);
  FUN_00e34641(this);
  InvalidateRect((HWND)local_38[1],(RECT *)0x0,1);
  FUN_00e359e6(this,*(int **)((int)this + 0x22c));
  if (local_38[0x27] != 0) {
    InvalidateRect(*(HWND *)(local_38[0x27] + 4),(RECT *)0x0,1);
  }
  if (local_38[0x26] != 0) {
    InvalidateRect(*(HWND *)(local_38[0x26] + 4),(RECT *)0x0,1);
  }
  (**(code **)(**(int **)((int)this + 0x19c) + 0x48))
            (*(int **)((int)this + 0x19c),*(undefined4 *)(*(int *)((int)this + 0x158) + 4));
  (**(code **)(*(int *)this + 4))(1,0);
  uVar18 = 1;
  FUN_00e01f81((int *)&local_58);
LAB_00e37ca6:
  (*pcVar20)();
  (*pcVar20)();
  (*pcVar20)();
  (*pcVar20)(param_6);
  return uVar18;
}


