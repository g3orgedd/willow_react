// Source: CLCSBlockTextField.dll @ 4181c864; FUN_4181c864

void __cdecl FUN_4181c864(size_t param_1)

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
  FUN_4182143d(local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  FUN_4181f507((int *)local_14,&DAT_41842094);
}


