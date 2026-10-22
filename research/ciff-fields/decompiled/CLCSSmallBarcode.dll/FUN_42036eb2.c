// Source: CLCSSmallBarcode.dll @ 42036eb2; FUN_42036eb2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_42036eb2(void *this,int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  *(undefined4 *)this = 0;
  local_14[0] = 0;
  local_8 = 1;
  if (param_1 == (int *)0x0) {
LAB_42036f04:
    puVar2 = (undefined4 *)FUN_42067914(4);
    if (puVar2 == (undefined4 *)0x0) {
LAB_42036f18:
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = CLCSSmallBarcodeCalcs::vftable;
    }
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0xa8))(param_1,local_14);
    if (iVar1 < 0) goto LAB_42036f1c;
    if (local_14[0] != 3) goto LAB_42036f04;
    puVar2 = (undefined4 *)FUN_42067914(4);
    if (puVar2 == (undefined4 *)0x0) goto LAB_42036f18;
    *puVar2 = CLCSCode39BarcodeCalcs::vftable;
  }
  *(undefined4 **)this = puVar2;
LAB_42036f1c:
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return this;
}


