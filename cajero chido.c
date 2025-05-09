#include <stdlib.h>
#include "ATM.h"

int main(){

    int option = 0, timer = 2, i=0, hrm2=0, z=0, opcion2=0;
    float hrm1;
    int cuenta;

    struct cliente customer[3] = {
        {1, 1000.00, "Mario Alejandro", 1234, Mexico},
        {2, 2000.00, "Karla Flores", 5678, Mexico},
        {3, 3000.00, "Baruc Gutierrez", 9012, Mexico}};

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
                        customer[cuenta].historial[z] = customer[cuenta].saldo - hrm1;  
                        z++;
                        printf("\nSu saldo actual es: %.2f\n\n", customer[cuenta].saldo);
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
                    printf("1.\t Crear cuenta\n");
                    printf("2.\t Buscar Usuario por nombre\n");
                    printf("3.\t Mostrar historial de usuario \n");
                    scanf("%d", &option1);
                    printf("\n************************************************\n\n\n");

                    switch(option1){
                        case 1:

                            break;
                        
                        case 2:
                            printf("Ingrese el numero del usuario del que quiere buscar su historial:");
                            scanf("%d", cuenta);
                            check (customer[cuenta].historial);
                            break;

                        case 3:

                            break;
                        
                        default:
                            
                            break;
                            
            break;

        default:
            printf("\n\nopcion no valida\n\n");
            break;

                        
    };


//Funcion para bsucar usuarios por nombres empieza aquí
                        //Parte afuera 
                        char nombres [3][40];
for (int i = 0; i < 3; i++) {
        strcpy(nombres[i], customer[i].nombre);
    }
 char IngresaUsuario[40];
 Bool flag =false;
            //Parte de adentro del switchcase
              printf("1.\t Buscar Usuario por nombre\n");
                    
                        fgets()(IngresaUsuario, sizeof(IngresaUsuario), stdin);
                    
                    for(i=0;i>3;i++){
                        
                        if (IngresaUsuario==nombres[i]){
                            printf(" Usuario existente");
                            flag = True;
                        } 
                    }
                    if(flag=false){
                            printf("Error, %s no es un usuario existente en el sistema\n",IngresaUsuario );} 
            //Fin de la funcion para buscar por nombres


    return 0;
}
