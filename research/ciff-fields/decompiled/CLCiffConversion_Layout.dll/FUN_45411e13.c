// Source: CLCiffConversion_Layout.dll @ 45411e13; FUN_45411e13

void __thiscall FUN_45411e13(void *this,undefined4 param_1,int param_2)

{
  int iVar1;
  wchar_t wVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)((int)this + 0xa8);
  wVar2 = (wchar_t)param_1;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      if (param_2 != 0) {
        FUN_45410a3f(this,0x1e);
      }
      if ((wVar2 != L'\'') && (wVar2 != L'\0')) {
        FUN_45410a3f(this,wVar2);
        return;
      }
      *(undefined4 *)((int)this + 0xa8) = 2;
      return;
    }
    if (iVar1 != 2) {
      if (iVar1 == 3) {
        uVar3 = FUN_45410eee(this,param_1);
      }
      else if (iVar1 == 4) {
        uVar3 = FUN_45410d5a(this,param_1);
      }
      else {
        if (iVar1 != 5) {
          return;
        }
        uVar3 = FUN_45410f62(this,param_1);
      }
      goto LAB_45411e8a;
    }
  }
  uVar3 = FUN_454110a3(this,wVar2);
LAB_45411e8a:
  *(undefined4 *)((int)this + 0xa8) = uVar3;
  return;
}


