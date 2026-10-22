// Source: CLCiffConversion_Data.dll @ 4500dd62; FUN_4500dd62

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_4500dd62(void *this,undefined4 *param_1,void *param_2)

{
  bool bVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_284 [16];
  uint local_274;
  wchar_t local_26c [99];
  wchar_t wStack_1a6;
  undefined1 local_1a4 [198];
  short sStack_de;
  wchar_t local_dc;
  wchar_t local_da [105];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x27c;
  local_8 = 0x4500dd71;
  if (*(int *)((int)this + 0x14) != 0) {
    bVar1 = false;
    basic_string<>(local_284,(wchar_t *)*param_1);
    local_8 = 0;
    sVar2 = _wcslen(L" ");
    FUN_45014125(local_284,(undefined8 *)&DAT_4503e510,sVar2);
    uVar5 = 0;
    if (local_274 != 0) {
      do {
        sVar2 = _wcslen(L"[");
        uVar3 = FUN_45007b2e(local_284,uVar5,1,L"[",sVar2);
        if (uVar3 == 0) {
          sVar2 = _wcslen(L"]");
          uVar3 = FUN_450142b7(local_284,L"]",uVar5,sVar2);
          uVar3 = uVar3 + 1;
        }
        else {
          sVar2 = _wcslen(L" ");
          uVar3 = FUN_450142b7(local_284,L" ",uVar5,sVar2);
        }
        if (local_274 <= uVar3) break;
        FUN_45021c10((uint *)&local_dc,0,200);
        FUN_45013fac(local_284,&local_dc,100,uVar3 - uVar5,uVar5);
        uVar5 = uVar3 + 1;
        sVar2 = _wcslen(&local_dc);
        if ((&sStack_de)[sVar2] == 0x3b) {
          sVar2 = _wcslen(&local_dc);
          if (199 < sVar2 * 2 - 2) goto LAB_4500dff6;
          (&sStack_de)[sVar2] = 0;
        }
        FUN_45021540((undefined8 *)local_26c,(undefined8 *)&local_dc,200);
        FUN_45023e2d(local_26c,100);
        iVar4 = _wcscmp(local_26c,L"FROM");
        if (iVar4 == 0) {
          bVar1 = true;
        }
        else if (local_dc == L'[') {
          if (bVar1) {
            FUN_45021c10((uint *)local_1a4,0,200);
            _wcscpy_s((wchar_t *)local_1a4,100,local_da);
            sVar2 = _wcslen((wchar_t *)local_1a4);
            if (199 < sVar2 * 2 - 2) {
LAB_4500dff6:
                    /* WARNING: Subroutine does not return */
              ___report_rangecheckfailure();
            }
            (&wStack_1a6)[sVar2] = L'\0';
            FUN_45021c10((uint *)&local_dc,0,200);
            _wcscpy_s(&local_dc,100,(wchar_t *)local_1a4);
            bVar1 = false;
          }
          else {
            local_dc = L'\"';
            sVar2 = _wcslen(&local_dc);
            (&sStack_de)[sVar2] = 0x22;
          }
        }
        iVar4 = FUN_45002522(param_2,&local_dc);
        if ((iVar4 < 0) || (iVar4 = FUN_45002522(param_2,L" "), iVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_45002735(iVar4);
        }
      } while (uVar5 < local_274);
    }
    FUN_450046d9(local_284,'\x01',0);
  }
  FUN_45022eb8();
  return;
}


