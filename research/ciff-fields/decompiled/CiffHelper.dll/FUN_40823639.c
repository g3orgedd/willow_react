// Source: CiffHelper.dll @ 40823639; FUN_40823639

undefined4 FUN_40823639(int param_1,wchar_t *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != (wchar_t *)0x0) {
    while (param_3 <= param_4) {
      iVar2 = (param_3 + param_4) / 2;
      iVar1 = _wcscmp(*(wchar_t **)(param_1 + iVar2 * 8),param_2);
      if (iVar1 == 0) {
        return *(undefined4 *)(param_1 + 4 + iVar2 * 8);
      }
      if (iVar1 < 1) {
        param_3 = iVar2 + 1;
      }
      else {
        param_4 = iVar2 + -1;
      }
    }
  }
  return 0;
}


