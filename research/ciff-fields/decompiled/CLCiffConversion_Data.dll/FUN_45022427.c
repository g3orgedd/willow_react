// Source: CLCiffConversion_Data.dll @ 45022427; FUN_45022427

undefined1 (*) [16] __cdecl FUN_45022427(undefined1 (*param_1) [16],undefined1 (*param_2) [16])

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  undefined1 (*pauVar5) [16];
  undefined1 (*pauVar6) [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar11 [14];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  short sVar14;
  short sVar15;
  int local_14;
  
  uVar1 = *(ushort *)*param_2;
  if (uVar1 != 0) {
    if (1 < DAT_45055388) {
      if (((uint)param_2 & 0xfff) < 0xff1) {
        auVar7 = *param_2;
      }
      else {
        iVar4 = 8;
        pauVar5 = param_2;
        auVar8 = (undefined1  [16])0x0;
        uVar3 = uVar1;
        do {
          auVar7._0_8_ = auVar8._2_8_;
          auVar7._8_8_ = auVar8._8_8_ >> 0x10 | (ulonglong)uVar3 << 0x30;
          if (uVar3 != 0) {
            pauVar5 = (undefined1 (*) [16])(*pauVar5 + 2);
            uVar3 = *(ushort *)*pauVar5;
          }
          iVar4 = iVar4 + -1;
          auVar8 = auVar7;
        } while (iVar4 != 0);
      }
LAB_450224aa:
      while( true ) {
        while( true ) {
          uVar2 = (uint)param_1 & 0xfff;
          pauVar5 = param_2;
          if (uVar2 < 0xff1) break;
          if (*(ushort *)*param_1 == 0) goto LAB_450226af;
          pauVar6 = param_1;
          if (*(ushort *)*param_1 == uVar1) goto LAB_450224e0;
          param_1 = (undefined1 (*) [16])(*param_1 + 2);
        }
        pcmpistri(auVar7,*param_1,0xd);
        if (uVar2 < 0xff1) break;
        param_1 = param_1 + 1;
      }
      if (uVar2 < 0xff0) {
        iVar4 = pcmpistri(auVar7,*param_1,0xd);
        param_1 = (undefined1 (*) [16])(*param_1 + iVar4 * 2);
        pauVar6 = param_1;
LAB_450224e0:
        do {
          for (; 0xff0 < ((uint)param_1 & 0xfff); param_1 = (undefined1 (*) [16])(*param_1 + 2)) {
LAB_45022536:
            if (*(short *)*pauVar5 == 0) {
              return pauVar6;
            }
            if (*(short *)*param_1 != *(short *)*pauVar5) goto LAB_4502254e;
            pauVar5 = (undefined1 (*) [16])(*pauVar5 + 2);
          }
          uVar2 = (uint)pauVar5 & 0xfff;
          if (0xff0 < uVar2) goto LAB_45022536;
          pcmpistri(*pauVar5,*param_1,0xd);
          if (!SBORROW4(uVar2,0xff0)) goto LAB_4502254e;
          if ((int)(uVar2 - 0xff0) < 0) {
            return pauVar6;
          }
          param_1 = param_1 + 1;
          pauVar5 = pauVar5 + 1;
        } while( true );
      }
      goto LAB_450226af;
    }
    if (DAT_45055388 == 1) {
      auVar8 = pshuflw(ZEXT216(uVar1),ZEXT216(uVar1),0);
LAB_4502257d:
      for (; ((uint)param_1 & 0xfff) < 0xff1; param_1 = param_1 + 1) {
        auVar11 = SUB1614((undefined1  [16])0x0,2);
        auVar9._0_2_ = -(ushort)(*(short *)*param_1 == 0);
        auVar9._2_2_ = -(ushort)(*(short *)(*param_1 + 2) == 0);
        auVar9._4_2_ = -(ushort)(*(short *)(*param_1 + 4) == 0);
        auVar9._6_2_ = -(ushort)(*(short *)(*param_1 + 6) == 0);
        auVar9._8_2_ = -(ushort)(*(short *)(*param_1 + 8) == 0);
        auVar9._10_2_ = -(ushort)(auVar11._8_2_ == *(short *)(*param_1 + 10));
        auVar9._12_2_ = -(ushort)(auVar11._10_2_ == *(short *)(*param_1 + 0xc));
        auVar9._14_2_ = -(ushort)(auVar11._12_2_ == *(short *)(*param_1 + 0xe));
        sVar14 = auVar8._0_2_;
        auVar12._0_2_ = -(ushort)(*(short *)*param_1 == sVar14);
        sVar15 = auVar8._2_2_;
        auVar12._2_2_ = -(ushort)(*(short *)(*param_1 + 2) == sVar15);
        auVar12._4_2_ = -(ushort)(*(short *)(*param_1 + 4) == sVar14);
        auVar12._6_2_ = -(ushort)(*(short *)(*param_1 + 6) == sVar15);
        auVar12._8_2_ = -(ushort)(*(short *)(*param_1 + 8) == sVar14);
        auVar12._10_2_ = -(ushort)(*(short *)(*param_1 + 10) == sVar15);
        auVar12._12_2_ = -(ushort)(*(short *)(*param_1 + 0xc) == sVar14);
        auVar12._14_2_ = -(ushort)(*(short *)(*param_1 + 0xe) == sVar15);
        auVar9 = auVar9 | auVar12;
        uVar1 = (ushort)(SUB161(auVar9 >> 7,0) & 1) | (ushort)(SUB161(auVar9 >> 0xf,0) & 1) << 1 |
                (ushort)(SUB161(auVar9 >> 0x17,0) & 1) << 2 |
                (ushort)(SUB161(auVar9 >> 0x1f,0) & 1) << 3 |
                (ushort)(SUB161(auVar9 >> 0x27,0) & 1) << 4 |
                (ushort)(SUB161(auVar9 >> 0x2f,0) & 1) << 5 |
                (ushort)(SUB161(auVar9 >> 0x37,0) & 1) << 6 |
                (ushort)(SUB161(auVar9 >> 0x3f,0) & 1) << 7 |
                (ushort)(SUB161(auVar9 >> 0x47,0) & 1) << 8 |
                (ushort)(SUB161(auVar9 >> 0x4f,0) & 1) << 9 |
                (ushort)(SUB161(auVar9 >> 0x57,0) & 1) << 10 |
                (ushort)(SUB161(auVar9 >> 0x5f,0) & 1) << 0xb |
                (ushort)(SUB161(auVar9 >> 0x67,0) & 1) << 0xc |
                (ushort)(SUB161(auVar9 >> 0x6f,0) & 1) << 0xd |
                (ushort)(SUB161(auVar9 >> 0x77,0) & 1) << 0xe |
                (ushort)(byte)(auVar9[0xf] >> 7) << 0xf;
        if (uVar1 != 0) {
          uVar2 = 0;
          if (uVar1 != 0) {
            for (; (uVar1 >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {
            }
          }
          param_1 = (undefined1 (*) [16])(*param_1 + (uVar2 & 0xfffffffe));
          break;
        }
      }
      if (*(short *)*param_1 != 0) {
        pauVar5 = param_1;
        pauVar6 = param_2;
        if (*(short *)*param_2 == *(short *)*param_1) {
LAB_450225cf:
          for (; (((uint)pauVar6 & 0xfff) < 0xff1 && (((uint)pauVar5 & 0xfff) < 0xff1));
              pauVar5 = pauVar5 + 1) {
            auVar11 = SUB1614((undefined1  [16])0x0,2);
            auVar10._0_2_ = -(ushort)(*(short *)*pauVar6 == 0);
            auVar10._2_2_ = -(ushort)(*(short *)(*pauVar6 + 2) == 0);
            auVar10._4_2_ = -(ushort)(*(short *)(*pauVar6 + 4) == 0);
            auVar10._6_2_ = -(ushort)(*(short *)(*pauVar6 + 6) == 0);
            auVar10._8_2_ = -(ushort)(*(short *)(*pauVar6 + 8) == 0);
            auVar10._10_2_ = -(ushort)(auVar11._8_2_ == *(short *)(*pauVar6 + 10));
            auVar10._12_2_ = -(ushort)(auVar11._10_2_ == *(short *)(*pauVar6 + 0xc));
            auVar10._14_2_ = -(ushort)(auVar11._12_2_ == *(short *)(*pauVar6 + 0xe));
            auVar13._0_2_ = -(ushort)(*(short *)*pauVar5 != *(short *)*pauVar6);
            auVar13._2_2_ = -(ushort)(*(short *)(*pauVar5 + 2) != *(short *)(*pauVar6 + 2));
            auVar13._4_2_ = -(ushort)(*(short *)(*pauVar5 + 4) != *(short *)(*pauVar6 + 4));
            auVar13._6_2_ = -(ushort)(*(short *)(*pauVar5 + 6) != *(short *)(*pauVar6 + 6));
            auVar13._8_2_ = -(ushort)(*(short *)(*pauVar5 + 8) != *(short *)(*pauVar6 + 8));
            auVar13._10_2_ = -(ushort)(*(short *)(*pauVar5 + 10) != *(short *)(*pauVar6 + 10));
            auVar13._12_2_ = -(ushort)(*(short *)(*pauVar5 + 0xc) != *(short *)(*pauVar6 + 0xc));
            auVar13._14_2_ = -(ushort)(*(short *)(*pauVar5 + 0xe) != *(short *)(*pauVar6 + 0xe));
            auVar13 = auVar13 | auVar10;
            uVar1 = (ushort)(SUB161(auVar13 >> 7,0) & 1) |
                    (ushort)(SUB161(auVar13 >> 0xf,0) & 1) << 1 |
                    (ushort)(SUB161(auVar13 >> 0x17,0) & 1) << 2 |
                    (ushort)(SUB161(auVar13 >> 0x1f,0) & 1) << 3 |
                    (ushort)(SUB161(auVar13 >> 0x27,0) & 1) << 4 |
                    (ushort)(SUB161(auVar13 >> 0x2f,0) & 1) << 5 |
                    (ushort)(SUB161(auVar13 >> 0x37,0) & 1) << 6 |
                    (ushort)(SUB161(auVar13 >> 0x3f,0) & 1) << 7 |
                    (ushort)(SUB161(auVar13 >> 0x47,0) & 1) << 8 |
                    (ushort)(SUB161(auVar13 >> 0x4f,0) & 1) << 9 |
                    (ushort)(SUB161(auVar13 >> 0x57,0) & 1) << 10 |
                    (ushort)(SUB161(auVar13 >> 0x5f,0) & 1) << 0xb |
                    (ushort)(SUB161(auVar13 >> 0x67,0) & 1) << 0xc |
                    (ushort)(SUB161(auVar13 >> 0x6f,0) & 1) << 0xd |
                    (ushort)(SUB161(auVar13 >> 0x77,0) & 1) << 0xe |
                    (ushort)(byte)(auVar13[0xf] >> 7) << 0xf;
            if (uVar1 != 0) {
              uVar2 = 0;
              if (uVar1 != 0) {
                for (; (uVar1 >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {
                }
              }
              pauVar5 = (undefined1 (*) [16])(*pauVar5 + (uVar2 & 0xfffffffe));
              pauVar6 = (undefined1 (*) [16])(*pauVar6 + (uVar2 & 0xfffffffe));
              break;
            }
            pauVar6 = pauVar6 + 1;
          }
          if (*(short *)*pauVar6 == 0) {
            return param_1;
          }
          if (*(short *)*pauVar5 == *(short *)*pauVar6) {
            pauVar5 = (undefined1 (*) [16])(*pauVar5 + 2);
            pauVar6 = (undefined1 (*) [16])(*pauVar6 + 2);
            goto LAB_450225cf;
          }
        }
        param_1 = (undefined1 (*) [16])(*param_1 + 2);
        goto LAB_4502257d;
      }
    }
    else if (*(short *)*param_1 != 0) {
      local_14 = (int)param_1 - (int)param_2;
      pauVar5 = param_2;
      if (*(short *)*param_1 == 0) goto LAB_45022694;
      do {
        do {
          if (*(short *)*pauVar5 == 0) {
            return param_1;
          }
        } while ((*(short *)(*pauVar5 + local_14) == *(short *)*pauVar5) &&
                (pauVar5 = (undefined1 (*) [16])(*pauVar5 + 2), *(short *)(*pauVar5 + local_14) != 0
                ));
LAB_45022694:
        if (*(short *)*pauVar5 == 0) {
          return param_1;
        }
        param_1 = (undefined1 (*) [16])(*param_1 + 2);
        local_14 = local_14 + 2;
        pauVar5 = param_2;
      } while (*(short *)*param_1 != 0);
    }
LAB_450226af:
    param_1 = (undefined1 (*) [16])0x0;
  }
  return param_1;
LAB_4502254e:
  param_1 = (undefined1 (*) [16])(*pauVar6 + 2);
  goto LAB_450224aa;
}


