// Source: CiffMgr.dll @ 68118c55; FUN_68118c55

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_68118c55(BSTR param_1,BSTR param_2,undefined4 *param_3)

{
  uint uVar1;
  UINT UVar2;
  int iVar3;
  uint local_824;
  int local_820;
  BSTR local_81c;
  BSTR local_818;
  ushort local_814;
  uint local_812 [127];
  ushort local_614;
  uint local_612 [127];
  ushort local_414;
  uint local_412 [127];
  ushort local_214;
  uint local_212 [130];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x818;
  local_8 = 0x68118c64;
  local_818 = param_2;
  local_81c = param_1;
  UVar2 = SysStringLen((BSTR)*param_3);
  if (((UVar2 != 0) && (UVar2 = SysStringLen(*(BSTR *)local_818), UVar2 == 8)) &&
     (UVar2 = SysStringLen(*(BSTR *)param_1), UVar2 != 0)) {
    local_824 = 0;
    iVar3 = FUN_68118280((int *)local_818,(int *)&local_824);
    uVar1 = local_824;
    if (((-1 < iVar3) && (5 < local_824)) &&
       (UVar2 = SysStringLen(*(BSTR *)local_81c), uVar1 + 0x18 < UVar2)) {
      FUN_68118181(&local_81c,uVar1,(OLECHAR *)(*(int *)local_81c + 0x30));
      local_818 = (BSTR)0x0;
      local_8 = 1;
      iVar3 = (**(code **)(*(int *)(local_820 + 0x10) + 4))
                        ((int *)(local_820 + 0x10),local_81c,*(undefined4 *)(local_820 + 0xaf4),
                         *(undefined4 *)(local_820 + 0xafc),0,&local_818);
      if (-1 < iVar3) {
        local_814 = 0;
        FUN_68132710(local_812,0,0x1fe);
        local_214 = 0;
        FUN_68132710(local_212,0,0x1fe);
        local_614 = 0;
        FUN_68132710(local_612,0,0x1fe);
        local_414 = 0;
        FUN_68132710(local_412,0,0x1fe);
        FUN_68134dca((short *)*param_3,(short *)0x0,0,(short *)0x0,0,(short *)&local_814,0x100,
                     (short *)&local_214,0x100);
        FUN_68134dca(local_818,(short *)0x0,0,(short *)0x0,0,(short *)&local_614,0x100,
                     (short *)&local_414,0x100);
        iVar3 = FUN_68134fc4(&local_814,&local_614,DAT_6814be48);
        if ((iVar3 == 0) && (iVar3 = FUN_68134501(&local_214,&local_414), iVar3 == 0)) {
          FUN_68134501(&local_214,(ushort *)L".ciff");
        }
      }
      SysFreeString(local_818);
      SysFreeString(local_81c);
    }
  }
  FUN_681320d7();
  return;
}


