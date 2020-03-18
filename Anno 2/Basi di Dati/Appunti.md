# Basi di dati 

## 1 Introduzione alle Basi di Dati

### 1.2 Dagli archivi tradizionali alle basi di dati

**Base di Dati** : insieme organizzato di dati utilizzati per lo svolgimento di determinate attività.
**Possibili Problemi** : 
1. Ridondanza: informazioni duplicate.
2. Incoerenza: versioni differenti non coincidono.

La base di dati è integrata, ossia condivisa tra i vari settori di un'organizzazione in quanto esistono sovrapposizioni fra i dati di interesse tra i settori.

### 1.3 Sistema di Gestione di Basi di Dati
La base di dati è una risorsa integrata condivisa tra le varie applicazioni, quindi:
 1. Attività diverse su dati condivisi parzialmente: 
	 - Meccanismi di autorizzazione.
 2. Attività multi-utente su dati condivisi:
	 - Controllo della concorrenza.

Necessità di un **Sistema di gestione di basi di dati**.
Il **DBMS** è un prodotto software in grado di gestire collezioni di dati:
- Grandi.
- Persistenti.
- Condivise

Garantendo:
 - Affidabilità.
 - Sicurezza.
 - Efficienza. 

**Schema**: Insieme dei concetti e delle relazioni tra i concetti rappresentati nella base di dati (Insegnamento,Docente,Aula,Ora).
**Istanza**:I dati effettivamente memorizzati.
 **Modello**: Insieme di costrutti utilizzati per organizzare i dati di interesse in concetti e descriverne la dinamica.
 
 **Modello logico:**
- Utilizzati dai programmi.
- Indipendenti dalla strutture fisiche.
 - **Modello relazionale**: Tramite il costrutto relazione definisce insiemi di record omogenei
 - Altri modelli: reticolare, gerarchico, a oggetti...

**Modello concettuale:** permette di rappresentare i dati in modo indipendente da ogni **DBMS** cercando di descrivere direttamente i concetti, utilizzato principalmente nella fase iniziale. Il modello più noto è quello **Enitità Relazione**.

### 1.4 Architettura di un Sistema di  Gestione di Basi di Dati.

Architettura a 2 livelli:
1. **schema logico:** descrizione della base di dati con strutture ad alto livello (relazione).
2. **schema fisico:** rappresentazione dello schema logico tramite strutture fisiche di memorizzazione.

**Indipendenza dei dati:** 
- Il livello logico è indipendente da quello fisico, una relazione è indipendente dalla sua realizzazione fisica.
- Il livello esterno (utente) è indipendente dal livello logico, all'utente che utilizza le applicazioni non interessa come sono memorizzate logicamente.
- Il livello esterno è indipendente da quello fisico: la realizzazione fisica può cambiare senza che debbano essere modificati i programmi software.

**Linguaggi usati in un DBMS:**
1. **DDL:** Data Description Language: Linguaggio di descrizione dei dati, con cui si descrivono le strutture degli schemi.
2. **DML:** Data Manipulation Language: Linguaggio di manipolazione dei dati, con cui si esprimono le interrogazioni che ritrovano i dati dalla base di dati.
## Il Modello Entità Relazione ##
 **Strutture di rappresentazione nel modulo ER**
 - **Entità**: classe di oggetti che:
   - Sono d'interesse per l'applicazione.
   - Hanno esistenza autonoma.
   - Hanno proprietà comuni. 
   - Identificata da un nome unico nello schema e rappresentata tramite un rettangolo.
   - Un'istanza di un'entità rappresenta un oggetto dell'insieme rappresentato,
 - **Attributi di entità**: proprietà locale di un'entità il cui valore dipende solamente dall'istanza e non da altri elementi dello schema:
   - Il valore dell'attributo appartiene ad un dominio.
   -  Ogni attributo ha un nome univoco nell'ambito dell'entità.
 - **Relazioni**: Si definiscono su 2 o più entità, rappresentano un legame logico tra tali entità:
   - Il numero di entità coinvolte rappresenta il grado della relazione. 
   - Ha un numero che la identifica in modo univoco nello schema.
   - Rappresentata tramite un rombo che collega le entità che coinvolge.
   - Una relazione che coinvolge più di 2 entità si dice N-aria.
 - **Attributi di relazione:** proprietà locale di una relazione ai fini dell'applicazione:
   - Associa ad ogni istanza di relazione un valore appartenente ad un insieme detto dominio dell'attributo. 
   - Un vincolo di cardinalità tra un'entità E ed una relazione E esprime un limite minimo ed un limite massimo di istanza di R a cui può partecipare E.
   - A secondo delle cardinalità massime una relazione si definisce 
     - 1 a 1.
     - 1 a Molti.
     - Molti a Molti. 
   - Un attributo composto è formato da più sotto attributi chiamati campi, il dominio di un attributo composto è chiamato record. 
 - **Relazioni IS-A**: rappresenta una relazione di sottoinsieme tra le entità: gli attributi di un'entità figlia sono un sottoinsieme degli attributi di un'entità padre 
   - La rappresentazione grafica consiste in una freccia che parte dall'entità figlia verso quella padre.
   - Ogni proprietà dell'entità padre(attributo/relazione) è proprietà anche dell'entità figlia.
 - **Generalizzazioni**: L'entità padre generalizza più entità figlie secondo un unico criterio. La generalizzazione può essere:
     - Completa:l'unione delle istanze delle sotto entità è uguale all'insieme delle istanze dell'entità padre *Persona <- Uomo / Donna*. **[Rappresentazione nera].**
     - Non completa. **[Rappresentazione bianca].**
 - **Identificatori**: un identificatore di un'entità è un insieme di proprietà che permettono di identificare univocamente le istanza di un'entità.
   - L'identificatore di un entità E può essere:
     - Interno: formato solo da attributi di E.
     - Esterno: formato da attributi di E e/o da relazione che coinvolgono E (matricola di uno studente e le relazione che stabilisce a quale università appartiene).

## Il Modello Relazionale ##

**Modello logico:** insieme di strutture e rappresentazioni utilizzabili per descrivere un insieme di dati, o schema logico, che a sua volta descrive una realtà di interesse.

**Modello relazionale** struttura posizionale per distinguere i domini, oppure non posizionale ed ad ogni dominio si assegna un nome (attributo).
In una relazione del modello relazionale:
- I valori di ogni colonna sono fra loro omogenei.
- Le righe sono diverse tra loro.
- Le intestazione delle colonne sono diverse tra loro.
- L'ordinamento delle righe è irrilevante.
- L'ordinamento delle colonne è irrilevante.

Il modello relazionale è basato sui valori, vantaggi:
- L'utente finale vedi gli stessi dati dei programmatori.
- Indipendenza della rappresentazione dalle strutture fisiche.
- I dati sono portabili più facilmente da un sistema all'altro.

**Schema di relazione:** un nome $R$ con un insieme di attributi $A_1,...,A_n$: $R(A_1,...,A_n)$.
**Schema di basi di dati:** insieme di schemi di relazione:
$R=\{R_1(X_1),...,R_k(X_k)\}$

Un ennupla su un insieme di attributi $X$ è una funzione che associa a ciascun attributo $A$ in $X$ un valore del dominio di $A$: ```t[A]``` rappresenta il valore dell'ennupla $t$ sull'attributo $A$.

**Istanza di relazione** su uno schema $R(x)$: insieme $r$ di ennuple su $X$.
**Istanza di base di dati:** su uno schema $R=\{R_1(X_1)...,R_n(X_n)\}$: insieme dei relazinoe $r=\{r_1,...,r_n\}$


Vincolo di integrità: proprietà che devono essere soddisfatte per tutte le istanza di uno schema che rappresentano informazioni corrette per un'applicazione, è una funzione booleana che associa ad ogni istanza di $r$ vero se è corretta, altrimenti falso.
I vincolo di integrità contribuiscono a rappresentare i dati in modo più accurato, tornano utili anche nella fase di progettazione.
Vincoli:
- Intrarelazionali: definiti in un'unica relazione:
  - Vincoli sui singoli valori (voto compreso tra 18 e 30).
  - Vincoli di ennupla: condizioni su ciascuna ennupla della relazione (non ci possono essere due ennuple con la stessa matricola). Definiamo una sintassi:
    - Espressioni booleane AND, OR, NOT , atomi di confronto: > >=, =, <, <=, $\neq$ e valori di attributo / espressioni aritmetiche.
  - Vincoli di relazione (tra cui i vincoli di chiave):
    - Vincolo di chiave: insieme di attributi che identificano le ennuple di una relazione. un insieme $K$ di attributi è **superchiave** per una relazione $r$ se $r$ non contiene due ennuple distinte $t_1, t_2$ tali che $t_1[K]=t_2[K]$. Il concetto di chiave corrisponde a quello di superchiave minimale ($K$ è una superchiave minimale se $K$ è superchiave ma nessun suo sottoinsieme lo è).
    **I vincoli di chiave si riferiscono allo schema e non alle istanze.** Le chiavi garantiscono l'accessibilità e permettono di collegare i dati di relazioni differenti.
- Interrelazionali: definiti su più relazioni. 

Valori nulli:
1. Valore sconosciuto (ma esiste).
2. Valore inesistente.
3. Senza informazione: non si sa se esiste o meno.
Per rappresentare un'informazione nulla si estende il dominio degli attributi con il valore NULL, i valori nulli nelle chiavi devono essere limitati. La **chiave primaria** è una chiave su cui non sono ammessi valori NULL (sottolineata nello schema)

Vincolo di integrità referenziale: Esprime la proprietà per cui informazioni con stesso significato in relazioni diverse sono correlate: non è possibile che un valore sia rappresentato nella sua relazione con un altro oggetto ma non sia rappresentato ed identificato nella tabella che lo descrive.
Definizione Formale: Un vincolo di integrità referenziale, tra un insieme di attributi $X$ di una relazione $R_1$ e un'altra relazione $R_2$ impone ai valori su $X$ in $R_1$ di comparire come valori della chiave primaria di $R_2$.

Nel caso in cui un inserimento non rispetti i vincoli di integrità referenziale, si possono attuare una delle seguenti:
- Rifiuto l'operazione.
- Eliminazione a cascata.
- Introduzione di valori nulli.
