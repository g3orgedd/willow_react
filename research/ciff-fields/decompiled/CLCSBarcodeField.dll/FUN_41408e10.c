// Source: CLCSBarcodeField.dll @ 41408e10; FUN_41408e10

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_41408e10(void *this,int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  UINT UVar5;
  undefined4 *puVar6;
  float fVar7;
  int *piVar8;
  undefined4 local_20;
  int *local_1c;
  int local_18;
  uint local_8;
  undefined4 uStack_4;
  
  piVar2 = param_3;
  piVar8 = param_1;
  uStack_4 = 0x14;
  if (((*param_1 == 0) || (piVar1 = (int *)*param_2, piVar1 == (int *)0x0)) || (*param_3 == 0)) {
    iVar3 = -0x7fffbffd;
  }
  else {
    local_18 = 0;
    local_8 = 0;
    iVar3 = (**(code **)(*piVar1 + 0x2c))(piVar1,&param_3);
    FUN_41408310(iVar3);
    local_1c = (int *)((float)param_3 * _DAT_4148100c);
    iVar3 = FUN_414092db((float)local_1c);
    *(int *)((int)this + 0x28) = iVar3;
    *(int **)((int)this + 0x30) = local_1c;
    iVar3 = (**(code **)(*(int *)*param_2 + 0x34))((int *)*param_2,&param_3);
    FUN_41408310(iVar3);
    fVar7 = (float)param_3 * _DAT_4148100c;
    *(float *)((int)this + 0x34) = fVar7;
    iVar3 = FUN_414092db(fVar7);
    *(int *)((int)this + 0x2c) = iVar3;
    iVar3 = (**(code **)(*(int *)*piVar8 + 0x54))((int *)*piVar8,(int)this + 0x24);
    if (-1 < iVar3) {
      local_18 = iVar3;
      iVar4 = (**(code **)(*(int *)*piVar2 + 0x1c))((int *)*piVar2,(int)this + 0x3c);
      FUN_41408310(iVar4);
      param_1 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar4 = (**(code **)(*(int *)*piVar2 + 0x5c))((int *)*piVar2,&param_1);
      FUN_41408310(iVar4);
      if (param_1 != (int *)0x0) {
        iVar3 = (**(code **)(*(int *)*piVar2 + 0x98))((int *)*piVar2,(int)this + 0x38);
        local_18 = iVar3;
        UVar5 = SysStringLen(*(BSTR *)((int)this + 0x38));
        if (UVar5 == 0) {
          puVar6 = (undefined4 *)((int)this + 0x40);
          *(undefined4 *)((int)this + 0x50) = 0;
          if (7 < *(uint *)((int)this + 0x54)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          *(undefined2 *)puVar6 = 0;
        }
        else {
          FID_conflict_assign((void *)((int)this + 0x40),*(wchar_t **)((int)this + 0x38));
        }
      }
      if (-1 < iVar3) {
        iVar4 = (**(code **)(*(int *)*piVar2 + 0x2c))((int *)*piVar2,(int)this + 0xbc);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0x34))((int *)*piVar2,(int)this + 0xc0);
        FUN_41408310(iVar4);
        *(undefined4 *)((int)this + 0xbc) = 0;
        *(undefined4 *)((int)this + 0xc0) = 0;
        iVar4 = (**(code **)(*(int *)*piVar2 + 0x3c))((int *)*piVar2,(int)this + 0x70);
        FUN_41408310(iVar4);
        *(undefined4 *)((int)this + 0x70) = 0;
        iVar4 = (**(code **)(*(int *)*piVar2 + 0x4c))((int *)*piVar2,(int)this + 0x74);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0x44))((int *)*piVar2,(int)this + 0x78);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0x54))((int *)*piVar2,(int)this + 0x7c);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0xc0))((int *)*piVar2,(int)this + 0x80);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 200))((int *)*piVar2,(int)this + 0x84);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0x100))((int *)*piVar2,(int)this + 0x88);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0x108))((int *)*piVar2,(int)this + 0x8c);
        FUN_41408310(iVar4);
        local_1c = (int *)((int)this + 0x90);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0xb0))((int *)*piVar2,local_1c);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0xb8))((int *)*piVar2,(int)this + 0xd4);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0x80))((int *)*piVar2,(int)this + 200);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0x78))((int *)*piVar2,(int)this + 0xc4);
        FUN_41408310(iVar4);
        *(undefined4 *)((int)this + 200) = *(undefined4 *)((int)this + 0xd4);
        UVar5 = SysStringLen(*(BSTR *)((int)this + 0x38));
        if (*(int *)((int)this + 0x8c) != 0) {
          UVar5 = UVar5 + 2;
        }
        *(UINT *)((int)this + 0xcc) = UVar5 * 400;
        UVar5 = SysStringLen(*(BSTR *)((int)this + 0x38));
        if (UVar5 < 4) {
          *(int *)((int)this + 0xcc) = *(int *)((int)this + 0xcc) + 400;
        }
        iVar4 = FUN_41409304((double)(*(int *)((int)this + 0xcc) * *(int *)((int)this + 0x90)) /
                             DAT_41481000);
        *(int *)((int)this + 0xcc) = iVar4;
        iVar4 = FUN_41409304((double)((*(int *)((int)this + 200) + 0x14) *
                                      *(int *)((int)this + 0x90) * 2) / DAT_41481000);
        *(int *)((int)this + 0xd0) = iVar4;
        if (*(int *)((int)this + 0x24) == 0) {
          FUN_4144c328(&local_20);
          local_8 = CONCAT31(local_8._1_3_,2);
          piVar8 = (int *)*param_2;
          if (piVar8 != (int *)0x0) {
            (**(code **)(*piVar8 + 4))(piVar8);
          }
          iVar4 = FUN_4144c3fb(*(int *)((int)this + 0xd4),0.0,piVar8);
          *(int *)((int)this + 0xd4) = iVar4;
          piVar8 = (int *)*param_2;
          if (piVar8 != (int *)0x0) {
            (**(code **)(*piVar8 + 4))(piVar8);
          }
          iVar4 = FUN_4144c3fb(*(int *)((int)this + 200),0.0,piVar8);
          *(int *)((int)this + 200) = iVar4;
          piVar8 = (int *)*param_2;
          if (piVar8 != (int *)0x0) {
            (**(code **)(*piVar8 + 4))(piVar8);
          }
          iVar4 = FUN_4144c3fb(*(int *)((int)this + 0xc4),1.4013e-45,piVar8);
          *(int *)((int)this + 0xc4) = iVar4;
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_4144c348(&local_20);
        }
        iVar4 = (**(code **)(*(int *)*piVar2 + 0xd0))((int *)*piVar2,(int)this + 0x94);
        FUN_41408310(iVar4);
        FUN_41407cc3((void *)((int)this + 0x94),"OCRB");
        iVar4 = (**(code **)(*(int *)*piVar2 + 0xd4))
                          ((int *)*piVar2,*(undefined4 *)((int)this + 0x94));
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0xd8))((int *)*piVar2,(int)this + 0x98);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0xe8))((int *)*piVar2,(int)this + 0x9c);
        FUN_41408310(iVar4);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0xe0))
                          ((int *)*piVar2,(undefined4 *)((int)this + 0xa0));
        FUN_41408310(iVar4);
        param_2 = (int *)((*local_1c * 0x14) / 1000);
        iVar4 = (**(code **)(*(int *)*piVar2 + 0xe4))((int *)*piVar2,0x14);
        FUN_41408310(iVar4);
        *(undefined4 *)((int)this + 0xa0) = param_2;
      }
      local_8 = local_8 & 0xffffff00;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    }
  }
  return iVar3;
}


