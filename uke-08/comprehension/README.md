# Lagring

## (1) Disk scheduling algorithms

### Norsk

1. Tilgang til sekundær lagring som mekaniske harddisker tar mye tid sammenlignet med tilgang til minne i RAM. Forklar kort hvorfor og hvilke operasjoner tilgangsforsinkelsen består av.

2. Hva gjøres vanligvis for å forbedre ytelsen til mekaniske disker i dag når det gjelder tilgangsforsinkelser og dataoverføringer?

Nevn 2 tilnærmingen og forklar dem.

3. La oss anta at vi har en (veldig liten) disk som har 50 spor, nummerert fra 0 til 49, og som diskhodet beveger seg over og leser data fra. Anta at på et gitt tidspunkt er diskhodet plassert over og leser data fra spor 14. Etter denne forespørselen er følgende forespørsler i diskscheduleringskøen (hvert nummer angir sporet som den forespurte datablokken er lagret på, og sekvensen viser rekkefølgen forespørslene ankom i køen, dvs. forespørsel 2 er den første som ankom systemet):

45 15 3 49 19 40 5 16 33 9 17 23 46 2

Lag en grafisk figur som viser hvordan diskhodet beveger seg over de forskjellige sporene (i hvilken rekkefølge betjenes forespørselene) hvis vi bruker "First-Come-First-Serve" (FCFS) og SCAN (hodet beveger seg for øyeblikket fra lavt nummerert spor til høynummererte spor), henholdsvis, og forutsetter at alle forespørsler i køen kan betjenes i samme runde.

### Engelsk

1. Accessing secondary storage like mechanical hard drives takes a lot of time compared to accessing memory in RAM. Briefly explain why and what operations the access latency consists of.

2. What is typically done to improve the performance of mechanical disks today in terms of access latencies and data transfers?

State 2 approaches and explain them.

3. Let us assume that we have a (very small) disk which has 50 tracks, numbered from 0 to 49, and which the disk head moves above and reads data from. Assume that at a given time, the disk head is positioned above and reading data from track 14. After this request, the following requests are in the disk scheduling queue (each number denotes the track on which the requested data block is stored, and the sequence shows the order in which the requests arrived in the queue, i.e., request 2 is the first that arrived in the system):

45 15 3 49 19 40 5 16 33 9 17 23 46 2

Make a graphical figure that shows how the disk head moves over the different tracks (in what order are request serviced) if we use “First-Come-First-Serve” (FCFS) and SCAN (the head is currently moving from low-numbered tracks to high-numbered tracks), respectively, and assume that all requests in the queue can be served during the same round.

## (2) File systems

### Norsk

Den fysiske representasjonen av data, uansett medium, er sjelden så ren og ryddig som det kan se ut som for applikasjonen eller applikasjonsprogrammereren. Når det gjelder disklagring, er det filsystemet som gir logikken som forvandler det underliggende «kaoset» til orden.

1. Bortsett fra å tildele lagringsplass til filer, hva er noen andre viktige oppgaver som filsystemet håndterer?

2. Et mye brukt filsystem er EXT4 på Linux, som bruker inoder for lagring av metadata. Forklar hvordan EXT4 kan støtte svært store filer.

3. Du har til oppgave å designe et system som skal lagre store datamengder, og som også krever høyst tilgjengelig og redundant lagring. Velg en teknologi som tjener disse formålene og forklar hvordan den gjør det.

### English

The physical representation of data, whatever medium, is seldom as neat and tidy as it may appear to the application or application programmer. In the case of disk storage, it is the filesystem that provides the logic that transforms chaos into order.

1. Apart from allocating storage space for files, what are some other important tasks that the filesystem handles?

2. A widely used filesystem is EXT4 on Linux, which uses inodes for storing metadata. Explain how EXT4 is able to support very large files.

3. You are tasked with designing a system that is supposed to store large amounts of data, and that also requires highly available and redundant storage. Choose a technology that serves these purposes and explain how it does so.


## (3) Disk layout

### Norsk

Fra brukerens perspektiv fremstår en fil som en enkelt, sammenhengende enhet. Dette er imidlertid sjelden hvordan blokkene er lagret på disk. En fils blokker kan spenne over flere sektorer, spor og plater, sammenflettet med annen ledig og brukt diskplass. Det er filsystemet som sørger for nødvendig mapping mellom blokker og filer.

1. Hvor er selve filsystemet lagret?

2.  Hvis filsystemet ødelegges, går alle data på disken – i det minste i betydningen lesbare filer og kataloger) – tapt. Hva kan gjøres for å redusere denne sårbarheten?

3. Kjeding i media og kjeding i kart er to teknikker for å holde oversikt over hvilke blokker som tilhører hvilke filer. Sammenlign disse teknikkene og forklar hvordan sistnevnte forbedrer effektiviteten for tilfeldig aksess.

### English

From the users’ perspective, a file appears as a single, contiguous entity; however, this is seldom how its constituent blocks are stored on disk. One file’s blocks may span several sectors, tracks and platters, interleaved with other free and used disk space. It is the file system that provides the necessary mapping between blocks and files.

1. Where is the file system itself stored?

2. If the file system is corrupted, all data on the disk—at least in the sense of readable files and directories—are lost. What can be done to reduce this vulnerability?

3. Chaining in media and chaining in map are two techniques for keeping record of which blocks belong to which files. Compare these techniques and explain how the latter improves efficiency for random access.

