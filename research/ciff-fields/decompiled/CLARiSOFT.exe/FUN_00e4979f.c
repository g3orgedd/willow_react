// Source: CLARiSOFT.exe @ 00e4979f; FUN_00e4979f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_00e4979f(void *this,int *param_1,LPWSTR param_2,int param_3,void *param_4,char param_5)

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
  undefined1 uVar10;
  int iVar11;
  OLECHAR *pOVar12;
  UINT UVar13;
  int *piVar14;
  OLECHAR *extraout_ECX;
  BSTR extraout_ECX_00;
  code *pcVar15;
  BSTR pOVar16;
  void *pvVar17;
  int local_138 [8];
  undefined4 local_118;
  undefined2 local_114;
  _union_2683 local_108;
  _union_2683 local_f8;
  _union_2683 local_e8;
  short local_d8 [4];
  undefined4 *local_d0;
  short local_c8 [4];
  undefined4 *local_c0;
  short local_b8 [4];
  undefined4 *local_b0;
  _union_2683 local_a8;
  _union_2683 local_98;
  int local_88;
  int local_84;
  int *local_80;
  BSTR local_7c;
  BSTR local_78;
  BSTR local_74;
  void *local_70;
  int *local_6c;
  int *local_68;
  int *local_64;
  void *local_60;
  BSTR local_5c;
  BSTR local_58;
  VARIANTARG local_54;
  int *local_44;
  int *local_40;
  _union_2683 local_3c;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pvVar17 = param_4;
  uStack_4 = 0x158;
  local_64 = param_1;
  local_70 = param_4;
  local_8 = 0;
  local_60 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CPrintCiff::PrintCiffFile");
  local_8._0_1_ = 1;
  if (param_3 < 1) goto LAB_00e4a4ad;
  local_58 = (BSTR)0x0;
  local_8._0_1_ = 2;
  (**(code **)(*(int *)*param_1 + 0x44))();
  pOVar12 = extraout_ECX;
  FUN_00e03ab8(&stack0xfffffe80,(int *)&local_58);
  iVar11 = FUN_00e4963c(this,pOVar12,pvVar17);
  if (iVar11 == 0) {
    FUN_00e03b51((uint *)local_c8);
    piVar14 = local_64;
    local_8._0_1_ = 3;
    (**(code **)(*(int *)*local_64 + 0x24))();
    pcVar15 = VariantClear_exref;
    if (local_c8[0] != 0) {
      CComQIPtr<>(&local_6c,local_c0);
      if (local_6c != (int *)0x0) {
        local_5c = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,5);
        (**(code **)(*local_6c + 0x4c))();
        *(int **)((int)this + 0x18) = local_6c;
        if (local_6c != (int *)0x0) {
          (**(code **)(*local_6c + 4))();
        }
        FUN_00e03b51((uint *)local_d8);
        local_8._0_1_ = 6;
        (**(code **)(**(int **)((int)this + 0x1c) + 0x470))();
        if (local_d8[0] != 0) {
          CComQIPtr<>(&local_80,local_d0);
          if (local_80 != (int *)0x0) {
            FUN_00e03b51((uint *)local_b8);
            local_8._0_1_ = 8;
            (**(code **)(*local_80 + 0x30))();
            if (local_b8[0] != 0) {
              CComQIPtr<>(&local_68,local_b0);
              local_8._0_1_ = 9;
              if (local_68 != (int *)0x0) {
                *(int **)((int)this + 100) = local_68;
                (**(code **)(*local_68 + 4))();
                FUN_00e4a72c((int)this);
                FUN_00e11de5((void *)((int)this + 0x14),piVar14);
                *(undefined4 *)((int)this + 0x68) = 0;
                *(undefined4 *)((int)this + 0x74) = 0;
                *(undefined4 *)((int)this + 0x78) = 0;
                local_64 = (int *)CoCreateInstance((IID *)&DAT_00eff2e0,(LPUNKNOWN)0x0,0x17,
                                                   (IID *)&DAT_00f01534,(LPVOID *)((int)this + 0x60)
                                                  );
                if ((param_5 == '\0') || (*(int *)((int)this + 0x10) == 2)) {
                  local_44 = (int *)0x0;
                  local_40 = (int *)0x0;
                  local_8._0_1_ = 0xb;
                  CoCreateInstance((IID *)&DAT_00eff2f0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00eff480,
                                   &local_44);
                  CoCreateInstance((IID *)&DAT_00eff300,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_00eff490,
                                   &local_40);
                  pOVar12 = (OLECHAR *)FUN_00eb80ef();
                  FUN_00e03b21(&local_74,pOVar12);
                  local_8._0_1_ = 0xc;
                  uVar10 = (undefined1)local_8;
                  local_8._0_1_ = 0xc;
                  if (*(int *)((int)local_70 + 8) == 0) {
                    local_8._0_1_ = uVar10;
                    SysFreeString(local_74);
                    local_8._0_1_ = 10;
                    if (local_40 != (int *)0x0) {
                      (**(code **)(*local_40 + 8))();
                    }
                    local_8._0_1_ = 9;
                    if (local_44 != (int *)0x0) {
                      (**(code **)(*local_44 + 8))();
                    }
                    goto LAB_00e4a450;
                  }
                  piVar14 = (int *)**(int **)((int)local_70 + 4);
                  if (piVar14 != *(int **)((int)local_70 + 4)) {
                    do {
                      local_88 = piVar14[2];
                      local_3c._8_4_ = *(int *)(local_88 + 0x28);
                      local_3c.n2.vt = 9;
                      if ((int *)local_3c._8_4_ != (int *)0x0) {
                        (**(code **)(*(int *)local_3c._8_4_ + 4))();
                      }
                      uVar9 = local_3c._0_4_;
                      local_8._0_1_ = 0xd;
                      local_e8._0_4_ = local_e8._0_4_ & 0xffff0000;
                      FUN_00e03e6b(&local_e8,(int *)(local_88 + 4));
                      uVar8 = local_e8._12_4_;
                      uVar7 = local_e8._8_4_;
                      uVar6 = local_e8.decVal.Hi32;
                      uVar5 = local_e8._0_4_;
                      local_8._0_1_ = 0xe;
                      local_108._0_4_ = local_108._0_4_ & 0xffff0000;
                      FUN_00e03e6b(&local_108,(int *)(local_88 + 0x24));
                      uVar4 = local_108._12_4_;
                      uVar3 = local_108._8_4_;
                      uVar2 = local_108.decVal.Hi32;
                      uVar1 = local_108._0_4_;
                      local_8._0_1_ = 0xf;
                      local_f8._0_4_ = local_f8._0_4_ & 0xffff0000;
                      FUN_00e03e6b(&local_f8,(int *)&local_74);
                      local_8._0_1_ = 0x10;
                      (**(code **)(*local_40 + 0x28))
                                (local_40,local_f8._0_4_,local_f8.decVal.Hi32,local_f8._8_4_,
                                 local_f8._12_4_,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8,
                                 uVar9);
                      VariantClear((VARIANTARG *)&local_f8.n2);
                      VariantClear((VARIANTARG *)&local_108.n2);
                      VariantClear((VARIANTARG *)&local_e8.n2);
                      local_8._0_1_ = 0xc;
                      VariantClear((VARIANTARG *)&local_3c.n2);
                      piVar14 = (int *)*piVar14;
                    } while (piVar14 != (int *)*(int *)((int)local_70 + 4));
                  }
                  FUN_00e03b51((uint *)&local_54);
                  this = local_60;
                  local_78 = (BSTR)0x0;
                  local_8._0_1_ = 0x12;
                  (**(code **)(**(int **)((int)local_60 + 100) + 0x1c))();
                  pOVar16 = extraout_ECX_00;
                  FUN_00e03ab8(&stack0xfffffe54,(int *)&local_58);
                  FUN_00e056b2((int)local_70,&local_7c,pOVar16);
                  local_98._8_4_ = *(int *)((int)this + 0x14);
                  local_8._0_1_ = 0x13;
                  local_98.n2.vt = 9;
                  if ((int *)local_98._8_4_ != (int *)0x0) {
                    (**(code **)(*(int *)local_98._8_4_ + 4))();
                  }
                  local_8._0_1_ = 0x14;
                  FUN_00e6e048(&local_54,1);
                  local_a8._8_4_ = 0;
                  local_a8.n2.vt = 3;
                  local_8._0_1_ = 0x15;
                  uVar10 = (undefined1)local_8;
                  local_8._0_1_ = 0x15;
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  if (*(int *)((int)this + 0x10) == 2) {
                    FUN_00e11e15(&local_3c,L"CS Demo Field");
                    local_8._0_1_ = 0x16;
                    (**(code **)(*local_40 + 0x20))
                              (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                               local_3c._12_4_);
                    local_8._0_1_ = 0x15;
                    VariantClear((VARIANTARG *)&local_3c.n2);
                    local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                    FUN_00e11e15(&local_3c,L"CS Demo Field");
                    local_8._0_1_ = 0x17;
                    (**(code **)(*local_44 + 0x20))
                              (local_44,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                               local_3c._12_4_,&local_54);
                    local_8._0_1_ = 0x15;
                    VariantClear((VARIANTARG *)&local_3c.n2);
                    local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                    FUN_00e11e15(&local_3c,L"CS Field Order");
                    local_8._0_1_ = 0x18;
                    piVar14 = local_40;
                  }
                  else {
                    local_8._0_1_ = uVar10;
                    FUN_00e11e15(&local_3c,L"CS Demo Field");
                    local_8._0_1_ = 0x19;
                    (**(code **)(*local_40 + 0x20))
                              (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                               local_3c._12_4_);
                    local_8._0_1_ = 0x15;
                    VariantClear((VARIANTARG *)&local_3c.n2);
                    local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                    FUN_00e11e15(&local_3c,L"CS Demo Field");
                    local_8._0_1_ = 0x1a;
                    piVar14 = local_44;
                  }
                  (**(code **)(*piVar14 + 0x20))
                            (piVar14,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_a8);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  FUN_00e11e15(&local_54,L"JobSelection");
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"ConversionRequestSource");
                  local_8._0_1_ = 0x1b;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  FUN_00e03e6b(&local_54,(int *)&local_7c);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CapsFile");
                  local_8._0_1_ = 0x1c;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  FUN_00e03e6b(&local_54,(int *)&local_58);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CapsCoder");
                  local_8._0_1_ = 0x1d;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  FUN_00e03e6b(&local_54,(int *)&local_5c);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CapsFormat");
                  local_8._0_1_ = 0x1e;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  (**(code **)(*local_40 + 0x1c))(local_40,&local_98);
                  FUN_00e6e048(&local_54,1);
                  UVar13 = SysStringLen(*(BSTR *)((int)this + 8));
                  if (UVar13 != 0) {
                    local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                    FUN_00e11e15(&local_3c,L"CS Database Resolve");
                    local_8._0_1_ = 0x1f;
                    (**(code **)(*local_44 + 0x20))
                              (local_44,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                               local_3c._12_4_,&local_54);
                    local_8._0_1_ = 0x15;
                    VariantClear((VARIANTARG *)&local_3c.n2);
                  }
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CS Field Resolve");
                  local_8._0_1_ = 0x20;
                  (**(code **)(*local_44 + 0x20))
                            (local_44,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  UVar13 = SysStringLen(*(BSTR *)((int)this + 8));
                  if (UVar13 != 0) {
                    FUN_00e03e6b(&local_54,(int *)((int)this + 8));
                    local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                    FUN_00e11e15(&local_3c,L"Database");
                    local_8._0_1_ = 0x21;
                    (**(code **)(*local_44 + 0x20))
                              (local_44,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                               local_3c._12_4_,&local_54);
                    local_8._0_1_ = 0x15;
                    VariantClear((VARIANTARG *)&local_3c.n2);
                    FUN_00e03e6b(&local_54,(int *)((int)this + 0xc));
                    local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                    FUN_00e11e15(&local_3c,L"ProductCode");
                    local_8._0_1_ = 0x22;
                    (**(code **)(*local_44 + 0x20))
                              (local_44,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                               local_3c._12_4_,&local_54);
                    local_8._0_1_ = 0x15;
                    VariantClear((VARIANTARG *)&local_3c.n2);
                  }
                  FUN_00e11e15(&local_54,L"JobSelection");
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"ConversionRequestSource");
                  local_8._0_1_ = 0x23;
                  (**(code **)(*local_44 + 0x20))
                            (local_44,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  FUN_00e6e048(&local_54,1);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CS Cull");
                  local_8._0_1_ = 0x24;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CS Resolution Adjust");
                  local_8._0_1_ = 0x25;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CS Font Convert");
                  local_8._0_1_ = 0x26;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CS Resolve Field Width");
                  local_8._0_1_ = 0x27;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  local_84 = 0;
                  (**(code **)(**(int **)((int)this + 100) + 0x4c))
                            (*(int **)((int)this + 100),&local_84);
                  if (local_84 != 0) {
                    local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                    FUN_00e11e15(&local_3c,L"CS Field Order");
                    local_8._0_1_ = 0x28;
                    (**(code **)(*local_40 + 0x20))
                              (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                               local_3c._12_4_,&local_54);
                    local_8._0_1_ = 0x15;
                    VariantClear((VARIANTARG *)&local_3c.n2);
                  }
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CS Position");
                  local_8._0_1_ = 0x29;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CS Add Tab Fields");
                  local_8._0_1_ = 0x2a;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CS Tag");
                  local_8._0_1_ = 0x2b;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CS RTBF2LOGO");
                  local_8._0_1_ = 0x2c;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  FUN_00e11e15(&local_54,L"Print Preview");
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"ConversionRequestSource");
                  local_8._0_1_ = 0x2d;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  FUN_00e03e6b(&local_54,(int *)&local_7c);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CapsFile");
                  local_8._0_1_ = 0x2e;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  FUN_00e03e6b(&local_54,(int *)&local_58);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CapsCoder");
                  local_8._0_1_ = 0x2f;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  FUN_00e03e6b(&local_54,(int *)&local_5c);
                  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
                  FUN_00e11e15(&local_3c,L"CapsFormat");
                  local_8._0_1_ = 0x30;
                  (**(code **)(*local_40 + 0x20))
                            (local_40,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                             local_3c._12_4_,&local_54);
                  pcVar15 = VariantClear_exref;
                  local_8._0_1_ = 0x15;
                  VariantClear((VARIANTARG *)&local_3c.n2);
                  (**(code **)(*local_44 + 0x1c))(local_44,&local_98);
                  (**(code **)(*local_40 + 0x1c))(local_40,&local_98);
                  VariantClear((VARIANTARG *)&local_a8.n2);
                  VariantClear((VARIANTARG *)&local_98.n2);
                  SysFreeString(local_7c);
                  SysFreeString(local_78);
                  VariantClear(&local_54);
                  SysFreeString(local_74);
                  local_8._0_1_ = 10;
                  if (local_40 != (int *)0x0) {
                    (**(code **)(*local_40 + 8))();
                  }
                  local_8._0_1_ = 9;
                  if (local_44 != (int *)0x0) {
                    (**(code **)(*local_44 + 8))();
                  }
                }
                FUN_00e49754((void *)((int)this + 0x54),param_2,(LPDEVMODEW)0x0);
                FUN_00e4957d((void *)((int)this + 0x58),*(HANDLE *)((int)this + 0x54));
                local_114 = 0x100;
                local_138[0] = 0;
                local_118 = 0;
                local_8._0_1_ = 0x31;
                piVar14 = FUN_00e03bc2(&local_60,*(LPCWSTR *)((int)this + 0xc));
                local_8._0_1_ = 0x32;
                FUN_00e4a8d4(local_138,'\0',*(int *)((int)this + 0x54),*(int *)((int)this + 0x5c),
                             (DWORD)this,*piVar14,0,param_3 + -1,'\0',(wchar_t *)0x0);
                FUN_00e01f81((int *)&local_60);
                if (*(int *)((int)this + 0x54) != 0) {
                  ClosePrinter(*(HANDLE *)((int)this + 0x54));
                  *(undefined4 *)((int)this + 0x54) = 0;
                }
                SelectObject(*(HDC *)((int)this + 0x68),*(HGDIOBJ *)((int)this + 0x70));
                if (*(int *)((int)this + 0x68) != 0) {
                  DeleteDC(*(HDC *)((int)this + 0x68));
                }
                if (*(int *)((int)this + 0x6c) != 0) {
                  DeleteObject(*(HGDIOBJ *)((int)this + 0x6c));
                }
                if (local_138[0] != 0) {
                  local_138[0] = 0;
                }
              }
LAB_00e4a450:
              local_8._0_1_ = 8;
              if (local_68 != (int *)0x0) {
                (**(code **)(*local_68 + 8))();
              }
            }
            (*pcVar15)();
          }
          local_8._0_1_ = 6;
          if (local_80 != (int *)0x0) {
            (**(code **)(*local_80 + 8))();
          }
        }
        (*pcVar15)();
        SysFreeString(local_5c);
      }
      local_8._0_1_ = 3;
      if (local_6c != (int *)0x0) {
        (**(code **)(*local_6c + 8))();
      }
    }
    (*pcVar15)();
  }
  SysFreeString(local_58);
LAB_00e4a4ad:
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_00e01f81((int *)&param_2);
  FUN_00ec9e3c();
  return;
}


