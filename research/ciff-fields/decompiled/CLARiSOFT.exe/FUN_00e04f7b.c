// Source: CLARiSOFT.exe @ 00e04f7b; FUN_00e04f7b

HRESULT __thiscall FUN_00e04f7b(void *this,IID *param_1,LPUNKNOWN param_2,uint param_3)

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
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_00efcb68,this);
  }
  else {
    HVar2 = CoCreateInstance(param_1,param_2,param_3,(IID *)&DAT_00efca90,&local_8);
    if (HVar2 < 0) goto LAB_00e04ff8;
    HVar2 = OleRun(local_8);
    if (-1 < HVar2) {
      HVar2 = (*local_8->lpVtbl->QueryInterface)(local_8,(IID *)&DAT_00efcb68,this);
    }
    (*local_8->lpVtbl->Release)(local_8);
  }
  if (-1 < HVar2) {
    return HVar2;
  }
LAB_00e04ff8:
  *(undefined4 *)this = 0;
  return HVar2;
}


