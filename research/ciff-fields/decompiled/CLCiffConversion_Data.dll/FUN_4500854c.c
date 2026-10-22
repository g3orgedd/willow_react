// Source: CLCiffConversion_Data.dll @ 4500854c; FUN_4500854c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall
FUN_4500854c(int *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  undefined4 *puVar4;
  char cVar5;
  undefined4 local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0;
  if (param_1[1] == 0) {
    param_3 = (int *)*param_1;
  }
  else {
    piVar1 = (int *)*param_1;
    if (param_3 != (int *)*piVar1) {
      if (param_3 == piVar1) {
        bVar3 = FUN_45008b14((undefined4 *)(piVar1[2] + 0x10),param_4);
        if (!bVar3) goto LAB_45008686;
        param_3 = *(int **)(*param_1 + 8);
        cVar5 = '\0';
        goto LAB_45008570;
      }
      bVar3 = FUN_45008b14(param_4,param_3 + 4);
      if (bVar3) {
        local_18[0] = param_3;
        FUN_45005981((int *)local_18);
        piVar1 = local_18[0];
        bVar3 = FUN_45008b14(local_18[0] + 4,param_4);
        if (!bVar3) goto LAB_4500861b;
        cVar5 = *(char *)(piVar1[2] + 0xd);
      }
      else {
LAB_4500861b:
        bVar3 = FUN_45008b14(param_3 + 4,param_4);
        if (!bVar3) {
LAB_45008686:
          local_8 = 0xffffffff;
          puVar4 = (undefined4 *)FUN_450086aa(param_1,&local_1c,(undefined4 *)0x0,param_4,param_5);
          *param_2 = *puVar4;
          return param_2;
        }
        local_18[0] = param_3;
        FUN_45005947((int *)local_18);
        piVar2 = local_18[0];
        if ((local_18[0] != (int *)*param_1) &&
           (bVar3 = FUN_45008b14(param_4,local_18[0] + 4), !bVar3)) goto LAB_45008686;
        cVar5 = *(char *)(param_3[2] + 0xd);
        piVar1 = param_3;
        param_3 = piVar2;
      }
      if (cVar5 == '\0') {
        cVar5 = '\x01';
      }
      else {
        cVar5 = '\0';
        param_3 = piVar1;
      }
      goto LAB_45008570;
    }
    bVar3 = FUN_45008b14(param_4,param_3 + 4);
    if (!bVar3) goto LAB_45008686;
  }
  cVar5 = '\x01';
LAB_45008570:
  FUN_4500841c(param_1,param_2,cVar5,param_3,param_4,param_5);
  return param_2;
}


