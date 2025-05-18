#include <stdlib.h>
#include <stdio.h>
#include "ATM.h"


int main(){

    int option = 0, timer = 5, i=0,j=0, hrm2=0, z=0, option1=0,opcion2=0, capacidad = 3, timer1=1, hrm0, attemp, hrm3=0;
    float hrm1;
    int cuenta;
    char IngresaUsuario[50], trash[50];
    int flag =0;

struct cliente *customer = NULL;

int numClientes = 3;

customer = malloc(numClientes * sizeof(struct cliente));

//****************************************
FILE *archivo1 = fopen("clientes.txt", "r");

if (archivo1 == NULL) {
    printf("Error al abrir el archivo.\n");
    return;
}

for (i = 0; i < numClientes; i++) {

    fscanf(archivo1, "%d\n", &customer[i].nocliente);
    fscanf(archivo1, "%[^\n]\n", customer[i].nombre);
    fscanf(archivo1, "%d\n", &customer[i].nip);
    fscanf(archivo1, "%f\n", &customer[i].saldo);
    fscanf(archivo1, "%[^\n]\n", customer[i].pais);


    for (int j = 0; j < 10; j++) {
        if (fscanf(archivo1, "%f\n", &customer[i].historial[j]) != 1) {
            customer[i].historial[j] = 0.0;
        }
    }
}


fclose(archivo1);
//*****************************************

char nombres[100][50];
for(i=0;i<20;i++){
    strcpy(nombres[i], customer[i].nombre);
}

fflush(stdin);

do{
printf("************************************************\n\n");
printf("Seleccione la Version del programa:\n");
printf("1.\t Usuario\n");
printf("2.\t Administrador\n");
printf("\nSeleccione una opcion:\t");
scanf("%d", &hrm2);
printf("\n************************************************\n\n\n");
sleep(timer1);  LimpiarPantalla();

    switch(hrm2){
        case 1:
            hrm3=1;

            cuenta=100;
            for(i=3;i>0;i--){
            printf("Ingrese su pin numerico (tiene %d intentos): ", i);
            scanf("%d", &attemp);

                for(j=0;j<numClientes;j++){
                     if(attemp == customer[j].nip){
                        cuenta = j;
                        i=0;
                    }
                }
                if(cuenta == 100){
                     printf("\n\t--- PIN incorrecto ---\n\n");
                }
            }

            if(cuenta == 100){
                printf("\n\n*******Demasiados intentos fallidos*******\n\n");
                exit(0);
            }

                do{
                    LimpiarPantalla();
                    printf("*****        Cajero Automatico BBVA        *****\n\n");
                    printf("No. Cliente:\t%d\n", customer[cuenta].nocliente);
                    printf("Nombre:\t\t%s\n\n", customer[cuenta].nombre);
                    printf("1.\t Consultar saldo\n");
                    printf("2.\t Depositar dinero\n");
                    printf("3.\t Retirar dinero\n");
                    printf("4.\t Salir\n");
                    printf("\nSeleccione una opcion:\t");
                    scanf("%d", &option);
                    printf("\n************************************************\n\n\n");
                    sleep(timer1);  LimpiarPantalla();


                    switch(option){
                    case 1: //Muestra el saldo en pantalla
                        printf("*****           Consultar Saldo            *****");
                        printf("\n\nSu saldo es: %.2f\n\n", customer[cuenta].saldo);
                        printf("************************************************\n\n\n");
                        sleep(timer);  LimpiarPantalla();

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
                        sleep(timer);   LimpiarPantalla();

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
                        sleep(timer);   LimpiarPantalla();
                        break;
                    case 4: //Da el mensaje de salida
                        printf("*****                Salida                *****");
                        printf("\n\n\n\tGracias por usar nuestro cajero BBVA\n\n\n");
                        printf("************************************************\n\n\n");
                        break;
                    default:    //Mensaje si la opcion no existe
                        printf("************************************************");
                        printf("\n\tOpcion no valida\n");
                        printf("************************************************\n\n\n");
                        sleep(timer - 4);   LimpiarPantalla();
                        break;
                    }

                }while(option != 4); //Do-While para repetir el proceso hasta que se ingrese una opcion valida
            break;

        case 2:
                hrm3=1;
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
                    sleep(timer1);  LimpiarPantalla();

                    switch(option1){
                        case 1:
                            printf("*****             Crear Cuenta             *****\n");
                            numClientes++;
                            capacidad++;
                            customer = realloc(customer, numClientes * sizeof(struct cliente));
                            if (customer == NULL) {
                                printf("Error al asignar memoria\n");
                                break;
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

                            strcpy(nombres[numClientes - 1], customer[numClientes - 1].nombre);

                            printf("\nCuenta creada exitosamente con numero de cliente: %d\n\n", customer[numClientes - 1].nocliente);
                            printf("************************************************\n\n\n");
                            sleep(timer);  LimpiarPantalla();

                            break;


                        case 2:
                            fflush(stdin);
                            printf("*****            Buscar Usuario            *****\n");

                            printf("Ingrese el nombre del usuario que quiere buscar: ");
                            fgets(IngresaUsuario, sizeof(IngresaUsuario), stdin);

                            IngresaUsuario[strcspn(IngresaUsuario, "\n")] = '\0';

                            flag = 0;

                            for(i = 0; i < numClientes; i++) {
                                if ((strcmp(IngresaUsuario, nombres[i])) == 0) {
                                    mostrar(customer[i]);
                                    printf("************************************************");
                                    sleep(timer + 3);  LimpiarPantalla();
                                    flag = 1;
                                }
                            }



                              if(flag == 0) {
                                printf("\n\tError\n\n%s no es un usuario existente en el sistema\n", IngresaUsuario);
                                printf("************************************************");
                                sleep(timer);  LimpiarPantalla();
                            }

                            break;

                        case 3:
                            printf("*****           Buscar Historial           *****\n");

                            printf("Ingrese el numero del usuario del que quiere buscar su historial:");
                            scanf("%d", &cuenta);
                            check (customer[numClientes - 1].historial);
                            printf("************************************************");
                            sleep(timer + 2);  LimpiarPantalla();
                            break;

                        case 4:
                            printf("*****            Mostrar Usuarios           *****\n");
                            for(i=0; i < capacidad; i++){
                                mostrar(customer[i]);
                            }
                            printf("Para volver al menu ingrese (y): ");
                            scanf("%s",trash);
                            printf("\n************************************************");
                            sleep(timer-2);  LimpiarPantalla();

                            break;

                        case 5:
                            printf("*****                Salida                *****");
                            printf("\n\n\n\tGracias administrador BBVA\n\n\n");
                            printf("************************************************\n\n\n");
                        break;

                        default:
                            printf("************************************************");
                            printf("\n\tOpcion no valida\n");
                            printf("************************************************\n\n\n");
                            sleep(timer - 4);   LimpiarPantalla();
                            break;


                        }

                    }while(option1 != 5);
            break;

        default:
            printf("************************************************");
            printf("\n\tOpcion no valida\n");
            printf("************************************************\n\n\n");
            sleep(timer - 4);   LimpiarPantalla();
            break;
    };
}while(hrm3!=1);

//****************************************
    FILE *archivo = fopen("clientes.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar los clientes.\n");
        return;
    }

    for (i = 0; i < numClientes; i++) {
    fprintf(archivo, "%d\n", customer[i].nocliente);
    fprintf(archivo, "%s\n", customer[i].nombre);
    fprintf(archivo, "%d\n", customer[i].nip);
    fprintf(archivo, "%.2f\n", customer[i].saldo);
    fprintf(archivo, "%s\n", customer[i].pais);

    for(j=0;j<10;j++){
        fprintf(archivo, "%f\n", customer[i].historial[j]);
    }

    }
    fclose(archivo);
//*****************************************

    return 0;
}
