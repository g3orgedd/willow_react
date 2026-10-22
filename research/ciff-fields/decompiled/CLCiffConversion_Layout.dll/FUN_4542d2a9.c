// Source: CLCiffConversion_Layout.dll @ 4542d2a9; FUN_4542d2a9

ushort __cdecl FUN_4542d2a9(uint param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  char local_c;
  undefined4 local_8;
  
  FUN_4542c8eb(&local_18,param_2);
  if (param_1 < 0x100) {
    if (*(int *)(local_18 + 0x74) < 2) {
      uVar1 = *(ushort *)(*(int *)(local_18 + 0x90) + param_1 * 2) & 4;
    }
    else {
      uVar1 = FUN_454344e5(param_1,4,&local_18);
    }
  }
  else {
    local_8 = 0;
    param_1 = CONCAT31(CONCAT21(param_1._2_2_,(char)param_1),(char)(param_1 >> 8));
    if (*(int *)(local_14 + 8) != 0) {
      uVar1 = 1;
      iVar2 = FUN_4543468e(&local_18,1,(LPCSTR)&param_1,2,(LPWORD)&local_8,*(UINT *)(local_14 + 4),1
                          );
      if (((iVar2 != 0) && (local_8._2_2_ == 0)) && ((local_8 & 4) != 0)) goto LAB_4542d33b;
    }
    uVar1 = 0;
  }
LAB_4542d33b:
  if (local_c != '\0') {
    *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
  }
  return uVar1;
}


