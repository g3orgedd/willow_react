// Source: CLCiffConversion_Layout.dll @ 4541d1d8; FUN_4541d1d8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4541d1d8(void *this,int *param_1)

{
  int *this_00;
  int iVar1;
  undefined4 *this_01;
  HRESULT HVar2;
  int *piVar3;
  VARIANTARG local_30;
  undefined4 *local_1c;
  int local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  FUN_45429f70((uint *)&local_30,0,0x10);
  VariantInit(&local_30);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = (**(code **)(**(int **)((int)this + 0x38) + 0x474))(*(int **)((int)this + 0x38),&local_30)
  ;
  FUN_4541534f(iVar1);
  (*(code *)**(undefined4 **)local_30.n1._8_4_)(local_30.n1._8_4_,&DAT_45447790,local_14);
  local_18 = 0;
  (**(code **)(*local_14[0] + 0x24))(local_14[0],&local_18);
  this_00 = param_1;
  iVar1 = 0;
  if (0 < local_18) {
    do {
      param_1 = (int *)0x0;
      iVar1 = iVar1 + 1;
      local_8._0_1_ = 2;
      (**(code **)(*local_14[0] + 0x20))(local_14[0],iVar1,&local_30);
      (*(code *)**(undefined4 **)local_30.n1._8_4_)(local_30.n1._8_4_,&DAT_45447760,&param_1);
      this_01 = (undefined4 *)FUN_454298b4(4);
      local_8._0_1_ = 3;
      if (this_01 == (undefined4 *)0x0) {
        local_1c = (undefined4 *)0x0;
      }
      else {
        piVar3 = param_1;
        local_1c = this_01;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 4))(param_1);
        }
        local_1c = FUN_45412a60(this_01,piVar3);
      }
      local_8._0_1_ = 2;
      FUN_4541222d(this_00,(int *)*this_00,&local_1c);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    } while (iVar1 < local_18);
  }
  HVar2 = VariantClear(&local_30);
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    HVar2 = (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return CONCAT31((int3)((uint)HVar2 >> 8),1);
}


