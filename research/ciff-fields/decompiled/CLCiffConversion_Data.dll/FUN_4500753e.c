// Source: CLCiffConversion_Data.dll @ 4500753e; FUN_4500753e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4500753e(void *this,undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  VARIANTARG local_24;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_1;
  uStack_4 = 0x14;
  local_8 = 0x4500754a;
  local_14[0] = 0;
  (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,local_14);
  iVar3 = 1;
  iVar2 = local_14[0];
  if (0 < local_14[0]) {
    do {
      if ((*(int *)((int)this + 0x30) == 0) || (*(int *)((int)this + 0x30) == iVar3)) {
        param_1 = (undefined4 *)0x0;
        FUN_45001f8d((uint *)&local_24);
        local_8 = 0;
        (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,iVar3,&local_24);
        (*(code *)**(undefined4 **)local_24.n1._8_4_)(local_24.n1._8_4_,&DAT_4503d678,&param_1);
        FUN_4500503f(param_2,(int *)*param_2,&param_1);
        local_8 = 0xffffffff;
        VariantClear(&local_24);
        iVar2 = local_14[0];
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar2);
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


