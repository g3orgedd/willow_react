// Source: CiffMgr.dll @ 6810f015; DllGetClassObject

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  
                    /* 0xf015  2  DllGetClassObject */
  iVar1 = FUN_6810d43a(&DAT_681670d8,(LPCRITICAL_SECTION)rclsid,riid,(int *)ppv);
  return iVar1;
}


