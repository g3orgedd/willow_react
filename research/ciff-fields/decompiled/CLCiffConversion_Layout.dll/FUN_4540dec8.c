// Source: CLCiffConversion_Layout.dll @ 4540dec8; FUN_4540dec8

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void __thiscall FUN_4540dec8(void *this,int *param_1,wchar_t *param_2)

{
  int iVar1;
  ushort uVar2;
  size_t sVar3;
  int iVar4;
  LPCSTR lpFileName;
  HANDLE hFile;
  BOOL BVar5;
  undefined4 uVar6;
  uint *puVar7;
  int local_44;
  uint local_3c;
  undefined1 local_38 [8];
  uint local_30 [10];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  if (param_2 == (wchar_t *)0x0) {
LAB_4540def7:
    lpFileName = (LPCSTR)0x0;
  }
  else {
    sVar3 = _wcslen(param_2);
    iVar4 = sVar3 + 1;
    if (0x3fffffff < iVar4) goto LAB_4540def7;
    iVar1 = iVar4 * -2;
    *(undefined4 *)(local_38 + iVar1 + -0x1c) = 3;
    *(int *)(local_38 + iVar1 + -0x20) = iVar4 * 2;
    *(wchar_t **)(&stack0xffffffa4 + iVar1) = param_2;
    *(int *)(&stack0xffffffa0 + iVar1) = (int)local_30 + iVar1 + -0x20;
    *(undefined4 *)(&stack0xffffff9c + iVar1) = 0x4540df11;
    lpFileName = AtlW2AHelper(*(char **)(&stack0xffffffa0 + iVar1),
                              *(wchar_t **)(&stack0xffffffa4 + iVar1),
                              *(int *)(local_38 + iVar1 + -0x20),*(uint *)(local_38 + iVar1 + -0x1c)
                             );
  }
  hFile = CreateFileA(lpFileName,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    BVar5 = ReadFile(hFile,param_1,100,&local_3c,(LPOVERLAPPED)0x0);
    if ((((BVar5 != 0) && (local_3c == 100)) && (*param_1 == 0x4642465a)) &&
       (uVar2 = *(ushort *)((int)param_1 + 0x62), uVar2 < 0x3e9)) {
      if (3 < uVar2) {
        uVar2 = 4;
      }
      *(ushort *)((int)param_1 + 0x62) = uVar2;
      BVar5 = ReadFile(hFile,local_38,(uint)uVar2 * 0xc,&local_3c,(LPOVERLAPPED)0x0);
      if ((BVar5 != 0) && (local_3c == (uint)uVar2 * 0xc)) {
        local_44 = 0;
        if (*(short *)((int)param_1 + 0x62) != 0) {
          puVar7 = local_30;
          do {
            SetFilePointer(hFile,puVar7[-1],(PLONG)0x0,0);
            if (puVar7[-2] == 0x50414d43) {
              uVar6 = FUN_4540da6f((int)param_1,(uint)*(ushort *)(param_1 + 0x13),'\0');
              if ((((char)uVar6 == '\0') || ((uint)*(ushort *)(param_1 + 0x13) * 0x14 < *puVar7)) ||
                 ((BVar5 = ReadFile(hFile,(LPVOID)param_1[0x1d],*puVar7,&local_3c,(LPOVERLAPPED)0x0)
                  , BVar5 == 0 || (local_3c != *puVar7)))) goto LAB_4540e053;
            }
            else if (puVar7[-2] == 0x52cc47d3) {
              BVar5 = ReadFile(hFile,(LPVOID)((int)this + 0x48),4,&local_3c,(LPOVERLAPPED)0x0);
              if ((BVar5 == 0) || (local_3c != 4)) {
                *(undefined4 *)((int)this + 0x48) = 0;
                goto LAB_4540e053;
              }
            }
            else if (puVar7[-2] == 0x54414443) {
              uVar6 = FUN_4540d9f6((int)param_1,*puVar7,'\0');
              if ((((char)uVar6 == '\0') ||
                  (BVar5 = ReadFile(hFile,(LPVOID)param_1[0x25],*puVar7,&local_3c,(LPOVERLAPPED)0x0)
                  , BVar5 == 0)) || (local_3c != *puVar7)) goto LAB_4540e053;
              param_1[0x26] = *puVar7;
            }
            puVar7 = puVar7 + 3;
            local_44 = local_44 + 1;
          } while (local_44 < (int)(uint)*(ushort *)((int)param_1 + 0x62));
        }
        CloseHandle(hFile);
        goto LAB_4540e05c;
      }
    }
LAB_4540e053:
    CloseHandle(hFile);
  }
LAB_4540e05c:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


