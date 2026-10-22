// Source: CLARiSOFT.exe @ 00eb1a01; FUN_00eb1a01

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00eb1a01(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int *param_4,
                 undefined4 *param_5,byte *param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  byte bVar3;
  byte *pbVar4;
  int *piVar5;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c [2];
  BSTR local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  pbVar4 = param_6;
  puVar1 = param_3;
  uStack_4 = 0x4c;
  local_34 = (BSTR)0x0;
  *param_6 = 1;
  local_8 = 0;
  (**(code **)(*(int *)*param_3 + 0x1c))((int *)*param_3,&local_34);
  local_30 = 1;
  (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,&local_30);
  if (local_30 != 0) {
    local_20 = 0;
    local_2c = 0;
    FUN_00eae6d1(local_3c);
    local_8 = CONCAT31(local_8._1_3_,1);
    (**(code **)(*(int *)*param_2 + 0x5c))((int *)*param_2,local_14);
    (**(code **)(*(int *)*param_2 + 100))((int *)*param_2,&local_1c);
    piVar2 = param_4;
    piVar5 = (int *)*param_4;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    local_14[0] = FUN_00eaeae0(local_14[0],1.4013e-45,piVar5);
    piVar5 = (int *)*piVar2;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    local_1c = FUN_00eaeae0(local_1c,0.0,piVar5);
    puVar1 = param_3;
    (**(code **)(*(int *)*param_3 + 0x3c))((int *)*param_3,&local_2c);
    (**(code **)(*(int *)*puVar1 + 0x2c))((int *)*puVar1,&local_18);
    (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1,&local_24);
    (**(code **)(*(int *)*puVar1 + 0x78))((int *)*puVar1,&local_28);
    (**(code **)(*(int *)*puVar1 + 0x80))((int *)*puVar1,&local_20);
    piVar5 = (int *)*piVar2;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    local_18 = FUN_00eaeae0(local_18,1.4013e-45,piVar5);
    piVar5 = (int *)*piVar2;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    local_24 = FUN_00eaeae0(local_24,0.0,piVar5);
    piVar5 = (int *)*piVar2;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    local_28 = FUN_00eaeae0(local_28,1.4013e-45,piVar5);
    piVar5 = (int *)*piVar2;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    local_20 = FUN_00eaeae0(local_20,0.0,piVar5);
    local_4c = local_18;
    local_40 = local_24 + local_20;
    local_48 = local_24;
    if ((local_2c == 0x5a) || (local_44 = local_28 + local_18, local_2c == 0x10e)) {
      local_44 = (local_40 - local_24) + local_18;
      local_40 = ((local_28 + local_18) - local_18) + local_24;
      pbVar4 = param_6;
    }
    if ((char)param_5 == '\0') {
      if ((((local_18 < 0) || (local_24 < 0)) || (local_14[0] < local_44)) || (local_1c < local_40))
      {
        *pbVar4 = 0;
      }
      else {
        piVar5 = (int *)*piVar2;
        if (piVar5 != (int *)0x0) {
          param_6 = (byte *)0x0;
          (**(code **)(*piVar5 + 0x3ec))(piVar5,&param_6);
          if (0 < (int)param_6) {
            param_5 = (undefined4 *)0x0;
            param_3 = (undefined4 *)0x0;
            (**(code **)(*(int *)*piVar2 + 0x4c4))((int *)*piVar2,&param_5);
            (**(code **)(*(int *)*piVar2 + 0x4cc))((int *)*piVar2,&param_3);
            puVar1 = param_5;
            if (local_1c < local_14[0]) {
              param_5 = param_3;
              param_3 = puVar1;
            }
            bVar3 = FUN_00eb16ee((int)param_5,(int)param_3,local_14[0],local_1c,&local_4c);
            *pbVar4 = bVar3;
          }
        }
      }
    }
    local_8 = local_8 & 0xffffff00;
    FUN_00eae7b2(local_3c);
  }
  SysFreeString(local_34);
  return;
}


