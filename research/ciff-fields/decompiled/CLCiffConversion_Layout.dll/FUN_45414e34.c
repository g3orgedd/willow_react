// Source: CLCiffConversion_Layout.dll @ 45414e34; FUN_45414e34

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_45414e34(int param_1)

{
  uint *puVar1;
  LPCSTR pCVar2;
  char *extraout_ECX;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  uint uStack_1088;
  int local_106c [13];
  char local_1038 [4128];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_45443f50;
  local_10 = ExceptionList;
  uStack_1088 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_1088;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_1088;
  puVar1 = &uStack_1088;
  if (DAT_4545fba4 != '\0') {
    pCVar2 = (LPCSTR)FUN_45408666();
    FUN_45402a65(local_106c,pCVar2);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_45404db2(local_106c,"claricomsystem.log");
    FUN_4542cca5(local_1038,0x1000,0xfff,param_1,&stack0x00000008);
    pcVar4 = local_1038;
    cVar5 = '\0';
    pcVar3 = extraout_ECX;
    FUN_45402a2f(&stack0xffffef6c,local_106c);
    FUN_4541b11f(pcVar3,pcVar4,cVar5);
    FUN_45402c5d(local_106c);
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  ExceptionList = local_10;
  FUN_4542a8d1(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


