// Source: CiffHelper.dll @ 4082d9f3; FUN_4082d9f3

void __cdecl FUN_4082d9f3(size_t param_1)

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
  FUN_40832047(local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  FUN_4082d44f((int *)local_14,&DAT_40860140);
}


