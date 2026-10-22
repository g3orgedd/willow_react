// Source: CLCiffConversion_Layout.dll @ 4540993f; FUN_4540993f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_4540993f(XQATItem *param_1,XQATItem *param_2)

{
  undefined1 *puVar1;
  
  puVar1 = &LAB_45443526;
  if (param_1 != (XQATItem *)0x0) {
    CMFCRibbonInfo::XQAT::XQATItem::operator=(param_1,param_2);
    puVar1 = *(undefined1 **)(param_2 + 0xc);
    *(undefined1 **)(param_1 + 0xc) = puVar1;
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  return puVar1;
}


