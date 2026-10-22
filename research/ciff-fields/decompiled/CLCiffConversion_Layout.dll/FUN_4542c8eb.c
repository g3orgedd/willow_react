// Source: CLCiffConversion_Layout.dll @ 4542c8eb; FUN_4542c8eb

int * __thiscall FUN_4542c8eb(void *this,int *param_1)

{
  uint uVar1;
  _ptiddata p_Var2;
  pthreadlocinfo ptVar3;
  pthreadmbcinfo ptVar4;
  
  *(undefined1 *)((int)this + 0xc) = 0;
  if (param_1 == (int *)0x0) {
    p_Var2 = __getptd();
    *(_ptiddata *)((int)this + 8) = p_Var2;
    ptVar3 = p_Var2->ptlocinfo;
    *(pthreadlocinfo *)this = ptVar3;
    *(pthreadmbcinfo *)((int)this + 4) = p_Var2->ptmbcinfo;
    if ((ptVar3 != (pthreadlocinfo)PTR_DAT_4545e264) && ((p_Var2->_ownlocale & DAT_4545e328) == 0))
    {
      ptVar3 = FUN_45432a62();
      *(pthreadlocinfo *)this = ptVar3;
    }
    if ((*(undefined **)((int)this + 4) != PTR_DAT_4545e004) &&
       ((*(uint *)(*(int *)((int)this + 8) + 0x70) & DAT_4545e328) == 0)) {
      ptVar4 = FUN_45432de4();
      *(pthreadmbcinfo *)((int)this + 4) = ptVar4;
    }
    uVar1 = *(uint *)(*(int *)((int)this + 8) + 0x70);
    if ((uVar1 & 2) == 0) {
      *(uint *)(*(int *)((int)this + 8) + 0x70) = uVar1 | 2;
      *(undefined1 *)((int)this + 0xc) = 1;
    }
  }
  else {
    *(int *)this = *param_1;
    *(int *)((int)this + 4) = param_1[1];
  }
  return this;
}


