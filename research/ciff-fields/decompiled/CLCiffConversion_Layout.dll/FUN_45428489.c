// Source: CLCiffConversion_Layout.dll @ 45428489; FUN_45428489

undefined4 __cdecl FUN_45428489(int *param_1,int *param_2)

{
  int *piVar1;
  
  if ((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) {
    piVar1 = (int *)*param_2;
    *param_1 = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_45401d09(-0x7fffbffb);
}


