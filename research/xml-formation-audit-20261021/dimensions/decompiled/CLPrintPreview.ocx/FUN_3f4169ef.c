// Source: CLPrintPreview.ocx @ 3f4169ef; FUN_3f4169ef

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_3f4169ef(int param_1)

{
  LPVOID *ppv;
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  _union_2683 *pvarg;
  BSTR pOVar4;
  BSTR pOVar5;
  _union_2683 local_5c;
  _union_2683 local_4c;
  _union_2683 local_3c;
  _union_2683 local_2c;
  int local_1c;
  LPVOID *local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x3f4169fb;
  pOVar5 = *(BSTR *)(param_1 + 0xe8);
  local_14 = param_1;
  if (pOVar5 != (BSTR)0x0) {
    (**(code **)(*(int *)pOVar5 + 4))(pOVar5);
  }
  pOVar4 = *(BSTR *)(param_1 + 0xe0);
  if (pOVar4 != (BSTR)0x0) {
    (**(code **)(*(int *)pOVar4 + 4))(pOVar4);
  }
  uVar2 = FUN_3f41b6ef((void *)(param_1 + 0x1ec),pOVar4,pOVar5);
  *(undefined4 *)(param_1 + 0x1e8) = uVar2;
  local_18 = (LPVOID *)(param_1 + 0xd8);
  if (*local_18 == (LPVOID)0x0) {
    CoCreateInstance((IID *)&DAT_3f441258,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_3f44335c,local_18);
  }
  ppv = (LPVOID *)(param_1 + 0xdc);
  if (*ppv == (LPVOID)0x0) {
    CoCreateInstance((IID *)&DAT_3f441268,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_3f44336c,ppv);
    local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
    FUN_3f4157be(&local_3c,(int *)(param_1 + 0x128));
    local_8 = 0;
    (**(code **)(*(int *)*ppv + 0x24))
              (*ppv,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,local_3c._12_4_);
    VariantClear((VARIANTARG *)&local_3c.n2);
  }
  FUN_3f4272e0((uint *)&local_2c,0,0x10);
  VariantInit((VARIANTARG *)&local_2c.n2);
  local_8 = 1;
  if (local_2c.n2.vt != 3) {
    iVar3 = VariantClear((VARIANTARG *)&local_2c.n2);
    if (iVar3 < 0) goto LAB_3f416aeb;
    local_2c.n2.vt = 3;
  }
  local_2c._8_4_ = 1;
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"CS Database Resolve");
  local_8._0_1_ = 2;
  (**(code **)(*(int *)*local_18 + 0x20))
            (*local_18,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,local_3c._12_4_,&local_2c)
  ;
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"CS Field Resolve");
  local_8._0_1_ = 3;
  (**(code **)(*(int *)*local_18 + 0x20))
            (*local_18,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,local_3c._12_4_,&local_2c)
  ;
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  FUN_3f4157be(&local_2c,(int *)(local_14 + 0x10c));
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"Database");
  local_8._0_1_ = 4;
  (**(code **)(*(int *)*local_18 + 0x20))
            (*local_18,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,local_3c._12_4_,&local_2c)
  ;
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  FUN_3f4157be(&local_2c,(int *)(local_14 + 0x110));
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"ProductCode");
  local_8._0_1_ = 5;
  (**(code **)(*(int *)*local_18 + 0x20))
            (*local_18,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,local_3c._12_4_,&local_2c)
  ;
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  FUN_3f407785(&local_2c,L"Print Preview");
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"ConversionRequestSource");
  local_8._0_1_ = 6;
  (**(code **)(*(int *)*local_18 + 0x20))
            (*local_18,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,local_3c._12_4_,&local_2c)
  ;
  local_8 = CONCAT31(local_8._1_3_,1);
  VariantClear((VARIANTARG *)&local_3c.n2);
  if (local_2c.n2.vt != 3) {
    iVar3 = VariantClear((VARIANTARG *)&local_2c.n2);
    if (iVar3 < 0) {
LAB_3f416aeb:
                    /* WARNING: Subroutine does not return */
      FUN_3f4036fd(iVar3);
    }
    local_2c.n2.vt = 3;
  }
  local_2c._8_4_ = 1;
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"CS Cull");
  local_8._0_1_ = 7;
  (**(code **)(**(int **)(local_14 + 0xdc) + 0x20))
            (*(int **)(local_14 + 0xdc),local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
             local_3c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"CS Resolution Adjust");
  local_8._0_1_ = 8;
  (**(code **)(**(int **)(local_14 + 0xdc) + 0x20))
            (*(int **)(local_14 + 0xdc),local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
             local_3c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"CS Font Convert");
  local_8._0_1_ = 9;
  (**(code **)(**(int **)(local_14 + 0xdc) + 0x20))
            (*(int **)(local_14 + 0xdc),local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
             local_3c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"CS Resolve Field Width");
  local_8._0_1_ = 10;
  (**(code **)(**(int **)(local_14 + 0xdc) + 0x20))
            (*(int **)(local_14 + 0xdc),local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
             local_3c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  iVar3 = local_14;
  (**(code **)(**(int **)(local_14 + 0x124) + 0x4c))(*(int **)(local_14 + 0x124),&local_1c);
  if (local_1c != 0) {
    local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
    FUN_3f407785(&local_3c,L"CS Field Order");
    piVar1 = *(int **)(iVar3 + 0xdc);
    local_8._0_1_ = 0xb;
    (**(code **)(*piVar1 + 0x20))
              (piVar1,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,local_3c._12_4_,&local_2c);
    local_8._0_1_ = 1;
    VariantClear((VARIANTARG *)&local_3c.n2);
    iVar3 = local_14;
  }
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"CS Position");
  local_8._0_1_ = 0xc;
  (**(code **)(**(int **)(iVar3 + 0xdc) + 0x20))
            (*(int **)(iVar3 + 0xdc),local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
             local_3c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"CS Add Tab Fields");
  local_8._0_1_ = 0xd;
  (**(code **)(**(int **)(local_14 + 0xdc) + 0x20))
            (*(int **)(local_14 + 0xdc),local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
             local_3c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"CS Tag");
  local_8._0_1_ = 0xe;
  (**(code **)(**(int **)(local_14 + 0xdc) + 0x20))
            (*(int **)(local_14 + 0xdc),local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
             local_3c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_3c,L"CS RTBF2LOGO");
  local_8._0_1_ = 0xf;
  (**(code **)(**(int **)(local_14 + 0xdc) + 0x20))
            (*(int **)(local_14 + 0xdc),local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
             local_3c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_3c.n2);
  iVar3 = local_14;
  if (*(int *)(local_14 + 0x1a4) == 0) {
    local_3c._8_4_ = 0;
    local_3c.n2.vt = 3;
    local_8._0_1_ = 0x14;
    local_5c._0_4_ = local_5c._0_4_ & 0xffff0000;
    FUN_3f407785(&local_5c,L"CS Demo Field");
    piVar1 = *(int **)(iVar3 + 0xdc);
    local_8._0_1_ = 0x15;
    (**(code **)(*piVar1 + 0x20))
              (piVar1,local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,local_5c._12_4_,&local_3c);
    local_8._0_1_ = 0x14;
    VariantClear((VARIANTARG *)&local_5c.n2);
    local_5c._0_4_ = local_5c._0_4_ & 0xffff0000;
    FUN_3f407785(&local_5c,L"CS Demo Field");
    local_8 = CONCAT31(local_8._1_3_,0x16);
    (**(code **)(*(int *)*local_18 + 0x20))
              (*local_18,local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,local_5c._12_4_,
               &local_3c);
    VariantClear((VARIANTARG *)&local_5c.n2);
    pvarg = &local_3c;
  }
  else {
    local_3c._0_4_ = (uint)local_3c.n2.wReserved1 << 0x10;
    FUN_3f407785(&local_3c,L"CS Demo Field");
    piVar1 = *(int **)(iVar3 + 0xdc);
    local_8._0_1_ = 0x10;
    (**(code **)(*piVar1 + 0x20))
              (piVar1,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,local_3c._12_4_,&local_2c);
    local_8._0_1_ = 1;
    VariantClear((VARIANTARG *)&local_3c.n2);
    local_3c._0_4_ = local_3c._0_4_ & 0xffff0000;
    FUN_3f407785(&local_3c,L"CS Demo Field");
    local_8._0_1_ = 0x11;
    (**(code **)(*(int *)*local_18 + 0x20))
              (*local_18,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,local_3c._12_4_,
               &local_2c);
    local_8._0_1_ = 1;
    VariantClear((VARIANTARG *)&local_3c.n2);
    local_5c._0_4_ = (uint)local_5c.n2.wReserved1 << 0x10;
    FUN_3f407785(&local_5c,L"CS Field Order");
    local_3c._8_4_ = 0;
    local_3c.n2.vt = 3;
    local_8 = CONCAT31(local_8._1_3_,0x13);
    (**(code **)(**(int **)(local_14 + 0xdc) + 0x20))
              (*(int **)(local_14 + 0xdc),local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,
               local_5c._12_4_,&local_3c);
    VariantClear((VARIANTARG *)&local_3c.n2);
    pvarg = &local_5c;
  }
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&pvarg->n2);
  FUN_3f407785(&local_2c,L"Print Preview");
  local_5c._0_4_ = local_5c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_5c,L"ConversionRequestSource");
  local_8._0_1_ = 0x17;
  (**(code **)(**(int **)(local_14 + 0xdc) + 0x20))
            (*(int **)(local_14 + 0xdc),local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,
             local_5c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_5c.n2);
  iVar3 = local_14;
  FUN_3f415827(&local_2c,*(int **)(local_14 + 0xe4));
  local_5c._0_4_ = local_5c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_5c,L"CapsFile Pointer");
  local_8._0_1_ = 0x18;
  (**(code **)(**(int **)(iVar3 + 0xdc) + 0x20))
            (*(int **)(iVar3 + 0xdc),local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,
             local_5c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_5c.n2);
  iVar3 = local_14;
  FUN_3f415827(&local_2c,*(int **)(local_14 + 0xe8));
  local_5c._0_4_ = local_5c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_5c,L"CapsCoder Pointer");
  local_8._0_1_ = 0x19;
  (**(code **)(**(int **)(iVar3 + 0xdc) + 0x20))
            (*(int **)(iVar3 + 0xdc),local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,
             local_5c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_5c.n2);
  iVar3 = local_14;
  FUN_3f4157be(&local_2c,(int *)(local_14 + 0x120));
  local_5c._0_4_ = local_5c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_5c,L"CapsFormat");
  local_8._0_1_ = 0x1a;
  (**(code **)(**(int **)(iVar3 + 0xdc) + 0x20))
            (*(int **)(iVar3 + 0xdc),local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,
             local_5c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_5c.n2);
  iVar3 = local_14;
  FUN_3f4157be(&local_2c,(int *)(local_14 + 0x114));
  local_5c._0_4_ = local_5c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_5c,L"CapsFile");
  local_8._0_1_ = 0x1b;
  (**(code **)(**(int **)(iVar3 + 0xdc) + 0x20))
            (*(int **)(iVar3 + 0xdc),local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,
             local_5c._12_4_,&local_2c);
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_5c.n2);
  iVar3 = local_14;
  FUN_3f4157be(&local_2c,(int *)(local_14 + 0x118));
  local_5c._0_4_ = local_5c._0_4_ & 0xffff0000;
  FUN_3f407785(&local_5c,L"CapsCoder");
  local_8._0_1_ = 0x1c;
  (**(code **)(**(int **)(iVar3 + 0xdc) + 0x20))
            (*(int **)(iVar3 + 0xdc),local_5c._0_4_,local_5c.decVal.Hi32,local_5c._8_4_,
             local_5c._12_4_,&local_2c);
  local_8 = CONCAT31(local_8._1_3_,1);
  VariantClear((VARIANTARG *)&local_5c.n2);
  iVar3 = local_14;
  local_4c.n2.vt = 9;
  local_4c._8_4_ = *(int *)(local_14 + 0xe0);
  if ((int *)local_4c._8_4_ != (int *)0x0) {
    (**(code **)(*(int *)local_4c._8_4_ + 4))(local_4c._8_4_);
  }
  piVar1 = *(int **)(iVar3 + 0xd8);
  local_8 = CONCAT31(local_8._1_3_,0x1d);
  (**(code **)(*piVar1 + 0x1c))(piVar1,&local_4c);
  piVar1 = *(int **)(iVar3 + 0xdc);
  (**(code **)(*piVar1 + 0x1c))(piVar1,&local_4c);
  VariantClear((VARIANTARG *)&local_4c.n2);
  VariantClear((VARIANTARG *)&local_2c.n2);
  return;
}


