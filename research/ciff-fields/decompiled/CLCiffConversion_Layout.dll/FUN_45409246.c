// Source: CLCiffConversion_Layout.dll @ 45409246; FUN_45409246

void __fastcall FUN_45409246(int param_1)

{
  int *piVar1;
  
  SysFreeString(*(BSTR *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0xc) = 0;
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(param_1 + 8) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}


