// Source: CLCSSmallBarcode.dll @ 4202a8f1; FUN_4202a8f1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_4202a8f1(void *this,int param_1,int param_2,int param_3,BSTR param_4,char param_5)

{
  uint uVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  int local_1c [5];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  uVar5 = 0xffffffff;
  local_8 = 0;
  if (param_1 == 10) {
    pvVar2 = (void *)FUN_42067914(0x848);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (pvVar2 == (void *)0x0) goto LAB_4202aa1c;
    cVar6 = '\0';
LAB_4202aa0d:
    piVar3 = FUN_42028cfb(pvVar2,param_2,param_3,cVar6,(uint)(param_5 != '\0'));
  }
  else if (param_1 == 0xb) {
    pvVar2 = (void *)FUN_42067914(0x848);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (pvVar2 != (void *)0x0) {
      cVar6 = '\x01';
      goto LAB_4202aa0d;
    }
LAB_4202aa1c:
    piVar3 = (int *)0x0;
  }
  else if (param_1 == 0xc) {
    pvVar2 = (void *)FUN_42067914(0x84c);
    local_8 = CONCAT31(local_8._1_3_,3);
    if (pvVar2 == (void *)0x0) goto LAB_4202aa1c;
    piVar3 = FUN_42027c0a(pvVar2,param_2,(uint)(param_5 != '\0'));
  }
  else if (param_1 == 0xd) {
    pvVar2 = (void *)FUN_42067914(0x848);
    local_8 = CONCAT31(local_8._1_3_,4);
    if (pvVar2 == (void *)0x0) goto LAB_4202aa1c;
    piVar3 = FUN_420285a6(pvVar2,param_2,param_3,(uint)(param_5 != '\0'));
  }
  else {
    if (param_1 != 0xe) goto LAB_4202aa66;
    pvVar2 = (void *)FUN_42067914(0x848);
    local_8 = CONCAT31(local_8._1_3_,5);
    if (pvVar2 == (void *)0x0) goto LAB_4202aa1c;
    piVar3 = FUN_4202914d(pvVar2,param_2,param_3,(uint)(param_5 != '\0'));
  }
  uVar1 = local_8 >> 8;
  local_8 = local_8 & 0xffffff00;
  if (piVar3 != (int *)0x0) {
    local_1c[0] = 0;
    local_1c[1] = 0;
    local_1c[2] = 0;
    local_8 = CONCAT31((int3)uVar1,6);
    iVar4 = (**(code **)(*piVar3 + 4))(&param_4,local_1c,(int)this + 0x74);
    if (-1 < iVar4) {
      uVar5 = (**(code **)(*piVar3 + 0xc))();
    }
    (**(code **)*piVar3)(1);
    FUN_420284e3(local_1c);
  }
LAB_4202aa66:
  SysFreeString(param_4);
  return uVar5;
}


