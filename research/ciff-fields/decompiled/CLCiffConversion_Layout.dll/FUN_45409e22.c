// Source: CLCiffConversion_Layout.dll @ 45409e22; FUN_45409e22

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_45409e22(void *this,wchar_t *param_1)

{
  int iVar1;
  wchar_t **ppwVar2;
  ushort *puVar3;
  int iVar4;
  ushort *puVar5;
  uint in_stack_00000018;
  int local_18;
  byte *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  puVar5 = (ushort *)&DAT_4545d140;
  iVar4 = 0;
  while( true ) {
    puVar3 = puVar5;
    if (7 < *(uint *)(puVar5 + 10)) {
      puVar3 = *(ushort **)puVar5;
    }
    ppwVar2 = &param_1;
    if (7 < in_stack_00000018) {
      ppwVar2 = (wchar_t **)param_1;
    }
    iVar1 = FUN_4542c973((ushort *)ppwVar2,puVar3);
    if (iVar1 == 0) break;
    puVar5 = puVar5 + 0xe;
    iVar4 = iVar4 + 1;
    if (0x4545d93b < (int)puVar5) {
      *(undefined4 *)((int)this + 0xa4) = 0x809;
LAB_45409eed:
      FUN_4540460c(&param_1,'\x01',0);
      return;
    }
  }
  ppwVar2 = &param_1;
  if (7 < in_stack_00000018) {
    ppwVar2 = (wchar_t **)param_1;
  }
  FUN_45402ac2(&local_18,(wchar_t *)ppwVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4540629a(&local_18,local_14,9);
  iVar1 = FUN_4542cae1(local_14[0],(byte *)"ARABICNUM");
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x150) = 1;
    *(undefined4 *)((int)this + 0xa4) = 0x809;
  }
  else {
    *(undefined4 *)((int)this + 0x150) = 0;
    *(uint *)((int)this + 0xa4) = (uint)(ushort)(&DAT_4545d158)[iVar4 * 0xe];
  }
  FUN_45402c5d((int *)local_14);
  FUN_45402c5d(&local_18);
  goto LAB_45409eed;
}


