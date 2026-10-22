// Source: CLCiffConversion_Layout.dll @ 45403ab4; FUN_45403ab4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_45403ab4(int *param_1,BSTR param_2)

{
  ushort uVar1;
  UINT UVar2;
  undefined4 ***pppuVar3;
  int iVar4;
  int local_30;
  undefined4 **local_2c [5];
  uint local_18;
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 1;
  uStack_7 = 0;
  FUN_45402a11(param_1);
  UVar2 = SysStringLen(param_2);
  if (0 < (int)UVar2) {
    basic_string<>(local_2c,param_2);
    iVar4 = 0;
    local_8 = 2;
    if (0 < (int)UVar2) {
      do {
        pppuVar3 = local_2c;
        if (7 < local_18) {
          pppuVar3 = (undefined4 ***)local_2c[0];
        }
        uVar1 = *(ushort *)((int)pppuVar3 + iVar4 * 2);
        if ((0x36f < uVar1) && (uVar1 < 0x400)) {
          FUN_45402a65(&local_30,"EL");
          local_8 = 3;
LAB_45403bdb:
          FUN_454025d8(param_1,(int *)*param_1,&local_30);
          FUN_45402c5d(&local_30);
          break;
        }
        if ((0x3ff < uVar1) && (uVar1 < 0x530)) {
          FUN_45402a65(&local_30,"RU");
          local_8 = 4;
          goto LAB_45403bdb;
        }
        if ((0x58f < uVar1) && (uVar1 < 0x600)) {
          FUN_45402a65(&local_30,"HE");
          local_8 = 5;
          goto LAB_45403bdb;
        }
        if ((0x5ff < uVar1) && (uVar1 < 0x700)) {
          FUN_45402a65(&local_30,"AR");
          local_8 = 6;
          goto LAB_45403bdb;
        }
        if ((0x4dff < uVar1) && (uVar1 < 0x9fa6)) {
          FUN_45402a65(&local_30,"ZH");
          local_8 = 7;
          goto LAB_45403bdb;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)UVar2);
    }
    FUN_4540460c(local_2c,'\x01',0);
  }
  SysFreeString(param_2);
  FUN_4542a957();
  return;
}


