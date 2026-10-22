// Source: CLCSSmallBarcode.dll @ 4200d122; FUN_4200d122

void __thiscall FUN_4200d122(void *this,int param_1,int param_2)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  HGDIOBJ h;
  int iVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  int iVar7;
  ushort *puVar8;
  tagTEXTMETRICW local_44;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  iVar7 = param_2 * 0xd8;
  iVar3 = (param_1 + 0x1b1) * 0xc;
  h = SelectObject(*(HDC *)(iVar3 + (int)this),*(HGDIOBJ *)(iVar7 + 0xd0 + (int)this));
  if (h == (HGDIOBJ)0x0) goto LAB_4200d24f;
  if ((*(int *)(iVar7 + 200 + (int)this) == 0) && (*(int *)(iVar7 + 0x58 + (int)this) == 100)) {
    bVar2 = true;
LAB_4200d19a:
    GetTextMetricsW(*(HDC *)(iVar3 + (int)this),&local_44);
    if (bVar2) {
      *(LONG *)(iVar7 + 200 + (int)this) = local_44.tmAveCharWidth;
    }
    if (((local_44.tmItalic != '\0') && ((*(byte *)(iVar7 + 0x60 + (int)this) & 2) == 0)) &&
       ((*(byte *)(iVar7 + 0x60 + (int)this) & 1) != 0)) {
      puVar5 = (ushort *)((int)this + iVar7 + 0x6c);
      puVar6 = (undefined4 *)((int)this + iVar7 + 0x10);
      puVar8 = puVar5;
      for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined4 *)puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 2;
      }
      puVar1 = (uint *)(iVar7 + 0xbc + (int)this);
      *puVar1 = *puVar1 & 0xfffffffe;
      *(undefined1 *)(iVar7 + 0xcc + (int)this) = 1;
      SelectObject(*(HDC *)(iVar3 + (int)this),h);
      DeleteObject(*(HGDIOBJ *)(iVar7 + 0xd0 + (int)this));
      *(undefined4 *)(iVar7 + 0xd0 + (int)this) = 0;
      FUN_4200ce9a(this,*(int *)(iVar3 + (int)this),puVar5);
      goto LAB_4200d24f;
    }
  }
  else {
    bVar2 = false;
    if ((*(byte *)(iVar7 + 0x60 + (int)this) & 1) != 0) goto LAB_4200d19a;
  }
  iVar3 = param_1 * 0xc;
  if (*(int *)(iVar3 + 0x1450 + (int)this) == 0) {
    *(HGDIOBJ *)(iVar3 + 0x1450 + (int)this) = h;
  }
  *(int *)(iVar3 + 0x1454 + (int)this) = param_2;
LAB_4200d24f:
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


