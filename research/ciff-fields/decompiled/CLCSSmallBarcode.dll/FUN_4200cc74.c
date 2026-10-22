// Source: CLCSSmallBarcode.dll @ 4200cc74; FUN_4200cc74

void __thiscall FUN_4200cc74(void *this,int *param_1,HDC param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  HBRUSH hbr;
  INT *pIVar3;
  int local_6c [3];
  int *local_60;
  int local_5c;
  uint local_58;
  HDC local_54;
  RECT local_50;
  RECT local_40;
  tagRECT local_30;
  INT local_20 [6];
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  local_54 = param_2;
  local_60 = param_3;
  local_6c[2] = 0;
  local_6c[0] = 0;
  local_50.left = 0;
  local_50.top = 0;
  local_50.right = 0;
  local_50.bottom = 0;
  local_6c[1] = 0;
  SetRect(&local_30,*(int *)((int)this + 0x84),*(int *)((int)this + 0x88),
          *(int *)((int)this + 0x70) + *(int *)((int)this + 0x84),
          *(int *)((int)this + 0x78) + *(int *)((int)this + 0x88));
  FUN_4200c1f4(&local_30.left);
  iVar2 = (**(code **)(*param_1 + 0x18))((int)this + 0x2d0,&local_58);
  if ((-1 < iVar2) && (local_58 != 0)) {
    if (*(int *)((int)this + 0x4c) < 1000) {
      *(int *)((int)this + 0x68) =
           (*(int *)((int)this + 0x68) * *(int *)((int)this + 0x4c)) / 1000 + -1;
    }
    if (*(int *)((int)this + 0x68) < 3) {
      *(undefined4 *)((int)this + 0x68) = 3;
    }
    local_5c = 0;
    local_40.left = 0;
    local_40.top = 0;
    local_40.right = 0;
    local_40.bottom = 0;
    do {
      if (iVar2 < 0) break;
      pIVar3 = local_20;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pIVar3 = 0;
        pIVar3 = pIVar3 + 1;
      }
      FUN_42069210((undefined8 *)&local_40,(undefined8 *)&local_30,0x10);
      iVar1 = local_5c;
      FUN_4200c21a(this,local_54,(int *)(*(int *)((int)this + 0x2d0) + local_5c),&local_50.left,
                   local_6c,(int)local_20,local_60);
      if (local_30.bottom < local_50.bottom) {
        local_40.bottom = local_50.bottom;
        local_40.top = local_30.bottom;
      }
      else if (local_50.top < local_30.top) {
        local_40.top = local_50.top;
        local_40.bottom = local_30.top;
      }
      iVar2 = FUN_42067a8d((uint *)&local_30,(uint *)&local_40,0x10);
      if (iVar2 != 0) {
        hbr = CreateSolidBrush(0xffffff);
        FillRect(local_54,&local_40,hbr);
        DeleteObject(hbr);
      }
      iVar2 = FUN_4200ce72(local_54,&local_50,local_6c,
                           (LPCWSTR)(*(int *)((int)this + 0x2d0) + 0x2c + iVar1),
                           *(UINT *)(iVar1 + 0x28 + *(int *)((int)this + 0x2d0)),local_20);
      (**(code **)(*local_60 + 4))(local_60,&local_54);
      UnionRect(&local_30,&local_30,&local_50);
      FUN_4200c1f4(&local_30.left);
      local_5c = iVar1 + 0x38;
      local_6c[2] = local_6c[2] + 1;
    } while ((uint)local_6c[2] < local_58);
  }
  *(LONG *)((int)this + 0x84) = local_30.left;
  *(LONG *)((int)this + 0x70) = local_30.right - local_30.left;
  *(LONG *)((int)this + 0x80) = local_30.bottom;
  *(LONG *)((int)this + 0x78) = local_30.bottom - local_30.top;
  *(LONG *)((int)this + 0x88) = local_30.top;
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}


