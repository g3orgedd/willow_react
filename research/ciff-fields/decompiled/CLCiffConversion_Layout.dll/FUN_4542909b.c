// Source: CLCiffConversion_Layout.dll @ 4542909b; FUN_4542909b

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_4542909b(short *param_1,short *param_2)

{
  wchar_t *pwVar1;
  int iVar2;
  short sVar3;
  size_t sVar4;
  OLECHAR *psz;
  BSTR pOVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 uStackY_12c;
  char local_108 [256];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  sVar3 = *param_1;
  if (sVar3 != 2) {
    if (sVar3 == 3) {
      sVar3 = *param_2;
      if (sVar3 == 2) {
        pOVar5 = (BSTR)(int)param_2[4];
      }
      else if (sVar3 == 3) {
        pOVar5 = *(BSTR *)(param_2 + 4);
      }
      else if (sVar3 == 8) {
        pwVar1 = *(wchar_t **)(param_2 + 4);
        if (pwVar1 == (wchar_t *)0x0) {
LAB_454291cd:
          pcVar7 = (char *)0x0;
        }
        else {
          sVar4 = _wcslen(pwVar1);
          iVar6 = sVar4 + 1;
          if (0x3fffffff < iVar6) goto LAB_454291cd;
          iVar2 = iVar6 * -2;
          pcVar8 = local_108 + iVar2 + -0x14;
          pcVar8[0] = '\x03';
          pcVar8[1] = '\0';
          pcVar8[2] = '\0';
          pcVar8[3] = '\0';
          *(int *)(local_108 + iVar2 + -0x18) = iVar6 * 2;
          *(wchar_t **)(local_108 + iVar2 + -0x1c) = pwVar1;
          *(undefined1 **)(local_108 + iVar2 + -0x20) = &stack0xfffffee8;
          *(undefined4 *)((int)&uStackY_12c + iVar2) = 0x454291eb;
          pcVar7 = AtlW2AHelper(*(char **)(local_108 + iVar2 + -0x20),
                                *(wchar_t **)(local_108 + iVar2 + -0x1c),
                                *(int *)(local_108 + iVar2 + -0x18),
                                *(uint *)(local_108 + iVar2 + -0x14));
        }
        pOVar5 = (BSTR)_atol(pcVar7);
      }
      else {
        if (sVar3 != 0xb) goto LAB_4542927e;
        pOVar5 = (BSTR)(uint)(param_2[4] != 0);
      }
    }
    else {
      if (sVar3 != 8) {
        if (sVar3 == 0xd) {
          if (*(int **)(param_1 + 4) != (int *)0x0) {
            (**(code **)(**(int **)(param_1 + 4) + 8))();
            param_1[4] = 0;
            param_1[5] = 0;
          }
          if ((*param_2 == 0xd) || (*param_2 == 9)) {
            *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
          }
          if (*(int **)(param_1 + 4) != (int *)0x0) {
            (**(code **)(**(int **)(param_1 + 4) + 4))();
          }
        }
        goto LAB_4542927e;
      }
      if (*param_2 == 8) {
        SysFreeString(*(BSTR *)(param_1 + 4));
        psz = *(OLECHAR **)(param_2 + 4);
      }
      else {
        if (*param_2 == 2) {
          uStackY_12c = 0x45429139;
          FUN_4542d4fb((int)param_2[4],local_108,0xff,10);
        }
        else {
          uStackY_12c = 0x4542918c;
          FUN_4542d524(*(uint *)(param_2 + 4),local_108,0xff,10);
        }
        SysFreeString(*(BSTR *)(param_1 + 4));
        sVar4 = _strlen(local_108);
        if ((int)(sVar4 + 1) < 0x40000000) {
          uStackY_12c = 0x4542917b;
          psz = AtlA2WHelper((wchar_t *)&stack0xfffffee8,local_108,sVar4 + 1,3);
        }
        else {
          psz = (OLECHAR *)0x0;
        }
      }
      pOVar5 = SysAllocString(psz);
    }
    *(BSTR *)(param_1 + 4) = pOVar5;
    goto LAB_4542927e;
  }
  sVar3 = *param_2;
  if ((sVar3 == 2) || (sVar3 == 3)) {
    sVar3 = param_2[4];
  }
  else {
    if (sVar3 != 8) goto LAB_4542927e;
    pwVar1 = *(wchar_t **)(param_2 + 4);
    if (pwVar1 == (wchar_t *)0x0) {
LAB_45429246:
      pcVar7 = (char *)0x0;
    }
    else {
      sVar4 = _wcslen(pwVar1);
      iVar6 = sVar4 + 1;
      if (0x3fffffff < iVar6) goto LAB_45429246;
      iVar2 = iVar6 * -2;
      pcVar9 = local_108 + iVar2 + -0x14;
      pcVar9[0] = '\x03';
      pcVar9[1] = '\0';
      pcVar9[2] = '\0';
      pcVar9[3] = '\0';
      *(int *)(local_108 + iVar2 + -0x18) = iVar6 * 2;
      *(wchar_t **)(local_108 + iVar2 + -0x1c) = pwVar1;
      *(undefined1 **)(local_108 + iVar2 + -0x20) = &stack0xfffffee8;
      *(undefined4 *)((int)&uStackY_12c + iVar2) = 0x45429264;
      pcVar7 = AtlW2AHelper(*(char **)(local_108 + iVar2 + -0x20),
                            *(wchar_t **)(local_108 + iVar2 + -0x1c),
                            *(int *)(local_108 + iVar2 + -0x18),*(uint *)(local_108 + iVar2 + -0x14)
                           );
    }
    sVar3 = FUN_4542aefb(pcVar7);
  }
  param_1[4] = sVar3;
LAB_4542927e:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


