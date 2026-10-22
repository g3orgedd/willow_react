// Source: CLARiSOFT.exe @ 00eca369; FUN_00eca369

void __cdecl FUN_00eca369(size_t param_1)

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
  FUN_00ecf822(local_14,&local_8);
  local_14[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  FUN_00ec9dc5((int *)local_14,&DAT_00f31594);
}


