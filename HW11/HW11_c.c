#include <stdio.h>

typedef struct obj{
    int hpm, atk, x, y;
}obj;

typedef struct mon{
    obj monster[25];
}Mon;

int to_x[] = {0, 0, 1, -1};
int to_x[] = {1, -1, 0, 0};

int encounter(obj hero, Mon monster)
{

}

int fight(int id, obj *hero, obj *monster)
{

}

int can_go(int x, int y)
{

}

int dfs(int x, int y, int hero, Mon monster)
{
    if(x == )
    int id = encouter(hero, monster);
    if(id == -1 && !fight(id, &hero, moster.monster))
        return 0;
    if(x == 5 &&y == 5)
        return 1;
    for(int i = 0;i < 4;i++){
        if(can_go(x+to_x[i], y + to_y[i])){
            map[x+to_x[i]][y + to_y[i]] = 1;
            if(dfs(x + to_x[i], y + to_y[i], hero, monster)
               return 1;
            map[x+to_x[i]][y + to_y[i]] = 0;
        }
    }
    return 0;
}

int main(void)
{
    if(dfs())printf()
}
