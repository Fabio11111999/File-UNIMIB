## Comandi R ### 
 ###  Statistica Descrittiva Parte 1 ###
 - Caricare un file: ```f=file.choose()```.
 - Leggere un file: ```x=scan(f,sep=";")```. f è il file, sep è il separatore dei dati.
 - Leggere un file: ```x=scan(f,sep=";",dec=",")``` f è il file, sep è il separatore dei dati, dec indica il carattere per la virgola.
 -  Valore minimo del dataset: ```min(x)```.
 -  Valore massimo del dataset: ```max(x)```.

**Dati quantitativi discreti:**
 -  Frequenza assoluta: ```table(x)```.
 -  Frequenza relativa: ```prop.table(table(x))```.
  - Frequenza cumulata assoluta: ```cumsum(table(x))```.
 - Frequenza cumulata relativa: ```cumsum(prop.table(table(x)))```.
 -  Grafico a barre: ```barplot(table(x),xlab="label asse x",ylab="label asse y",main="titolo grafico")```.
 - Grafico StripChart: ```stripchart(x,method="stack",xlab = "label assex")``` .

**Dati quantitativi continui:**
 - Grafico istogramma:  
	 -  ```hist(x)```: R disegna un grafico scegliendo autonomamente gli intervalli in cui dividere i valori.
	 - 2```hist(x,v)```: ```v``` contiene gli estremi degli intervalli in cui dividere il dataset, esempio:```hist(x,c(0.4,1.5,2.3,3,4,5.5))```
- Grafico IndexPlot: ```plot(x,xlab="label asse x", ylab="label asse y")```.

 ### Statistica Descrittiva Parte 2 ###
 - Ordinamento:
	 - Crescente: ```sort(x)```.
	 - Decrescente: ```sort(x,dec=T)```.
 - Media: ```mean(x)```.
 - Mediana:```median(x)```.
 - Moda:```table(x)[table(x)==max(table(x))]```.

**Indici di dipersione**
- Varianza:```var(x)```.
- Deviazione Standard: ```sd(x)``` o ```sqrt(var(x))```.
- Quantili:```quantile(x,v)``` dove ```v``` è il vettore con le probabilità, esempio: ```quantile(x,c(0.25,0.5,0.75))```.
- Range Interquantile(differenza tra il 75esimo quantile ed il 25esimo quantile): ```IQR(x)```.
- Range: valore minimo e massimo: ```range(x)```.
