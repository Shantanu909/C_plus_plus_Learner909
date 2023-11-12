int main()
{
	
	int a = 5;
    int *b;
    int *c;
    int **d;
    int **e;
    int *f;
	int arr[2][2];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;
	arr[2][0] = 7;
	arr[2][1] = 8;
	arr[2][2] = 9;

	b = &a;
    c = a;
    d = &a;
	e = &arr[1][2];
    f = &arr[2][0];
	printf("%d",a);
	printf("\n%d",b);
	printf("\n%d",c);
	printf("\n%d",d);
    printf("\n%d",e);
    printf("\n%d",f);

}