// Source: CLCiffConversion_Data.dll @ 45027b53; FUN_45027b53

/* WARNING: Removing unreachable block (ram,0x45027b83) */
/* WARNING: Removing unreachable block (ram,0x45027c3f) */
/* WARNING: Removing unreachable block (ram,0x45027bd3) */

undefined4 FUN_45027b53(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  BOOL BVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  DAT_45055388 = 0;
  DAT_4505205c = DAT_4505205c | 1;
  BVar4 = IsProcessorFeaturePresent(10);
  uVar5 = DAT_4505205c;
  if (BVar4 != 0) {
    DAT_45055388 = 1;
    piVar1 = (int *)cpuid_basic_info(0);
    puVar2 = (uint *)cpuid_Version_info(1);
    uVar6 = puVar2[3];
    if (((piVar1[2] == 0x49656e69 && piVar1[3] == 0x6c65746e) && piVar1[1] == 0x756e6547) &&
       (((((uVar5 = *puVar2 & 0xfff3ff0, uVar5 == 0x106c0 || (uVar5 == 0x20660)) ||
          (uVar5 == 0x20670)) || ((uVar5 == 0x30650 || (uVar5 == 0x30660)))) || (uVar5 == 0x30670)))
       ) {
      DAT_4505538c = DAT_4505538c | 1;
    }
    if (*piVar1 < 7) {
      uVar7 = 0;
    }
    else {
      iVar3 = cpuid_Extended_Feature_Enumeration_info(7);
      uVar7 = *(uint *)(iVar3 + 4);
      if ((uVar7 & 0x200) != 0) {
        DAT_4505538c = DAT_4505538c | 2;
      }
    }
    uVar5 = DAT_4505205c | 2;
    if ((uVar6 & 0x100000) != 0) {
      DAT_45055388 = 2;
      uVar5 = DAT_4505205c | 6;
      if (((uVar6 & 0x8000000) != 0) && ((uVar6 & 0x10000000) != 0)) {
        DAT_45055388 = 3;
        uVar5 = DAT_4505205c | 0xe;
        if ((uVar7 & 0x20) != 0) {
          DAT_45055388 = 5;
          uVar5 = DAT_4505205c | 0x2e;
        }
      }
    }
  }
  DAT_4505205c = uVar5;
  return 0;
}


