// Source: CLCiffConversion_Data.dll @ 4500d930; FUN_4500d930

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_4500d930(int param_1)

{
  HRESULT HVar1;
  int iVar2;
  int *piVar3;
  int local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x4500d93c;
  iVar2 = 0;
  VariantClear((VARIANTARG *)(param_1 + 0x468));
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_1c[0] = FUN_4500790c();
  local_8 = 0;
  piVar3 = (int *)**(int **)(param_1 + 0x4e8);
  if (piVar3 != *(int **)(param_1 + 0x4e8)) {
    do {
      if (iVar2 < 0) break;
      if ((int *)piVar3[2] != (int *)0x0) {
        iVar2 = (**(code **)(*(int *)piVar3[2] + 8))();
      }
      if (*(int *)(piVar3[2] + 0xd8) != 0) {
        FUN_4500ffc5((void *)piVar3[2],local_1c);
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*(int *)(param_1 + 0x4e8));
  }
  local_1c[2] = 0;
  HVar1 = FUN_4500fff6(local_1c + 2,local_1c);
  if (-1 < HVar1) {
    *(undefined2 *)(param_1 + 0x468) = 0x2008;
    *(int *)(param_1 + 0x470) = local_1c[2];
  }
  FUN_450056b7(local_1c);
  return iVar2;
}


