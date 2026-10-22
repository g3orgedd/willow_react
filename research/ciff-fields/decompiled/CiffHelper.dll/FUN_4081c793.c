// Source: CiffHelper.dll @ 4081c793; FUN_4081c793

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_4081c793(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  size_t sVar3;
  int iVar4;
  long lVar5;
  wchar_t ***pppwVar6;
  uint uVar7;
  int *piVar8;
  int in_stack_00000024;
  void *in_stack_0000002c;
  char in_stack_00000030;
  undefined2 local_44 [8];
  undefined4 local_34;
  undefined4 local_30;
  wchar_t **local_2c [4];
  undefined4 local_1c;
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  iVar1 = *(int *)((int)in_stack_0000002c + 0x10);
  local_8 = 0;
  if (((iVar1 != 0) && ((int)*param_4 <= in_stack_00000024)) && (in_stack_00000030 == '\0')) {
    local_34 = 0;
    local_30 = 7;
    local_44[0] = 0;
    local_8 = 1;
    if (-1 < iVar1) {
      uVar7 = 0;
      do {
        puVar2 = FUN_40811cd5(in_stack_0000002c,local_2c,uVar7,iVar1 - uVar7);
        FUN_4081a521(local_44,puVar2);
        FUN_4080653d(local_2c,'\x01',0);
        local_1c = 0;
        local_18 = 7;
        local_2c[0] = (wchar_t **)((uint)local_2c[0] & 0xffff0000);
        sVar3 = _wcslen(L"d");
        FID_conflict_assign(local_2c,(undefined8 *)&DAT_4084c9e4,sVar3);
        iVar4 = FUN_40808f0b(local_44,(wchar_t *)local_2c);
        FUN_4080653d(local_2c,'\x01',0);
        if (iVar4 == 0) {
          FUN_40811cd5(&stack0x00000014,local_2c,*param_4,1);
          pppwVar6 = local_2c;
          if (7 < local_18) {
            pppwVar6 = (wchar_t ***)local_2c[0];
          }
          lVar5 = __wtol((wchar_t *)pppwVar6);
          *param_1 = *param_1 + lVar5;
LAB_4081c895:
          *param_4 = *param_4 + 1;
LAB_4081cc85:
          FUN_4080653d(local_2c,'\x01',0);
        }
        else {
          local_1c = 0;
          local_18 = 7;
          local_2c[0] = (wchar_t **)((uint)local_2c[0] & 0xffff0000);
          sVar3 = _wcslen(L"dd");
          FID_conflict_assign(local_2c,(undefined8 *)&DAT_4084c9e8,sVar3);
          iVar4 = FUN_40808f0b(local_44,(wchar_t *)local_2c);
          FUN_4080653d(local_2c,'\x01',0);
          if (iVar4 == 0) {
            FUN_40811cd5(&stack0x00000014,local_2c,*param_4,2);
            pppwVar6 = local_2c;
            if (7 < local_18) {
              pppwVar6 = (wchar_t ***)local_2c[0];
            }
            iVar4 = __wtol((wchar_t *)pppwVar6);
LAB_4081cc7f:
            *param_1 = *param_1 + iVar4;
LAB_4081cc81:
            *param_4 = *param_4 + 2;
            goto LAB_4081cc85;
          }
          local_1c = 0;
          local_18 = 7;
          local_2c[0] = (wchar_t **)((uint)local_2c[0] & 0xffff0000);
          sVar3 = _wcslen(L"ddd");
          FID_conflict_assign(local_2c,(undefined8 *)&DAT_4084c9f0,sVar3);
          iVar4 = FUN_40808f0b(local_44,(wchar_t *)local_2c);
          FUN_4080653d(local_2c,'\x01',0);
          if (iVar4 == 0) {
            FUN_40811cd5(&stack0x00000014,local_2c,*param_4,3);
            pppwVar6 = local_2c;
            if (7 < local_18) {
              pppwVar6 = (wchar_t ***)local_2c[0];
            }
            lVar5 = __wtol((wchar_t *)pppwVar6);
            *param_1 = *param_1 + lVar5;
            *param_4 = *param_4 + 3;
            goto LAB_4081cc85;
          }
          local_1c = 0;
          local_18 = 7;
          local_2c[0] = (wchar_t **)((uint)local_2c[0] & 0xffff0000);
          sVar3 = _wcslen(L"M");
          FID_conflict_assign(local_2c,(undefined8 *)&DAT_4084b684,sVar3);
          iVar4 = FUN_40808f0b(local_44,(wchar_t *)local_2c);
          FUN_4080653d(local_2c,'\x01',0);
          if (iVar4 == 0) {
            FUN_40811cd5(&stack0x00000014,local_2c,*param_4,1);
            pppwVar6 = local_2c;
            if (7 < local_18) {
              pppwVar6 = (wchar_t ***)local_2c[0];
            }
            iVar4 = __wtol((wchar_t *)pppwVar6);
            piVar8 = param_2;
LAB_4081c9ec:
            *piVar8 = *piVar8 + iVar4;
            goto LAB_4081c895;
          }
          local_1c = 0;
          local_18 = 7;
          local_2c[0] = (wchar_t **)((uint)local_2c[0] & 0xffff0000);
          sVar3 = _wcslen(L"MM");
          FID_conflict_assign(local_2c,(undefined8 *)&DAT_4084c9f8,sVar3);
          iVar4 = FUN_40808f0b(local_44,(wchar_t *)local_2c);
          FUN_4080653d(local_2c,'\x01',0);
          if (iVar4 == 0) {
            FUN_40811cd5(&stack0x00000014,local_2c,*param_4,2);
            pppwVar6 = local_2c;
            if (7 < local_18) {
              pppwVar6 = (wchar_t ***)local_2c[0];
            }
            lVar5 = __wtol((wchar_t *)pppwVar6);
            *param_2 = *param_2 + lVar5;
            *param_4 = *param_4 + 2;
            goto LAB_4081cc85;
          }
          local_1c = 0;
          local_18 = 7;
          local_2c[0] = (wchar_t **)((uint)local_2c[0] & 0xffff0000);
          sVar3 = _wcslen(L"y");
          FID_conflict_assign(local_2c,(undefined8 *)&DAT_4084ca00,sVar3);
          iVar4 = FUN_40808f0b(local_44,(wchar_t *)local_2c);
          FUN_4080653d(local_2c,'\x01',0);
          if (iVar4 == 0) {
            FUN_40811cd5(&stack0x00000014,local_2c,*param_4,1);
            pppwVar6 = local_2c;
            if (7 < local_18) {
              pppwVar6 = (wchar_t ***)local_2c[0];
            }
            iVar4 = __wtol((wchar_t *)pppwVar6);
            piVar8 = param_3;
            goto LAB_4081c9ec;
          }
          local_1c = 0;
          local_18 = 7;
          local_2c[0] = (wchar_t **)((uint)local_2c[0] & 0xffff0000);
          sVar3 = _wcslen(L"yy");
          FID_conflict_assign(local_2c,(undefined8 *)&DAT_4084ca04,sVar3);
          iVar4 = FUN_40808f0b(local_44,(wchar_t *)local_2c);
          FUN_4080653d(local_2c,'\x01',0);
          if (iVar4 == 0) {
            FUN_40811cd5(&stack0x00000014,local_2c,*param_4,2);
            pppwVar6 = local_2c;
            if (7 < local_18) {
              pppwVar6 = (wchar_t ***)local_2c[0];
            }
            lVar5 = __wtol((wchar_t *)pppwVar6);
            *param_3 = *param_3 + lVar5;
            goto LAB_4081cc81;
          }
          local_1c = 0;
          local_18 = 7;
          local_2c[0] = (wchar_t **)((uint)local_2c[0] & 0xffff0000);
          sVar3 = _wcslen(L"yyyy");
          FID_conflict_assign(local_2c,(undefined8 *)L"yyyy",sVar3);
          iVar4 = FUN_40808f0b(local_44,(wchar_t *)local_2c);
          FUN_4080653d(local_2c,'\x01',0);
          if (iVar4 == 0) {
            FUN_40811cd5(&stack0x00000014,local_2c,*param_4,4);
            pppwVar6 = local_2c;
            if (7 < local_18) {
              pppwVar6 = (wchar_t ***)local_2c[0];
            }
            lVar5 = __wtol((wchar_t *)pppwVar6);
            *param_3 = *param_3 + lVar5;
            *param_4 = *param_4 + 4;
            goto LAB_4081cc85;
          }
          local_1c = 0;
          local_18 = 7;
          local_2c[0] = (wchar_t **)((uint)local_2c[0] & 0xffff0000);
          sVar3 = _wcslen(L"cl:ww");
          FID_conflict_assign(local_2c,(undefined8 *)L"cl:ww",sVar3);
          iVar4 = FUN_40808f0b(local_44,(wchar_t *)local_2c);
          FUN_4080653d(local_2c,'\x01',0);
          if (iVar4 == 0) {
LAB_4081cc5b:
            FUN_40811cd5(&stack0x00000014,local_2c,*param_4,2);
            pppwVar6 = local_2c;
            if (7 < local_18) {
              pppwVar6 = (wchar_t ***)local_2c[0];
            }
            lVar5 = __wtol((wchar_t *)pppwVar6);
            iVar4 = lVar5 * 7;
            goto LAB_4081cc7f;
          }
          local_1c = 0;
          local_18 = 7;
          local_2c[0] = (wchar_t **)((uint)local_2c[0] & 0xffff0000);
          sVar3 = _wcslen(L"cl:wwz");
          FID_conflict_assign(local_2c,(undefined8 *)L"cl:wwz",sVar3);
          iVar4 = FUN_40808f0b(local_44,(wchar_t *)local_2c);
          FUN_4080653d(local_2c,'\x01',0);
          if (iVar4 == 0) goto LAB_4081cc5b;
        }
        uVar7 = iVar1 + 1U;
      } while ((int)(iVar1 + 1U) <= iVar1);
    }
    FUN_4080653d(local_44,'\x01',0);
  }
  FUN_4080653d(&stack0x00000014,'\x01',0);
  FUN_4082d4c6();
  return;
}


