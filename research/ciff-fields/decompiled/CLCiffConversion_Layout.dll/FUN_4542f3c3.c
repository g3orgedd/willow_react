// Source: CLCiffConversion_Layout.dll @ 4542f3c3; FUN_4542f3c3

/* WARNING: Removing unreachable block (ram,0x4542f3f3) */
/* WARNING: Removing unreachable block (ram,0x4542f4af) */
/* WARNING: Removing unreachable block (ram,0x4542f443) */

undefined4 FUN_4542f3c3(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  DAT_45460b80 = 0;
  DAT_4545da20 = DAT_4545da20 | 1;
  BVar4 = IsProcessorFeaturePresent(10);
  uVar5 = DAT_4545da20;
  if (BVar4 != 0) {
    DAT_45460b80 = 1;
    piVar1 = (int *)cpuid_basic_info(0);
    puVar2 = (uint *)cpuid_Version_info(1);
    uVar6 = puVar2[3];
    if (((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) &&
       (((((uVar5 = *puVar2 & 0xfff3ff0, uVar5 == 0x106c0 || (uVar5 == 0x20660)) ||
          (uVar5 == 0x20670)) || ((uVar5 == 0x30650 || (uVar5 == 0x30660)))) || (uVar5 == 0x30670)))
       ) {
      DAT_45460b84 = DAT_45460b84 | 1;
    }
    if (*piVar1 < 7) {
      uVar7 = 0;
    }
    else {
      iVar3 = cpuid_Extended_Feature_Enumeration_info(7);
      uVar7 = *(uint *)(iVar3 + 4);
      if ((uVar7 & 0x200) != 0) {
        DAT_45460b84 = DAT_45460b84 | 2;
      }
    }
    uVar5 = DAT_4545da20 | 2;
    if ((uVar6 & 0x100000) != 0) {
      DAT_45460b80 = 2;
      uVar5 = DAT_4545da20 | 6;
      if (((uVar6 & 0x8000000) != 0) && ((uVar6 & 0x10000000) != 0)) {
        DAT_45460b80 = 3;
        uVar5 = DAT_4545da20 | 0xe;
        if ((uVar7 & 0x20) != 0) {
          DAT_45460b80 = 5;
          uVar5 = DAT_4545da20 | 0x2e;
        }
      }
    }
  }
  DAT_4545da20 = uVar5;
  return 0;
}


