// Source: CLCiffConversion_Data.dll @ 45005fd1; FUN_45005fd1

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_45005fd1(int param_1)

{
  uint *puVar1;
  LPCWSTR pWVar2;
  OLECHAR *extraout_ECX;
  OLECHAR *pOVar3;
  char *pcVar4;
  char cVar5;
  uint uStack_1088;
  int local_106c;
  void *local_1068 [12];
  char local_1038 [4128];
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_45039bcb;
  local_10 = ExceptionList;
  uStack_1088 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_1088;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = uStack_1088;
  puVar1 = &uStack_1088;
  if (DAT_45053981 != '\0') {
    pWVar2 = (LPCWSTR)FUN_4501ca70();
    FUN_450020a5(&local_106c,pWVar2);
    local_8._0_1_ = 1;
    FUN_45002050(local_1068,"claricomsystem.log");
    local_8._0_1_ = 2;
    FUN_450035a3(&local_106c,*(int *)((int)local_1068[0] + -8),local_1068[0]);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_45002256((int *)local_1068);
    FUN_45022c9f(local_1038,0x1000,0xfff,param_1,&stack0x00000008);
    pcVar4 = local_1038;
    cVar5 = '\0';
    pOVar3 = extraout_ECX;
    FUN_4500201a(&stack0xffffef6c,&local_106c);
    FUN_45006df5(pOVar3,pcVar4,cVar5);
    FUN_45002256(&local_106c);
    puVar1 = (uint *)local_14;
  }
  local_14 = (undefined1 *)puVar1;
  ExceptionList = local_10;
  FUN_45022e32(local_18 ^ (uint)&stack0xfffffffc);
  return;
}


