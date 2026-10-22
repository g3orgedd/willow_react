// Source: CLCiffConversion_Layout.dll @ 454066cc; FUN_454066cc

int __thiscall FUN_454066cc(void *this,int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  if (*(int *)this != iVar1) {
    *param_1 = 0;
    piVar2 = *(int **)this;
    *(int *)this = iVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  return *(int *)this;
}


