// CiffMgr.dll entry=68117f20

int FUN_68117f20(int param_1)

{
  short sVar1;
  undefined4 uStack_8;
  
  sVar1 = (short)param_1;
  if ((ushort)(sVar1 - 0x30U) < 10) {
    uStack_8 = param_1 + -0x30;
  }
  else if ((ushort)(sVar1 - 0x41U) < 0x1a) {
    uStack_8 = param_1 + -0x37;
  }
  else if ((ushort)(sVar1 - 0x61U) < 0x1a) {
    uStack_8 = param_1 + -0x3d;
  }
  else if (sVar1 == 0x21) {
    uStack_8 = 0x3e;
  }
  else {
    uStack_8 = 0x3f;
  }
  return uStack_8;
}


