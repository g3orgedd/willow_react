// Source: CLCiffConversion_Data.dll @ 45004281; FUN_45004281

void * __thiscall FUN_45004281(void *this,void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = FUN_45003e6a(this);
  if ((char)uVar1 != '\0') {
    if (*(int *)this < 1) {
      iVar2 = FUN_45022828(*(uint *)this);
    }
    else {
      iVar2 = 0x15180 - *(int *)this;
    }
  }
  FUN_45001fa9(param_1,iVar2 / 0xe10,(iVar2 % 0xe10) / 0x3c);
  return param_1;
}


