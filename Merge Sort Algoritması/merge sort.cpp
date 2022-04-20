#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///////////////////////////////////////////////////////////////////////////////
void merge(int arr[], int p, int q, int r) 
{
    int n1 = q - p + 1; // sol ve sag ýndýsler elemanlarý olusturuldu
    int n2 = r - q;

    int L[n1], M[n2]; //diziler tanýmlandý

    for (int i = 0; i < n1; i++) // orjýnal dýzý sol lop olusturuldu
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++) // orjýnal dýzý sag lop olusturuldu
        M[j] = arr[q + 1 + j];

    
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {  ///sol sag kendý ýcýnde sol daha kucuk olacak sekýlde elemanlar yerlestýrýldý 
        if (L[i] <= M[j]) { 
            arr[k] = L[i]; 
            i++;
        } else {
            arr[k] = M[j]; 
            j++;
        }
        k++;
    }

    while (i < n1) { // kalan sol elemanlarý yerlestýrýlýr 
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {// kalan sað elemanlarý yerlestýrýlýr 
        arr[k] = M[j];
        j++;
        k++;
    }
}

///////////////////////////////////////////////////////////////////////////////////
void mergeSort(int arr[], int l, int r) // olusan dýzýlerý ýkýye bolmeyle gorevlý 
{
	
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    
}
////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int k;
	int i;
	int size;
	int dizi[17]={10,9,8,7,6,1,2,3,4,5,6,11,12,13,14,15,16};
	mergeSort(dizi,0,17);
	
	printf("sonuc:\n");
	
	for(i=1;i<18;i++)
	{
		printf("%d\n", dizi[i]);
	}
	
}

////























///////////////////////////////////////////////////////////////////////////////////////
