// Source: CLARiSOFT.exe @ 00e625e8; FUN_00e625e8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_00e625e8(void *this,HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  _union_2683 local_24;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0xe625f4;
  local_24._8_4_ = *(int *)((int)this + 4);
  local_24.n2.vt = 9;
  if ((int *)local_24._8_4_ != (int *)0x0) {
    (**(code **)(*(int *)local_24._8_4_ + 4))(local_24._8_4_);
  }
  local_8 = 0;
  CComQIPtr<>(local_14,*(undefined4 **)((int)this + 0x3c));
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_14[0] == (int *)0x0) {
    FUN_00e0429d(0xf02b68);
  }
  else {
    (**(code **)(*local_14[0] + 0xc))
              (local_14[0],param_1,&local_24,param_2,param_3,param_4,param_5,param_6,param_7,param_8
               ,param_9,param_10,param_11);
    PostMessageW(param_1,0x414,0,0);
  }
  local_8 = local_8 & 0xffffff00;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  VariantClear((VARIANTARG *)&local_24.n2);
  return;
}


