// Source: CLCiffConversion_Layout.dll @ 4541669c; FUN_4541669c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4541669c(void *this,BSTR param_1)

{
  int *piVar1;
  BSTR this_00;
  int *piVar2;
  undefined4 *puVar3;
  int *local_18;
  undefined4 local_14;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x454166a8;
  local_14 = 0;
  local_18 = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
  this_00 = param_1;
  local_8 = 0;
  FUN_45404ce5((void *)((int)this + 0x60),(int *)(param_1 + 2));
  puVar3 = FUN_4541cbbe(this_00,&param_1);
  local_8._0_1_ = 1;
  FUN_45407800((void *)((int)this + 100),(wchar_t *)*puVar3);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(param_1);
  FUN_4541c9f1((int *)this_00,&local_18);
  piVar2 = local_18;
  for (piVar1 = (int *)*local_18; piVar1 != piVar2; piVar1 = (int *)*piVar1) {
    (**(code **)(*(int *)this + 0xc))(piVar1[2]);
  }
  FUN_454120f3((int *)&local_18);
  piVar1 = *(int **)((int)this + 0x60);
  if ((piVar1 != (int *)0x0) && (*(int *)((int)this + 0x60) = 0, piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45402cd0((void *)((int)this + 100),"");
  FUN_454224ff((int *)&local_18);
  FID_conflict__free(local_18);
  return 0;
}


