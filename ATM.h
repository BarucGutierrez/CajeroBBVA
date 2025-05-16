#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED

struct cliente {
    int nocliente;
    float saldo;
    char nombre[40];
    int nip;
    char pais[50];
    float historial[10];
};

int check(float historial2[10]){
    int i;
    for (i = 0; i<10; i++){
        if (historial2[i] >= 0){
    printf("Se hizo el deposito de esta cantidad: %f\n",historial2[i]);
        }else printf("Se hizo el retiro de esta cantidad: %f\n",historial2[i]);{

        }
  }
    return 0;
}

//Función para validar la contraseña del usuario.
int login(struct cliente c1, struct cliente c2, struct cliente c3){
    int i=0, attemp=0;

    for(i=3; i>0; i--){
        printf("Ingrese su pin numerico (tiene %d intentos): ", i);
        scanf("%d", &attemp);

        if(attemp == c1.nip){
            printf("\n");
            return 0;
        }else{
            if(attemp == c2.nip){
            printf("\n");
            return 1;
            }else{
                if(attemp == c3.nip){
                printf("\n");
                return 2;
                }else{
                    printf("\n--- Constrasena incorrecta ---\n\n");
                }
            }
        }
    }
    printf("\n\n\n\n\n************   Demasiados intentos fallidos   ************\n\n\n\n\n");
exit(0);
}


int logincuenta(int hrm4){
    if((hrm4==1)||(hrm4==2)||(hrm4==3)){
        return 1;
    }else{
        printf("\t--- opcion no valida ---\n\n");
        return 0;
    }
}

//Funcion que comprueba si los datos ingresados por el usuario son validos.
//Funciona tanto para el deposito (suma) como para el retiro (resta)
int comprobacion(int operacion, float hrm2, float balance){
        switch(operacion){
        case 1:     //Comprobación para el retiro
            if((balance>=hrm2)&&(hrm2>0)){
                return 1;
            }else{
                return 0;
            }
            break;
        case 0:     //Comprobacion para el deposito
            if(hrm2>0){
                return 1;
            }else{
                return 0;
            }
        }
    }

//Funcion encargada del cambio de valores en la variable global saldo
//Funciona para el deposito y también para el retiro
float cambio(int opcion, float saldo){

    float hrm1=0.0;
    int hrm3;

    if(opcion == 0){    //Proceso del deposito
        do{
            printf("\n\nSu saldo acutal es: %.2f\n", saldo);
            printf("La cantidad a depositar: ");
            scanf("%f", &hrm1);

            hrm3 = comprobacion(opcion,hrm1,saldo);   //Se mandan a verificar los valores

                if(hrm3){
                    saldo = saldo + hrm1;
                }else{
                    printf("\n--- cantidad no valida ---");
                }

        }while(hrm3!=1);    //Do-While para repetir el proceso hasta obtener una cantidad valida
    }

    if(opcion == 1){    //Proceso del retiro

        do{
            printf("\n\nSu saldo acutal es: %.2f\n", saldo);
            printf("La cantidad a retirar: ");
            scanf("%f", &hrm1);

            hrm3 = comprobacion(opcion,hrm1,saldo);   //Se mandan a verificar los valores

            if(hrm3){
                saldo = saldo - hrm1;
            }else{
                printf("\n--- cantidad no valida ---");
            }

        }while(hrm3!=1);    //Do-While para repetir el proceso hasta obtener una cantidad valida

    }

return saldo;   //Se regresa el valor de la variable global saldo
}
// Funcion para buscar usuario por nombre

void mostrar(struct cliente c1){
    printf("Cuenta %d\n\n", c1.nocliente);
    printf("No. Cliente:\t\t %d\n", c1.nocliente);
    printf("Nombre del dueño:\t %s\n", c1.nombre);
    printf("Pais del dueño:\t\t %s\n", c1.pais);
    printf("Nip de la cuenta:\t %d\n", c1.nip);
    printf("historial de la cuenta:\n");
    check(c1.historial);
    printf("\n\n");

}

void guardar_clientes(struct cliente *clientes, int numClientes) {
    FILE *archivo = fopen("clientes.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar los clientes.\n");
        return;
    }

    for (int i = 0; i < numClientes; i++) {
    fprintf(archivo, "NoCliente: %d\n", clientes->nocliente);
    fprintf(archivo, "Nombre: %s\n", clientes->nombre);
    fprintf(archivo, "NIP: %d\n", clientes->nip);
    fprintf(archivo, "Saldo: %.2f\n", clientes->saldo);
    fprintf(archivo, "Pais: %s\n", clientes->pais);
    fprintf(archivo, "Historial: ");

    for (int i = 0; i < 10; i++) {
        fprintf(archivo, "%.2f ", clientes->historial[i]);
    }

    fprintf(archivo, "\n-----------------------------\n");
    }

    fclose(archivo);
}

#endif // ATM_H_INCLUDED
