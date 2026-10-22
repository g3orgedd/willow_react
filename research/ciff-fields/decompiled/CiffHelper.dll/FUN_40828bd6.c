// Source: CiffHelper.dll @ 40828bd6; FUN_40828bd6

void __cdecl FUN_40828bd6(int *param_1,double *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  double *pdVar4;
  undefined4 *puVar5;
  int local_20 [2];
  double local_18;
  double local_10;
  int local_8;
  
  piVar1 = param_1;
  if ((param_1[1] - *param_1) / 0xc != 0) {
    piVar2 = (int *)FUN_40829763(param_2);
    local_8 = FUN_40829cd3(param_2);
    puVar5 = (undefined4 *)*param_1;
    param_1 = piVar2;
    for (; puVar5 != (undefined4 *)piVar1[1]; puVar5 = puVar5 + 3) {
      piVar2 = (int *)FUN_408286c9(puVar5);
      if ((piVar2 == param_1) && (iVar3 = FUN_408286cc((int)puVar5), iVar3 == local_8)) {
        iVar3 = FUN_4081f2bf((int)puVar5);
        local_20[0] = 0;
        local_20[1] = 0;
        local_18 = (double)iVar3;
        pdVar4 = FUN_408294b5(&local_10,param_2,local_20);
        *param_2 = *pdVar4;
        param_1 = (int *)FUN_40829763(param_2);
        local_8 = FUN_40829cd3(param_2);
      }
    }
  }
  return;
}


