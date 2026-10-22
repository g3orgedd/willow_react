// Source: CLCiffConversion_Data.dll @ 4500e002; FUN_4500e002

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500e002(void *this,undefined4 *param_1,void *param_2)

{
  OLECHAR ****ppppOVar1;
  int *piVar2;
  OLECHAR ****ppppOVar3;
  OLECHAR ****ppppOVar4;
  bool bVar5;
  int local_34;
  undefined4 local_30;
  OLECHAR ***local_2c [4];
  int local_1c;
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x4500e00e;
  if (*(int *)((int)this + 0x14) != 0) {
    basic_string<>(local_2c,(wchar_t *)*param_1);
    local_8 = 0;
    bVar5 = 7 < local_18;
    ppppOVar3 = local_2c;
    if (bVar5) {
      ppppOVar3 = (OLECHAR ****)local_2c[0];
    }
    ppppOVar1 = local_2c;
    if (bVar5) {
      ppppOVar1 = (OLECHAR ****)local_2c[0];
    }
    ppppOVar4 = local_2c;
    if (bVar5) {
      ppppOVar4 = (OLECHAR ****)local_2c[0];
    }
    piVar2 = FUN_4500a81b(&local_30,(short *)ppppOVar4,(OLECHAR *)((int)ppppOVar1 + local_1c * 2));
    FUN_45014266(local_2c,&local_34,*piVar2,(int)((int)ppppOVar3 + local_1c * 2));
    ppppOVar3 = local_2c;
    if (7 < local_18) {
      ppppOVar3 = (OLECHAR ****)local_2c[0];
    }
    FUN_45002326(param_2,(OLECHAR *)ppppOVar3);
    FUN_450046d9(local_2c,'\x01',0);
  }
  FUN_45022eb8();
  return;
}


