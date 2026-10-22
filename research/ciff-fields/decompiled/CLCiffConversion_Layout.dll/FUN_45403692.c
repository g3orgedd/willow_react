// Source: CLCiffConversion_Layout.dll @ 45403692; FUN_45403692

HRESULT __thiscall FUN_45403692(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

{
  int *piVar1;
  HRESULT HVar2;
  LPUNKNOWN local_8;
  
  piVar1 = *(int **)this;
  local_8 = this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if ((param_3 & 0x14) == 0) {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_454476b0,this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_4544768c,&local_8);
    if (HVar2 < 0) goto LAB_4540370f;
    HVar2 = OleRun(local_8);
    if (-1 < HVar2) {
      HVar2 = (*local_8->lpVtbl->QueryInterface)(local_8,(IID *)&DAT_454476b0,this);
    }
    (*local_8->lpVtbl->Release)(local_8);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_4540370f:
  *(undefined4 *)this = 0;
  return HVar2;
}


