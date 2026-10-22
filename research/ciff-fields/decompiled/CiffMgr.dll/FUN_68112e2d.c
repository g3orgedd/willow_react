// Source: CiffMgr.dll @ 68112e2d; FUN_68112e2d

uint __thiscall FUN_68112e2d(void *this,BSTR param_1,undefined8 *param_2,char param_3,char param_4)

{
  undefined8 *puVar1;
  uint uVar2;
  BSTR psz;
  undefined4 *puVar3;
  
  psz = param_1;
  if (param_1 != (BSTR)0x0) {
    if (*(int *)((int)this + 0xc) != 0) {
      uVar2 = FUN_68111578(this,param_1,0,*(int *)((int)this + 0xc) - 1,
                           (undefined1 *)((int)&param_1 + 3));
      if (param_1._3_1_ == '\0') {
        if (*(uint *)((int)this + 8) < *(int *)((int)this + 0xc) + 1U) {
          if (uVar2 == *(uint *)((int)this + 8)) {
            FUN_681114df((int)this);
          }
          else {
            FUN_68111467(this,uVar2);
          }
          if (*(uint *)((int)this + 8) <= *(uint *)((int)this + 0xc)) {
            return 0xffffffff;
          }
        }
        else {
          puVar1 = (undefined8 *)(*(int *)((int)this + 4) + uVar2 * 8);
          FUN_681317c0(puVar1 + 1,puVar1,
                       (*(int *)((int)this + 0xc) - uVar2) * *(int *)((int)this + 0x10));
        }
        if (param_3 == '\0') {
          psz = SysAllocString(psz);
        }
        *(BSTR *)(*(int *)((int)this + 4) + uVar2 * 8) = psz;
        if (param_4 == '\0') {
          puVar3 = (undefined4 *)(*(int *)((int)this + 4) + 4 + uVar2 * 8);
          if (puVar3 != (undefined4 *)0x0) {
            *puVar3 = *(undefined4 *)param_2;
          }
        }
        else {
          FUN_681310e0((undefined8 *)(*(int *)((int)this + 4) + uVar2 * 8 + 4),param_2,4);
        }
        *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
        return uVar2;
      }
      if (param_4 == '\0') {
        puVar3 = (undefined4 *)(*(int *)((int)this + 4) + 4 + uVar2 * 8);
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = *(undefined4 *)param_2;
        }
      }
      else {
        FUN_681310e0((undefined8 *)(*(int *)((int)this + 4) + uVar2 * 8 + 4),param_2,4);
      }
      if (param_3 != '\0') {
        SysFreeString(psz);
        return uVar2;
      }
      return uVar2;
    }
    if ((*(int *)((int)this + 8) != 0) ||
       (FUN_681114df((int)this), *(uint *)((int)this + 0xc) < *(uint *)((int)this + 8))) {
      if (param_3 == '\0') {
        psz = SysAllocString(psz);
      }
      **(undefined4 **)((int)this + 4) = psz;
      if (param_4 == '\0') {
        puVar3 = (undefined4 *)(*(int *)((int)this + 4) + 4);
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = *(undefined4 *)param_2;
        }
      }
      else {
        FUN_681310e0((undefined8 *)(*(int *)((int)this + 4) + 4),param_2,4);
      }
      *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;
      return 0;
    }
  }
  return 0xffffffff;
}


