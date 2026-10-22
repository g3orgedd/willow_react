// Source: CLCiffConversion_Layout.dll @ 45431d22; FUN_45431d22

void FUN_45431d22(void)

{
  PVOID pvVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    pvVar1 = EncodePointer(*(PVOID *)((int)&PTR_LAB_4545da40 + uVar2));
    *(PVOID *)((int)&PTR_LAB_4545da40 + uVar2) = pvVar1;
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x28);
  return;
}


