// Source: CLCiffConversion_Data.dll @ 450339ec; FUN_450339ec

void __cdecl FUN_450339ec(undefined4 param_1,FILE *param_2)

{
  WCHAR *pWVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  WCHAR WVar5;
  undefined4 local_14;
  undefined1 local_10;
  undefined1 local_f;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  WVar5 = (WCHAR)param_1;
  if ((WVar5 != L'\xffff') &&
     (((param_2->_flag & 1) != 0 || (((param_2->_flag & 0x80) != 0 && ((param_2->_flag & 2) == 0))))
     )) {
    if (param_2->_base == (char *)0x0) {
      __getbuf(param_2);
    }
    if ((param_2->_flag & 0x40) == 0) {
      iVar2 = __fileno(param_2);
      if ((iVar2 == -1) || (iVar2 = __fileno(param_2), iVar2 == -2)) {
        puVar4 = &DAT_45052420;
      }
      else {
        iVar2 = __fileno(param_2);
        uVar3 = __fileno(param_2);
        puVar4 = (undefined *)((uVar3 & 0x1f) * 0x40 + (&DAT_45055ae0)[iVar2 >> 5]);
      }
      if ((puVar4[4] & 0x80) != 0) {
        iVar2 = __fileno(param_2);
        if ((iVar2 == -1) || (iVar2 = __fileno(param_2), iVar2 == -2)) {
          puVar4 = &DAT_45052420;
        }
        else {
          iVar2 = __fileno(param_2);
          uVar3 = __fileno(param_2);
          puVar4 = (undefined *)((uVar3 & 0x1f) * 0x40 + (&DAT_45055ae0)[iVar2 >> 5]);
        }
        if ((puVar4[0x24] & 0x7f) == 0) {
          iVar2 = FUN_45033dc3(&local_14,(uint *)&local_10,5,WVar5);
          if (iVar2 != 0) goto LAB_45033b77;
        }
        else {
          local_10 = (char)param_1;
          local_f = (char)((uint)param_1 >> 8);
          local_14 = 2;
        }
        iVar2 = local_14;
        if (param_2->_ptr < param_2->_base + local_14) {
          if ((param_2->_cnt != 0) || (param_2->_bufsiz < local_14)) goto LAB_45033b77;
          param_2->_ptr = param_2->_base + local_14;
        }
        while (-1 < iVar2 + -1) {
          param_2->_ptr = param_2->_ptr + -1;
          *param_2->_ptr = *(char *)((int)&local_14 + iVar2 + 3);
          iVar2 = iVar2 + -1;
        }
        param_2->_cnt = param_2->_cnt + local_14;
        param_2->_flag = param_2->_flag & 0xffffffefU | 1;
        goto LAB_45033b77;
      }
    }
    if (param_2->_ptr < param_2->_base + 2) {
      if ((param_2->_cnt != 0) || ((uint)param_2->_bufsiz < 2)) goto LAB_45033b77;
      param_2->_ptr = param_2->_base + 2;
    }
    param_2->_ptr = param_2->_ptr + -2;
    pWVar1 = (WCHAR *)param_2->_ptr;
    if ((param_2->_flag & 0x40) == 0) {
      *pWVar1 = WVar5;
    }
    else if (*pWVar1 != WVar5) {
      param_2->_ptr = (char *)(pWVar1 + 1);
      goto LAB_45033b77;
    }
    param_2->_cnt = param_2->_cnt + 2;
    param_2->_flag = param_2->_flag & 0xffffffefU | 1;
  }
LAB_45033b77:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


