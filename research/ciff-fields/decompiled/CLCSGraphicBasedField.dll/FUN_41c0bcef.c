// Source: CLCSGraphicBasedField.dll @ 41c0bcef; FUN_41c0bcef

bool __cdecl FUN_41c0bcef(undefined4 param_1)

{
  HRESULT HVar1;
  int *local_8;
  
  local_8 = (int *)0x0;
  HVar1 = CoCreateInstance((IID *)&DAT_41c30df4,(LPUNKNOWN)0x0,0x15,(IID *)&DAT_41c317ac,&local_8);
  if (HVar1 == 0) {
    (**(code **)*local_8)(local_8,&DAT_41c317bc,param_1);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return HVar1 == 0;
}


