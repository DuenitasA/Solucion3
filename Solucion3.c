#include <stdio.h>

struct OrdenTrabajo
{
    char nombreCliente[25];
    char apellidoCliente[25];
    int trabajo;
    float costo;
    int Factura;
};

/* Se creo una estructura que almacene todos los datos que se van a imprimir proximamente en un archivo plano*/

int main(void)
{
    int opcion;
    FILE *archivo;
    archivo = fopen("ordenes_trabajo.txt", "a");

    printf("Ingrese el numero de la accion que desee realizar. (Ejemplo = 1 )\n");
    scanf("%d", &opcion);

    printf("1.Ingresar su cuenta. \n");
    printf("2. Realizar una orden de trabajo. \n");
    printf("3. Mostrar los datos de su pedido. \n");
    printf("4. Salir. \n");
    printf("\n");
    printf("\n");

    switch (opcion)
    {
    case 1:
        struct OrdenTrabajo orden;
        printf("Ingrese su nombre. \n");
        scanf("%s", orden.nombreCliente);
        printf("Ingrese su apellido.\n");
        scanf("%s", orden.apellidoCliente);
        break;
    case 2:
        struct OrdenTrabajo orden;
        printf("Escoja el dispositivo al cual desea que le realicemos mantenimiento.\n");
        printf("1. Computadora.\n");
        printf("2. Celular. \n");
        scanf("%d", orden.trabajo);
        
    default:
        break;
    }

    struct OrdenTrabajo orden;

    return 0;
}