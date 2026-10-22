// Source: CiffMgr.dll @ 681299bb; FUN_681299bb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_681299bb(int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  bool bVar3;
  int iVar4;
  wchar_t *pwVar5;
  short *psVar6;
  undefined *puVar7;
  BSTR local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_18 = (BSTR)0x0;
  local_8 = 0;
  iVar4 = (**(code **)(*(int *)*param_2 + 0xd0))((int *)*param_2,&local_18);
  puVar2 = param_3;
  piVar1 = param_1;
  if ((-1 < iVar4) && (bVar3 = FUN_68119d18(&local_18,L"OCRB"), !bVar3)) {
    iVar4 = FUN_6810226e(piVar1,puVar2,PTR_u_Face_6815fdd0,local_18);
  }
  local_8 = 0xffffffff;
  SysFreeString(local_18);
  if ((-1 < iVar4) &&
     (iVar4 = (**(code **)(*(int *)*param_2 + 0xd8))((int *)*param_2,&param_3), -1 < iVar4)) {
    if (param_3 != (undefined4 *)0x20) {
      pwVar5 = FUN_6812ef79((int)param_3);
      iVar4 = FUN_6810248f(piVar1,puVar2,PTR_u_Family_6815fdd4,pwVar5);
    }
    if ((-1 < iVar4) &&
       (iVar4 = (**(code **)(*(int *)*param_2 + 0xe0))((int *)*param_2,&param_3), -1 < iVar4)) {
      if (param_3 != (undefined4 *)0xd) {
        psVar6 = FUN_6812f174(local_14,(int)param_3);
        iVar4 = FUN_6810248f(piVar1,puVar2,PTR_u_Pitch_6815fdd8,psVar6);
      }
      if ((-1 < iVar4) &&
         (iVar4 = (**(code **)(*(int *)*param_2 + 0xe8))((int *)*param_2,&param_3), -1 < iVar4)) {
        if (param_3 != (undefined4 *)0x64) {
          psVar6 = FUN_6812f174(local_14,(int)param_3);
          iVar4 = FUN_6810248f(piVar1,puVar2,PTR_u_XMag_6815fddc,psVar6);
        }
        if ((-1 < iVar4) &&
           (iVar4 = (**(code **)(*(int *)*param_2 + 0x13c))((int *)*param_2,&param_3), -1 < iVar4))
        {
          if (param_3 != (undefined4 *)0x64) {
            psVar6 = FUN_6812f174(local_14,(int)param_3);
            iVar4 = FUN_6810248f(piVar1,puVar2,PTR_u_YMag_6815fde0,psVar6);
          }
          if ((-1 < iVar4) &&
             (iVar4 = (**(code **)(*(int *)*param_2 + 0x144))((int *)*param_2,&param_3), -1 < iVar4)
             ) {
            if (param_3 != (undefined4 *)0x0) {
              psVar6 = FUN_6812f174(local_14,(int)param_3);
              iVar4 = FUN_6810248f(piVar1,puVar2,PTR_u_TTSize_6815fde4,psVar6);
            }
            if (-1 < iVar4) {
              CComQIPtr<>(&param_2,(undefined4 *)*param_2);
              local_8 = 1;
              if (((param_2 != (int *)0x0) &&
                  (iVar4 = (**(code **)(*param_2 + 0x1a4))(param_2,&param_1), -1 < iVar4)) &&
                 (param_1 != (int *)0x0)) {
                puVar7 = FUN_6812fad9((int)param_1);
                iVar4 = FUN_6810248f(piVar1,puVar2,PTR_u_TxtDir_6815ff48,puVar7);
              }
              local_8 = 0xffffffff;
              if (param_2 != (int *)0x0) {
                (**(code **)(*param_2 + 8))(param_2);
              }
            }
          }
        }
      }
    }
  }
  return iVar4;
}


