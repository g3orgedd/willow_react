// Source: CLCiffConversion_Layout.dll @ 4540d124; FUN_4540d124

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4540d124(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = std::_Allocate<char>(param_1,(char *)0x0);
  FUN_4540a2d5(*(uint *)this,*(uint *)((int)this + 4),pcVar3);
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


