// Source: CLCiffConversion_Layout.dll @ 4541dc6a; FUN_4541dc6a

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void FUN_4541dc6a(int param_1,short param_2,undefined4 param_3,wchar_t *param_4)

{
  IUnknown *This;
  LPCSTR pCVar1;
  HRESULT HVar2;
  undefined ***pppuVar3;
  IID *riid;
  ULONG UVar4;
  char *****pppppcVar5;
  int *piVar6;
  int iVar7;
  IUnknown *This_00;
  void **in_stack_fffffe04;
  byte *pbVar8;
  void **ppvObject;
  void **ppvObject_00;
  undefined **local_1b4;
  HRESULT local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined **local_1a4;
  ULONG local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined **local_194;
  HRESULT local_190;
  undefined4 local_18c;
  undefined4 local_188;
  IUnknown *local_184;
  BSTR local_180 [2];
  MULTI_QI local_178;
  void *local_16c;
  undefined1 local_168 [12];
  int *local_15c;
  IID local_158;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_148 [24];
  char ****local_130 [5];
  uint local_11c;
  uint local_118 [68];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1a8;
  local_8 = 0x4541dc79;
  local_168._8_4_ = param_1;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_148,"CCiffConversion_Layout::Initialise");
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_4541e049(param_2,param_3,param_4);
  if (param_2 != 8) {
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_148,true,0);
    FUN_4541e041();
    return;
  }
  pCVar1 = FUN_45408515();
  FUN_45402a65(local_168 + 4,pCVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_45404db2(local_168 + 4,"CLCLSID.ini");
  local_178.pIID = (IID *)&DAT_45447d5c;
  pbVar8 = (byte *)0x0;
  local_178.pItf = (IUnknown *)0x0;
  local_178.hr = 0;
  HVar2 = CoCreateInstanceEx((IID *)&DAT_45447d4c,(IUnknown *)0x0,0x15,(COSERVERINFO *)0x0,1,
                             &local_178);
  This = local_178.pItf;
  if (HVar2 < 0) {
    pppuVar3 = &local_1b4;
    local_1b4 = _com_error::vftable;
    local_1ac = 0;
    local_1a8 = 0;
    local_1b0 = HVar2;
  }
  else if (local_178.hr < 0) {
    pppuVar3 = &local_194;
    local_194 = _com_error::vftable;
    local_18c = 0;
    local_188 = 0;
    local_190 = HVar2;
  }
  else {
    local_184 = local_178.pItf;
    if (local_178.pItf != (IUnknown *)0x0) {
      (*(local_178.pItf)->lpVtbl->AddRef)(local_178.pItf);
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    (*(local_178.pItf)->lpVtbl->Release)(local_178.pItf);
    riid = (IID *)FUN_454037db(local_168 + 4,0xff);
    ppvObject_00 = (void **)0x20;
    UVar4 = (*This->lpVtbl[1].AddRef)(This);
    FUN_45404047(local_168 + 4,-1);
    if (-1 < (int)UVar4) {
      ppvObject = &local_16c;
      local_16c = (void *)0x0;
      UVar4 = (*This->lpVtbl[1].Release)(This);
      FUN_4541534f(UVar4);
      This_00 = This;
      if (local_16c != (void *)0x0) {
        local_168._0_4_ = 0;
        HVar2 = (*This->lpVtbl[2].QueryInterface)(This,(IID *)local_168,ppvObject);
        FUN_4541534f(HVar2);
        while (This_00 = (IUnknown *)0x0, (local_168._0_4_ & 2) == 0) {
          FUN_45429f70(local_118,0,0xff);
          UVar4 = (*This->lpVtbl[3].AddRef)(This);
          FUN_4541534f(UVar4);
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_130,
                     (char *)local_118);
          local_8._0_1_ = 4;
          FUN_454028ee(local_180,L"");
          local_8._0_1_ = 5;
          pppppcVar5 = local_130;
          if (0xf < local_11c) {
            pppppcVar5 = (char *****)local_130[0];
          }
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
          basic_string<char,std::char_traits<char>,std::allocator<char>_>
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                     &stack0xfffffe04,(char *)pppppcVar5);
          piVar6 = (int *)FUN_4541f405();
          local_8 = CONCAT31(local_8._1_3_,4);
          SysFreeString(local_180[0]);
          if (piVar6 == (int *)0x0) {
            local_15c = piVar6;
            HVar2 = CoCreateInstance(&local_158,(LPUNKNOWN)0x0,0x15,(IID *)&DAT_45447e1c,&local_15c)
            ;
            if (-1 < HVar2) {
              piVar6 = local_15c;
              if (local_15c != (int *)0x0) {
                (**(code **)(*local_15c + 4))(local_15c);
              }
              iVar7 = FUN_45421a24(piVar6);
              FUN_4541534f(iVar7);
              (**(code **)(*local_15c + 8))(local_15c);
              goto LAB_4541df6b;
            }
          }
          else {
LAB_4541df6b:
            (*This->lpVtbl[2].QueryInterface)(This,(IID *)local_168,in_stack_fffffe04);
          }
          local_8 = CONCAT31(local_8._1_3_,3);
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy
                    ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_130,
                     true,0);
        }
        HVar2 = (*This->lpVtbl[3].QueryInterface)(This,riid,ppvObject_00);
        FUN_4541534f(HVar2);
        local_184 = This_00;
        if (This != (IUnknown *)0x0) {
          (*This->lpVtbl->Release)(This);
        }
      }
      FUN_4541ec43();
      local_8 = CONCAT31(local_8._1_3_,2);
      *(undefined1 *)(local_168._8_4_ + 0x4dc) = 1;
      if (This_00 != (IUnknown *)0x0) {
        (*This_00->lpVtbl->Release)(This_00);
      }
      FUN_45402c5d((int *)(local_168 + 4));
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_148,true,0);
      FUN_4541e041();
      return;
    }
    local_19c = 0;
    pppuVar3 = &local_1a4;
    local_198 = 0;
    local_1a4 = _com_error::vftable;
    pbVar8 = &DAT_4545636c;
    local_1a0 = UVar4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_4542a8e0((int *)pppuVar3,pbVar8);
}


