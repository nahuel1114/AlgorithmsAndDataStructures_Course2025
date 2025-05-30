//
// Created by nahue on 30/5/2025.
//

#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <algorithm>
#include <climits>
#include <queue>
#include <utility>
#include <vector>
#include<iostream>

class grafo
{
private:
    std::vector<std::vector<std::pair<int,int>>> lista_adj;

public:
    explicit grafo(const int n)
    {
            lista_adj.resize(n);
    }

    void agregar_arista(int nodo1, int nodo2, int distancia)
    {
        lista_adj[nodo1].push_back(std::pair<int, int>(distancia, nodo2));
    }

    void dijkstra(int inicio, int final)
    {
        int n = static_cast<int>(lista_adj.size());
        std::vector<int> distancias(n, INT_MAX);
        distancias[inicio] = 0;

        std::priority_queue<std::pair<int,int>,
                            std::vector<std::pair<int,int>>,
                            std::greater<std::pair<int,int>>> siguiente;
        siguiente.push(std::pair<int,int>(0, inicio));

        std::vector<int> predecesor(n, -1);

        while (!siguiente.empty())
        {
            int distancia = siguiente.top().first;
            int nodo = siguiente.top().second;
            siguiente.pop();

            if (distancia > distancias[nodo]) continue;
            for (int i = 0; i < lista_adj[nodo].size(); i++)
            {
                int distancia_vec = lista_adj[nodo][i].first;
                int vecino = lista_adj[nodo][i].second;
                if (distancias[vecino] > distancias[nodo] + distancia_vec)
                {
                    distancias[vecino] = distancias[nodo] + distancia_vec;
                    predecesor[vecino] = nodo;
                    siguiente.push(std::pair<int,int>(distancias[vecino], vecino));
                }
            }
        }
        if (distancias[final] != INT_MAX)
        {
            std::vector<int> recorrido;
            for (int i = final; i != -1; i = predecesor[i])
            {
                recorrido.push_back(i);
            }
            std::reverse(recorrido.begin(), recorrido.end());

            std::cout<<"El recorrido relizado para ir desde el refugio: "<<inicio
                     <<", hacia el refugio: "<<final<<" es:\n";
            for (int i = 0; i < recorrido.size(); i++)
            {
                std::cout<<recorrido[i];

                if (i < recorrido.size() - 1)
                {
                    std::cout<<"->";
                }
            }
            std::cout<<"\nCon un riesgo total acumulado de: "<<distancias[final]<<std::endl;
        }
        else
        {
            std::cout<<"No existe un camino desde el refugio "<<inicio
            <<" hacia el refugio "<<final;
        }
    }

};


#endif //DIJKSTRA_H
