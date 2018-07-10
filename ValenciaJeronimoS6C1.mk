graficas.pdf : datosPendulo.dat
	python plot.py
	xdg-open graficas.pdf

datosPendulo.dat : datosPendulo.exe
	./datosPendulo.exe > datosPendulo.dat

datosPendulo.exe : ValenciaJeronimoS6C1.cpp
	g++ ValenciaJeronimoS6C1.cpp -o datosPendulo.exe
