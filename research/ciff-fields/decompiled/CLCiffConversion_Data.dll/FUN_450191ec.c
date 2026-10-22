// Source: CLCiffConversion_Data.dll @ 450191ec; FUN_450191ec

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_450191ec(wchar_t *param_1,int param_2,VARIANTARG *param_3,char param_4)

{
  VARTYPE VVar1;
  VARIANTARG *pvargDest;
  int iVar2;
  uint uVar3;
  int iVar4;
  wchar_t *pwVar5;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined *local_30;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pvargDest = param_3;
  uStack_4 = 0x2c;
  local_8 = 0;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (local_2c,"CCiffConversion_Data::Parameter_GetSet");
  uVar3 = 0;
  local_34 = 0;
  local_30 = PTR_DAT_4505101c;
  VVar1 = (pvargDest->n1).n2.vt;
  local_8._0_1_ = 2;
  if (VVar1 == 2) {
    pwVar5 = L"%d";
  }
  else {
    if (VVar1 != 3) {
      if (VVar1 == 8) {
        FUN_450020a5(&local_3c,*(LPCWSTR *)((int)&pvargDest->n1 + 8));
        local_8._0_1_ = 3;
        FUN_450037ea(&local_30,L"%s");
        local_8._0_1_ = 2;
        FUN_45002256(&local_3c);
      }
      goto LAB_45019280;
    }
    pwVar5 = L"%ld";
  }
  FUN_450037ea(&local_30,pwVar5);
LAB_45019280:
  iVar4 = param_2;
  FUN_45005aac(0x450403e8);
  if ((iVar4 == 1) || (iVar2 = _wcscmp(param_1,L"Char Translate File"), iVar2 == 0)) {
    uVar3 = 0x10001;
  }
  else if ((iVar4 == 2) || (iVar2 = _wcscmp(param_1,L"MachineID"), iVar2 == 0)) {
    uVar3 = 0x10002;
  }
  else if ((iVar4 == 3) || (iVar2 = _wcscmp(param_1,L"LineID"), iVar2 == 0)) {
    uVar3 = 0x10003;
  }
  else if ((iVar4 == 4) || (iVar2 = _wcscmp(param_1,L"IgnoreEquipmentReference"), iVar2 == 0)) {
    uVar3 = 0x10004;
  }
  else if ((iVar4 == 5) || (iVar2 = _wcscmp(param_1,L"Database"), iVar2 == 0)) {
    uVar3 = 0x10005;
  }
  else if ((iVar4 == 6) || (iVar2 = _wcscmp(param_1,L"ProductCode"), iVar2 == 0)) {
    uVar3 = 0x10006;
  }
  else if ((iVar4 == 10) || (iVar2 = _wcscmp(param_1,L"CS Database Resolve"), iVar2 == 0)) {
    uVar3 = 0x1000a;
  }
  else if ((iVar4 == 0xb) || (iVar2 = _wcscmp(param_1,L"CS Field Resolve"), iVar2 == 0)) {
    uVar3 = 0x1000b;
  }
  else if ((iVar4 == 0xc) || (iVar2 = _wcscmp(param_1,L"CS Char Translate"), iVar2 == 0)) {
    uVar3 = 0x1000c;
  }
  else if ((iVar4 == 7) || (iVar2 = _wcscmp(param_1,L"ConversionRequestSource"), iVar2 == 0)) {
    uVar3 = 0x10007;
  }
  else if ((iVar4 == 8) || (iVar2 = _wcscmp(param_1,L"DeviceName"), iVar2 == 0)) {
    uVar3 = 0x10008;
  }
  else if ((iVar4 == 9) || (iVar2 = _wcscmp(param_1,L"DownloadOnly"), iVar2 == 0)) {
    uVar3 = 0x10009;
  }
  else if ((iVar4 == 0xd) || (iVar2 = _wcscmp(param_1,L"UserID"), iVar2 == 0)) {
    uVar3 = 0x1000d;
  }
  else if ((iVar4 == 0xe) || (iVar2 = _wcscmp(param_1,L"UserLogo"), iVar2 == 0)) {
    uVar3 = 0x1000e;
  }
  else if ((iVar4 == 0xf) || (iVar2 = _wcscmp(param_1,L"CoderName"), iVar2 == 0)) {
    uVar3 = 0x1000f;
  }
  else if ((iVar4 == 0x10) || (iVar2 = _wcscmp(param_1,L"GroupName"), iVar2 == 0)) {
    uVar3 = 0x10010;
  }
  else if ((iVar4 == 0x11) || (iVar2 = _wcscmp(param_1,L"SSCC Component"), iVar2 == 0)) {
    uVar3 = 0x10011;
  }
  else if ((iVar4 == 0x12) || (iVar2 = _wcscmp(param_1,L"Char Translate Paragraphs"), iVar2 == 0)) {
    uVar3 = 0x10012;
  }
  else if ((iVar4 == 0x13) || (iVar2 = _wcscmp(param_1,L"Fix Merge Fields"), iVar2 == 0)) {
    uVar3 = 0x10013;
  }
  else if ((iVar4 == 0x14) || (iVar2 = _wcscmp(param_1,L"CapsCoder Pointer"), iVar2 == 0)) {
    uVar3 = 0x10014;
  }
  else if ((iVar4 == 0x15) || (iVar2 = _wcscmp(param_1,L"CS Demo Field"), iVar2 == 0)) {
    uVar3 = 0x10015;
  }
  else if ((iVar4 == 0x10016) || (iVar2 = _wcscmp(param_1,L"IDI_DRIVERLETTER_TO_UNC"), iVar2 == 0))
  {
    uVar3 = 0x10016;
  }
  else if (iVar4 == 0x10017) {
    uVar3 = 0x10017;
  }
  if (param_4 == '\x01') {
    iVar4 = (uVar3 & 0xffff) * 0x30;
    local_34 = FUN_45019660((short *)(local_38 + 0x48 + iVar4),(short *)pvargDest);
    *(undefined1 *)(iVar4 + 0x65 + local_38) = 0;
  }
  else {
    VariantCopy(pvargDest,(VARIANTARG *)((uVar3 & 0xffff) * 0x30 + local_38 + 0x48));
  }
  FUN_45002256((int *)&local_30);
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy(local_2c,true,0);
  FUN_45002256((int *)&param_1);
  FUN_45022eb8();
  return;
}


