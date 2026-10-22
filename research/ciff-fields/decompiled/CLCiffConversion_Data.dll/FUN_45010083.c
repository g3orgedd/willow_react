// Source: CLCiffConversion_Data.dll @ 45010083; FUN_45010083

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45010083(void *this,int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 **ppuVar3;
  undefined4 auStack_234 [60];
  undefined4 uStack_144;
  int *piVar4;
  LPCWSTR *ppWVar5;
  int local_120;
  LPCWSTR local_11c;
  undefined1 *local_118;
  undefined1 local_114 [268];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x110;
  local_8 = 0;
  FUN_4500201a(&local_11c,param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4500af7f(&local_11c,L" : ");
  ppWVar5 = &local_11c;
  piVar4 = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))();
  }
  FUN_4500f908(piVar4,ppWVar5);
  if (*(char *)this == '\x01') {
    puVar1 = FUN_4501cb23(&local_120,0xe017);
    uStack_144 = 0x45010106;
    MessageBoxW((HWND)0x0,local_11c,(LPCWSTR)*puVar1,0);
    FUN_45002256(&local_120);
  }
  local_118 = local_114;
  ATL::CW2WEX<128>::Init((CW2WEX<128> *)&local_118,local_11c);
  local_8 = CONCAT31(local_8._1_3_,2);
  ppuVar3 = &local_118;
  puVar1 = auStack_234;
  for (iVar2 = 0x41; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *ppuVar3;
    ppuVar3 = ppuVar3 + 1;
    puVar1 = puVar1 + 1;
  }
  FUN_4500274d(0x4503e8ec);
  if (local_118 != local_114) {
    FID_conflict__free(local_118);
  }
  FUN_45002256((int *)&local_11c);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  FUN_45022eb8();
  return;
}


