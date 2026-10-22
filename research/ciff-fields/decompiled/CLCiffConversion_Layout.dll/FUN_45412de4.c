// Source: CLCiffConversion_Layout.dll @ 45412de4; FUN_45412de4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_45412de4(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = CCIFFConvertBase::vftable;
  FUN_45409f68(param_1 + 0x3a);
  SysFreeString((BSTR)param_1[0x39]);
  SysFreeString((BSTR)param_1[0x38]);
  piVar1 = (int *)param_1[0x37];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45407670(param_1 + 0x35);
  piVar1 = (int *)param_1[0x34];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  VariantClear((VARIANTARG *)(param_1 + 0x30));
  VariantClear((VARIANTARG *)(param_1 + 0x2c));
  VariantClear((VARIANTARG *)(param_1 + 0x28));
  VariantClear((VARIANTARG *)(param_1 + 0x24));
  VariantClear((VARIANTARG *)(param_1 + 0x20));
  FUN_45404cb7(param_1 + 0x1c);
  piVar1 = (int *)param_1[0x1b];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45402c5d(param_1 + 0x1a);
  FUN_45402c5d(param_1 + 0x19);
  piVar1 = (int *)param_1[0x18];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[0x17];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  SysFreeString((BSTR)param_1[0x16]);
  SysFreeString((BSTR)param_1[0x15]);
  SysFreeString((BSTR)param_1[0x12]);
  SysFreeString((BSTR)param_1[0x10]);
  piVar1 = (int *)param_1[0xf];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[0xe];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[0xd];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45412d96((int)(param_1 + 3));
  SysFreeString((BSTR)param_1[2]);
  return;
}


