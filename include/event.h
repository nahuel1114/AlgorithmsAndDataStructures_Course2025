//
// Created by nahue on 7/4/2025.
//

#ifndef EVENT_H
#define EVENT_H

#include<iostream>

struct Event
{
    std::string m_type; //tipo de evento
    std::string m_description; //descripcion del evento
    std::string m_time; //ticks que durara el evento

    Event(std::string type, std::string description, std::string time)
        : m_type(std::move(type)), m_description(std::move(description)), m_time(std::move(time)) {}

};

#endif //EVENT_H
