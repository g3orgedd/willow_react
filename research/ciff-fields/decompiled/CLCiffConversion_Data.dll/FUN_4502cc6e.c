// Source: CLCiffConversion_Data.dll @ 4502cc6e; __cfltcvt_l

/* Library Function - Single Match
    __cfltcvt_l
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release,
   Visual Studio 2012 Release */

errno_t __cdecl
__cfltcvt_l(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps,
           _locale_t plocinfo)

{
  errno_t eVar1;
  
  if ((format == 0x65) || (format == 0x45)) {
    eVar1 = FUN_4502d1bf((undefined4 *)arg,buffer,sizeInBytes,precision,caps,(int *)plocinfo);
  }
  else {
    if (format == 0x66) {
      eVar1 = FUN_4502d379((undefined4 *)arg,buffer,sizeInBytes,precision,(int *)plocinfo);
      return eVar1;
    }
    if ((format == 0x61) || (format == 0x41)) {
      eVar1 = FUN_4502ccf4((int *)arg,buffer,sizeInBytes,precision,caps,(int *)plocinfo);
    }
    else {
      eVar1 = FUN_4502d43a((undefined4 *)arg,buffer,sizeInBytes,precision,caps,(int *)plocinfo);
    }
  }
  return eVar1;
}


