// Source: CLCiffConversion_Data.dll @ 45033c9f; FUN_45033c9f

int __cdecl FUN_45033c9f(int *param_1,uint *param_2,uint param_3,WCHAR param_4,int *param_5)

{
  uint *lpMultiByteStr;
  uint cbMultiByte;
  int *piVar1;
  int iVar2;
  DWORD DVar3;
  int unaff_ESI;
  int local_14 [2];
  int local_c;
  char local_8;
  
  cbMultiByte = param_3;
  lpMultiByteStr = param_2;
  if ((param_2 == (uint *)0x0) && (param_3 != 0)) {
    if (param_1 == (int *)0x0) {
      return unaff_ESI;
    }
    *param_1 = 0;
    return unaff_ESI;
  }
  if (param_1 != (int *)0x0) {
    *param_1 = -1;
  }
  if (0x7fffffff < param_3) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45027e29();
    return unaff_ESI;
  }
  FUN_45021444(local_14,param_5);
  if (*(int *)(local_14[0] + 0xa8) == 0) {
    if ((ushort)param_4 < 0x100) {
      if (lpMultiByteStr != (uint *)0x0) {
        if (cbMultiByte == 0) goto LAB_45033daf;
        *(char *)lpMultiByteStr = (char)param_4;
      }
      if (param_1 != (int *)0x0) {
        *param_1 = 1;
      }
      goto LAB_45033d32;
    }
    if ((lpMultiByteStr != (uint *)0x0) && (cbMultiByte != 0)) {
      FUN_45021c10(lpMultiByteStr,0,cbMultiByte);
    }
  }
  else {
    param_2 = (uint *)0x0;
    iVar2 = WideCharToMultiByte(*(UINT *)(local_14[0] + 4),0,&param_4,1,(LPSTR)lpMultiByteStr,
                                cbMultiByte,(LPCSTR)0x0,(LPBOOL)&param_2);
    if (iVar2 == 0) {
      DVar3 = GetLastError();
      if (DVar3 == 0x7a) {
        if ((lpMultiByteStr != (uint *)0x0) && (cbMultiByte != 0)) {
          FUN_45021c10(lpMultiByteStr,0,cbMultiByte);
        }
LAB_45033daf:
        piVar1 = __errno();
        *piVar1 = 0x22;
        FUN_45027e29();
        goto LAB_45033d32;
      }
    }
    else if (param_2 == (uint *)0x0) {
      if (param_1 != (int *)0x0) {
        *param_1 = iVar2;
      }
      goto LAB_45033d32;
    }
  }
  piVar1 = __errno();
  *piVar1 = 0x2a;
  __errno();
LAB_45033d32:
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return unaff_ESI;
}


