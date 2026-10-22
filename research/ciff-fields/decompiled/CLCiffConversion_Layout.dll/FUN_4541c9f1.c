// Source: CLCiffConversion_Layout.dll @ 4541c9f1; FUN_4541c9f1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 FUN_4541c9f1(int *param_1,undefined4 *param_2)

{
  undefined4 *this;
  undefined1 uVar1;
  int iVar2;
  VARIANTARG local_2c;
  undefined4 *local_1c;
  int local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  uVar1 = 0;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  (**(code **)(*(int *)param_1[1] + 0x5c))((int *)param_1[1],local_14);
  if (local_14[0] != (int *)0x0) {
    local_18 = 0;
    (**(code **)(*local_14[0] + 0x1c))(local_14[0],&local_18);
    iVar2 = 0;
    if (0 < local_18) {
      do {
        param_1 = (int *)0x0;
        FUN_45429f70((uint *)&local_2c,0,0x10);
        VariantInit(&local_2c);
        iVar2 = iVar2 + 1;
        local_8 = CONCAT31(local_8._1_3_,2);
        (**(code **)(*local_14[0] + 0x24))(local_14[0],iVar2,&local_2c);
        (*(code *)**(undefined4 **)local_2c.n1._8_4_)(local_2c.n1._8_4_,&DAT_45447c98,&param_1);
        this = (undefined4 *)FUN_454298b4(4);
        if (this == (undefined4 *)0x0) {
          this = (undefined4 *)0x0;
        }
        else {
          *this = 0;
          FUN_45404ce5(this,(int *)&param_1);
        }
        local_1c = this;
        FUN_4541222d(param_2,(int *)*param_2,&local_1c);
        VariantClear(&local_2c);
        local_8 = local_8 & 0xffffff00;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      } while (iVar2 < local_18);
    }
    uVar1 = 1;
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return uVar1;
}


