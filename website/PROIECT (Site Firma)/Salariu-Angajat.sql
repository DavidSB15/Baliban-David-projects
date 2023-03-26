SELECT Angajati.Nume, Angajati.Prenume, Salariu.Valoare
FROM Angajati
INNER JOIN Salariu ON Angajati.ID = Salariu.ID;