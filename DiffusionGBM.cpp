#pragma once
#include <stdexcept>

namespace SiriusFM
{

class DiffusionGBM
{
public:
    double const m_mu, m_sigma;
public:
    double mu(double a_s, double a_t) const
    {   return m_mu*a_s;  }
    double sigma(double a_s, double a_t) const
    {   return m_sigma*a_s;   }
    
    DiffusionGBM(double m_mu, double m_sigma)
    :m_mu(m_mu),
    m_sigma(m_sigma)
    {
        if (m_sigma<0) throw std::invalid_argument("Negative volatility");
    }
};
}



