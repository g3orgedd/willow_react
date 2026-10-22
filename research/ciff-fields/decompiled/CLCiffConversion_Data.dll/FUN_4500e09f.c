// Source: CLCiffConversion_Data.dll @ 4500e09f; FUN_4500e09f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_4500e09f(undefined4 *param_1,void *param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  size_t sVar3;
  uint uVar4;
  undefined4 *puVar5;
  wchar_t *_Memory;
  undefined4 *puVar6;
  undefined1 local_2c [16];
  undefined4 *local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x4500e0ab;
  basic_string<>(local_2c,(wchar_t *)*param_1);
  local_8 = 0;
  FUN_45014125(local_2c,(undefined8 *)&DAT_4503e530,0);
  puVar2 = local_1c;
  puVar6 = (undefined4 *)0x0;
  if (local_1c != (undefined4 *)0x0) {
    do {
      sVar3 = _wcslen(L"[");
      uVar4 = FUN_45007b2e(local_2c,(uint)puVar6,1,L"[",sVar3);
      if (uVar4 == 0) {
        sVar3 = _wcslen(L"]");
        puVar5 = (undefined4 *)FUN_450142b7(local_2c,L"]",(uint)puVar6,sVar3);
        if (puVar5 == (undefined4 *)0xffffffff) break;
        sVar3 = _wcslen(L"`");
        FUN_45008165(local_2c,puVar6,(undefined4 *)0x1,(undefined8 *)&DAT_4503e534,sVar3);
        sVar3 = _wcslen(L"`");
        FUN_45008165(local_2c,puVar5,(undefined4 *)0x1,(undefined8 *)&DAT_4503e534,sVar3);
      }
      else {
        sVar3 = _wcslen(L" ");
        puVar5 = (undefined4 *)FUN_450142b7(local_2c,L" ",(uint)puVar6,sVar3);
        if (puVar5 == (undefined4 *)0xffffffff) break;
      }
      puVar6 = (undefined4 *)((int)puVar5 + 1);
    } while (puVar6 < puVar2);
  }
  puVar2 = local_1c;
  lVar1 = (ulonglong)((int)local_1c + 1) * 2;
  _Memory = (wchar_t *)FUN_45020ebb(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
  FUN_45013fac(local_2c,_Memory,(rsize_t)puVar2,(uint)puVar2,0);
  _Memory[(int)local_1c] = L'\0';
  FUN_45002326(param_2,_Memory);
  FID_conflict__free(_Memory);
  FUN_450046d9(local_2c,'\x01',0);
  FUN_45022eb8();
  return;
}


