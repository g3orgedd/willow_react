// Source: CLCiffConversion_Data.dll @ 4502682d; FUN_4502682d

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 FUN_4502682d(undefined4 param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  int iVar3;
  DWORD *_Memory;
  DWORD DVar4;
  
  if (param_2 == 1) {
    bVar1 = FUN_4502eb25();
    if (CONCAT31(extraout_var,bVar1) != 0) {
      iVar3 = FUN_45027a91();
      if (iVar3 != 0) {
        FUN_45031d42();
        DAT_45056f9c = GetCommandLineA();
        DAT_4505535c = FUN_45031cb5();
        iVar3 = FUN_45031603();
        if (-1 < iVar3) {
          iVar3 = FUN_45031909();
          if (-1 < iVar3) {
            iVar3 = FUN_45031b38();
            if (-1 < iVar3) {
              iVar3 = FUN_4502dc47(0);
              if (iVar3 == 0) {
                DAT_45055358 = DAT_45055358 + 1;
                goto LAB_45026994;
              }
            }
          }
          __ioterm();
        }
        __mtterm();
      }
      FUN_4502eb3a();
    }
LAB_4502684a:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_45055358 < 1) goto LAB_4502684a;
      DAT_45055358 = DAT_45055358 + -1;
      if (DAT_450553cc == 0) {
        __cexit();
      }
      FUN_4502db0f();
      if (param_3 == 0) {
        __ioterm();
        __mtterm();
        FUN_4502eb3a();
      }
      FUN_4502690f();
    }
    else if (param_2 == 2) {
      iVar3 = FUN_4502ec32(DAT_45051e20);
      if (iVar3 == 0) {
        _Memory = FUN_4502dee1(1,0x3bc);
        if (_Memory != (DWORD *)0x0) {
          iVar3 = FUN_4502ec51(DAT_45051e20,_Memory);
          if (iVar3 != 0) {
            FUN_450279de((int)_Memory,0);
            DVar4 = GetCurrentThreadId();
            *_Memory = DVar4;
            _Memory[1] = 0xffffffff;
            goto LAB_45026994;
          }
          FID_conflict__free(_Memory);
        }
        goto LAB_4502684a;
      }
    }
    else if (param_2 == 3) {
      FUN_45027921((void *)0x0);
    }
LAB_45026994:
    uVar2 = 1;
  }
  return uVar2;
}


