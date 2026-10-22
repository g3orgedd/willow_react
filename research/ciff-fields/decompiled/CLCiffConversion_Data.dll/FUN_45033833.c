// Source: CLCiffConversion_Data.dll @ 45033833; FUN_45033833

uint __thiscall FUN_45033833(void *this,FILE *param_1)

{
  byte bVar1;
  FILE *_File;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  byte *pbVar6;
  int *piVar7;
  undefined2 extraout_var;
  byte *pbVar8;
  uint uVar9;
  undefined *puVar10;
  undefined4 local_8;
  
  _File = param_1;
  puVar10 = &DAT_45052420;
  local_8 = this;
  if ((param_1->_flag & 0x40) == 0) {
    iVar3 = __fileno(param_1);
    if ((iVar3 == -1) || (iVar3 = __fileno(_File), iVar3 == -2)) {
      puVar5 = &DAT_45052420;
    }
    else {
      iVar3 = __fileno(_File);
      uVar4 = __fileno(_File);
      puVar5 = (undefined *)((uVar4 & 0x1f) * 0x40 + (&DAT_45055ae0)[iVar3 >> 5]);
    }
    if ((puVar5[0x24] & 0x7f) != 0) {
      piVar7 = &_File->_cnt;
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 0) {
        uVar4 = FUN_450366d6(_File);
      }
      else {
        uVar4 = (uint)(byte)*_File->_ptr;
        _File->_ptr = _File->_ptr + 1;
      }
      if (uVar4 != 0xffffffff) {
        piVar7 = &_File->_cnt;
        *piVar7 = *piVar7 + -1;
        param_1 = (FILE *)CONCAT31(param_1._1_3_,(char)uVar4);
        if (*piVar7 < 0) {
          pbVar6 = (byte *)FUN_450366d6(_File);
          pbVar8 = pbVar6;
        }
        else {
          bVar1 = *_File->_ptr;
          pbVar6 = (byte *)(_File->_ptr + 1);
          _File->_ptr = (char *)pbVar6;
          pbVar8 = (byte *)(uint)bVar1;
        }
        if (pbVar8 != (byte *)0xffffffff) {
          param_1._0_2_ = CONCAT11((char)pbVar8,param_1._0_1_);
          param_1 = (FILE *)(uint)(ushort)param_1;
          goto LAB_450338d8;
        }
      }
      return 0xffff;
    }
    if ((_File->_flag & 0x40) == 0) {
      iVar3 = __fileno(_File);
      if ((iVar3 != -1) && (iVar3 = __fileno(_File), iVar3 != -2)) {
        iVar3 = __fileno(_File);
        uVar4 = __fileno(_File);
        puVar10 = (undefined *)((uVar4 & 0x1f) * 0x40 + (&DAT_45055ae0)[iVar3 >> 5]);
      }
      if ((puVar10[4] & 0x80) != 0) {
        uVar4 = 1;
        piVar7 = &_File->_cnt;
        *piVar7 = *piVar7 + -1;
        if (*piVar7 < 0) {
          uVar9 = FUN_450366d6(_File);
        }
        else {
          uVar9 = (uint)(byte)*_File->_ptr;
          _File->_ptr = _File->_ptr + 1;
        }
        if (uVar9 == 0xffffffff) {
          return 0xffff;
        }
        local_8 = (void *)CONCAT31(local_8._1_3_,(char)uVar9);
        iVar3 = FUN_45021506(uVar9 & 0xff);
        if (iVar3 != 0) {
          piVar7 = &_File->_cnt;
          *piVar7 = *piVar7 + -1;
          if (*piVar7 < 0) {
            uVar4 = FUN_450366d6(_File);
          }
          else {
            uVar4 = (uint)(byte)*_File->_ptr;
            _File->_ptr = _File->_ptr + 1;
          }
          if (uVar4 == 0xffffffff) {
            FUN_450368d7((int)(char)(byte)local_8,_File);
            return 0xffff;
          }
          local_8._0_2_ = CONCAT11((char)uVar4,(byte)local_8);
          uVar4 = 2;
        }
        pbVar6 = (byte *)FUN_4503381b((LPWSTR)&param_1,(byte *)&local_8,uVar4);
        if (pbVar6 == (byte *)0xffffffff) {
          piVar7 = __errno();
          *piVar7 = 0x2a;
          return 0xffff;
        }
LAB_450338d8:
        return CONCAT22((short)((uint)pbVar6 >> 0x10),(ushort)param_1);
      }
    }
  }
  if (_File->_cnt < 2) {
    uVar2 = FUN_45036947(_File);
    uVar4 = CONCAT22(extraout_var,uVar2);
  }
  else {
    _File->_cnt = _File->_cnt + -2;
    uVar4 = (uint)*(ushort *)_File->_ptr;
    _File->_ptr = (char *)((int)_File->_ptr + 2);
  }
  return uVar4;
}


