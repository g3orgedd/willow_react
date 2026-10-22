// Source: CLCiffConversion_Layout.dll @ 454161c3; FUN_454161c3

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_454161c3(void *this,int *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  uint *puVar6;
  float10 fVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  uint *puVar12;
  undefined4 *puVar13;
  BSTR pOVar14;
  int iVar15;
  BSTR pOVar16;
  VARIANTARG local_ac;
  int local_9c;
  int local_98;
  int local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  BSTR local_80;
  BSTR local_7c;
  int local_78;
  int local_74;
  int *local_70;
  int local_6c;
  int *local_68;
  void *local_64;
  int *local_60;
  int *local_5c;
  int *local_58;
  int local_54;
  wchar_t *local_50;
  int *local_4c;
  int local_48;
  int local_44;
  char local_3d;
  int local_3c [4];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xac;
  local_8 = 0x454161d2;
  local_68 = param_1;
  local_64 = this;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCIFFAddTabFields::Convert");
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  FUN_4541f8b2(param_1);
  if (*(int **)((int)this + 0x6c) != (int *)0x0) {
    local_80 = (BSTR)0x0;
    local_8._0_1_ = 1;
    (**(code **)(**(int **)((int)this + 0x6c) + 0x44))();
    bVar2 = FUN_45402d4b(&local_80,L"Line");
    if (bVar2) {
      (**(code **)(**(int **)((int)this + 0x34) + 0x54))();
      local_78 = 0;
      iVar3 = (**(code **)(*(int *)*param_1 + 0x1c))();
      if (-1 < iVar3) {
        local_44 = 0;
        local_54 = 0;
        local_7c = (BSTR)0x0;
        pOVar14 = (BSTR)0x45416270;
        (**(code **)(**(int **)((int)this + 0x6c) + 0x34))();
        iVar3 = local_54;
        if (local_9c == 0) {
          fVar7 = FUN_45406d26((int)this);
          local_5c = (int *)(float)fVar7;
          local_54 = (int)((float)iVar3 / (float)local_5c + DAT_45447488);
          param_1 = local_68;
        }
        pOVar16 = 
        L"䖋薤痀뼇䀅耀䷫줳趉ｰ\xffff趉ｴ\xffff趉ｸ\xffff䗆ϼ趉ｼ\xffff䶉㦘豍噿\xec83贌炅\xffff诿僌רￄ囿쮋맨\x94贀炍\xffff\xe8ff셼"
        ;
        FUN_4541ce57(this,(int *)&local_60);
        if (local_60 != (int *)0x0) {
          local_94 = 0;
          local_90 = 0;
          local_8c = 0;
          local_8._0_1_ = 3;
          local_88 = 0;
          local_6c = 0;
          if (0 < local_78) {
            do {
              FUN_45429f70((uint *)&local_ac,0,0x10);
              VariantInit(&local_ac);
              local_6c = local_6c + 1;
              local_8._0_1_ = 4;
              iVar3 = (**(code **)(*(int *)*param_1 + 0x24))();
              if (iVar3 < 0) {
LAB_45416619:
                VariantClear(&local_ac);
                goto LAB_454162fc;
              }
              CComQIPtr<>(&local_58,(undefined4 *)local_ac.n1._8_4_);
              piVar1 = local_58;
              local_8._0_1_ = 5;
              local_70 = local_58;
              local_5c = local_58;
              if (local_58 != (int *)0x0) {
                (**(code **)(*local_58 + 4))();
              }
              local_8._0_1_ = 6;
              piVar4 = piVar1;
              if (piVar1 != (int *)0x0) {
                (**(code **)(*piVar1 + 4))();
              }
              piVar4 = (int *)FUN_4541cc0e(local_3c,piVar4);
              iVar3 = *piVar4;
              pOVar16 = (BSTR)piVar4[1];
              iVar10 = piVar4[2];
              piVar4 = (int *)piVar4[3];
              local_50 = (wchar_t *)0x0;
              local_8._0_1_ = 7;
              (**(code **)(*piVar1 + 0x1c))();
              FUN_45402ac2(&local_98,local_50);
              pOVar14 = local_7c;
              local_8._0_1_ = 8;
              FUN_4540303d(0x4544a004);
              local_8._0_1_ = 7;
              FUN_45402c5d(&local_98);
              if ((int)pOVar14 < (int)pOVar16) {
                local_44 = 0;
                pOVar14 = pOVar16;
                local_7c = pOVar16;
              }
              local_48 = 0;
              local_4c = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
              param_1 = local_68;
              local_8._0_1_ = 9;
              local_3d = '\x01';
              local_74 = FUN_4541a37f(local_68,local_44,(int)pOVar14,&local_3d,&local_4c);
              piVar8 = local_4c;
              if (local_74 < 0) {
                FUN_454224ff((int *)&local_4c);
                FID_conflict__free(local_4c);
                SysFreeString(local_50);
                local_8._0_1_ = 5;
                if (piVar1 != (int *)0x0) {
                  (**(code **)(*piVar1 + 8))();
                }
                local_8._0_1_ = 4;
                if (local_58 != (int *)0x0) {
                  (**(code **)(*local_58 + 8))();
                }
                goto LAB_45416619;
              }
              if ((local_48 == 0) || (local_3d == '\0')) {
                local_44 = iVar10;
                FUN_4542278f(&local_94,&local_5c);
                FUN_454224ff((int *)&local_4c);
                FID_conflict__free(local_4c);
                SysFreeString(local_50);
                local_8._0_1_ = 5;
                if (local_5c != (int *)0x0) {
                  (**(code **)(*local_5c + 8))();
                }
                local_8._0_1_ = 4;
                if (local_58 != (int *)0x0) {
                  (**(code **)(*local_58 + 8))();
                }
                local_8._0_1_ = 3;
                pOVar16 = L"䖋㮘豅谏ﵟ\xffff嶋\xe9a0ﴃ\xffff䶍\xe8b8뼗";
                VariantClear(&local_ac);
              }
              else {
                puVar12 = (uint *)0x0;
                pOVar14 = local_7c;
                piVar11 = local_60;
                iVar15 = local_44;
                for (piVar9 = (int *)*local_4c; local_7c = pOVar14, local_60 = piVar11,
                    local_44 = iVar15, piVar9 != piVar8; piVar9 = (int *)*piVar9) {
                  local_84 = 0;
                  local_74 = (**(code **)(*(int *)piVar9[2] + 0x2c))();
                  puVar5 = (uint *)(local_84 - local_44);
                  puVar6 = puVar5;
                  if ((puVar12 != (uint *)0x0) && (puVar6 = puVar12, (int)puVar5 < (int)puVar12)) {
                    puVar6 = puVar5;
                  }
                  puVar12 = puVar6;
                  pOVar14 = local_7c;
                  piVar11 = local_60;
                  piVar1 = local_70;
                  iVar15 = local_44;
                }
                puVar13 = &local_88;
                if (piVar11 != (int *)0x0) {
                  (**(code **)(*piVar11 + 4))(piVar11);
                }
                piVar8 = piVar1;
                piVar9 = piVar1;
                (**(code **)(*piVar1 + 4))();
                param_1 = local_68;
                FUN_454140ab(local_64,local_68,&local_94,piVar8,piVar9,iVar3,pOVar16,iVar10,piVar4,
                             (int)piVar11,puVar12,puVar13,iVar15,(int)pOVar14);
                FUN_454224ff((int *)&local_4c);
                FID_conflict__free(local_4c);
                SysFreeString(local_50);
                local_8._0_1_ = 5;
                pOVar14 = 
                L"䖋욬ﱅ蔄瓀謆倈凿贈墅\xffff웿ﱅ倃ᗿ版䕄綋\xeb90譥傅\xffff跿炍\xffff觿쁅䖍储შÂ贀롍磨¿＀롵⃨ĳ夀痿ﾴ尕䑲譅ꡅ䗆׼삅ٴࢋｐࡑ䖋욬ﱅ蔄瓀謆倈凿贈墅\xffff웿ﱅ倃ᗿ版䕄䖋㮘豅谏ﵟ\xffff嶋\xe9a0ﴃ\xffff䶍\xe8b8뼗"
                ;
                (**(code **)(*piVar1 + 8))();
                local_8._0_1_ = 4;
                if (local_58 != (int *)0x0) {
                  (**(code **)(*local_58 + 8))();
                }
                local_8._0_1_ = 3;
                pOVar16 = 
                L"綋\xeb90譥傅\xffff跿炍\xffff觿쁅䖍储შÂ贀롍磨¿＀롵⃨ĳ夀痿ﾴ尕䑲譅ꡅ䗆׼삅ٴࢋｐࡑ䖋욬ﱅ蔄瓀謆倈凿贈墅\xffff웿ﱅ倃ᗿ版䕄䖋㮘豅谏ﵟ\xffff嶋\xe9a0ﴃ\xffff䶍\xe8b8뼗"
                ;
                VariantClear(&local_ac);
              }
              this = local_64;
            } while (local_6c < local_78);
          }
          FUN_454126f9(&stack0xffffff28,&local_94);
          FUN_4541f7b5(this,param_1,pOVar14,pOVar16);
LAB_454162fc:
          FUN_45422483(&local_94);
        }
        local_8._0_1_ = 1;
        if (local_60 != (int *)0x0) {
          (**(code **)(*local_60 + 8))();
        }
      }
    }
    SysFreeString(local_80);
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_4542a957();
  return;
}


