// Source: CLCiffConversion_Layout.dll @ 4541c943; FUN_4541c943

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_4541c943(void *this,int *param_1,int *param_2)

{
  _union_2683 local_28;
  undefined4 local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  *param_1 = 0;
  local_14[0] = (int *)0x0;
  local_18 = 1;
  local_8 = 1;
  (**(code **)(**(int **)((int)this + 4) + 0x5c))(*(int **)((int)this + 4),local_14);
  if (local_14[0] != (int *)0x0) {
    FUN_45429f70((uint *)&local_28,0,0x10);
    VariantInit((VARIANTARG *)&local_28.n2);
    local_8 = CONCAT31(local_8._1_3_,2);
    (**(code **)(*local_14[0] + 0x24))(local_14[0],param_2,&local_28);
    if (local_28.n2.vt != 0) {
      CComQIPtr<>(&param_2,(undefined4 *)local_28._8_4_);
      FUN_4541a358(&param_2,param_1);
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    }
    VariantClear((VARIANTARG *)&local_28.n2);
  }
  local_8 = local_8 & 0xffffff00;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return param_1;
}


