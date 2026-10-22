// Source: CLCiffConversion_Data.dll @ 45007476; FUN_45007476

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_45007476(undefined4 *param_1,int *param_2)

{
  int *this;
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  VARIANTARG local_28;
  undefined4 *local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x45007482;
  local_14[0] = 0;
  uVar1 = (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,local_14);
  this = param_2;
  iVar3 = 0;
  if (0 < local_14[0]) {
    do {
      param_2 = (int *)0x0;
      local_8 = 0;
      FUN_45001f8d((uint *)&local_28);
      iVar3 = iVar3 + 1;
      local_8 = CONCAT31(local_8._1_3_,1);
      (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,iVar3,&local_28);
      (*(code *)**(undefined4 **)local_28.n1._8_4_)(local_28.n1._8_4_,&DAT_4503d688,&param_2);
      puVar2 = (undefined4 *)FUN_450213f3(8);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = TCIFFField<ICiffField>::vftable;
        puVar2[1] = 0;
        FUN_450022ba(puVar2 + 1,(int *)&param_2);
      }
      local_18 = puVar2;
      FUN_4500503f(this,(int *)*this,&local_18);
      VariantClear(&local_28);
      local_8 = 0xffffffff;
      uVar1 = 0;
      if (param_2 != (int *)0x0) {
        uVar1 = (**(code **)(*param_2 + 8))(param_2);
      }
    } while (iVar3 < local_14[0]);
  }
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


