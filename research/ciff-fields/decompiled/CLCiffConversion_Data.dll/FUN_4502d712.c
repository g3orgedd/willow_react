// Source: CLCiffConversion_Data.dll @ 4502d712; FUN_4502d712

void FUN_4502d712(void)

{
  PVOID pvVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    pvVar1 = EncodePointer(*(PVOID *)((int)&PTR_LAB_450521e0 + uVar2));
    *(PVOID *)((int)&PTR_LAB_450521e0 + uVar2) = pvVar1;
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x28);
  return;
}


