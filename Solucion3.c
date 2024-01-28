#include <stdio.h>

struct OrdenTrabajo
{
    char nombreCliente[25];
    char apellidoCliente[25];
    int trabajo;
    float costo;
};

/* Se creo una estructura que almacene todos los datos que se van a imprimir proximamente en un archivo plano*/

int main(void)
{
    int opcion;
    FILE *archivo;
    archivo = fopen("ordenes_trabajo.txt", "a");
    do
    {
        printf("Ingrese el numero de la accion que desee realizar. (Ejemplo = 1 )\n");
        printf("1.Ingresar su cuenta. \n");
        printf("2. Realizar una orden de trabajo. \n");
        printf("3. Mostrar los datos de su pedido. \n");
        printf("4. Salir. \n");
        scanf("%d", &opcion);
        printf("\n");
        struct OrdenTrabajo orden;
        switch (opcion)
        {
        case 1:
            printf("Ingrese su nombre. \n");
            scanf("%s", orden.nombreCliente);
            printf("Ingrese su apellido.\n");
            scanf("%s", orden.apellidoCliente);
            break;
        case 2:
            orden.costo = 0;
            do
            {

                printf("Escoja el dispositivo al cual desea que le realicemos mantenimiento.\n");
                printf("1. Computadora.\n");
                printf("2. Celular. \n");
                scanf("%d", &orden.trabajo);
                if (orden.trabajo < 1 || orden.trabajo > 2)
                {
                    printf("Por favor, ingrese una opcion valida (1 o 2).\n");
                }
            } while (orden.trabajo < 1 || orden.trabajo > 2);
            if (orden.trabajo == 1)
            {
                orden.costo += 30.00;
            }
            else
            {

                orden.costo += 15.00;
            }
            break;
        case 3:

            fprintf(archivo, "%s %s %.2f \n", orden.nombreCliente, orden.apellidoCliente, orden.costo);
            
            break;
        case 4:

            printf("Hasta pronto!\n");

        default:
            break;
        }
    } while (opcion != 4);

    fclose(archivo);
    return 0;
}