// Source: CLCiffConversion_Layout.dll @ 4541770e; FUN_4541770e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4541770e(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined4 *puVar5;
  float10 fVar6;
  float fVar7;
  wchar_t *local_3c;
  undefined4 *local_38;
  float local_34;
  float local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x4541771a;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFResolutionAdjust::Convert");
  local_3c = (wchar_t *)0x0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  (**(code **)(*(int *)*param_1 + 0x34))((int *)*param_1,&local_3c);
  FUN_45402ac2(&local_30,local_3c);
  local_8._0_1_ = 2;
  FUN_4540303d(0x454498d8);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_45402c5d((int *)&local_30);
  FUN_45404ce5((void *)((int)this + *(int *)(*(int *)((int)this + -0x10) + 4) + 0x4c),param_1);
  cVar4 = FUN_4540678d((int)this + *(int *)(*(int *)((int)this + -0x10) + 4) + -0x10);
  if (cVar4 == '\0') {
    FUN_4540303d(0x45449914);
    fVar6 = FUN_45406d0a((int)this + *(int *)(*(int *)((int)this + -0x10) + 4) + -0x10);
    local_30 = (float)fVar6;
    fVar6 = FUN_4541c700(param_1);
    fVar7 = 0.0;
    local_34 = (float)fVar6;
    if ((0.0 < local_30) && (0.0 < local_34)) {
      fVar7 = local_30 / local_34;
    }
    *(float *)((int)this + -0xc) = fVar7;
    fVar6 = FUN_45406d26((int)this + *(int *)(*(int *)((int)this + -0x10) + 4) + -0x10);
    local_34 = (float)fVar6;
    fVar6 = FUN_4541c720(param_1);
    fVar7 = 0.0;
    local_30 = (float)fVar6;
    if ((0.0 < local_34) && (0.0 < local_30)) {
      fVar7 = local_34 / local_30;
    }
    *(float *)((int)this + -8) = fVar7;
    FUN_4540303d(0x4544993c);
    if ((*(float *)((int)this + -0xc) != DAT_45447a24) &&
       (*(float *)((int)this + -8) != DAT_45447a24)) {
      piVar1 = (int *)*param_1;
      iVar2 = *piVar1;
      FUN_45406d0a((int)this + *(int *)(*(int *)((int)this + -0x10) + 4) + -0x10);
      (**(code **)(iVar2 + 0x70))(piVar1);
      piVar1 = (int *)*param_1;
      iVar2 = *piVar1;
      fVar6 = FUN_45406d26((int)this + *(int *)(*(int *)((int)this + -0x10) + 4) + -0x10);
      (**(code **)(iVar2 + 0x78))(piVar1,(float)fVar6);
      local_30 = 0.0;
      piVar1 = *(int **)(*(int *)(*(int *)((int)this + -0x10) + 4) + 0x24 + (int)this);
      (**(code **)(*piVar1 + 0x54))(piVar1,&local_34);
      if (local_34 != 0.0) {
        (**(code **)(*(int *)*param_1 + 0x44))((int *)*param_1);
        local_30 = (float)(int)((float)(int)local_30 * *(float *)((int)this + -8));
        (**(code **)(*(int *)*param_1 + 0x48))((int *)*param_1,local_30);
        (**(code **)(*(int *)*param_1 + 0x68))((int *)*param_1,local_30);
        (**(code **)(*(int *)*param_1 + 0x3c))((int *)*param_1,&local_30);
        local_30 = (float)(int)((float)(int)local_30 * *(float *)((int)this + -0xc));
        (**(code **)(*(int *)*param_1 + 0x40))((int *)*param_1,local_30);
        (**(code **)(*(int *)*param_1 + 0x60))((int *)*param_1,local_30);
      }
      local_34 = 0.0;
      local_38 = (undefined4 *)FUN_454043b0((int *)0x0,(int *)0x0);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_45406d62(param_1,&local_38);
      puVar3 = local_38;
      for (puVar5 = (undefined4 *)*local_38; puVar5 != puVar3; puVar5 = (undefined4 *)*puVar5) {
        (**(code **)(*(int *)((int)this + *(int *)(*(int *)((int)this + -0x10) + 4) + -0x10) + 0x10)
        )();
      }
      FUN_454065f3((int *)&local_38);
      iVar2 = *(int *)(*(int *)((int)this + -0x10) + 4);
      piVar1 = *(int **)(iVar2 + 0x4c + (int)this);
      if ((piVar1 != (int *)0x0) &&
         (*(undefined4 *)(iVar2 + 0x4c + (int)this) = 0, piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 8))();
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_454224ff((int *)&local_38);
      FID_conflict__free(local_38);
    }
    FUN_4540303d(0x4544995c);
  }
  else {
    FUN_4540303d(0x454498ec);
  }
  SysFreeString(local_3c);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


