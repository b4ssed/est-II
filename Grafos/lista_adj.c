#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int vertice;
    struct no *prox;
}tipo_no;

typedef struct grafo{
    int num_vertices;
    tipo_no *VETOR_list_adj;
}tipo_grafo;

tipo_grafo *criaGRAFO(int n){
    tipo_grafo *G = (tipo_grafo*) malloc(sizeof(tipo_grafo));
    if (G){
        G->num_vertices = n;
        G->VETOR_list_adj = (tipo_no*) malloc(n*sizeof(tipo_no));
        if (G->VETOR_list_adj){
            
            for (int i = 0; i < n; i++)
                G->VETOR_list_adj[i].prox = NULL;
            return G;
        }
        return NULL;
    }
    return NULL;
}

void mostraGRAFO(tipo_grafo *G){
    int i;
    printf("\nGRAFO - Lista adjacencia\n");
    for(i = 0; i < G->num_vertices; i++){
        tipo_no *p = G->VETOR_list_adj[i].prox;
        printf("\n%d->", i);
        while(p){
            printf("%d->", p->vertice);
            p = p->prox;
        }
        printf("NULL\n");
    }
}

tipo_no * criaNO(int v){
    tipo_no *novoNO = (tipo_no *) malloc(sizeof(tipo_no));
    novoNO->vertice = v;
    novoNO->prox = NULL;
    
    return novoNO;
}

void addARESTA(tipo_grafo *G, int origem, int destino){
    tipo_no *novoNO = criaNO(destino);
    novoNO->prox = G->VETOR_list_adj[origem].prox;
    G->VETOR_list_adj[origem].prox = novoNO;
    
    novoNO = criaNO(origem);
    novoNO->prox = G->VETOR_list_adj[destino].prox;
    G->VETOR_list_adj[destino].prox = novoNO;
    
}

tipo_grafo* destroiGRAFO(tipo_grafo *G){
    if(G){
        if (G->VETOR_list_adj){
            for (int i = 0; i < G->num_vertices; i++){
                tipo_no *p = G->VETOR_list_adj[i].prox;
                while(p){
                    tipo_no *tmp = p;
                    p = p->prox;
                    free(tmp);
                }
            }
            free(G->VETOR_list_adj);
        }
        free(G);
    }
    return NULL;
}

int main(){
	
	tipo_grafo *G = criaGRAFO(5);
	if (G == NULL)
	    return -1;
	
	addARESTA(G, 1, 2);
	addARESTA(G, 1, 3);
	addARESTA(G, 1, 0);
	
	mostraGRAFO(G);
	
	G = destroiGRAFO(G);
    return 0;
}