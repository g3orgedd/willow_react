// Source: CLCSSmallBarcode.dll @ 4200bdaa; FUN_4200bdaa

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_4200bdaa(BSTR param_1,void *param_2)

{
  BSTR pOVar1;
  HRESULT HVar2;
  int iVar3;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  HVar2 = CoCreateInstance((IID *)&DAT_4208a628,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4208a7cc,local_14);
  pOVar1 = param_1;
  if (-1 < HVar2) {
    param_1 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar3 = (**(code **)(*local_14[0] + 0xc))(local_14[0],*(undefined4 *)pOVar1,&param_1);
    if (-1 < iVar3) {
      FUN_4200572b(param_2,(int *)&param_1);
    }
    local_8 = local_8 & 0xffffff00;
    SysFreeString(param_1);
    if (-1 < iVar3) goto LAB_4200be1d;
  }
  FUN_4200572b(param_2,(int *)pOVar1);
LAB_4200be1d:
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return;
}


