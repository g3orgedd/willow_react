// Source: CLCiffConversion_Layout.dll @ 45410952; Catch_All@45410952

void Catch_All_45410952(void)

{
  int unaff_EBP;
  int iVar1;
  
  for (iVar1 = *(int *)(unaff_EBP + -0x14); iVar1 != *(int *)(unaff_EBP + 0x10); iVar1 = iVar1 + 8)
  {
    SysFreeString(*(BSTR *)(iVar1 + 4));
  }
                    /* WARNING: Subroutine does not return */
  FUN_4542a8e0((int *)0x0,(byte *)0x0);
}


