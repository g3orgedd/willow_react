// Source: CLCiffConversion_Layout.dll @ 45404b00; FUN_45404b00

void * __cdecl FUN_45404b00(void *param_1,size_t param_2,char *param_3)

{
  void *pvVar1;
  
  if (param_2 == 0) {
    return (void *)0x0;
  }
  pvVar1 = _memchr(param_1,(int)*param_3,param_2);
  return pvVar1;
}


