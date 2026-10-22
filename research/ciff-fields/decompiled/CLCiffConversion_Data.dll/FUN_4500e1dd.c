// Source: CLCiffConversion_Data.dll @ 4500e1dd; FUN_4500e1dd

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500e1dd(void *this,undefined4 *param_1,void *param_2)

{
  size_t sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_1bc [16];
  uint local_1ac;
  wchar_t local_1a4 [99];
  short sStack_de;
  wchar_t local_dc [106];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1b0;
  local_8 = 0x4500e1ec;
  if (*(int *)((int)this + 0x14) != 0) {
    basic_string<>(local_1bc,(wchar_t *)*param_1);
    local_8 = 0;
    sVar1 = _wcslen(L" ");
    FUN_45014125(local_1bc,(undefined8 *)&DAT_4503e510,sVar1);
    uVar4 = 0;
    if (local_1ac != 0) {
      do {
        sVar1 = _wcslen(L"[");
        uVar2 = FUN_45007b2e(local_1bc,uVar4,1,L"[",sVar1);
        if (uVar2 == 0) {
          sVar1 = _wcslen(L"]");
          uVar2 = FUN_450142b7(local_1bc,L"]",uVar4,sVar1);
          uVar2 = uVar2 + 1;
        }
        else {
          sVar1 = _wcslen(L" ");
          uVar2 = FUN_450142b7(local_1bc,L" ",uVar4,sVar1);
        }
        if (local_1ac <= uVar2) break;
        FUN_45021c10((uint *)local_dc,0,200);
        FUN_45013fac(local_1bc,local_dc,100,uVar2 - uVar4,uVar4);
        uVar4 = uVar2 + 1;
        sVar1 = _wcslen(local_dc);
        if ((&sStack_de)[sVar1] == 0x3b) {
          sVar1 = _wcslen(local_dc);
          if (199 < sVar1 * 2 - 2) {
                    /* WARNING: Subroutine does not return */
            ___report_rangecheckfailure();
          }
          (&sStack_de)[sVar1] = 0;
        }
        FUN_45021540((undefined8 *)local_1a4,(undefined8 *)local_dc,200);
        FUN_45023e2d(local_1a4,100);
        iVar3 = _wcscmp(local_1a4,L"FROM");
        if ((iVar3 != 0) && (local_dc[0] == L'[')) {
          local_dc[0] = L'\"';
          sVar1 = _wcslen(local_dc);
          (&sStack_de)[sVar1] = 0x22;
        }
        iVar3 = FUN_45002522(param_2,local_dc);
        if ((iVar3 < 0) || (iVar3 = FUN_45002522(param_2,L" "), iVar3 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_45002735(iVar3);
        }
      } while (uVar4 < local_1ac);
    }
    FUN_450046d9(local_1bc,'\x01',0);
  }
  FUN_45022eb8();
  return;
}


