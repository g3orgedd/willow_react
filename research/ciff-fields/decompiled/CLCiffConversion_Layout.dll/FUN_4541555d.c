// Source: CLCiffConversion_Layout.dll @ 4541555d; FUN_4541555d

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */

void __thiscall FUN_4541555d(void *this,void *param_1,int *param_2,int *param_3)

{
  void *pvVar1;
  undefined1 uVar2;
  bool bVar3;
  HRESULT HVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int extraout_EAX;
  BSTR extraout_EAX_00;
  BSTR extraout_ECX;
  byte bVar9;
  BSTR pOVar10;
  BSTR pOVar11;
  undefined1 auStack_1500 [8];
  undefined4 uStack_14f8;
  ULONG local_14c8;
  int *piStack_14c4;
  int *piStack_14c0;
  int *local_1480;
  VARIANTARG local_147c;
  _union_2683 local_146c;
  int *local_145c;
  BSTR local_1458;
  int *local_1454;
  BSTR local_1450;
  int local_144c;
  _union_2683 local_1448;
  BSTR local_1438;
  undefined1 local_1434 [16];
  BSTR local_1424;
  BSTR local_1420;
  void *local_141c;
  BSTR local_1418;
  int *local_1414;
  void *local_1410;
  undefined1 local_1409;
  BSTR local_1408;
  BSTR local_1404;
  BSTR local_1400;
  BSTR local_13fc;
  BSTR local_13f8;
  BSTR local_13f4;
  byte local_13ed;
  int local_13ec [1270];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  local_8 = 0xff;
  uStack_7 = 0xffffff;
  puStack_c = &LAB_4544405f;
  local_10 = ExceptionList;
  local_14 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  bVar9 = 0;
  local_141c = param_1;
  local_1414 = param_3;
  local_144c = 0;
  local_1410 = this;
  if ((*(int **)((int)this + 0x38) != (int *)0x0) &&
     ((**(code **)(**(int **)((int)this + 0x38) + 0x29c))(), local_144c == 1)) goto LAB_45415e3f;
  local_1418 = (BSTR)0x0;
  pOVar10 = (BSTR)0x0;
  local_1408 = (BSTR)0x0;
  FUN_4541cdb6(param_1,&local_1450);
  local_8 = 0;
  uStack_7 = 0;
  piVar5 = *(int **)*param_2;
  if (piVar5 != (int *)*param_2) {
    do {
      local_1404 = (BSTR)piVar5[2];
      FUN_4541db3e(local_1404,&local_1438);
      local_8 = 1;
      if (pOVar10 == (BSTR)0x0) {
        pOVar10 = local_1404;
      }
      local_1408 = pOVar10;
      HVar4 = VarBstrCmp(local_1450,local_1438,0x400,0);
      pOVar11 = local_1404;
      if (HVar4 == 1) {
        local_1404 = (BSTR)FUN_4541d9ab((undefined4 *)local_1404);
        FUN_45429f70((uint *)&local_1448,0,0x10);
        VariantInit((VARIANTARG *)&local_1448.n2);
        local_8 = 2;
        (**(code **)(**(int **)((int)local_1410 + 0x6c) + 0x7c))();
        if (local_1448.n2.vt != 0) {
          CComQIPtr<>(&local_13f4,(undefined4 *)local_1448._8_4_);
          if (local_13f4 != (BSTR)0x0) {
            FUN_45429f70((uint *)local_1434,0,0x10);
            VariantInit((VARIANTARG *)&((_union_2683 *)local_1434)->n2);
            local_8 = 4;
            (**(code **)(*(int *)local_13f4 + 0x30))();
            if ((local_1434._0_2_ != 0) && ((int)local_1404 <= *local_1414)) {
              local_1418 = (BSTR)0x1;
              local_1408 = pOVar11;
              pOVar10 = pOVar11;
            }
            VariantClear((VARIANTARG *)&((_union_2683 *)local_1434)->n2);
          }
          local_8 = 2;
          if (local_13f4 != (BSTR)0x0) {
            (**(code **)(*(int *)local_13f4 + 8))();
          }
        }
        VariantClear((VARIANTARG *)&local_1448.n2);
        local_8 = 0;
        SysFreeString(local_1438);
        if (local_1418 == (BSTR)0x1) goto LAB_45415923;
        break;
      }
      local_8 = 0;
      SysFreeString(local_1438);
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*param_2);
  }
  piVar5 = *(int **)*param_2;
  if (piVar5 != (int *)*param_2) {
    do {
      local_13fc = (BSTR)piVar5[2];
      local_13f4 = (BSTR)FUN_4541d9ab((undefined4 *)local_13fc);
      pOVar11 = pOVar10;
      if (pOVar10 == (BSTR)0x0) {
        pOVar11 = local_13fc;
      }
      local_1408 = pOVar11;
      FUN_45429f70((uint *)&local_1448,0,0x10);
      VariantInit((VARIANTARG *)&local_1448.n2);
      local_8 = 5;
      (**(code **)(**(int **)((int)local_1410 + 0x6c) + 0x7c))();
      pOVar10 = pOVar11;
      if (local_1448.n2.vt == 0) {
LAB_454158a9:
        pOVar10 = local_13fc;
        if (local_13f4 == (BSTR)*local_1414) {
          local_1408 = local_13fc;
          VariantClear((VARIANTARG *)&local_1448.n2);
          break;
        }
        pOVar10 = pOVar11;
        if ((((int)local_13f4 < *local_1414) &&
            (iVar8 = FUN_4541d9ab((undefined4 *)pOVar11), pOVar10 = local_13fc,
            local_1408 = local_13fc, (int)local_13f4 <= iVar8)) &&
           (pOVar10 = pOVar11, local_1408 = pOVar11, *local_1414 < iVar8)) {
          pOVar10 = local_13fc;
          local_1408 = local_13fc;
        }
      }
      else {
        CComQIPtr<>(&local_13f8,(undefined4 *)local_1448._8_4_);
        if (local_13f8 == (BSTR)0x0) {
LAB_4541589b:
          local_8 = 5;
          if (local_13f8 != (BSTR)0x0) {
            (**(code **)(*(int *)local_13f8 + 8))();
          }
          goto LAB_454158a9;
        }
        FUN_45429f70((uint *)local_1434,0,0x10);
        VariantInit((VARIANTARG *)&((_union_2683 *)local_1434)->n2);
        local_8 = 7;
        (**(code **)(*(int *)local_13f8 + 0x30))();
        if (local_1434._0_2_ != 0) {
          VariantClear((VARIANTARG *)&((_union_2683 *)local_1434)->n2);
          goto LAB_4541589b;
        }
        VariantClear((VARIANTARG *)&((_union_2683 *)local_1434)->n2);
        local_8 = 5;
        if (local_13f8 != (BSTR)0x0) {
          (**(code **)(*(int *)local_13f8 + 8))();
        }
      }
      local_8 = 0;
      VariantClear((VARIANTARG *)&local_1448.n2);
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)*param_2);
  }
LAB_45415923:
  local_1404 = (BSTR)0x0;
  local_8 = 8;
  uVar2 = local_8;
  local_8 = 8;
  if (pOVar10 == (BSTR)0x0) {
    local_13ed = 0;
    local_8 = uVar2;
  }
  else {
    piVar5 = FUN_4541d03c(pOVar10,&local_1424);
    FUN_454066f3(&local_1404,piVar5);
    SysFreeString(local_1424);
    local_13fc = (BSTR)0x0;
    local_1424 = (BSTR)FUN_4541d9ab((undefined4 *)pOVar10);
    pvVar1 = local_141c;
    FUN_4541c774(local_141c,&local_13f8);
    piVar5 = *(int **)((int)pvVar1 + 4);
    local_8 = 9;
    local_1480 = piVar5;
    local_145c = piVar5;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))();
    }
    local_13f4 = (BSTR)0x0;
    _local_8 = CONCAT31(uStack_7,0xb);
    (**(code **)(*piVar5 + 0x68))();
    bVar3 = FUN_45402d1b(&local_13f4,(BSTR)"DateText");
    if ((bVar3) || (bVar3 = FUN_45402d1b(&local_13f4,(BSTR)"TimeText"), bVar3)) {
      piVar6 = FUN_4541c943(local_141c,(int *)&local_1400,(int *)0x1);
      piVar6 = (int *)*piVar6;
      local_1454 = piVar6;
      if (piVar6 != (int *)0x0) {
        (**(code **)(*piVar6 + 4))();
      }
      local_8 = 0xc;
      if (local_1400 != (BSTR)0x0) {
        (**(code **)(*(int *)local_1400 + 8))();
      }
      local_1418 = (wchar_t *)0x0;
      local_8 = 0xd;
      (**(code **)(*piVar6 + 0x80))();
      FUN_4540637b(&(((_union_2683 *)local_1434)->n2).n3);
      basic_string<>(auStack_1500,local_1418);
      FUN_4540ee71(local_13ec,(DOUBLE)CONCAT44(local_1434._12_4_,local_1434._8_4_));
      local_1400 = (BSTR)0x0;
      _local_8 = CONCAT31(uStack_7,0xf);
      local_1420 = FUN_4541100c(local_13ec,(int *)&local_13f8,0);
      if (local_1420 != (BSTR)0x0) {
        SysFreeString((BSTR)0x0);
        local_1400 = local_1420;
      }
      FUN_45404d15(&local_13f8,(int *)&local_1400);
      SysFreeString(local_1400);
      local_8 = 0xd;
      FUN_4540efc0(local_13ec);
      SysFreeString(local_1418);
      _local_8 = CONCAT31(uStack_7,0xb);
      (**(code **)(*piVar6 + 8))();
      pOVar10 = local_1408;
    }
    bVar3 = FUN_4541e8f1(pOVar10);
    if (bVar3) {
      FUN_45415453(pOVar10,&local_13f8,(LONG)local_1424,local_1414,(LONG *)&local_13fc);
LAB_45415d3e:
      iVar8 = FUN_4541d9ab((undefined4 *)pOVar10);
      piVar5 = local_1414;
      *local_1414 = iVar8;
      FUN_45421dd2(local_1410,iVar8,'\0',(void *)0x1);
      *piVar5 = extraout_EAX;
      (**(code **)(**(int **)((int)local_141c + 4) + 0x84))();
      uStack_14f8 = 0x45415d86;
      FUN_45421dd2(local_1410,(int)local_13fc,'\x01',(void *)0x1);
      pvVar1 = local_141c;
      local_13fc = extraout_EAX_00;
      (**(code **)(**(int **)((int)local_141c + 4) + 0x7c))();
      FUN_454214b0(pvVar1,pOVar10,local_1424);
      bVar9 = 1;
    }
    else {
      bVar3 = FUN_45402d4b(&local_1404,L"ZFBF");
      if (!bVar3) {
        if (*(int *)((int)local_1410 + 0xdc) != 0) {
          local_13ed = FUN_4541d38b((int)local_141c);
          local_1409 = FUN_4541cb1d((int)local_141c);
          FUN_4541db3e(pOVar10,&local_1400);
          _local_8 = CONCAT31(uStack_7,0x14);
          if (local_13ed != 0) {
            piVar5 = FUN_4541dad8(pOVar10,&local_1420);
            FUN_454066f3(&local_1400,piVar5);
            SysFreeString(local_1420);
          }
          iVar8 = FUN_45414de7((int *)pOVar10);
          if (iVar8 == 1) {
            uVar7 = (uint)local_13ed;
            pOVar11 = extraout_ECX;
            FUN_4540288a(&stack0xffffeb18,(int *)&local_13f8);
            local_13fc = (BSTR)FUN_4541c617(pOVar10,pOVar11,uVar7);
          }
          else {
            uStack_14f8 = 0x45415e0a;
            iVar8 = (**(code **)(**(int **)((int)local_1410 + 0xdc) + 0x20))();
            if (iVar8 < 0) {
              SysFreeString(local_1400);
              goto LAB_45415dac;
            }
          }
          _local_8 = CONCAT31(uStack_7,0xb);
          SysFreeString(local_1400);
        }
        goto LAB_45415d3e;
      }
      FUN_4540e34a(&local_14c8);
      local_146c.n2.vt = 9;
      local_8 = 0x10;
      local_146c._8_4_ = piVar5;
      (**(code **)(*piVar5 + 4))();
      pvVar1 = local_1410;
      local_8 = 0x11;
      local_147c.n1.n2.vt = 9;
      piStack_14c0 = *(int **)((int)local_1410 + 0x38);
      local_147c.n1._8_4_ = piStack_14c0;
      if (piStack_14c0 != (int *)0x0) {
        piStack_14c4 = (int *)0x45415b83;
        (**(code **)(*piStack_14c0 + 4))();
      }
      piStack_14c0 = *(int **)((int)pvVar1 + 0x34);
      local_8 = 0x12;
      local_1434._0_2_ = 9;
      local_1434._8_4_ = piStack_14c0;
      if (piStack_14c0 != (int *)0x0) {
        piStack_14c4 = (int *)0x45415ba1;
        (**(code **)(*piStack_14c0 + 4))();
      }
      local_8 = 0x13;
      local_14c8 = local_1434._4_4_;
      piStack_14c4 = (int *)local_1434._8_4_;
      piStack_14c0 = (int *)local_1434._12_4_;
      iVar8 = FUN_4540e43b(&local_14c8,&local_1458,local_146c._0_4_,local_146c.decVal.Hi32,
                           (undefined4 *)local_146c._8_4_);
      if (-1 < iVar8) {
        local_13fc = local_1458;
        *local_1414 = (int)local_1454;
        VariantClear((VARIANTARG *)&((_union_2683 *)local_1434)->n2);
        VariantClear(&local_147c);
        VariantClear((VARIANTARG *)&local_146c.n2);
        _local_8 = CONCAT31(uStack_7,0xb);
        FUN_4540e3e0(&local_14c8);
        pOVar10 = local_1408;
        goto LAB_45415d3e;
      }
      VariantClear((VARIANTARG *)&((_union_2683 *)local_1434)->n2);
      VariantClear(&local_147c);
      VariantClear((VARIANTARG *)&local_146c.n2);
      _local_8 = CONCAT31(uStack_7,0xb);
      FUN_4540e3e0(&local_14c8);
    }
LAB_45415dac:
    SysFreeString(local_13f4);
    local_8 = 9;
    (**(code **)(*local_145c + 8))();
    SysFreeString(local_13f8);
    local_13ed = bVar9;
  }
  SysFreeString(local_1404);
  SysFreeString(local_1450);
LAB_45415e3f:
  ExceptionList = local_10;
  FUN_4542a8d1(local_14 ^ (uint)&stack0xfffffffc);
  return;
}


