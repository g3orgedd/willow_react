// Source: CiffMgr.dll @ 68103e74; FUN_68103e74

void __cdecl FUN_68103e74(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  if (param_1 == 0xc) {
    iVar1 = -0x7ff8fff2;
  }
  else if ((param_1 == 0x16) || (param_1 == 0x22)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if (param_1 == 0x50) {
      return;
    }
    iVar1 = -0x7fffbffb;
  }
                    /* WARNING: Subroutine does not return */
  FUN_681024d6(iVar1);
}


