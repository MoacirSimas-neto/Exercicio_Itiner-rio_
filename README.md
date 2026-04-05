# 🚌 Sistema de Itinerário de Ônibus

Sistema em **C++** para gerenciamento de rotas de transporte coletivo, usando **lista duplamente encadeada**.

## Como compilar e executar

```bash
g++ -o itinerario main.cpp src/linked_list.cpp
./itinerario
```

## Funcionalidades

1. Inserir parada no início
2. Inserir parada no fim
3. Inserir parada por posição
4. Remover primeira parada
5. Remover última parada
6. Buscar parada por nome (parcial)
7. Listar rota completa (ida)
8. Listar rota em ordem inversa
9. Contar paradas

## Estrutura de dados escolhida

**Lista duplamente encadeada**, pois permite:
- Percurso nos dois sentidos (ida e volta) sem estruturas auxiliares
- Remoção eficiente nas duas extremidades em O(1)
- Inserção por posição facilitada pelo ponteiro `anterior`

## Cenário alternativo

Para **linhas circulares** (ônibus que retorna ao ponto de origem), uma **lista circular duplamente encadeada** seria mais vantajosa, pois o último nó conectaria naturalmente ao primeiro, sem lógica condicional extra.