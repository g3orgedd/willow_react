// Source: CLCiffConversion_Layout.dll @ 4543a16c; FUN_4543a16c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 FUN_4543a16c(void)

{
  HANDLE hFile;
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  DWORD DVar4;
  HANDLE pvVar5;
  int *piVar6;
  int iVar7;
  _STARTUPINFOW local_78;
  int local_34;
  uint local_30;
  byte *local_2c;
  int *local_28;
  byte *local_24;
  HANDLE local_20;
  undefined1 local_14 [8];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_4545b098;
  uStack_c = 0x4543a178;
  __lock(0xb);
  local_8 = (undefined *)0x0;
  local_28 = FUN_454375c4(0x20,0x40);
  if (local_28 == (int *)0x0) {
    __local_unwind4(&DAT_4545d9f0,(int)local_14,0xfffffffe);
    uVar3 = 0xffffffff;
  }
  else {
    DAT_454626e8 = (HANDLE)0x20;
    DAT_454612f8 = local_28;
    for (; local_28 < DAT_454612f8 + 0x200; local_28 = local_28 + 0x10) {
      *(undefined2 *)(local_28 + 1) = 0xa00;
      *local_28 = -1;
      local_28[2] = 0;
      *(byte *)(local_28 + 9) = *(byte *)(local_28 + 9) & 0x80;
      *(byte *)(local_28 + 9) = *(byte *)(local_28 + 9) & 0x7f;
      *(undefined2 *)((int)local_28 + 0x25) = 0xa0a;
      local_28[0xe] = 0;
      *(undefined1 *)(local_28 + 0xd) = 0;
    }
    GetStartupInfoW(&local_78);
    if ((local_78.cbReserved2 != 0) && ((int *)local_78.lpReserved2 != (int *)0x0)) {
      local_20 = *(HANDLE *)local_78.lpReserved2;
      local_2c = (byte *)((int)local_78.lpReserved2 + 4);
      local_24 = local_2c + (int)local_20;
      if (0x7ff < (int)local_20) {
        local_20 = (HANDLE)0x800;
      }
      local_34 = 1;
      while (iVar7 = local_34, (int)DAT_454626e8 < (int)local_20) {
        local_28 = FUN_454375c4(0x20,0x40);
        if (local_28 == (int *)0x0) {
          local_20 = DAT_454626e8;
          break;
        }
        (&DAT_454612f8)[iVar7] = local_28;
        DAT_454626e8 = (HANDLE)((int)DAT_454626e8 + 0x20);
        for (; local_28 < (int *)((int)(&DAT_454612f8)[iVar7] + 0x800); local_28 = local_28 + 0x10)
        {
          *(undefined2 *)(local_28 + 1) = 0xa00;
          *local_28 = -1;
          local_28[2] = 0;
          *(byte *)(local_28 + 9) = *(byte *)(local_28 + 9) & 0x80;
          *(undefined2 *)((int)local_28 + 0x25) = 0xa0a;
          local_28[0xe] = 0;
          *(undefined1 *)(local_28 + 0xd) = 0;
        }
        local_34 = iVar7 + 1;
      }
      local_30 = 0;
      pvVar5 = local_20;
      while (uVar1 = local_30, (int)local_30 < (int)pvVar5) {
        hFile = *(HANDLE *)local_24;
        if ((((hFile != (HANDLE)0xffffffff) && (hFile != (HANDLE)0xfffffffe)) &&
            ((*local_2c & 1) != 0)) &&
           (((*local_2c & 8) != 0 || (DVar4 = GetFileType(hFile), pvVar5 = local_20, DVar4 != 0))))
        {
          piVar6 = (int *)((uVar1 & 0x1f) * 0x40 + (int)(&DAT_454612f8)[(int)uVar1 >> 5]);
          *piVar6 = *(int *)local_24;
          *(byte *)(piVar6 + 1) = *local_2c;
          local_28 = piVar6;
          FUN_454396de((LPCRITICAL_SECTION)(piVar6 + 3),4000,0);
          piVar6[2] = piVar6[2] + 1;
          pvVar5 = local_20;
        }
        local_2c = local_2c + 1;
        local_24 = local_24 + 4;
        local_30 = uVar1 + 1;
      }
    }
    for (iVar7 = 0; local_30 = iVar7, iVar7 < 3; iVar7 = iVar7 + 1) {
      piVar6 = DAT_454612f8 + iVar7 * 0x10;
      local_28 = piVar6;
      if ((*piVar6 == -1) || (*piVar6 == -2)) {
        *(undefined1 *)(piVar6 + 1) = 0x81;
        if (iVar7 == 0) {
          DVar4 = 0xfffffff6;
        }
        else {
          DVar4 = 0xfffffff5 - (iVar7 != 1);
        }
        local_20 = GetStdHandle(DVar4);
        if (((local_20 == (HANDLE)0xffffffff) || (local_20 == (HANDLE)0x0)) ||
           (DVar4 = GetFileType(local_20), DVar4 == 0)) {
          *(byte *)(piVar6 + 1) = *(byte *)(piVar6 + 1) | 0x40;
          *piVar6 = -2;
          if (DAT_454626e0 != 0) {
            *(undefined4 *)(*(int *)(DAT_454626e0 + iVar7 * 4) + 0x10) = 0xfffffffe;
          }
        }
        else {
          *piVar6 = (int)local_20;
          if ((DVar4 & 0xff) == 2) {
            bVar2 = *(byte *)(piVar6 + 1) | 0x40;
LAB_4543a3cc:
            *(byte *)(piVar6 + 1) = bVar2;
          }
          else if ((DVar4 & 0xff) == 3) {
            bVar2 = *(byte *)(piVar6 + 1) | 8;
            goto LAB_4543a3cc;
          }
          FUN_454396de((LPCRITICAL_SECTION)(piVar6 + 3),4000,0);
          piVar6[2] = piVar6[2] + 1;
        }
      }
      else {
        *(byte *)(piVar6 + 1) = *(byte *)(piVar6 + 1) | 0x80;
      }
    }
    local_8 = (undefined *)0xfffffffe;
    FUN_4543a417();
    uVar3 = 0;
  }
  return uVar3;
}


