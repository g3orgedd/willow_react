// Source: CLCSSmallBarcode.dll @ 420333ab; FUN_420333ab

void __thiscall FUN_420333ab(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  *(undefined1 *)((int)this + 0x121c) = 0;
  if (param_1 != 0) {
    do {
      iVar1 = *(int *)((int)this + 0x1218);
      if (iVar1 == 1) {
        iVar2 = FUN_42032039(this,&param_1);
      }
      else if (iVar1 == 2) {
        iVar2 = FUN_42032295(this,&param_1);
      }
      else if (iVar1 == 4) {
        iVar2 = FUN_420327ce(this,&param_1);
      }
      else if (iVar1 == 8) {
        iVar2 = FUN_420328df(this,&param_1);
      }
    } while (param_1 != 0);
    if (iVar2 != 0) {
      return;
    }
  }
  if (*(char *)((int)this + 0x121c) != '\0') {
    if (*(int *)((int)this + 0x1218) == 8) {
      FUN_420319a2(this,0x1d);
      *(undefined4 *)((int)this + 0x1218) = 1;
    }
    else {
      FUN_420319a2(this,0x1d);
    }
  }
  return;
}


