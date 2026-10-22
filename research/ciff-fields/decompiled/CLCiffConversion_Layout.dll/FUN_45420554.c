// Source: CLCiffConversion_Layout.dll @ 45420554; FUN_45420554

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_45420554(int param_1)

{
  int *this;
  int *piVar1;
  int iVar2;
  _union_2683 local_2c;
  int local_1c;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  this = (int *)(param_1 + 0x38);
  if ((*this == 0) || (piVar1 = *(int **)(param_1 + 0x40), piVar1 == (int *)0x0)) {
    iVar2 = -0x7fffbffd;
  }
  else {
    local_18 = (BSTR)0x0;
    local_8 = 0;
    iVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1,&local_18);
    if (-1 < iVar2) {
      piVar1 = (int *)*this;
      if (piVar1 == (int *)0x0) {
        iVar2 = -0x7fffbffb;
      }
      else {
        local_1c = 0;
        iVar2 = (**(code **)(*piVar1 + 0x490))(piVar1,&local_1c);
        if ((-1 < iVar2) && (local_1c == 0)) {
          FUN_45429f70((uint *)&local_2c,0,0x10);
          VariantInit((VARIANTARG *)&local_2c.n2);
          local_8 = CONCAT31(local_8._1_3_,1);
          iVar2 = (**(code **)(*(int *)*this + 0x4c0))((int *)*this,local_18,&local_2c);
          if ((-1 < iVar2) &&
             ((local_2c.n2.vt == 9 && ((undefined4 *)local_2c._8_4_ != (undefined4 *)0x0)))) {
            CComQIPtr<>(local_14,(undefined4 *)local_2c._8_4_);
            if (local_14[0] != (int *)0x0) {
              FUN_45404ce5(this,(int *)local_14);
              if (local_14[0] != (int *)0x0) {
                (**(code **)(*local_14[0] + 8))(local_14[0]);
              }
            }
          }
          VariantClear((VARIANTARG *)&local_2c.n2);
        }
      }
    }
    SysFreeString(local_18);
  }
  return iVar2;
}


