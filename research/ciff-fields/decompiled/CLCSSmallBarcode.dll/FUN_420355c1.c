// Source: CLCSSmallBarcode.dll @ 420355c1; FUN_420355c1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_420355c1(void *this,int param_1,size_t param_2,undefined8 *param_3)

{
  void *this_00;
  int *piVar1;
  undefined4 uVar2;
  
  this_00 = (void *)FUN_42067914(0x14);
  piVar1 = (int *)0x0;
  if (this_00 != (void *)0x0) {
    piVar1 = FUN_42035574(this_00,param_1,param_2,param_3);
  }
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (*(int *)((int)this + 0xc) == 0) {
      *(int **)((int)this + 8) = piVar1;
    }
    else {
      *(int **)(*(int *)((int)this + 0xc) + 0x10) = piVar1;
    }
    *(int **)((int)this + 0xc) = piVar1;
    uVar2 = 0;
  }
  return uVar2;
}


