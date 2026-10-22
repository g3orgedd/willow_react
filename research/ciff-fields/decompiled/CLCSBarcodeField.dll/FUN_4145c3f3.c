// Source: CLCSBarcodeField.dll @ 4145c3f3; FUN_4145c3f3

undefined8 __thiscall FUN_4145c3f3(void *this,char *param_1,uint *param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int local_18;
  uint *local_10;
  int local_8;
  
  puVar1 = param_2;
  uVar3 = 0;
  local_18 = 0;
  iVar4 = 0;
  local_8 = 0;
  if (*param_1 == -0x6f) {
    FUN_41460d10((undefined8 *)param_1,(undefined8 *)(param_1 + 1),*param_2 - 1);
    *puVar1 = *puVar1 - 1;
  }
  if (*puVar1 != 0) {
    do {
      if (iVar4 != 0) break;
      piVar2 = FUN_4145c305((byte *)(param_1 + uVar3),*puVar1 - uVar3,&local_8);
      iVar4 = local_8;
      if ((local_8 == 0) && (piVar2 != (int *)0x0)) {
        param_2 = (uint *)0x0;
        if (*piVar2 == 0x17) {
          local_8 = FUN_4145c2b4((int)(param_1 + uVar3),*puVar1 - uVar3,piVar2,(uint *)&param_2);
LAB_4145c4a0:
          local_10 = param_2;
        }
        else {
          if (0 < piVar2[6]) {
            local_8 = FUN_4145c56f(param_1 + uVar3,*puVar1 - uVar3,(int)piVar2,(uint *)&param_2);
            goto LAB_4145c4a0;
          }
          local_8 = FUN_4145c591((int)(param_1 + uVar3),*puVar1 - uVar3,piVar2,(uint *)&param_2);
          if (param_1[(int)param_2 + (uVar3 - 1)] == -0x6f) {
            local_10 = (uint *)((int)param_2 + -1);
          }
        }
        iVar4 = local_8;
        if (((local_8 == 0) &&
            (iVar4 = (*(code *)piVar2[2])(param_1 + uVar3,local_10,piVar2), local_8 = iVar4,
            iVar4 == 0)) &&
           (iVar4 = (*(code *)piVar2[8])(param_1 + uVar3,local_10,piVar2), local_8 = iVar4,
           iVar4 == 0)) {
          if (0x30 < (uint)((int)param_2 + local_18)) {
            FUN_41460d10((undefined8 *)(param_1 + uVar3 + 1),(undefined8 *)(param_1 + uVar3),
                         *puVar1 - uVar3);
            param_1[uVar3] = -0x6e;
            *puVar1 = *puVar1 + 1;
            uVar3 = uVar3 + 1;
            local_18 = 0;
          }
          uVar3 = uVar3 + (int)param_2;
          local_18 = local_18 + (int)param_2;
        }
      }
    } while (uVar3 < *puVar1);
  }
  return CONCAT44(this,iVar4);
}


