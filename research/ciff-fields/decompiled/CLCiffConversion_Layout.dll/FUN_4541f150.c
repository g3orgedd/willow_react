// Source: CLCiffConversion_Layout.dll @ 4541f150; FUN_4541f150

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_4541f150(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  VARIANTARG local_2c;
  int local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  puVar1 = param_1;
  uStack_4 = 0x1c;
  local_8 = 0x4541f15c;
  puVar2 = (undefined4 *)0x0;
  local_18 = 0;
  (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,&local_18);
  iVar3 = 0;
  if (0 < local_18) {
    do {
      FUN_45429f70((uint *)&local_2c,0,0x10);
      VariantInit(&local_2c);
      local_8 = 0;
      iVar3 = iVar3 + 1;
      (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,iVar3,&local_2c);
      CComQIPtr<>(local_14,(undefined4 *)local_2c.n1._8_4_);
      param_1 = (undefined4 *)0x0;
      local_1c = 0;
      local_8._0_1_ = 1;
      (**(code **)(*local_14[0] + 0x34))(local_14[0],&param_1);
      (**(code **)(*local_14[0] + 0x80))(local_14[0],&local_1c);
      param_1 = (undefined4 *)((int)param_1 + local_1c);
      local_8 = (uint)local_8._1_3_ << 8;
      if ((int)puVar2 < (int)param_1) {
        puVar2 = param_1;
      }
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      local_8 = 0xffffffff;
      VariantClear(&local_2c);
    } while (iVar3 < local_18);
  }
  return puVar2;
}


