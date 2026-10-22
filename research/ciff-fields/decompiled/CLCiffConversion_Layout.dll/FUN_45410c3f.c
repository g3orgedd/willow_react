// Source: CLCiffConversion_Layout.dll @ 45410c3f; FUN_45410c3f

void __fastcall FUN_45410c3f(int param_1)

{
  int iVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  uint uVar4;
  wchar_t *local_14;
  wchar_t *local_10;
  undefined2 *local_c;
  int local_8;
  
  *(undefined2 *)(param_1 + 0xc) = 99;
  local_10 = (wchar_t *)(param_1 + 0x70);
  local_14 = (wchar_t *)(param_1 + 0xe);
  *local_14 = L'\0';
  local_c = (undefined2 *)(param_1 + 0x3e);
  *local_c = 0;
  uVar4 = 0;
  local_8 = 0;
  do {
    pwVar3 = (wchar_t *)((int)&DAT_45448800 + uVar4);
    if (((*pwVar3 == L'c') && (*(short *)(&UNK_45448802 + uVar4) == 0x6c)) &&
       (*(short *)(&UNK_45448804 + uVar4) == 0x3a)) {
      iVar1 = FUN_45410fd0((wchar_t *)(param_1 + 0x3e),*(wchar_t *)(&UNK_45448806 + uVar4));
      if (iVar1 == -1) {
        *local_c = *(undefined2 *)(&UNK_45448806 + uVar4);
        local_c = local_c + 1;
        *local_c = 0;
      }
      sVar2 = _wcslen(pwVar3);
      if ((*(short *)(&DAT_454487fe + (sVar2 + local_8) * 2) == 99) &&
         (*(wchar_t *)(&UNK_45448806 + uVar4) != L'c')) {
        iVar1 = FUN_45410fd0((wchar_t *)(param_1 + 0x70),*(wchar_t *)(&UNK_45448806 + uVar4));
        if (iVar1 == -1) {
          *local_10 = *(wchar_t *)(&UNK_45448806 + uVar4);
          pwVar3 = local_10 + 1;
          local_10 = pwVar3;
          goto LAB_45410d35;
        }
      }
    }
    else {
      iVar1 = FUN_45410fd0((wchar_t *)(param_1 + 0xc),*pwVar3);
      if (iVar1 == -1) {
        *local_14 = *pwVar3;
        pwVar3 = local_14 + 1;
        local_14 = pwVar3;
LAB_45410d35:
        *pwVar3 = L'\0';
      }
    }
    local_8 = local_8 + 0xc;
    uVar4 = uVar4 + 0x18;
    if (0x6ef < uVar4) {
      return;
    }
  } while( true );
}


