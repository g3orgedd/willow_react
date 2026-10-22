// Source: CLCiffConversion_Data.dll @ 4500a7d8; FUN_4500a7d8

void __cdecl FUN_4500a7d8(undefined4 *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = -(uint)((int)((ulonglong)param_2 * 2 >> 0x20) != 0) | (uint)((ulonglong)param_2 * 2);
  puVar1 = (uint *)FUN_45020ebb(uVar2);
  if (puVar1 == (uint *)0x0) {
    puVar1 = (uint *)0x0;
  }
  else {
    FUN_45021c10(puVar1,0,uVar2);
  }
  *param_1 = puVar1;
  return;
}


