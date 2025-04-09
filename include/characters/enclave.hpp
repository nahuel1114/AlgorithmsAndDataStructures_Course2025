#ifndef ENCLAVE_HPP
#define ENCLAVE_HPP

#include "entidadGenerica.hpp"
#include <iostream>
#include <random>

/**
 * @class Enclave
 * @brief Representa una fuerza de combate de la facción ENCLAVE.
 *
 * Altamente equipada y letal, no se puede razonar con ellos. Atacan con fuerza total
 * y su presencia representa un peligro inmediato para el refugio.
 */
class Enclave : public EntidadGenerica
{
private:
    int m_fuerza;      ///< Cantidad de soldados (entre 10 y 50)
    double m_potencia; ///< Nivel de potencia de fuego estimado (escala 1.0 a 5.0)
    bool m_detectado;  ///< Si han detectado el refugio

public:
    /**
     * @brief Constructor
     * @param nombre Nombre del escuadrón
     */
    explicit Enclave(const std::string& nombre);

    /**
     * @brief Muestra información de la escuadra ENCLAVE
     */
    void showInfo() const override;

    /**
     * @brief Simula la detección del refugio
     */
    void detectarRefugio();

    /**
     * @brief Devuelve si la escuadra ya ha detectado el refugio
     */
    bool haDetectado() const;

    /**
     * @brief Devuelve la fuerza de combate
     */
    int fuerza() const;
    /**
     * @brief Devuelve la potencia de ataque
     */
    double potencia() const;

private:
    /**
     * @brief Genera aleatoriamente una cantidad de soldados entre 10 y 50
     */
    int generarFuerza();
    /**
     * @brief Genera aleatoriamente un valor de potencia entre 2.5 y 5.0
     */
    double generarPotencia() const;
};

#endif // ENCLAVE_HPP
