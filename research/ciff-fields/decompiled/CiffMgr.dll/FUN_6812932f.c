// Source: CiffMgr.dll @ 6812932f; FUN_6812932f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6812932f(BSTR param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  _union_2683 local_24;
  int local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 0x14;
  local_8 = 0x6812933b;
  iVar2 = FUN_6812a3fb(param_1,param_2,param_3);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*(int *)*piVar1 + 0x24))((int *)*piVar1,local_14);
    if (-1 < iVar2) {
      if (local_14[0] != 0) {
        puVar3 = FUN_6812f5f0(local_14[0]);
        iVar2 = FUN_6810248f((int *)param_1,param_3,PTR_u_ImageQuality_6815feac,puVar3);
      }
      if (-1 < iVar2) {
        iVar2 = (**(code **)(*(int *)*piVar1 + 0x2c))((int *)*piVar1,local_14);
        if (-1 < iVar2) {
          if (local_14[0] != 0) {
            puVar3 = FUN_6812e9d1(local_14[0]);
            iVar2 = FUN_6810248f((int *)param_1,param_3,PTR_u_SelectAfterDownload_6815feb0,puVar3);
          }
          if (-1 < iVar2) {
            FUN_68132710((uint *)&local_24,0,0x10);
            VariantInit((VARIANTARG *)&local_24.n2);
            local_8 = 0;
            iVar2 = (**(code **)(*(int *)*piVar1 + 0x4c))((int *)*piVar1,&local_24);
            if ((-1 < iVar2) && (local_24.n2.vt == 9)) {
              param_2 = (int *)0x0;
              local_8 = CONCAT31(local_8._1_3_,1);
              iVar2 = (*(code *)**(undefined4 **)local_24._8_4_)
                                (local_24._8_4_,&DAT_68148824,&param_2);
              if ((-1 < iVar2) && (param_2 != (int *)0x0)) {
                iVar2 = FUN_6812afaf(param_1,(int *)&param_2,param_3);
              }
              local_8 = local_8 & 0xffffff00;
              if (param_2 != (int *)0x0) {
                (**(code **)(*param_2 + 8))(param_2);
              }
            }
            VariantClear((VARIANTARG *)&local_24.n2);
          }
        }
      }
    }
  }
  return iVar2;
}


