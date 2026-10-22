// Source: CiffMgr.dll @ 681053c2; FUN_681053c2

void FUN_681053c2(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  OLECHAR ***psz;
  BSTR pOVar2;
  int iVar3;
  OLECHAR **local_20 [5];
  uint local_c;
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  iVar3 = 1;
  puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x74);
  do {
    if (puVar1 == *(undefined4 **)(param_1 + 0x74)) {
LAB_68105438:
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
      FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (iVar3 == param_2) {
      basic_string<>(local_20,(undefined8 *)(puVar1 + 2));
      psz = local_20;
      if (7 < local_c) {
        psz = (OLECHAR ***)local_20[0];
      }
      pOVar2 = SysAllocString((OLECHAR *)psz);
      *param_3 = pOVar2;
      FUN_68105b16(local_20,'\x01',0);
      goto LAB_68105438;
    }
    puVar1 = (undefined4 *)*puVar1;
    iVar3 = iVar3 + 1;
  } while( true );
}


