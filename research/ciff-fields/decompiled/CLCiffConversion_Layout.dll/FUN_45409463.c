// Source: CLCiffConversion_Layout.dll @ 45409463; FUN_45409463

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_45409463(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)&LAB_4544294e;
  piVar1 = *(int **)((int)this + 4);
  if ((param_1 < piVar1) && (*(int **)this <= param_1)) {
    iVar2 = *(int *)this;
    if (piVar1 == *(int **)((int)this + 8)) {
      FUN_454093c5(this,1);
    }
    piVar3 = (int *)((((int)param_1 - iVar2) / 0x14) * 0x14 + *(int *)this);
    if (*(void **)((int)this + 4) != (void *)0x0) {
      piVar3 = FUN_454088e6(*(void **)((int)this + 4),piVar3);
    }
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x14;
  }
  else {
    if (piVar1 == *(int **)((int)this + 8)) {
      piVar3 = (int *)FUN_454093c5(this,1);
    }
    if (*(void **)((int)this + 4) != (void *)0x0) {
      piVar3 = FUN_454088e6(*(void **)((int)this + 4),param_1);
    }
    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 0x14;
  }
  return piVar3;
}


