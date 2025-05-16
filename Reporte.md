# **Reporte**

***Profesor:*** Jorge Ernesto Lopez Arce Delgado

***Integrantes:***  
Karla Sofía Flores Jiménez  
Baruc Shemuel Gutierrez Fuentes  
Emiliano Barba Navarro  
  
  

## **Guía de Instalación**
**Requisitos previos para que compile el código**  
1. Un sistema operativo compatible (Linux, macOS o Windows con WSL)
2. Descarga o clona el repositorio del código
    -  git clone
3. Ubica los archivos fuente del programa (.c y .h), y el archivo .atm si es necesario.
4. Compila el programa usando gcc
5.  Ejecutar el programa para saber si funciona





## **Guía de Usuario**  
Al acceder al programa el primer menú que aparece da las opciones de usuario o administrador.    
### **Al ser cliente puedes:**    
- *Depositar y retirar dinero.*
    + Escribes la cantidad que deseas agregar o retirar.            
- *Consultar saldo.*
    + Después de algún movimineto puedes asegurarte de que fue correcto.  
- *Salir.*
    + Sales del programa.  
### **Al ser Administrador puedes:**  
- *Crear una cuenta nueva para acceder como usuario.*
    + Te pide tu nombre, país de origen, NIP y saldo inicial

- *Buscar a un Usuario.*
    + Te pide tu numero de usuario

- *Historial de Usuario*
    + Muestra el historial del usuario que se requiere (Se busca con el numero de usuario)

- *Mostrar todas las cuentas registradas.*
- *Salir.*
  
### **Capacidades:**
- Agregar mas usuarios  
- Ver los movimientos de los usuarios
- Guarda los valores en un archivo txt
- El programa recibe datos de un archivo txt

### **Limitaciones:**  
- No admite cantitades extremadamente grandes


## **Explicación/descripción** 
Para hablar más sobre las cuentas debemos de separarlas en 2 partes características y acciones; de forma simple las características son los tipos de datos que contiene el programa ej. int, char etc… , las acciones por su lado se refiere a lo que se puede realizar también conocido como funciones.  

### **Características**
- int (enteros), el programa usa enteros para guardar datos como el contador o la cuenta.
- float (flotantes), en el programa se utilizaron para “hrm1” que es el saldo de las cuentas
- char (carácter), que fue utilizado para crear cadenas de caracteres (strings) como por ejemplo  en : char IngresaUsuario[50]; que sirve para guardar los nombres de los usuarios.
- struct (estructura), en el código las struct fueron usadas para representar los clientes y sus datos.
- void, se utilizó para funciones de las cuales no se esperaba que dieran algún dato, por ejemplo en guardar_clientes 
### **Acciones**
- **Cliente**
  + Consultar saldo, en el que se accede y se muestra el saldo disponible y no regresa nada nuevo.
  + Depositar saldo, el cual actualiza y guarda cambios positivos realizados al saldo y los muestra en pantalla, este devuelve Saldo nuevo (float) y se involucra con cambio() + guardar_clientes()
  + Retirar dinero, el cual también actualiza y guarda cambios realizados en el saldo, pero en esta ocasión solo negativos, devuelve Saldo nuevo (float) y se involucra con cambio() + guardar_clientes()
  + Salir, que lo único que hace es salir del loop

- **Administrador**
  + Crear cuenta, agrega nuevo cliente y sus datos, el cúal no regresa ningún dato y se involucra con (Directo, realloc + guardar_clientes())
  + Buscar usuario por nombre, el cual busca usuarios y muestra sus datos y se involucra con mostrar().
  + Mostrar historial de usuario, el cual muestra las últimas actividades realizadas en una cuenta específica y se involucra con check()
  + Mostrar todas las cuentas, que como dice muestra todas las cuentas que se encuentran registradas y se involucra con mostrar()
  + Salir, que lo único que hace es salir del loop


