// Source: CLCiffConversion_Layout.dll @ 4543b5ad; FUN_4543b5ad

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_4543b5ad(int param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  code *pcVar4;
  PVOID pvVar5;
  int iVar6;
  _ptiddata p_Var7;
  int local_34;
  void *local_30;
  undefined4 *local_20;
  
  local_30 = (void *)0x0;
  local_34 = 0;
  bVar1 = false;
  p_Var7 = (_ptiddata)0x0;
  if (param_1 < 0xc) {
    if (param_1 != 0xb) {
      if (param_1 == 2) {
        local_20 = &DAT_45461690;
        pvVar5 = DAT_45461690;
        goto LAB_4543b66c;
      }
      if (param_1 != 4) {
        if (param_1 == 6) goto LAB_4543b644;
        if (param_1 != 8) goto LAB_4543b632;
      }
    }
    p_Var7 = __getptd_noexit();
    if (p_Var7 == (_ptiddata)0x0) {
      return 0xffffffff;
    }
    uVar2 = FUN_4543b768(param_1,(uint)p_Var7->_pxcptacttab);
    local_20 = (undefined4 *)(uVar2 + 8);
    pcVar4 = (code *)*local_20;
  }
  else {
    if (param_1 == 0xf) {
      local_20 = &DAT_4546169c;
      pvVar5 = DAT_4546169c;
    }
    else if (param_1 == 0x15) {
      local_20 = &DAT_45461694;
      pvVar5 = DAT_45461694;
    }
    else {
      if (param_1 != 0x16) {
LAB_4543b632:
        piVar3 = __errno();
        *piVar3 = 0x16;
        FUN_45432798();
        return 0xffffffff;
      }
LAB_4543b644:
      local_20 = &DAT_45461698;
      pvVar5 = DAT_45461698;
    }
LAB_4543b66c:
    bVar1 = true;
    pcVar4 = DecodePointer(pvVar5);
  }
  if (pcVar4 == (code *)0x1) {
    return 0;
  }
  if (pcVar4 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (bVar1) {
    __lock(0);
  }
  if (((param_1 == 8) || (param_1 == 0xb)) || (param_1 == 4)) {
    local_30 = p_Var7->_tpxcptinfoptrs;
    p_Var7->_tpxcptinfoptrs = (void *)0x0;
    if (param_1 == 8) {
      local_34 = p_Var7->_tfpecode;
      p_Var7->_tfpecode = 0x8c;
      goto LAB_4543b6cb;
    }
  }
  else {
LAB_4543b6cb:
    iVar6 = DAT_45450eb8;
    if (param_1 == 8) {
      for (; iVar6 < DAT_45450ebc + DAT_45450eb8; iVar6 = iVar6 + 1) {
        *(undefined4 *)((int)p_Var7->_pxcptacttab + iVar6 * 0xc + 8) = 0;
      }
      goto LAB_4543b70a;
    }
  }
  pvVar5 = EncodePointer((PVOID)0x0);
  *local_20 = pvVar5;
LAB_4543b70a:
  FUN_4543b72e();
  if (param_1 == 8) {
    (*pcVar4)(8,p_Var7->_tfpecode);
  }
  else {
    (*pcVar4)(param_1);
    if ((param_1 != 0xb) && (param_1 != 4)) {
      return 0;
    }
  }
  p_Var7->_tpxcptinfoptrs = local_30;
  if (param_1 == 8) {
    p_Var7->_tfpecode = local_34;
  }
  return 0;
}


