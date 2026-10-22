// Source: CLCiffConversion_Layout.dll @ 45408886; Catch_All@45408886

void Catch_All_45408886(void)

{
  int unaff_EBP;
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(unaff_EBP + -0x14); puVar1 != *(undefined4 **)(unaff_EBP + 0x10);
      puVar1 = puVar1 + 5) {
    SysFreeString((BSTR)*puVar1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_4542a8e0((int *)0x0,(byte *)0x0);
}


