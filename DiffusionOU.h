#pragma once

#include <stdexcept>

namespace SiriusFM
{
class DiffusionCIR
{
private:
    double const m_kappa, m_sigma, m_theta;
public:
    double mu(double a_s, double a_t) const
    {   return m_kappa*(m_theta-a_s);  }
    double sigma(double a_s, double a_t) const
    {   return m_sigma;   }
    
    DiffusionCIR(double m_kappa, double m_sigma, double m_theta)
    :m_kappa(m_kappa),
    m_sigma(m_sigma),
    m_theta(m_theta)
    {
        if ((m_kappa<=0) || (m_sigma<=0)) throw std::invalid_argument("Wrong volatility");
    }
};
}
