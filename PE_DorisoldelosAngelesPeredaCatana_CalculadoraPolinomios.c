#include <stdio.h>
#include <stdlib.h>
#define borde 90

char lineas(int n);
void men_inicio(int n);
void men_final(int n);
void mensaje_menu();
int evaluar_menu();
int term_F();
int term_G();
int leer_datos(float *m, int *n, int tam, int i);
void menu();
void mostrar_poli(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2);
void imprimir_pol(float *m, int *n, int tam);
void ordenar_poli(float *m,int *n, int tam);
int suma1(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2);
int aux_sum(float *m, int *n, int tam);
int resta(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2);
int mult(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2);
int cont_dif(int may, int men, int *n);
int division(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2);
int quitar_div(float *m, int *n, int tam);
void imp_arc(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2);
void aux_ar(FILE *a, float *m, int *n, int tam);

int main(int argc, char const *argv[])
{
	men_inicio(borde);
	menu();
	men_final(borde);
	return 0;
}

char lineas(int n)    //FUNCION PARA MOSTRAR LINEAS (CON RECURSION)
{
	if(n<1)
	{
		return n;
	}
	else
	{
		printf("*");
		return lineas(n-1);
	}
}


void men_inicio(int n)
{
	system("cls");
	printf("\n");
	printf("\t\t");
	lineas(n);
	printf("\n\n\n\t\t\t\t\tBIENVENIDO A LA CALCULADORA DE POLINOMIOS\n\n\n");
	printf("\t\t");
	lineas(n);
	printf("\n\n\t\tIndicaciones: ");
	printf("\n\n\t\t1. Para realizar cualquier operaci%cn, primero debe ingresar sus polinomios ",162);
	printf("\n\n\t\t2. Para ingresar sus polinomios, primero debe  ingresar la cantidad de t%crminos ",130);
	printf("\n\n\t\t3. Para escribir un t%crmino independiente, debe escribir un 0 como exponente ",130);
	printf("\n\n\n\t\t PULSA ENTER PARA CONTINUAR...");
	getchar();
}

void men_final(int n)
{
	system("cls");
	printf("\t\t");
	lineas(n);
	printf("\n\n\n\t\t\t\t\t%c GRACIAS POR USAR LA CALCULADORA !",173);
	printf("\n\n\t\t\t\t\t\t\tBYE :D\n\n\n");
	printf("\t\t");
	lineas(n);
	printf("\n");
}

void mensaje_menu()
{
	printf("\n\t\t ----------------------------------- MENU ------------------------------------\n");
	printf("\n\t\t1. Capturar datos");
	printf("\n\t\t2. Suma de polinomios");
	printf("\n\t\t3. Resta de polinomios");
	printf("\n\t\t4. Multiplicaci%cn de polinomios",162);
	printf("\n\t\t5. Divisi%cn de polinomios",162);
	printf("\n\t\t6. Imprimir ejercicios");
	printf("\n\t\t7. Salir\n");
	printf("\n\t\t   Ingrese su opci%cn: ",162);

}

int evaluar_menu()      //LEE OPCIONES DEL MENU
{
	int op;
	scanf("%d", &op);
	return op;
}

int term_F()           //PIDE CUANTOS TERMINOS EL TENDRA POLINOMIO F 
{
	int F;
	scanf("%d", &F);
	return F;
}


int term_G()           //PIDE CUANTOS TERMINOS EL TENDRA POLINOMIO G
{
	int G;
	scanf("%d", &G);
	return G;
}

int leer_datos(float *m, int *n, int tam, int i)     //FUNCION PARA INGRESAR LOS DATOS (CON RECURSION)
{
	if(i<tam)
	{
		printf("\n\t\tT%crmino %d ", 130,i+1);
		printf("\n\t\tCoeficiente: ");
		scanf("%f", &*(m+i));
		printf("\t\tExponente: ");
		scanf("%d", &*(n+i));
		i++;
		leer_datos(m,n,tam,i);
	}

	return 0;
}

void menu()                                          //FUNCION PARA USAR EL MENU
{
	int op_menu;
	int terminoF, terminoG;
	int s=0;                        //interruptor para verificar si hay datos o no
	do
	{
		system("cls");
		mensaje_menu();
		op_menu=evaluar_menu(op_menu);

		switch(op_menu)
		{
			case 1:                                          //CASO 1: INGRESO DE VALORES
				system("cls");
				printf("\n\t\tIngrese cantidad de t%crminos en F(x): ",130);
				terminoF=term_F(); 
				printf("\t\tIngrese cantidad de t%crminos en G(x): ",130);
				terminoG=term_G();  

				float *ko_PolF=NULL;        //arreglo para coeficiente y exponente del polinomio A
				int *exp_PolF=NULL;
				float *ko_PolG=NULL;        //arreglo para coeficiente y exponente del polinomio B
				int *exp_PolG=NULL;

				ko_PolF=(float*)calloc(terminoF, sizeof(float));      //ASIGNACION DE MEMORIA PARA F(x)
				exp_PolF=(int*)calloc(terminoF, sizeof(int));
				ko_PolG=(float*)calloc(terminoG, sizeof(float));      //ASIGNACION DE MEMORIA PARA G(x)
				exp_PolG=(int*)calloc(terminoG, sizeof(int));

				if(ko_PolF==NULL || exp_PolF==NULL || ko_PolG==NULL || exp_PolG==NULL)  //NOTIFICAR SI HAY ALGUN ERROR EN LA ASIGNACION DE MEMORIA 
				{
					printf("\nError!");
					exit(1);
				}
				
				printf("\n\t\tPara F(x)\n");
				leer_datos(ko_PolF, exp_PolF, terminoF,0);
				system("cls");

				printf("\n\t\tPara G(x)\n");
				leer_datos(ko_PolG, exp_PolG, terminoG,0);
	
				system("cls");
				printf("\n\t\tLos polinomios ingresados fueron: ");
				printf("\n\t\tF(x): ");
				imprimir_pol(ko_PolF,exp_PolF,terminoF);
				printf("\n\t\tG(x): ");
				imprimir_pol(ko_PolG, exp_PolG, terminoG);
				puts(" ");

				puts(" ");
				printf("\n\t\tPolinomios ordenados: ");
				mostrar_poli(ko_PolF,ko_PolG,exp_PolF,exp_PolG,terminoF,terminoG);

				s=1;     //marca que ya hay valores en el programa

				printf("\n\n\t\tPULSA ENTER PARA CONTINUAR...");				
				getchar();
				getchar();
				break; 

			case 2:                                           //CASO 2: SUMA DE POLINOMIOS
				system("cls");
				if(s==0)
				{
					printf("\n\t\tNo hay valores todavia...");
		    }
		    else
		    {
		      printf("\n\t\tResultado de la Suma de polinomios");   
		      mostrar_poli(ko_PolF,ko_PolG,exp_PolF,exp_PolG,terminoF,terminoG);

		      printf("\n\n\t\tEs");
		      printf("\n\t\tR(x) =  ");
		      suma1(ko_PolF,ko_PolG,exp_PolF,exp_PolG,terminoF,terminoG);
		   }
		      printf("\n\n\t\tPULSA ENTER PARA CONTINUAR...");	
		      getchar();
		      getchar();
		      break;

		 	case 3:                                           //CASO 3: RESTA DE POLINOMIOS
				system("cls");
				if(s==0)
				{
			   	printf("\n\t\tNo hay valores todavia...");
		    }
		    else
		    {
		      printf("\n\t\tResultado de la Resta de polinomios");   
		      mostrar_poli(ko_PolF,ko_PolG,exp_PolF,exp_PolG,terminoF,terminoG);

		      printf("\n\n\t\tEs");
		      printf("\n\t\tR(x) =  ");
		      resta(ko_PolF,ko_PolG,exp_PolF,exp_PolG,terminoF,terminoG);

		    }
		    printf("\n\n\t\tPULSA ENTER PARA CONTINUAR...");
		    getchar();
		    getchar();
		    break;

		  case 4:                                           //CASO 4: MULTIPLICACION DE POLINOMIOS
				system("cls");
				if(s==0)
				{
					printf("\n\t\tNo hay valores todavia...");
		    }
		    else
		    {
		      printf("\n\t\tResultado de la multiplicaci%cn de polinomios",162);   
		      mostrar_poli(ko_PolF,ko_PolG,exp_PolF,exp_PolG,terminoF,terminoG);

		      printf("\n\n\t\tEs");
		      printf("\n\t\tR(x) =  ");
		      mult(ko_PolF,ko_PolG,exp_PolF,exp_PolG,terminoF,terminoG);   //
		    }
		    printf("\n\n\t\tPULSA ENTER PARA CONTINUAR...");
		    getchar();
		    getchar();
		    break;

		   	case 5:                                           //CASO 5: DIVISION DE POLINOMIOS
					system("cls");
					if(s==0)
					{
						printf("\n\t\tNo hay valores todavia...");
		      }
		      else
		      {
		      	printf("\n\t\tResultado de la divisi%cn de polinomios",162);   
		     	  mostrar_poli(ko_PolF,ko_PolG,exp_PolF,exp_PolG,terminoF,terminoG);

		      	printf("\n\n\t\tEs");
		      	printf("\n\t\tR(x) =  ");
		     	  division(ko_PolF,ko_PolG,exp_PolF,exp_PolG,terminoF,terminoG);
		    
		      }
		      printf("\n\n\t\tPULSA ENTER PARA CONTINUAR...");
		      getchar();
		      getchar();
		      break;

		   	case 6:                                           //CASO 6: IMPRESION DE POLINOMIOS
					system("cls");
					if(s==0)
					{
						printf("\n\t\tNo hay valores todavia...");
		      }
		      else
		      {
		        imp_arc(ko_PolF,ko_PolG,exp_PolF,exp_PolG,terminoF,terminoG);  //
		      }
		      printf("\n\n\t\tPULSA ENTER PARA CONTINUAR...");		
		      getchar();
		      getchar();
		      break;

		    case 7:                                        //CASO 7. LIBERACION DE MEMORIA CUANDO SE SELECCIONA LA ULTIMA OPCION
		    	free(ko_PolF);
					free(ko_PolG);
					free(exp_PolF);
					free(exp_PolG);
		        break;

		    default:
		        system("cls");
		        printf("\n\t\tLa opci%cn es incorrecta. Intenta de nuevo...",162);
		        getchar();
		        getchar();
		        break;                               
		}

	}while(op_menu!=7);
}

void mostrar_poli(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2)
{
	ordenar_poli(m1, n1, tam1);
	ordenar_poli(m2, n2, tam2);
	printf("\n\t\tF(x): ");
	imprimir_pol(m1, n1, tam1);
	printf("\n\t\tG(x): ");
	imprimir_pol(m2, n2, tam2);
}

void imprimir_pol(float *m, int *n, int tam)    //FUNCION PARA IMPRIMIR POLINOMIOS CON LA VARIABLE
{
	for (int i = 0; i < tam; ++i)  
	{
		if(*(n+i)==0)    //si el exponente es 0 (termino independiente)
		{
			if(*(m+i)<0 || i==0)  
			{
				printf("  %.1f", *(m+i));    //si el termino independiente es negativo, se imprime negativo
			}
			else
			{
				printf(" + %.1f", *(m+i));    //si el termino independiente es positivo, se imprime positivo
			}
		}
		else  //si el exponente no es 0  (termino con variable)
		{
			if (*(m+i)<0 || i==0)
			{
				printf("  %.1fx^%d", *(m+i), *(n+i));  //si el termino es negativo, se imprime negativo
			}
			else
			{
				printf(" + %.1fx^%d", *(m+i), *(n+i));  //si el termino es positivo, se imprime positivo	
			}

		}
	}
}
void ordenar_poli(float *m,int *n, int tam)
{
	int aux, aux2;
	for (int i = 0; i < tam; ++i)        
	{
		for (int j = 0; j < tam-1; ++j)
		{
			if (*(n+j) < *(n+j+1))
			{
				aux = *(n+j);
				aux2 = *(m+j);    //si el exponente cambia de posicion, su homologo en el otro array tambien se mueve 

				*(n+j) = *(n+j+1);
				*(m+j) = *(m+j+1);

				*(n+j+1) = aux;
				*(m+j+1) = aux2;
			}
		}
	}
}

int suma1(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2)      //FUNCION PARA SUMAR ARREGLO
{
	int j=0;
	int c=0;
	int tot = tam1+tam2;

	float *ko=NULL;                //ARREGLO PARA UNIR POLINOMIOS
	int *exp=NULL;

	ko=(float*)calloc(tot, sizeof(float));  //ASIGNACION DE MEMORIA
	exp=(int*)calloc(tot, sizeof(int));

	if(ko==NULL || exp==NULL)    //MENSAJE DE ERROR 
	{
		printf("\nError!!");
		exit(1);
	}

	//concatenar F(x) y G(x)
	for (int i = 0; i < tam1; ++i)   //f(x)
	{
		*(ko+i)=*(m1+i);
		*(exp+i)=*(n1+i);
	}

	for (int i = tam1; i < tot ; ++i)
	{
		*(ko+i)=*(m2 +i-tam1);
		*(exp+i)=*(n2 +i-tam1);
	}

	ordenar_poli(ko,exp,tot);    //ordenar arreglo 

	aux_sum(ko,exp,tot);

	free(ko);   //liberar memoria
	free(exp);

	return 0;
}

int aux_sum(float *m, int *n, int tam)    //FUNCION AUXILIAR PARA SUMA 
{
	int j;

  for (int i = 0; i < tam; ++i)         //ciclo for para evaluar exponentes
 	{
	    j=i+1;
	    while(j<tam)                    
        {
			if(*(n+i)==*(n+j))           //si los exponentes son iguales
			{
				*(m+i) += *(m+i+1);     //se suma el coeficiente actual con el anterior
				*(m+j) = 0;            //el coeficiente se iguala a 0 porque se considera un lugar vacio

				for (int a = j; a+1 < tam; ++a) //ciclo for para recorrer lugares vacios del arr coeficiente (dejar los 0 al final)
				{	
                  if(*(m+a) ==0)
                  {
                    *(m+a) = *(m+a+1);
                    *(m+a+1) = 0;           
                  }
				}

	            for (int k = j; k+1 < tam; k++)   //ciclo for para ir eliminado exponentes que se repiten
	            {
	                *(n+k) = *(n+k+1);
	            }
	            tam--;
	        }
	        else
	        {
	           j++;
	        }
	    }   
	}

	//lo que se pretende hacer NO MOSTRAR LOS LUGARES ("VACIOS"), o sea, los 0
	n=(int*)realloc(n,tam*sizeof(int)); //redimension de los arreglos con el nuevo tamaño de los mismos(sin cambiar valores)
	m=(float*)realloc(m, tam*sizeof(float));
	
	if(m==NULL || n==NULL)
	{
		printf("\nError!!");;
	}
	else
	{  

		j=0;
		//comprobar si ha coeficientes 0
		for (int i = 0; i < tam; ++i)
		{
			if (*(m+i)==0.0)
			{
				j++;   //cuenta cuantos coeficientes 0 hay
			}
		}

		if(j>0)   //si el contador marco que si hay coeficientes 0
		{
			quitar_div(m,n,tam);     //llama a la funcion para quitar esos terminos
		}
		else
		{
			imprimir_pol(m,n,tam);   //sino, se imprime el polinomio 
		}

	}

	return 0;
}

int resta(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2)      //FUNCION PARA RESTAR ARREGLO
{
	int j=0;
	int c=0;
	int tot = tam1+tam2;

	float *ko=NULL;                //ARREGLO PARA CONCATENAR POLINOMIOS
	int *exp=NULL;

	ko=(float*)calloc(tot, sizeof(float));  //ASIGNACION DE MEMORIA
	exp=(int*)calloc(tot, sizeof(int));

	if(ko==NULL || exp==NULL)    //MENSAJE DE ERROR 
	{
		printf("\nError!!");
		exit(1);
	}

	//concatenar F(x) y G(x)
	for (int i = 0; i < tam1; ++i)   //f(x)
	{
		*(ko+i)=*(m1 + i);
		*(exp+i)=*(n1+ i);
	}

	for (int i = tam1; i < tot ; ++i)
	{
		*(ko+i)=*(m2 +i-tam1)*-1;   //multiplicar segundo polinomio por -1
		*(exp+i)=*(n2 +i-tam1);
	}

	ordenar_poli(ko,exp,tot);    //ordenar arreglo 

	aux_sum(ko,exp,tot);  //realizar suma

	free(ko);   //liberar memoria
	free(exp);

	return 0;
}

int mult(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2)
{
	int tot = tam1*tam2;  //el tamaño se define multiplicando la cantidad de terminos de los polinomios
	float *ko=NULL;                //ARREGLO PARA UNIR POLINOMIOS
	int *exp=NULL;

	ko=(float*)calloc(tot, sizeof(float));  //ASIGNACION DE MEMORIA
	exp=(int*)calloc(tot, sizeof(int));

	if(ko==NULL || exp==NULL)    //MENSAJE DE ERROR 
	{
		printf("\nError!!");
		exit(1);
	}

	//multiplicar
	float multiplica;
	int suma_exp;
	int k=0;
	for (int i = 0; i < tam1; ++i)   //multiplica todos los terminos del primer termino por cada termino del segundo polinomio
	{
		for (int j = 0; j < tam2; ++j)
		{
			multiplica=1;
			suma_exp=0;

			multiplica=*(m1+i)* *(m2+j);   //multiplicacion de coeficientes
			*(ko+k)=multiplica;           //guarda el coeficiente en el nuevo arreglo

			suma_exp=*(n1+i)+ *(n2+j);    //suma de exponentes 
			*(exp+k)=suma_exp;
			k++;
		}
	}

	ordenar_poli(ko,exp,tot);    //ordenar arreglo 

	aux_sum(ko,exp,tot);     //sumar terminos y mostrar termino resultante

	free(ko);   //liberar memoria
	free(exp);
	
	return 0;
}

int division(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2)
{
	ordenar_poli(m1,n1,tam1);
	ordenar_poli(m2,n2,tam2);

	int mayorF = *n1;           //primera posicion de n1 --> n1[0]
	int mayorG = *n2;          //primera posicion de n2 ---> n2[0]
	int menorF = *(n1 + tam1-1);  //ultima posicion de n1
	int menorG = *(n2 + tam2-1);


	//llamar funcion cont_dif() para contar grados faltantes  
	//definir nuevos arreglos para realizar la division
	int newtam_F = tam1 + cont_dif(mayorF,menorF,n1) ;    //para F(x)    
	int newtam_G = tam2 + cont_dif(mayorG,menorG,n2);      //para G(x)      

	int filas_mat=7;
	float mat_horn[filas_mat][newtam_F];
	int k=0;
	int j=0;

//INICIALIZAR MATRIZ
	for (int f = 0; f < filas_mat; ++f)
	{
		for (int c = 0; c < newtam_F; ++c)
		{
			if (f==0)                            //llenar primera fila con los valores que corresponden
			{
				if( *(n1+j) == mayorF)             //si el exponente de los coeficientes corresponde al grado
				{
					mat_horn[f][c]=*(m1+j);      //su coeficiente se guarda en la matriz
				}
				else
				{
					mat_horn[f][c]=0;        //de lo contrario, el grado faltante se complementa con coeficiente 0
					j--;
				}
					j++;
					mayorF--;				
			}

			if(f!=0)                    //poner los lugares en 0 si no se itera en la fila 0
			{
				mat_horn[f][c]=0;
			}	
		}
	}


	float *koG_div=NULL;                            //nuevo arreglo para completar coeficiente de G(x)

	koG_div=(float*)calloc(newtam_G, sizeof(float));
	if (koG_div==NULL)
	{
		printf("\nError 1");
		exit(1);
	}

	j=0;
	//llenar G(x) con los valores que corresponden   //NO TOCAR newtam_G
	for(int i = 0; i < newtam_G; ++i)
	{
		if( *(n2+j) == mayorG)
		{
			*(koG_div +i)= *(m2+j)*-1;    //multiplicar los numeros por -1
		}
		else
		{
			*(koG_div+i)=0;
			j--;
		}
		mayorG--;
		j++;
	}	


//OBTENER COEFICIENTES
	float comun = *m2;    
	float aux = **mat_horn;
	float cociente;

	float *arr_cociente=NULL;      //cambiar
	int tam_cociente= newtam_F-(newtam_G-1);

	arr_cociente=(float*)calloc(tam_cociente,sizeof(float));
	if(arr_cociente==NULL)
	{
		printf("\nError 4");
		exit(1);
	}

	k=0;  //para llenar arreglo cociente
	j=1;  //para recorrer denominador G(x)  a partir de la segunda posicion
	int h = 1; //columna que va a sumar
	int f=1;
	int c=1;   //columna donde se van a poner los valores


	float suma_col;

	for (f = 1; f < filas_mat; ++f) 
	{         
		if(c==newtam_F)    //si se llega a la ultima columna, se detiene el ciclo
		{
			break;
		}

		suma_col=0;
		cociente = aux/comun;         //el cociente se obtiene dividiendo el auxiliar sobre comun 
		*(arr_cociente+k)=cociente;     //el cociente se guarda en el arreglo

		for(j=1; j<= newtam_G; j++)    //for para recorrer G(x) y guardar en matriz
		{
			mat_horn[f][c]= *(koG_div+j)*cociente;  //  el valor de los elementos dentro de la matriz sera la multiplicacion de G(x) por el cociente
			c++;                       //recorrer columas de matriz
		}

		for (int i = 0; i < filas_mat; ++i)     //sumar columna    i=filas en total
		{
			suma_col += mat_horn[i][h];  
		}

		aux=suma_col;      //el auxiliar que va a seguir multiplicando, sera igual a la suma de la columna
		c -= newtam_G-1;   //el valor de las columnas regresa a su valor +1 

		k++;                //aumentar valor de k para recorrer arreglo de cociente
		h++;                 //aumenta valor de h para sumar las columnas y obtener el valor de cocien-
	}

	//OBTENER EXPONENTES DEL COCIENTE
	int *exp_cociente=NULL;
	exp_cociente=(int*)calloc(tam_cociente, sizeof(int));
	if(exp_cociente==NULL)
	{
		printf("\nError exp cociente:");
		exit(0);
	}

	j=0;      //inicializar exponentes de cociente
	for (int i = tam_cociente; i>=0 ; --i)
	{
		*(exp_cociente+j)=i-1;
		j++;
	}

	quitar_div(arr_cociente,exp_cociente,tam_cociente);


	//OBTENER RESIDUO
	int tam_residuo=newtam_F - tam_cociente;
  float *arr_residuo=NULL;
  int *exp_residuo=NULL;

  arr_residuo=(float*)calloc(tam_residuo, sizeof(float));
  exp_residuo=(int*)calloc(tam_residuo, sizeof(int));
  aux=0;
  k=0;
  for (int i = tam_cociente; i <newtam_F; ++i)  //columnas
  {
  	suma_col=0;
  	for (int j = 0; j < filas_mat; ++j)     //filas 
		{
			suma_col += mat_horn[j][i];         //suma de las filas respecto a la columna 
		}
		*(arr_residuo+k)=suma_col;     //guardar suma en el arreglo
		k++;
  }

  k=0;
  for (int i = tam_residuo; i>=0 ; --i)       //OBTENER EXPONENTES DEL RESIDUO 
	{
		*(exp_residuo+k)=i-1;
		k++;
	}

	k=0;     //comprobador
  for (int i = 0; i < tam_residuo; ++i)  //comprobar si hay residuo
  {
  	if(*(arr_residuo+i)==0.0)
  	{
  		k++;
  	}
  	
  }

  printf("\n\t\tResiduo: ");

  if(k==tam_residuo)
  {
  	printf("0");
  }
  else
  {
  	quitar_div(arr_residuo,exp_residuo,tam_residuo);
  }

	free(koG_div);
  free(arr_cociente);
	free(exp_cociente);
	free(arr_residuo);
	free(exp_residuo);
	return 0;
}

int quitar_div(float *m, int *n, int tam)   //funcion para quitar los coeficientes y exponentes que sobran 
{
	int j=0;
	float aux_co;
	int aux_exp;
	for (int i = 0; i < tam; ++i)
	{
			if (*(m+i)==0)    //si el coeficiente es 0, se pasa al final
			{
				for (int k = i; k+1<tam ; ++k)
				{
					if (*(m+k)==0)
					{
						aux_co=*(m+k);
						aux_exp=*(n+k);

						*(m+k)=*(m+k+1);
						*(n+k)=*(n+k+1);

						*(m+k+1)=aux_co;
					  *(n+k+1)=aux_exp;
					}
					
				}
				tam--;
			}
	}

	n=(int*)realloc(n,tam*sizeof(int)); //redimension de los arreglos con el nuevo tamaño de los mismos(sin cambiar valores)
	m=(float*)realloc(m, tam*sizeof(float));
	
	if(m==NULL || n==NULL)
	{
		printf("\nError de reasignacion de memoria para division!!");;
	}
	else
	{
		imprimir_pol(m,n,tam);
	}
	return 0;
}


int cont_dif(int may, int men, int *n)   //FUNCION PARA CONTAR CUANTOS GRADOS NO EXISTEN EN EL POLINOMIO 
{
	int cant_dif=0;
	int j=0;

	for (int i = may; i >= men; --i)  
	{
		if(i != *(n+j))
		{
			cant_dif++;
			j--;
		}
		j++;
	}
	return cant_dif;
}



void imp_arc(float *m1, float *m2, int *n1, int *n2, int tam1, int tam2)   //FUNCION PARA CREAR ARCHIVO
{
	FILE *archivo;
	
	archivo = fopen ("Ejercicios_Polinomios.txt", "w"); 
	if (archivo == NULL) 
	{ 
		fprintf(stderr, "\n\t\tNo se pudo abrir el archivo\n"); 
		exit (1); 
	}

	fprintf(archivo,"\n Programación Estructurada");
	fprintf(archivo, "\n Profa. Yuliana Berumen Díaz");
	fprintf(archivo, "\n\n Favor de resolver lo siguiente: ");

	fprintf(archivo, "\n F(x): ");
	aux_ar(archivo, m1,n1,tam1);
	fprintf(archivo, "\n G(x): ");
	aux_ar(archivo, m2,n2,tam2);

	if(archivo==NULL)
	{
		printf("\n Error al escribir en el archivo\n");
	} 
	else
	{
			printf("\n\t\tArchivo listo :D"); 
	}

	fclose(archivo);

}

void aux_ar(FILE *a, float *m, int *n, int tam)    //FUNCION PARA IMPRIMIR POLINOMIOS CON LA VARIABLE EN EL ARCHIVO
{
	ordenar_poli(m,n,tam);

	for (int i = 0; i < tam; ++i)  
	{
		if(*(n+i)==0)    //si el exponente es 0 (termino independiente)
		{
			if(*(m+i)<0 || i==0)  
			{
				fprintf(a,"  %.1f", *(m+i));    //si el termino independiente es negativo, se imprime negativo
			}
			else
			{
				fprintf(a, " + %.1f", *(m+i));    //si el termino independiente es positivo, se imprime positivo
			}
		}
		else  //si el exponente no es 0  (termino con variable)
		{
			if (*(m+i)<0 || i==0)
			{
				fprintf(a,"  %.1fx^%d", *(m+i), *(n+i));  //si el termino es negativo, se imprime negativo
			}
			else
			{
				fprintf(a," + %.1fx^%d", *(m+i), *(n+i));  //si el termino es positivo, se imprime positivo	
			}

		}
	}
}