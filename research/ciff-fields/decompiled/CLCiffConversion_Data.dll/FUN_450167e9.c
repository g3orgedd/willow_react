// Source: CLCiffConversion_Data.dll @ 450167e9; FUN_450167e9

int __thiscall FUN_450167e9(void *this,int param_1)

{
  code *pcVar1;
  int iVar2;
  
  if (param_1 < *(int *)((int)this + 8)) {
    return *(int *)this + param_1 * 4;
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pcVar1 = (code *)swi(3);
  iVar2 = (*pcVar1)();
  return iVar2;
}


