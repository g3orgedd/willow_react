// Source: CiffMgr.dll @ 681044c1; FUN_681044c1

bool __thiscall FUN_681044c1(void *this,int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  int *local_8;
  
  piVar2 = param_1;
  puVar1 = *(undefined4 **)this;
  if (puVar1 == (undefined4 *)0x0) {
    if (param_1 == (int *)0x0) {
      return true;
    }
  }
  else if (param_1 != (int *)0x0) {
    param_1 = (int *)0x0;
    local_8 = (int *)0x0;
    (**(code **)*puVar1)(puVar1,&DAT_68147750,&param_1);
    (**(code **)*piVar2)(piVar2,&DAT_68147750,&local_8);
    bVar3 = param_1 == local_8;
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 8))(local_8);
    }
    if (param_1 == (int *)0x0) {
      return bVar3;
    }
    (**(code **)(*param_1 + 8))(param_1);
    return bVar3;
  }
  return false;
}


