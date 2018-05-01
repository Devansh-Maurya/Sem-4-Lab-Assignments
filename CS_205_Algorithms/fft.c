#include<stdio.h>
#include<complex.h>
#include<math.h>
#define MAX 100
#define PI 3.1415
ppoly(double complex a[],int n)
{
    int i;
    for(i=0;i<n;i++){
        if (i==0)
            printf("\nA[%d] : %4.1f + i*%4.1f",i,creal(a[i]),cimag(a[i]));
        else
            printf("\nA[%d] : %4.1f + i*%4.1f",i,-1*creal(a[i]),-1*cimag(a[i]));
    }
}

FFT(int N,double complex a[],double complex w,double complex A[])
{
    int n,i,j,k ;
    double complex b[N/2],c[N/2],B[N/2],C[N/2];
    double complex wp;

    if(N==1) 
        A[0]=a[0];
    else
    {
        n=N/2;
        for(i=0,j=0,k=0;i<=N;i++){
            if(i%2==0){
                b[j]=a[i];
                j++;
            }
            else{
                c[k]=a[i];
                k++;
            }
        }

        FFT(n,b,w*w,B);
        FFT(n,c,w*w,C);

        wp=1/w;
        for(j=0;j<=n-1;j++){
            wp=w*wp;
            A[j]=B[j]+wp*C[j];
            A[j+n]=B[j]-wp*C[j];
        }
    }
}

main()
{
    double complex a[MAX],A[MAX];
    double complex w=cos((2*PI)/4)+sin((2*PI)/4)*I;
    int i,n; int real;
    beg:
    printf("Enter the degree : ");
    scanf("%d",&n);
    n++;
    if(n%2==0)
    {
        for(i=0;i<n;i++){
            printf("Enter the coeffecient of x^%d : ",i);
            scanf("%d",&real);
            a[i]=real+0*I;
        }
        FFT(n,a,w,A);

        ppoly(A,n);
    }
    else
    {
        printf("\nPlease enter an odd degree ....\n");
        goto beg;
    }
}
