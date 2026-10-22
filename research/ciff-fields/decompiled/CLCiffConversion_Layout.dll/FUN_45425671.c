// Source: CLCiffConversion_Layout.dll @ 45425671; FUN_45425671

uint __thiscall FUN_45425671(void *this,char param_1)

{
  uint in_EAX;
  
  if ('/' < param_1) {
    if (param_1 < ':') {
      return (int)param_1 - 0x30;
    }
    if ('@' < param_1) {
      if (param_1 < 'G') {
        return (int)param_1 - 0x37;
      }
      in_EAX = CONCAT31((int3)((uint)this >> 8),param_1) - 0x61;
      if ((byte)in_EAX < 6) {
        return (int)param_1 - 0x57;
      }
    }
  }
  return in_EAX & 0xffffff00;
}


