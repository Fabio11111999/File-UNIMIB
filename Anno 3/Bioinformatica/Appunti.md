### Lezione 2

- $H(S) = \sum_{i=1}^{|S|} 2^{i-1}* H(S[i])$
- Sliding window di ampiezza m su T.
- $H(T[i+1:i+m]) = (H(T[i:i+m-1]) -T[i])/2+2^{m-1}T[1+m]$ : per passare dalla finger-print $[i:m-1]$ a $[i+1:m]$. Tolgo il primo carattere (quello rappresentato da $2^0$), divido per 2 in modo di shiftare la finger-print a destra di 1. Aggiungo poi l'ultimo carattere (lo devo moltiplicare per $2^{m-1}$.
- Come controllo se esiste un'occorrenza: $T[i:i+m-1]=P$ SSE $H(T[i:i+m-1])=H(P)$
- Questo algoritmo al momento non è lineare, il valore della finger-print può valere fino a ~$2^{m-1}$, fare le operazioni su numeri così grandi impiega un tempo logaritmico rispetto al numero. Quindi essendo il numero esponenziale , $log(2^{m-1})$ = $O(m)$ tornando quindi a complessità $O(nm)$.
- Devo quindi aggiungere un modulo, rende l'algoritmi lineare ma diventa probabilistico. 

- Aggiungo il modulo in tutte le operazioni.
-Problemi dell'aggiunta del modulo:
  - Falso positivo (FP): occorrenza non vera.
  - Non esistono i falsi negativi. Se $x≠y$ allora $x\%z ≠ y\%z$ 

Per diminuire la probabilità di errori lo eseguo con $K$ numeri primi differenti e poi faccio l'intersezione dell'insieme delle soluzioni. Faccio l'intersezione perché Karp-Rabin non ammette falsi negativi, allora basta che la finger-print di una finestra non risulti essere congrua alla finger-print del pattern per un singolo primo per essere sicuro che quella finestra non corrispondi al pattern. 

**Analisi degli errori**: 
- $P[\#FP \geq=1] \leq O(nm/I)$: $I$ numero primo maggiore usato.

**Algoritmi probabilistici**: due tipologie:
- Monte Carlo: 
  - Sempre veloce.
  - Forse non corretto.
 - Las Vegas:
   - Sempre corretto.
   - Forse non veloce. 

L'algoritmo Karp-Rabin presentato appartiene alla categoria Monte Carlo, ma posso "renderlo" Las Vegas verificando che le occorrenze trovate precedentemente siano effettivamente corrette (controllando manualmente). La complessità aumenta però all'aumentare delle occorrenze diventando dunque $O(nm)$ nel caso peggiore. 
