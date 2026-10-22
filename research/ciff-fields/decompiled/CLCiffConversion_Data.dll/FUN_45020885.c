// Source: CLCiffConversion_Data.dll @ 45020885; FUN_45020885

void __thiscall FUN_45020885(void *this,undefined4 param_1,int param_2)

{
  int iVar1;
  wchar_t wVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)((int)this + 0xa8);
  wVar2 = (wchar_t)param_1;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      if (param_2 != 0) {
        FUN_4501f8dd(this,0x1e);
      }
      if ((wVar2 != L'\'') && (wVar2 != L'\0')) {
        FUN_4501f8dd(this,wVar2);
        return;
      }
      *(undefined4 *)((int)this + 0xa8) = 2;
      return;
    }
    if (iVar1 != 2) {
      if (iVar1 == 3) {
        uVar3 = FUN_4501fd8c(this,param_1);
      }
      else if (iVar1 == 4) {
        uVar3 = FUN_4501fbf8(this,param_1);
      }
      else {
        if (iVar1 != 5) {
          return;
        }
        uVar3 = FUN_4501fe00(this,param_1);
      }
      goto LAB_450208fc;
    }
  }
  uVar3 = FUN_4501ff41(this,wVar2);
LAB_450208fc:
  *(undefined4 *)((int)this + 0xa8) = uVar3;
  return;
}


