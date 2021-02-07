#pragma once

#include <stdexcept>

namespace SiriusFM
{
class DiffusionLipton
{
private:
    double const m_mu, m_sigma0, m_sigma1, m_sigma2;
public:
    double mu(double a_s, double a_t) const
    {   return m_mu*a_s;  }
    double sigma(double a_s, double a_t) const
    {   return m_sigma0 + m_sigma1*a_s+m_sigma2*a_s*a_s;   }
    
    DiffusionLipton(double m_mu, double m_sigma0, double m_sigma1, double m_sigma2)
    :m_mu(m_mu),
    m_sigma0(m_sigma0),
    m_sigma1(m_sigma1),
    m_sigma2(m_sigma2)
    {
        if ((m_sigma1*m_sigma1-4*m_sigma0*m_sigma0<0) || (m_sigma0<0) || (m_sigma2<0)) throw std::invalid_argument("Volatility can be negative");
    }
};
}
