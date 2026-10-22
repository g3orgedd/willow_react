// Source: CLCiffConversion_Layout.dll @ 45434159; FUN_45434159

uint __cdecl FUN_45434159(WCHAR param_1,uint param_2)

{
  uint uVar1;
  BOOL BVar2;
  uint local_8;
  
  if (param_1 == L'\xffff') {
    uVar1 = 0;
  }
  else {
    if ((ushort)param_1 < 0x100) {
      uVar1 = (uint)*(ushort *)(PTR_DAT_4545e720 + (uint)(ushort)param_1 * 2);
    }
    else {
      BVar2 = GetStringTypeW(1,&param_1,1,(LPWORD)&local_8);
      uVar1 = -(uint)(BVar2 != 0) & local_8 & 0xffff;
    }
    uVar1 = uVar1 & param_2 & 0xffff;
  }
  return uVar1;
}


