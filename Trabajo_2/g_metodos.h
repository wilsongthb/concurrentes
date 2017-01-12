#ifndef G_METODOS_H_INCLUDED
#define G_METODOS_H_INCLUDED

//tamaño de la ventana
#define MAX_X 600
#define MAX_Y 600

//tiempo de espera en cada iteracion
#define TIEMPO_CICLO 1
//longitud de los arrays
#define N 290
//valor maximo dentro de los arrays
#define MAX_N 290

void llenar_array(int *arr){
    for (int i = 0; i < N; i++) {
        arr[i] = 0 + rand()%MAX_N;
	}
}
void graficar_array(int *arr,int x,int y ){
    /*
        Muestra el array representado por lineas, estas se despliegan hacia la derecha
        su altura se define segun el valor del array en esa posicion
        de 0 a N
    */
    int POS_X = x;
    for(int i = 0; i < N; i++){
        //line(POS_X, y-arr[i]+1, POS_X, y-arr[i]);
        line(POS_X, y, POS_X, y-arr[i]);
        POS_X++;
    }
}
void G_Burbuja(int *array, int n) {
	int x, y, tmp;
	for (x = 1; x < n; x++) {
		for (y = 0; y < n - x; y++) {
			if (array[y] > array[y + 1]) {
				tmp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tmp;

				Sleep(TIEMPO_CICLO);
			}
		}
	}
}
void _QuickSort(int *array, int inicio, int final) {
	int i = inicio, f = final, tmp;
	int x = array[(inicio + final) / 2];
	do {
		while (array[i] < x && f <= final) {
			i++;
		}
		while (x < array[f] && f > inicio) {
			f--;
		}
		if (i <= f) {
			tmp = array[i];
			array[i] = array[f];
			array[f] = tmp;
			i++; f--;

			Sleep(TIEMPO_CICLO);
		}
	} while (i <= f);

	if (inicio < f) {
		_QuickSort(array, inicio, f);
	}

	if (i < final) {
		_QuickSort(array, i, final);
	}
}
void G_QuickSort(int *array, int n) {
    _QuickSort(array, 0, n);
}
void G_IDirecta(int *array, int n) {
	int x, val, y;
	for (x = 1; x < n; x++) {
		val = array[x];
		y = x - 1;
		while (y >= 0 && array[y] > val) {
			array[y + 1] = array[y];
			y--;

			Sleep(TIEMPO_CICLO);
		}
		array[y + 1] = val;
	}
}
/********************* METODO DE ORDENACION POR MEZCLA *******************/
void mezclar(int A[], int izq, int der, int centro)
{
  int i=izq;
  int j=centro+1;
  int* aux= new int[der-izq+1];
  int k=0;

  while ((i<=centro) &&(j<=der))
  {
      if(A[i]<A[j])
      {
          aux[k]=A[i];
          i++;
      }
      else
      {
          aux[k]=A[j];
          j++;
      }
      k++;
  }

  while (i<=centro)
  {
      aux[k]=A[i];
      i++;
      k++;
  }

  while (j<=der)
  {
      aux[k]=A[j];
      j++;
      k++;
  }

  for(i=0;i<k;i++)
  {
      A[i+izq]=aux[i];
      Sleep(TIEMPO_CICLO);
  }

}
void ordenarMezcla(int A[], int p, int q)
{
  int centro=0;
  if (p<q)
  {
      centro=(p+q)/2;
      ordenarMezcla(A,p,centro);
      ordenarMezcla(A,centro+1,q);
      mezclar(A,p,q,centro);
  }
}
void Merge(int *arr, int n){
    ordenarMezcla(arr,0,n);
}

#endif // G_METODOS_H_INCLUDED
