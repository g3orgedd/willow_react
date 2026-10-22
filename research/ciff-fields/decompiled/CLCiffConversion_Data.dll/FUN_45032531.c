// Source: CLCiffConversion_Data.dll @ 45032531; FUN_45032531

void __cdecl
FUN_45032531(int *param_1,DWORD param_2,LPCSTR param_3,int param_4,LPWORD param_5,UINT param_6,
            int param_7)

{
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_45021444(local_14,param_1);
  FUN_45032439(local_14,param_2,param_3,param_4,param_5,param_6,param_7);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return;
}


