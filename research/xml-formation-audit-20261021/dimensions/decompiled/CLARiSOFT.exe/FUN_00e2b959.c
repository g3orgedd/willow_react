// Source: CLARiSOFT.exe @ 00e2b959; FUN_00e2b959

undefined1 __fastcall FUN_00e2b959(void *param_1)

{
  undefined1 uVar1;
  
  uVar1 = 1;
  if (*(int *)((int)param_1 + 0x10) != 0) {
    uVar1 = FUN_00e35147(param_1);
  }
  SysFreeString(*(BSTR *)((int)param_1 + 0x1dc));
  *(undefined4 *)((int)param_1 + 0x1dc) = 0;
  return uVar1;
}


