#include "enclave.hpp"

explicit Enclave::Enclave(const std::string& nombre)
: EntidadGenerica(nombre)
, m_fuerza(generarFuerza())
, m_potencia(generarPotencia())
, m_detectado(false)

{
}

void Enclave::showInfo() const 
{
    std::cout << "💂🏻 ENCLAVE - Escuadrón: " << m_name << "\n"
              << " - Soldados: " << m_fuerza << "\n"
              << " - Potencia táctica: " << m_potencia << "\n"
              << " - ¿Han detectado el refugio?: " << (m_detectado ? "Sí" : "No") << "\n";
}

void  Enclave::detectarRefugio()
{
    m_detectado = true;
    std::cout << "💬 " << m_name << " >>> Objetivo confirmado. Preparando ofensiva." << std::endl;
}

bool Enclave::haDetectado() const
{
    return m_detectado;
}

int Enclave::fuerza() const
{
    return m_fuerza;
}

double Enclave::potencia() const
{
    return m_potencia;
}

int Enclave::generarFuerza()
{
    static std::mt19937 rng(std::random_device {}());
    std::uniform_int_distribution<int> dist(10, 50);
    return dist(rng);
}

double Enclave::generarPotencia() const
{
    static std::mt19937 rng(std::random_device {}());
    std::uniform_real_distribution<double> dist(2.5, 5.0);
    return dist(rng);
};