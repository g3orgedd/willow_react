// Source: CLCiffConversion_Layout.dll @ 45409b0d; FUN_45409b0d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_45409b0d(void *this,XQATItem *param_1,int *param_2)

{
  BSTR local_28 [3];
  BSTR local_1c;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x45409b19;
  CMFCRibbonInfo::XQAT::XQATItem::operator=((XQATItem *)local_28,param_1);
  local_8 = 0;
  FUN_4540288a(&local_1c,param_2);
  local_8 = 1;
  FUN_45409870(this,local_18,(undefined4 *)0x0,(XQATItem *)local_28,(uint)DAT_45460734);
  SysFreeString(local_1c);
  SysFreeString(local_28[0]);
  return;
}


