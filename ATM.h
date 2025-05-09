#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED

struct cliente {
    int nocliente;
    float saldo;
    char nombre[40];
    int nip;
};

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


//===Color font code===/
#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"

//===Color background code===/
#define BG_BLACK   "\x1B[40m"
#define BG_RED     "\x1B[41m"
#define BG_GREEN   "\x1B[42m"
#define BG_YELLOW  "\x1B[43m"
#define BG_BLUE    "\x1B[44m"
#define BG_MAGENTA "\x1B[45m"
#define BG_CYAN    "\x1B[46m"
#define BG_WHITE   "\x1B[47m"
#define BG_ORANGE  "\x1B[48;2;255;128;0m"
#define BG_LBLUE   "\x1B[48;2;53;149;240m"
#define BG_LGREEN  "\x1B[48;2;17;245;120m"
#define BG_GRAY    "\x1B[48;2;176;174;174m"
#define BG_ROSE    "\x1B[48;2;255;151;203m"

#endif // ATM_H_INCLUDED
