// Source: CLCiffConversion_Layout.dll @ 4542ef9b; FUN_4542ef9b

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 FUN_4542ef9b(undefined4 param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  int iVar3;
  DWORD *_Memory;
  DWORD DVar4;
  
  if (param_2 == 1) {
    bVar1 = FUN_45432019();
    if (CONCAT31(extraout_var,bVar1) != 0) {
      iVar3 = FUN_4543020f();
      if (iVar3 != 0) {
        FUN_4543a8ab();
        DAT_454627a0 = GetCommandLineA();
        DAT_45460b74 = FUN_4543a81e();
        iVar3 = FUN_4543a16c();
        if (-1 < iVar3) {
          iVar3 = FUN_4543a472();
          if (-1 < iVar3) {
            iVar3 = FUN_4543a6a1();
            if (-1 < iVar3) {
              iVar3 = FUN_454321b8(0);
              if (iVar3 == 0) {
                DAT_45460b70 = DAT_45460b70 + 1;
                goto LAB_4542f102;
              }
            }
          }
          __ioterm();
        }
        __mtterm();
      }
      FUN_4543202e();
    }
LAB_4542efb8:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (DAT_45460b70 < 1) goto LAB_4542efb8;
      DAT_45460b70 = DAT_45460b70 + -1;
      if (DAT_45460bc8 == 0) {
        __cexit();
      }
      FUN_45432080();
      if (param_3 == 0) {
        __ioterm();
        __mtterm();
        FUN_4543202e();
      }
      FUN_4542f07d();
    }
    else if (param_2 == 2) {
      iVar3 = FUN_4543969d(DAT_4545da34);
      if (iVar3 == 0) {
        _Memory = FUN_454375c4(1,0x3bc);
        if (_Memory != (DWORD *)0x0) {
          iVar3 = FUN_454396bc(DAT_4545da34,_Memory);
          if (iVar3 != 0) {
            FUN_4543015c((int)_Memory,0);
            DVar4 = GetCurrentThreadId();
            *_Memory = DVar4;
            _Memory[1] = 0xffffffff;
            goto LAB_4542f102;
          }
          FID_conflict__free(_Memory);
        }
        goto LAB_4542efb8;
      }
    }
    else if (param_2 == 3) {
      FUN_4543009f((void *)0x0);
    }
LAB_4542f102:
    uVar2 = 1;
  }
  return uVar2;
}


