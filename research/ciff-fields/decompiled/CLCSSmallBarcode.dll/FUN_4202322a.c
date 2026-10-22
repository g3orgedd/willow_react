// Source: CLCSSmallBarcode.dll @ 4202322a; FUN_4202322a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_4202322a(void *this,BSTR param_1,int param_2)

{
  int iVar1;
  UINT UVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  UINT UVar6;
  wchar_t local_14 [6];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  FUN_4200572b((void *)((int)this + 8),(int *)&param_1);
  iVar1 = param_2;
  iVar4 = 0;
  for (iVar3 = param_2; -1 < iVar3; iVar3 = iVar3 + -2) {
    iVar4 = iVar4 + -0x30 + (uint)(ushort)param_1[iVar3];
  }
  iVar5 = 0;
  for (iVar3 = param_2 + -1; -1 < iVar3; iVar3 = iVar3 + -2) {
    iVar5 = iVar5 + -0x30 + (uint)(ushort)param_1[iVar3];
  }
  iVar4 = (10 - (iVar5 + iVar4 * 3) % 10) % 10;
  SysFreeString(*(BSTR *)((int)this + 0xc));
  *(undefined4 *)((int)this + 0xc) = 0;
  UVar6 = iVar1 + 1;
  UVar2 = SysStringLen(param_1);
  if ((int)UVar2 < (int)UVar6) {
    UVar6 = SysStringLen(param_1);
  }
  FUN_420059e8((void *)((int)this + 0xc),param_1,UVar6);
  local_14[0] = (short)iVar4 + L'0';
  local_14[1] = 0;
  FUN_420059bf((void *)((int)this + 0xc),local_14);
  SysFreeString(param_1);
  return iVar4;
}


