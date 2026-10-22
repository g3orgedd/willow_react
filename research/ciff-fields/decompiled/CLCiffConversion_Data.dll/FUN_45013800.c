// Source: CLCiffConversion_Data.dll @ 45013800; FUN_45013800

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_45013800(undefined4 *param_1)

{
  bool bVar1;
  UINT UVar2;
  short *psVar3;
  OLECHAR *pOVar4;
  int iVar5;
  int local_48;
  undefined1 local_44 [24];
  undefined1 local_2c [16];
  int local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x4501380c;
  UVar2 = SysStringLen((BSTR)*param_1);
  if (UVar2 != 0) {
    local_48 = 0;
    bVar1 = false;
    basic_string<>(local_2c,(wchar_t *)*param_1);
    local_8 = 0;
    iVar5 = local_1c;
    while ((0 < iVar5 && (psVar3 = (short *)FUN_45014218(local_2c,iVar5 - 1), *psVar3 == 0x20))) {
      if (iVar5 == local_1c) {
        bVar1 = true;
      }
      if (bVar1) {
        local_48 = local_48 + 1;
      }
      iVar5 = iVar5 + -1;
    }
    pOVar4 = FUN_45014419(local_2c,local_44,0,local_1c - local_48);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (7 < *(uint *)(pOVar4 + 10)) {
      pOVar4 = *(OLECHAR **)pOVar4;
    }
    FUN_45002326(param_1,pOVar4);
    FUN_450046d9(local_44,'\x01',0);
    FUN_450046d9(local_2c,'\x01',0);
  }
  FUN_45022eb8();
  return;
}


