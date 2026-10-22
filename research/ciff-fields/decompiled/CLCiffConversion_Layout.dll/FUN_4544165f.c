// Source: CLCiffConversion_Layout.dll @ 4544165f; FUN_4544165f

int __cdecl FUN_4544165f(byte *param_1,byte *param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14 [2];
  int local_c;
  char local_8;
  
  FUN_4542c8eb(local_14,param_4);
  if (param_3 == 0) {
    iVar3 = 0;
  }
  else if ((param_1 == (byte *)0x0) || (param_2 == (byte *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45432798();
    iVar3 = 0x7fffffff;
  }
  else {
    iVar3 = 0x7fffffff;
    if (param_3 < 0x80000000) {
      if (*(wchar_t **)(local_14[0] + 0xa4) == (wchar_t *)0x0) {
        iVar3 = FUN_45441cb2((char *)param_1,param_2,param_3,local_14);
      }
      else {
        iVar2 = FUN_454419c8(local_14,*(wchar_t **)(local_14[0] + 0xa4),0x1001,param_1,param_3,
                             param_2,param_3,*(UINT *)(local_14[0] + 8));
        if (iVar2 == 0) {
          piVar1 = __errno();
          *piVar1 = 0x16;
        }
        else {
          iVar3 = iVar2 + -2;
        }
      }
    }
    else {
      piVar1 = __errno();
      *piVar1 = 0x16;
      FUN_45432798();
    }
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar3;
}


