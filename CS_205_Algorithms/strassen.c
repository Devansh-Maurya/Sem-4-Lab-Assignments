#include <stdio.h>

#define S 10 

struct strassen_matrix {
    int row_start;
    int row_end;
    int column_start;
    int column_end;
    int matrix[S][S];
};

typedef struct strassen_matrix strassen_matrix;

void print_strassen_matrix(strassen_matrix);
strassen_matrix input_strassen_matrix(int n);
strassen_matrix initialize_strassen_matrix(strassen_matrix, int, int, int, int);
strassen_matrix multiply(strassen_matrix, strassen_matrix);
strassen_matrix add(strassen_matrix, strassen_matrix);
strassen_matrix subtract(strassen_matrix, strassen_matrix);

int main()
{
    int n, i, j;
    strassen_matrix A, B, C;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    printf("Enter elements of matrix A:\n");
    A = input_strassen_matrix(n);

    printf("Enter elements of matrix B:\n");
    B = input_strassen_matrix(n);

    C = multiply(A, B);

    print_strassen_matrix(C);
}

strassen_matrix multiply(strassen_matrix A, strassen_matrix B)
{
    int i, j, n;
    n = A.row_end - A.row_start + 1;
    strassen_matrix C;

    if(n == 1)
    {
        C.matrix[C.row_start][C.row_start] = A.matrix[A.row_start][A.row_start] * B.matrix[B.row_start][B.row_start];

        return C;
    }
    else
    {
        strassen_matrix a, b, c, d, e, f, g, h;
        strassen_matrix p1, p2, p3, p4, p5, p6, p7;
        strassen_matrix c1, c2, c3, c4;

        a = initialize_strassen_matrix(A, A.row_start, A.row_end/2, A.column_start, A.column_end/2);
        b = initialize_strassen_matrix(A, A.row_start, A.row_end/2, A.column_start/2 + 1, A.column_end);
        c = initialize_strassen_matrix(A, A.row_start/2 + 1, A.row_end, A.column_start, A.column_end/2);
        d = initialize_strassen_matrix(A, A.row_start/2 + 1, A.row_end, A.column_start/2 + 1, A.column_end);

        e = initialize_strassen_matrix(B, b.row_start, B.row_end/2, B.column_start, B.column_end/2);
        f = initialize_strassen_matrix(B, b.row_start, B.row_end/2, B.column_start/2 + 1, B.column_end);
        g = initialize_strassen_matrix(B, b.row_start/2 + 1, B.row_end, B.column_start, B.column_end/2);
        h = initialize_strassen_matrix(B, b.row_start/2 + 1, B.row_end, B.column_start/2 + 1, B.column_end);

        p1 = multiply(a, subtract(f, h));
        p2 = multiply(add(a, b), h);
        p3 = multiply(add(c, d), e);
        p4 = multiply(d, subtract(g, e));
        p5 = multiply(add(a, d), add(e, h));
        p6 = multiply(subtract(a, c), add(e, f));
        p7 = multiply(subtract(b, d), add(e, h));

        c1 = add(subtract(add(p5, p4), p2), p6);
        c2 = add(p1, p2);
        c3 = add(p3, p4);
        c4 = subtract(subtract(add(p1, p5), p3), p7);

        for(i = 1; i <= n/2; i++)
            for(j = 1; j<= n/2; j++)
            C.matrix[i][j] = c1.matrix[i][j];

        for(i = 1; i <= n/2; i++)
            for(j = n/2 + 1; j<= n; j++)
            C.matrix[i][j] = c2.matrix[i][j];
        
        for(i = n/2 + 1; i <= n; i++)
            for(j = 1; j<= n/2; j++)
            C.matrix[i][j] = c3.matrix[i][j];
        
        for(i = n/2; i <= n; i++)
            for(j = n/2 + 1; j<= n; j++)
            C.matrix[i][j] = c4.matrix[i][j];
        
        return C;

    }
}

strassen_matrix add(strassen_matrix A, strassen_matrix B)
{
    int n = A.row_end - A.row_start + 1, A_i, A_j, B_i, B_j;
    int i, j;
    strassen_matrix result;

    for(A_i = A.row_start, B_i = B.row_start, i = 1; i <= n; i++, A_i++, B_i++)
    {
        for(A_j = A.column_start, B_j = B.column_start, j = 1; j < n; j++, A_j++, B_j++)
        {
            result.matrix[i][j] = A.matrix[A_i][A_j] + B.matrix[B_i][B_j];
        }
    }

    return result;

}

strassen_matrix subtract(strassen_matrix A, strassen_matrix B)
{
    int n = A.row_end - A.row_start + 1, A_i, A_j, B_i, B_j;
    int i, j;
    strassen_matrix result;

    for(A_i = A.row_start, B_i = B.row_start, i = 1; i <= n; i++, A_i++, B_i++)
    {
        for(A_j = A.column_start, B_j = B.column_start, j = 1; j < n; j++, A_j++, B_j++)
        {
            result.matrix[i][j] = A.matrix[A_i][A_j] - B.matrix[B_i][B_j];
        }
    }

    return result;

}

strassen_matrix initialize_strassen_matrix(strassen_matrix m, int rs, int re, int cs, int ce)
{
    strassen_matrix a;

    a = m;

    a.row_start = rs;
    a.row_end  = re;
    a.column_start = cs;
    a.column_end = ce;
}

void print_strassen_matrix(strassen_matrix A)
{
    int i, j;

    printf("\nMatrix elements from function:\n");
    for(i = 1; i < A.row_end; i++)
    {
        for(j = 1;j < A.column_end;j++)
        {
            printf("%d", A.matrix[i][j]);
        }
        printf("\n");
    }
}

strassen_matrix input_strassen_matrix(int size)
{
    strassen_matrix m;
    int i, j;

    m.row_start = 1;
    m.row_end = size;
    m.column_start = 1;
    m.column_end = size;

    for(i = 1;i < size;i++)
    {
        for(j = 1;j < size;j++)
        {
            scanf("%d", &m.matrix[i][j]);
        }
    }

    return m;
}