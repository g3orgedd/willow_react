// Source: CLCiffConversion_Layout.dll @ 45406d62; FUN_45406d62

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_45406d62(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  VARIANTARG local_28;
  undefined4 *local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x18;
  local_8 = 0x45406d6e;
  local_14[0] = 0;
  uVar2 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,local_14);
  iVar4 = 0;
  if (0 < local_14[0]) {
    do {
      param_1 = (int *)0x0;
      local_8 = 0;
      FUN_45429f70((uint *)&local_28,0,0x10);
      VariantInit(&local_28);
      iVar4 = iVar4 + 1;
      local_8 = CONCAT31(local_8._1_3_,1);
      (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,iVar4,&local_28);
      (*(code *)**(undefined4 **)local_28.n1._8_4_)(local_28.n1._8_4_,&DAT_45447c4c,&param_1);
      puVar3 = (undefined4 *)FUN_454298b4(8);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = TCIFFField<ICiffField>::vftable;
        puVar3[1] = 0;
        FUN_45404ce5(puVar3 + 1,(int *)&param_1);
      }
      local_18 = puVar3;
      FUN_4541222d(param_2,(int *)*param_2,&local_18);
      VariantClear(&local_28);
      local_8 = 0xffffffff;
      uVar2 = 0;
      if (param_1 != (int *)0x0) {
        uVar2 = (**(code **)(*param_1 + 8))(param_1);
      }
    } while (iVar4 < local_14[0]);
  }
  return CONCAT31((int3)((uint)uVar2 >> 8),1);
}


