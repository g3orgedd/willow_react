// Source: CLCiffConversion_Layout.dll @ 4542e90c; FUN_4542e90c

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_4542e90c(void)

{
  SIZE_T SVar1;
  int iVar2;
  LPVOID pvVar3;
  int iVar4;
  uint dwSize;
  LPVOID lpAddress;
  undefined4 uStack_68;
  _SYSTEM_INFO local_58;
  _MEMORY_BASIC_INFORMATION local_34;
  DWORD local_18;
  undefined1 *local_14;
  PVOID local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  uStack_68 = 0x4542e927;
  local_14 = (undefined1 *)&uStack_68;
  SVar1 = VirtualQuery(&uStack_68,&local_34,0x1c);
  if (SVar1 != 0) {
    local_10 = local_34.AllocationBase;
    GetSystemInfo(&local_58);
    local_c = 0;
    iVar2 = FUN_454399d7(&local_c);
    iVar4 = 0;
    if ((iVar2 != 0) && (local_c != 0)) {
      iVar4 = local_c;
    }
    dwSize = iVar4 + -1 + local_58.dwPageSize & ~(local_58.dwPageSize - 1);
    if (dwSize != 0) {
      dwSize = dwSize + local_58.dwPageSize;
    }
    if (dwSize < local_58.dwPageSize * 2) {
      dwSize = local_58.dwPageSize * 2;
    }
    lpAddress = (LPVOID)((~(local_58.dwPageSize - 1) & (uint)local_14) - dwSize);
    if (((LPVOID)((int)local_10 + local_58.dwPageSize) <= lpAddress) &&
       (pvVar3 = VirtualAlloc(lpAddress,dwSize,0x1000,4), pvVar3 != (LPVOID)0x0)) {
      VirtualProtect(lpAddress,dwSize,0x104,&local_18);
    }
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


