#include <caravana.hpp>


Caravana::Caravana(const std::string& nombre, bool confia)
    : EntidadGenerica(nombre)
    , m_confia(confia)
{
    inicializarStock();
}


void Caravana::showInfo() const 
{
    std::cout << "🚚 Caravana: " << m_name << "\n";
    std::cout << " - Confianza: " << (m_confia ? "Sí" : "No") << "\n";
    std::cout << " - Artefactos disponibles:\n";
        for (const auto& item : this->m_stock)
        {
            item->showInfo();
        }
}

std::shared_ptr<ArtefactoUnico> Caravana::comprarArtefacto(const std::string& nombre)
{
    if (!m_confia)
        {
            std::cout << "💬 " << m_name << " >>> No confiamos lo suficiente en tu refugio para hacer negocios."
                      << std::endl;
            return nullptr;
        }

        for (auto it = m_stock.begin(); it != m_stock.end(); ++it)
        {
             if ((*it)->nombre() == nombre)
             {
                 std::cout << "💬 " << m_name << " >>> Excelente elección. Espero que lo uses bien." << std::endl;
                 auto item = *it;
                 m_stock.erase(it);
                 return item;
             }
        }

        std::cout << "💬 " << m_name << " >>> No tenemos ese artefacto en este momento." << std::endl;
        return nullptr;
}

void Caravana::evaluarConfianza()
{
    this->m_confia = true; // Lógica temporal, puede depender del nivel del refugio
}

void Caravana::inicializarStock()
{
    m_stock.emplace_back(std::make_shared<ArtefactoUnico>("Detector de Radiación", "Épico", EngineData::UniqueArtifactType::TECHNOLOGY, 250.0));
    m_stock.emplace_back(std::make_shared<ArtefactoUnico>("Pistola Láser Táctica", "Legendaria", EngineData::UniqueArtifactType::WEAPON, 400.0));
    m_stock.emplace_back(std::make_shared<ArtefactoUnico>("Batería de Fusión", "Rara", EngineData::UniqueArtifactType::TECHNOLOGY, 320.0));

}