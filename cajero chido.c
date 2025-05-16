#include <stdlib.h>
#include <stdio.h>
#include "ATM.h"


int main(){

    int option = 0, timer = 2, i=0, hrm2=0, z=0, option1=0,opcion2=0, capacidad = 3;
    float hrm1;
    int cuenta;
    char IngresaUsuario[50];
    int flag;

struct cliente *customer = NULL;
int numClientes = 3;

customer = malloc(numClientes * sizeof(struct cliente));

customer[0] = (struct cliente){1, 1000.00, "Mario Alejandro", 1234, "Mexico", {0,0,0,0,0,0,0,0,0,0}};
customer[1] = (struct cliente){2, 2000.00, "Karla Flores", 5678, "Mexico", {0,0,0,0,0,0,0,0,0,0}};
customer[2] = (struct cliente){3, 3000.00, "Baruc Gutierrez", 9012, "Mexico", {0,0,0,0,0,0,0,0,0,0}};

char nombres[3][40];
for(i=0;i<3;i++){
    strcpy(nombres[i], customer[i].nombre);
}

fflush(stdin);

for(i=0; i<numClientes;i++){
    guardar_clientes(&customer[i], numClientes);
}

printf("Seleccione la Version del programa:\n");
printf("1.\t Usuario\n");
printf("2.\t Administrador\n");
scanf("%d", &hrm2);

    switch(hrm2){
        case 1:


                 cuenta = login(customer[0], customer[1], customer[2]);    //Llamado de la función encargada de la verificación de la contraseña

                do{
                    printf("*****        Cajero Automatico BBVA        *****\n\n");
                    printf("1.\t Consultar saldo\n");
                    printf("2.\t Depositar dinero\n");
                    printf("3.\t Retirar dinero\n");
                    printf("4.\t Salir\n");
                    printf("\nSeleccione una opcion:\t");
                    scanf("%d", &option);
                    printf("\n************************************************\n\n\n");

                    switch(option){
                    case 1: //Muestra el saldo en pantalla
                        printf("*****           Consultar Saldo            *****");
                        printf("\n\nSu saldo es: %.2f\n\n", customer[cuenta].saldo);
                        printf("************************************************\n\n\n");
                        sleep(timer);
                        printf("                     ------\n\n\n");
                        break;
                    case 2: //Manda a llamar a la funcion de cambio y muestra el valor despues de haberlo cambiado
                        printf("*****           Depositar Dinero           *****");
                        hrm1 = customer[cuenta].saldo;
                        customer[cuenta].saldo = cambio(0, hrm1);
                        customer[cuenta].historial[z] = customer[cuenta].saldo - hrm1;
                        z++;
                        printf("\nSu saldo actual es: %.2f\n\n", customer[cuenta].saldo);
                        guardar_clientes(&customer[cuenta], numClientes);
                        printf("************************************************\n\n\n");
                        sleep(timer);
                        printf("                     ------\n\n\n");
                        break;
                    case 3: //Manda a llamar a la funcion de cambio y muestra el valor despues de haberlo cambiado
                        printf("*****            Retirar Dinero            *****");
                        hrm1 = customer[cuenta].saldo;
                        customer[cuenta].saldo = cambio(1, hrm1);
                        customer[cuenta].historial[z] = customer[cuenta].saldo - hrm1;
                        z++;
                        printf("\nSu saldo actual es: %.2f\n\n", customer[cuenta].saldo);
                        guardar_clientes(&customer[cuenta], numClientes);
                        printf("************************************************\n\n\n");
                        sleep(timer);
                        printf("                     ------\n\n\n");
                        break;
                    case 4: //Da el mensaje de salida
                        printf("*****                Salida                *****");
                        printf("\n\n\n\tGracias por usar nuestro cajero BBVA\n\n\n");
                        printf("************************************************\n\n\n");
                        sleep(timer);
                        break;
                    default:    //Mensaje si la opcion no existe
                        printf("                     ------\n\n\n");
                        printf("************************************************");
                        printf("\n\tOpcion no valida\n");
                        printf("************************************************\n\n\n");
                        sleep(timer);
                        printf("                     ------\n\n\n");
                        break;
                    }

                }while(option != 4); //Do-While para repetir el proceso hasta que se ingrese una opcion valida
            break;

        case 2:

                    do{
                    printf("*****        Supervisor del banco BBVA        *****\n\n");
                    printf("1.\t Crear cuenta\n");
                    printf("2.\t Buscar Usuario por nombre\n");
                    printf("3.\t Mostrar historial de usuario \n");
                    printf("4.\t Mostrar todas las cuentas \n");
                    printf("5.\t Salir\n");
                    printf("\nSeleccione una opcion:\t");
                    scanf("%d", &option1);
                    printf("\n************************************************\n\n\n");

                    switch(option1){
                        case 1:
                            numClientes++;
                            capacidad++;
                            customer = realloc(customer, numClientes * sizeof(struct cliente));
                            if (customer == NULL) {
                                printf("Error al asignar memoria\n");
                                exit(1);
                            }

                            printf("Ingrese el nombre: ");
                            scanf(" %[^\n]", customer[numClientes - 1].nombre);

                            printf("Ingrese el pais: ");
                            scanf(" %[^\n]", customer[numClientes - 1].pais);


                            printf("Ingrese el NIP: ");
                            scanf("%d", &customer[numClientes - 1].nip);

                            printf("Ingrese el saldo inicial: ");
                            scanf("%f", &customer[numClientes - 1].saldo);

                            for(i=0; i<10;i++){
                                customer[numClientes - 1].historial[i] = 0;
                            }

                            customer[numClientes - 1].nocliente = numClientes;

                            guardar_clientes(&customer[numClientes - 1], numClientes);

                            printf("Cuenta creada exitosamente con número de cliente: %d\n\n\n", customer[numClientes - 1].nocliente);
                            break;


                        case 2:
                            printf("Ingrese el nombre del usuario que quiere buscar: ");
                            scanf("%s", &IngresaUsuario);

                            for(i = 0; i < numClientes; i++) {
                                if ((strcmp(IngresaUsuario, nombres[i])) == 0) {
                                    printf("Usuario existente\n");
                                    mostrar(customer[i]);
                                    flag = 1;
                                }
                            }


                              if(flag == 0) {
                                printf("Error, %s no es un usuario existente en el sistema\n", IngresaUsuario);
                            }

                            printf("\n\n");

                            break;

                        case 3:
                            printf("Ingrese el numero del usuario del que quiere buscar su historial:");
                            scanf("%d", &cuenta);
                            check (customer[numClientes - 1].historial);
                            break;

                        case 4:
                            for(i=0; i < capacidad; i++){
                                mostrar(customer[i]);
                            }
                            break;

                        case 5:
                            printf("*****                Salida                *****");
                            printf("\n\n\n\tGracias por usar nuestro cajero BBVA\n\n\n");
                            printf("************************************************\n\n\n");
                            sleep(timer);
                        break;

                        default:
                            printf("                     ------\n\n\n");
                            printf("************************************************");
                            printf("\n\tOpcion no valida\n");
                            printf("************************************************\n\n\n");
                            sleep(timer);
                            printf("                     ------\n\n\n");
                            break;


                        }

                    }while(option1 != 5);
            break;

        default:
            printf("\n\nopcion no valida\n\n");
            break;
    };





    return 0;
}
