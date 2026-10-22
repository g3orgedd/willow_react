// Source: CLARiSOFT.exe @ 00e6600f; FUN_00e6600f

void __thiscall FUN_00e6600f(void *this,int *param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00f385b8 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_00e68567((int)this);
  FUN_00e68547(this,&local_1c);
  uVar3 = 0;
  puVar4 = local_1c;
  if (uVar2 != 0) {
    do {
      local_1c = (undefined4 *)puVar4[2];
      bVar1 = FUN_00eb59a2((int)local_1c);
      if (bVar1) {
        FUN_00e61d8e(local_1c,&local_18);
        if (param_1[3] < local_c) {
          param_1[3] = local_c;
        }
        if (param_1[2] < local_10) {
          param_1[2] = local_10;
        }
        if (uVar3 == 0) {
          *param_1 = local_18;
        }
        else {
          if (local_18 < *param_1) {
            *param_1 = local_18;
          }
          if (param_1[1] <= local_14) goto LAB_00e66098;
        }
        param_1[1] = local_14;
      }
LAB_00e66098:
      uVar3 = uVar3 + 1;
      puVar4 = (undefined4 *)*puVar4;
    } while (uVar3 < uVar2);
  }
  FUN_00ec9db6(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


