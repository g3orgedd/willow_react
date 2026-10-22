// Source: CLCiffConversion_Layout.dll @ 45408df7; FUN_45408df7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HRESULT __thiscall FUN_45408df7(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  HRESULT HVar3;
  BSTR pOVar4;
  BSTR local_4c [8];
  _union_2683 local_2c;
  undefined4 local_1c;
  int *local_18;
  short local_14 [6];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_18 = (int *)0x0;
  local_8 = 0;
  HVar3 = CoCreateInstance((IID *)&DAT_45447f1c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_45447e98,&local_18);
  if (((-1 < HVar3) && (local_18 != (int *)0x0)) &&
     (HVar3 = (**(code **)(*local_18 + 0xfc))(local_18,0), -1 < HVar3)) {
    local_2c._0_4_ = local_2c._0_4_ & 0xffff0000;
    FUN_4540894d(&local_2c,param_1);
    local_8._0_1_ = 1;
    HVar3 = (**(code **)(*local_18 + 0xe8))
                      (local_18,local_2c._0_4_,local_2c.decVal.Hi32,local_2c._8_4_,local_2c._12_4_,
                       local_14);
    if ((-1 < HVar3) && (local_14[0] != 0)) {
      local_1c = 0;
      piVar1 = (int *)((int)this + 8);
      local_8._0_1_ = 2;
      piVar2 = (int *)*piVar1;
      if (piVar2 != (int *)0x0) {
        *piVar1 = 0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      HVar3 = (**(code **)(*local_18 + 0xb4))(local_18,piVar1);
      if (-1 < HVar3) {
        if (*piVar1 == 0) {
          HVar3 = -0x7fffbffb;
        }
        else {
          SysFreeString(*(BSTR *)((int)this + 0xc));
          *(undefined4 *)((int)this + 0xc) = 0;
          local_4c[0] = FUN_4540363b(param_1);
          FUN_4540911e((int *)local_4c);
          pOVar4 = FUN_454089c8((int *)local_4c);
          if (*(BSTR *)((int)this + 0xc) != pOVar4) {
            SysFreeString(*(BSTR *)((int)this + 0xc));
            *(BSTR *)((int)this + 0xc) = pOVar4;
          }
          FUN_45408930((int *)local_4c);
        }
      }
    }
    VariantClear((VARIANTARG *)&local_2c.n2);
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return HVar3;
}


