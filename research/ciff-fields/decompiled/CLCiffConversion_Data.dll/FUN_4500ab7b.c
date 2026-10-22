// Source: CLCiffConversion_Data.dll @ 4500ab7b; FUN_4500ab7b

undefined4 * __fastcall FUN_4500ab7b(undefined4 *param_1)

{
  int *piVar1;
  
  FUN_4500a9c0(param_1);
  *param_1 = CCIFFTextField::vftable;
  piVar1 = (int *)param_1[1];
  if ((piVar1 != (int *)0x0) && (param_1[1] = 0, piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return param_1;
}


