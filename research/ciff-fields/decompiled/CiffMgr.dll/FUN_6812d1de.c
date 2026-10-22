// Source: CiffMgr.dll @ 6812d1de; FUN_6812d1de

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6812d1de(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  wchar_t *pwVar5;
  short *psVar6;
  undefined *puVar7;
  BSTR local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 8;
  local_18 = (BSTR)0x0;
  local_8 = 0;
  iVar4 = (**(code **)(*(int *)*param_2 + 0xa8))((int *)*param_2,&local_18);
  piVar2 = param_3;
  if ((-1 < iVar4) && (bVar3 = FUN_68119d18(&local_18,L"Arial"), !bVar3)) {
    iVar4 = FUN_6810226e(param_1,piVar2,PTR_u_Face_6815fdd0,local_18);
  }
  local_8 = 0xffffffff;
  SysFreeString(local_18);
  if ((-1 < iVar4) &&
     (iVar4 = (**(code **)(*(int *)*piVar1 + 0xfc))((int *)*piVar1,&param_2), -1 < iVar4)) {
    if (param_2 != (int *)0x20) {
      pwVar5 = FUN_6812ef79((int)param_2);
      iVar4 = FUN_6810248f(param_1,piVar2,PTR_u_Family_6815fdd4,pwVar5);
    }
    if ((-1 < iVar4) &&
       (iVar4 = (**(code **)(*(int *)*piVar1 + 0xb0))((int *)*piVar1,&param_2), -1 < iVar4)) {
      if (param_2 != (int *)0xd) {
        psVar6 = FUN_6812f174(local_14,(int)param_2);
        iVar4 = FUN_6810248f(param_1,piVar2,PTR_u_Pitch_6815fdd8,psVar6);
      }
      if (-1 < iVar4) {
        CComQIPtr<>(&param_2,(undefined4 *)*piVar1);
        local_8 = 1;
        if (((param_2 != (int *)0x0) &&
            (iVar4 = (**(code **)(*param_2 + 0x168))(param_2,&param_3), -1 < iVar4)) &&
           (param_3 != (int *)0x1)) {
          psVar6 = FUN_6812f174(local_14,(int)param_3);
          iVar4 = FUN_6810248f(param_1,piVar2,PTR_u_PitchResolution_6815ffa0,psVar6);
        }
        local_8 = 0xffffffff;
        if (param_2 != (int *)0x0) {
          (**(code **)(*param_2 + 8))(param_2);
        }
        if ((-1 < iVar4) &&
           (iVar4 = (**(code **)(*(int *)*piVar1 + 0xb8))((int *)*piVar1,&param_2), -1 < iVar4)) {
          if (param_2 != (int *)0x64) {
            psVar6 = FUN_6812f174(local_14,(int)param_2);
            iVar4 = FUN_6810248f(param_1,piVar2,PTR_u_XMag_6815fddc,psVar6);
          }
          if ((-1 < iVar4) &&
             (iVar4 = (**(code **)(*(int *)*piVar1 + 0x11c))((int *)*piVar1,&param_2), -1 < iVar4))
          {
            if (param_2 != (int *)0x64) {
              psVar6 = FUN_6812f174(local_14,(int)param_2);
              iVar4 = FUN_6810248f(param_1,piVar2,PTR_u_YMag_6815fde0,psVar6);
            }
            if ((-1 < iVar4) &&
               (iVar4 = (**(code **)(*(int *)*piVar1 + 0x124))((int *)*piVar1,&param_2), -1 < iVar4)
               ) {
              if (param_2 != (int *)0x1) {
                psVar6 = FUN_6812f174(local_14,(int)param_2);
                iVar4 = FUN_6810248f(param_1,piVar2,PTR_u_TTSize_6815fde4,psVar6);
              }
              if (-1 < iVar4) {
                CComQIPtr<>(&param_2,(undefined4 *)*piVar1);
                local_8 = 2;
                if (((param_2 != (int *)0x0) &&
                    (iVar4 = (**(code **)(*param_2 + 0x134))(param_2,&param_3), -1 < iVar4)) &&
                   (param_3 != (int *)0x0)) {
                  puVar7 = FUN_6812fad9((int)param_3);
                  iVar4 = FUN_6810248f(param_1,piVar2,PTR_u_TxtDir_6815ff48,puVar7);
                }
                local_8 = 0xffffffff;
                if (param_2 != (int *)0x0) {
                  (**(code **)(*param_2 + 8))(param_2);
                }
                if (-1 < iVar4) {
                  CComQIPtr<>(&param_3,(undefined4 *)*piVar1);
                  local_8 = 3;
                  if (((param_3 != (int *)0x0) &&
                      (iVar4 = (**(code **)(*param_3 + 0x150))(param_3,&local_18), -1 < iVar4)) &&
                     (local_18 != (BSTR)0x0)) {
                    psVar6 = FUN_6812f174(local_14,(int)local_18);
                    iVar4 = FUN_6810248f(param_1,piVar2,PTR_u_CharSpace_6815ff58,psVar6);
                  }
                  local_8 = 0xffffffff;
                  if (param_3 != (int *)0x0) {
                    (**(code **)(*param_3 + 8))(param_3);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar4;
}


