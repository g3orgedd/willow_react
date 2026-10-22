// Source: CLCiffConversion_Data.dll @ 450102ee; FUN_450102ee

void __thiscall FUN_450102ee(void *this,VARIANTARG *param_1)

{
  HRESULT HVar1;
  
  HVar1 = VariantCopy(this,param_1);
  if (-1 < HVar1) {
    return;
  }
  *(undefined2 *)this = 10;
  *(HRESULT *)((int)this + 8) = HVar1;
                    /* WARNING: Subroutine does not return */
  FUN_45002735(HVar1);
}


