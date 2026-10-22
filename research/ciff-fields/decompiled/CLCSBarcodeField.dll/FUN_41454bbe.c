// Source: CLCSBarcodeField.dll @ 41454bbe; FUN_41454bbe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall
FUN_41454bbe(void *this,int *param_1,undefined4 param_2,int *param_3,undefined4 param_4,
            undefined4 param_5)

{
  _union_2683 local_24;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined ***)this = CSymbologyChooser::vftable;
  *(undefined **)((int)this + 0x24) = PTR_DAT_414a9018;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined2 *)((int)this + 0x38) = param_3._0_2_;
  *(undefined4 *)((int)this + 0x40) = param_4;
  *(undefined4 *)((int)this + 0x44) = param_5;
  local_8._0_1_ = 5;
  local_8._1_3_ = 0;
  local_14 = this;
  (**(code **)(*param_1 + 0x1c))(param_1,(undefined4 *)((int)this + 0x30));
  *(undefined4 *)((int)this + 0x20) = 4;
  FUN_41460bf0((uint *)&local_24,0,0x10);
  VariantInit((VARIANTARG *)&local_24.n2);
  local_8 = CONCAT31(local_8._1_3_,6);
  (**(code **)(*param_1 + 0x480))(param_1,&local_24);
  if (local_24.n2.vt != 0) {
    CComQIPtr<>(&param_3,(undefined4 *)local_24._8_4_);
    FUN_41413c1e((void *)((int)this + 0x34),(int *)&param_3);
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 8))(param_3);
    }
  }
  *(undefined4 *)((int)this + 0x3c) = param_2;
  VariantClear((VARIANTARG *)&local_24.n2);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return this;
}


