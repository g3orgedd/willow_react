// Source: CLCiffConversion_Layout.dll @ 45406e39; FUN_45406e39

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_45406e39(void *this,undefined4 *param_1,undefined4 *param_2)

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
  local_8 = 0x45406e45;
  local_14[0] = 0;
  (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,local_14);
  iVar3 = 1;
  iVar2 = local_14[0];
  if (0 < local_14[0]) {
    do {
      if ((*(int *)((int)this + 0x30) == 0) || (*(int *)((int)this + 0x30) == iVar3)) {
        param_1 = (undefined4 *)0x0;
        FUN_45429f70((uint *)&local_24,0,0x10);
        VariantInit(&local_24);
        local_8 = 0;
        (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,iVar3,&local_24);
        (*(code *)**(undefined4 **)local_24.n1._8_4_)(local_24.n1._8_4_,&DAT_45447c3c,&param_1);
        FUN_4541222d(param_2,(int *)*param_2,&param_1);
        local_8 = 0xffffffff;
        VariantClear(&local_24);
        iVar2 = local_14[0];
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar2);
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


