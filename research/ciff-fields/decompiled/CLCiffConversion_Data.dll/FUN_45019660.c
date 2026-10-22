// Source: CLCiffConversion_Data.dll @ 45019660; FUN_45019660

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_45019660(short *param_1,short *param_2)

{
  wchar_t *pwVar1;
  short sVar2;
  uint uVar3;
  BSTR pOVar4;
  size_t sVar5;
  int iVar6;
  char *pcVar7;
  int *piVar8;
  undefined4 uStackY_22c;
  OLECHAR *psz;
  OLECHAR local_208 [256];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  sVar2 = *param_1;
  if (sVar2 != 2) {
    if (sVar2 == 3) {
      sVar2 = *param_2;
      if (sVar2 == 2) {
        pOVar4 = (BSTR)(int)param_2[4];
      }
      else if (sVar2 == 3) {
        pOVar4 = *(BSTR *)(param_2 + 4);
      }
      else if (sVar2 == 8) {
        pwVar1 = *(wchar_t **)(param_2 + 4);
        if (pwVar1 == (wchar_t *)0x0) {
LAB_4501979e:
          pcVar7 = (char *)0x0;
        }
        else {
          sVar5 = _wcslen(pwVar1);
          iVar6 = sVar5 + 1;
          if (0x3fffffff < iVar6) goto LAB_4501979e;
          (local_208 + (-10 - iVar6))[0] = L'\x03';
          (local_208 + (-10 - iVar6))[1] = L'\0';
          *(int *)(local_208 + (-0xc - iVar6)) = iVar6 * 2;
          *(wchar_t **)(local_208 + (-0xe - iVar6)) = pwVar1;
          *(undefined1 **)(local_208 + (-0x10 - iVar6)) = &stack0xfffffde8;
          *(undefined4 *)((int)&uStackY_22c + iVar6 * -2) = 0x450197bc;
          pcVar7 = FUN_4500b2c8(*(LPSTR *)(local_208 + (-0x10 - iVar6)),
                                *(LPCWSTR *)(local_208 + (-0xe - iVar6)),
                                *(int *)(local_208 + (-0xc - iVar6)),
                                *(UINT *)(local_208 + (-10 - iVar6)));
        }
        pOVar4 = (BSTR)_atol(pcVar7);
      }
      else {
        if (sVar2 != 0xb) goto LAB_450196de;
        pOVar4 = (BSTR)(uint)(param_2[4] != 0);
      }
    }
    else {
      if (sVar2 != 8) {
        if (sVar2 == 9) {
          if (*(int **)(param_1 + 4) != (int *)0x0) {
            (**(code **)(**(int **)(param_1 + 4) + 8))();
            param_1[4] = 0;
            param_1[5] = 0;
          }
          piVar8 = *(int **)(param_2 + 4);
          *(int **)(param_1 + 4) = piVar8;
        }
        else {
          if (sVar2 == 0xb) {
            if (*param_2 != 0xb) goto LAB_450196de;
            goto LAB_450196d4;
          }
          if (sVar2 != 0xd) goto LAB_450196de;
          if (*(int **)(param_1 + 4) != (int *)0x0) {
            (**(code **)(**(int **)(param_1 + 4) + 8))();
            param_1[4] = 0;
            param_1[5] = 0;
          }
          if ((*param_2 == 0xd) || (*param_2 == 9)) {
            *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
          }
          piVar8 = *(int **)(param_1 + 4);
        }
        if (piVar8 != (int *)0x0) {
          (**(code **)(*piVar8 + 4))();
        }
        goto LAB_450196de;
      }
      if (*param_2 == 8) {
        SysFreeString(*(BSTR *)(param_1 + 4));
        psz = *(OLECHAR **)(param_2 + 4);
      }
      else {
        if (*param_2 == 2) {
          uVar3 = (uint)param_2[4];
        }
        else {
          uVar3 = *(uint *)(param_2 + 4);
        }
        uStackY_22c = 0x45019744;
        FUN_450235fc(uVar3,local_208,0xff,10);
        SysFreeString(*(BSTR *)(param_1 + 4));
        psz = local_208;
      }
      pOVar4 = SysAllocString(psz);
    }
    *(BSTR *)(param_1 + 4) = pOVar4;
    goto LAB_450196de;
  }
  sVar2 = *param_2;
  if ((sVar2 == 2) || (sVar2 == 3)) {
LAB_450196d4:
    sVar2 = param_2[4];
  }
  else {
    if (sVar2 != 8) goto LAB_450196de;
    pwVar1 = *(wchar_t **)(param_2 + 4);
    if (pwVar1 == (wchar_t *)0x0) {
LAB_4501981f:
      pcVar7 = (char *)0x0;
    }
    else {
      sVar5 = _wcslen(pwVar1);
      iVar6 = sVar5 + 1;
      if (0x3fffffff < iVar6) goto LAB_4501981f;
      (local_208 + (-10 - iVar6))[0] = L'\x03';
      (local_208 + (-10 - iVar6))[1] = L'\0';
      *(int *)(local_208 + (-0xc - iVar6)) = iVar6 * 2;
      *(wchar_t **)(local_208 + (-0xe - iVar6)) = pwVar1;
      *(undefined1 **)(local_208 + (-0x10 - iVar6)) = &stack0xfffffde8;
      *(undefined4 *)((int)&uStackY_22c + iVar6 * -2) = 0x4501983d;
      pcVar7 = FUN_4500b2c8(*(LPSTR *)(local_208 + (-0x10 - iVar6)),
                            *(LPCWSTR *)(local_208 + (-0xe - iVar6)),
                            *(int *)(local_208 + (-0xc - iVar6)),
                            *(UINT *)(local_208 + (-10 - iVar6)));
    }
    sVar2 = FUN_45025df4(pcVar7);
  }
  param_1[4] = sVar2;
LAB_450196de:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


