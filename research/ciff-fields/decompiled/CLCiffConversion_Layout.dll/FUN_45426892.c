// Source: CLCiffConversion_Layout.dll @ 45426892; FUN_45426892

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45426892(void *this,char *param_1,int *param_2)

{
  char cVar1;
  LPVOID pvVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  LPCSTR pCVar7;
  LPSTR pCVar8;
  wchar_t *pwVar9;
  LPCSTR pCVar10;
  char *pcVar11;
  code *pcVar12;
  undefined1 local_50 [8];
  LPVOID local_48;
  byte *local_44;
  LPCSTR local_40;
  int local_3c;
  char local_37;
  char local_36;
  char local_35;
  byte local_34 [44];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x4542689e;
  if ((param_1 != (char *)0x0) && (param_2 != (int *)0x0)) {
    *param_2 = 0;
    sVar3 = _strlen(param_1);
    FUN_45423d47(local_50,sVar3 * 2);
    local_8 = 0;
    if (local_48 != (LPVOID)0x0) {
      *(char **)this = param_1;
      local_37 = '\0';
      iVar4 = FUN_45424be5(&local_37);
      if (-1 < iVar4) {
        local_3c = 0;
        local_36 = '\0';
        local_35 = '\0';
        cVar1 = *param_1;
        pcVar12 = CharNextA_exref;
        while (cVar1 != '\0') {
          if (local_37 == '\x01') {
            if (((local_3c == 0) &&
                (iVar5 = FUN_4542eea4(*(undefined1 (**) [16])this,(undefined1 (*) [16])&DAT_4544a8e0
                                     ), iVar5 != 0)) && (iVar5 == *(int *)this)) {
              uVar6 = (*pcVar12)(*(undefined4 *)this);
              *(undefined4 *)this = uVar6;
              uVar6 = (*pcVar12)(uVar6);
              *(undefined4 *)this = uVar6;
              uVar6 = (*pcVar12)(uVar6);
              *(undefined4 *)this = uVar6;
              uVar6 = (*pcVar12)(uVar6);
              *(undefined4 *)this = uVar6;
              iVar5 = FUN_454242ea(local_50,L"HKCU\r\n{\tSoftware\r\n\t{\r\n\t\tClasses");
              if (iVar5 == 0) goto LAB_45426aef;
              local_36 = '\x01';
            }
            if (**(char **)this == '\'') {
              if (local_35 != '\0') {
                iVar5 = FUN_45425a3e(this);
                if (iVar5 != 0) {
                  local_35 = '\0';
                  goto LAB_454269b7;
                }
                pCVar7 = (LPCSTR)(*pcVar12)(*(undefined4 *)this);
                *(LPCSTR *)this = pCVar7;
                pCVar8 = CharNextA(pCVar7);
                iVar5 = FUN_4542486f(local_50,pCVar7,(int)pCVar8 - (int)pCVar7);
                pcVar12 = CharNextA_exref;
                if (iVar5 != 0) goto LAB_454269b3;
                goto LAB_45426aef;
              }
              local_35 = '\x01';
            }
            else {
LAB_454269b3:
              if (local_35 == '\0') {
LAB_454269b7:
                if (**(char **)this == '{') {
                  local_3c = local_3c + 1;
                }
                if (((**(char **)this == '}') && (local_3c = local_3c + -1, local_3c == 0)) &&
                   (local_36 == '\x01')) {
                  iVar5 = FUN_454242ea(local_50,L"\r\n\t}\r\n}\r\n");
                  if (iVar5 == 0) goto LAB_45426aef;
                  local_36 = '\0';
                }
              }
            }
          }
          local_44 = *(byte **)this;
          if (*local_44 == 0x25) {
            local_40 = (LPCSTR)(*pcVar12)(local_44);
            *(LPCSTR *)this = local_40;
            if (*local_40 == '%') {
              iVar5 = (*pcVar12)(local_40);
              iVar5 = FUN_4542486f(local_50,local_40,iVar5 - (int)local_40);
              if (iVar5 == 0) goto LAB_45426aef;
            }
            else {
              local_40 = FUN_45427c18(local_40,'%');
              if ((local_40 == (char *)0x0) || (0x1f < (int)local_40 - *(int *)this))
              goto LAB_45426aef;
              iVar5 = FUN_4542a6d4(local_34,0x20,*(byte **)this,(int)local_40 - *(int *)this);
              FUN_45402fb2(iVar5);
              local_44 = local_34;
              pwVar9 = (wchar_t *)FUN_45426685((void *)(*(int *)((int)this + 4) + 4),&local_44);
              if ((pwVar9 == (wchar_t *)0x0) ||
                 (iVar5 = FUN_454242ea(local_50,pwVar9), pCVar7 = local_40, iVar5 == 0))
              goto LAB_45426aef;
              pCVar10 = *(LPCSTR *)this;
              while (pCVar10 != pCVar7) {
                pCVar10 = (LPCSTR)(*pcVar12)(*(undefined4 *)this);
                *(LPCSTR *)this = pCVar10;
              }
            }
          }
          else {
            iVar5 = (*pcVar12)(local_44);
            iVar5 = FUN_4542486f(local_50,local_44,iVar5 - (int)local_44);
            if (iVar5 == 0) {
              iVar4 = -0x7ff8fff2;
              break;
            }
          }
          pcVar11 = (char *)(*pcVar12)(*(undefined4 *)this);
          *(char **)this = pcVar11;
          cVar1 = *pcVar11;
        }
        pvVar2 = local_48;
        if (-1 < iVar4) {
          local_48 = (LPVOID)0x0;
          *param_2 = (int)pvVar2;
        }
      }
    }
LAB_45426aef:
    CoTaskMemFree(local_48);
  }
  FUN_4542a957();
  return;
}


