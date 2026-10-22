// Source: CLCSTextBasedField.dll @ 42460c41; FUN_42460c41

void __cdecl
FUN_42460c41(LCID param_1,char param_2,undefined1 *param_3,char *param_4,uint *param_5,uint *param_6
            )

{
  int iVar1;
  char cVar2;
  undefined1 *local_18;
  undefined1 local_14 [12];
  uint local_8;
  
  local_8 = DAT_424ba210 ^ (uint)&stack0xfffffffc;
  local_18 = param_3;
  FUN_4246d990(param_5,0,4);
  FUN_4246d990(param_6,0,2);
  if ((param_3 == (undefined1 *)0x0) && (param_2 != '\0')) {
    iVar1 = ScriptRecordDigitSubstitution(param_1,local_14);
    if (iVar1 < 0) {
      param_2 = '\0';
    }
    else {
      local_18 = local_14;
    }
  }
  if (param_4 == (char *)0x0) {
    iVar1 = FUN_42460d78(param_1);
    if (iVar1 < 0) goto LAB_42460ce9;
    cVar2 = iVar1 == 1;
  }
  else {
    cVar2 = *param_4;
  }
  if (param_2 == '\0') {
    *(short *)param_5 = (short)param_1;
  }
  else {
    ScriptApplyDigitSubstitution(local_18,param_5,param_6);
  }
  *(ushort *)param_6 = (ushort)*param_6 ^ ((ushort)(cVar2 != '\0') ^ (ushort)*param_6) & 0x1f;
LAB_42460ce9:
  FUN_4246ec70(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


