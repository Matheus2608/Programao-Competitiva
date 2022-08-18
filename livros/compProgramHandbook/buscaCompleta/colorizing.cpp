#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main()
{
    char c;
    int n,m,cor,x,y;
    int image[1026][1026];
    bool visited[1026][1026];
    
    scanf("%d %d",&n,&m);
    
    scanf("%c\n",&c);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%c",&c);
            if(c == '.')
                image[i][j]=1;
        }
        scanf("%c",&c);
    }
    
    cor = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(image[i][j] == 1 and !visited[i][j])
            {
                cor++;
                queue<pii> fila;
                fila.push(make_pair(i,j));
                visited[i][j] = true;
                
                while(!fila.empty())
                {
                    tie(x,y) = fila.front();fila.pop();
                    
                    if(image[x-1][y] == 1 and !visited[x-1][y])
                    {
                        fila.push(make_pair(x-1,y));
                        visited[x-1][y] = true;
                    }
                    
                    if(image[x+1][y] == 1 and !visited[x+1][y])
                    {
                        fila.push(make_pair(x+1,y));
                        visited[x+1][y] = true;
                    }
                    
                    if(image[x][y-1] == 1 and !visited[x][y-1])
                    {
                        visited[x][y-1] = true;
                        fila.push(make_pair(x,y-1));
                    }
                    
                    if(image[x][y+1] == 1 and !visited[x][y+1])
                    {
                        visited[x][y+1] = true;
                        fila.push(make_pair(x,y+1));
                    }
                }
            }
        }
    }
    
    printf("%d\n",cor);
    
    return 0;
}
