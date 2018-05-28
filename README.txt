Jusqu'où avez-vous été ? qu'est-ce que vous avez fait/pas fait ?

Nous avons fait tous les exercices, de P1 à P13. Ce rendu contient tous les fichiers sources et headers créés dans le cadre de ces 13 exercices. 
Nous avons fait:

Les 3 intégrateurs:
-Euler-Cromer
-Newmarck
-Runge-Kutta

3 oscillateurs differents:
-Les pendules
-Les ressorts
-Les double-ressorts

Nous n'avons pas fait:
Les oscillateurs:
-Les pendules de torsion
-Les chariots avec pendule amorti par un ressort
-Les pendules-ressort
-Les pendules double
-Les pendules reliés par un ressort


Avez-vous une version graphique ? Si oui, avec quelle bibliothèque graphique (Qt (quelle version ?), WxWidget, SDL, Glut, autre [précisez]) ?

Oui, nous avons utilise Qt 5.10.1.


Combien d'heures en moyenne par personne estimez vous avoir passé par semaine sur le projet ? (essayez d'être objectif : n'oubliez pas qu'au début vous n'avez peut être pas fait grand chose, comptez sur 14 semaines, i.e. la première semaine incluse, ne comptez pas le cours ni les exercices hors projet, n'oubliez pas de diviser le total par 2 car je veux une estimation moyenne par personne.)

En moyenne, nous estimons notre travail à 5 heures par semaine par personne. 


Comment faire fonctionner le projet?

Interface graphique:
-Aller dans le répertoire P10
-Ouvrez le fichier exerciceP10.pro
-Une fenêtre Qt Creator devrait s'ouvrir
-Compilez le projet
-Executez le projet
-Une fois le programme lance, vous pouvez:
	-Bouger la camera avec la souris, les touches q,e ou les fleches directionnelles
	-Vous deplacer avec les touches w,a,s,d,r,f
	-Faire pause en appuyant sur espace
	-Retourner au point de vue originel avec la touche home
	-Afficher l'espace des phases avec la touche p et changer d'oscillateur avec la touche i

Pour modifier le contenu du système et rajouter des oscillateurs:
	-Allez dans le fichier glwidget.h, a travers Qt Creator, qui est dans le repertoire QT_GL, dans les headers
	-Vous pouvez modifier le systeme a travers le constructeur de GLWidget
	-Pour rajouter un oscillateur, vous pouvez vous inspirer des modèles existants de chaque oscillateur, en veillant a rajouter en paramètre 3 double a la fin qui sont les 	coordonnees de l'origine des oscillateurs. Qt Creator devrait vous aidez pour la construction des differents oscillateurs.

Interface texte:
	-Vous pouvez exécutez les different test dans le fichier P9 a l'aide de Geany
	
	-Vous pouvez aussi utiliser Qt Creator:
	-Ouvrez le fichier P10.pro
	-Une fenetre Qt Creator devrait s'ouvrir
	-Compilez le projet si ce n'est pas déjà fait
	-Clickez sur le répertoire exerciceP10
	-Faites clic droit sur le repertoire text et selectionnez "executer"

Pour modifier le contenu du système:
	-Allez dans le fichier exerciceP9.cc puis rajouter des oscillateurs ou modifiez ceux existant de la même façon que pour l'affichage graphique
  
