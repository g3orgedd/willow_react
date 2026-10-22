// Source: CLCiffConversion_Layout.dll @ 45412a39; FUN_45412a39

undefined4 * __fastcall FUN_45412a39(undefined4 *param_1)

{
  int *piVar1;
  
  FUN_45412654(param_1);
  *param_1 = CCIFFTextField::vftable;
  piVar1 = (int *)param_1[1];
  if ((piVar1 != (int *)0x0) && (param_1[1] = 0, piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return param_1;
}


