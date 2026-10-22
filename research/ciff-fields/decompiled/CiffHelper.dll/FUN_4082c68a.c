// Source: CiffHelper.dll @ 4082c68a; FUN_4082c68a

void __thiscall FUN_4082c68a(void *this,undefined4 param_1,int param_2)

{
  int iVar1;
  wchar_t wVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)((int)this + 0xa8);
  wVar2 = (wchar_t)param_1;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      if (param_2 != 0) {
        FUN_4082b6e2(this,0x1e);
      }
      if ((wVar2 != L'\'') && (wVar2 != L'\0')) {
        FUN_4082b6e2(this,wVar2);
        return;
      }
      *(undefined4 *)((int)this + 0xa8) = 2;
      return;
    }
    if (iVar1 != 2) {
      if (iVar1 == 3) {
        uVar3 = FUN_4082bb91(this,param_1);
      }
      else if (iVar1 == 4) {
        uVar3 = FUN_4082b9fd(this,param_1);
      }
      else {
        if (iVar1 != 5) {
          return;
        }
        uVar3 = FUN_4082bc05(this,param_1);
      }
      goto LAB_4082c701;
    }
  }
  uVar3 = FUN_4082bd46(this,wVar2);
LAB_4082c701:
  *(undefined4 *)((int)this + 0xa8) = uVar3;
  return;
}


