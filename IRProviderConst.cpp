#include "IRProviderConst.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

namespace SiriusFM
{
IRProvider<IRModeE::Const>::IRProvider(char const* a_file)
{
    for(int i=0; i<int(CcyE::N); i++)
    {
        m_IRs[i]=0;
    }
    FILE * f = fopen(a_file, "r");
    char buff[64];
    while (!fgets(buff, 64, f))
    {
        buff[3] = '\0';
        CcyE a_ccy = Str2CcyE(buff);
        m_IRs[int(a_ccy)] = atof(buff + 4);
    }
    
}
}
