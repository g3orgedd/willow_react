// Source: CLCSSmallBarcode.dll @ 42027391; FUN_42027391

void __fastcall FUN_42027391(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = ZipherRendering::vftable;
  piVar1 = (int *)param_1[3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}


