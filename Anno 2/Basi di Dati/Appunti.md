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
