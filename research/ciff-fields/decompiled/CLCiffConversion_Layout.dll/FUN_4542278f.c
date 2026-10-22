// Source: CLCiffConversion_Layout.dll @ 4542278f; FUN_4542278f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4542278f(void *this,undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  puVar2 = *(undefined4 **)((int)this + 4);
  if ((param_1 < puVar2) && (*(undefined4 **)this <= param_1)) {
    iVar1 = *(int *)this;
    if (puVar2 == *(undefined4 **)((int)this + 8)) {
      FUN_45422352(this,1);
    }
    puVar2 = *(undefined4 **)((int)this + 4);
    if (puVar2 == (undefined4 *)0x0) goto LAB_454227f5;
    piVar3 = *(int **)(*(int *)this + ((int)param_1 - iVar1 >> 2) * 4);
  }
  else {
    if (puVar2 == *(undefined4 **)((int)this + 8)) {
      FUN_45422352(this,1);
    }
    puVar2 = *(undefined4 **)((int)this + 4);
    if (puVar2 == (undefined4 *)0x0) goto LAB_454227f5;
    piVar3 = (int *)*param_1;
  }
  *puVar2 = piVar3;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(piVar3);
  }
LAB_454227f5:
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  return;
}


