// Source: CLCiffConversion_Layout.dll @ 4540dc78; FUN_4540dc78

undefined4 FUN_4540dc78(wchar_t *param_1,uint *param_2,int param_3)

{
  bool bVar1;
  size_t sVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  wchar_t *pwVar6;
  uint *local_8;
  
  sVar2 = _wcslen(param_1);
  bVar1 = false;
  local_8 = (uint *)0x0;
  *(undefined2 *)(param_3 + 2) = 0;
  *(undefined2 *)(param_3 + 4) = 100;
  *(undefined4 *)(param_3 + 6) = 0;
  puVar3 = FUN_45429f70(param_2,0,0x40);
  uVar5 = 0;
  pwVar6 = param_1;
  if (sVar2 != 0xffffffff) {
    do {
      puVar3 = (uint *)(uint)(ushort)*pwVar6;
      if ((puVar3 == (uint *)0x2e) || (*pwVar6 == L'\0')) {
        if (!bVar1) {
          uVar4 = uVar5 - (int)local_8;
          if (0x1f < uVar5 - (int)local_8) {
            uVar4 = 0x1f;
          }
          FUN_4542df68((short *)param_2,0x20,param_1 + (int)local_8,uVar4);
          bVar1 = true;
          goto LAB_4540dd08;
        }
      }
      else if ((puVar3 == (uint *)0x5c) || (puVar3 == (uint *)0x2f)) {
        bVar1 = false;
LAB_4540dd08:
        puVar3 = (uint *)(uVar5 + 1);
        local_8 = puVar3;
      }
      uVar5 = uVar5 + 1;
      pwVar6 = pwVar6 + 1;
    } while (uVar5 < sVar2 + 1);
  }
  return CONCAT31((int3)((uint)puVar3 >> 8),1);
}


