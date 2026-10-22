// Source: CLCiffConversion_Layout.dll @ 45412d87; thunk_FUN_45422419

void __fastcall thunk_FUN_45422419(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*param_1;
  if (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)param_1[1];
    for (; puVar2 != puVar1; puVar2 = puVar2 + 5) {
      SysFreeString((BSTR)*puVar2);
    }
    FID_conflict__free((void *)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  return;
}


