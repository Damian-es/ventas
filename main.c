#include <stdio.h>

int main() {
    int stock, cantidad, opcion;
    float precio, total_ganancias = 0, venta=0;
    char nombre[30], id[30];
    int val;
    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar informacion del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el ID del producto:\n ");
                fflush(stdin);
                fgets(id, 30, stdin);

                printf("Ingrese el nombre del producto:\n ");
                fflush(stdin);
                fgets(nombre, 30, stdin);
                do
                {
                    printf("Ingrese la cantidad inicial en stock: ");
                    fflush(stdin);
                    val = scanf("%d", &stock);
                    if (val != 1)
                    {
                        printf("El valor ingresado es incorrecto, vuelva a ingresar\n");
                    }
                    if (stock < 1)
                    {
                        printf("El stock no puede ser negativo ni cero, vuelva a ingresar\n");
                    }
                } while (stock < 1 || val != 1);

                do
                {
                    printf("Ingrese el precio unitario del producto: ");
                    fflush(stdin);
                    val = scanf("%f", &precio);
                    if (val != 1)
                    {
                        printf("El valor ingresado es incorrecto, vuelva a ingresar\n");
                    }
                    if (precio < 1)
                    {
                        printf("El precio no puede ser negativo ni cero, vuelva a ingresar\n");
                    }
                } while (precio < 1 || val != 1);

                break;
                
            case 2:
                do
                {
                    printf("Ingrese la cantidad a vender: ");
                    fflush(stdin);
                    val = scanf("%d", &cantidad);
                    if (val != 1)
                    {
                        printf("El valor ingresado es incorrecto, vuelva a ingresar\n");
                    }
                    if (cantidad < 1)
                    {
                        printf("la cantidad no puede ser negativo ni cero, vuelva a ingresar\n");
                    }
                    if (cantidad > stock)
                    {
                        printf("No se puede realizar la venta, no existe suficiente stock, vuelva a ingresar\n");
                    }

                } while (cantidad < 1 || val != 1 || cantidad > stock);
                venta = cantidad * precio;
                printf("El valor de la venta es: %f\n", venta);
                stock -= cantidad;
                total_ganancias+=venta;

                break;

            case 3:
                do
                {
                    printf("Ingrese la cantidad a agregar al stock: ");
                    fflush(stdin);
                    val = scanf("%d", &cantidad);
                    if (val != 1)
                    {
                        printf("El valor ingresado es incorrecto, vuelva a ingresar\n");
                    }
                    if (cantidad < 1)
                    {
                        printf("la cantidad no puede ser negativo ni cero, vuelva a ingresar\n");
                    }
                } while (cantidad < 1 || val != 1);
                stock+=cantidad;
                
                break;

            case 4:
                printf("\nInformación del producto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 5:
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
