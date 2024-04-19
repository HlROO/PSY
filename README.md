# Projet PSY
Projet "Tests et Contrôles en Hôpital Psychiatrique"

## Domaine(s) d'activité(s) du système support du projet :

- Informatique, réseaux et infrastructures
- Multimédia, son et image, radio et télédiffusion
- Mesure, instrumentation et micro systèmes

## Analyse de l’existant :

Les patients atteints de dégénérescence fronto-temporale nécessitent des exercices réguliers d'attention et de mémorisation. Les activités privilégiées sont les jeux, la lecture et la discussion.

Des logiciels existent pour réaliser des tests QCM, mais l'absence d'écran tactile dans les foyers des patients pose problème. Le recours à un ordinateur est difficile en raison de l'âge des patients et de leur vue défaillante.

Les pannes des réfrigérateurs à l'hôpital sont un autre problème, nécessitant une surveillance prolongée pour détecter les anomalies.

## Expression du besoin :

### Présentation globale :

Le projet comprend deux activités distinctes :

1. **Développement d'un Clavier Déporté** : Permettra aux patients de répondre aux tests sans toucher les écrans non tactiles des ordinateurs ou des télévisions familiales.

![clavier](img/clv.png)

2. **Système de Surveillance des Réfrigérateurs** : Mesurera la température du condenseur, l'intervalle entre deux compressions et détectera les fuites d'eau près des réfrigérateurs.

![condensateur frigo](img/cdnfrg.png)
![cdnfrg2](img/cdnfrg2.png)

### Spécifications :

- Utilisation de l'USB pour le clavier déporté, avec possibilité d'envisager d'autres interfaces sans fil.
- Utilisation d'Android, Bluetooth et ZigBee pour la surveillance des réfrigérateurs.

![diagram de context](img/diagramcontext.png)

## Énoncé des tâches à réaliser par les étudiants :

### Étudiant 1 :

- Développement du programme de liaison USB pour le clavier.
- Réflexion sur d'autres interfaces de liaison.
- Développement de l'application Android en relation avec l'Étudiant 3.

### Étudiant 2 :

- Mesure de température et détection d'eau.
- Programmation de la communication ZigBee.
- Réflexion sur l'alimentation des sous-ensembles.

### Étudiant 3 :

- Gestion des interfaces Bluetooth et ZigBee.
- Enregistrement et formatage des données pour l'application Android.
- Assurer le bon fonctionnement de la station de communication.

## Description structurelle du système :

### Principaux constituants :

- Cartes de développement
- Boîtier du clavier
- Smartphone
- Élément chauffant pour simuler le condenseur du frigo

### Matériels et outils logiciels :

- Logiciels de développement Arduino et Microchip IDE
- Logiciels de simulation et d'édition de schéma
- Matériel de mesure et de soudure
- Documentation Arduino

## Contraintes :

- Contraintes financières : Maintenir un coût raisonnable avec des distributeurs sélectionnés.
- Contraintes de qualité : Les maquettes doivent être utilisables directement et conformes aux exigences.
- Contraintes de fiabilité/sécurité : Respecter les règles de sécurité électrique pour les mesures.

Ce projet vise à répondre aux besoins spécifiques de l'hôpital psychiatrique en proposant des solutions technologiques adaptées et fiables.
