#include "tsp.h"

void iniciaGrafo(grafo *g, ifstream &instancia){
    int i , j[100], Total, k, l, mult;
    //instancia >> g->n_elementos;
    instancia >> text;
			
			for (i = 0, k=0; i < text.length(); i++){
			
    			cout << text[i] << " - " << (int)text[i] << endl;
    			if((int)text[i]>=48  && (int)text[i]<=57){
    				j[k]=(int)text[i]-48;
    				cout<<"      "<<k<<" - "<<j[k]<<endl;
    				k++;
				}cout<<endl<<k<<endl;
	                for(i=0, Total=0, mult=0; k>0; k--, i++){
                        cout<<(j[i])<< " ";
                        for(l=0, mult=1; l<k-1; l++){
                            mult*=10;
                        }
                        //if(mult!=0)
                            Total+=(j[i])*(mult);
                        //else
                        //	Total+=j[i];
                    
                        cout<<" -> "<<mult<<" = "<< Total<<endl;
                    }
                        cout<<endl<<endl <<Total<< endl;
                    
    g->n_elementos = Total;

    g->elementos = new int*[g->n_elementos];
    for (int u = 0; u < g->n_elementos; u++) g->elementos[u] = new int[g->n_elementos];

    string valor;
    for(int i = 0; i < g->n_elementos; i++){
        for(int j = 0; j < g->n_elementos; j++){
            instancia >> valor;
            g->elementos[i][j] = atoi(valor.c_str());
        }
    }
}

void HVMP(grafo g, int *rota, int n_inicial){    //Heuristica de construção do vizinho mais proximo
    bool elem_adicionados[g.n_elementos];
    for(int u = 0; u < g.n_elementos; u++) elem_adicionados[u] = false;

    elem_adicionados[n_inicial] = true;
    rota[0] = n_inicial;

    for(int i = 0; i < g.n_elementos; i++){
        int distancia_min = INFINITO;
        int n_proximo;

        for(int j = 0; j < g.n_elementos; j++){
            if((elem_adicionados[j] == false) && (distancia_min > g.elementos[rota[i]][j]) && (i != j)){  //se o elemento nao já estiver contido na rota, e for a menor distancia
                distancia_min = g.elementos[rota[i]][j];
                n_proximo = j;
            }
        }
        rota[i + 1] = n_proximo;    //adiciona o proximo a rota
        elem_adicionados[n_proximo] = true; //salva o proximo como adicionado a rota
    }
    rota[g.n_elementos] = n_inicial;    //retorna ao ponto inicial ao fim da rota
}

int *opt2(grafo g, int *rota){
    int melhor_rota[g.n_elementos + 1];

}

int calculaCusto(grafo g, int *rota){
    int custo = 0;
    for (int u = 0; u < g.n_elementos - 1; u++) custo += g.elementos[rota[u]][rota[u + 1]];
    return custo;
}

int calculaNInicial(grafo g, int *rota){
    int n_inicial;
    int custo_min = INFINITO;
    for(int u = 0; u < g.n_elementos; u++){
        HVMP(g, rota, u);
        int custo = calculaCusto(g, rota);
        cout << "n_inicial:" << " ";
        cout << u << endl;
        cout << "custo:" << " ";
        cout << custo << endl;
        if (custo_min > custo){
            custo_min = custo;
            n_inicial = u;
        }
    }
    cout << "custo minimo:" << " ";
    cout << custo_min << endl;
    cout << "n_inicial_final:" << " ";
    cout << n_inicial << endl;
    return n_inicial;
}

void printMatriz(grafo g){
    cout << "Matriz de adjacencias: " << endl;
    for(int i = 0; i < g.n_elementos; i++){
        for(int j = 0; j < g.n_elementos; j++) cout << g.elementos[i][j] << " ";
        cout << endl;
    }
}

void printRota(grafo g, int *rota){
    cout << "Rota: " << endl;
    for(int u = 0; u <= g.n_elementos; u++) cout << rota[u] << " ";
    cout << endl;
}                 
