// Source: CLCiffConversion_Data.dll @ 4501cc3f; FUN_4501cc3f

void __cdecl FUN_4501cc3f(int *param_1,double *param_2)

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
    piVar2 = (int *)FUN_4501d4ad(param_2);
    local_8 = FUN_4501de65(param_2);
    puVar5 = (undefined4 *)*param_1;
    param_1 = piVar2;
    for (; puVar5 != (undefined4 *)piVar1[1]; puVar5 = puVar5 + 3) {
      piVar2 = (int *)FUN_450199c2(puVar5);
      if ((piVar2 == param_1) && (iVar3 = FUN_450199c9((int)puVar5), iVar3 == local_8)) {
        iVar3 = FUN_450199c5((int)puVar5);
        local_20[0] = 0;
        local_20[1] = 0;
        local_18 = (double)iVar3;
        pdVar4 = FUN_4501d1ec(&local_10,param_2,local_20);
        *param_2 = *pdVar4;
        param_1 = (int *)FUN_4501d4ad(param_2);
        local_8 = FUN_4501de65(param_2);
      }
    }
  }
  return;
}


