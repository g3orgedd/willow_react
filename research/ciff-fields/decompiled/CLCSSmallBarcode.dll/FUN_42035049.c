// Source: CLCSSmallBarcode.dll @ 42035049; FUN_42035049

undefined4 __thiscall FUN_42035049(void *this,int *param_1,byte *param_2,int param_3)

{
  ushort uVar1;
  UINT UVar2;
  byte *_Memory;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  uint uVar6;
  size_t sVar7;
  int iVar8;
  int iVar9;
  ushort *puVar10;
  UINT UVar11;
  
  if (*(void **)((int)this + 8) != (void *)0x0) {
    FUN_42034e64(*(void **)((int)this + 8),1);
    *(undefined4 *)((int)this + 8) = 0;
  }
  UVar2 = SysStringLen((BSTR)*param_1);
  sVar7 = 1;
  if (0 < (int)UVar2) {
    puVar10 = (ushort *)*param_1;
    UVar11 = UVar2;
    do {
      uVar1 = *puVar10;
      puVar10 = puVar10 + 1;
      iVar9 = 3 - (uint)(uVar1 < 0x800);
      if (uVar1 < 0x80) {
        iVar9 = 1;
      }
      sVar7 = sVar7 + iVar9;
      UVar11 = UVar11 - 1;
    } while (UVar11 != 0);
  }
  iVar9 = 0;
  _Memory = (byte *)FUN_42067510(sVar7);
  if (_Memory != (byte *)0x0) {
    iVar8 = 0;
    iVar3 = 3;
    if (0 < (int)UVar2) {
      do {
        uVar1 = *(ushort *)(*param_1 + iVar9 * 2);
        uVar6 = (uint)uVar1;
        bVar5 = (byte)uVar1;
        if (uVar6 < 0x80) {
          _Memory[iVar8] = bVar5;
          iVar8 = iVar8 + 1;
LAB_42035111:
          iVar3 = 2;
        }
        else {
          if (uVar6 < 0x800) {
            _Memory[iVar8 + 1] = bVar5 & 0x3f | 0x80;
            _Memory[iVar8] = (byte)(uVar1 >> 6) & 0x1f | 0xc0;
            iVar8 = iVar8 + 2;
            goto LAB_42035111;
          }
          _Memory[iVar8] = (byte)(uVar1 >> 0xc) | 0xe0;
          _Memory[iVar8 + 1] = (byte)(uVar1 >> 6) & 0x3f | 0x80;
          _Memory[iVar8 + 2] = bVar5 & 0x3f | 0x80;
          iVar8 = iVar8 + 3;
          if (((uVar6 < 0x8140) || (0x9ffc < uVar6)) && (0xb7f < uVar6 - 0xe040)) {
            iVar3 = 2;
          }
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < (int)UVar2);
    }
    _Memory[iVar8] = 0;
    uVar4 = FUN_42034d59(_Memory,param_2,param_3,iVar3);
    *(undefined4 *)((int)this + 8) = uVar4;
    FID_conflict__free(_Memory);
  }
  uVar4 = 0;
  if (*(int *)((int)this + 8) == 0) {
    uVar4 = 0x80070057;
  }
  return uVar4;
}


