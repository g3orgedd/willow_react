// Source: CiffMgr.dll @ 68124afe; FUN_68124afe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68124afe(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  short *psVar3;
  undefined *puVar4;
  int local_1c;
  void *local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar2 = (*(code *)**(undefined4 **)*param_2)((undefined4 *)*param_2,&DAT_6814a7fc,local_14);
  if (((-1 < iVar2) && (local_14[0] != (int *)0x0)) &&
     (iVar2 = (**(code **)(*local_14[0] + 0xb0))(local_14[0],&local_1c), puVar1 = param_3,
     -1 < iVar2)) {
    if (local_1c != 1000) {
      psVar3 = FUN_6812f174(local_18,local_1c);
      iVar2 = FUN_6810248f(param_1,puVar1,PTR_DAT_6815fdfc,psVar3);
    }
    if (-1 < iVar2) {
      CComQIPtr<>(&param_2,local_14[0]);
      local_8._0_1_ = 1;
      if (((param_2 != (int *)0x0) &&
          (iVar2 = (**(code **)(*param_2 + 0x1ec))(param_2,&param_3), -1 < iVar2)) &&
         (param_3 != (undefined4 *)0x32)) {
        psVar3 = FUN_6812f174(local_18,(int)param_3);
        iVar2 = FUN_6810248f(param_1,puVar1,PTR_u_MagRnd_6815ffac,psVar3);
      }
      local_8._0_1_ = 0;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
      if ((-1 < iVar2) &&
         (iVar2 = (**(code **)(*local_14[0] + 0xb8))(local_14[0],&param_2), -1 < iVar2)) {
        psVar3 = FUN_6812f174(local_18,(int)param_2);
        iVar2 = FUN_6810248f(param_1,puVar1,PTR_DAT_6815fe00,psVar3);
        if (-1 < iVar2) {
          param_2 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,2);
          iVar2 = FUN_68124179(param_1,puVar1,PTR_DAT_6815fe04,(int *)&param_2);
          if (-1 < iVar2) {
            iVar2 = FUN_6812a184(param_1,(int *)local_14,&param_2);
          }
          local_8 = local_8 & 0xffffff00;
          if (param_2 != (int *)0x0) {
            (**(code **)(*param_2 + 8))(param_2);
          }
          if ((-1 < iVar2) &&
             (iVar2 = (**(code **)(*local_14[0] + 0x100))(local_14[0],&param_2), -1 < iVar2)) {
            if (param_2 != (int *)0x0) {
              puVar4 = FUN_6812e9d1((int)param_2);
              iVar2 = FUN_6810248f(param_1,puVar1,PTR_u_CheckDigit_6815fe08,puVar4);
            }
            if ((-1 < iVar2) &&
               (iVar2 = (**(code **)(*local_14[0] + 0x108))(local_14[0],&param_2), -1 < iVar2)) {
              if (param_2 != (int *)0x1) {
                puVar4 = FUN_6812e9d1((int)param_2);
                iVar2 = FUN_6810248f(param_1,puVar1,PTR_u_QuietMargin_6815fe0c,puVar4);
              }
              if ((-1 < iVar2) &&
                 (iVar2 = (**(code **)(*local_14[0] + 0x14c))(local_14[0],&param_2), -1 < iVar2)) {
                if (param_2 != (int *)0x0) {
                  psVar3 = FUN_6812f174(local_18,(int)param_2);
                  iVar2 = FUN_6810248f(param_1,puVar1,PTR_u_XOffSet_6815fe10,psVar3);
                }
                if (-1 < iVar2) {
                  CComQIPtr<>(&param_2,local_14[0]);
                  local_8._0_1_ = 3;
                  if (((param_2 != (int *)0x0) &&
                      (iVar2 = (**(code **)(*param_2 + 0x20c))(param_2,&param_3), -1 < iVar2)) &&
                     (param_3 != (undefined4 *)0x0)) {
                    puVar4 = FUN_6812e903((int)param_3);
                    iVar2 = FUN_6810248f(param_1,puVar1,PTR_u_BarcodePrinting_6815ffd4,puVar4);
                  }
                  local_8._0_1_ = 0;
                  if (param_2 != (int *)0x0) {
                    (**(code **)(*param_2 + 8))(param_2);
                  }
                  if ((-1 < iVar2) &&
                     (iVar2 = (**(code **)(*local_14[0] + 0xa8))(local_14[0],&param_3), -1 < iVar2))
                  {
                    param_2 = (int *)0x0;
                    local_8 = CONCAT31(local_8._1_3_,4);
                    iVar2 = FUN_68124179(param_1,puVar1,
                                         (&PTR_DAT_6815fc38)
                                         [*(int *)(&DAT_6814b8e8 + (int)param_3 * 8)],
                                         (int *)&param_2);
                    if (-1 < iVar2) {
                      iVar2 = FUN_68124e3d(local_18,param_1,(int *)local_14,&param_2,
                                           *(int **)(&DAT_6814b8ec + (int)param_3 * 8));
                    }
                    local_8 = local_8 & 0xffffff00;
                    if (param_2 != (int *)0x0) {
                      (**(code **)(*param_2 + 8))(param_2);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar2;
}


