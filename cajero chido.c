#include <stdlib.h>
#include "ATM.h"

int main(){

    int option = 0, timer = 2, i=0, hrm2=0;
    float hrm1;
    int cuenta;

    struct cliente customer[3] = {
        {1, 1000.00, "Mario Alejandro", 1234},
        {2, 2000.00, "Karla Flores", 5678},
        {3, 3000.00, "Baruc Gutierrez", 9012}};

printf("Seleccione la Versión del programa:\n");
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
                        customer[cuenta].historial = customer[cuenta].saldo - hrm1  
                        printf("\nSu saldo actual es: %.2f\n\n", customer[cuenta].saldo);
                        printf("************************************************\n\n\n");
                        sleep(timer);
                        printf("                     ------\n\n\n");
                        break;
                    case 3: //Manda a llamar a la funcion de cambio y muestra el valor despues de haberlo cambiado
                        printf("*****            Retirar Dinero            *****");
                        hrm1 = customer[cuenta].saldo;
                        customer[cuenta].saldo = cambio(1, hrm1);
                        customer[cuenta].historial = customer[cuenta].saldo - hrm1
                        printf("\nSu saldo actual es: %.2f\n\n", customer[cuenta].saldo);
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
                    printf("*****        Supervisor del banco BBVA        *****\n\n");
                    printf("1.\t Buscar Usuario por nombre\n");
                    printf("2.\t Buscar historial del usuario \n");
                    scanf("%d", &option);
                    printf("\n************************************************\n\n\n");
            break;

        default:
            printf("\n\nopcion no valida\n\n");
            break;
    };





    return 0;
}
