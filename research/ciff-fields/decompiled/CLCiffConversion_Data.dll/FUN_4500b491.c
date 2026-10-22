// Source: CLCiffConversion_Data.dll @ 4500b491; FUN_4500b491

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void * __cdecl FUN_4500b491(void *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 *puVar3;
  undefined3 extraout_var_00;
  int iVar4;
  LPCWSTR local_1c;
  undefined *local_18;
  undefined *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x4500b49d;
  iVar4 = 1;
  iVar2 = FUN_450032a1();
  if (0 < iVar2) {
    do {
      FUN_4500b3b7(&local_1c);
      local_8 = 0;
      bVar1 = FUN_450034f4(local_1c,(ushort *)*param_2);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        local_14[0] = PTR_DAT_4505101c;
        local_8._0_1_ = 1;
        puVar3 = FUN_4501cb23(&local_18,0x64cc);
        local_8._0_1_ = 2;
        bVar1 = FUN_450034f4((LPCWSTR)*param_2,(ushort *)*puVar3);
        local_8 = CONCAT31(local_8._1_3_,1);
        FUN_45002256((int *)&local_18);
        if (CONCAT31(extraout_var_00,bVar1) == 0) {
          FUN_45008a06(local_14,param_2);
        }
        else {
          FUN_45002365(local_14,L"Table containing Index Fields");
        }
        local_18 = PTR_DAT_4505101c;
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_450037ea(&local_18,L"%s_%s");
        FUN_4500201a(param_1,(int *)&local_18);
        FUN_45002256((int *)&local_18);
        FUN_45002256((int *)local_14);
        FUN_45002256((int *)&local_1c);
        return param_1;
      }
      local_8 = 0xffffffff;
      FUN_45002256((int *)&local_1c);
      iVar4 = iVar4 + 1;
      iVar2 = FUN_450032a1();
    } while (iVar4 <= iVar2);
  }
  FUN_45002050(param_1,"");
  return param_1;
}


