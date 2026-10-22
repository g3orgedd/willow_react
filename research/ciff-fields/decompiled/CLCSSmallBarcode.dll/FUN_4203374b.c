// Source: CLCSSmallBarcode.dll @ 4203374b; FUN_4203374b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __fastcall FUN_4203374b(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_42027375(param_1);
  puVar2 = (undefined4 *)0x0;
  *param_1 = CQRBarcodeRender::vftable;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  puVar1 = (undefined4 *)FUN_42067914(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = FUN_42034e3a(puVar1);
  }
  param_1[0x3c] = puVar2;
  return param_1;
}


