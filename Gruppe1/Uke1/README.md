# SSH og SCP

## Innlogging med SSH
I terminalen din skriver du:
```
ssh <brukernavn>@login.ifi.uio.no
```

Hvis du skal lage en mappe for in2140 via SSH kan du gjøre følgende:

```
mkdir in2140-v24
cd in2140-v24
mkdir ukesoppgaver
mkdir obliger
```

## Filoverføring
```
scp -r sample.txt <brukernavn>@login.ifi.uio.no:~/gruppelaerer/testern
```

## Overføre alt innholdet i mappen du befinner deg i
```
scp -r * <brukernavn>@login.ifi.uio.no:~/gruppelaerer/testern
```

## Overføre en mappe
```
scp -r ./gruppelaerer <brukernavn>@login.ifi.uio.no:<dest>
```

## Slette en fil
```
rm -r "sample.txt"
```

## Slette alt innholdet i en mappe
```
rm -r *
```

## Slette en mappe
```
rm -r <mappenavn>
```

relativ mappe NB: merk at når det er mellomrom i en filbane så kan du legge til fnutter "he he", så det fortsatt tolkes som ett argument Ett argument:
```
"./ett argument"
```