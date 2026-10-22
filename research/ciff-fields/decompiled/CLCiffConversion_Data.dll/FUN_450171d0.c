// Source: CLCiffConversion_Data.dll @ 450171d0; FUN_450171d0

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_450171d0(void *this,wchar_t *param_1,int *param_2)

{
  wchar_t wVar1;
  short *psVar2;
  LPVOID pvVar3;
  size_t sVar4;
  int iVar5;
  undefined1 (*pauVar6) [16];
  undefined4 uVar7;
  int iVar8;
  void *pvVar9;
  LPCWSTR pWVar10;
  LPCWSTR pWVar11;
  wchar_t *pwVar12;
  code *pcVar13;
  short *local_70;
  int *local_6c;
  undefined1 local_68 [8];
  LPVOID local_60;
  int local_5c;
  char local_57;
  char local_56;
  char local_55;
  short local_54 [38];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0x450171dc;
  local_6c = param_2;
  *param_2 = 0;
  sVar4 = _wcslen(param_1);
  FUN_45014776(local_68,sVar4 * 2);
  local_8 = 0;
  if (local_60 != (LPVOID)0x0) {
    local_57 = '\0';
    *(wchar_t **)this = param_1;
    iVar5 = FUN_450155c6(&local_57);
    if (-1 < iVar5) {
      local_5c = 0;
      local_56 = '\0';
      local_55 = '\0';
      wVar1 = *param_1;
      pcVar13 = CharNextW_exref;
      while (wVar1 != L'\0') {
        if (local_57 == '\x01') {
          if (((local_5c == 0) &&
              (pauVar6 = FUN_45022427(*(undefined1 (**) [16])this,(undefined1 (*) [16])L"HKCR"),
              pauVar6 != (undefined1 (*) [16])0x0)) && (pauVar6 == *(undefined1 (**) [16])this)) {
            uVar7 = (*pcVar13)(*(undefined4 *)this);
            *(undefined4 *)this = uVar7;
            uVar7 = (*pcVar13)(uVar7);
            *(undefined4 *)this = uVar7;
            uVar7 = (*pcVar13)(uVar7);
            *(undefined4 *)this = uVar7;
            uVar7 = (*pcVar13)(uVar7);
            *(undefined4 *)this = uVar7;
            iVar8 = FUN_45014e02(local_68,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
            if (iVar8 == 0) goto LAB_450173fb;
            local_56 = '\x01';
          }
          if (**(short **)this == 0x27) {
            if (local_55 != '\0') {
              iVar8 = FUN_4501638e(this);
              if (iVar8 != 0) {
                local_55 = '\0';
                goto LAB_450172d8;
              }
              pvVar9 = (void *)(*pcVar13)(*(undefined4 *)this);
              *(void **)this = pvVar9;
              iVar8 = FUN_450152b1(local_68,pvVar9,1);
              if (iVar8 != 0) goto LAB_450172d4;
              goto LAB_450173fb;
            }
            local_55 = '\x01';
          }
          else {
LAB_450172d4:
            if (local_55 == '\0') {
LAB_450172d8:
              if (**(short **)this == 0x7b) {
                local_5c = local_5c + 1;
              }
              if (((**(short **)this == 0x7d) && (local_5c = local_5c + -1, local_5c == 0)) &&
                 (local_56 == '\x01')) {
                iVar8 = FUN_45014e02(local_68,L"\r\n\t}\r\n}\r\n");
                if (iVar8 == 0) goto LAB_450173fb;
                local_56 = '\0';
              }
            }
          }
        }
        psVar2 = *(short **)this;
        if (*psVar2 == 0x25) {
          pWVar10 = (LPCWSTR)(*pcVar13)(psVar2);
          *(LPCWSTR *)this = pWVar10;
          if (*pWVar10 == L'%') {
            iVar8 = FUN_450152b1(local_68,pWVar10,1);
            if (iVar8 == 0) goto LAB_450173fb;
          }
          else {
            pWVar10 = FUN_45018370(pWVar10,L'%');
            if ((pWVar10 == (LPCWSTR)0x0) ||
               (iVar8 = (int)pWVar10 - *(int *)this >> 1, 0x1f < iVar8)) goto LAB_450173fb;
            iVar8 = FUN_45025980(local_54,0x20,*(short **)this,iVar8);
            FUN_450026fa(iVar8);
            local_70 = local_54;
            pwVar12 = (wchar_t *)FUN_45016f42((void *)(*(int *)((int)this + 4) + 4),&local_70);
            if ((pwVar12 == (wchar_t *)0x0) || (iVar8 = FUN_45014e02(local_68,pwVar12), iVar8 == 0))
            goto LAB_450173fb;
            pWVar11 = *(LPCWSTR *)this;
            pcVar13 = CharNextW_exref;
            while (CharNextW_exref = pcVar13, pWVar11 != pWVar10) {
              pWVar11 = CharNextW(*(LPCWSTR *)this);
              *(LPCWSTR *)this = pWVar11;
              pcVar13 = CharNextW_exref;
            }
          }
        }
        else {
          iVar8 = FUN_450152b1(local_68,psVar2,1);
          if (iVar8 == 0) {
            iVar5 = -0x7ff8fff2;
            break;
          }
        }
        pwVar12 = (wchar_t *)(*pcVar13)(*(undefined4 *)this);
        *(wchar_t **)this = pwVar12;
        wVar1 = *pwVar12;
      }
      pvVar3 = local_60;
      if (-1 < iVar5) {
        local_60 = (LPVOID)0x0;
        *local_6c = (int)pvVar3;
      }
    }
  }
LAB_450173fb:
  CoTaskMemFree(local_60);
  FUN_45022eb8();
  return;
}


