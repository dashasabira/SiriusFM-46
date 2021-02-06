#pragma once

#include <stdexcept>
#include <cmath>

namespace SiriusFM
{
class DiffusionCEV
{
public:
    double const m_mu, m_sigma, m_b;
public:
    double mu(double a_s, double a_t)
    {   return m_mu*a_s;  }
    double sigma(double a_s, double a_t)
    {   return m_sigma*pow(a_s, m_b);   }
    
    DiffusionCEV(double m_mu, double m_sigma, double m_b)
    :m_mu(m_mu),
    m_sigma(m_sigma),
    m_b(m_b)
    {
        if ((m_b<=0) || (m_b>1) || (m_sigma<0)) throw std::invalid_argument("Volatility can be negative");
    }
};
}
