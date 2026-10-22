// Source: CLCSGraphicBasedField.dll @ 41c0b0c7; FUN_41c0b0c7

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_41c0b0c7(void *this,BSTR param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5,undefined4 *param_6,undefined4 param_7,IUnknown *param_8,
            undefined4 param_9,ULONG param_10,int *param_11,undefined4 param_12)

{
  IUnknown *This;
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar4;
  LPVOID *ppv;
  BSTR bstrString;
  int *piVar5;
  void **in_stack_fffffb60;
  undefined1 local_480 [4];
  VARIANTARG local_47c;
  _union_2683 local_46c;
  undefined4 local_45c;
  BSTR local_458;
  int *local_454;
  int *local_450;
  IUnknown *local_44c;
  int local_448;
  int local_444;
  void *local_440;
  int local_43c;
  IUnknown *local_438;
  BSTR local_434;
  int *local_430;
  char local_429;
  int *local_428;
  short local_424 [256];
  WCHAR local_224 [260];
  short local_1c [10];
  int local_8;
  undefined4 uStack_4;
  undefined4 uVar3;
  
  uStack_4 = 0x480;
  local_44c = param_8;
  local_46c._0_4_ = param_9;
  local_46c.decVal.Hi32 = param_10;
  local_46c._8_4_ = param_11;
  local_46c._12_4_ = param_12;
  local_8 = 0;
  local_440 = this;
  CComQIPtr<>(&local_428,param_3);
  CComQIPtr<>(&local_430,(undefined4 *)local_46c._8_4_);
  FUN_41c0168b((void *)((int)this + 0x48),(int *)&local_430);
  local_434 = (BSTR)0x0;
  local_8._0_1_ = 3;
  GetModuleFileNameW(DAT_41c44d34,local_224,0x104);
  FUN_41c1c6ba(local_224,local_1c,3,local_424,0x100,(short *)0x0,0,(short *)0x0,0);
  FUN_41c1c597(local_224,0x104,local_1c,local_424,(short *)0x0,(short *)0x0);
  FUN_41c016f7(&local_434,local_224);
  iVar2 = FUN_41c01911(&local_434,L"CLARiSOFT LOGO.BMP");
  if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    FUN_41c01b24(iVar2);
  }
  iVar2 = 0;
  FUN_41c0a4f9(&local_458,(GUID *)&DAT_41c30dd4);
  local_450 = (int *)0x0;
  local_8._0_1_ = 5;
  if (local_428 != (int *)0x0) {
    (**(code **)(*local_428 + 0x74))(local_428,local_458);
    (**(code **)(*local_428 + 0x5c))(local_428,&local_450);
    iVar2 = (**(code **)(*local_428 + 0x6c))(local_428,L"StaticGraphic");
  }
  FUN_41c18d70((uint *)&local_47c,0,0x10);
  VariantInit(&local_47c);
  local_8._0_1_ = 6;
  if (local_450 != (int *)0x0) {
    iVar2 = (**(code **)(*local_450 + 0x28))(local_450,0,0,1,0,&local_47c);
  }
  local_438 = (IUnknown *)0x0;
  local_8 = CONCAT31(local_8._1_3_,7);
  bstrString = local_434;
  if (((-1 < iVar2) && ((IUnknown *)local_47c.n1._8_4_ != (IUnknown *)0x0)) &&
     (ATL::AtlComQIPtrAssign(&local_438,(IUnknown *)local_47c.n1._8_4_,(_GUID *)&DAT_41c3090c),
     bstrString = local_434, local_438 != (IUnknown *)0x0)) {
    (*local_438->lpVtbl[7].QueryInterface)(local_438,(IID *)0x0,in_stack_fffffb60);
    This = local_438;
    SysStringLen(local_434);
    (*This->lpVtbl[0xc].Release)(This);
    (*local_438->lpVtbl[7].Release)(local_438);
    bVar1 = FUN_41c0bc21((int *)&local_430);
    uVar3 = CONCAT31(extraout_var,bVar1);
    bVar1 = FUN_41c0bc7d((int *)&local_430);
    FUN_41c0be4f((int *)&local_434,(void *)((int)this + 0x5c),CONCAT31(extraout_var_00,bVar1),uVar3)
    ;
    bstrString = local_434;
    (*local_438->lpVtbl[8].AddRef)(local_438);
  }
  if (local_428 != (int *)0x0) {
    (**(code **)(*local_428 + 0x9c))(local_428,bstrString);
  }
  iVar2 = FUN_41c12f74((int)this + 0x5c);
  local_43c = iVar2;
  local_444 = FUN_41c135b9((int)this + 0x5c);
  CComQIPtr<>(&local_454,param_6);
  local_448 = 0;
  local_8._0_1_ = 8;
  iVar4 = (**(code **)(*local_454 + 0x54))(local_454,&local_448);
  FUN_41c11a03(&local_45c);
  local_8 = CONCAT31(local_8._1_3_,9);
  if ((-1 < iVar4) && (local_448 == 0)) {
    piVar5 = local_430;
    if (local_430 != (int *)0x0) {
      (**(code **)(*local_430 + 4))(local_430);
    }
    local_444 = FUN_41c11afc(local_444,1.4013e-45,piVar5);
    piVar5 = local_430;
    if (local_430 != (int *)0x0) {
      (**(code **)(*local_430 + 4))(local_430);
    }
    iVar2 = FUN_41c11afc(iVar2,0.0,piVar5);
    local_43c = iVar2;
  }
  local_429 = FUN_41c0a9f8((int *)&local_430,local_44c,local_480,&local_43c,&local_429,local_448);
  if (local_428 != (int *)0x0) {
    (**(code **)(*local_428 + 0xb4))(local_428,iVar2);
    iVar2 = local_444;
    (**(code **)(*local_428 + 0xac))(local_428,local_444);
    (**(code **)(*local_428 + 0x84))(local_428,local_43c);
    (**(code **)(*local_428 + 0x7c))(local_428,iVar2);
    (**(code **)(*local_428 + 0xc0))(local_428,1);
    iVar4 = (**(code **)(*local_428 + 200))(local_428,0);
  }
  if (local_429 != '\0') {
    ppv = (LPVOID *)((int)local_440 + 0x54);
    if (*ppv == (LPVOID)0x0) {
      iVar4 = CoCreateInstance((IID *)&DAT_41c30d54,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_41c3178c,ppv);
    }
    if (iVar4 < 0) goto LAB_41c0b580;
    if (*ppv != (LPVOID)0x0) {
      local_46c.n2.vt = 9;
      local_46c._8_4_ = local_428;
      if (local_428 != (int *)0x0) {
        (**(code **)(*local_428 + 4))(local_428);
      }
      local_8._0_1_ = 10;
      iVar4 = (**(code **)(*(int *)*ppv + 0x40))(*ppv,&local_46c,2);
      local_8 = CONCAT31(local_8._1_3_,9);
      VariantClear((VARIANTARG *)&local_46c.n2);
    }
  }
  if ((-1 < iVar4) && (local_430 != (int *)0x0)) {
    local_440 = (void *)0x0;
    iVar2 = (**(code **)(*local_430 + 0x3c4))(local_430,&local_440);
    if ((-1 < iVar2) &&
       ((local_440 != (void *)0x0 &&
        (CComQIPtr<>(&local_44c,local_428), local_44c != (IUnknown *)0x0)))) {
      (*local_44c->lpVtbl->Release)(local_44c);
    }
  }
LAB_41c0b580:
  local_8._0_1_ = 8;
  FUN_41c11a0c(&local_45c);
  local_8._0_1_ = 7;
  if (local_454 != (int *)0x0) {
    (**(code **)(*local_454 + 8))(local_454);
  }
  local_8._0_1_ = 6;
  if (local_438 != (IUnknown *)0x0) {
    (*local_438->lpVtbl->Release)(local_438);
  }
  VariantClear(&local_47c);
  local_8._0_1_ = 4;
  if (local_450 != (int *)0x0) {
    (**(code **)(*local_450 + 8))(local_450);
  }
  SysFreeString(local_458);
  SysFreeString(bstrString);
  local_8._0_1_ = 1;
  if (local_430 != (int *)0x0) {
    (**(code **)(*local_430 + 8))(local_430);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_428 != (int *)0x0) {
    (**(code **)(*local_428 + 8))(local_428);
  }
  SysFreeString(param_1);
  FUN_41c1a062();
  return;
}


