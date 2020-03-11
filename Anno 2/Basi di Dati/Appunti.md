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
