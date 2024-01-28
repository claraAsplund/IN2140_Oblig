**Tema for uken:** håndtering av bits, hva er true og false i C, boolske operatorer, bruke bits som flags

# True og false i C

I C har vi ikke boolean datatyper. Vi bruker i stedet 0 eller et hvilket som helst annet tall for å indikere at noe er henholdsvis usant eller sant. For eksempel blir 1 mye brukt for å indikere verdien sant. Flere andre programmeringsspråk har også støtte for liknende bruk av sannhetsverdier (for eksempel Python).

I dette veldig enkle programmet printer vi ut en liten setning dersom verdien inni parentesen er sann. Det er den både ved 1 og !0.

```cpp
#include <stdio.h>

int main(void)
{
    if (1)
    {
        printf("Sann!");
    }
    if (!0)
    {
        printf("Ikke usann!\n");
    }
}
```

Output i terminal:

```bash
Sann!Ikke usann!
```

Noen andre boolske operatorer i C er `&&` (AND) og `||` (OR).

# Bits

I C kan vi skrive tall med binær representasjon ved å bruke `0b` som prefiks. Datatypen vi bruker bestemmer størrelsen til dette binære tallet. Altså, dersom vi bruker en char (1 byte) får vi et binært tall med 8 bits, for eksempel 0b00000001. Dersom vi bruker en short (2 bytes) så får vi et binært tall med 16 bits, og på lik måte vil en long(4 bytes) være hele 32 bits(!). Denne uken skal dere lære dere å gjøre en rekke operasjoner på bits.

Dere skal kunne å bruke disse operasjonene:

- `<<` flytt til venstre (left shift)
- `>>` flytt til høyre (right shift)
- `&` bitwise AND
- `|` bitwise OR
- `^` bitwise XOR
- `~` bitwise NOT

Å flytte bitsene kaller vi også bitshifting.

<details>
<summary>Eksempel</summary>

Flytte en bit seks plasser opp: \
`char c = 1 << 6`\
`>> 0b01000000`

Flytte to plasser nedover: \
`c >> 2` \
`>> 0b00010000`

Kan flytte den utenfor byten vår: \
`char c = 1 << 8` \
`>> 0b00000000`

</details>

Se også bitops.c. Vi kan forsåvidt kombinere `&`, `|`, `^` og `~` med `=`, slik som vi for eksempel gjør i flagg.c.

Men hvorfor er det nyttig å kunne gjøre operasjoner på bits? Som nevnt er 0 eller 1 måter å si om noe er sant eller usant på i C. En effektiv måte å lagre flere sannhetsverdier på er å lagre det som en binær representasjon av for eksempel en char. Dersom man skulle brukt for eksempel to int'er hadde dette tatt mye mer plass, og det vil vi jo ikke. Slik bruk kaller vi å **bruke bits som flagg**. Se flagg.c for et eksempel.

Vi kan også lagre flere verdier inni ett binært tall. For eksempel har man i filen masking.c lagret en universitetssøknad som et binært tall av størrelse 16 bits, altså en short:
`unsigned short soknad1 = 0b0000000011001010;`. Her er de første 8 bitsene en donasjon, de nestre 3 et karaktersnitt og de siste 5 bitsene er en ID. Ved å ta i bruk noe vi kaller **masker** kan vi hente ut bestemte deler av denne bitstrengen. Selv om hele søknaden bare er lagret som en rekke av sammenhengende bits. Dersom vi vil ha de siste 5 tallene (som er en ID) lager vi en maske som henter ut de siste 5 tallene:

```cpp
unsigned char hent_id(unsigned short s)
{
    return s & 0b0000000000011111;
}
```

Vi kan gjøre tilsvarende for donasjon (de første 8) og karaktersnitt (s & 0b0000000011100000), men vi får masse nuller etterpå, altså får vi ikke det rette tallet. Da bruker vi >> for å flytte tallet lenger bort. Masking har flere nyttige anvendelser, for eksempel er bildefiltre lagd ved å legge masker på RGB-verdiene til pikslene. Se masking.c.
