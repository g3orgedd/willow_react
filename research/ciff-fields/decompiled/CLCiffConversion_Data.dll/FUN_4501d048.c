// Source: CLCiffConversion_Data.dll @ 4501d048; FUN_4501d048

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4501d048(void *this,LPCWSTR param_1)

{
  int iVar1;
  LPCWSTR *ppWVar2;
  ushort *puVar3;
  int iVar4;
  ushort *puVar5;
  uint in_stack_00000018;
  int local_18;
  wchar_t *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  puVar5 = (ushort *)&DAT_450510b8;
  iVar4 = 0;
  while( true ) {
    puVar3 = puVar5;
    if (7 < *(uint *)(puVar5 + 10)) {
      puVar3 = *(ushort **)puVar5;
    }
    ppWVar2 = &param_1;
    if (7 < in_stack_00000018) {
      ppWVar2 = (LPCWSTR *)param_1;
    }
    iVar1 = FUN_450226ba((ushort *)ppWVar2,puVar3);
    if (iVar1 == 0) break;
    puVar5 = puVar5 + 0xe;
    iVar4 = iVar4 + 1;
    if (0x450518b3 < (int)puVar5) {
      *(undefined4 *)((int)this + 0xa4) = 0x809;
LAB_4501d113:
      FUN_450046d9(&param_1,'\x01',0);
      return;
    }
  }
  ppWVar2 = &param_1;
  if (7 < in_stack_00000018) {
    ppWVar2 = (LPCWSTR *)param_1;
  }
  FUN_450020a5(&local_18,(LPCWSTR)ppWVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_45003e81(&local_18,local_14,9);
  iVar1 = _wcscmp(local_14[0],L"ARABICNUM");
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x150) = 1;
    *(undefined4 *)((int)this + 0xa4) = 0x809;
  }
  else {
    *(undefined4 *)((int)this + 0x150) = 0;
    *(uint *)((int)this + 0xa4) = (uint)(ushort)(&DAT_450510d0)[iVar4 * 0xe];
  }
  FUN_45002256((int *)local_14);
  FUN_45002256(&local_18);
  goto LAB_4501d113;
}


