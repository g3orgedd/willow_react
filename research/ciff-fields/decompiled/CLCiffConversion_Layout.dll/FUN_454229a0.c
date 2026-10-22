// Source: CLCiffConversion_Layout.dll @ 454229a0; FUN_454229a0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_454229a0(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  undefined2 uVar2;
  HRESULT HVar3;
  int iVar4;
  DWORD DVar5;
  _union_2683 local_1e4;
  _union_2683 local_1d4;
  _union_2683 local_1c4;
  _union_2683 local_1b4;
  BSTR local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  int local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  BSTR local_17c;
  int *local_178;
  undefined4 local_174;
  BSTR local_170;
  int *local_16c;
  BSTR local_168;
  int *local_164;
  int *local_160;
  int *local_15c;
  int *local_158;
  BSTR local_154;
  BSTR local_150;
  int *local_14c;
  IID local_148;
  IID local_138;
  _union_2683 local_128;
  CHAR local_118;
  uint local_117 [67];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1d8;
  local_158 = param_2;
  local_150 = (BSTR)0x0;
  local_178 = (int *)0x0;
  local_8 = 2;
  local_138.Data1 = 0x77019f8f;
  local_138.Data2 = 0x9c60;
  local_138.Data3 = 0x4fdd;
  local_138.Data4[0] = 0xa4;
  local_138.Data4[1] = '.';
  local_138.Data4[2] = '2';
  local_138.Data4[3] = 200;
  local_138.Data4[4] = 'm';
  local_138.Data4[5] = 'M';
  local_138.Data4[6] = 0xe0;
  local_138.Data4[7] = ':';
  HVar3 = CoCreateInstance(&local_138,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_45449d68,&local_178);
  if (HVar3 < 0) goto LAB_4542315c;
  local_1e4._8_4_ = *param_2;
  local_1e4.n2.vt = 9;
  if ((int *)local_1e4._8_4_ != (int *)0x0) {
    (**(code **)(*(int *)local_1e4._8_4_ + 4))(local_1e4._8_4_);
  }
  local_8._0_1_ = 3;
  local_1c4.n2.vt = 9;
  local_1c4._8_4_ = *param_1;
  if ((int *)local_1c4._8_4_ != (int *)0x0) {
    (**(code **)(*(int *)local_1c4._8_4_ + 4))(local_1c4._8_4_);
  }
  local_8._0_1_ = 4;
  local_1d4._8_4_ = *param_4;
  local_1d4.n2.vt = 9;
  uVar2 = 9;
  if ((int *)local_1d4._8_4_ != (int *)0x0) {
    (**(code **)(*(int *)local_1d4._8_4_ + 4))(local_1d4._8_4_);
    uVar2 = local_1d4.n2.vt;
  }
  if (((local_1e4.n2.vt == 0) || (local_1c4.n2.vt == 0)) || (uVar2 == 0)) {
LAB_45422cac:
    local_170 = (BSTR)0x0;
    local_8._0_1_ = 0xb;
    (**(code **)(*(int *)*param_2 + 0x1c))((int *)*param_2,&local_170);
    local_17c = (BSTR)0x0;
    local_8._0_1_ = 0xc;
    (**(code **)(*param_3 + 0x34))(param_3,&local_17c);
    FUN_45429f70((uint *)&local_1b4,0,0x10);
    VariantInit((VARIANTARG *)&local_1b4.n2);
    local_16c = (int *)0x0;
    local_8._0_1_ = 0xe;
    local_148.Data1 = 0x6ae09851;
    local_148.Data2 = 0xd80f;
    local_148.Data3 = 0x11d4;
    local_148.Data4[0] = 0x8d;
    local_148.Data4[1] = 0xae;
    local_148.Data4[2] = '\0';
    local_148.Data4[3] = 'P';
    local_148.Data4[4] = 0xda;
    local_148.Data4[5] = 0xfe;
    local_148.Data4[6] = 0x8a;
    local_148.Data4[7] = 0x9f;
    HVar3 = CoCreateInstance(&local_148,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_45449d68,&local_16c);
    if ((-1 < HVar3) &&
       (iVar4 = (**(code **)(*local_16c + 0x1c))
                          (local_16c,0,L"Arial",10,local_1d4._0_4_,local_1d4.decVal.Hi32,
                           local_1d4._8_4_,local_1d4._12_4_,local_17c,local_170,local_1c4._0_4_,
                           local_1c4.decVal.Hi32,local_1c4._8_4_,local_1c4._12_4_,&local_1b4),
       -1 < iVar4)) {
      local_14c = (int *)0x0;
      local_8._0_1_ = 0xf;
      if (local_1b4.n2.vt == 9) {
        (*(code *)**(undefined4 **)local_1b4._8_4_)(local_1b4._8_4_,&DAT_45447c4c,&local_14c);
      }
      piVar1 = local_158;
      iVar4 = (**(code **)(*(int *)*local_158 + 0x78))((int *)*local_158,&local_174);
      if ((((((-1 < iVar4) &&
             (iVar4 = (**(code **)(*(int *)*piVar1 + 0x80))((int *)*piVar1,&local_180), -1 < iVar4))
            && (iVar4 = (**(code **)(*local_14c + 0x7c))(local_14c,local_174), -1 < iVar4)) &&
           ((iVar4 = (**(code **)(*local_14c + 0x84))(local_14c,local_180), -1 < iVar4 &&
            (iVar4 = (**(code **)(*(int *)*piVar1 + 0x2c))((int *)*piVar1,&local_190), -1 < iVar4)))
           ) && ((iVar4 = (**(code **)(*(int *)*piVar1 + 0x34))((int *)*piVar1,&local_194),
                 -1 < iVar4 &&
                 ((iVar4 = (**(code **)(*local_14c + 0x30))(local_14c,local_190), -1 < iVar4 &&
                  (iVar4 = (**(code **)(*local_14c + 0x38))(local_14c,local_194), -1 < iVar4))))))
         && ((iVar4 = (**(code **)(*(int *)*piVar1 + 0x3c))((int *)*piVar1,&local_188), -1 < iVar4
             && (((iVar4 = (**(code **)(*local_14c + 0x40))(local_14c,local_188), -1 < iVar4 &&
                  (iVar4 = (**(code **)(*(int *)*piVar1 + 0x54))((int *)*piVar1,&local_198),
                  -1 < iVar4)) &&
                 (iVar4 = (**(code **)(*local_14c + 0x58))(local_14c,local_198), -1 < iVar4)))))) {
        (**(code **)(*local_14c + 0x9c))(local_14c,local_150);
        local_184 = 0;
        (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,&local_184);
        (**(code **)(*local_14c + 0x28))(local_14c,local_184);
        local_15c = (int *)0x0;
        local_8._0_1_ = 0x10;
        iVar4 = (**(code **)(*local_14c + 0x5c))(local_14c,&local_15c);
        if ((-1 < iVar4) && (local_15c != (int *)0x0)) {
          FUN_45429f70((uint *)&local_128,0,0x10);
          VariantInit((VARIANTARG *)&local_128.n2);
          local_8._0_1_ = 0x11;
          iVar4 = (**(code **)(*local_15c + 0x24))(local_15c,1,&local_128);
          if (-1 < iVar4) {
            CComQIPtr<>(&local_158,(undefined4 *)local_128._8_4_);
            local_8._0_1_ = 0x12;
            (**(code **)(*local_158 + 0x5c))(local_158,local_150);
            local_8._0_1_ = 0x11;
            if (local_158 != (int *)0x0) {
              (**(code **)(*local_158 + 8))(local_158);
            }
          }
          VariantClear((VARIANTARG *)&local_128.n2);
        }
        local_160 = (int *)0x0;
        local_8._0_1_ = 0x13;
        (**(code **)*local_14c)(local_14c,&DAT_4544a718,&local_160);
        iVar4 = (**(code **)(*local_160 + 0xac))(local_160,local_174);
        if ((-1 < iVar4) &&
           (iVar4 = (**(code **)(*local_160 + 0xb4))(local_160,local_180), -1 < iVar4)) {
          FUN_4540288a(&local_1a4,(int *)&local_150);
          local_1a0 = local_180;
          local_19c = local_174;
          local_8._0_1_ = 0x14;
          FUN_45409b0d((void *)(local_18c + 0x100),(XQATItem *)&local_1a4,(int *)&local_150);
          SysFreeString(local_1a4);
        }
        local_8._0_1_ = 0x10;
        if (local_160 != (int *)0x0) {
          (**(code **)(*local_160 + 8))(local_160);
        }
        local_8._0_1_ = 0xf;
        if (local_15c != (int *)0x0) {
          (**(code **)(*local_15c + 8))(local_15c);
        }
      }
      local_8._0_1_ = 0xe;
      if (local_14c != (int *)0x0) {
        (**(code **)(*local_14c + 8))(local_14c);
      }
    }
    local_8 = CONCAT31(local_8._1_3_,0xd);
    if (local_16c != (int *)0x0) {
      (**(code **)(*local_16c + 8))(local_16c);
    }
    VariantClear((VARIANTARG *)&local_1b4.n2);
    SysFreeString(local_17c);
    SysFreeString(local_170);
  }
  else {
    local_164 = (int *)0x0;
    local_128._0_4_ = 0xafa3c746;
    local_128.decVal.Hi32 = 0x4bac1d10;
    local_128._8_4_ = (undefined4 *)0xbb7f179b;
    local_128._12_4_ = 0xe1468e7f;
    local_8._0_1_ = 6;
    iVar4 = (**(code **)*local_178)(local_178,&local_128,&local_164);
    if (-1 < iVar4) {
      local_168 = (BSTR)0x0;
      local_8._0_1_ = 7;
      FUN_45405fbb(&local_168,&DAT_4545d948);
      local_8 = CONCAT31(local_8._1_3_,8);
      local_118 = '\0';
      FUN_45429f70(local_117,0,0x103);
      DVar5 = GetTempPathA(0x104,&local_118);
      if (DVar5 == 0) {
        _strcpy_s(&local_118,0x104,"c:\\temp\\");
      }
      FUN_454028b9(&local_154,&local_118);
      local_8._0_1_ = 9;
      iVar4 = FUN_45404f92(&local_150,local_154);
      if (iVar4 < 0) {
LAB_45422b9a:
                    /* WARNING: Subroutine does not return */
        FUN_45401d09(iVar4);
      }
      local_8._0_1_ = 8;
      SysFreeString(local_154);
      FUN_454028b9(&local_154,"Claricom\\");
      local_8._0_1_ = 10;
      iVar4 = FUN_45404f92(&local_150,local_154);
      if (iVar4 < 0) goto LAB_45422b9a;
      local_8._0_1_ = 8;
      SysFreeString(local_154);
      iVar4 = FUN_45404f92(&local_150,local_168);
      if (iVar4 < 0) goto LAB_45422b9a;
      if ((local_164 == (int *)0x0) ||
         (iVar4 = (**(code **)(*local_164 + 0xc))
                            (local_164,local_150,local_1e4._0_4_,local_1e4.decVal.Hi32,
                             local_1e4._8_4_,local_1e4._12_4_,local_1c4._0_4_,local_1c4.decVal.Hi32,
                             local_1c4._8_4_,local_1c4._12_4_,local_1d4._0_4_,local_1d4.decVal.Hi32,
                             local_1d4._8_4_,local_1d4._12_4_), param_2 = local_158, -1 < iVar4)) {
        SysFreeString((BSTR)0x0);
        SysFreeString(local_168);
        local_8._0_1_ = 5;
        if (local_164 != (int *)0x0) {
          (**(code **)(*local_164 + 8))(local_164);
        }
        goto LAB_45422cac;
      }
      SysFreeString((BSTR)0x0);
      SysFreeString(local_168);
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    if (local_164 != (int *)0x0) {
      (**(code **)(*local_164 + 8))(local_164);
    }
  }
  VariantClear((VARIANTARG *)&local_1d4.n2);
  VariantClear((VARIANTARG *)&local_1c4.n2);
  VariantClear((VARIANTARG *)&local_1e4.n2);
LAB_4542315c:
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_178 != (int *)0x0) {
    (**(code **)(*local_178 + 8))(local_178);
  }
  SysFreeString(local_150);
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  FUN_4542a957();
  return;
}


