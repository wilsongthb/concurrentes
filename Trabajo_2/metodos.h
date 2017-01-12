#pragma once
void SelectionSort(int *array, int n) {
	int x, y, min, tmp;
	for (x = 0; x < n; x++) {
		min = x;
		for (y = x + 1; y < n; y++) {
			if (array[min] > array[y]) {
				min = y;
			}
		}
		tmp = array[min];
		array[min] = array[x];
		array[x] = tmp;
	}
}

void Shell(int *array, int n) {
	int i, x, y, tmp;

	for (i = 1; i < n; i = i * 3 + 1) {} //la idea es que SOLO se incremente i a razón de i*3+1 por repetición

	while (i > 0) {
		for (x = i; x < n; x++) {
			y = x;
			tmp = array[x];
			while (y >= i && array[y - i] > tmp) {
				array[y] = array[y - i];
				y = y - i;
			}
			array[y] = tmp;
		}
		i = i / 2;
	}
}

void IBinaria(int *array, int n) {
	int x, y, m, tmp, izq, der;
	for (x = 1; x < n; x++) {
		tmp = array[x];
		izq = 0;
		der = x - 1;
		while (izq <= der) {
			m = (izq + der) / 2;
			if (tmp < array[m]) {
				der = m - 1;
			}
			else {
				izq = m + 1;
			}
		}
		y = x - 1;
		while (y >= izq) {
			array[y + 1] = array[y];
			y = y - 1;
		}
		array[izq] = tmp;
	}
}

void IDirecta(int *array, int n) {
	int x, val, y;
	for (x = 1; x < n; x++) {
		val = array[x];
		y = x - 1;
		while (y >= 0 && array[y] > val) {
			array[y + 1] = array[y];
			y--;
		}
		array[y + 1] = val;
	}
}

void QuickSort(int *array, int inicio, int final) {
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
		}
	} while (i <= f);

	if (inicio < f) {
		QuickSort(array, inicio, f);
	}

	if (i < final) {
		QuickSort(array, i, final);
	}

}

void Burbuja(int *array, int n) {
	int x, y, tmp;
	for (x = 1; x < n; x++) {
		for (y = 0; y < n - x; y++) {
			if (array[y] > array[y + 1]) {
				tmp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tmp;
			}
		}
	}
}

void Print(char *function, int *array, int n) {
	int x;
	printf("%s:", function);
	for (x = 0; x < n; x++) {
		printf(" %i", array[x]);
	}
	printf("\n");
}
