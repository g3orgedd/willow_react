// Source: CLCiffConversion_Data.dll @ 450275ab; FUN_450275ab

void __cdecl FUN_450275ab(UINT param_1,__crt_multibyte_data *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  UINT CodePage;
  uint uVar3;
  BOOL BVar4;
  BYTE *pBVar5;
  __crt_multibyte_data *p_Var6;
  wchar_t *pwVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  undefined2 *puVar11;
  uint uVar12;
  int local_20;
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  CodePage = FUN_450270fe(param_1);
  if (CodePage != 0) {
    uVar12 = 0;
    uVar3 = 0;
    local_20 = 0;
LAB_450275e7:
    if (*(UINT *)((int)&DAT_45051d30 + uVar3) != CodePage) goto code_r0x450275f3;
    FUN_45021c10((uint *)(param_2 + 0x18),0,0x101);
    pbVar8 = (byte *)(local_20 * 0x30 + 0x45051d40);
    do {
      bVar1 = *pbVar8;
      pbVar10 = pbVar8;
      while ((bVar1 != 0 && (bVar1 = pbVar10[1], bVar1 != 0))) {
        for (uVar3 = (uint)*pbVar10; (uVar3 <= bVar1 && (uVar3 < 0x100)); uVar3 = uVar3 + 1) {
          param_2[uVar3 + 0x19] =
               (__crt_multibyte_data)((byte)param_2[uVar3 + 0x19] | (&DAT_45051d28)[uVar12]);
          bVar1 = pbVar10[1];
        }
        pbVar10 = pbVar10 + 2;
        bVar1 = *pbVar10;
      }
      uVar12 = uVar12 + 1;
      pbVar8 = pbVar8 + 8;
    } while (uVar12 < 4);
    *(UINT *)(param_2 + 4) = CodePage;
    *(undefined4 *)(param_2 + 8) = 1;
    pwVar7 = CPtoLocaleName(CodePage);
    *(wchar_t **)(param_2 + 0x21c) = pwVar7;
    p_Var6 = param_2 + 0xc;
    puVar11 = (undefined2 *)(local_20 * 0x30 + 0x45051d34);
    iVar9 = 6;
    do {
      uVar2 = *puVar11;
      puVar11 = puVar11 + 1;
      *(undefined2 *)p_Var6 = uVar2;
      p_Var6 = p_Var6 + 2;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    goto LAB_4502777c;
  }
  FUN_4502716c((int)param_2);
LAB_45027786:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
code_r0x450275f3:
  local_20 = local_20 + 1;
  uVar3 = uVar3 + 0x30;
  if (0xef < uVar3) goto code_r0x45027601;
  goto LAB_450275e7;
code_r0x45027601:
  if (((CodePage != 65000) && (CodePage != 0xfde9)) &&
     (BVar4 = IsValidCodePage(CodePage & 0xffff), BVar4 != 0)) {
    BVar4 = GetCPInfo(CodePage,&local_1c);
    if (BVar4 == 0) {
      if (DAT_45055384 != 0) {
        FUN_4502716c((int)param_2);
      }
    }
    else {
      FUN_45021c10((uint *)(param_2 + 0x18),0,0x101);
      *(UINT *)(param_2 + 4) = CodePage;
      *(undefined4 *)(param_2 + 0x21c) = 0;
      if (local_1c.MaxCharSize < 2) {
        *(undefined4 *)(param_2 + 8) = 0;
      }
      else {
        pBVar5 = local_1c.LeadByte;
        while ((local_1c.LeadByte[0] != 0 && (bVar1 = pBVar5[1], bVar1 != 0))) {
          for (uVar3 = (uint)*pBVar5; uVar3 <= bVar1; uVar3 = uVar3 + 1) {
            param_2[uVar3 + 0x19] = (__crt_multibyte_data)((byte)param_2[uVar3 + 0x19] | 4);
          }
          pBVar5 = pBVar5 + 2;
          local_1c.LeadByte[0] = *pBVar5;
        }
        p_Var6 = param_2 + 0x1a;
        iVar9 = 0xfe;
        do {
          *p_Var6 = (__crt_multibyte_data)((byte)*p_Var6 | 8);
          p_Var6 = p_Var6 + 1;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        pwVar7 = CPtoLocaleName(*(int *)(param_2 + 4));
        *(wchar_t **)(param_2 + 0x21c) = pwVar7;
        *(undefined4 *)(param_2 + 8) = 1;
      }
      *(undefined4 *)(param_2 + 0xc) = 0;
      *(undefined4 *)(param_2 + 0x10) = 0;
      *(undefined4 *)(param_2 + 0x14) = 0;
LAB_4502777c:
      setSBUpLow(param_2);
    }
  }
  goto LAB_45027786;
}


