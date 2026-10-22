// Source: CLCiffConversion_Data.dll @ 4503474e; FUN_4503474e

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_4503474e(int param_1)

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
        local_20 = &DAT_45055e8c;
        pvVar5 = DAT_45055e8c;
        goto LAB_4503480d;
      }
      if (param_1 != 4) {
        if (param_1 == 6) goto LAB_450347e5;
        if (param_1 != 8) goto LAB_450347d3;
      }
    }
    p_Var7 = __getptd_noexit();
    if (p_Var7 == (_ptiddata)0x0) {
      return 0xffffffff;
    }
    uVar2 = FUN_45034909(param_1,(uint)p_Var7->_pxcptacttab);
    local_20 = (undefined4 *)(uVar2 + 8);
    pcVar4 = (code *)*local_20;
  }
  else {
    if (param_1 == 0xf) {
      local_20 = &DAT_45055e98;
      pvVar5 = DAT_45055e98;
    }
    else if (param_1 == 0x15) {
      local_20 = &DAT_45055e90;
      pvVar5 = DAT_45055e90;
    }
    else {
      if (param_1 != 0x16) {
LAB_450347d3:
        piVar3 = __errno();
        *piVar3 = 0x16;
        FUN_45027e29();
        return 0xffffffff;
      }
LAB_450347e5:
      local_20 = &DAT_45055e94;
      pvVar5 = DAT_45055e94;
    }
LAB_4503480d:
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
      goto LAB_4503486c;
    }
  }
  else {
LAB_4503486c:
    iVar6 = DAT_45047590;
    if (param_1 == 8) {
      for (; iVar6 < DAT_45047594 + DAT_45047590; iVar6 = iVar6 + 1) {
        *(undefined4 *)((int)p_Var7->_pxcptacttab + iVar6 * 0xc + 8) = 0;
      }
      goto LAB_450348ab;
    }
  }
  pvVar5 = EncodePointer((PVOID)0x0);
  *local_20 = pvVar5;
LAB_450348ab:
  FUN_450348cf();
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


