**Tema:** lister, trær og grafer med structer i C, serialisering for skriving til fil, om minnelayout for strukter.

Vi har ikke noen egne lenkelister, trær eller grafobjekter i C, men vi har structs. Vi kan bruke structs til å lage disse datastrukturene. Se enkel_lenkeliste.c og bintre.c. Dersom du vil vite mer om grafer i C er dette en veldig god artikkel: https://www.techiedelight.com/implement-graph-data-structure-c/.

Serialisering handler om å ta et objekt som vi for eksempel vil lagre til en fil eller sende over nettet, og serialisere det til et portabelt/kompakt format, slik at vi kan bruke det senere.

__Korrigert:__
For sending over nett er htonl og nthol funksjoner som konverterer fra host (altså vår) sin byte order til network byte order. Network byte order er en standarisert ordning av bytes som blir brukt til nettverkskommunikasjon. Dette er viktig fordi forskjellige maskinarkitekturer bruker forskjellige byte orders for å lagre datatyper som bruker flere bytes, som for eksempel heltall. For skriving til fil på samme pc er det irrelevant.
Det er ingenting galt med serialiseringen i filene. Men i praktiske situasjoner ville det vært unødvendig å bruke de gitte funksjonene nthol og htnol.

Som vi nevnte kort for to uker siden har structer i C padding. Dette er på grunn av noe som heter alignment, som gir oss kortere kjøretid. Akkurat hvordan alignment fungerer er ikke ekstremt viktig for dette kurset. Noen ganger vil vi ikke ha denne paddingen, for eksempel for å spare minne. Da kan vi legge på en \_\_attribute\_\_((packed)) etter structen.

```cpp
struct my_struct {
    char a;
    int b;
    short c;
} __attribute__((packed));
```
For eksempler på serialisering og hvordan minnelayouten for structs fungerer, se de vedlagte filene i denne mappen.
