// Source: CLCiffConversion_Data.dll @ 45009355; FUN_45009355

void __thiscall FUN_45009355(void *this,int *param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  
  puVar2 = FUN_45009021(this,param_2);
  if ((puVar2 == *(undefined4 **)this) ||
     (bVar1 = FUN_45008b14(param_2,puVar2 + 4), param_2 = puVar2, bVar1)) {
    param_2 = *(undefined4 **)this;
  }
  *param_1 = (int)param_2;
  return;
}


