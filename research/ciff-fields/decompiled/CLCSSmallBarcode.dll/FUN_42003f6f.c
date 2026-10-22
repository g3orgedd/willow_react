// Source: CLCSSmallBarcode.dll @ 42003f6f; FUN_42003f6f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_42003f6f(int *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  HDC hDC;
  HFONT h;
  HGDIOBJ h_00;
  UINT c;
  int iVar2;
  float fVar3;
  undefined4 *local_94;
  tagSIZE local_90;
  undefined4 *local_88;
  float local_84;
  BSTR local_80;
  HDC local_7c;
  int local_78;
  BSTR local_74;
  LOGFONTW local_70;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x88;
  local_8 = 0;
  if ((param_1 != (int *)0x0) && (*param_2 != 0)) {
    local_7c = GetDC((HWND)0x0);
    local_80 = (BSTR)0x0;
    local_8._0_1_ = 1;
    (**(code **)(*param_1 + 0xd0))(param_1);
    local_78 = 0;
    (**(code **)(*param_1 + 0xe0))(param_1,&local_78);
    if (param_3 < 0x3e9) {
      local_78 = (local_78 * param_3) / 1000;
    }
    FUN_420698e0((uint *)&local_70,0,0x5c);
    FUN_4206a09b(local_70.lfFaceName,0x20,local_80,0x1f);
    iVar2 = local_78;
    local_84 = 0.0;
    local_70.lfCharSet = '\x01';
    (**(code **)(*(int *)*param_2 + 0x34))((int *)*param_2,&local_84);
    fVar3 = local_84 * _DAT_4208982c + DAT_420897f4;
    local_70.lfHeight =
         MulDiv(iVar2,(int)(local_84 * _DAT_4208982c * _DAT_42089828 + DAT_420897f4),0x48);
    local_70.lfHeight = -local_70.lfHeight;
    local_88 = (undefined4 *)FUN_42067914(4);
    if (local_88 == (undefined4 *)0x0) {
      local_88 = (undefined4 *)0x0;
    }
    else {
      *local_88 = 0;
    }
    puVar1 = local_88;
    local_94 = local_88;
    h = CreateFontIndirectW(&local_70);
    *puVar1 = h;
    h_00 = SelectObject(local_7c,h);
    local_74 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    (**(code **)(*param_1 + 0x98))(param_1,&local_74);
    local_90.cx = 0;
    local_90.cy = 0;
    c = SysStringLen(local_74);
    GetTextExtentPoint32W(local_7c,local_74,c,&local_90);
    hDC = local_7c;
    SelectObject(local_7c,h_00);
    DeleteObject((HGDIOBJ)*local_88);
    ReleaseDC((HWND)0x0,hDC);
    iVar2 = FUN_42004376(((double)(int)fVar3 * (double)param_3 * _DAT_42089800) / DAT_42089818);
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    local_90.cy = local_90.cy + iVar2;
    SysFreeString(local_74);
    FUN_42003eea(&local_94);
    SysFreeString(local_80);
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  FUN_4206a64e();
  return;
}


