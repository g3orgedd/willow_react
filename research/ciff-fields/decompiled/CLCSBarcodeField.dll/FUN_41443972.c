// Source: CLCSBarcodeField.dll @ 41443972; FUN_41443972

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_41443972(void *this,undefined4 *param_1)

{
  int iVar1;
  double dVar2;
  
  iVar1 = 1;
  (**(code **)(*(int *)*param_1 + 0x2c))((int *)*param_1,&param_1);
  while (dVar2 = (((double)iVar1 / (double)(float)param_1) * DAT_41481000) /
                 *(double *)((int)this + 0x28), dVar2 <= _DAT_41484290) {
    iVar1 = iVar1 + 1;
  }
  return (int)((float)(int)(dVar2 * DAT_41483fb8) / _DAT_41481008);
}


