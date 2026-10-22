// Source: CLCiffConversion_Data.dll @ 45006ca4; FUN_45006ca4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_45006ca4(undefined4 *param_1,int param_2)

{
  int iVar1;
  UINT UVar2;
  undefined8 *puVar3;
  OLECHAR ****ppppOVar4;
  int local_4c;
  BSTR local_48;
  undefined2 local_44 [12];
  OLECHAR ***local_2c [5];
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x45006cb0;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    local_48 = (BSTR)0x0;
    local_8 = 0;
    iVar1 = (**(code **)(*(int *)*param_1 + 0x28))((int *)*param_1,&local_4c);
    if (-1 < iVar1) {
      if (local_4c == 0) {
        iVar1 = (**(code **)(*(int *)*param_1 + 0x58))((int *)*param_1,&local_48);
      }
      else if (0 < local_4c) {
        if (local_4c < 3) {
          iVar1 = (**(code **)(*(int *)*param_1 + 0x60))((int *)*param_1,&local_48);
        }
        else if (local_4c == 3) {
          (**(code **)(*(int *)*param_1 + 0xcc))((int *)*param_1,&local_48);
        }
      }
      if ((-1 < iVar1) && (UVar2 = SysStringLen(local_48), UVar2 != 0)) {
        basic_string<>(local_2c,local_48);
        local_8 = CONCAT31(local_8._1_3_,1);
        puVar3 = (undefined8 *)FUN_4500782c(local_44,local_2c);
        FUN_4500589e(local_2c,puVar3);
        FUN_450046d9(local_44,'\x01',0);
        puVar3 = (undefined8 *)FUN_450077a4(local_44,local_2c);
        FUN_4500589e(local_2c,puVar3);
        FUN_450046d9(local_44,'\x01',0);
        ppppOVar4 = local_2c;
        if (7 < local_18) {
          ppppOVar4 = (OLECHAR ****)local_2c[0];
        }
        FUN_45002326(&local_48,(OLECHAR *)ppppOVar4);
        if (local_4c == 0) {
          (**(code **)(*(int *)*param_1 + 0x5c))((int *)*param_1,local_48);
        }
        (**(code **)(**(int **)(param_2 + 4) + 0x9c))(*(int **)(param_2 + 4),local_48);
        FUN_450046d9(local_2c,'\x01',0);
      }
    }
    SysFreeString(local_48);
  }
  FUN_45022eb8();
  return;
}


