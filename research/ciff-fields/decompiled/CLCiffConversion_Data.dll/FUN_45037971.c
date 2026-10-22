// Source: CLCiffConversion_Data.dll @ 45037971; FUN_45037971

int __cdecl FUN_45037971(byte *param_1,byte *param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int local_10;
  int local_c;
  char local_8;
  
  FUN_45021444(&local_14,param_4);
  if (param_3 == 0) {
    iVar3 = 0;
  }
  else if ((param_1 == (byte *)0x0) || (param_2 == (byte *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45027e29();
    iVar3 = 0x7fffffff;
  }
  else {
    iVar3 = 0x7fffffff;
    if (param_3 < 0x80000000) {
      if (*(int *)(local_10 + 8) == 0) {
        iVar3 = FUN_450389b1(param_1,param_2,param_3,param_4);
      }
      else {
        iVar2 = FUN_45038d1a(&local_14,*(wchar_t **)(local_10 + 0x21c),0x1001,param_1,param_3,
                             param_2,param_3,*(UINT *)(local_10 + 4));
        if (iVar2 != 0) {
          iVar3 = iVar2 + -2;
        }
      }
    }
    else {
      piVar1 = __errno();
      *piVar1 = 0x16;
      FUN_45027e29();
    }
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar3;
}


