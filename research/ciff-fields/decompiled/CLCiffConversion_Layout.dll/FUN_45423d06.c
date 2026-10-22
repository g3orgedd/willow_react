// Source: CLCiffConversion_Layout.dll @ 45423d06; FUN_45423d06

int __fastcall FUN_45423d06(int param_1)

{
  undefined4 *puVar1;
  DWORD DVar2;
  
  puVar1 = (undefined4 *)(param_1 + 4);
  FUN_45423d7c((int)puVar1);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  DAT_4545fba8 = param_1;
  *(undefined4 *)(param_1 + 0x28) = 0;
  DVar2 = FUN_45409b72((LPCRITICAL_SECTION)(param_1 + 0x10));
  if ((int)DVar2 < 0) {
    DAT_45460735 = 1;
  }
  else {
    *puVar1 = 0x24;
  }
  return param_1;
}


