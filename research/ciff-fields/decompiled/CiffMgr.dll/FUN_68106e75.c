// Source: CiffMgr.dll @ 68106e75; FUN_68106e75

undefined4 FUN_68106e75(int *param_1,OLECHAR *param_2)

{
  int *this;
  LPCRITICAL_SECTION lpCriticalSection;
  HRESULT HVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = param_1;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x3e);
  EnterCriticalSection(lpCriticalSection);
  this = piVar3 + 0x13;
  FUN_68102644(this,param_2);
  FUN_681055f7(this);
  param_1 = (int *)0x0;
  HVar1 = CoCreateInstance((IID *)&DAT_68147924,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_681479e4,&param_1);
  if (-1 < HVar1) {
    piVar3 = piVar3 + 0x14;
    iVar2 = (**(code **)(*param_1 + 0x38))(param_1,piVar3,*this);
    if (iVar2 < 0) {
      FUN_68102644(this,L"EN-GB");
      *piVar3 = 0x809;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return 0;
}


