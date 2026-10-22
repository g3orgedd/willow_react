// Source: CLCiffConversion_Data.dll @ 4501f7f0; Catch_All@4501f7f0

void Catch_All_4501f7f0(void)

{
  int unaff_EBP;
  int iVar1;
  
  for (iVar1 = *(int *)(unaff_EBP + -0x14); iVar1 != *(int *)(unaff_EBP + 0x10); iVar1 = iVar1 + 8)
  {
    SysFreeString(*(BSTR *)(iVar1 + 4));
  }
                    /* WARNING: Subroutine does not return */
  FUN_45022e41((int *)0x0,(byte *)0x0);
}


