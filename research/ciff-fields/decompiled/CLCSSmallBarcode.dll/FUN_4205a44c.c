// Source: CLCSSmallBarcode.dll @ 4205a44c; FUN_4205a44c

void __thiscall FUN_4205a44c(void *this,int param_1,char param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  double dVar3;
  
  fVar2 = DAT_4209d580;
  fVar1 = (float)((double)param_1 * *(double *)((int)this + 0x28)) / DAT_4209d580;
  *param_3 = fVar1;
  if (param_2 == '\x01') {
    dVar3 = *(double *)((int)this + 0x50);
  }
  else {
    dVar3 = *(double *)((int)this + 0x40);
  }
  *param_3 = fVar1 * (float)dVar3;
  fVar2 = (float)((double)param_1 * *(double *)((int)this + 0x28)) / fVar2;
  *param_4 = fVar2;
  if (param_2 == '\x01') {
    dVar3 = *(double *)((int)this + 0x58);
  }
  else {
    dVar3 = *(double *)((int)this + 0x48);
  }
  *param_4 = fVar2 * (float)dVar3;
  return;
}


