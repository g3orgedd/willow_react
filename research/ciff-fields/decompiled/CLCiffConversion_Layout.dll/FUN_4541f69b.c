// Source: CLCiffConversion_Layout.dll @ 4541f69b; FUN_4541f69b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_4541f69b(int *param_1)

{
  int *piVar1;
  int *this;
  bool bVar2;
  int **this_00;
  int *piVar3;
  int *piVar4;
  int *local_28;
  undefined4 local_24;
  int *local_20;
  undefined4 local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  this = param_1;
  uStack_4 = 0x18;
  local_8 = 0x4541f6a7;
  if (param_1[1] != 0) {
    piVar1 = *(int **)(*(int *)*param_1 + 8);
    local_28 = (int *)0x0;
    local_24 = 0;
    local_18[0] = piVar1;
    local_28 = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
    local_8 = 0;
    local_20 = (int *)0x0;
    local_1c = 0;
    local_20 = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
    local_8 = CONCAT31(local_8._1_3_,1);
    piVar3 = *(int **)*this;
    if (piVar3 != (int *)*this) {
      do {
        param_1 = (int *)piVar3[2];
        if (param_1 != piVar1) {
          bVar2 = FUN_45421e35((int)param_1,(int)piVar1);
          if (bVar2) {
            this_00 = &local_28;
            piVar4 = local_28;
          }
          else {
            this_00 = &local_20;
            piVar4 = local_20;
          }
          FUN_4541222d(this_00,piVar4,&param_1);
        }
        piVar3 = (int *)*piVar3;
      } while (piVar3 != (int *)*this);
    }
    FUN_4541f69b((int *)&local_28);
    FUN_4541f69b((int *)&local_20);
    FUN_45412166(this);
    FUN_45422801(this,*this,(int *)&local_28);
    FUN_4541222d(this,(int *)*this,local_18);
    FUN_45422801(this,*this,(int *)&local_20);
    FUN_45412166((int *)&local_28);
    FUN_45412166((int *)&local_20);
    FUN_454224ff((int *)&local_20);
    FID_conflict__free(local_20);
    FUN_454224ff((int *)&local_28);
    FID_conflict__free(local_28);
  }
  return;
}


