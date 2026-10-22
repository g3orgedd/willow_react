// Source: CLCSTextBasedField.dll @ 4246780c; FUN_4246780c

void __thiscall FUN_4246780c(void *this,int *param_1,LPCWSTR param_2)

{
  ushort uVar1;
  HANDLE hFile;
  BOOL BVar2;
  undefined4 uVar3;
  uint *puVar4;
  int local_44;
  uint local_3c;
  undefined1 local_38 [8];
  uint local_30 [10];
  uint local_8;
  
  local_8 = DAT_424ba210 ^ (uint)&stack0xfffffffc;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    BVar2 = ReadFile(hFile,param_1,100,&local_3c,(LPOVERLAPPED)0x0);
    if ((((BVar2 != 0) && (local_3c == 100)) && (*param_1 == 0x4642465a)) &&
       (uVar1 = *(ushort *)((int)param_1 + 0x62), uVar1 < 0x3e9)) {
      if (3 < uVar1) {
        uVar1 = 4;
      }
      *(ushort *)((int)param_1 + 0x62) = uVar1;
      BVar2 = ReadFile(hFile,local_38,(uint)uVar1 * 0xc,&local_3c,(LPOVERLAPPED)0x0);
      if ((BVar2 != 0) && (local_3c == (uint)uVar1 * 0xc)) {
        local_44 = 0;
        if (*(short *)((int)param_1 + 0x62) != 0) {
          puVar4 = local_30;
          do {
            SetFilePointer(hFile,puVar4[-1],(PLONG)0x0,0);
            if (puVar4[-2] == 0x50414d43) {
              uVar3 = FUN_424673b3((int)param_1,(uint)*(ushort *)(param_1 + 0x13),'\0');
              if ((((char)uVar3 == '\0') || ((uint)*(ushort *)(param_1 + 0x13) * 0x14 < *puVar4)) ||
                 ((BVar2 = ReadFile(hFile,(LPVOID)param_1[0x1d],*puVar4,&local_3c,(LPOVERLAPPED)0x0)
                  , BVar2 == 0 || (local_3c != *puVar4)))) goto LAB_42467966;
            }
            else if (puVar4[-2] == 0x52cc47d3) {
              BVar2 = ReadFile(hFile,(LPVOID)((int)this + 0x48),4,&local_3c,(LPOVERLAPPED)0x0);
              if ((BVar2 == 0) || (local_3c != 4)) {
                *(undefined4 *)((int)this + 0x48) = 0;
                goto LAB_42467966;
              }
            }
            else if (puVar4[-2] == 0x54414443) {
              uVar3 = FUN_4246733a((int)param_1,*puVar4,'\0');
              if ((((char)uVar3 == '\0') ||
                  (BVar2 = ReadFile(hFile,(LPVOID)param_1[0x25],*puVar4,&local_3c,(LPOVERLAPPED)0x0)
                  , BVar2 == 0)) || (local_3c != *puVar4)) goto LAB_42467966;
              param_1[0x26] = *puVar4;
            }
            puVar4 = puVar4 + 3;
            local_44 = local_44 + 1;
          } while (local_44 < (int)(uint)*(ushort *)((int)param_1 + 0x62));
        }
        CloseHandle(hFile);
        goto LAB_4246796f;
      }
    }
LAB_42467966:
    CloseHandle(hFile);
  }
LAB_4246796f:
  FUN_4246ec70(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


