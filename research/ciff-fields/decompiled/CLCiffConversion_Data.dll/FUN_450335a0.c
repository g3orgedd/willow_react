// Source: CLCiffConversion_Data.dll @ 450335a0; FUN_450335a0

void __cdecl FUN_450335a0(WCHAR param_1,FILE *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int local_14;
  uint local_10 [2];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if ((param_2->_flag & 0x40) == 0) {
    iVar2 = __fileno(param_2);
    puVar5 = &DAT_45052420;
    if ((iVar2 == -1) || (iVar2 = __fileno(param_2), iVar2 == -2)) {
      puVar4 = &DAT_45052420;
    }
    else {
      iVar2 = __fileno(param_2);
      uVar3 = __fileno(param_2);
      puVar4 = (undefined *)((uVar3 & 0x1f) * 0x40 + (&DAT_45055ae0)[iVar2 >> 5]);
    }
    if ((puVar4[0x24] & 0x7f) != 2) {
      iVar2 = __fileno(param_2);
      if ((iVar2 == -1) || (iVar2 = __fileno(param_2), iVar2 == -2)) {
        puVar4 = &DAT_45052420;
      }
      else {
        iVar2 = __fileno(param_2);
        uVar3 = __fileno(param_2);
        puVar4 = (undefined *)((uVar3 & 0x1f) * 0x40 + (&DAT_45055ae0)[iVar2 >> 5]);
      }
      if ((puVar4[0x24] & 0x7f) != 1) {
        iVar2 = __fileno(param_2);
        if ((iVar2 != -1) && (iVar2 = __fileno(param_2), iVar2 != -2)) {
          iVar2 = __fileno(param_2);
          uVar3 = __fileno(param_2);
          puVar5 = (undefined *)((uVar3 & 0x1f) * 0x40 + (&DAT_45055ae0)[iVar2 >> 5]);
        }
        if ((puVar5[4] & 0x80) != 0) {
          iVar2 = FUN_45033dc3(&local_14,local_10,5,param_1);
          if ((iVar2 == 0) && (iVar2 = 0, 0 < local_14)) {
            do {
              piVar1 = &param_2->_cnt;
              *piVar1 = *piVar1 + -1;
              if (*piVar1 < 0) {
                uVar3 = FUN_450280b7((int)*(char *)((int)local_10 + iVar2),param_2);
              }
              else {
                *param_2->_ptr = *(char *)((int)local_10 + iVar2);
                uVar3 = (uint)(byte)*param_2->_ptr;
                param_2->_ptr = param_2->_ptr + 1;
              }
            } while ((uVar3 != 0xffffffff) && (iVar2 = iVar2 + 1, iVar2 < local_14));
          }
          goto LAB_45033715;
        }
      }
    }
  }
  piVar1 = &param_2->_cnt;
  *piVar1 = *piVar1 + -2;
  if (*piVar1 < 0) {
    FUN_45036574(param_1,param_2);
  }
  else {
    *(WCHAR *)param_2->_ptr = param_1;
    param_2->_ptr = param_2->_ptr + 2;
  }
LAB_45033715:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


