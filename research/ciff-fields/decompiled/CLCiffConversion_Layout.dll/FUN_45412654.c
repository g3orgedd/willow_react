// Source: CLCiffConversion_Layout.dll @ 45412654; FUN_45412654

undefined4 * __fastcall FUN_45412654(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = TCIFFField<ICiffTextField>::vftable;
  param_1[1] = 0;
  piVar1 = (int *)param_1[1];
  if ((param_1[1] != 0) && (param_1[1] = 0, piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return param_1;
}


