#ifndef CARAVAN_HPP
#define CARAVAN_HPP

#include "artefactoUnico.hpp"
#include "entidadGenerica.hpp"
#include <iostream>
#include <memory>
#include <vector>

/**
 * @class Caravana
 * @brief Representa a los comerciantes itinerantes de artefactos únicos.
 *
 * La caravana viaja por el yermo ofreciendo artículos extremadamente raros a precios elevados.
 */
class Caravana : public EntidadGenerica
{
private:
    std::vector<std::shared_ptr<ArtefactoUnico>> m_stock; ///< Lista de artefactos únicos disponibles
    bool m_confia;                                        ///< Confianza en el refugio

public:
    /**
     * @brief Constructor
     * @param nombre Nombre de la caravana
     * @param confia Indica si la caravana está dispuesta a comerciar
     */
    Caravana(const std::string& nombre, bool confia);
    /**
     * @brief Muestra el inventario de la caravana
     */
    void showInfo() const override;

    /**
     * @brief Intenta comprar un artefacto
     * @param nombre Nombre del artefacto
     * @return Puntero al artefacto si se realizó la transacción, nullptr en caso contrario
     */
    std::shared_ptr<ArtefactoUnico> comprarArtefacto(const std::string& nombre);

    /**
     * @brief Simula una evaluación de confianza futura
     */
    void evaluarConfianza();

private:
    void inicializarStock();
};

#endif // CARAVAN_HPP
