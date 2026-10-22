// Source: CLCiffConversion_Layout.dll @ 4542d360; FUN_4542d360

uint __cdecl FUN_4542d360(uint param_1,int *param_2)

{
  int iVar1;
  int local_1c;
  int local_18;
  int local_14;
  char local_10;
  uint local_c;
  CHAR local_8;
  undefined1 local_7;
  
  FUN_4542c8eb(&local_1c,param_2);
  if (param_1 < 0x100) {
    if ((*(byte *)(local_18 + 0x19 + param_1) & 0x20) != 0) {
      param_1 = (uint)*(byte *)(local_18 + 0x119 + param_1);
    }
  }
  else {
    local_8 = (CHAR)(param_1 >> 8);
    local_7 = (undefined1)param_1;
    if ((*(byte *)((param_1 >> 8 & 0xff) + 0x19 + local_18) & 4) != 0) {
      iVar1 = FUN_45434481(&local_1c,*(wchar_t **)(local_18 + 0x21c),0x200,&local_8,2,
                           (LPWSTR)&local_c,2,*(UINT *)(local_18 + 4),1);
      if (iVar1 != 0) {
        param_1 = (local_c & 0xff) * 0x100 + (local_c >> 8 & 0xff);
      }
    }
  }
  if (local_10 != '\0') {
    *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
  }
  return param_1;
}


