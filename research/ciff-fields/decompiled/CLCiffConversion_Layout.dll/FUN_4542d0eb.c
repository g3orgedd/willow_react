// Source: CLCiffConversion_Layout.dll @ 4542d0eb; FUN_4542d0eb

int __cdecl FUN_4542d0eb(byte *param_1,byte *param_2,int *param_3)

{
  ushort uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  int local_18;
  int local_14;
  int local_10;
  char local_c;
  uint local_8;
  
  FUN_4542c8eb(&local_18,param_3);
  if ((param_1 == (byte *)0x0) || (param_2 == (byte *)0x0)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_45432798();
LAB_4542d275:
    iVar8 = 0x7fffffff;
  }
  else {
    iVar8 = 0;
    iVar4 = local_14;
    if (*(int *)(local_14 + 8) == 0) {
      iVar8 = FUN_454341e8((char *)param_1,param_2,&local_18);
    }
    else {
      do {
        uVar7 = (uint)*param_1;
        pbVar9 = param_1 + 1;
        if ((*(byte *)(uVar7 + 0x19 + iVar4) & 4) != 0) {
          if (*pbVar9 == 0) {
            uVar7 = 0;
            goto LAB_4542d1c3;
          }
          iVar4 = FUN_45434481(&local_18,*(wchar_t **)(iVar4 + 0x21c),0x200,(LPCSTR)param_1,2,
                               (LPWSTR)&local_8,2,*(UINT *)(iVar4 + 4),1);
          if (iVar4 == 1) {
            uVar7 = local_8 & 0xff;
LAB_4542d1a9:
            pbVar9 = param_1 + 2;
            iVar4 = local_14;
            goto LAB_4542d1c3;
          }
          if (iVar4 == 2) {
            uVar7 = (uint)(ushort)((short)local_8 * 0x100 + ((ushort)(local_8 >> 8) & 0xff));
            goto LAB_4542d1a9;
          }
LAB_4542d26a:
          piVar2 = __errno();
          *piVar2 = 0x16;
          goto LAB_4542d275;
        }
        if ((*(byte *)(uVar7 + 0x19 + iVar4) & 0x10) != 0) {
          uVar7 = (uint)*(byte *)(uVar7 + 0x119 + iVar4);
        }
LAB_4542d1c3:
        uVar3 = (uint)*param_2;
        pbVar5 = param_2 + 1;
        if ((*(byte *)(uVar3 + 0x19 + iVar4) & 4) == 0) {
          uVar1 = (ushort)*param_2;
          param_2 = pbVar5;
          if ((*(byte *)(uVar3 + 0x19 + iVar4) & 0x10) != 0) {
            uVar1 = (ushort)*(byte *)(uVar3 + 0x119 + iVar4);
          }
        }
        else if (*pbVar5 == 0) {
          uVar1 = 0;
          param_2 = pbVar5;
        }
        else {
          iVar4 = FUN_45434481(&local_18,*(wchar_t **)(iVar4 + 0x21c),0x200,(LPCSTR)param_2,2,
                               (LPWSTR)&local_8,2,*(UINT *)(iVar4 + 4),1);
          if (iVar4 == 1) {
            uVar1 = (ushort)(byte)local_8;
          }
          else {
            if (iVar4 != 2) goto LAB_4542d26a;
            uVar1 = (short)local_8 * 0x100 + ((ushort)(local_8 >> 8) & 0xff);
          }
          iVar4 = local_14;
          param_2 = param_2 + 2;
        }
        uVar6 = (ushort)uVar7;
        if (uVar1 != uVar6) {
          iVar8 = (-(uint)(uVar1 < uVar6) & 2) - 1;
          break;
        }
        param_1 = pbVar9;
      } while (uVar6 != 0);
    }
  }
  if (local_c != '\0') {
    *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
  }
  return iVar8;
}


