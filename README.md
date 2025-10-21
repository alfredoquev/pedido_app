#  Sistema de Gestión de Pedidos en C++

Este proyecto permite registrar, procesar, eliminar y visualizar pedidos desde la consola. Los pedidos se agrupan y se encolan según si el cliente es suscriptor o no, utilizando estructuras lineales como arreglos dinámicos, colas FIFO y colas con prioridad.

##  Funcionalidades

- Registro de pedidos con sobrecarga de operadores
- Procesamiento de pedidos por prioridad (suscriptores) o por orden de llegada (no suscriptores)
- Eliminación de pedidos por ID
- Visualización de todos los pedidos registrados

##  Estructuras utilizadas

- `std::vector<Pedido>` para almacenar pedidos
- `std::queue<std::vector<Pedido>>` para cola normal
- `std::priority_queue<std::vector<Pedido>>` para cola de suscriptores

##  Compilación

```bash
g++ src/main.cpp src/pedido.cpp -o pedido_app
./pedido_app

