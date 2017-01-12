#pragma once
bool es_primo(int n) {
	int divisores = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0) {
			divisores++;
		}
	}
	if (divisores == 1) {
		return true;
	}
	return false;
}
void n_primos(int n) {
	int numero = 0;
	while (n > 0) {
		if (es_primo(numero)) {
			cout << numero << endl;
			numero++;
			n--;
		}
		else {
			numero++;
			//n--;
		}
	}
}
int n_primo(int n) {
	int numero = 0;
	int primo = 1;
	while (n > 0) {
		if (es_primo(numero)) {
			//cout << numero << endl;
			primo = numero;
			numero++;
			n--;
		}
		else {
			numero++;
			//n--;
		}
	}
	return primo;
}
void n_primos_1(
	size_t n, //numero donde empezar
	size_t m //numero de primos
	) {
	int numero = n;
	while (m > 0) {
		if (es_primo(numero)) {
			cout << numero << endl;
			numero++;
			m--;
		}
		else {
			numero++;
		}
	}
}
void genera_lista_primos(int n, int m) {
	for (int i = n; i < m; i++)
	{
		primos[i] = n_primo(i);
	}
}
void new_g(int n, int m) {
	clock_t t;
	t = clock();
	genera_lista_primos(n, m);
	t = clock() - t;
	cout << "tiempo de ejecucion: " << t << "ms" << endl;
}
void new_chrono(int n, int m){
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
        genera_lista_primos(n, m);
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> duration = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "Termino la ejecucion en " << std::ctime(&end_time)
              << "duracion: " << duration.count() << "s\n";
    //std::cout << "Termino la ejecucion en " << std::ctime(&end_time)
    std::cout<< "duracion en milisegundos: " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count()<< "ms\n";
}
void generar_primos(int n) {
	for (int i = 0; i < n; i++)
	{
		if (es_primo(i))
			cout << i << endl;
	}
}
void f() {
	cout << "hola" << endl;
}
void g() {
	cout << "mundo" << endl;
}
