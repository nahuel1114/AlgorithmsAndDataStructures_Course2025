#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "gameSerializer.hpp"
#include "randomEventGenerator.hpp"
#include "refugio.hpp"
#include "engineData.hpp"
#include "event.h"
#include "queue.hpp"
#include "stack.hpp"
#include <chrono>
#include <filesystem>
#include <iostream>
#include <string_view>
#include <thread>
#include <unordered_map>

#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN "cls"
#else
#include <cstdlib>
#define CLEAR_SCREEN "clear"
#endif

#define GREEN  "\033[32m"
#define BLUE   "\033[34m"
#define RED    "\033[31m"
#define WHITE  "\033[37m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

auto constexpr SAVE_FILE {"assets/save.txt"};      //< Nombre del archivo de guardado
auto constexpr CONFIG_FILE {"assets/system.conf"}; //< Nombre del archivo de configuración
auto constexpr CONSOLE_VERSION {"0.1.0"};          //< Versión de la consola

class Refugio;

/**
 * @brief: Clase que inicializa el motor del juego
 */
class Engine
{
public:
    /**
     * @brief: Inicializa el motor del juego
     */
    void start();

    /**
     * @brief: Carga la configuración del juego
     * @param: config Referencia a la configuración del juego
     */

    void engineConfig(const EngineData::GameConfig& config);

    /**
     * @brief: Obtiene la configuración del juego actual
     * @return: Referencia a la configuración del juego
     */
    const EngineData::GameConfig& engineConfig() const;

    /**
     * @brief: Carga el refugio del jugador
     * @param: refugio Referencia al refugio del jugador
     */
    void playerShelter(const Refugio& refugio);

    /**
     * @brief: Carga la información del jugador
     * @return: Referencia a la información del jugador
     */
    const Refugio& playerShelter() const;

    /**
     * @brief: Carga la información del jugador
     * @param: player Referencia a la información del jugador
     */
    void playerInfo(const EngineData::PlayerInfo& player);

    /**
     * @brief: Carga la información del jugador
     * @return: Referencia a la información del jugador
     */
    const EngineData::PlayerInfo& playerInfo() const;

private:
    /**
     * @brief: Inicializa los recursos del tablero
     */
    void initResources();

    /**
     * @brief: Inicializa los elementos del tablero
     */
    static void initEntities();

    /**
     * @brief: Consola interactiva
     */
    void interactiveConsole();

    /**
     * @brief: Muestra el banner de bienvenida
     */
    void showBanner();

    /**
     * @brief: Muestra el menu principal
     */
    void showMenu();

    /**
     * @brief: Limpia la pantalla antes de mostrar el menú
     */
    void clearScreen();

    /**
     * @brief: Carga la información de guardado
     */
    void loadGame();

    /**
     * @brief: Carga la configuración del juego
     */
    void loadConfig();

    void onNewEvent(const Event& evento);

    void registerDecision(const std::string& accion);

    EngineData::PlayerInfo m_player;        //< Información del jugador
    RandomEventGenerator m_randomGenerator; //< Generador de eventos aleatorios
    EngineData::GameConfig m_gameConfig;    //< Configuración del juego
    std::unique_ptr<Refugio> m_shelter;     //< Refugio del jugador
    Queue<Event> m_eventosPendientes;
    Stack<std::string> m_historialDecisiones;

    /**
     * @brief: Operaciones que puede realizar el jugador
     */
    enum class Operation
    {
        SHOW_STATUS, //< Muestra el estado actual del refugio
        SHOW_EVENTS, //< Muestra los eventos aleatorios
        CHECK_EVENT, //< Muestra el evento actual
        SHOW_HISTORY, //<Muestra el historial de decisiones
        EXPLORE,     //< Explora el mapa
        FIGHT,       //< Lucha contra un enemigo
        EXIT,        //< Salir del juego
        SAVE,        //< Guardar el juego
        UNKNOWN      //< Operación desconocida
    };

    const std::unordered_map<char, Operation> m_validOperations = {{'i', Operation::SHOW_STATUS},
                                                                   {'e', Operation::SHOW_EVENTS},
                                                                   {'c', Operation::CHECK_EVENT},
                                                                   {'x', Operation::EXPLORE},
                                                                   {'f', Operation::FIGHT},
                                                                   {'s', Operation::SAVE},
                                                                   {'q', Operation::EXIT}};
};

#endif // ENGINE_HPP
