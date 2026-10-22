// Source: CLCSSmallBarcode.dll @ 4200aef7; FUN_4200aef7

void __fastcall FUN_4200aef7(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  *param_1 = CTTFFontManager::vftable;
  if (0 < (int)param_1[0x51f]) {
    do {
      FUN_4200c5b5(param_1,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)param_1[0x51f]);
  }
  iVar1 = 0;
  if (0 < (int)param_1[0x512]) {
    piVar2 = param_1 + 0x34;
    do {
      if (*piVar2 != 0) {
        DeleteObject((HGDIOBJ)*piVar2);
        *piVar2 = 0;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x36;
    } while (iVar1 < (int)param_1[0x512]);
  }
  _eh_vector_destructor_iterator_(param_1 + 2,0xd8,0x18,FUN_4200af65);
  return;
}


