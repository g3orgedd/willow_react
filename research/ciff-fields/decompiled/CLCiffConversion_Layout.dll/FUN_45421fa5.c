// Source: CLCiffConversion_Layout.dll @ 45421fa5; FUN_45421fa5

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_45421fa5(void *this,int *param_1,int *param_2,uint param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *this_00;
  int *local_24;
  undefined4 *local_20;
  undefined4 local_1c;
  int *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x45421fb1;
  iVar6 = (int)param_2 - *(int *)this;
  if (param_3 != 0) {
    iVar5 = *(int *)((int)this + 4);
    local_18 = this;
    if ((uint)(*(int *)((int)this + 8) - iVar5 >> 2) < param_3) {
      iVar5 = iVar5 - *(int *)this >> 2;
      if (0x3fffffffU - iVar5 < param_3) {
                    /* WARNING: Subroutine does not return */
        FUN_45429486("vector<T> too long");
      }
      uVar3 = FUN_45421f4d(this,iVar5 + param_3);
      puVar4 = (undefined4 *)_Allocate<>(uVar3);
      local_24 = (int *)((int)param_2 - *(int *)this >> 2);
      local_8 = 0;
      local_1c = 0;
      local_20 = puVar4;
      FUN_454224a9(puVar4 + (int)local_24,param_3,param_4);
      local_1c = 1;
      FUN_45412315(*(undefined4 **)this,param_2,puVar4);
      local_1c = 2;
      FUN_45412315(param_2,*(undefined4 **)((int)this + 4),puVar4 + (int)local_24 + param_3);
      iVar5 = *(int *)((int)this + 4);
      iVar1 = *(int *)this;
      if (*(int *)this != 0) {
        FUN_45421f2e(*(void **)this,*(void **)((int)this + 4));
        FID_conflict__free(*(void **)this);
      }
      *(undefined4 **)this = puVar4;
      *(undefined4 **)((int)this + 8) = puVar4 + uVar3;
      *(undefined4 **)((int)this + 4) = puVar4 + param_3 + (iVar5 - iVar1 >> 2);
    }
    else {
      piVar2 = (int *)*param_4;
      if ((uint)(iVar5 - (int)param_2 >> 2) < param_3) {
        local_24 = piVar2;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 4))(piVar2);
        }
        local_8 = 2;
        FUN_45412315(param_2,*(undefined4 **)((int)this + 4),param_2 + param_3);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_45412391(*(int **)((int)this + 4),
                     param_3 - (*(int *)((int)this + 4) - (int)param_2 >> 2),(int *)&local_24);
        *(int *)((int)this + 4) = *(int *)((int)this + 4) + param_3 * 4;
        iVar5 = *(int *)((int)this + 4);
        for (; param_2 != (int *)(iVar5 + param_3 * -4); param_2 = param_2 + 1) {
          FUN_45404ce5(param_2,(int *)&local_24);
        }
        local_8 = 0xffffffff;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))(piVar2);
        }
      }
      else {
        param_4 = piVar2;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 4))(piVar2);
        }
        puVar4 = *(undefined4 **)((int)this + 4);
        local_8 = 5;
        iVar5 = FUN_45412315(puVar4 + -param_3,puVar4,puVar4);
        local_18[1] = iVar5;
        FUN_45412204(param_2,puVar4 + -param_3,puVar4);
        for (this_00 = param_2; this_00 != param_2 + param_3; this_00 = this_00 + 1) {
          FUN_45404ce5(this_00,(int *)&param_4);
        }
        local_8 = 0xffffffff;
        this = local_18;
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))(piVar2);
          this = local_18;
        }
      }
    }
  }
  *param_1 = *(int *)this + (iVar6 >> 2) * 4;
  return;
}


