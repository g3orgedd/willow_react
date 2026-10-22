// Source: CLCiffConversion_Layout.dll @ 4543d55e; FUN_4543d55e

void __cdecl FUN_4543d55e(LPSTR param_1,WCHAR *param_2,uint param_3,int *param_4)

{
  char cVar1;
  WCHAR WVar2;
  int *piVar3;
  WCHAR *pWVar4;
  int iVar5;
  DWORD DVar6;
  uint uVar7;
  uint uVar8;
  int local_30 [2];
  int local_28;
  char local_24;
  int local_20;
  LPSTR local_1c;
  WCHAR *local_18;
  BOOL local_14;
  CHAR local_10 [8];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  uVar8 = 0;
  local_1c = param_1;
  local_14 = 0;
  local_18 = param_2;
  if ((param_1 != (LPSTR)0x0) && (param_3 == 0)) goto LAB_4543d7b4;
  if (param_2 == (WCHAR *)0x0) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_45432798();
    goto LAB_4543d7b4;
  }
  FUN_4542c8eb(local_30,param_4);
  if (local_1c == (LPSTR)0x0) {
    if (*(int *)(local_30[0] + 0xa8) == 0) {
      WVar2 = *param_2;
      while (WVar2 != L'\0') {
        if (0xff < (ushort)WVar2) goto LAB_4543d797;
        param_2 = param_2 + 1;
        WVar2 = *param_2;
      }
    }
    else {
      iVar5 = WideCharToMultiByte(*(UINT *)(local_30[0] + 4),0,param_2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,
                                  &local_14);
      if ((iVar5 == 0) || (local_14 != 0)) {
LAB_4543d797:
        piVar3 = __errno();
        *piVar3 = 0x2a;
      }
    }
  }
  else if (*(int *)(local_30[0] + 0xa8) == 0) {
    if (param_3 != 0) {
      do {
        if (0xff < (ushort)*param_2) goto LAB_4543d73b;
        local_1c[uVar8] = (CHAR)*param_2;
        WVar2 = *param_2;
        param_2 = param_2 + 1;
      } while ((WVar2 != L'\0') && (uVar8 = uVar8 + 1, uVar8 < param_3));
    }
  }
  else if (*(int *)(local_30[0] + 0x74) == 1) {
    pWVar4 = param_2;
    uVar8 = param_3;
    if (param_3 != 0) {
      do {
        if (*pWVar4 == L'\0') break;
        pWVar4 = pWVar4 + 1;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
      if ((uVar8 != 0) && (*pWVar4 == L'\0')) {
        param_3 = ((int)pWVar4 - (int)param_2 >> 1) + 1;
      }
    }
    iVar5 = WideCharToMultiByte(*(UINT *)(local_30[0] + 4),0,param_2,param_3,local_1c,param_3,
                                (LPCSTR)0x0,&local_14);
    if (iVar5 != 0) {
joined_r0x4543d689:
      if (local_14 == 0) goto LAB_4543d7a5;
    }
LAB_4543d73b:
    piVar3 = __errno();
    *piVar3 = 0x2a;
  }
  else {
    iVar5 = WideCharToMultiByte(*(UINT *)(local_30[0] + 4),0,param_2,-1,local_1c,param_3,(LPCSTR)0x0
                                ,&local_14);
    if (iVar5 != 0) goto joined_r0x4543d689;
    if ((local_14 != 0) || (DVar6 = GetLastError(), DVar6 != 0x7a)) goto LAB_4543d73b;
    if (param_3 != 0) {
      uVar8 = 0;
      do {
        uVar7 = WideCharToMultiByte(*(UINT *)(local_30[0] + 4),0,local_18,1,local_10,
                                    *(int *)(local_30[0] + 0x74),(LPCSTR)0x0,&local_14);
        if ((((uVar7 == 0) || (local_14 != 0)) || ((int)uVar7 < 0)) || (5 < uVar7))
        goto LAB_4543d797;
        if (param_3 < uVar7 + uVar8) break;
        local_20 = 0;
        if (0 < (int)uVar7) {
          do {
            cVar1 = local_10[local_20];
            local_1c[uVar8] = cVar1;
            if (cVar1 == '\0') goto LAB_4543d7a5;
            local_20 = local_20 + 1;
            uVar8 = uVar8 + 1;
          } while (local_20 < (int)uVar7);
        }
        local_18 = local_18 + 1;
      } while (uVar8 < param_3);
    }
  }
LAB_4543d7a5:
  if (local_24 != '\0') {
    *(uint *)(local_28 + 0x70) = *(uint *)(local_28 + 0x70) & 0xfffffffd;
  }
LAB_4543d7b4:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


