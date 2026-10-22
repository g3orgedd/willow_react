// Source: CLCiffConversion_Layout.dll @ 4540d011; FUN_4540d011

void __thiscall FUN_4540d011(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = std::_Allocate<char>(param_1,(char *)0x0);
  FUN_4542a090((undefined8 *)pcVar3,*(undefined8 **)this,*(int *)((int)this + 4) - *(int *)this);
  iVar1 = *(int *)((int)this + 4);
  iVar2 = *(int *)this;
  if (*(int *)this != 0) {
    FID_conflict__free(*(void **)this);
  }
  *(char **)this = pcVar3;
  *(char **)((int)this + 8) = pcVar3 + param_1;
  *(char **)((int)this + 4) = pcVar3 + (iVar1 - iVar2);
  return;
}


