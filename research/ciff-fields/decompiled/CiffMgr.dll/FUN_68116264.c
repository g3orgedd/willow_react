// Source: CiffMgr.dll @ 68116264; FUN_68116264

undefined4 __cdecl FUN_68116264(int *param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_2;
  *param_1 = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    return 0;
  }
  return 0x80004003;
}


