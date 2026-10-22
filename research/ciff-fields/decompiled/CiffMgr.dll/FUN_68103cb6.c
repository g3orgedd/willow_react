// Source: CiffMgr.dll @ 68103cb6; FUN_68103cb6

LPCRITICAL_SECTION __fastcall FUN_68103cb6(LPCRITICAL_SECTION param_1)

{
  DWORD DVar1;
  
  FUN_68132710((uint *)param_1,0,0x18);
  DVar1 = FUN_681043fa(param_1);
  if (-1 < (int)DVar1) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_681024d6(DVar1);
}


