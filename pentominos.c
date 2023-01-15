
#include <stdio.h>
#include <time.h>

#define TAM_TABLERO 16
#define TAM_PIEZA 5
#define NUM_PIEZAS 12

int encontrada_valida = 0;
int cont_max = 0;
int cont_ceros = 0;

int piezas[NUM_PIEZAS][TAM_PIEZA][TAM_PIEZA] = {{
        {'a', 'a', '0', '0', '0'},
        {'a', '0', '0', '0', '0'},
        {'a', 'a', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'b', '0', '0', '0', '0'},
        {'b', '0', '0', '0', '0'},
        {'b', 'b', 'b', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'c', '0', '0', '0', '0'},
        {'c', 'c', '0', '0', '0'},
        {'c', 'c', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'d', '0', '0', '0', '0'},
        {'d', 'd', '0', '0', '0'},
        {'0', 'd', 'd', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'e', 'e', '0', '0', '0'},
        {'0', 'e', '0', '0', '0'},
        {'0', 'e', 'e', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'0', 'f', '0', '0', '0'},
        {'f', 'f', 'f', '0', '0'},
        {'0', 'f', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'g', 'g', 'g', 'g', 'g'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'h', 'h', 'h', '0', '0'},
        {'0', 'h', '0', '0', '0'},
        {'0', 'h', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'i', 'i', 'i', 'i', '0'},
        {'0', 'i', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'j', 'j', '0', '0', '0'},
        {'0', 'j', 'j', 'j', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'k', 'k', 'k', 'k', '0'},
        {'0', '0', '0', 'k', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }, {
        {'0', 'l', '0', '0', '0'},
        {'l', 'l', 'l', '0', '0'},
        {'l', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    }};


int dibujar_tablero(int tablero[TAM_TABLERO][TAM_TABLERO])
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if(tablero[i+TAM_PIEZA-1][j+TAM_PIEZA-1] == 'z'){
                printf("  ");
            }else{
                printf("%c ", tablero[i+TAM_PIEZA-1][j+TAM_PIEZA-1]);
            }   
            
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int dibujar_pieza(int pieza[TAM_PIEZA][TAM_PIEZA])
{
    int i, j;
    for (i = 0; i < TAM_PIEZA; i++)
    {
        for (j = 0; j < TAM_PIEZA; j++)
        {
            printf("%c ", pieza[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int pos_valida(int matriz[TAM_PIEZA][TAM_PIEZA])
{
    int i, j;
    for (i = 0; i < TAM_PIEZA; i++)
    {
        for (j = 0; j < TAM_PIEZA; j++)
        {
            if (matriz[i][j]>=194) // probar 195 que es a + z
            {
                //printf("Posicion invalida: %d\n", matriz[i][j]);
                return 0;
            }
        }
    }
    return 1;
}

int buscar_ceros(int tablero[TAM_TABLERO][TAM_TABLERO], int i, int j, int i_ant, int j_ant){
    //dibujar_tablero(tablero);
    if (i_ant == i && j_ant == j-1) // ha entrado por la izquierda
    {
        if (tablero[i-1][j] == '0')
        {
            tablero[i-1][j] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i-1,j,i,j);
        }
        if (tablero[i][j+1] == '0')
        {
            tablero[i][j+1] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i,j+1,i,j);
        }
        if (tablero[i+1][j] == '0')
        {
            tablero[i+1][j] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i+1,j,i,j);
        }
    }
    else if (i_ant == i && j_ant == j+1) // ha entrado por la derecha
    {
        if(tablero[i-1][j] == '0')
        {
            tablero[i-1][j] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i-1,j,i,j);
        }
        if (tablero[i][j-1] == '0')
        {
            tablero[i][j-1] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i,j-1,i,j);
        }        
        if (tablero[i+1][j] == '0')
        {
            tablero[i+1][j] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i+1,j,i,j);
        }
    }
    else if (i_ant == i-1 && j_ant == j) // ha entrado por arriba
    {
        if (tablero[i][j-1] == '0')
        {
            tablero[i][j-1] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i,j-1,i,j);
        }
        if (tablero[i+1][j] == '0')
        {
            tablero[i+1][j] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i+1,j,i,j);
        }
        if (tablero[i][j+1] == '0')
        {
            tablero[i][j+1] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i,j+1,i,j);
        }
    }
    else if (i_ant == i+1 && j_ant == j) // ha entrado por abajo
    {
        if (tablero[i][j-1] == '0')
        {
            tablero[i][j-1] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i,j-1,i,j);
        }
        if (tablero[i-1][j] == '0')
        {
            tablero[i-1][j] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i-1,j,i,j);
        }
        if (tablero[i][j+1] == '0')
        {
            tablero[i][j+1] = '1';
            cont_ceros ++;
            buscar_ceros(tablero,i,j+1,i,j);
        }
    }
    return 0;
}

int encontrar_aislados(int tablero[TAM_TABLERO][TAM_TABLERO]){
    
    int i, j,i_ant,j_ant;
    int pieza_aux [TAM_PIEZA+1][TAM_PIEZA+1];

    i_ant = 0;
    j_ant = -1;
    
    for (i = 0; i < TAM_TABLERO; i++)
    {
        for (j = 0; j < TAM_TABLERO; j++)
        {
            cont_ceros = 0;
            if(tablero[i][j]=='0')
            {
                tablero[i][j]='1';
                cont_ceros ++;
                buscar_ceros(tablero,i,j,i_ant,j_ant);

                //printf("Contador ceros: %d\n", cont_ceros);
                if (cont_ceros < 10 && cont_ceros%5!=0)
                {
                    // printf("Existen ceros aislados\n");
                    // dibujar_tablero(tablero);
                    return 1;
                }
            }
            j_ant = j;
            i_ant = i;
        }
    }
    // printf("No existen ceros aislados\n");
    // dibujar_tablero(tablero);
    return 0;    
}

int encontrar_solucion(int tablero[TAM_TABLERO][TAM_TABLERO],int cont){

    int i, j;  
    int n, m;
    
    int pieza_aux [TAM_PIEZA][TAM_PIEZA];
    int tablero_ant [TAM_TABLERO][TAM_TABLERO];

    int rotaciones,simetria;
    
    /*printf("Contador: %d\n",cont);
    if (cont != 12){
        encontrar_solucion(tablero,cont+1);
    }*/
    //printf("Contador: %d\n",cont);
    if (cont >= cont_max){
        cont_max = cont;
        printf("Mejor hasta el momento: %d piezas\n",cont_max);
        dibujar_tablero(tablero);
    }
    //printf("Encontada valida: %d\n",encontrada_valida);
    for (simetria=0;simetria<2&&encontrada_valida==0;simetria++){
        //printf("Simetria: %d\n",simetria);
        for (rotaciones=0; rotaciones<4&&encontrada_valida==0; rotaciones++)
        {
            for (n=0; n<(TAM_TABLERO-TAM_PIEZA)&&encontrada_valida==0; n++) //TAM_PIEZA
            {
                for (m=0; m<(TAM_TABLERO-TAM_PIEZA)&&encontrada_valida==0; m++) //TAM_PIEZA
                {
                    //printf("m:%d\n",m);
                    for (i=0; i<TAM_PIEZA; i++)
                    {
                        for (j=0; j<TAM_PIEZA; j++)
                        {
                            pieza_aux[i][j] = tablero[i+n][j+m] + piezas[cont][i][j];
                        }
                    }
                    //dibujar_pieza(pieza_aux);
                    
                    
                    if (pos_valida(pieza_aux) == 1)
                    {
                        //Guardamos el tablero en tablero_ant
                        for (i=0;i<TAM_TABLERO;i++){
                            for(j=0;j<TAM_TABLERO;j++){
                                tablero_ant[i][j] = tablero[i][j];
                            }
                        }
                        //dibujar_pieza(pieza_aux);
                        //printf("Posicion valida: %d, %d\n", n, m);
                        

                        for (i=0; i<(TAM_PIEZA); i++)
                        {
                            for (j=0; j<(TAM_PIEZA); j++)
                            {
                                if(piezas[cont][i][j] != '0'){
                                    tablero[i+n][j+m] = piezas[cont][i][j];
                                }
                            }
                        }
                        //dibujar_tablero(tablero);
                        if(encontrar_aislados(tablero) == 0){
                            //No se han encontrado aislados

                            //Recuperamos los ceros
                            for (i=0;i<TAM_TABLERO;i++){
                                for(j=0;j<TAM_TABLERO;j++){
                                    if(tablero[i][j] == '1'){
                                        tablero[i][j] = '0';
                                    }
                                }
                            }

                            //dibujar_tablero(tablero);
                            if (cont == (NUM_PIEZAS-1)){
                                encontrada_valida = 1;
                                printf("Solucion encontrada, 12 piezas colocadas\n");

                                dibujar_tablero(tablero);
                            }else{
                                //Recuperamos los ceros
                                for (i=0;i<TAM_TABLERO;i++){
                                    for(j=0;j<TAM_TABLERO;j++){
                                        if(tablero[i][j] == '1'){
                                            tablero[i][j] = '0';
                                        }
                                    }
                                }
                                encontrar_solucion(tablero, cont+1);
                                //printf("Vuelta al %d\n",cont);
                                //dibujar_tablero(tablero);
                                //Recuperamos el tablero_ant
                                for (i=0;i<TAM_TABLERO;i++){
                                    for(j=0;j<TAM_TABLERO;j++){
                                        tablero[i][j] = tablero_ant[i][j];
                                    }
                                }
                                //dibujar_tablero(tablero);
                            }
                        }else{
                            for (i=0;i<TAM_TABLERO;i++){
                                for(j=0;j<TAM_TABLERO;j++){
                                    tablero[i][j] = tablero_ant[i][j];
                                }
                            }
                        }
                        
                        
                    }
                }
            }
            //Rotamos pieza 90º a la dcha
            //dibujar_pieza(piezas[cont]);
            for (i=0; i<TAM_PIEZA; i++)
            {
                for (j=0; j<TAM_PIEZA; j++)
                {
                    pieza_aux[i][j] = piezas[cont][i][j];
                }
            }
            
            for (i=0; i<TAM_PIEZA; i++)
            {
                for (j=0; j<TAM_PIEZA; j++)
                {
                    piezas[cont][i][j] = pieza_aux[TAM_PIEZA-j-1][i];
                }
            }
            //dibujar_pieza(piezas[cont]);
        }

        //Cambiamos simetria
        for (i=0; i<TAM_PIEZA; i++)
        {
            for (j=0; j<TAM_PIEZA; j++)
            {
                pieza_aux[i][j] = piezas[cont][i][j];
            }
        }
           
        for (i=0; i<TAM_PIEZA; i++)
        {
            for (j=0; j<TAM_PIEZA; j++)
            {
                piezas[cont][i][j] = pieza_aux[i][TAM_PIEZA-j-1];
            }
        }
    }
    
}


int main()
{
    int tablero [TAM_TABLERO][TAM_TABLERO] = {
        {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122},
        {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122},
        {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122},
        {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122},
        {122, 122, 122, 122, '0', '0', '0', '0', '0', '0', '0', '0', 122, 122, 122, 122},
        {122, 122, 122, 122, '0', '0', '0', '0', '0', '0', '0', '0', 122, 122, 122, 122},
        {122, 122, 122, 122, '0', '0', '0', '0', '0', '0', '0', '0', 122, 122, 122, 122},
        {122, 122, 122, 122, '0', '0', '0', 'z', 'z', '0', '0', '0', 122, 122, 122, 122},
        {122, 122, 122, 122, '0', '0', '0', 'z', 'z', '0', '0', '0', 122, 122, 122, 122},
        {122, 122, 122, 122, '0', '0', '0', '0', '0', '0', '0', '0', 122, 122, 122, 122},
        {122, 122, 122, 122, '0', '0', '0', '0', '0', '0', '0', '0', 122, 122, 122, 122},
        {122, 122, 122, 122, '0', '0', '0', '0', '0', '0', '0', '0', 122, 122, 122, 122},
        {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122},
        {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122},
        {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122},
        {122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122}
    };
    int cont = 0;
    int pieza_aux [TAM_PIEZA][TAM_PIEZA];
    int rotaciones = 0;
    int simetria = 0;
    int i,j;
    
    //printf("%c\n",171);
    dibujar_tablero(tablero);
    //dibujar_pieza(piezas[cont]);

    clock_t t;
    t = clock();

    encontrar_solucion(tablero,0);

    t = clock() - t;
    double minutos = ((double)t)/CLOCKS_PER_SEC/60;
    if (minutos > 1)
    {
        printf("Ha tardado %f minutos\n", minutos);
    }else
    {
        printf("Ha tardado %f segundos\n", minutos*60);
    }
    printf("Final\n");
    return 0;
}

