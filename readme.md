Nazwa, cokolwiek: nevermind


Opis/zalozenia:

Strategia turowa,
odbijanie zakladników przez oddzial specjalny z bazy terorystów

mapa 10x10 zlozona z kafelków,
generowana losowo

oddzial 4 antyterrorystów, mozliwy dobór klas.


Plan rozgrywki:

1. Generowanie mapy
2. Caly oddzial jest zawsze w jednym miejscu na mapie
3. w petli
    1. Opis pozycji.
    2. Wykonanie ruchu przez oddzial:
        - Przeladowanie broni
        - Poruszanie sie
        - Walka z obecnymi zagrozeniami
     jesli zostanie wybrane poruszanie sie, to leci punkt 3:
    3. Reakcja otoczenia/pola
        - Puste, idziesz dalej
        - Drzwi, otwierasz i opis tego co sie dzieje i przejscie na kolejne pole za drzwiami
        - Walka <do obmyslenia>
        - Zakladnicy - koniec gry
    4. Podsumowanie tury - obrazenia, straty w eq, zgony, cokolwiek
    
    
Plan implementacji:
1. Kafelki
2. Zolnierze i wrogowie
3. Mechanizmy walki
4. Mapa (generowanie)
5. Spiecie razem powyzszych
6. Prosty interfejs?? cokolwiek



mechanika zolnieza
	zadajObrazenia()
		przyjmuje obiekt do ktorego strzelam i odleglosc,
		liczy prawdopodobienstywo trafienia
		jesli trafie, base_damage+-bonus(+-x)
	przyjmijObrazenia()
		odejmij sobie hp.

	



