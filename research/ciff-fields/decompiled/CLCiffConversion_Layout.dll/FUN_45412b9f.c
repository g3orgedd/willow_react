// Source: CLCiffConversion_Layout.dll @ 45412b9f; FUN_45412b9f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_45412b9f(void *this,int *param_1,int *param_2)

{
  int *piVar1;
  
  FUN_45402a2f(this,param_1);
  piVar1 = (int *)*param_2;
  *(int **)((int)this + 4) = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  *(undefined **)((int)this + 8) = PTR_DAT_4545d110;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined2 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  FUN_454077ad(this,param_1);
  FUN_45404ce5((void *)((int)this + 4),param_2);
  FUN_4541eb21(this);
  FUN_454160f3((int)this);
  return this;
}


