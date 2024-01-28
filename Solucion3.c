#include <stdio.h>

struct OrdenTrabajo
{
    char nombreCliente[50];
    char apellidoCliente[50];
    int trabajo;
    float costo;
};

int main(void)
{
    int opcion;
    int mantenimiento;
    FILE *archivo;
    archivo = fopen("ordenes_trabajo.txt", "a");
    struct OrdenTrabajo orden;
    orden.costo = 0;

    do
    {
        printf("Ingrese el numero de la accion que desee realizar. (Ejemplo = 1 )\n");
        printf("1. Ingresar su cuenta. \n");
        printf("2. Realizar una orden de trabajo. \n");
        printf("3. Mostrar los datos de su pedido. \n");
        printf("4. Salir. \n");
        scanf("%d", &opcion);
        printf("\n");

        switch (opcion)
        {
        case 1:
            printf("Ingrese su nombre. \n");
            scanf("%s", orden.nombreCliente);
            printf("Ingrese su apellido.\n");
            scanf("%s", orden.apellidoCliente);
            break;
        case 2:
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
                printf("Que mantenimiento se va a realizar?\n");
                printf("1. Mantenimiento de HARDWARE.\n");
                printf("2. Mantenimiento de SOFTWARE.\n");
                printf("3. Formateo del dispositivo.\n");
                scanf("%d", &mantenimiento);
                if (mantenimiento == 1)
                {
                    orden.costo += 40;
                }
                else if (mantenimiento == 2)
                {
                    orden.costo += 50;
                }
                else if (mantenimiento == 3)
                {
                    orden.costo += 8;
                }
                printf("Su orden de trabajo ha sido guardada!\n");
                printf("\n");
            }
            else
            {
                printf("Que mantenimiento se va a realizar?\n");
                printf("1. Mantenimiento de HARDWARE.\n");
                printf("2. Mantenimiento de SOFTWARE.\n");
                printf("3. Formateo del dispositivo.\n");
                scanf("%d", &mantenimiento);
                if (mantenimiento == 1)
                {
                    orden.costo += 35;
                }
                else if (mantenimiento == 2)
                {
                    orden.costo += 45;
                }
                else if (mantenimiento == 3)
                {
                    orden.costo += 10;
                }
                printf("Su orden de trabajo ha sido guardada!\n");
                printf("\n");
            }
            break;
        case 3:

            printf("Datos del pedido:\n");
            printf("Nombre: %s %s\n", orden.nombreCliente, orden.apellidoCliente);
            printf("Costo total: $%.2f\n", orden.costo);

            fprintf(archivo, "%s %s %.2f \n", orden.nombreCliente, orden.apellidoCliente, orden.costo);
            break;
        case 4:
            printf("Hasta pronto!\n");
            break;
        default:
            printf("Opción no válida. Por favor, ingrese una opción válida.\n");
            break;
        }
    } while (opcion != 4);

    fclose(archivo);
    return 0;
}