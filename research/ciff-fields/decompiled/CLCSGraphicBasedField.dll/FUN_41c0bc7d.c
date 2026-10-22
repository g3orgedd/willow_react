// Source: CLCSGraphicBasedField.dll @ 41c0bc7d; FUN_41c0bc7d

bool __cdecl FUN_41c0bc7d(int *param_1)

{
  int *piVar1;
  int iVar2;
  int local_8;
  
  local_8 = 1;
  piVar1 = (int *)*param_1;
  iVar2 = 1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x23c))(piVar1,&local_8);
    iVar2 = local_8;
  }
  return iVar2 != 0;
}


