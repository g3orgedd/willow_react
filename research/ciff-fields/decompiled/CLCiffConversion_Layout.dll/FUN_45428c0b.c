// Source: CLCiffConversion_Layout.dll @ 45428c0b; FUN_45428c0b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_45428c0b(void *this,byte *param_1,int param_2,VARIANTARG *param_3,char param_4)

{
  bool bVar1;
  VARIANTARG *pvargDest;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *local_34;
  uint local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pvargDest = param_3;
  uStack_4 = 0x30;
  local_30 = 0;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCiffConversion_Layout::Parameter_GetSet");
  iVar4 = param_2;
  uVar3 = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4540303d(0x4544aef0);
  if ((iVar4 == 1) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CharTrans"), iVar2 == 0)) {
    uVar3 = 0x10001;
    goto LAB_45428f31;
  }
  if ((iVar4 == 10) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CS Cull"), iVar2 == 0)) {
    uVar3 = 0x1000a;
    goto LAB_45428f31;
  }
  if ((iVar4 == 0xb) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CS Resolution Adjust"), iVar2 == 0))
  {
    uVar3 = 0x1000b;
    goto LAB_45428f31;
  }
  if ((iVar4 == 0xc) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CS Font Convert"), iVar2 == 0)) {
    uVar3 = 0x1000c;
    goto LAB_45428f31;
  }
  if ((iVar4 == 0xd) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CS Resolve Field Width"), iVar2 == 0)
     ) {
    uVar3 = 0x1000d;
    goto LAB_45428f31;
  }
  if ((iVar4 == 0xe) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CS Field Order"), iVar2 == 0)) {
    uVar3 = 0x1000e;
    goto LAB_45428f31;
  }
  if ((iVar4 == 0xf) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CS Position"), iVar2 == 0)) {
    uVar3 = 0x1000f;
    goto LAB_45428f31;
  }
  if ((iVar4 == 0x10) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CS Add Tab Fields"), iVar2 == 0)) {
    uVar3 = 0x10010;
    goto LAB_45428f31;
  }
  if ((iVar4 == 0x11) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CS Tag"), iVar2 == 0)) {
    uVar3 = 0x10011;
    goto LAB_45428f31;
  }
  if ((iVar4 == 0x12) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CS Demo Field"), iVar2 == 0)) {
    uVar3 = 0x10012;
    goto LAB_45428f31;
  }
  if ((iVar4 == 0x13) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CS Zipher Barcode"), iVar2 == 0)) {
    uVar3 = 0x10013;
    goto LAB_45428f31;
  }
  if ((iVar4 == 2) || (iVar2 = FUN_4542cae1(param_1,(byte *)"DeviceName"), iVar2 == 0)) {
    uVar3 = 0x10002;
    goto LAB_45428f31;
  }
  if ((iVar4 == 3) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CapsFile"), iVar2 == 0)) {
    uVar3 = 0x10003;
    goto LAB_45428f31;
  }
  if ((iVar4 == 4) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CapsCoder"), iVar2 == 0)) {
    uVar3 = 0x10004;
    goto LAB_45428f31;
  }
  if ((iVar4 == 5) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CapsFormat"), iVar2 == 0)) {
    uVar3 = 0x10005;
    goto LAB_45428f31;
  }
  if ((iVar4 == 6) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CapsFile Pointer"), iVar2 == 0)) {
    uVar3 = 0x10006;
    goto LAB_45428f31;
  }
  if ((iVar4 == 7) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CapsCoder Pointer"), iVar2 == 0)) {
    uVar3 = 0x10007;
    goto LAB_45428f31;
  }
  if ((iVar4 == 8) || (iVar2 = FUN_4542cae1(param_1,(byte *)"CapsFormat Pointer"), iVar2 == 0)) {
    uVar3 = 0x10008;
    goto LAB_45428f31;
  }
  if ((iVar4 == 9) || (iVar2 = FUN_4542cae1(param_1,(byte *)"ConversionRequestSource"), iVar2 == 0))
  {
    uVar3 = 0x10009;
    goto LAB_45428f31;
  }
  if ((iVar4 == 0x14) || (iVar2 = FUN_4542cae1(param_1,(byte *)"Sub Image"), iVar2 == 0)) {
    uVar3 = 0x10014;
    goto LAB_45428f31;
  }
  if (iVar4 == 0x15) {
LAB_45428f0e:
    bVar1 = true;
  }
  else {
    FUN_45402ac2(&local_34,L"Convert To Dots");
    local_30 = 1;
    iVar2 = FUN_4542cae1(param_1,local_34);
    if (iVar2 == 0) goto LAB_45428f0e;
    bVar1 = false;
  }
  if ((local_30 & 1) != 0) {
    local_30 = local_30 & 0xfffffffe;
    FUN_45402c5d((int *)&local_34);
  }
  if (bVar1) {
    uVar3 = 0x10015;
    goto LAB_45428f31;
  }
  if (iVar4 == 0x16) {
LAB_45428f89:
    bVar1 = true;
  }
  else {
    FUN_45402ac2(&local_34,L"CS RTBF2LOGO");
    local_30 = local_30 | 2;
    iVar4 = FUN_4542cae1(param_1,local_34);
    if (iVar4 == 0) goto LAB_45428f89;
    bVar1 = false;
  }
  if ((local_30 & 2) != 0) {
    FUN_45402c5d((int *)&local_34);
  }
  if (bVar1) {
    uVar3 = 0x10016;
  }
LAB_45428f31:
  if (param_4 == '\0') {
    VariantCopy(pvargDest,(VARIANTARG *)((uVar3 & 0xffff) * 0x30 + 0x58 + (int)this));
  }
  else {
    iVar4 = (uVar3 & 0xffff) * 0x30;
    FUN_4542909b((short *)((int)this + iVar4 + 0x58),(short *)pvargDest);
    *(undefined1 *)(iVar4 + 0x75 + (int)this) = 0;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45402c5d((int *)&param_1);
  FUN_4542a957();
  return;
}


