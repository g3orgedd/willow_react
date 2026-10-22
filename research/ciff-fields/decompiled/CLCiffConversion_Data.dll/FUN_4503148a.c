// Source: CLCiffConversion_Data.dll @ 4503148a; FUN_4503148a

undefined4 __cdecl FUN_4503148a(int param_1,void *param_2)

{
  int *piVar1;
  code *pcVar2;
  void *pvVar3;
  _ptiddata p_Var4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  
  p_Var4 = __getptd_noexit();
  uVar5 = 0;
  if (p_Var4 != (_ptiddata)0x0) {
    piVar1 = p_Var4->_pxcptacttab;
    piVar6 = piVar1;
    do {
      if (*piVar6 == param_1) break;
      piVar6 = piVar6 + 3;
    } while (piVar6 < piVar1 + 0x24);
    if ((piVar1 + 0x24 <= piVar6) || (*piVar6 != param_1)) {
      piVar6 = (int *)0x0;
    }
    if ((piVar6 == (int *)0x0) || (pcVar2 = (code *)piVar6[2], pcVar2 == (code *)0x0)) {
      uVar5 = 0;
    }
    else if (pcVar2 == (code *)0x5) {
      piVar6[2] = 0;
      uVar5 = 1;
    }
    else if (pcVar2 == (code *)0x1) {
      uVar5 = 0xffffffff;
    }
    else {
      pvVar3 = p_Var4->_tpxcptinfoptrs;
      p_Var4->_tpxcptinfoptrs = param_2;
      if (piVar6[1] == 8) {
        iVar7 = 0x24;
        do {
          *(undefined4 *)(iVar7 + 8 + (int)p_Var4->_pxcptacttab) = 0;
          iVar7 = iVar7 + 0xc;
        } while (iVar7 < 0x90);
        iVar7 = p_Var4->_tfpecode;
        if (*piVar6 == -0x3fffff72) {
          p_Var4->_tfpecode = 0x83;
        }
        else if (*piVar6 == -0x3fffff70) {
          p_Var4->_tfpecode = 0x81;
        }
        else if (*piVar6 == -0x3fffff6f) {
          p_Var4->_tfpecode = 0x84;
        }
        else if (*piVar6 == -0x3fffff6d) {
          p_Var4->_tfpecode = 0x85;
        }
        else if (*piVar6 == -0x3fffff73) {
          p_Var4->_tfpecode = 0x82;
        }
        else if (*piVar6 == -0x3fffff71) {
          p_Var4->_tfpecode = 0x86;
        }
        else if (*piVar6 == -0x3fffff6e) {
          p_Var4->_tfpecode = 0x8a;
        }
        else if (*piVar6 == -0x3ffffd4b) {
          p_Var4->_tfpecode = 0x8d;
        }
        else if (*piVar6 == -0x3ffffd4c) {
          p_Var4->_tfpecode = 0x8e;
        }
        (*pcVar2)(8,p_Var4->_tfpecode);
        p_Var4->_tfpecode = iVar7;
      }
      else {
        piVar6[2] = 0;
        (*pcVar2)(piVar6[1]);
      }
      p_Var4->_tpxcptinfoptrs = pvVar3;
      uVar5 = 0xffffffff;
    }
  }
  return uVar5;
}


