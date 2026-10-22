// Source: CiffMgr.dll @ 681026d0; FUN_681026d0

undefined4 __thiscall FUN_681026d0(void *this,undefined4 *param_1)

{
  undefined4 uVar1;
  BSTR pOVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    pOVar2 = FUN_68102501(this);
    *param_1 = pOVar2;
    if ((pOVar2 == (BSTR)0x0) && (*(int *)this != 0)) {
      uVar1 = 0x8007000e;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


