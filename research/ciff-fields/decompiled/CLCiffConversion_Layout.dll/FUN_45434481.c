// Source: CLCiffConversion_Layout.dll @ 45434481; FUN_45434481

void __cdecl
FUN_45434481(int *param_1,wchar_t *param_2,uint param_3,LPCSTR param_4,int param_5,LPWSTR param_6,
            int param_7,UINT param_8,int param_9)

{
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_4542c8eb(local_14,param_1);
  FUN_4543427d(local_14,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return;
}


