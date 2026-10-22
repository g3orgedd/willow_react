// Source: CLCiffConversion_Layout.dll @ 4540793b; FUN_4540793b

undefined4 __thiscall FUN_4540793b(void *this,undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 local_14 [8];
  undefined1 local_c [8];
  
  piVar1 = *(int **)((int)this + 0x18);
  uVar2 = 0x80004005;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x38))(piVar1,param_1,local_14,local_c);
  }
  return uVar2;
}


