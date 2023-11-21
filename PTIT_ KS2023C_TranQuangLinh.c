#include<stdio.h>
#include<math.h>
int main(){
	int arr[100];
	int i,n,choice, j, k, m=0, temp;
	float sum =0, count =0;
	printf("n************************MENU**************************\n");
	printf("1. Nhap gia tri n phan tu cua mang\n");
	printf("2. In gia tri cac phan tu trong mang\n");
	printf("3. Tinh trung binh cac phan tu duong trong mang\n ");
	printf("4. in ra cac vi tri cac phan tu co gia tri k trong mang\n ");
	printf("5. Su dung thuat toan sap xep noi bot sap xep cac mang giam dan\n ");
	printf("6. Tinh so luong cac phan tu la so nguyen to trong bang \n");
	printf("7. Sap xep cac phan tu chan chia het cho 3 o dau mang theo thu tu tang dan, cac phan tu le chia het cho 3 o cuoi mang theo thu tu giam gian, cac phan tu con lai o giua mang theo thu tu tang dan \n");
	printf("8. Nhap gia tri m tu ban phim, chen gia tri m vao mang \n");
	printf("9. Thoat\n ");
	do
	{
		printf("nhap lua chon cua ban:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Nhap so phan tu: ");
            scanf("%d", &n);

            printf("Nhap cac gia tri phan tu:\n");
            for (j = 0; j < n; j++)
            {
                scanf("%d", &arr[j]);
            }
            break;
            case 2:
            	printf("Cac phan tu trong quan ly la: ");
            for (j = 0; j < n; j++)
            {
                printf("%d ", arr[j]);
            }
            break;
            case 3:
            for (j = 0; j < n; j++)
            {
                if (arr[j] > 0)
                {
                    sum+= arr[j];
                    count++;
                }
            }
            printf("Trung binh cac phan tu duong trong mang la: %.2f\n", sum / count);
            break;
            case 4:
            	printf("Nhap gia tri k: ");
            scanf("%d", &k);
            printf("Vi tri cac phan tu co gia tri bang %d la: ", k);
            for (j = 0; j < n; j++)
            {
                if (arr[j] == k)
                {
                    printf("%d ", j);
                }
            }
            printf("\n");
            break;
            case 5:
            	for (j = 0; j < n - 1; j++)
            {
                for (k = j + 1; k < n; k++)
                {
                    if (arr[j] < arr[k])
                    {
                        temp = arr[j];
                        arr[j] = arr[k];
                        arr[k] = temp;
                    }
                }
            }
            printf("Mang sau khi sap xep giam dan la: ");
            for (j = 0; j < n; j++)
            {
                printf("%d ", arr[j]);
            }
            printf("\n");
            break;
            case 6:
            	 count = 0;
            for (j = 0; j <= sqrt(n); j++)
            {
                if (arr[j] > 1)
                {
                    for (k = 2; k <= sqrt(arr[j]); k++)
                    {
                        if (arr[j] % k == 0)
                        {
                            break;
                        }
                    }
                    if (k == arr[j])
                    {
                        count++;
                        
                    }
                }
            }
            printf("so luong cac so nguyen to trong phan tu la : %.0f\n", count);
            break;
            case 7:
            for (j = 0; j < n - 1; j++)
            {
                for (k = j + 1; k < n; k++)
                {
                    if (arr[j] % 3 == 0 && arr[k] % 3 == 0)
                    {
                        if (arr[j] % 2 == 0 && arr[k] % 2 == 0)
                        {
                            if (arr[j] < arr[k])
                            {
                                temp = arr[j];
                                arr[j] = arr[k];
                                arr[k] = temp;
                            }
                        }
                        else if (arr[j] % 2 != 0 && arr[k] % 2 != 0)
                        {
                            if (arr[j] > arr[k])
                            {
                                temp = arr[j];
                                arr[j] = arr[k];
                                arr[k] = temp;
                            }
                        }
                    }
                    else if (arr[j] % 3 == 0 && arr[k] % 3 != 0)
                    {
                        if (arr[j] % 2 == 0)
                        {
                            if (arr[j] < arr[k])
                            {
                                temp = arr[j];
                                arr[j] = arr[k];
                                arr[k] = temp;
                            }
                        }
                        else if (arr[j] % 2 != 0)
                        {
                            if (arr[j] > arr[k])
                            {
                                temp = arr[j];
                                arr[j] = arr[k];
                                arr[k] = temp;
                            }
                        }
                    }
                    else if (arr[j] % 3 != 0 && arr[k] % 3 == 0)
                    {
                        if (arr[k] % 2 == 0)
                        {
                            if (arr[j] < arr[k])
                            {
                                temp = arr[j];
                                arr[j] = arr[k];
                                arr[k] = temp;
                            }
                        }
                        else if (arr[k] % 2 != 0)
                        {
                            if (arr[j] > arr[k])
                            {
                                temp = arr[j];
                                arr[j] = arr[k];
                                arr[k] = temp;
                            }
                        }
                    }
                }
            }
            printf("Mang sau khi sap xep la : ");
            for (j = 0; j < n; j++)
            {
                printf("%d ", arr[j]);
            }
            printf("\n");
            break;

			case 8:
			printf("Nhap gia tri m: ");
                scanf("%d", &m);
                arr[n] = m;
                for (j = 0; j < n; j++) {
                    if (arr[j] < m) {
                        for (i = n; i > j; i--) {
                            arr[i] = arr[i-1];
                        }
                        arr[j] = m;
                        break;
                    }
                }
                printf("Mang sau khi chen gia tri m va sap xep giam dan la:\n");
                for (j = n; j >=0 ; j--) {
                    printf("%d ", arr[j]);
                }
                printf("\n");
                break;	
        	case 9:
			printf("\nEnd.\n");
                break;
	default:
                printf("\nLua chon khong hop le vui long chon lai.\n");
        }
    } while (choice != 9);

    return 0;
}
