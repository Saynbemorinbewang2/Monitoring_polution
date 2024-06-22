# Surveillance des émissions des véhicules

Les instructions détaillées de ce projet sont disponibles dans le fichier PDF [README ORANGE SUMMER CHALLENGE 2024.pdf](README%20ORANGE%20SUMMER%20CHALLENGE%202024.pdf).

## Aperçu du projet
Ce projet utilise des capteurs de gaz et de particules connectés à un microcontrôleur ESP32 pour surveiller les émissions des véhicules. Les données collectées sont envoyées via Wi-Fi à un serveur distant et peuvent être consultées en temps réel via un moniteur final.

## Composants utilisés
- ESP32
- Capteur de gaz multiples (MQ-135)
- Capteur de particules fines (PMS5003)
- Module GSM (SIM800L) ou Wi-Fi intégré à l’ESP32
- Écran OLED (0.96 inch OLED)
- Batterie LiPo et module de gestion d’alimentation (TP4056)

## Instructions de montage et de code
1. Connecter les capteurs à l’ESP32 selon le schéma de montage.
2. Alimenter l’ESP32 avec une batterie LiPo.
3. Utiliser le module de communication (GSM ou Wi-Fi) pour envoyer les données au serveur.
4. Afficher les données sur un écran OLED ou une interface web.
5. Utiliser le code fourni pour lire les capteurs et envoyer les données.

## Auteur
Saynbe Mo

## Licence
© 2024 Saynbe Mo. Tous droits réservés. Ce code peut être utilisé par Orange Cameroun pour des projets de surveillance de la qualité de l'air.
