// Source: CiffHelper.dll @ 40819383; FUN_40819383

BSTR FUN_40819383(int param_1,int *param_2)

{
  BSTR pOVar1;
  
  param_2 = (int *)param_2[2];
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
    if (param_2 != (int *)0x0) {
      pOVar1 = FUN_408240f3((void *)(param_1 + 0xf4),(int *)&param_2);
      goto LAB_408193bf;
    }
  }
  pOVar1 = (BSTR)0x80004005;
LAB_408193bf:
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return pOVar1;
}


