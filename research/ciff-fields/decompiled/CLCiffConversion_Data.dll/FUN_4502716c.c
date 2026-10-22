// Source: CLCiffConversion_Data.dll @ 4502716c; FUN_4502716c

void __cdecl FUN_4502716c(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_1 + 0x18);
  FUN_45021c10(puVar3,0,0x101);
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x21c) = 0;
  iVar1 = 0x101;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  do {
    *(undefined1 *)puVar3 = *(undefined1 *)(((int)&DAT_45051b08 - param_1) + (int)puVar3);
    puVar3 = (uint *)((int)puVar3 + 1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  puVar2 = (undefined1 *)(param_1 + 0x119);
  iVar1 = 0x100;
  do {
    *puVar2 = puVar2[(int)&DAT_45051b08 - param_1];
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


