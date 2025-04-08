#include "refugio.hpp"

std::string Refugio::faccionToString(EngineData::Faction faccion) const
{
    switch (faccion)
    {
        case EngineData::Faction::REFUGEES: return "Refugiados";
        case EngineData::Faction::WATER_MERCHANTS: return "Comerciantes de Agua";
        case EngineData::Faction::MERCHANTS: return "Comerciantes";
        case EngineData::Faction::STEEL_BROTHERS: return "Hermanos del Acero";
        case EngineData::Faction::CARAVAN: return "Caravana";
        case EngineData::Faction::RAIDERS: return "Asaltantes";
        case EngineData::Faction::MUTANTS: return "Mutantes";
        default: return "Desconocida";
    }
}

Refugio::Refugio(const std::string& name, const std::string& leader)
    : EntidadGenerica(name)
    , m_leader(leader)
{
}

void Refugio::showInfo() const
{
    std::cout << "🏠 Refugio: " << m_name << "\t A cargo de: " << m_leader << "\n";
    std::cout << "\t🛡️  Defensa: " << m_defense << "\n";
    std::cout << "\t⚔️  Ataque: " << m_attack << "\n";
    std::cout << "👥 Moradores: ";
    for (int refugee = 0; refugee < m_refugees.size(); refugee++)
    {
        std::cout << "\t - " << m_refugees.at(refugee) << std::endl;
    }
    std::cout << "\n";
    std::cout << "\t📦 Recursos: \n";
}

void Refugio::doAction() const
{
    throw std::runtime_error("Not implemented yet");
}

void Refugio::addRefugee(const std::string& refugee)
{
    throw std::runtime_error("Not implemented yet");
}

void Refugio::addResource(const std::string& resource, float amount)
{
    throw std::runtime_error("Not implemented yet");
}

bool Refugio::consumeResource(const std::string& resource, float amount)
{
    throw std::runtime_error("Not implemented yet");
    return false;
}

void Refugio::registerVisitant(const std::string& nombre, const EngineData::Faction faccion)
{
    if (!isSafeFaction(faccion))
    {
//        std::cout << "Acceso denegado: La facción " << faccionToString(faccion) << " no es segura para el refugio."
  //                << std::endl;
        return;
    }

    Visitante nuevoVisitante {nombre, faccion};
    m_visitants->push_front(nuevoVisitante);
    std::cout << "Visitante: " << nombre << " registrado existosamente en el refugio." << std::endl;
}

void Refugio::showVisits()
{
    std::cout << "📖 Registro de visitas al Refugio " << m_name << ":\n";
    printRecursive(m_visitants->get_head());
}

void Refugio::printRecursive(DoublyListNode<Visitante>* mNode)
{
    if (!mNode)
    {
        std::cout << "Fin del registro!" << std::endl;
        return;
    }
}


bool Refugio::isSafeFaction(const EngineData::Faction faccion) const
{
    return (faccion == EngineData::Faction::REFUGEES || faccion == EngineData::Faction::WATER_MERCHANTS ||
            faccion == EngineData::Faction::MERCHANTS || faccion == EngineData::Faction::STEEL_BROTHERS ||
            faccion == EngineData::Faction::CARAVAN);
}

std::ostream& operator<<(std::ostream& os, const Refugio::Visitante& visitante)
{
    // Creamos una instancia temporal para llamar a faccionToString (ya que no es static)
    Refugio dummy("Dummy", "Líder");
    os << visitante.nombre << " (" << dummy.faccionToString(visitante.faccion) << ")";
    return os;
}

