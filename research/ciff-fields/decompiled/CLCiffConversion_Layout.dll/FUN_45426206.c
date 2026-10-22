// Source: CLCiffConversion_Layout.dll @ 45426206; FUN_45426206

int __thiscall FUN_45426206(void *this,int param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((-1 < param_1) && (param_1 < *(int *)((int)this + 8))) {
    return *(int *)((int)this + 4) + param_1 * 4;
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pcVar1 = (code *)swi(3);
  iVar2 = (*pcVar1)();
  return iVar2;
}


