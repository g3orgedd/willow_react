// Source: CLCiffConversion_Data.dll @ 45011457; FUN_45011457

void __fastcall FUN_45011457(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  _com_issue_error(-0x7fffbffd);
}


