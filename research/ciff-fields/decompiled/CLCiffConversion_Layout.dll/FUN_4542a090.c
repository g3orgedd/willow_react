// Source: CLCiffConversion_Layout.dll @ 4542a090; FUN_4542a090

/* WARNING: Control flow encountered bad instruction data */

undefined8 * __cdecl FUN_4542a090(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  undefined8 *puVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  undefined8 *puVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  
  if ((param_2 < param_1) && (param_1 < (undefined8 *)(param_3 + (int)param_2))) {
    puVar20 = (undefined4 *)((param_3 - 4) + (int)param_2);
    puVar21 = (undefined4 *)((param_3 - 4) + (int)param_1);
    if (((uint)puVar21 & 3) == 0) {
      uVar16 = param_3 >> 2;
      uVar17 = param_3 & 3;
      if (7 < uVar16) {
        for (; uVar16 != 0; uVar16 = uVar16 - 1) {
          *puVar21 = *puVar20;
          puVar20 = puVar20 + -1;
          puVar21 = puVar21 + -1;
        }
        switch(uVar17) {
        case 0:
          return param_1;
        case 2:
          goto switchD_4542a437_caseD_2;
        case 3:
          goto switchD_4542a437_caseD_3;
        }
        goto switchD_4542a437_caseD_1;
      }
    }
    else {
      switch(param_3) {
      case 0:
        goto switchD_4542a437_caseD_0;
      case 1:
        goto switchD_4542a437_caseD_1;
      case 2:
        goto switchD_4542a437_caseD_2;
      case 3:
        goto switchD_4542a437_caseD_3;
      default:
        uVar16 = param_3 - ((uint)puVar21 & 3);
        switch((uint)puVar21 & 3) {
        case 1:
          uVar17 = uVar16 & 3;
          *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
          puVar20 = (undefined4 *)((int)puVar20 + -1);
          uVar16 = uVar16 >> 2;
          puVar21 = (undefined4 *)((int)puVar21 - 1);
          if (7 < uVar16) {
            for (; uVar16 != 0; uVar16 = uVar16 - 1) {
              *puVar21 = *puVar20;
              puVar20 = puVar20 + -1;
              puVar21 = puVar21 + -1;
            }
            switch(uVar17) {
            case 0:
              return param_1;
            case 2:
              goto switchD_4542a437_caseD_2;
            case 3:
              goto switchD_4542a437_caseD_3;
            }
            goto switchD_4542a437_caseD_1;
          }
          break;
        case 2:
          uVar17 = uVar16 & 3;
          *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
          uVar16 = uVar16 >> 2;
          *(undefined1 *)((int)puVar21 + 2) = *(undefined1 *)((int)puVar20 + 2);
          puVar20 = (undefined4 *)((int)puVar20 + -2);
          puVar21 = (undefined4 *)((int)puVar21 - 2);
          if (7 < uVar16) {
            for (; uVar16 != 0; uVar16 = uVar16 - 1) {
              *puVar21 = *puVar20;
              puVar20 = puVar20 + -1;
              puVar21 = puVar21 + -1;
            }
            switch(uVar17) {
            case 0:
              return param_1;
            case 2:
              goto switchD_4542a437_caseD_2;
            case 3:
              goto switchD_4542a437_caseD_3;
            }
            goto switchD_4542a437_caseD_1;
          }
          break;
        case 3:
          uVar17 = uVar16 & 3;
          *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
          *(undefined1 *)((int)puVar21 + 2) = *(undefined1 *)((int)puVar20 + 2);
          uVar16 = uVar16 >> 2;
          *(undefined1 *)((int)puVar21 + 1) = *(undefined1 *)((int)puVar20 + 1);
          puVar20 = (undefined4 *)((int)puVar20 + -3);
          puVar21 = (undefined4 *)((int)puVar21 - 3);
          if (7 < uVar16) {
            for (; uVar16 != 0; uVar16 = uVar16 - 1) {
              *puVar21 = *puVar20;
              puVar20 = puVar20 + -1;
              puVar21 = puVar21 + -1;
            }
            switch(uVar17) {
            case 0:
              return param_1;
            case 2:
              goto switchD_4542a437_caseD_2;
            case 3:
              goto switchD_4542a437_caseD_3;
            }
            goto switchD_4542a437_caseD_1;
          }
        }
      }
    }
    switch(uVar16) {
    case 7:
      puVar21[7 - uVar16] = puVar20[7 - uVar16];
    case 6:
      puVar21[6 - uVar16] = puVar20[6 - uVar16];
    case 5:
      puVar21[5 - uVar16] = puVar20[5 - uVar16];
    case 4:
      puVar21[4 - uVar16] = puVar20[4 - uVar16];
    case 3:
      puVar21[3 - uVar16] = puVar20[3 - uVar16];
    case 2:
      puVar21[2 - uVar16] = puVar20[2 - uVar16];
    case 1:
      puVar21[1 - uVar16] = puVar20[1 - uVar16];
      puVar20 = puVar20 + -uVar16;
      puVar21 = puVar21 + -uVar16;
    }
    switch(uVar17) {
    case 1:
switchD_4542a437_caseD_1:
      *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
      return param_1;
    case 2:
switchD_4542a437_caseD_2:
      *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
      *(undefined1 *)((int)puVar21 + 2) = *(undefined1 *)((int)puVar20 + 2);
      return param_1;
    case 3:
switchD_4542a437_caseD_3:
      *(undefined1 *)((int)puVar21 + 3) = *(undefined1 *)((int)puVar20 + 3);
      *(undefined1 *)((int)puVar21 + 2) = *(undefined1 *)((int)puVar20 + 2);
      *(undefined1 *)((int)puVar21 + 1) = *(undefined1 *)((int)puVar20 + 1);
      return param_1;
    }
switchD_4542a437_caseD_0:
    return param_1;
  }
  puVar15 = param_1;
  if ((DAT_45460b84 >> 1 & 1) != 0) {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      *(undefined1 *)puVar15 = *(undefined1 *)param_2;
      param_2 = (undefined8 *)((int)param_2 + 1);
      puVar15 = (undefined8 *)((int)puVar15 + 1);
    }
    return param_1;
  }
  if (param_3 < 0x80) {
LAB_4542a29b:
    if (((uint)param_1 & 3) == 0) goto LAB_4542a2a3;
LAB_4542a2b8:
    switch(param_3) {
    case 0:
      goto switchD_4542a2b0_caseD_0;
    case 1:
      goto switchD_4542a2b0_caseD_1;
    case 2:
      goto switchD_4542a2b0_caseD_2;
    case 3:
      goto switchD_4542a2b0_caseD_3;
    default:
      uVar16 = (param_3 - 4) + ((uint)param_1 & 3);
      switch((uint)param_1 & 3) {
      case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      case 1:
        uVar17 = uVar16 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        uVar16 = uVar16 >> 2;
        *(undefined1 *)((int)param_1 + 2) = *(undefined1 *)((int)param_2 + 2);
        param_2 = (undefined8 *)((int)param_2 + 3);
        puVar15 = (undefined8 *)((int)param_1 + 3);
        if (7 < uVar16) {
          for (; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)puVar15 = *(undefined4 *)param_2;
            param_2 = (undefined8 *)((int)param_2 + 4);
            puVar15 = (undefined8 *)((int)puVar15 + 4);
          }
          switch(uVar17) {
          case 0:
            return param_1;
          case 2:
            goto switchD_4542a2b0_caseD_2;
          case 3:
            goto switchD_4542a2b0_caseD_3;
          }
          goto switchD_4542a2b0_caseD_1;
        }
        break;
      case 2:
        uVar17 = uVar16 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        uVar16 = uVar16 >> 2;
        *(undefined1 *)((int)param_1 + 1) = *(undefined1 *)((int)param_2 + 1);
        param_2 = (undefined8 *)((int)param_2 + 2);
        puVar15 = (undefined8 *)((int)param_1 + 2);
        if (7 < uVar16) {
          for (; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)puVar15 = *(undefined4 *)param_2;
            param_2 = (undefined8 *)((int)param_2 + 4);
            puVar15 = (undefined8 *)((int)puVar15 + 4);
          }
          switch(uVar17) {
          case 0:
            return param_1;
          case 2:
            goto switchD_4542a2b0_caseD_2;
          case 3:
            goto switchD_4542a2b0_caseD_3;
          }
          goto switchD_4542a2b0_caseD_1;
        }
        break;
      case 3:
        uVar17 = uVar16 & 3;
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined8 *)((int)param_2 + 1);
        uVar16 = uVar16 >> 2;
        puVar15 = (undefined8 *)((int)param_1 + 1);
        if (7 < uVar16) {
          for (; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)puVar15 = *(undefined4 *)param_2;
            param_2 = (undefined8 *)((int)param_2 + 4);
            puVar15 = (undefined8 *)((int)puVar15 + 4);
          }
          switch(uVar17) {
          case 0:
            return param_1;
          case 2:
            goto switchD_4542a2b0_caseD_2;
          case 3:
            goto switchD_4542a2b0_caseD_3;
          }
          goto switchD_4542a2b0_caseD_1;
        }
      }
    }
  }
  else {
    if (((((uint)param_1 ^ (uint)param_2) & 0xf) == 0) && ((DAT_4545da20 >> 1 & 1) != 0)) {
      if (((uint)param_2 & 0xf) != 0) {
        uVar17 = 0x10 - ((uint)param_2 & 0xf);
        param_3 = param_3 - uVar17;
        for (uVar16 = uVar17 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
          *(undefined1 *)puVar15 = *(undefined1 *)param_2;
          param_2 = (undefined8 *)((int)param_2 + 1);
          puVar15 = (undefined8 *)((int)puVar15 + 1);
        }
        for (uVar17 = uVar17 >> 2; uVar17 != 0; uVar17 = uVar17 - 1) {
          *(undefined4 *)puVar15 = *(undefined4 *)param_2;
          param_2 = (undefined8 *)((int)param_2 + 4);
          puVar15 = (undefined8 *)((int)puVar15 + 4);
        }
      }
      for (uVar16 = param_3 >> 7; uVar16 != 0; uVar16 = uVar16 - 1) {
        uVar22 = *(undefined4 *)((int)param_2 + 4);
        uVar23 = *(undefined4 *)(param_2 + 1);
        uVar24 = *(undefined4 *)((int)param_2 + 0xc);
        uVar2 = *(undefined4 *)(param_2 + 2);
        uVar3 = *(undefined4 *)((int)param_2 + 0x14);
        uVar4 = *(undefined4 *)(param_2 + 3);
        uVar5 = *(undefined4 *)((int)param_2 + 0x1c);
        uVar6 = *(undefined4 *)(param_2 + 4);
        uVar7 = *(undefined4 *)((int)param_2 + 0x24);
        uVar8 = *(undefined4 *)(param_2 + 5);
        uVar9 = *(undefined4 *)((int)param_2 + 0x2c);
        uVar10 = *(undefined4 *)(param_2 + 6);
        uVar11 = *(undefined4 *)((int)param_2 + 0x34);
        uVar12 = *(undefined4 *)(param_2 + 7);
        uVar13 = *(undefined4 *)((int)param_2 + 0x3c);
        *(undefined4 *)puVar15 = *(undefined4 *)param_2;
        *(undefined4 *)((int)puVar15 + 4) = uVar22;
        *(undefined4 *)(puVar15 + 1) = uVar23;
        *(undefined4 *)((int)puVar15 + 0xc) = uVar24;
        *(undefined4 *)(puVar15 + 2) = uVar2;
        *(undefined4 *)((int)puVar15 + 0x14) = uVar3;
        *(undefined4 *)(puVar15 + 3) = uVar4;
        *(undefined4 *)((int)puVar15 + 0x1c) = uVar5;
        *(undefined4 *)(puVar15 + 4) = uVar6;
        *(undefined4 *)((int)puVar15 + 0x24) = uVar7;
        *(undefined4 *)(puVar15 + 5) = uVar8;
        *(undefined4 *)((int)puVar15 + 0x2c) = uVar9;
        *(undefined4 *)(puVar15 + 6) = uVar10;
        *(undefined4 *)((int)puVar15 + 0x34) = uVar11;
        *(undefined4 *)(puVar15 + 7) = uVar12;
        *(undefined4 *)((int)puVar15 + 0x3c) = uVar13;
        uVar22 = *(undefined4 *)((int)param_2 + 0x44);
        uVar23 = *(undefined4 *)(param_2 + 9);
        uVar24 = *(undefined4 *)((int)param_2 + 0x4c);
        uVar2 = *(undefined4 *)(param_2 + 10);
        uVar3 = *(undefined4 *)((int)param_2 + 0x54);
        uVar4 = *(undefined4 *)(param_2 + 0xb);
        uVar5 = *(undefined4 *)((int)param_2 + 0x5c);
        uVar6 = *(undefined4 *)(param_2 + 0xc);
        uVar7 = *(undefined4 *)((int)param_2 + 100);
        uVar8 = *(undefined4 *)(param_2 + 0xd);
        uVar9 = *(undefined4 *)((int)param_2 + 0x6c);
        uVar10 = *(undefined4 *)(param_2 + 0xe);
        uVar11 = *(undefined4 *)((int)param_2 + 0x74);
        uVar12 = *(undefined4 *)(param_2 + 0xf);
        uVar13 = *(undefined4 *)((int)param_2 + 0x7c);
        *(undefined4 *)(puVar15 + 8) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)((int)puVar15 + 0x44) = uVar22;
        *(undefined4 *)(puVar15 + 9) = uVar23;
        *(undefined4 *)((int)puVar15 + 0x4c) = uVar24;
        *(undefined4 *)(puVar15 + 10) = uVar2;
        *(undefined4 *)((int)puVar15 + 0x54) = uVar3;
        *(undefined4 *)(puVar15 + 0xb) = uVar4;
        *(undefined4 *)((int)puVar15 + 0x5c) = uVar5;
        *(undefined4 *)(puVar15 + 0xc) = uVar6;
        *(undefined4 *)((int)puVar15 + 100) = uVar7;
        *(undefined4 *)(puVar15 + 0xd) = uVar8;
        *(undefined4 *)((int)puVar15 + 0x6c) = uVar9;
        *(undefined4 *)(puVar15 + 0xe) = uVar10;
        *(undefined4 *)((int)puVar15 + 0x74) = uVar11;
        *(undefined4 *)(puVar15 + 0xf) = uVar12;
        *(undefined4 *)((int)puVar15 + 0x7c) = uVar13;
        param_2 = param_2 + 0x10;
        puVar15 = puVar15 + 0x10;
      }
      if ((param_3 & 0x7f) != 0) {
        for (uVar16 = (param_3 & 0x7f) >> 4; uVar16 != 0; uVar16 = uVar16 - 1) {
          uVar22 = *(undefined4 *)((int)param_2 + 4);
          uVar23 = *(undefined4 *)(param_2 + 1);
          uVar24 = *(undefined4 *)((int)param_2 + 0xc);
          *(undefined4 *)puVar15 = *(undefined4 *)param_2;
          *(undefined4 *)((int)puVar15 + 4) = uVar22;
          *(undefined4 *)(puVar15 + 1) = uVar23;
          *(undefined4 *)((int)puVar15 + 0xc) = uVar24;
          param_2 = param_2 + 2;
          puVar15 = puVar15 + 2;
        }
        if ((param_3 & 0xf) != 0) {
          for (uVar16 = (param_3 & 0xf) >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined4 *)puVar15 = *(undefined4 *)param_2;
            param_2 = (undefined8 *)((int)param_2 + 4);
            puVar15 = (undefined8 *)((int)puVar15 + 4);
          }
          for (uVar16 = param_3 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
            *(undefined1 *)puVar15 = *(undefined1 *)param_2;
            param_2 = (undefined8 *)((int)param_2 + 1);
            puVar15 = (undefined8 *)((int)puVar15 + 1);
          }
        }
      }
      return param_1;
    }
    if ((DAT_45460b84 & 1) == 0) goto LAB_4542a29b;
    if (((uint)param_1 & 3) != 0) goto LAB_4542a2b8;
    if (((uint)param_2 & 3) == 0) {
      if (((uint)param_1 >> 2 & 1) != 0) {
        uVar22 = *(undefined4 *)param_2;
        param_3 = param_3 - 4;
        param_2 = (undefined8 *)((int)param_2 + 4);
        *(undefined4 *)param_1 = uVar22;
        param_1 = (undefined8 *)((int)param_1 + 4);
      }
      if (((uint)param_1 >> 3 & 1) != 0) {
        uVar1 = *param_2;
        param_3 = param_3 - 8;
        param_2 = param_2 + 1;
        *param_1 = uVar1;
        param_1 = param_1 + 1;
      }
      if (((uint)param_2 & 7) == 0) {
        puVar15 = param_2 + -1;
        uVar22 = *(undefined4 *)param_2;
        uVar23 = *(undefined4 *)((int)param_2 + 4);
        do {
          puVar19 = puVar15;
          uVar3 = *(undefined4 *)(puVar19 + 2);
          uVar4 = *(undefined4 *)((int)puVar19 + 0x14);
          param_3 = param_3 - 0x30;
          uVar5 = *(undefined4 *)(puVar19 + 3);
          uVar6 = *(undefined4 *)((int)puVar19 + 0x1c);
          uVar7 = *(undefined4 *)(puVar19 + 4);
          uVar8 = *(undefined4 *)((int)puVar19 + 0x24);
          uVar24 = *(undefined4 *)(puVar19 + 7);
          uVar2 = *(undefined4 *)((int)puVar19 + 0x3c);
          uVar9 = *(undefined4 *)(puVar19 + 5);
          uVar10 = *(undefined4 *)((int)puVar19 + 0x2c);
          uVar11 = *(undefined4 *)(puVar19 + 6);
          uVar12 = *(undefined4 *)((int)puVar19 + 0x34);
          *(undefined4 *)param_1 = uVar22;
          *(undefined4 *)((int)param_1 + 4) = uVar23;
          *(undefined4 *)(param_1 + 1) = uVar3;
          *(undefined4 *)((int)param_1 + 0xc) = uVar4;
          *(undefined4 *)(param_1 + 2) = uVar5;
          *(undefined4 *)((int)param_1 + 0x14) = uVar6;
          *(undefined4 *)(param_1 + 3) = uVar7;
          *(undefined4 *)((int)param_1 + 0x1c) = uVar8;
          *(undefined4 *)(param_1 + 4) = uVar9;
          *(undefined4 *)((int)param_1 + 0x24) = uVar10;
          *(undefined4 *)(param_1 + 5) = uVar11;
          *(undefined4 *)((int)param_1 + 0x2c) = uVar12;
          param_1 = param_1 + 6;
          puVar15 = puVar19 + 6;
          uVar22 = uVar24;
          uVar23 = uVar2;
        } while (0x2f < (int)param_3);
        puVar19 = puVar19 + 7;
      }
      else if (((uint)param_2 >> 3 & 1) == 0) {
        iVar14 = (int)param_2 + -4;
        uVar22 = *(undefined4 *)param_2;
        uVar23 = *(undefined4 *)((int)param_2 + 4);
        uVar24 = *(undefined4 *)(param_2 + 1);
        do {
          iVar18 = iVar14;
          uVar5 = *(undefined4 *)(iVar18 + 0x10);
          param_3 = param_3 - 0x30;
          uVar6 = *(undefined4 *)(iVar18 + 0x14);
          uVar7 = *(undefined4 *)(iVar18 + 0x18);
          uVar8 = *(undefined4 *)(iVar18 + 0x1c);
          uVar9 = *(undefined4 *)(iVar18 + 0x20);
          uVar2 = *(undefined4 *)(iVar18 + 0x34);
          uVar3 = *(undefined4 *)(iVar18 + 0x38);
          uVar4 = *(undefined4 *)(iVar18 + 0x3c);
          uVar10 = *(undefined4 *)(iVar18 + 0x24);
          uVar11 = *(undefined4 *)(iVar18 + 0x28);
          uVar12 = *(undefined4 *)(iVar18 + 0x2c);
          uVar13 = *(undefined4 *)(iVar18 + 0x30);
          *(undefined4 *)param_1 = uVar22;
          *(undefined4 *)((int)param_1 + 4) = uVar23;
          *(undefined4 *)(param_1 + 1) = uVar24;
          *(undefined4 *)((int)param_1 + 0xc) = uVar5;
          *(undefined4 *)(param_1 + 2) = uVar6;
          *(undefined4 *)((int)param_1 + 0x14) = uVar7;
          *(undefined4 *)(param_1 + 3) = uVar8;
          *(undefined4 *)((int)param_1 + 0x1c) = uVar9;
          *(undefined4 *)(param_1 + 4) = uVar10;
          *(undefined4 *)((int)param_1 + 0x24) = uVar11;
          *(undefined4 *)(param_1 + 5) = uVar12;
          *(undefined4 *)((int)param_1 + 0x2c) = uVar13;
          param_1 = param_1 + 6;
          iVar14 = iVar18 + 0x30;
          uVar22 = uVar2;
          uVar23 = uVar3;
          uVar24 = uVar4;
        } while (0x2f < (int)param_3);
        puVar19 = (undefined8 *)(iVar18 + 0x34);
      }
      else {
        iVar14 = (int)param_2 + -0xc;
        uVar22 = *(undefined4 *)param_2;
        do {
          iVar18 = iVar14;
          uVar24 = *(undefined4 *)(iVar18 + 0x10);
          uVar2 = *(undefined4 *)(iVar18 + 0x14);
          uVar3 = *(undefined4 *)(iVar18 + 0x18);
          param_3 = param_3 - 0x30;
          uVar4 = *(undefined4 *)(iVar18 + 0x1c);
          uVar5 = *(undefined4 *)(iVar18 + 0x20);
          uVar6 = *(undefined4 *)(iVar18 + 0x24);
          uVar7 = *(undefined4 *)(iVar18 + 0x28);
          uVar23 = *(undefined4 *)(iVar18 + 0x3c);
          uVar8 = *(undefined4 *)(iVar18 + 0x2c);
          uVar9 = *(undefined4 *)(iVar18 + 0x30);
          uVar10 = *(undefined4 *)(iVar18 + 0x34);
          uVar11 = *(undefined4 *)(iVar18 + 0x38);
          *(undefined4 *)param_1 = uVar22;
          *(undefined4 *)((int)param_1 + 4) = uVar24;
          *(undefined4 *)(param_1 + 1) = uVar2;
          *(undefined4 *)((int)param_1 + 0xc) = uVar3;
          *(undefined4 *)(param_1 + 2) = uVar4;
          *(undefined4 *)((int)param_1 + 0x14) = uVar5;
          *(undefined4 *)(param_1 + 3) = uVar6;
          *(undefined4 *)((int)param_1 + 0x1c) = uVar7;
          *(undefined4 *)(param_1 + 4) = uVar8;
          *(undefined4 *)((int)param_1 + 0x24) = uVar9;
          *(undefined4 *)(param_1 + 5) = uVar10;
          *(undefined4 *)((int)param_1 + 0x2c) = uVar11;
          param_1 = param_1 + 6;
          iVar14 = iVar18 + 0x30;
          uVar22 = uVar23;
        } while (0x2f < (int)param_3);
        puVar19 = (undefined8 *)(iVar18 + 0x3c);
      }
      for (; 0xf < (int)param_3; param_3 = param_3 - 0x10) {
        uVar22 = *(undefined4 *)puVar19;
        uVar23 = *(undefined4 *)((int)puVar19 + 4);
        uVar24 = *(undefined4 *)(puVar19 + 1);
        uVar2 = *(undefined4 *)((int)puVar19 + 0xc);
        puVar19 = puVar19 + 2;
        *(undefined4 *)param_1 = uVar22;
        *(undefined4 *)((int)param_1 + 4) = uVar23;
        *(undefined4 *)(param_1 + 1) = uVar24;
        *(undefined4 *)((int)param_1 + 0xc) = uVar2;
        param_1 = param_1 + 2;
      }
      if ((param_3 >> 2 & 1) != 0) {
        uVar22 = *(undefined4 *)puVar19;
        param_3 = param_3 - 4;
        puVar19 = (undefined8 *)((int)puVar19 + 4);
        *(undefined4 *)param_1 = uVar22;
        param_1 = (undefined8 *)((int)param_1 + 4);
      }
      if ((param_3 >> 3 & 1) != 0) {
        param_3 = param_3 - 8;
        *param_1 = *puVar19;
      }
                    /* WARNING: Could not recover jumptable at 0x4542a299. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar15 = (undefined8 *)(*(code *)(&switchD_4542a2b0::switchdataD_4542a3c8)[param_3])();
      return puVar15;
    }
LAB_4542a2a3:
    uVar16 = param_3 >> 2;
    uVar17 = param_3 & 3;
    if (7 < uVar16) {
      for (; uVar16 != 0; uVar16 = uVar16 - 1) {
        *(undefined4 *)puVar15 = *(undefined4 *)param_2;
        param_2 = (undefined8 *)((int)param_2 + 4);
        puVar15 = (undefined8 *)((int)puVar15 + 4);
      }
      switch(uVar17) {
      case 0:
        return param_1;
      case 2:
        goto switchD_4542a2b0_caseD_2;
      case 3:
        goto switchD_4542a2b0_caseD_3;
      }
      goto switchD_4542a2b0_caseD_1;
    }
  }
  switch(uVar16) {
  case 7:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -0x1c) =
         *(undefined4 *)((int)param_2 + uVar16 * 4 + -0x1c);
  case 6:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -0x18) =
         *(undefined4 *)((int)param_2 + uVar16 * 4 + -0x18);
  case 5:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -0x14) =
         *(undefined4 *)((int)param_2 + uVar16 * 4 + -0x14);
  case 4:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -0x10) =
         *(undefined4 *)((int)param_2 + uVar16 * 4 + -0x10);
  case 3:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -0xc) =
         *(undefined4 *)((int)param_2 + uVar16 * 4 + -0xc);
  case 2:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -8) =
         *(undefined4 *)((int)param_2 + uVar16 * 4 + -8);
  case 1:
    *(undefined4 *)((int)puVar15 + uVar16 * 4 + -4) =
         *(undefined4 *)((int)param_2 + uVar16 * 4 + -4);
    param_2 = (undefined8 *)((int)param_2 + uVar16 * 4);
    puVar15 = (undefined8 *)((int)puVar15 + uVar16 * 4);
  }
  switch(uVar17) {
  case 0:
switchD_4542a2b0_caseD_0:
    return param_1;
  case 2:
switchD_4542a2b0_caseD_2:
    *(undefined1 *)puVar15 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar15 + 1) = *(undefined1 *)((int)param_2 + 1);
    return param_1;
  case 3:
switchD_4542a2b0_caseD_3:
    *(undefined1 *)puVar15 = *(undefined1 *)param_2;
    *(undefined1 *)((int)puVar15 + 1) = *(undefined1 *)((int)param_2 + 1);
    *(undefined1 *)((int)puVar15 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
switchD_4542a2b0_caseD_1:
  *(undefined1 *)puVar15 = *(undefined1 *)param_2;
  return param_1;
}


