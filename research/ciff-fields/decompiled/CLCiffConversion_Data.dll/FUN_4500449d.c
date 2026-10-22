// Source: CLCiffConversion_Data.dll @ 4500449d; FUN_4500449d

/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_4500449d(void)

{
  int iVar1;
  undefined8 *in_EAX;
  undefined8 *puVar2;
  int unaff_EBP;
  undefined8 *unaff_ESI;
  uint unaff_EDI;
  
  iVar1 = *(int *)(unaff_EBP + 0xc);
  *(undefined8 **)(unaff_EBP + -0x14) = in_EAX;
  if (iVar1 != 0) {
    puVar2 = unaff_ESI;
    if (7 < *(uint *)((int)unaff_ESI + 0x14)) {
      puVar2 = *(undefined8 **)unaff_ESI;
    }
    copy(in_EAX,puVar2,iVar1);
  }
  FUN_450046d9(unaff_ESI,'\x01',0);
  if (unaff_ESI != (undefined8 *)0x0) {
    *(undefined4 *)unaff_ESI = *(undefined4 *)(unaff_EBP + -0x14);
  }
  *(uint *)((int)unaff_ESI + 0x14) = unaff_EDI;
  *(int *)(unaff_ESI + 2) = iVar1;
  if (7 < unaff_EDI) {
    unaff_ESI = *(undefined8 **)unaff_ESI;
  }
  *(undefined2 *)((int)unaff_ESI + iVar1 * 2) = 0;
  return;
}


