// Source: CiffHelper.dll @ 40829343; FUN_40829343

_union_2685 * __thiscall FUN_40829343(void *this,VARIANTARG *param_1)

{
  HRESULT HVar1;
  _union_2685 _Var2;
  _union_2683 local_14;
  
  if ((param_1->n1).n2.vt == 7) {
    _Var2 = (param_1->n1).n2.n3;
  }
  else {
    local_14.n2.vt = 0;
    local_14._2_4_ = 0;
    local_14.n2.wReserved3 = 0;
    local_14._8_2_ = 0;
    local_14._10_4_ = 0;
    local_14._14_2_ = 0;
    HVar1 = VariantChangeType((VARIANTARG *)&local_14.n2,param_1,0,7);
    _Var2 = DAT_4084abe0;
    if (-1 < HVar1) {
      *(ulonglong *)this = CONCAT26(local_14._14_2_,CONCAT42(local_14._10_4_,local_14._8_2_));
      VariantClear((VARIANTARG *)&local_14.n2);
      return this;
    }
  }
  *(_union_2685 *)this = _Var2;
  return this;
}


