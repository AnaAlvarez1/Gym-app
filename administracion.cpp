#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"cuadro.h"

typedef char cadenaA[60];
typedef char cadenaD[20];
typedef char cadena[50];

struct horario
{
	int inicio;
	int fin;
	
};
struct registroActividades
{
	int legajo;
	cadenaA apeynom;
	cadenaA actividad;
	cadenaD dia;
    horario horarios;
	bool borrado;	
};


struct registroUsuarios
{
	char nombreUsuario[10];
	char contrasena[10];
	char apeynom[60] ;
	bool borrado;
};


int Menu();
void registroActividad(FILE *archi);
void listaDeActividades(FILE *archi);
void calculoDePago(FILE *archi, float valorXhora, float total, int contadorHoras);
void mayorCargaHoraria(FILE *archi);


main()
{
	registroActividades regi;
	
	int opcion=0,contador;

	float valorHora,total;
	
	FILE *archivo1;
	FILE *archivo2;
	
	archivo1 = fopen("Usuarios.dat","r+b"); //apertura de archivo que existe (lectura + escritura)
		
	
	    if(archivo1 == NULL)
	    {
	        archivo1 = fopen("Usuarios.dat","w+b"); //crea archivo, ya que no existe (y lo escribe) o  si existe, lo abre lo borra y lo deja vacio.
		
		        if(archivo1 == NULL)
		        {
		        	system("COLOR 47"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
				    dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO DEL TITULO

				    gotoxy (30,2); printf("\n\n Se produjo un ERROR al intentar abrir el archivo\n");
				    gotoxy (2,12); printf("comuniquese con el administrador del Sistema. Gracias");
				    gotoxy (2,13); system("PAUSE");
			        exit(1);
	        	}
	    }
	    
	archivo2 = fopen("BD.dat","r+b"); //apertura de archivo que existe (lectura + escritura)
	
	    if(archivo2 == NULL)
	    {
	        archivo2 = fopen("BD.dat","w+b"); //crea archivo, ya que no existe (y lo escribe) o  si existe, lo abre lo borra y lo deja vacio.
		
		        if(archivo2 == NULL)
		        {
		        	system("COLOR 47"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
				    dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO DEL TITULO

				    gotoxy (30,2); printf("\n\n Se produjo un ERROR al intentar abrir el archivo\n");
				    gotoxy (2,12); printf("comuniquese con el administrador del Sistema. Gracias");
				    gotoxy (2,13); system("PAUSE");
			        exit(1);

	        	}
	    }

	do
	{		
		system("cls");
		opcion=Menu();
		system("cls");
		
		switch(opcion)
		{
			case    1  :   {
				                system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
                            	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
                            	system("COLOR F0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
                             	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
                            	gotoxy(30,2); printf("INICIAR SESION");

				                break;
			               }
			case    2  :   {
				                system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
                            	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
                            	system("COLOR F0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
                             	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
                            	gotoxy(30,2); printf("REGISTRARSE");

			                	break;
		                   }
			case    3  :   {
				                system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
                            	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
                            	system("COLOR F0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
                             	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
                            	gotoxy(30,2); printf("REGISTRO DE ACTIVIDAD");
				                registroActividad(archivo2);

				                break;
			               }
			case    4  :   {
				                system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
                            	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
                            	system("COLOR F0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
                             	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
                            	gotoxy(30,2); printf("CALCULO DE PAGO");
				                calculoDePago(archivo2,valorHora,total,contador);

				                break;
			               }
			case    5  :   {
				                system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
                            	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
                            	system("COLOR F0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
                             	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
                            	gotoxy(30,2); printf("MAYOR CARGA HORARIA");
				                mayorCargaHoraria(archivo2);


				                break;
			               }
			case    6  :   {
				                listaDeActividades(archivo2);
				
			                	break;
		                	}
			case    0  :   {
				                system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
                            	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
                            	system("COLOR F0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
                             	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
                            	gotoxy(30,2); printf("CERRANDO PROGRAMA ...");
				          
				                system("PAUSE");

			                	break;
			               }
			default    :   {
				                system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
                            	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
                            	system("COLOR F0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
                             	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
                            	gotoxy(30,2); printf("\aERROR: OPCIÓN INCORRECTA");
				                system("PAUSE");

			                	break;
			                }
		};
		
		printf("\n\n");
		system("pause");
		
	}while(opcion!=0);	
	
	fclose(archivo1);
	fclose(archivo2);
}

int Menu()
{
	int opcion=0;
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
	system("COLOR F0"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
	dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(30,2); printf("MENU PRINCIPAL");
	gotoxy(2,5); printf("1)Iniciar Seccion.");
	gotoxy(2,6); printf("2)Registrar usuario de Recepcion.");
	gotoxy(2,7); printf("3)Registrar nueva Actividad del Gym.");
	gotoxy(2,8); printf("4)Calcular pago al entrenador.");
	gotoxy(2,9); printf("5)Entrenador con mayor carga horaria.");
    gotoxy(2,10); printf("6)Cronograma de actividades registradas");
	gotoxy(2,11); printf("0)Salir");
	gotoxy(2,12);printf("Ingrese una opcion: ");
	scanf("%d",&opcion);
	return (opcion);
	
	gotoxy (2,15); system("pause");	
}

void registroActividad(FILE *archi)
{
	registroActividades regi;
	
	int inicio,fin,legajo,opcion,comparacion;
	cadena nombre,dia,actividad;
	bool busqueda=false;
	
	
	
	gotoxy (2,5); printf("Por favor ingrese el n° de legajo del entrenador: \n");
    gotoxy (2,6); scanf("%d", &regi.legajo);
    gotoxy (2,7); system("pause");
    system("cls");
    
    while ( (regi.legajo < 0) || (regi.legajo > 1000) )
	{
		gotoxy (2,5); printf("Registro de actividad\n");
		gotoxy (2,6); printf("Error. El n° de legajo debe estar entre 1 y 999\n");
        gotoxy (2,7); printf("Por favor ingrese nuevamente el n° de legajo del entrenador: \n");
        gotoxy (2,8); scanf("%d", &regi.legajo);
        system("cls");
        
	}
	
    legajo=regi.legajo;
    

	gotoxy (2,5); printf("Por favor ingrese el nombre y apellido del entrenador: \n");
	_flushall();
    gotoxy (2,6); gets(regi.apeynom);
    strcpy(nombre,regi.apeynom);
    system("cls");

    gotoxy (2,5); printf("Por favor ingrese el dia de la actividad: ");
	_flushall();
    gotoxy (2,6); gets(regi.dia);
    strcpy(dia,regi.dia);
    system("cls");
    
    gotoxy (2,5); printf("Por favor ingrese la actividad: ");
	_flushall();
    gotoxy (2,6); gets(regi.actividad);
    strcpy(actividad,regi.actividad);
    system("cls");

	gotoxy (2,5); printf("Por favor ingrese el horario inicial: ");
	gotoxy (2,6); scanf("%d",&inicio);
	system("cls");
	
	gotoxy (2,5); printf("Por favor ingrese el horario final: ");
	gotoxy (2,6); scanf("%d",&fin);
	
	system("cls");
	
	
		// Paso 1 - Rebobinar el archivo
	rewind(archi);

	// Paso 2 - Intentar extraer el siguiente "dato" (variable simple o registro) del archivo
	fread(&regi, sizeof(regi), 1, archi);
	
	
	// Paso 3 - Mientras no sea FIN DE ARCHIVO (EOF)
	while (!feof(archi))
	{
		if((comparacion = strcmp(regi.apeynom,nombre))==0)
		{
			if((comparacion = strcmp(regi.dia,dia) == 0))
			{
				if((comparacion = strcmp(regi.actividad,actividad) == 0))
				{
	            	while( (regi.horarios.inicio<inicio) && (regi.horarios.fin<inicio))
	            	{
	            		regi.horarios.inicio=inicio;
	                    regi.horarios.fin=fin;
	    
	                    // Marcar el registro como "activo" por defecto
	                    regi.borrado = false;
	
                        // Volcar o escribir el registro al FINAL del archivo
                        fseek(archi,0,SEEK_END);
                        fwrite(&regi, sizeof(regi), 1, archi);
                            
                        gotoxy (2,5); printf("Actividad registrada con exito...");               
                        gotoxy (2,6); system("pause");
                        system("cls");	
					}
					while((regi.horarios.inicio>inicio) && (regi.horarios.fin>inicio))
					{
						regi.horarios.inicio=inicio;
	                    regi.horarios.fin=fin;
	    
	                    // Marcar el registro como "activo" por defecto
	                    regi.borrado = false;
	
                        // Volcar o escribir el registro al FINAL del archivo
                        fseek(archi,0,SEEK_END);
                        fwrite(&regi, sizeof(regi), 1, archi);
                            
                        gotoxy (2,5); printf("Actividad registrada con exito...");               
                        gotoxy (2,6); system("pause");
                        system("cls");
                        
					}
					while((regi.horarios.inicio==inicio) && (regi.horarios.fin==inicio) )
					{
						gotoxy (2,5); printf("El entrenador da otra actividad.");
                    	gotoxy (2,6); printf("Por favor digite 0 si quiere salir o 1 si quiere ingresar otro horario.");
                    	gotoxy (2,7); printf("Su opcion es: ");
                    	gotoxy (2,8); scanf("%d",&opcion);
                    	system("cls");
                        busqueda=true;
                            
                    	if(opcion == 0)
                        {
                       	    exit(0);
				        }
				        	
				        if(opcion==1)
				        {
					        rewind(archi);
					        fread(&regi, sizeof(regi), 1, archi);
					 
                        	    
				    		gotoxy (2,5); printf("Por favor ingrese el horario inicial: ");
	                        gotoxy (2,6); scanf("%d",&inicio);
	                        system("cls");
	             
	                        gotoxy (2,5); printf("Por favor ingrese el horario final: ");
                        	gotoxy (2,6); scanf("%d",&fin);
	                        system("cls");	
	                        busqueda=false;

				        }
						
					}
					while((regi.horarios.inicio<inicio) && (regi.horarios.fin>=fin) )
					{
						gotoxy (2,5); printf("El entrenador da otra actividad.");
                    	gotoxy (2,6); printf("Por favor digite 0 si quiere salir o 1 si quiere ingresar otro horario.");
                    	gotoxy (2,7); printf("Su opcion es: ");
                    	gotoxy (2,8); scanf("%d",&opcion);
                    	system("cls");
                        busqueda=true;
                            
                    	if(opcion == 0)
                        {
                       	    exit(0);
				        }
				        	
				        if(opcion==1)
				        {
					        rewind(archi);
					        fread(&regi, sizeof(regi), 1, archi);
					 
                        	    
				    		gotoxy (2,5); printf("Por favor ingrese el horario inicial: ");
	                        gotoxy (2,6); scanf("%d",&inicio);
	                        system("cls");
	             
	                        gotoxy (2,5); printf("Por favor ingrese el horario final: ");
                        	gotoxy (2,5); scanf("%d",&fin);
	                        system("cls");	
	                        busqueda=false;

				        }
						
					}
					while((regi.horarios.inicio>inicio) && (regi.horarios.fin>=fin) )
					{
						gotoxy (2,5); printf("El entrenador da otra actividad.");
                    	gotoxy (2,6); printf("Por favor digite 0 si quiere salir o 1 si quiere ingresar otro horario.");
                    	gotoxy (2,7); printf("Su opcion es: ");
                    	gotoxy (2,8); scanf("%d",&opcion);
                    	system("cls");
                        busqueda=true;
                            
                    	if(opcion == 0)
                        {
                       	    exit(0);
				        }
				        	
				        if(opcion==1)
				        {
					        rewind(archi);
					        fread(&regi, sizeof(regi), 1, archi);
					 
                        	    
				    		gotoxy (2,5); printf("Por favor ingrese el horario inicial: ");
	                        gotoxy (2,6); scanf("%d",&inicio);
	                        system("cls");
	             
	                        gotoxy (2,5); printf("Por favor ingrese el horario final: ");
                        	gotoxy (2,6); scanf("%d",&fin);
	                        system("cls");	
	                        busqueda=false;

				        }
					}
					while((regi.horarios.inicio>inicio) && (regi.horarios.fin<fin) )
					{
						gotoxy (2,5); printf("El entrenador da otra actividad.");
                    	gotoxy (2,6); printf("Por favor digite 0 si quiere salir o 1 si quiere ingresar otro horario.");
                    	gotoxy (2,7); printf("Su opcion es: ");
                    	gotoxy (2,8); scanf("%d",&opcion);
                    	system("cls");
                        busqueda=true;
                            
                    	if(opcion == 0)
                        {
                       	    exit(0);
				        }
				        	
				        if(opcion==1)
				        {
					        rewind(archi);
					        fread(&regi, sizeof(regi), 1, archi);
					 
                        	    
				    		gotoxy (2,5); printf("Por favor ingrese el horario inicial: ");
	                        gotoxy (2,6); scanf("\n %d",&inicio);
	                        system("cls");
	             
	                        gotoxy (2,5); printf("Por favor ingrese el horario final: ");
                        	gotoxy (2,5); scanf("%d",&fin);
	                        system("cls");	
	                        busqueda=false;

				        }
					}
	            	
				}
            }
        }
	}		
}

void listaDeActividades(FILE *archi)
{
	registroActividades regi;
	
	// Paso 1 - Rebobinar el archivo
	rewind(archi);

	// Paso 2 - Intentar extraer el siguiente "dato" (variable simple o registro) del archivo
	fread(&regi, sizeof(regi), 1, archi);
	
	
	// Paso 3 - Mientras no sea FIN DE ARCHIVO (EOF)
	while (!feof(archi))
	{
		// Paso 4 - Procesar el dato actual
		
		if (regi.borrado == false)
		{
			printf("\n\n\nLegajo: %d", regi.legajo);
			printf("\nEntrenador: %s", regi.apeynom);
			printf("\nDia : %s", regi.dia);
			printf("\nActividad: %s", regi.actividad);
			printf("\nHorario inicial: %d", regi.horarios.inicio);
			printf("\nHorario final: %d", regi.horarios.fin);
		}
		
		// Paso 5 - Intentar extraer el siguiente dato o registro
		fread(&regi, sizeof(regi), 1, archi);
	} 
}

void calculoDePago(FILE *archi,float valorXhora,float total,int contadorHoras)
{
	registroActividades regi;
	char nombre[50];

	
	valorXhora=0.0;
	total=0.0;
	contadorHoras=0;
	int inicio=0,final=0,comparacion=0;


	gotoxy (2,5); printf("Por favor ingrese el nombre del entrenador: \n");
	_flushall();
    gotoxy (2,6); gets(nombre);
    system("cls");
    
  
    gotoxy (2,5); printf("Por favor ingrese el valor por hora del entrenador: \n");
	gotoxy (2,6); scanf("%f",&valorXhora);
    system("cls");
    
    // Rebobinar el archivo - Poner el puntero del archivo al principio
	rewind(archi);
    
    fread(&regi, sizeof(regi), 1, archi);
    
	while (!feof(archi))
	{
		if (regi.borrado == false)
		{
			if((comparacion = strcmp(regi.apeynom,nombre)) == 0)
			{
				inicio=regi.horarios.inicio;
			    final=regi.horarios.fin;
			
			    for(int i=inicio;i<=final;i++)
			    {
			        contadorHoras = contadorHoras+1;	
			    } 
				fread(&regi, sizeof(regi), 1, archi);	
		 	}
		 	if((comparacion = strcmp(regi.apeynom,nombre)) != 0)
		 	{
		 	    fread(&regi, sizeof(regi), 1, archi);
			}
		}	
	}
	if(contadorHoras==0)
	{
	   
    	gotoxy (2,5); printf("El entrenador no se encuentra registrado\n");
    	system("cls");
    	exit(1);
	}
	
	if(contadorHoras!=0)
	{
		total=valorXhora*contadorHoras;
		
        gotoxy (2,5); printf("El monto total a pagar por las horas trabajadas es $ %0.2f",total);
	}
}

void mayorCargaHoraria(FILE *archi)
{
	registroActividades regi;
	
	cadena entrenadores[50];
	int posicion=0,m=0, horasDeTrabajo[50], contadorHoras=0, comparacion, inicio, fin,horas=0, mayor=0,i=0;
	bool busqueda = false;
	char nombre[50];
	
	// Rebobinar el archivo - Poner el puntero del archivo al principio
	rewind(archi);
    fread(&regi, sizeof(regi), 1, archi);
    strcpy(entrenadores[posicion],regi.apeynom);
    horasDeTrabajo[posicion]=0;
    
    
    while (!feof(archi))
    {
    	if (regi.borrado == false)
    	{
    		if((comparacion = strcmp(regi.apeynom,entrenadores[posicion]))== 0)
    		{
    			horas=0;
    			contadorHoras=0;
    			inicio=regi.horarios.inicio;
    			fin=regi.horarios.fin;
    	
    			
    			for(m=inicio;m<fin;m++)
    			{
    				contadorHoras=contadorHoras+1;
    			
    				
				}
				
				horas=horasDeTrabajo[posicion];
		
				horas=horas+contadorHoras;
				horasDeTrabajo[posicion]= horas;
			
				
				fread(&regi, sizeof(regi), 1, archi);
				
			}
    		if((comparacion = strcmp(regi.apeynom,entrenadores[posicion])) != 0)
    		{
    			for(m=0;m<=posicion;m++)
    			{
    				if((comparacion = strcmp(regi.apeynom,entrenadores[m]))== 0)
    				{
    					horas=0;
    					contadorHoras=0;
    		        	inicio=regi.horarios.inicio;
    		        	fin=regi.horarios.fin;
    		        
    			
    	        		for(i=inicio;i<fin;i++)
    	         		{
    		        		contadorHoras=contadorHoras+1;
    		        
    		        		
			        	}
			        	
				        horas=horasDeTrabajo[m];
				    
			        	horas=horas+contadorHoras;
			        	horasDeTrabajo[m]= horas;
			        
			          	
			        	busqueda = true;
			        	m=posicion;
					}
				}
				
				if(busqueda == false)
				{
					posicion++;
					strcpy(entrenadores[posicion],regi.apeynom);
					horas=0;
					contadorHoras=0;
    		    	inicio=regi.horarios.inicio;
    		    	fin=regi.horarios.fin;
    		    	
    			
    	    		for(m=inicio;m<fin;m++)
    		    	{
    	    			contadorHoras=contadorHoras+1;
    	    		
		    		}
			      	
		    		horasDeTrabajo[posicion]=contadorHoras;	
				
		    		fread(&regi, sizeof(regi), 1, archi);
				}
				
				if(busqueda == true)
				{
					fread(&regi, sizeof(regi), 1, archi);
				}
			}
		}	
	}
	for(m=0;m<=posicion;m++)
	{
	
		if(mayor<horasDeTrabajo[m])
		{
			mayor=horasDeTrabajo[m];
			strcpy(nombre,entrenadores[m]);
		}
	}
	
	gotoxy(2,5); printf("La mayor carga horaria es para el entrenador %s.",nombre);
	gotoxy(2,6); printf("Tiene una carga horaria de %d hs",mayor);
}
