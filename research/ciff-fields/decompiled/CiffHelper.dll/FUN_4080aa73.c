// Source: CiffHelper.dll @ 4080aa73; FUN_4080aa73

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __thiscall FUN_4080aa73(void *this,void *param_1,LPCWSTR param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  wchar_t *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  FUN_408030ad(param_1,(int *)param_2);
  local_8 = 0;
  FUN_408030e3(&param_2,*(LPCWSTR *)((int)this + 0x20));
  local_8 = 1;
  cVar1 = FUN_4080a71f(this,&param_2);
  pcVar2 = "\'%s\';";
  if (cVar1 == '\0') {
    pcVar2 = "%s;";
  }
  FUN_40803c8a(local_14,pcVar2);
  FUN_40803143((int *)&param_2);
  param_2 = (LPCWSTR)PTR_DAT_40862014;
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_408051a5(&param_2,local_14[0]);
  FUN_4080a836(param_1,(undefined1 (*) [16])0x4084b9a4,param_2);
  FUN_40803143((int *)&param_2);
  FUN_40803143((int *)local_14);
  return param_1;
}


