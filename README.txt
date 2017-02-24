Task 1

Am inceput prin declararea unui vector de pointeri "Text", fiecare pointer aratand spre o linie din text, alocandu-i dinamic memorie. In functie de datele introduse apelez una dintre cele 3 operatii si trimit ca si parametrii vectorul de pointeri si numarul de linii.

Operatia 1
Parcurg textul pe linii, prelucrand doar cate una. Citesc cuvantul dorit si copiez valoarea liniei intr-un aux in care izolez cuvintele cu functia strtok. Compar cuvintele gasite cu cel dorit si atunci cand cele doua sunt egale, cresc cu 1 valoarea unei variablie pe care o afisez la sfarsit.

Operatia 2
Parcurg textul pe linii, prelucrand doar cate una. Citesc cuvantul vechi si cuvantul nou. Doresc sa parcurg linia principala si sa fac modificari in aceasta dar risc sa pierd pointerul la inceputul liniei  asa ca imi declar un pointer caruia ii dau adresa liniei. Caut cu strstr cuvantul vechi in pointer si copiez de la sfarsitul cuvantului pana la sfarsitul liniei in aux. Copiez peste cuvantul vechi pe cel nou caruia ii concatenez restul liniei pastrata in aux. La sfarsit mut adresa pointerului la sfarsitul cuvantului nou si eliberez memoria tinuta in aux

Operatia 3
Parcurg textul pe linii, prelucrand doar cate una. Citesc numarul de permutari si copiez valoarea liniei intr-un aux in care izolez cuvintele cu functia strtok. Iau iarasi un pointer la linia originala. Caut in adresa pointerului cuvintul gasit cu strtok si il permut. Deoarece dupa un numar=strlen(cuvant) permutarile se repeta pot eficientiza permutand doar de nr_permutari % strlen(cuvant). Permutarea o fac pastrand ultima litera a cuvantului si mutandu-le pe celelate cu o pozitie inainte lipind la inceputul cuvantului ultima litera.
Dupa ce am permutat cuvantul mut adresa pointerului la sfarsitul cuvantului si eliberez memoria lui aux.


Task 2

Pentru a eficientiza modul de citire nu am memorat textul ci am prelucrat direct linie cu linie izoland cuvintele su strtok si introducandu-le in doua liste, una pentru fiecare text. Cele doua liste sunt doi vectori de pointeri, fiecare pointer aratand spre un cuvant. In paralel cu listele am construit si doi vectori de integer in care memorez numarul de aparitii pentru fiecare cuvant. Pentru a folosi cat mai putina memorie am initializat atat listele cat si vectorii cu 1*sizeof(char*) respectiv 1*sizeof(int) iar mai apoi am realocat aceste memorii de fiecare data cand am gasit un cuvant nou, introducandu-l in lista.
Dupa ce am creat listele le-am ordonat mai intai in functie de numarul de aparitii si mai apoi alfabetic pe cele cu nr de aparitii egal. Le-am ordonat folosind un bubble-sort interschimband atat cuvintele cat si numarul de aparitii.
Dupa ce am ordomat listele, am creat functia dist unde am calculat diferenta dintre 2 cuvinte folosind metoda data. La sfarsit am calculat dupa formula data gradul de similaritate dintre cele doua texte si l-am printat.