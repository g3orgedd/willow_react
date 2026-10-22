// Source: CLCiffConversion_Layout.dll @ 4542ea40; FUN_4542ea40

undefined4 __cdecl FUN_4542ea40(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  BOOL BVar5;
  undefined4 uVar6;
  int *piVar7;
  PEXCEPTION_RECORD local_1c;
  undefined4 local_18;
  uint *local_14;
  undefined4 local_10;
  uint local_c;
  char local_5;
  
  local_5 = '\0';
  iVar1 = (int)param_2 + 0x10;
  piVar7 = (int *)(*(uint *)((int)param_2 + 8) ^ DAT_4545d9f0);
  local_10 = 1;
  if (*piVar7 != -2) {
    FUN_4542a8d1(piVar7[1] + iVar1 ^ *(uint *)(*piVar7 + iVar1));
  }
  FUN_4542a8d1(piVar7[3] + iVar1 ^ *(uint *)(piVar7[2] + iVar1));
  if ((param_1->ExceptionFlags & 0x66) == 0) {
    local_1c = param_1;
    local_18 = param_3;
    *(PEXCEPTION_RECORD **)((int)param_2 + -4) = &local_1c;
    local_c = *(uint *)((int)param_2 + 0xc);
    if (*(uint *)((int)param_2 + 0xc) == 0xfffffffe) {
      return local_10;
    }
    do {
      local_14 = (uint *)(piVar7 + local_c * 3 + 4);
      uVar2 = *local_14;
      if ((undefined *)piVar7[local_c * 3 + 5] != (undefined *)0x0) {
        iVar4 = _EH4_CallFilterFunc((undefined *)piVar7[local_c * 3 + 5]);
        local_5 = '\x01';
        if (iVar4 < 0) {
          local_10 = 0;
          goto LAB_4542eb7b;
        }
        if (0 < iVar4) {
          if (((param_1->ExceptionCode == 0xe06d7363) &&
              (PTR____DestructExceptionObject_4544c1e0 != (undefined *)0x0)) &&
             (BVar5 = __IsNonwritableInCurrentImage((PBYTE)&PTR____DestructExceptionObject_4544c1e0)
             , BVar5 != 0)) {
            (*(code *)PTR____DestructExceptionObject_4544c1e0)(param_1,1);
          }
          _EH4_GlobalUnwind2(param_2,param_1);
          if (*(uint *)((int)param_2 + 0xc) != local_c) {
            _EH4_LocalUnwind((int)param_2,local_c,iVar1,&DAT_4545d9f0);
          }
          *(uint *)((int)param_2 + 0xc) = uVar2;
          if (*piVar7 != -2) {
            FUN_4542a8d1(piVar7[1] + iVar1 ^ *(uint *)(*piVar7 + iVar1));
          }
          FUN_4542a8d1(piVar7[3] + iVar1 ^ *(uint *)(piVar7[2] + iVar1));
          _EH4_TransferToHandler((undefined *)local_14[2]);
          pcVar3 = (code *)swi(3);
          uVar6 = (*pcVar3)();
          return uVar6;
        }
      }
      local_c = uVar2;
    } while (uVar2 != 0xfffffffe);
    if (local_5 == '\0') {
      return local_10;
    }
  }
  else {
    if (*(int *)((int)param_2 + 0xc) == -2) {
      return local_10;
    }
    _EH4_LocalUnwind((int)param_2,0xfffffffe,iVar1,&DAT_4545d9f0);
  }
LAB_4542eb7b:
  if (*piVar7 != -2) {
    FUN_4542a8d1(piVar7[1] + iVar1 ^ *(uint *)(*piVar7 + iVar1));
  }
  FUN_4542a8d1(piVar7[3] + iVar1 ^ *(uint *)(piVar7[2] + iVar1));
  return local_10;
}


