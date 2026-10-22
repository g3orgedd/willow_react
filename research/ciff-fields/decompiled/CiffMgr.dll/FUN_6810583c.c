// Source: CiffMgr.dll @ 6810583c; FUN_6810583c

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_6810583c(void *this,int *param_1,VARIANTARG *param_2,uint param_3,VARIANTARG *param_4)

{
  int iVar1;
  VARIANTARG *pVVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int iVar5;
  VARIANTARG *pvarg;
  _union_2683 _Stack_48;
  _union_2683 local_38;
  void *local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined2 *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x68105848;
  iVar5 = (int)param_2 - *(int *)this >> 4;
  local_24 = iVar5;
  if (param_3 != 0) {
    iVar1 = *(int *)((int)this + 4);
    local_28 = this;
    if ((uint)(*(int *)((int)this + 8) - iVar1 >> 4) < param_3) {
      iVar5 = iVar1 - *(int *)this >> 4;
      if (0xfffffffU - iVar5 < param_3) {
                    /* WARNING: Subroutine does not return */
        FUN_68130e66("vector<T> too long");
      }
      local_28 = (void *)FUN_681046fc(this,iVar5 + param_3);
      local_18 = (undefined2 *)_Allocate<>((uint)local_28);
      local_20 = 0;
      local_1c = (int)param_2 - *(int *)this >> 4;
      local_8 = 0;
      FUN_68105b5c(local_18 + local_1c * 8,param_3,param_4);
      puVar3 = local_18;
      local_20 = 1;
      FUN_68103b7f(*(VARIANTARG **)this,param_2,local_18);
      local_20 = 2;
      FUN_68103b7f(param_2,*(VARIANTARG **)((int)this + 4),puVar3 + (local_1c + param_3) * 8);
      pVVar2 = *(VARIANTARG **)((int)this + 4);
      pvarg = *(VARIANTARG **)this;
      iVar5 = (int)pVVar2 - (int)pvarg;
      if (pvarg != (VARIANTARG *)0x0) {
        for (; pvarg != pVVar2; pvarg = pvarg + 1) {
          VariantClear(pvarg);
        }
        FID_conflict__free(*(void **)this);
      }
      *(undefined2 **)((int)this + 8) = local_18 + (int)local_28 * 8;
      *(undefined2 **)((int)this + 4) = local_18 + (param_3 + (iVar5 >> 4)) * 8;
      *(undefined2 **)this = local_18;
    }
    else if ((uint)(iVar1 - (int)param_2 >> 4) < param_3) {
      local_38.n2.vt = 0;
      FUN_68104449(&local_38,param_4);
      local_8 = 2;
      FUN_68103b7f(param_2,*(VARIANTARG **)((int)this + 4),(undefined2 *)(param_2 + param_3));
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_68105b5c(*(undefined2 **)((int)this + 4),
                   param_3 - (*(int *)((int)this + 4) - (int)param_2 >> 4),
                   (VARIANTARG *)&local_38.n2);
      *(int *)((int)this + 4) = *(int *)((int)this + 4) + param_3 * 0x10;
      local_8 = 2;
      FUN_68104b41(param_2,(VARIANTARG *)(*(int *)((int)this + 4) + param_3 * -0x10),
                   (VARIANTARG *)&local_38.n2);
      VariantClear((VARIANTARG *)&local_38.n2);
      local_24 = iVar5;
    }
    else {
      _Stack_48.n2.vt = 0;
      FUN_68104449(&_Stack_48,param_4);
      pVVar2 = *(VARIANTARG **)((int)this + 4);
      local_8 = 5;
      uVar4 = FUN_68103b7f(pVVar2 + -param_3,pVVar2,(undefined2 *)pVVar2);
      *(undefined4 *)((int)this + 4) = uVar4;
      FUN_68104b14(param_2,pVVar2 + -param_3,pVVar2);
      FUN_68104b41(param_2,param_2 + param_3,(VARIANTARG *)&_Stack_48.n2);
      VariantClear((VARIANTARG *)&_Stack_48.n2);
    }
  }
  *param_1 = local_24 * 0x10 + *(int *)this;
  return;
}


