// Source: CLCSBarcodeField.dll @ 41460343; FUN_41460343

void __cdecl FUN_41460343(size_t param_1)

{
  int iVar1;
  void *pvVar2;
  undefined **local_14 [3];
  char *local_8;
  
  do {
    pvVar2 = _malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return;
    }
    iVar1 = __callnewh(param_1);
  } while (iVar1 != 0);
  local_8 = "bad allocation";
  FUN_414657d7(local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  FUN_41461e6b((int *)local_14,&DAT_414a6b44);
}


