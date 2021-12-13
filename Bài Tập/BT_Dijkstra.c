#define INFINITY 99999 // Hằng số vô cùng
#define MAX 50         // Số đỉnh của đồ thị lớn nhất có thể xét

void readData(char *filename, int G[MAX][MAX], int *pn, int *psource)
{
    FILE *file = fopen(filename, "r");
    int i, j;
    if (file != NULL)
    {
        fscanf(file, ___, ___, ___);
        for (i = ___; i < ___; i++)
            2 for (j = ___; j < ___; j++)
                fscanf(file, ___, ___);
    }
    fclose(file);
}

void dijkstra(int G[MAX][MAX], int n, int source)
{
    int c[MAX][MAX], d[MAX], p[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                c[i][j] = INFINITY;
            else
                c[i][j] = ___;
    for (i = 0; i < n; i++)
    {
        d[i] = ___;
        p[i] = ___;
        visited[i] = 0;
    }
    d[source] = ___;
    visited[source] = 1;
    count = 1;
    while (count < n)
    {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (d[i] < ___ && visited[i] == ___)
            {
                mindistance = ___;
                nextnode = ___;
            }
        visited[___] = ___;
        for (i = 0; i < n; i++)
            if (visited[i] == ___)
                if (___)
                {
                    d[i] = ___;
                    p[i] = ___;
                    minh.phamtuan @phenikaa - uni.edu.vn 3
                }
        count++;
    }
    for (i = 0; i < n; i++)
        if (i != source)
        {
            printf("\nDistance to node%d=%d", i, ___);
            printf("\nPath=%d", i);
            j = i;
            do
            {
                j = ___;
                printf("<-%d", j);
            } while (j != source);
        }
}

int main()
{
    int G[MAX][MAX], n, source;
    readData(___, ___, ___, ___);
    dijkstra(___, ___, ___);
    return 0;
}