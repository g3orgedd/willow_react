// Source: CLCiffConversion_Data.dll @ 4500561c; FUN_4500561c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_4500561c(void *this,int *param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 != 0) {
    *(undefined ***)this = &PTR_4503dbbc;
    FUN_450054d2((undefined4 *)((int)this + 0x10));
  }
  *(undefined ***)((int)this + *(int *)(*(int *)this + 4)) = CCIFFFieldDataReplacement::vftable;
  *(int *)(*(int *)(*(int *)this + 4) + -4 + (int)this) = *(int *)(*(int *)this + 4) + -0x10;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = FUN_4500790c();
  *(undefined4 *)((int)this + 4) = uVar1;
  piVar2 = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  FUN_45006518(this,piVar2);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return this;
}


