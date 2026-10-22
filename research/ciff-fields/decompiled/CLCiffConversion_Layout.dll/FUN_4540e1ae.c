// Source: CLCiffConversion_Layout.dll @ 4540e1ae; FUN_4540e1ae

void FUN_4540e1ae(int param_1,short param_2)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = *(short **)(param_1 + 0xb4);
  if ((psVar2 == (short *)0x0) || (*(short *)(param_1 + 0xa2) == param_2)) {
    return;
  }
  *(short *)(param_1 + 0xa2) = param_2;
LAB_4540e20e:
  do {
    if (*psVar2 == -0x5ff9) {
      return;
    }
    sVar1 = *psVar2;
    if (sVar1 != -0x5fff) {
      if (sVar1 == -0x5ffe) {
LAB_4540e206:
        psVar2 = psVar2 + 1;
        goto LAB_4540e20e;
      }
      if (sVar1 != -0x5ffd) {
        if (sVar1 == -0x5ffc) {
          psVar2[2] = param_2;
        }
        else if (sVar1 != -0x5ffb) {
          if (sVar1 != -0x5ffa) goto LAB_4540e206;
          psVar2[2] = param_2;
          psVar2 = psVar2 + 4;
          goto LAB_4540e20e;
        }
        psVar2 = psVar2 + 3;
        goto LAB_4540e20e;
      }
    }
    psVar2 = psVar2 + 2;
  } while( true );
}


