// Source: CLCiffConversion_Data.dll @ 45004ea5; std::char_traits<char>::length

/* Library Function - Single Match
    public: static unsigned int __cdecl std::char_traits<char>::length(char const *)
   
   Library: Visual Studio 2012 Release */

uint __cdecl std::char_traits<char>::length(char *param_1)

{
  size_t sVar1;
  
  if (*param_1 == '\0') {
    return 0;
  }
  sVar1 = _strlen(param_1);
  return sVar1;
}


