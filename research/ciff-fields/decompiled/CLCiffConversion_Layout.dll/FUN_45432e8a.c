// Source: CLCiffConversion_Layout.dll @ 45432e8a; FUN_45432e8a

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_45432e8a(UINT param_1)

{
  _ptiddata p_Var1;
  UINT UVar2;
  pthreadmbcinfo ptVar3;
  int *piVar4;
  int iVar5;
  pthreadmbcinfo ptVar6;
  int iVar7;
  int iVar8;
  pthreadmbcinfo ptVar9;
  
  iVar8 = -1;
  p_Var1 = __getptd();
  FUN_45432de4();
  ptVar3 = p_Var1->ptmbcinfo;
  UVar2 = FUN_45432b85(param_1);
  if (UVar2 == ptVar3->mbcodepage) {
    iVar8 = 0;
  }
  else {
    ptVar3 = FUN_4543760c(0x220);
    if (ptVar3 != (pthreadmbcinfo)0x0) {
      ptVar6 = p_Var1->ptmbcinfo;
      ptVar9 = ptVar3;
      for (iVar8 = 0x88; iVar8 != 0; iVar8 = iVar8 + -1) {
        ptVar9->refcount = ptVar6->refcount;
        ptVar6 = (pthreadmbcinfo)&ptVar6->mbcodepage;
        ptVar9 = (pthreadmbcinfo)&ptVar9->mbcodepage;
      }
      iVar7 = 0;
      ptVar3->refcount = 0;
      iVar8 = FUN_45433032(UVar2,(__crt_multibyte_data *)ptVar3);
      if (iVar8 == 0) {
        LOCK();
        iVar5 = p_Var1->ptmbcinfo->refcount + -1;
        p_Var1->ptmbcinfo->refcount = iVar5;
        UNLOCK();
        if ((iVar5 == 0) && (p_Var1->ptmbcinfo != (pthreadmbcinfo)&DAT_4545dde0)) {
          FID_conflict__free(p_Var1->ptmbcinfo);
        }
        p_Var1->ptmbcinfo = ptVar3;
        LOCK();
        ptVar3->refcount = ptVar3->refcount + 1;
        UNLOCK();
        if (((p_Var1->_ownlocale & 2) == 0) && (((byte)DAT_4545e328 & 1) == 0)) {
          __lock(0xd);
          _DAT_45461210 = ptVar3->mbcodepage;
          _DAT_45461214 = ptVar3->ismbcodepage;
          _DAT_45461224 = ptVar3->mblocalename;
          for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {
            (&DAT_45461218)[iVar5] = ptVar3->mbulinfo[iVar5];
          }
          for (iVar5 = 0; iVar5 < 0x101; iVar5 = iVar5 + 1) {
            (&DAT_4545dbd8)[iVar5] = ptVar3->mbctype[iVar5];
          }
          for (; iVar7 < 0x100; iVar7 = iVar7 + 1) {
            (&DAT_4545dce0)[iVar7] = ptVar3->mbcasemap[iVar7];
          }
          LOCK();
          iVar7 = *(int *)PTR_DAT_4545e004;
          *(int *)PTR_DAT_4545e004 = iVar7 + -1;
          UNLOCK();
          if ((iVar7 + -1 == 0) && ((undefined4 *)PTR_DAT_4545e004 != &DAT_4545dde0)) {
            FID_conflict__free(PTR_DAT_4545e004);
          }
          LOCK();
          PTR_DAT_4545e004 = (undefined *)ptVar3;
          ptVar3->refcount = ptVar3->refcount + 1;
          UNLOCK();
          FUN_45432ffc();
        }
      }
      else if (iVar8 == -1) {
        if (ptVar3 != (pthreadmbcinfo)&DAT_4545dde0) {
          FID_conflict__free(ptVar3);
        }
        piVar4 = __errno();
        *piVar4 = 0x16;
      }
    }
  }
  return iVar8;
}


