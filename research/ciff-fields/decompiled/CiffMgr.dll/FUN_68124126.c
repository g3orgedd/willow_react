// Source: CiffMgr.dll @ 68124126; FUN_68124126

undefined4
FUN_68124126(undefined4 *param_1,int param_2,int param_3,int *param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  if (0 < param_3) {
    puVar3 = (undefined4 *)(param_2 + 4);
    do {
      iVar1 = (**(code **)(*(int *)*param_1 + 0x94))((int *)*param_1,*puVar3,param_4);
      if ((iVar1 == 0) && (*param_4 != 0)) {
        *param_5 = *(undefined4 *)(param_2 + iVar2 * 8);
        return 0;
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 2;
    } while (iVar2 < param_3);
  }
  return 0x80004005;
}


