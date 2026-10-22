// Source: CLCiffConversion_Layout.dll @ 454419c8; FUN_454419c8

void __cdecl
FUN_454419c8(int *param_1,wchar_t *param_2,DWORD param_3,byte *param_4,int param_5,byte *param_6,
            int param_7,UINT param_8)

{
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_4542c8eb(local_14,param_1);
  FUN_45441724(local_14,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return;
}


