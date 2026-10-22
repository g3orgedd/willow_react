// Source: CLCiffConversion_Layout.dll @ 45407316; FUN_45407316

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Variable defined which should be unmapped: param_2 */

undefined4 * __thiscall
FUN_45407316(int *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,int *param_5)

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
        bVar3 = FUN_454078ec((undefined4 *)(piVar1[2] + 0x10),param_4);
        if (!bVar3) goto LAB_45407450;
        param_3 = *(int **)(*param_1 + 8);
        cVar5 = '\0';
        goto LAB_4540733a;
      }
      bVar3 = FUN_454078ec(param_4,param_3 + 4);
      if (bVar3) {
        local_18[0] = param_3;
        FUN_454078a8((int *)local_18);
        piVar1 = local_18[0];
        bVar3 = FUN_454078ec(local_18[0] + 4,param_4);
        if (!bVar3) goto LAB_454073e5;
        cVar5 = *(char *)(piVar1[2] + 0xd);
      }
      else {
LAB_454073e5:
        bVar3 = FUN_454078ec(param_3 + 4,param_4);
        if (!bVar3) {
LAB_45407450:
          local_8 = 0xffffffff;
          puVar4 = (undefined4 *)FUN_45407474(param_1,&local_1c,(undefined4 *)0x0,param_4,param_5);
          *param_2 = *puVar4;
          return param_2;
        }
        local_18[0] = param_3;
        FUN_45409a25((int *)local_18);
        piVar2 = local_18[0];
        if ((local_18[0] != (int *)*param_1) &&
           (bVar3 = FUN_454078ec(param_4,local_18[0] + 4), !bVar3)) goto LAB_45407450;
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
      goto LAB_4540733a;
    }
    bVar3 = FUN_454078ec(param_4,param_3 + 4);
    if (!bVar3) goto LAB_45407450;
  }
  cVar5 = '\x01';
LAB_4540733a:
  FUN_454071e6(param_1,param_2,cVar5,param_3,param_4,param_5);
  return param_2;
}


