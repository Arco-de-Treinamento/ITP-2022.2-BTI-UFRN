#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cells[100];
    int size;
} Cells;


// Optei por usar um struct para aproveitar a mesma função para retornar o tamanho e o array
Cells get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index){
    Cells cells_range;
    cells_range.size = 0;

    *left_index = (user - distance);
    *right_index = (user + distance);

    for(int i = 0; i < n; i++){
        if(cells[i] >= *left_index && cells[i]<= *right_index){
            cells_range.cells[cells_range.size] = cells[i];
            cells_range.size++;
        }
    }

    return cells_range;
}

int main(){
    int n, distance, user, left_index, right_index;
    scanf(" %d %d %d", &n, &distance, &user);

    int cells[n];
    for(int i = 0; i < n; i++) scanf(" %d", &cells[i]);

    Cells range = get_range(n, cells, distance, user, &left_index, &right_index);

    if(range.size > 0) for(int i = 0; i < range.size; i++) printf("%d ", range.cells[i]);
    else puts("USUARIO DESCONECTADO");

    return 0;
}